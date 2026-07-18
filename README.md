# HW/FW Portfolio

HW/FW·장비제어 직무 지원을 위해 정리한 포트폴리오입니다.

전자회로, 센서 제어, 회로 제작 실습, 아두이노 프로젝트, 반도체 공정 경험을 바탕으로 수행한 프로젝트를 정리했습니다. 각 프로젝트는 센서 입력값과 출력 동작을 확인하고, 회로와 장치가 어떤 흐름으로 동작하는지 이해하는 데 중점을 두었습니다.

## Projects

### 01. Ultrasonic Radar

초음파 센서와 서보모터를 활용해 거리값을 측정하고, Processing 화면에 레이더 형태로 표시한 프로젝트입니다.

**주요 내용**
- 초음파 센서를 이용한 거리 측정
- 서보모터를 활용한 각도 변화
- Arduino와 Processing 간 시리얼 통신
- 측정된 각도와 거리 데이터를 화면에 시각화

**사용 기술**
- Arduino
- Ultrasonic Sensor
- Servo Motor
- Processing
- Serial Communication

---

### 02. IoT Mood Lamp

온습도 센서와 미세먼지 센서를 활용해 실내 환경값을 측정하고, LCD 표시, RGB LED 상태 표시, MQTT 전송 기능을 구현한 IoT 무드등 프로젝트입니다.

**주요 내용**
- DHT22 센서를 활용한 온도·습도 측정
- 미세먼지 센서를 활용한 실내 먼지 농도 측정
- LCD I2C를 통한 센서값 표시
- 미세먼지 상태에 따른 RGB LED 색상 변경
- MQTT를 통한 센서값 전송

**사용 기술**
- Arduino
- DHT22
- Dust Sensor
- LCD I2C
- RGB LED
- WiFi
- MQTT

---

### 03. Electronic Drum

압전소자를 활용해 입력 신호를 감지하고, Arduino와 MIDI Shield를 통해 소리로 출력하는 전자드럼 제작 프로젝트입니다.

이 프로젝트는 계획서와 결과보고서를 기반으로 정리했습니다. 압전소자 입력, 필터 회로, Arduino, MIDI Shield, 스피커 출력 흐름을 이해하고 제작한 경험을 담고 있습니다.

**주요 내용**
- 압전소자를 활용한 입력 신호 감지
- 필터 회로를 통한 신호 처리
- Arduino와 MIDI Shield를 활용한 소리 출력
- 스피커 출력 문제 확인 및 개선 방향 정리

**사용 기술**
- Arduino
- Piezo Sensor
- Filter Circuit
- MIDI Shield
- Speaker
- Circuit Assembly
- Soldering

---

## Portfolio Focus

이 포트폴리오는 단순히 코드를 작성한 경험보다, 하드웨어와 소프트웨어가 연결되어 동작하는 과정을 이해하고 확인한 경험을 중심으로 정리했습니다.

- 센서 입력값과 출력 동작 확인
- 회로와 부품 동작 흐름 이해
- Arduino 기반 센서 제어 경험
- LCD, RGB LED, 스피커 등 출력 장치 제어 경험
- 시리얼 통신 및 MQTT 전송 경험
- 회로 제작 및 납땜 실습 경험
- 문제 발생 시 원인을 나누어 확인하는 태도

## Folder Structure

```text
HW-FW-PORTFOLIO/
├─ 01_ultrasonic_radar/
│  ├─ arduino/
│  ├─ images/
│  ├─ processing/
│  └─ README.md
│
├─ 02_iot_mood_lamp/
│  ├─ arduino/
│  ├─ images/
│  └─ README.md
│
├─ 03_electronic_drum/
│  ├─ docs/
│  │  ├─ electronic_drum_plan.hwp
│  │  └─ electronic_drum_report.hwp
│  └─ README.md
│
└─ README.md
```

## About Me

전자회로와 센서 제어, 회로 제작 실습을 바탕으로 HW/FW·장비제어 직무를 준비하고 있습니다. 프로젝트를 진행하며 단순히 동작 여부만 확인하는 것이 아니라, 입력값과 출력 결과, 회로 연결 상태, 장치 동작 조건을 나누어 확인하는 태도를 길렀습니다.