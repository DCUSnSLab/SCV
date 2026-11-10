cmake_minimum_required(VERSION 3.16)
project(semantic_segmentation_yolo26_trt)

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

add_library(semantic_segmentation_yolo26_trt_component SHARED src/semantic_segmentation_yolo26_trt.cpp)
target_compile_features(semantic_segmentation_yolo26_trt_component PRIVATE cxx_std_17)
target_compile_options(semantic_segmentation_yolo26_trt_component PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(semantic_segmentation_yolo26_trt_component
  flux_wrapper::flux_wrapper tensorrt_common::tensorrt_common)
ament_target_dependencies(semantic_segmentation_yolo26_trt_component rclcpp rclcpp_components sensor_msgs)
rclcpp_components_register_node(semantic_segmentation_yolo26_trt_component
  PLUGIN "semantic_segmentation_yolo26_trt::SemanticSegmentationYolo26Trt" EXECUTABLE semantic_segmentation_yolo26_trt_node)

install(TARGETS semantic_segmentation_yolo26_trt_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})

ament_package()
