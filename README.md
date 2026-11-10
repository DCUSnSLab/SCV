# SCV (Service Co-operation Vehicle)

ROS 2 Jazzy colcon 작업공간이다. `src/` 아래 외부 저장소는 이 저장소에 들어 있지 않다. `dependencies.repos`가 각 저장소의 주소와 커밋을 고정하고, `vcs`로 받는다.

## 받기와 빌드

`vcs`는 `python3-vcstool` 패키지로 설치한다. `rosdep`은 처음 한 번 `sudo rosdep init`을 해 둬야 한다.

realsense-ros는 librealsense 2.59 이상을 요구하는데, ROS apt의 `ros-jazzy-librealsense2`는 2.58이다. `scripts/setup_librealsense.sh`는 RealSense apt 저장소를 추가하고, rosdep 키 `librealsense2`가 그 저장소의 `librealsense2-dev`로 풀리게 한다(`scripts/rosdep.yaml`). `ros-jazzy-librealsense2`가 설치돼 있으면 지운다. 머신마다 한 번 실행한다.

```bash
git clone https://github.com/DCUSnSLab/SCV.git
cd SCV
vcs import --recursive src < dependencies.repos
sudo apt install ros-jazzy-zed-msgs
source /opt/ros/jazzy/setup.bash
scripts/setup_librealsense.sh
rosdep install --from-paths src --ignore-src -y --rosdistro jazzy
ENABLE_FLUX=1 colcon build --symlink-install
```

- 일부 저장소 안에는 submodule이 있어서 `--recursive`로 받아야 한다.
- `zed_msgs`는 소스로 받지 않고 apt 패키지를 쓴다.
- 센서 드라이버와 영상 노드는 `flux_wrapper`로 발행하고 구독한다. `flux_wrapper`는 빌드할 때의 `ENABLE_FLUX`로 flux를 쓸지 정하므로, flux를 쓰려면 `ENABLE_FLUX=1`로 빌드한다. 실행할 때도 같은 값을 둔다.

## 지도

지도 파일은 git에 넣지 않는다. 작업공간 루트의 `maps/`에 직접 복사한다. 설정 파일은 `maps/` 기준 상대 경로를 적고, launch가 앞에 작업공간의 `maps/` 경로를 붙인다.

| 파일                                                     | 설정                                                |
| -------------------------------------------------------- | --------------------------------------------------- |
| `maps/d2_20260813_v2/ndt_map_0p4.pcd`, `full_corner.pcd` | `prior_map_localization`의 `config/map.param.yaml`  |
| `maps/d2_20260813_v2/path.osm`                           | `simple_sd_map`의 `config/simple_sd_map.param.yaml` |

## 저장소 버전 올리기

1. `dependencies.repos`에서 해당 저장소의 `version`을 새 커밋으로 바꾼다.
2. `vcs import --recursive src < dependencies.repos`로 받는다.
3. 빌드하고 시험한 뒤 `dependencies.repos`를 커밋한다.

## 코드 스타일

린터와 포맷터는 이 저장소가 추적하는 파일에만 적용된다. `dependencies.repos`로 받은 저장소는 자기 스타일을 따르므로 대상이 아니다. 별도 설정 없이 그렇게 동작한다.

```bash
scripts/install_hooks.sh
```

- 편집기의 저장 시 자동 포맷을 쓰면 포크 파일도 바뀐다. clang-format은 가장 가까운 `.clang-format`을 찾아 쓰므로, 자기 설정이 없는 포크에는 이 저장소의 스타일이 적용된다.
- `ruff`, `prettier`, `yamllint`은 `.gitignore`를 따른다. `flake8`은 커밋할 때 추적 파일에만 돈다.
- 별도 저장소로 받은 직접 작성 패키지는 `scripts/lint.sh <경로>`로 같은 설정을 적용한다. 그 저장소에 설정 파일을 따로 두지 않는다.
- 새 저장소를 `dependencies.repos`에 넣으면 `.gitignore`에도 넣는다. 빠뜨리면 커밋할 때 `repos-ignored` 검사가 알린다.
