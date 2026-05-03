# Localization 스터디 정리
날짜: 2026-03-10

---

## 1. dual_ekf_navsat_gps_only.launch.py 구조

### 전체 아키텍처
```
[GPS(/ublox)] + [IMU(/vectornav)] + [Wheel Odom] + [LiDAR Odom(fast_lio)]
        ↓                ↓
  navsat_transform    ekf_odom (local)
        ↓                ↓
  odometry/gps_raw  odometry/local
        ↓
  ekf_map (global)
        ↓
  odometry/global  ←→  gps_manager (품질 감시 + SetPose)
```

### 노드별 역할

**ekf_filter_node_odom** → `odometry/local`
- world_frame: odom (로컬 상대 측위)
- 주파수: 50Hz
- 융합: 휠 오돔(vx) + fast_lio(x,y,yaw,vx) + IMU(yaw, yaw_rate)

**ekf_filter_node_map** → `odometry/global`
- world_frame: map (절대 위치 보정)
- 주파수: 20Hz
- 융합: GPS(x,y) + IMU(yaw, yaw_rate)
- odom0_pose_rejection_threshold: 10.0 (Mahalanobis 이상값 거부)

**navsat_transform**
- GPS(lat/lon) → odom 좌표계(x,y) 변환
- delay: 0.05s (GPS-EKF 타임스탬프 동기화 버퍼)

**gps_manager**
- GPS 품질 분류 + EKF 강제 리셋(SetPose)
- RTK Fix(cov<0.01) + 위치차이≥2m + 쿨다운 10s 조건 시 리셋

---

## 2. navsat_transform delay 파라미터

- GPS 수신 후 실제 변환까지 기다리는 시간
- 목적: GPS 타임스탬프와 odometry/global 타임스탬프 동기화
- 튜닝 기준:
  - delay ≥ GPS 주기 + EKF 처리 지연 = 1/10 + 1/20 = 0.15s (이론적 상한)
  - 현재 0.05s는 타이트한 값 → 불안정 시 0.1~0.2 범위로 증가
  - odometry/gps_raw가 튀면 0.05씩 증가
  - 0.2s 이하 권장

---

## 3. PythonRobotics Localization 알고리즘 분석

### 공통 시나리오
- 상태벡터: [x, y, yaw, v], DT=0.1s, 50초 시뮬레이션

### EKF (Extended Kalman Filter)
- 비선형 운동모델을 야코비안으로 선형화
- 상태: [x, y, yaw, v]
- 관측: GPS(x, y)
- 한계: 강한 비선형에서 야코비안 선형화 오차 발생

**변종: EKF with velocity correction**
- 상태에 스케일 팩터 s 추가: [x, y, yaw, v, s]
- 휠 오돔의 속도 스케일 오차(타이어 마모, 슬립)를 추정하며 보정

### UKF (Unscented Kalman Filter)
- 야코비안 없이 2n+1개 sigma point를 비선형 함수에 직접 통과
- 파라미터: α=0.001, β=2, κ=0
- EKF 대비: 야코비안 불필요, 2차 비선형까지 정확
- 음수 가중치 발생 가능 → 수치 불안정 위험

### CKF (Cubature Kalman Filter)
- UKF 개선형, Spherical-Radial Cubature Rule 적용
- sigma point: 정확히 2n개, 가중치 모두 1/2n (균등)
- 튜닝 파라미터 없음 (수학적으로 최적 고정)
- 음수 가중치 없음 → 수치 안정성 높음
- CTRV 운동모델 사용 (곡선 주행에 더 정확)
- 단, 가우시안 가정 기반이므로 강한 비가우시안엔 UKF 튜닝이 유리할 수 있음

**UKF vs CKF 핵심 차이**
```
적분 문제: E[f(x)] = ∫ f(x) p(x) dx 를 어떻게 근사하는가

UKF: α,β,κ로 점 배치를 사용자가 조절 → 음수 가중치 가능
CKF: 구면 적분으로 수학적 최적 고정 → 튜닝 불필요
```

### PF (Particle Filter)
- N개 파티클로 상태 분포 표현
- 비가우시안, 멀티모달 분포에 강함
- 관측 모델에 따라 맵 필요 여부 결정 (GPS면 불필요, LiDAR면 필요)
- Low-variance resampling 사용

### EnKF (Ensemble Kalman Filter)
- N개 앙상블 샘플로 공분산 추정
- 칼만 게인으로 앙상블 직접 이동 (리샘플링 없음)
- 기상예측 등 고차원 시스템용, 로보틱스에서는 잘 안 씀

### Histogram Filter
- 2D 그리드 맵으로 확률 분포 직접 유지
- 초기 위치 불필요 (global localization 가능)
- yaw는 알고 있어야 함
- 그리드 크기에 비례하는 연산량, 고차원 불가

### 알고리즘 제약 조건 비교

| | EKF | UKF/CKF | PF | Histogram |
|--|-----|---------|-----|-----------|
| 운동모델 | 미분 가능 필요 | 제약 없음 | 제약 없음 | 제약 없음 |
| 관측모델 | 미분 가능 필요 | 제약 없음 | 제약 없음 | 제약 없음 |
| 노이즈 가정 | 가우시안 필수 | 가우시안 권장 | 어떤 분포도 OK | 어떤 분포도 OK |
| 초기 위치 | 필요 | 필요 | 필요 (글로벌 가능하나 파티클 폭발) | 불필요 |
| 맵 필요 | 관측모델 의존 | 관측모델 의존 | 관측모델 의존 | 필요 |
| 멀티모달 | X | X | O | O |

**관측 타입은 자유롭게 설계 가능** - 알고리즘에 종속된 것이 아닌 h(x) 정의에 달려있음

### 모든 칼만 계열 공통 필요 파라미터
| 파라미터 | 의미 |
|---------|------|
| Q (프로세스 노이즈) | 운동모델 신뢰도 |
| R (관측 노이즈) | 센서 신뢰도 |
| P₀ (초기 공분산) | 초기 추정치 확신도 |

---

## 4. 비가우시안 센서와 대응

### 주요 비가우시안 센서
| 센서 | 원인 | 분포 |
|------|------|------|
| UWB | NLOS → 오차 양수 방향 편향 | exponential / mixture |
| GPS | multipath, 건물 반사 | heavy tail |
| LiDAR | 유리/반사면, Occlusion | mixture |
| 휠 인코더 | 슬립 → 갑작스런 점프 | heavy tail |
| IMU | bias drift | colored noise |
| Radar | clutter | Rayleigh |

### 비가우시안 대응 방법
1. Robust estimator (Huber loss 등)
2. Mixture model
3. Outlier rejection (Mahalanobis distance)
4. Non-Gaussian filter (Particle Filter 등)
5. Sensor fusion

---

## 5. 현재 SCV 시스템의 취약점

### 문제점
- EKF는 가우시안 가정 기반 → GPS heavy tail이 지속 유입 시 S 공분산 오염
- 휠 슬립에 대한 별도 rejection threshold 없음 (Q(vx)=0.5로 크게만 설정)
- LiDAR(fast_lio) 이상값에 대한 ekf_odom rejection 없음

### GPS 품질 저하 시 동작
| 품질 | 오차 | 문제 |
|------|------|------|
| RTK Float | 5~30cm | 거부 기준 ~1m → 통과, 비교적 안전 |
| DGPS | 0.5~1m | 거부 기준 ~3m → 사실상 거부 안됨 |
| Single | 2~5m | 거부 기준 ~3m → 5m 오차 유입 가능 |

---

## 6. GPS 품질별 map→odom 업데이트 전략

### 전략 비교
**완전 고정 (GPS + IMU 모두 중단)**
- 장점: TF 완전 안정
- 단점: yaw도 고정 → 장시간 헤딩 오차 누적

**GPS만 차단, IMU 유지**
- GPS: 절대 위치 보정 역할
- IMU: yaw 방향 보정 역할
- → GPS와 IMU는 역할이 달라 함께 끊을 이유 없음

### 권장 전략
| GPS 품질 | GPS 입력 | IMU 입력 |
|---------|---------|---------|
| RTK Fix | 정상 | 유지 |
| RTK Float | 정상 | 유지 |
| DGPS | R 키워서 신뢰도 낮춰 입력 | 유지 |
| Single | 차단 | 유지 |
| No fix | 차단 | 유지 |

### Single GPS vs map→odom 고정 비교
- fast_lio 드리프트: 이동 거리의 ~1%
- Single GPS 오차: 2~5m (불규칙 점프)
- 손익분기점: 약 300~500m 이동 전까지는 고정이 유리
- 핵심: 오차 크기보다 **오차 형태**가 중요
  - Single GPS: 불규칙 점프 → 네비게이션 불안정
  - 고정: 부드러운 누적 → 네비게이션 안정

---

## 7. GPS 계층 구조

| 등급 | 방식 | 정확도 |
|------|------|--------|
| Single | 위성 신호만 | 2~5m |
| DGPS | 기준국 코드 보정 | 0.5~1m |
| RTK Float | 반송파 보정 (수렴 중) | 5~30cm |
| RTK Fix | 반송파 보정 (완전 수렴) | 1~2cm |

- DGPS: C/A 코드 기반 보정
- RTK: 반송파(carrier phase) 기반 보정, 기준국 실시간 통신 필요
- SCV에서 DGPS는 RTK 수렴 실패 또는 기준국 통신 불량 시 나타나는 중간 단계
