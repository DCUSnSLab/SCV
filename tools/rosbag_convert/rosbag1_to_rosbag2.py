from pathlib import Path
import glob, os, time, logging
from rosbags import convert
import traceback

logFilePath = '/rosbags2/conversion-log.txt'
logging.basicConfig(filename=logFilePath,
                    level=logging.INFO,
                    format='%(asctime)s - %(levelname)s - %(message)s')

SRC_ROOT = Path('/rosbags1')
DST_ROOT = Path('/rosbags2')

all_paths = sorted(
    SRC_ROOT.rglob('*.bag'),                       # **/*.bag 탐색
    key=lambda p: p.stat().st_size                 # 작은 파일부터
)

num_ok = num_fail = 0
for src in all_paths:
    size_mb   = src.stat().st_size >> 20
    t0        = time.time()

    rel_path  = src.relative_to(SRC_ROOT).with_suffix('')  # .bag 제거
    dest_path = DST_ROOT / rel_path                        # 최종 dir

    dest_path.parent.mkdir(parents=True, exist_ok=True)    # 폴더 생성

    try:
        convert.convert(src, dest_path)
        num_ok += 1
    except convert.converter.ConverterError:
        num_fail += 1
        logging.error(traceback.format_exc())
    finally:
        dt = time.time() - t0
        logging.info(f'{num_ok+num_fail}/{len(all_paths)} | {src.name} '
                     f'({size_mb} MB) → {dest_path}  [{dt:.1f}s]  '
                     f'Success:{num_ok} Fail:{num_fail}')
