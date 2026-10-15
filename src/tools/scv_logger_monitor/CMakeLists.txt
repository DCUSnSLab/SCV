cmake_minimum_required(VERSION 3.8)
project(scv_logger_monitor)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(scv_logger_monitor src/monitor_node.cpp)
ament_target_dependencies(scv_logger_monitor rclcpp std_msgs sensor_msgs tf2_msgs)
target_link_libraries(scv_logger_monitor nlohmann_json::nlohmann_json)

install(TARGETS scv_logger_monitor DESTINATION lib/${PROJECT_NAME})
ament_package()
