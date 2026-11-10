cmake_minimum_required(VERSION 3.16)
project(depth_anything3_multiview_trt)

# colcon passes no build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(flux_wrapper REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tensorrt_common REQUIRED)
find_package(tf2 REQUIRED)

add_library(depth_anything3_multiview_trt_component SHARED
  src/views.cpp
  src/depth_anything3_multiview_trt.cpp)
target_compile_features(depth_anything3_multiview_trt_component PRIVATE cxx_std_17)
target_compile_options(depth_anything3_multiview_trt_component PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(depth_anything3_multiview_trt_component
  flux_wrapper::flux_wrapper tensorrt_common::tensorrt_common tf2::tf2)
ament_target_dependencies(depth_anything3_multiview_trt_component
  geometry_msgs rclcpp rclcpp_components sensor_msgs)
rclcpp_components_register_node(depth_anything3_multiview_trt_component
  PLUGIN "depth_anything3_multiview_trt::DepthAnything3MultiviewTrt"
  EXECUTABLE depth_anything3_multiview_trt_node)

install(TARGETS depth_anything3_multiview_trt_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})
install(PROGRAMS scripts/export_onnx.py DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_views test/test_views.cpp src/views.cpp)
  target_include_directories(test_views PRIVATE src)
  target_link_libraries(test_views tensorrt_common::tensorrt_common tf2::tf2)
endif()

ament_package()
