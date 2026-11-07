# SCV (Service Co-operation Vehicle)

ROS 2 Jazzy colcon 작업공간이다. `src/` 아래 외부 저장소는 이 저장소에 들어 있지 않다. `dependencies.repos`가 각 저장소의 주소와 커밋을 고정하고, `vcs`로 받는다.

## 받기와 빌드

`vcs`는 `python3-vcstool` 패키지로 설치한다.

```bash
git clone https://github.com/DCUSnSLab/SCV.git
cd SCV
vcs import --recursive src < dependencies.repos
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install
```

일부 저장소 안에는 submodule이 있어서 `--recursive`로 받아야 한다.

## 저장소 버전 올리기

1. `dependencies.repos`에서 해당 저장소의 `version`을 새 커밋으로 바꾼다.
2. `vcs import --recursive src < dependencies.repos`로 받는다.
3. 빌드하고 시험한 뒤 `dependencies.repos`를 커밋한다.

## 코드 스타일

린터와 포맷터는 이 저장소가 추적하는 파일에만 적용된다. `dependencies.repos`로 받은 저장소는 자기 스타일을 따르므로 대상이 아니다. 별도 설정 없이 그렇게 동작한다.

```bash
scripts/install_hooks.sh
```

- `src/.clang-format`이 `src/` 전체의 clang-format을 끈다. 이 저장소의 패키지는 자기 폴더의 `.clang-format`으로 켠다.
- `ruff`, `prettier`, `yamllint`은 `.gitignore`를 따른다. `flake8`은 커밋할 때 추적 파일에만 돈다.
- 별도 저장소로 받은 직접 작성 패키지는 `scripts/lint.sh <경로>`로 같은 설정을 적용한다. 그 저장소에 설정 파일을 따로 두지 않는다.
- 새 저장소를 `dependencies.repos`에 넣으면 `.gitignore`에도 넣는다. 빠뜨리면 커밋할 때 `repos-ignored` 검사가 알린다.
