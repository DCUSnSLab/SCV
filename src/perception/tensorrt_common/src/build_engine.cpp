// A command, not a node: builds the engine of a param file ahead of the first start, with the
// same tensorrt.* parameters the node reads, so that both produce the same engine.
//
//   ros2 run tensorrt_common build_engine --ros-args --params-file <node>.param.yaml

#include "tensorrt_common/engine.hpp"
#include "tensorrt_common/parameters.hpp"

#include <rclcpp/rclcpp.hpp>

#include <exception>
#include <memory>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  const auto node = std::make_shared<rclcpp::Node>("build_engine");
  int status = 0;
  try {
    const auto options = tensorrt_common::declare_engine_options(*node);
    tensorrt_common::build_engine_file(options);
    RCLCPP_INFO(node->get_logger(), "wrote %s", options.engine_path.c_str());
  } catch (const std::exception & e) {
    RCLCPP_ERROR(node->get_logger(), "%s", e.what());
    status = 1;
  }
  rclcpp::shutdown();
  return status;
}
