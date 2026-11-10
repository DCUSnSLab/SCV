cmake_minimum_required(VERSION 3.16)
project(instance_segmentation_yolo26_trt)

# colcon passes no build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(flux_wrapper REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tensorrt_common REQUIRED)
find_package(vision_msgs REQUIRED)

add_library(instance_segmentation_yolo26_trt_component SHARED
  src/instance_mask.cpp
  src/instance_segmentation_yolo26_trt.cpp)
target_compile_features(instance_segmentation_yolo26_trt_component PRIVATE cxx_std_17)
target_compile_options(instance_segmentation_yolo26_trt_component PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(instance_segmentation_yolo26_trt_component
  flux_wrapper::flux_wrapper tensorrt_common::tensorrt_common)
ament_target_dependencies(instance_segmentation_yolo26_trt_component rclcpp rclcpp_components sensor_msgs vision_msgs)
rclcpp_components_register_node(instance_segmentation_yolo26_trt_component
  PLUGIN "instance_segmentation_yolo26_trt::InstanceSegmentationYolo26Trt" EXECUTABLE instance_segmentation_yolo26_trt_node)

install(TARGETS instance_segmentation_yolo26_trt_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_instance_mask test/test_instance_mask.cpp src/instance_mask.cpp)
  target_include_directories(test_instance_mask PRIVATE src)
  target_link_libraries(test_instance_mask tensorrt_common::tensorrt_common)

  # Not a test: prints the time of instance_mask. Pin it to a core with taskset.
  add_executable(bench_instance_mask test/bench_instance_mask.cpp src/instance_mask.cpp)
  target_include_directories(bench_instance_mask PRIVATE src)
  target_link_libraries(bench_instance_mask tensorrt_common::tensorrt_common)
endif()

ament_package()
