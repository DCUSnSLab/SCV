#!/usr/bin/env bash
# SCV 워크스페이스 submodule 초기화 (견고/멱등).
#
# 기본 `git submodule update --init --recursive` 는 도중에 클론 불가한
# submodule(예: 원격 저장소가 사라진 nev_teleop_bot)을 만나면 전체가 중단되고,
# 이미 일부는 .git 만 남고 작업트리가 비는 문제가 있다.
# 이 스크립트는 알려진 불가 모듈을 건너뛰고 나머지를 --force 로 끝까지 채운다.
#
# 사용법:  ./tools/init_workspace.sh
set -u

cd "$(git rev-parse --show-toplevel)"

# 원격 저장소가 없거나 접근 불가하여 의도적으로 건너뛰는 submodule 경로.
# (복구되면 이 목록에서 제거)
SKIP_PATHS=(
    "src/teleop/nev_teleop_bot"   # github.com/nevlife/nev_teleop_bot: Repository not found
)

is_skipped() {
    local p="$1"
    for s in "${SKIP_PATHS[@]}"; do
        [ "$p" = "$s" ] && return 0
    done
    return 1
}

echo "[init] submodule 목록 확인..."
ALL_PATHS=$(git config -f .gitmodules --get-regexp 'submodule\..*\.path' | awk '{print $2}')

TARGETS=()
for p in $ALL_PATHS; do
    if is_skipped "$p"; then
        echo "[init]  건너뜀(알려진 불가): $p"
    else
        TARGETS+=("$p")
    fi
done

echo "[init] ${#TARGETS[@]}개 submodule 초기화(--init --force --recursive)..."
if git submodule update --init --force --recursive -- "${TARGETS[@]}"; then
    echo "[init] OK"
else
    echo "[init] 경고: 일부 submodule 업데이트 실패. 위 로그 확인." >&2
fi

echo
echo "[init] 최종 상태:"
git submodule status -- "${TARGETS[@]}" | awk '{
    flag=substr($0,1,1);
    if (flag=="-")      tag="미초기화";
    else if (flag=="+") tag="커밋불일치";
    else                tag="정상";
    printf "  [%s] %s\n", tag, $2
}'

echo
echo "[init] 건너뛴 submodule:"
for s in "${SKIP_PATHS[@]}"; do echo "  [skip] $s"; done
echo "[init] 완료. 빌드는 docker/README.md 참고."
