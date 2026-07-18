#include <Servo.h>

const int trigPin = 8;
const int echoPin = 9;
const int servoPin = 7;

Servo servo;

int angle = 0;
int step = 2;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo.attach(servoPin);
}

void loop() {
  servo.write(angle);
  delay(200);  // 서보모터가 해당 각도로 이동할 시간

  long duration;
  int distance;

  // 초음파 신호 발생
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // echoPin에서 반사 신호 측정
  duration = pulseIn(echoPin, HIGH, 30000);

  // 거리 계산
  distance = duration * 0.034 / 2;

  // 유효 거리만 Processing으로 전송
  if (distance > 0 && distance < 200) {
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

  // 서보모터 각도 변경
  angle += step;

  // 0도와 180도에서 방향 전환
  if (angle >= 180 || angle <= 0) {
    step = -step;
  }
}