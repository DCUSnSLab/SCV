"""Export a Depth Anything 3 monocular model to ONNX with a fixed input size.

python3 export_onnx.py --model depth-anything/DA3METRIC-LARGE \
    --image-width 1280 --image-height 720 --output da3metric_large.onnx [--half]

The input size follows the Depth Anything 3 preprocessing: the longest side is resized to
--process-res, then each side to the nearest multiple of 14. The node resizes every image to it,
so export one file per camera aspect ratio. Outputs: depth (1, H, W) and sky (1, H, W).
"""

import argparse

import torch
from depth_anything_3.api import DepthAnything3

PATCH = 14


def nearest_multiple(x, p):
    down = (x // p) * p
    up = down + p
    return up if abs(up - x) <= abs(x - down) else down


def input_size(width, height, process_res):
    scale = process_res / max(width, height)
    w = max(1, round(width * scale))
    h = max(1, round(height * scale))
    return nearest_multiple(w, PATCH), nearest_multiple(h, PATCH)


class Monocular(torch.nn.Module):
    def __init__(self, net):
        super().__init__()
        self.net = net

    def forward(self, image):
        h, w = image.shape[-2:]
        feats, _ = self.net.backbone(
            image[:, None], cam_token=None, export_feat_layers=[], ref_view_strategy='first'
        )
        out = self.net.head(feats, h, w, patch_start_idx=0)
        return out['depth'].reshape(1, h, w), out['sky'].reshape(1, h, w)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--model', required=True)
    parser.add_argument('--image-width', type=int, required=True)
    parser.add_argument('--image-height', type=int, required=True)
    parser.add_argument('--process-res', type=int, default=504)
    parser.add_argument('--output', required=True)
    parser.add_argument('--half', action='store_true')
    parser.add_argument('--opset', type=int, default=17)
    args = parser.parse_args()

    net = DepthAnything3.from_pretrained(args.model).model.eval()
    module = Monocular(net)
    w, h = input_size(args.image_width, args.image_height, args.process_res)
    dtype = torch.float16 if args.half else torch.float32
    device = 'cuda' if args.half else 'cpu'
    module = module.to(device=device, dtype=dtype)
    image = torch.zeros(1, 3, h, w, device=device, dtype=dtype)
    with torch.no_grad():
        torch.onnx.export(
            module,
            (image,),
            args.output,
            input_names=['image'],
            output_names=['depth', 'sky'],
            opset_version=args.opset,
            dynamo=False,
        )
    print(f'{args.output}: input 1x3x{h}x{w}')


if __name__ == '__main__':
    main()
