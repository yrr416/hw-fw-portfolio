# Ultrasonic Radar

초음파 센서와 서보모터를 활용해 거리값을 측정하고, Processing 화면에 레이더 형태로 시각화한 프로젝트입니다.

## 프로젝트 개요

인터페이스설계 과목에서 초음파 센서와 서보모터를 활용한 레이더 시각화 시스템을 제작했습니다.

Arduino에서 각도별 거리값을 측정하고, 측정된 데이터를 시리얼 통신으로 Processing에 전달해 화면에 레이더 형태로 표시했습니다.

## 사용 부품 및 기술

- Arduino
- Ultrasonic Sensor
- Servo Motor
- Processing
- Serial Communication

## 주요 기능

- 초음파 센서를 이용한 거리 측정
- 서보모터를 활용한 0도~180도 각도 변화
- 각도와 거리값을 시리얼 통신으로 전송
- Processing 화면에 레이더 형태로 시각화

## 담당 내용

- 초음파 센서와 서보모터 연결
- Arduino 코드 작성 및 동작 확인
- Processing 화면 출력 확인
- 센서값과 화면 표시 결과 비교

## 프로젝트에서 확인한 점

센서값이 일정하지 않을 때 코드만 수정하지 않고, 센서 연결 상태와 측정 간격, 서보모터 제어값을 나누어 확인했습니다.

이를 통해 센서 입력값, 모터 동작, 화면 출력 결과를 함께 점검하는 경험을 쌓았습니다.

## 파일 구조

```text
01_ultrasonic_radar/
├─ arduino/
│  └─ ultrasonic_radar.ino
├─ images/
├─ processing/
│  └─ radar_visualization.pde
└─ README.md
```