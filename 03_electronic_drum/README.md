# Electronic Drum

압전소자를 활용해 입력 신호를 감지하고, Arduino와 MIDI Shield를 통해 소리로 출력하는 전자드럼 제작 프로젝트입니다.

## 프로젝트 개요

고등학교 전자과 팀프로젝트로 아두이노 기반 전자드럼을 제작했습니다.

압전소자를 입력부로 사용하고, 필터 회로와 Arduino, MIDI Shield를 거쳐 입력 핀에 맞는 소리가 출력되도록 구성했습니다.

이 프로젝트는 계획서와 결과보고서를 기반으로 정리했으며, 제작 목적, 사용 부품, 회로 구성, 역할 분담, 문제점과 개선 방향을 확인할 수 있습니다.

## 사용 부품 및 기술

- Arduino
- Piezo Sensor
- Filter Circuit
- MIDI Shield
- Speaker
- Circuit Assembly
- Soldering

## 담당 역할

- Arduino 프로그래밍
- 회로 제작 참여
- 압전소자 입력 신호 확인
- 출력 동작 확인
- 결과보고서 기반 문제점 및 개선 방향 정리

## 동작 흐름

1. 드럼 패드를 스틱으로 치면 압전소자가 충격을 감지합니다.
2. 압전소자에서 발생한 전기 신호가 필터 회로를 거쳐 Arduino로 입력됩니다.
3. Arduino와 MIDI Shield가 입력 핀에 맞는 소리를 처리합니다.
4. 스피커를 통해 소리가 출력됩니다.

## 문제 및 개선 방향

완성 후 전자드럼 형태는 구현되었고 소리도 출력되었지만, 스피커의 출력 전압이 낮아 소리가 작게 출력되는 문제가 있었습니다.

개선 방향으로는 프리앰프를 추가하거나 출력 전압이 높은 스피커를 사용하는 방법을 정리했습니다.

## 배운 점

이 프로젝트를 통해 센서 입력 신호가 실제 출력 결과로 이어지기 위해서는 입력부, 회로, 제어부, 출력부가 함께 맞아야 한다는 점을 배웠습니다.

또한 회로 제작 과정에서 부품 연결 상태와 출력 상태를 함께 확인하는 경험을 쌓았습니다.

## 파일 구조

```text
03_electronic_drum/
├─ docs/
│  ├─ electronic_drum_plan.hwp
│  └─ electronic_drum_report.hwp
└─ README.md
```

## 참고 자료

- `docs/electronic_drum_plan.hwp`
- `docs/electronic_drum_report.hwp`