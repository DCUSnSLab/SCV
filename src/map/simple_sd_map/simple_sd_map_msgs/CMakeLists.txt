cmake_minimum_required(VERSION 3.8)
project(simple_sd_map_msgs)

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(diagnostic_msgs REQUIRED)
find_package(std_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SdNode.msg"
  "msg/SdEdge.msg"
  "msg/SdMap.msg"
  DEPENDENCIES diagnostic_msgs std_msgs
)

ament_export_dependencies(rosidl_default_runtime)
ament_package()
