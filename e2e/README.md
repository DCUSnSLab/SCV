# e2e 기능 시험

원격조종과 모니터링을 서버, 차량, 관제 세 쪽으로 띄워서 기능을 끝까지 확인한다. 단위 시험과 달리 실제 프로그램을 실제 연결로 잇는다. `src/` 아래 받아 둔 커밋이 시험 대상이다.

```bash
e2e/run.sh              # 빌드하고 시험한 뒤 컨테이너를 내린다
e2e/run.sh --no-build   # 빌드는 건너뛴다
e2e/run.sh --keep       # 끝나도 컨테이너를 남긴다(docker compose -p scv-e2e -f e2e/compose.yaml)
```

모두 통과하면 `ALL PASSED`를 찍고 0으로 끝난다. 실패하면 1로 끝나고, 컨테이너 로그는 `e2e/.work/logs/`에 남는다.

## 구성

```
docker network (internal, 172.31.77.0/24)
 ├─ zenohd + fleetd   서버. tierlink deploy/server와 같은 이미지와 설정이다
 ├─ vehicle           sensor_dummy -> teleop_video, teleop_control, fleet_telemetry, hunter_mux
 │                    tierlink_edge ── TCP + UDP ──> zenohd
 └─ operator          operator_check (tierlink operator/의 link.rs와 영상 디코더)
```

| 파일                | 내용                                                                                       |
| ------------------- | ------------------------------------------------------------------------------------------ |
| `run.sh`            | 빌드, 컨테이너 기동, 시험 단계, netem 적용, 정리                                           |
| `compose.yaml`      | 서버, 차량, 관제 컨테이너와 내부 네트워크                                                  |
| `vehicle.sh`        | 차량 컨테이너의 시작 스크립트. `tierlink_edge`를 띄운 뒤 `vehicle.launch.py`를 띄운다      |
| `vehicle.launch.py` | 차량 노드들. `teleop_start.launch.py`의 연결을 따르고 hunter_base 대신 sensor_dummy를 쓴다 |
| `fleetd.yaml`       | 시험용 fleetd 설정                                                                         |

- 차량과 관제 컨테이너는 호스트의 `/usr`, `/opt/ros`, 이 작업공간을 읽기 전용으로 붙여서 호스트의 ROS 2와 빌드 결과를 그대로 쓴다. 네트워크만 분리한다.
- 네트워크는 `internal`이라 바깥으로 나가지 않는다. 컨테이너 안의 DDS는 `ROS_DOMAIN_ID=42`, `LOCALHOST` 범위라서 호스트의 ROS 그래프에 보이지 않는다.
- 빌드는 `e2e/.work/`에 따로 한다. 작업공간의 `build/`, `install/`과 호출한 셸의 환경은 쓰지 않는다. 처음 빌드는 2분쯤 걸린다.
- 영상 인코더는 `x265enc`로 바꿔서 돌린다. 컨테이너에는 GPU 인코더가 없다.

## 시험 단계

`operator_check`의 단계다. 무엇을 확인하는지는 tierlink `docs/design.md` 5.6에 있다.

| 링크 조건             | 단계                                                                        |
| --------------------- | --------------------------------------------------------------------------- |
| 깨끗한 링크           | fleet, video, drive, limit, watchdog, takeover, stop, estop, lidar, history |
| 차량 상향 지연 200 ms | degrade                                                                     |
| 차량 상향 손실 2%     | loss                                                                        |

확인하지 않는 것은 다음과 같다.

- 실제 차량, 실제 카메라와 라이다, GPU 인코더
- 관제 프로그램의 화면과 입력 장치
- LTE처럼 대역이 바뀌는 링크. 대역 변화는 tierlink `tools/bench`가 잰다
