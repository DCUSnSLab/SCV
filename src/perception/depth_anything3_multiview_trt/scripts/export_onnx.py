"""Export a Depth Anything 3 any-view model to ONNX with a fixed number of views and input size.

python3 export_onnx.py --model depth-anything/DA3-BASE --views 3 \
    --image-width 1280 --image-height 720 --output da3_base_3views.onnx [--half]

The input size follows the Depth Anything 3 preprocessing: the longest side is resized to
--process-res, then each side to the nearest multiple of 14. The first view is the reference
view (ref_view_strategy "first"). Outputs: depth and depth_conf (1, N, H, W), and the camera
pose encoding (1, N, 9): translation, quaternion xyzw and field of view (h, w) of each
camera-to-world transform.
"""

import argparse

import torch
from depth_anything_3.api import DepthAnything3

PATCH = 14


def cartesian_prod(a, b):
    y, x = torch.meshgrid(a, b, indexing='ij')
    return torch.stack([y.reshape(-1), x.reshape(-1)], dim=1)


# The RoPE positions of the any-view models use torch.cartesian_prod, which ONNX does not have;
# this is the same product of two 1-D tensors in operators that it has.
torch.cartesian_prod = cartesian_prod


def nearest_multiple(x, p):
    down = (x // p) * p
    up = down + p
    return up if abs(up - x) <= abs(x - down) else down


def input_size(width, height, process_res):
    scale = process_res / max(width, height)
    w = max(1, round(width * scale))
    h = max(1, round(height * scale))
    return nearest_multiple(w, PATCH), nearest_multiple(h, PATCH)


class MultiView(torch.nn.Module):
    def __init__(self, net):
        super().__init__()
        self.net = net

    def forward(self, images):
        n, h, w = images.shape[1], images.shape[-2], images.shape[-1]
        feats, _ = self.net.backbone(
            images, cam_token=None, export_feat_layers=[], ref_view_strategy='first'
        )
        out = self.net.head(feats, h, w, patch_start_idx=0)
        pose = self.net.cam_dec(feats[-1][1])
        return out['depth'].reshape(1, n, h, w), out['depth_conf'].reshape(1, n, h, w), pose


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--model', required=True)
    parser.add_argument('--views', type=int, required=True)
    parser.add_argument('--image-width', type=int, required=True)
    parser.add_argument('--image-height', type=int, required=True)
    parser.add_argument('--process-res', type=int, default=504)
    parser.add_argument('--output', required=True)
    parser.add_argument('--half', action='store_true')
    parser.add_argument('--opset', type=int, default=17)
    args = parser.parse_args()

    net = DepthAnything3.from_pretrained(args.model).model.eval()
    module = MultiView(net)
    w, h = input_size(args.image_width, args.image_height, args.process_res)
    dtype = torch.float16 if args.half else torch.float32
    device = 'cuda' if args.half else 'cpu'
    module = module.to(device=device, dtype=dtype)
    images = torch.zeros(1, args.views, 3, h, w, device=device, dtype=dtype)
    with torch.no_grad():
        torch.onnx.export(
            module,
            (images,),
            args.output,
            input_names=['images'],
            output_names=['depth', 'depth_conf', 'pose'],
            opset_version=args.opset,
            dynamo=False,
        )
    print(f'{args.output}: input 1x{args.views}x3x{h}x{w}')


if __name__ == '__main__':
    main()
