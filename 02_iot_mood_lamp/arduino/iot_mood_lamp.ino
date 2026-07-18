#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <WiFiS3.h>
#include <PubSubClient.h>

/*
  IoT Mood Lamp
  - DHT22 온습도 센서
  - 미세먼지 센서
  - LCD I2C 출력
  - RGB LED 상태 표시
  - MQTT 센서값 전송
*/

// ---------------- WiFi & MQTT 설정 ----------------
// GitHub에 실제 WiFi 이름/비밀번호를 올리면 안 되므로 반드시 아래처럼 가려서 올리기
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;

// test.mosquitto.org는 보통 사용자명/비밀번호 없이 접속 가능
const char* mqtt_user = "";
const char* mqtt_pass = "";

WiFiClient espClient;
PubSubClient client(espClient);

// ---------------- DHT22 센서 ----------------
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ---------------- LCD 설정 ----------------
// LCD 주소가 0x27이 아니면 0x3F로 바꿔서 테스트
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ---------------- 미세먼지 센서 ----------------
const int dustPin = A0;
const int ledPower = 6;

float dustDensity = 0.0;
String dustLevel = "GOOD";

// ---------------- RGB LED ----------------
// 공통 캐소드 RGB LED 기준
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// ---------------- 타이머 ----------------
unsigned long previousMillis = 0;
const unsigned long sensorInterval = 2000;   // 센서 측정 간격 2초
const unsigned long flickerInterval = 500;   // LED 깜빡임 간격

// ---------------- MQTT 토픽 ----------------
const char* temperature_topic = "home/temperature";
const char* humidity_topic    = "home/humidity";
const char* dust_topic        = "home/dust";
const char* dust_level_topic  = "home/dust/level";

// ---------------- RGB LED 제어 함수 ----------------
void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}

// ---------------- WiFi 연결 ----------------
void setup_wifi() {
  delay(10);

  Serial.println();
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

// ---------------- MQTT 연결 ----------------
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");

    String clientId = "ArduinoMoodLamp-";
    clientId += String(random(0xffff), HEX);

    bool connected;

    if (strlen(mqtt_user) > 0) {
      connected = client.connect(clientId.c_str(), mqtt_user, mqtt_pass);
    } else {
      connected = client.connect(clientId.c_str());
    }

    if (connected) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

// ---------------- PM2.5 레벨 판단 ----------------
String getDustLevel(float dust) {
  if (dust <= 15.0) {
    return "GOOD";
  } else if (dust <= 35.0) {
    return "NORMAL";
  } else if (dust <= 75.0) {
    return "BAD";
  } else {
    return "VERY_BAD";
  }
}

// ---------------- 미세먼지 측정 ----------------
float readDustDensity() {
  digitalWrite(ledPower, LOW);
  delayMicroseconds(280);

  int adcValue = analogRead(dustPin);

  delayMicroseconds(40);
  digitalWrite(ledPower, HIGH);
  delayMicroseconds(9680);

  float voltage = adcValue * (5.0 / 1023.0);
  float Vdark = 0.4;

  float density;

  if (voltage <= Vdark) {
    density = 0.0;
  } else {
    density = (voltage - Vdark) * 50.0;
  }

  return density;
}

// ---------------- LCD 출력 ----------------
void displayToLCD(float temperature, float humidity, float dust) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature, 1);
  lcd.print("C H:");
  lcd.print(humidity, 0);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("D:");
  lcd.print(dust, 1);
  lcd.print(" ");

  char gradeChar;

  if (dust <= 15.0) {
    gradeChar = 'G';
  } else if (dust <= 35.0) {
    gradeChar = 'N';
  } else if (dust <= 75.0) {
    gradeChar = 'B';
  } else {
    gradeChar = 'V';
  }

  lcd.print(gradeChar);

  int levelBlocks = map((int)dust, 0, 75, 0, 8);
  levelBlocks = constrain(levelBlocks, 0, 8);

  for (int i = 0; i < levelBlocks; i++) {
    lcd.write(byte(255));
  }
}

// ---------------- MQTT 전송 ----------------
void publishSensorData(float temperature, float humidity, float dust, String level) {
  char tempStr[10];
  char humStr[10];
  char dustStr[10];
  char levelStr[15];

  dtostrf(temperature, 4, 1, tempStr);
  dtostrf(humidity, 4, 1, humStr);
  dtostrf(dust, 5, 1, dustStr);
  level.toCharArray(levelStr, sizeof(levelStr));

  client.publish(temperature_topic, tempStr);
  client.publish(humidity_topic, humStr);
  client.publish(dust_topic, dustStr);
  client.publish(dust_level_topic, levelStr);
}

// ---------------- RGB LED 상태 표시 ----------------
void updateLED(float dust, unsigned long currentMillis) {
  int r = 0;
  int g = 0;
  int b = 0;

  if (dust <= 15.0) {
    // 좋음: 파랑
    r = 0;
    g = 0;
    b = 255;
  } else if (dust <= 35.0) {
    // 보통: 초록
    r = 0;
    g = 255;
    b = 0;
  } else if (dust <= 75.0) {
    // 나쁨: 주황 계열 깜빡임
    float phase = (currentMillis % flickerInterval) / (float)flickerInterval;
    r = 255;
    g = 60 + int(phase * 80);
    b = 0;
  } else {
    // 매우 나쁨: 빨강 계열 깜빡임
    float phase = (currentMillis % flickerInterval) / (float)flickerInterval;
    r = 255;
    g = int(phase * 50);
    b = 0;
  }

  setRGB(r, g, b);
}

// ---------------- Setup ----------------
void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  dht.begin();

  pinMode(ledPower, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  digitalWrite(ledPower, HIGH);
  setRGB(0, 0, 0);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);

  lcd.setCursor(0, 0);
  lcd.print("IoT Mood Lamp");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);
  lcd.clear();
}

// ---------------- Loop ----------------
void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  unsigned long currentMillis = millis();

  // 센서값 측정 및 LCD/MQTT 전송
  if (currentMillis - previousMillis >= sensorInterval) {
    previousMillis = currentMillis;

    dustDensity = readDustDensity();
    dustLevel = getDustLevel(dustDensity);

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("DHT Error");
      return;
    }

    displayToLCD(temperature, humidity, dustDensity);
    publishSensorData(temperature, humidity, dustDensity, dustLevel);

    Serial.print("T:");
    Serial.print(temperature, 1);
    Serial.print("C H:");
    Serial.print(humidity, 1);
    Serial.print("% D:");
    Serial.print(dustDensity, 1);
    Serial.print(" Level:");
    Serial.println(dustLevel);
  }

  // RGB LED는 센서 측정 주기와 별도로 계속 상태 표시
  updateLED(dustDensity, currentMillis);
}