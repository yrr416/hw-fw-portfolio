# IoT Mood Lamp

온습도 센서와 미세먼지 센서를 활용해 실내 환경값을 측정하고, LCD 표시, RGB LED 상태 표시, MQTT 전송 기능을 구현한 IoT 무드등 프로젝트입니다.

## 프로젝트 개요

DHT22 온습도 센서와 미세먼지 센서를 활용해 실내 환경값을 측정하고, LCD에 센서값을 표시했습니다.

또한 미세먼지 농도에 따라 RGB LED 색상이 달라지도록 구성해 사용자가 실내 공기 상태를 직관적으로 확인할 수 있도록 했습니다.

측정된 온도, 습도, 미세먼지 값은 MQTT를 통해 전송되도록 구성했습니다.

## 사용 부품 및 기술

- Arduino
- DHT22
- Dust Sensor
- LCD I2C
- RGB LED
- WiFi
- MQTT

## 주요 기능

- 온도와 습도 측정
- 미세먼지 농도 측정
- LCD에 센서값 표시
- 미세먼지 상태에 따른 RGB LED 색상 변경
- MQTT를 통한 센서값 전송

## 담당 내용

- 온습도 센서와 미세먼지 센서 데이터 측정
- LCD 출력 기능 구현
- RGB LED 상태 표시 기능 구현
- MQTT 전송 기능 구현
- 센서값과 출력값 비교 확인

## 프로젝트에서 확인한 점

측정값이 예상과 다를 때 센서 연결 상태, 측정 주기, LCD 표시값, LED 동작, MQTT 전송값을 나누어 확인했습니다.

이를 통해 센서 데이터가 실제 출력 장치와 전송값에 올바르게 반영되는지 점검하는 경험을 쌓았습니다.

## 파일 구조

```text
02_iot_mood_lamp/
├─ arduino/
│  └─ iot_mood_lamp.ino
├─ images/
└─ README.md
```

## 주의사항

GitHub에는 실제 WiFi 이름과 비밀번호를 올리지 않기 위해 코드 내 WiFi 정보는 아래처럼 처리했습니다.

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
```