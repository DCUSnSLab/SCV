"""Writes the identity ONNX files of test_preprocess: input image (1, 3, H, W) -> output copy."""

import onnx
from onnx import TensorProto, helper

for h, w in [(640, 640), (280, 504)]:
    shape = [1, 3, h, w]
    graph = helper.make_graph(
        [helper.make_node('Identity', ['image'], ['copy'])],
        'identity',
        [helper.make_tensor_value_info('image', TensorProto.FLOAT, shape)],
        [helper.make_tensor_value_info('copy', TensorProto.FLOAT, shape)],
    )
    model = helper.make_model(graph, opset_imports=[helper.make_opsetid('', 17)])
    model.ir_version = 8
    onnx.save(model, f'identity_{h}x{w}.onnx')
