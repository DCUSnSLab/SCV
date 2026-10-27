# FGO 융합 설계 문서 (loam_fgo_localization 내 구현)

> 2026-07-31. 목표: 규칙 기반 모드 매니저를 슬라이딩 윈도우 FGO로 대체하여
> 비RTK GPS(float, m급 바이어스)와 PCD 정합(간헐적 오정합)을 **동시에, 연속적으로** 사용.
>
> **구현 위치 (사용자 결정)**: 별도 패키지가 아니라 `loam_fgo_localization` 패키지 안에서 작업.
> - `src/global_localization/`: 소스별 측정 추출 노드 (PCD localizer + 신규 GPS frontend)
> - `src/fusion/`: 신규 FGO 융합 노드
> - `src/temp/`: 대체되는 기존 코드 보관 (baseline A/B 비교용으로 빌드는 유지)

---

## 1. 배경 (bag 근거)

- `rosbag2_2026_07_30`(파이프라인 출력 bag): 보고 σ 기반 규칙 스위칭이 GPS를 65%
  신뢰/PCD 3% 사용, 모드 전환 145회, map→odom 점프 최대 18.7m,
  GPS-PCD 간 **세션 수준 ~2.7m 바이어스** (float 추정, σ는 0.3m대로 과신).
- `record_20260721_214104`(raw bag, 697s, 53GB): RTK 양호 구간 → GPS 열화 구간 주행.
  맵 제작에 사용된 원본. **본 설계의 주 평가 bag.**
  - /vectornav/imu 100Hz, /hunter/velocity 50Hz, /ublox_gps_node/fix 10Hz,
    /velodyne_points 10Hz (+카메라/스캔/tf 등)

핵심 문제 정의: 신뢰 신호(보고 σ)가 오염된 환경에서 이진 선택은 잘못된 소스를
고를 수 있다 → 선택을 없애고 공분산 가중 + 바이어스 추정 + robust kernel로 대체.

## 2. 아키텍처 (전체 데이터 흐름)

```
                    [무변경 재사용]                          [신규: src/fusion + src/global_localization]
IMU+휠 ──► local_odometry_node ──► /odom (100Hz) ──────────► odom 증분 → between factor
                                        │                          │
LiDAR ──► lio_sam feature ──► lio_feature_map_localizer            │
                                   │ /pcd/global_pose (~3Hz) ────► PCD pose factor (robust)
                                   │ (+ 공분산 추가: 소규모 수정)      │
GPS   ──► (직접 구독: /ublox_gps_node/fix + datum) ──────────────► GPS factor + bias 변수
                                                                   │
                                                        [iSAM2 (Dogleg), §3.4/§10 참조]
                                                                   │
                                       map→odom TF (50Hz 재스탬프) + /global_pose + /fgo/status
```

- **local_odometry_node / lio_feature_map_localizer: 무변경** (PCD localizer만
  공분산 발행 1건 소규모 수정, §5.3)
- **gps_global_localizer / localization_mode_manager: FGO 파이프라인에서는 미사용**
  (src/temp로 이동, baseline 실행 시에만 사용). 단 `/gps/coarse_position`은 PCD
  전역초기화 prior로 계속 필요하므로, 신규 gps_measurement_node가 동일 포맷으로
  발행(§5.2).
- GPS는 `coarse_position`(σ만 있음)이 아니라 **`/ublox_gps_node/fix`를 직접 구독**
  → NavSatFix.status / 공분산 타입으로 fix-type 게이팅 가능. UTM 변환 + datum은
  기존 코드와 동일 방식(GeographicLib, UtmLayer 토픽/파라미터).

## 3. 팩터 그래프 설계

### 3.1 변수
| 변수 | 타입 | 생성 정책 |
|---|---|---|
| `X_i` | Pose2 (SE(2): x, y, yaw — map 프레임 base_link) | keyframe: 0.5m 이동 또는 0.5s 경과 |
| `B_j` | Point2 (GPS 바이어스: map 프레임 2D) | 10s마다 새 노드 (랜덤워크 체인) |

- SE(2) 선택 근거: 지상 로봇 + local ESKF planar 구속. z/roll/pitch는 PCD가 주지만
  v1은 2D로 시작 (SE(3) 확장은 후속).

### 3.2 팩터
| 팩터 | 대상 | 노이즈 모델 | 비고 |
|---|---|---|---|
| odom between | X_i — X_{i+1} | /odom 공분산 증분 또는 튜닝 상수(거리비례) | 그래프의 뼈대. 항상 존재 |
| GPS position | X_i — B_j | `max(보고σ, floor)` + fix-type별 floor: RTK-fixed 0.1m / float 1.5m / 기타 3.0m | 측정모델 `z = t(X_i) + B_j` |
| GPS bias 랜덤워크 | B_j — B_{j+1} | σ_rw ≈ 0.1 m / 10s | float 바이어스의 느린 변동 |
| GPS bias prior | B_0 (및 RTK-fixed 시 해당 B_j) | 약한 prior(3m) / RTK-fixed 시 강한 prior(0.1m) | RTK가 절대좌표 재고정 역할 |
| PCD pose | X_i (unary) | 정합 공분산(§5.3), **Cauchy robust kernel** | 삽입 전 카이제곱 게이트 |
| 초기 prior | X_0 | GPS 첫 fix 위치 + yaw 대분산(π²) | yaw는 주행하며 관측 |

### 3.3 오정합/이상치 처리 (기존 규칙의 이식)
1. **사전 게이트**: PCD 팩터 삽입 전 현재 추정 대비 Mahalanobis 검정 (χ², 3-DoF 99%)
   — 단 연속 N회 게이트 아웃되면 "우리가 틀렸을 가능성" → 게이트 완화 (kidnap 방어)
2. **robust kernel**: 게이트를 통과한 오정합의 잔여 영향 다운웨이트 (Cauchy k=1.0)
3. GPS는 bias 변수가 1차 방어, robust kernel(Huber k=1.345) 2차
4. **워치독**: 절대 팩터(GPS 유효 또는 PCD 유효)가 T_watchdog(기본 10s) 이상 없으면
   `/fgo/status = DEGRADED` 발행 (하위 시스템 감속 판단용; 기존 LOST 무한 Hold 개선)

### 3.4 스무더
- GTSAM `IncrementalFixedLagSmoother`, lag 20s (keyframe ~40개)
- 갱신: keyframe 생성 시 + PCD/GPS 팩터 도착 시 batch, 발행은 5Hz 타이머
- 지연 측정 처리: 팩터는 타임스탬프에 해당하는 keyframe에 부착 (lag 내 과거 수정 허용)

### 3.5 출력
- `map→odom = X_latest ∘ (odom pose_latest)⁻¹` → TF + `/localization/map_to_odom`
  (기존 토픽명 유지 → 하위 호환)
- `/global_pose` (map 프레임 base_link, 기존 포맷)
- `/fgo/status` (OK / DEGRADED / INIT), `/fgo/gps_bias` (추정 바이어스, 진단/논문용)

## 4. 파일 구조 (loam_fgo_localization 패키지 내)

```
loam_fgo_localization/
├── DESIGN_FGO.md                      # 본 문서
├── CMakeLists.txt                     # (수정) GTSAM 추가, temp 경로, 신규 실행파일 2개
├── config/
│   ├── fgo_fusion.yaml                # (신규) FGO 전 파라미터 (§3 노이즈/게이트/lag)
│   └── ...                            # 기존 config 유지
├── include/loam_fgo_localization/
│   ├── fusion/
│   │   ├── fgo_core.hpp               # (신규) 그래프 관리: keyframe 정책, 팩터 삽입,
│   │   │                              #   fixed-lag smoother 래핑 (ROS 비의존, 단위테스트 대상)
│   │   ├── fgo_gates.hpp              # (신규) 카이제곱 게이트, 워치독 (ROS 비의존)
│   │   └── hybrid_mode_logic.hpp      # (기존) temp 노드가 사용, 유지
│   ├── global_localization/
│   │   ├── gps_frontend.hpp           # (신규) NavSatFix→map 좌표 + fix-type 판별 + σ floor
│   │   └── ...                        # 기존 헤더 유지 (temp 노드들이 참조)
│   └── local_odometry/                # 무변경
├── src/
│   ├── local_odometry/                # 무변경
│   ├── global_localization/
│   │   ├── gps_measurement_node.cpp   # (신규) GPS frontend 노드 (EKF 없음)
│   │   ├── lio_feature_map_localizer_node.cpp  # (수정) 공분산 발행 추가 (§5.3)
│   │   ├── datum_publisher_node.cpp   # 무변경
│   │   ├── se2_branch_and_bound.cpp   # 무변경
│   │   └── cuda_knn.cu                # 무변경
│   ├── fusion/
│   │   ├── fgo_core.cpp               # (신규)
│   │   └── fgo_fusion_node.cpp        # (신규) ROS I/O 전담: 구독/발행/TF/타이머
│   └── temp/                          # (이동) 대체된 기존 코드 — baseline용 빌드 유지
│       ├── localization_mode_manager_node.cpp
│       ├── gps_global_localizer_node.cpp
│       ├── hybrid_gps_ekf.cpp
│       ├── global_localization_node.cpp
│       └── gps_ekf.cpp
├── launch/
│   ├── fgo_localization.launch.py     # (신규) 전체 FGO 스택: local + PCD + GPS frontend + FGO
│   ├── loam_fgo_localization.launch.py     # (기존) baseline 스택 — 그대로 동작
│   └── ...
└── tools/                             # (신규)
    ├── run_baseline.sh                # bag play + 기존 스택 → 결과 bag 기록
    ├── run_fgo.sh                     # bag play + FGO 스택 → 결과 bag 기록
    └── evaluate.py                    # 두 결과 bag 비교: 궤적, 점프 수, PCD 활용률,
                                       #   바이어스 궤적, (RTK 구간 한정) 절대오차
```

설계 원칙: `fgo_core`/`fgo_gates`는 ROS 비의존 → 단위테스트 + 향후 오프라인 도구 재사용.
ROS 결합은 `fgo_fusion_node.cpp` 한 파일에 격리 (기존 `hybrid_mode_logic` 분리 관행 유지).

## 5. 기존 코드 접점 (수정 범위)

| # | 대상 | 수정 | 규모 |
|---|---|---|---|
| 5.1 | 기존 노드 5개 소스 | `src/temp/`로 이동, 실행파일명 유지한 채 빌드 지속 (baseline) | 경로만 |
| 5.2 | gps_measurement_node | `/gps/coarse_position` 동일 포맷 재발행 (PCD BBS prior용) → FGO 스택에서 gps_global_localizer 불필요 | 신규 코드에 포함 |
| 5.3 | lio_feature_map_localizer | `/pcd/global_pose`의 covariance 필드에 LM Hessian(JᵀJ)⁻¹ 근사 기록 (현재 [0]에 degenerate 플래그만) | ~30줄, 옵션 파라미터로 가드 |

## 6. 평가 계획 (두 bag)

### 6.1 주 평가: `record_20260721_214104` (raw, RTK→열화, 맵 제작 bag)

측정된 GPS 프로파일 (60s bin, NavSatFix.status / σ p50):
```
  0-120s : status 0,  σ≈0.19-0.23m   (float)
120-180s : status 2,  σ p50=0.037m   ← RTK 수렴 구간 (준-GT 앵커)
180-697s : status 0,  σ p50=0.61-0.82m, p90 최대 1.9m  (열화 구간)
전체: σ<0.05m 8%, σ<0.5m 28%
```
→ fix-type 분류: status(2=GBAS/RTK) AND σ<0.05 를 "RTK-fixed"로 판정.
→ 참고: 현행 파이프라인 게이트(σ≤0.5)라면 이 bag의 GPS 72%가 게이트 아웃되는 환경.
1. `tools/run_baseline.sh`: bag play → 기존 스택(local+PCD+GPS-EKF+mode manager) → 결과 bag A
2. `tools/run_fgo.sh`: bag play → FGO 스택 → 결과 bag B
3. `evaluate.py A B`:
   - RTK-fixed 구간(σ<0.05): GPS를 준-GT로 절대오차 비교 ← **이 bag의 핵심 가치**
   - 열화 구간: 점프 수/크기, PCD 팩터 채택률, 랩 반복성
   - GPS 바이어스 추정치 B_j 궤적 (RTK 구간에서 ≈0, 열화 구간에서 성장 예상 — 논문 그림)
   - 주의: 맵 제작에 쓴 bag이므로 PCD 정합이 낙관적으로 나옴 (map-query 동일 세션).
     논문 최종 평가는 별도 세션 bag 필요. 개발/1차 검증용으로는 적합.
4. (참고) tf 토픽에 기존 스택 TF가 남아있으므로 재생 시 `--topics` 화이트리스트로
   /tf 재생 제외 또는 remap 필요 → run 스크립트에서 처리

### 6.2 보조: `rosbag2_2026_07_30` (파생 토픽 bag)
- /odom, /gps/coarse_position(σ만), /pcd/global_pose가 이미 있으므로 raw 스택 없이
  FGO 노드만 물려 빠른 반복 개발용. 단 fix-type 정보 없음 → σ floor 단일값으로.

## 7. 마일스톤

| M | 내용 | 상태 |
|---|---|---|
| M1 | 패키지 골격 + fgo_core (odom between만) | ✅ (2026-07-31) |
| M2 | + GPS factor + bias 체인 | ✅ |
| M3 | + PCD factor + 게이트 + robust kernel (+5.3 공분산) | ✅ + v1.1 안정화 (§10.4) |
| M4 | 평가 도구 + bag 6.1 전체 비교 | ✅ 1차 완료 (§10.2) — v1.1 재검증은 사용자 수행 예정 |

## 8. 결정 사항 (확정)

1. **구현 위치**: 별도 패키지 대신 `loam_fgo_localization` 내 구현 (사용자 지시, 2026-07-31).
   기존 코드는 `src/temp/` 보관 + baseline 빌드 유지.
2. **SE(2) v1**로 시작 (z/roll/pitch는 후속 확장).
3. GPS bias 노드 주기 10s / 랜덤워크 0.1m — `record_20260721` bag의 RTK↔float
   전이 구간에서 튜닝 예정.
4. 출력 토픽명은 기존 유지 (/localization/map_to_odom, /global_pose) — 하위 호환.
5. PCD localizer 공분산 발행 추가 진행 (파라미터 가드, baseline 영향 없음).

## 9. 신규 토픽 규약

| 토픽 | 타입 | 발행자 | 내용 |
|---|---|---|---|
| `/gps/measurement` | PoseWithCovarianceStamped | gps_measurement_node | map 프레임 GPS 위치, 공분산은 fix-type별 floor 적용값 |
| `/gps/fix_state` | String (latched) | gps_measurement_node | "RTK_FIXED" / "FLOAT" / "NONE" (변화 시 발행) |
| `/gps/coarse_position` | PoseWithCovarianceStamped | gps_measurement_node | 기존 규약 그대로 (raw σ) — PCD BBS prior용 |
| `/fgo/status` | String (latched) | fgo_fusion_node | "INIT" / "OK" / "DEGRADED" (워치독) |
| `/fgo/gps_bias` | PointStamped | fgo_fusion_node | 추정된 GPS 바이어스 (진단/논문 그림용) |

---

## 10. 구현/평가 이력 (2026-07-31 기준, v1.1)

### 10.1 구현 상태

마일스톤 M1~M3 완료 + v1.1 안정화. 신규/수정 파일:

| 파일 | 상태 |
|---|---|
| `src/global_localization/gps_measurement_node.cpp` + `include/.../gps_frontend.hpp` | 신규 — fix 분류(status≥2 & σ<0.05 → RTK_FIXED), σ floor, /gps/measurement·coarse_position·fix_state |
| `src/fusion/fgo_core.{hpp,cpp}` | 신규 — iSAM2(**Dogleg**), Pose2 keyframe(0.5m/0.5s), GPS bias Point2 랜덤워크 체인(10s), custom GpsBiasFactor(z=t(X)+B, Huber), PCD prior(χ² 게이트+relax 히스테리시스+Cauchy) |
| `src/fusion/fgo_fusion_node.cpp` | 신규 — solve 5Hz / TF 재스탬프 50Hz 분리(tf2 공통시각 문제), /global_pose 는 map→odom ∘ 최신 odom 합성 |
| `lio_feature_map_localizer_node.cpp` | 수정 — 수락 정합에 σ²(AᵀA)⁻¹ 공분산 기록(SVD 역행렬), 미기록(0)=정합 아님 표식 → FGO가 예측발행 무시 |
| `src/temp/` (5개) | 이동 — baseline 스택, 실행파일명 유지 빌드 |
| `launch/global_fgo.launch.py`, `launch/fgo_localization.launch.py` | 신규 — 기존 launch 패턴 미러 |
| `tools/run_stack_on_bag.sh`, `tools/evaluate.py` | 신규 — 도메인 격리(EVAL_DOMAIN=77) bag 재생 평가 |

실행: `map_provider(bundle) + fgo_localization.launch.py use_sim_time:=true + bag play(--clock, 센서 화이트리스트)`

### 10.2 평가 결과 (record_20260721, v1.0 시점)

| 지표 | FGO v1.0 | baseline (규칙 기반) |
|---|---|---|
| RTK(σ<0.05) 준-GT 오차 | p50 0.23 / p90 0.32 / max 0.41 m | p50 17.3 / max 101.9 m |
| map→odom 점프 >0.3m | 11회 (max 0.96m) | 212회 (max 219.8m) |
| PCD scan-match 활용 | 2,987개 발행 (게이트 수락 ~40%) | 14개 |
| 연속성 | 2.9s OK 이후 무전환 | 모드 전환 80회 |

주의: 맵 제작에 쓴 bag 자체 평가라 PCD 낙관적. baseline 붕괴에는 BBS 오정합
시드(복도 aliasing, ~22m) 후 미복구가 겹침 — run-to-run 분산 존재.
그림: `../impl_eval_survey/eval_fgo_vs_baseline_20260721.png`

### 10.3 발견된 문제와 진단 (bag 데이터로 확정)

1. **map→base 계단 현상**: map→odom TF 스탬프가 5Hz라 tf2 공통시각이 묶임
   → solve/TF 발행 분리(50Hz 재스탬프)로 해결.
2. **회전 시 뒤틀림→느린 복귀 (t*=383s)**: 급선회(47°/s) 중 PCD 정합 공백 +
   odom yaw 드리프트 → 출구 yaw ~10° 오버슈트. 복귀가 느린 근본 원인은 ↓3.
3. **게이트 자기잠금(lockout)**: float GPS 오프셋(PCD−rawGPS)이 **분 단위로 수 m
   배회**(310~380s에 ~4m 이동, 랩1 0.6m→랩3 3.2m). bias RW(0.1m/10s)가 못 쫓아가
   잔차↑ → 과신 공분산(σ=5cm 주장; 실체는 정밀도)의 χ² 게이트가 **옳은 PCD를 60%
   거부** → bias 학습 중단 → 잔차 유지 악순환. relax(10연속 거부 시 1개 무조건
   수락)는 1/11 duty + Cauchy 다운웨이트로 보정이 기어감.
   "1바퀴째는 맞고 2바퀴째 틀어진" 이유 = 주행 차이가 아니라 시간에 따른 float 배회.
4. **초기화 발산 (재현 실행에서)**: π-넓은 yaw prior + 강한 위치측정에서 GN 스텝
   폭주(map→odom 100~700m) → solve 마비 → CPU 포화로 PCD localizer 연쇄 붕괴.
   run-to-run 메시지 순서 차이로 발현 여부가 갈림.
5. (baseline 계열) BBS 시드 aliasing 오정합 후 재측위 미복구 — localizer 자체 과제.

분석 산출물: `impl_eval_survey/` (traj/twist/lap 비교 그림), 분석 스크립트는 세션
스크래치(재생 불필요, eval bag에서 직접).

### 10.4 v1.1 수정 (사용자 승인, 적용 완료)

| 수정 | 대상 문제 |
|---|---|
| iSAM2 GN → Dogleg | 10.3-④ 발산 |
| GPS 단독 앵커: 2m 주행 후 이동방향 yaw 추정 → pose prior(σ0.3) 앵커, 이전엔 GPS 팩터 보류 (PCD 우선 앵커) | 10.3-④ |
| `pcd.cov_scale: 100` (σ×10 현실화) | 10.3-③ 과신 |
| relax 히스테리시스: 완화 모드에서 공분산 ×25로 계속 수락, 정상 통과 시 복귀 ("무조건 수락" 제거) | 10.3-③ 락아웃, 10.3-② 급당김 |
| `bias_random_walk_sigma: 0.1→0.2` | 10.3-③ 보조 |

v1.1 검증 주행은 사용자가 직접 수행 예정.

### 10.5 남은 과제

- [ ] v1.1 before/after 정량 비교 (340~413s 랩 비교 재현)
- [ ] **별도 세션 bag 평가** (맵-쿼리 독립; 논문용 숫자는 이것으로)
- [ ] DEGRADED → 감속/MRM 연계 (현재 신호만 발행), Hold 시간·거리 상한
- [ ] /global_pose 에 marginal 공분산 동봉 (하류가 불확실성 소비 가능하게)
- [ ] 게이트 χ² 에 상태 marginal 포함 (수렴도 따라 자동 관대/엄격)
- [ ] odom between 노이즈에 회전 비례 항 (AMCL α1/α4) — 코너 오버슈트 잔여분
- [ ] 장시간 리소스 (iSAM2 무한 성장; 필요시 BatchFixedLagSmoother 재검토)
- [ ] run-to-run 반복 실험 (BBS 시드 분산), 오정합 주입 ablation
- [ ] SE(3) 확장, PCD localizer 재측위 강건화(서술자 fallback)

### 10.6 논문 포지셔닝 메모

- baseline(규칙 기반, src/temp) vs FGO(제안)를 같은 bag으로 A/B — 실험 축 확보.
- novelty 후보: float-GPS **바이어스 상태 온라인 추정**으로 비RTK GPS를 드리프트
  상한 닻으로 활용 + GPS-prior BBS 초기화 + relax 히스테리시스 게이트의 통합 시스템.
- 근거 문헌: `../impl_eval_survey/related_work_37papers.md` (37편, 축별 평결 포함).

## 11. v1.2 — Lost 무음 마비 진단·수정 (2026-08-19, DCU bag)

### 11.1 증상

`record_20260813_142410`(DCU 캠퍼스, 45분) + `DCU_0819` 번들 재생 시:
bag 약 5.5분 지점 커브에서 localizer 가 `MayLost(rejected_max_iterations) -> Lost`
후 **5분 이상 로그 0줄, CPU 100%, /pcd/global_pose 정지, FGO DEGRADED 지속**.
(d2_20260813_v2 와 DCU_0819 는 PCD md5 동일 — 번들 문제 아님.)

### 11.2 원인 사슬 (재현으로 확정)

1. **scan_match 과부하**: 스캔당 500~615ms (예산 100ms), 단일코어 포화 ->
   처리율 2~3Hz. 커브에서 처리 간 이동/회전이 커져 LM `rejected_max_iterations`
   -> MayLost -> Lost.
2. **재초기화 BBS 폭주**: 탐색창이 yaw ±180°(5°/s 성장) x 반경 20m 까지 확장.
   열화 구간(개활 도로)에서는 가지치기가 무력화돼 준-전수 탐색 -> match 1회가
   수 초~수십 초.
3. **투표 리셋 루프 (핵심)**: `vote_timeout_sec: 2.0` 인데 BBS 1회가 2초를
   넘으면 투표 간격 > timeout -> `addGlobalInitVote` 가 매번 리셋 -> **영원히
   3표 합의 불가**. 게다가 재초기화 경로는 `cb scan_match` 프로파일 로그에
   도달하기 전에 return 하고 투표 로그는 8/3 정리 때 주석 처리 -> **완전 무음**.
4. 콜백 점유로 odom 큐(depth 5) 유실 -> "non-continuous timestamp" 오검출 ->
   반경 추가 확장 (악순환).
5. GPS FLOAT + `float_mode: "off"` -> 절대측정 공백 -> watchdog DEGRADED 지속.

### 11.3 수정 (v1.2)

| # | 수정 | 위치 |
|---|---|---|
| 1 | BBS match 1회 **시간 예산** `max_match_seconds: 1.0` (초과 시 best-so-far + timed_out 플래그) | se2_branch_and_bound.{hpp,cpp}, 노드 파라미터 |
| 2 | 재초기화 yaw 상한 **180° -> 45°** (반경 20m 내 odom yaw 가 그 이상 틀릴 수 없음) | fixed_map_localization_bundle.yaml |
| 3 | **재초기화에도 GPS coarse prior 사용**: 신선하면 위치 원을 GPS 중심 clamp(3σ, xy_initial, stop) 로 축소 (yaw 중심은 odom 예측 유지) | relocalizationSearchWindow() |
| 4 | `vote_timeout_sec` 2.0 -> **4.0** (느린 attempt 에도 리셋 방지; 앵커가 odom 상대라 안전) | bundle yaml |
| 5 | prior odom 구독 depth 5 -> **200**, GPS prior 50 (콜백 점유 중 유실 방지) | 노드 QoS |
| 6 | 투표 로그(스로틀 2s)·시드 로그 재활성 + timed_out 표시 (무음 마비 재발 방지) | 노드 |
| 7 | `local_map_radius` 35 -> **25** (scan_match 처리율; 창 포인트 ~절반) | bundle yaml |
| 8 | **float GPS 활성화** `float_mode: "inflated"` (σ x4 약한 닻): PCD 공백 동안 드리프트 상한 + DEGRADED 공백 단축. bias 체인이 float 오프셋 흡수 | fgo_fusion.yaml |

(d2_library 변형 yaml 에도 2/4/7 동일 적용. 검토했으나 보류: BBS 전용 워커
스레드 — 예산 1s + 창 축소로 콜백 점유가 1s 내로 묶여 우선순위 하락.)

### 11.4 수정 후 재현 (offset 240, 주행 중 콜드스타트라는 더 어려운 조건)

- BBS match **16~57ms** (예산 도달 없음), 재초기화 탐색 `radius 2.0~2.6m
  (GPS prior) + yaw ±27~45°`. **무음 마비 소멸** — 투표/시드 로그 연속 흐름.
- 열화 구간 실체 확인: 어느 yaw 로도 score ~0.94 (corner SE(2) 로 본질적 모호)
  -> 투표가 합의를 거부하고 seed 는 6-DoF 정합이 기각 = **오위치 커밋 대신
  정직한 MayLost/Lost 유지**. 이 구간은 맵/특징 한계 (향후: 서술자 fallback).
- 그 동안 FGO 는 float 닻으로 **status OK 유지**, gps_bias (0.18,-0.08) 추정,
  map->odom 계속 갱신. = 설계 의도 그대로 (PCD 공백을 GPS 가 다리 놓기).

### 11.5 알려진 잔여 사항

- Lost/MayLost 상태 표기는 odom 확장 반경 기준이라 GPS prior 로 축소된 실제
  탐색 반경과 어긋날 수 있음 (표기만; 동작 무관).
- 시드 로그는 합의 성공마다 1회 — 주행 중 콜드스타트처럼 합의/기각이 반복되면
  ~2Hz 로 찍힘. 소음이면 스로틀 추가.
- 열화 구간 재획득은 환경이 허용해야 가능 — corner 만 쓰는 SE(2) BBS 의 한계.
