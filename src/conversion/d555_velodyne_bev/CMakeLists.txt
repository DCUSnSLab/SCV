cmake_minimum_required(VERSION 3.8)
project(d555_velodyne_bev)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -O3)
endif()

find_package(ament_cmake REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)

add_executable(d555_velodyne_bev_node src/d555_velodyne_bev_node.cpp)
target_compile_features(d555_velodyne_bev_node PUBLIC cxx_std_17)
ament_target_dependencies(d555_velodyne_bev_node
  cv_bridge rclcpp sensor_msgs tf2_ros)
target_link_libraries(d555_velodyne_bev_node ${OpenCV_LIBS})

install(TARGETS d555_velodyne_bev_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
