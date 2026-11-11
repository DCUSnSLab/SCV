#!/usr/bin/env python3
"""Export an Ultralytics YOLO26 model to the ONNX file that the yolo26 nodes read.

export_yolo26_onnx.py --model <release name or .pt> --output <file.onnx> [--half]

A release name that is not a file yet is downloaded to that path. The export is batch 1, 640x640
and NMS-free (nms=False). It is made in a temporary directory and moved to --output at the end.
"""

import argparse
import os
from pathlib import Path
import shutil
import tempfile

# Ultralytics would pip-install a missing optional package from inside the node.
os.environ.setdefault('YOLO_AUTOINSTALL', 'false')
from ultralytics import YOLO  # noqa: E402


def main():
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument('--model', required=True)
    parser.add_argument('--output', required=True)
    parser.add_argument('--half', action='store_true')
    args = parser.parse_args()

    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    source = YOLO(args.model).ckpt_path
    with tempfile.TemporaryDirectory(dir=output.parent) as tmp:
        weights = Path(tmp) / Path(source).name
        shutil.copy(source, weights)
        exported = YOLO(str(weights)).export(
            format='onnx',
            imgsz=640,
            batch=1,
            nms=False,
            half=args.half,
            device=0 if args.half else None,
        )
        os.replace(exported, output)


if __name__ == '__main__':
    main()
