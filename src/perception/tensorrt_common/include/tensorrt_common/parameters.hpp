#ifndef TENSORRT_COMMON__PARAMETERS_HPP_
#define TENSORRT_COMMON__PARAMETERS_HPP_

#include "tensorrt_common/engine.hpp"

#include <rclcpp/rclcpp.hpp>

#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <string>

namespace tensorrt_common
{

// The tensorrt.* parameters of a node. Header only, so that this library does not link rclcpp.
inline auto declare_engine_options(rclcpp::Node & node) -> EngineOptions
{
  EngineOptions o;
  o.onnx_path = node.declare_parameter<std::string>("tensorrt.onnx_path");
  o.engine_path = node.declare_parameter<std::string>("tensorrt.engine_path");
  o.workspace_bytes =
    static_cast<std::size_t>(node.declare_parameter<std::int64_t>("tensorrt.workspace_mb")) << 20;
  o.tf32 = node.declare_parameter<bool>("tensorrt.tf32");
  o.optimization_level =
    static_cast<int>(node.declare_parameter<std::int64_t>("tensorrt.optimization_level"));
  o.timing_cache_path = node.declare_parameter<std::string>("tensorrt.timing_cache_path");
  o.dla_core = static_cast<int>(node.declare_parameter<std::int64_t>("tensorrt.dla_core"));
  if (o.onnx_path.empty() || o.engine_path.empty()) {
    throw std::invalid_argument(
      "set tensorrt.onnx_path and tensorrt.engine_path in the param file");
  }
  return o;
}

// preprocess: gpu (the kernel of Engine::upload_image) or cpu (OpenCV, the reference).
inline auto declare_gpu_preprocess(rclcpp::Node & node) -> bool
{
  const auto v = node.declare_parameter<std::string>("preprocess");
  if (v != "gpu" && v != "cpu") {
    throw std::invalid_argument("preprocess must be gpu or cpu, got " + v);
  }
  return v == "gpu";
}

}  // namespace tensorrt_common

#endif  // TENSORRT_COMMON__PARAMETERS_HPP_
