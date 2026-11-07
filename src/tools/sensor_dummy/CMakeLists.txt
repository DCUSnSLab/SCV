cmake_minimum_required(VERSION 3.20)
project(sensor_dummy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -Wextra -Wpedantic)
# Raycasting through unoptimized Eigen takes most of the 100 ms scan period.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(hunter_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(tf2_msgs REQUIRED)
find_package(ublox_msgs REQUIRED)
find_package(yaml_cpp_vendor REQUIRED)

# GeographicLib ships its find module outside the default search path (same as robot_localization).
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "/usr/share/cmake/geographiclib/")
find_package(GeographicLib REQUIRED)

add_library(sensor_dummy_core STATIC
  src/fault.cpp
  src/gnss_model.cpp
  src/imu_model.cpp
  src/lidar_model.cpp
  src/test_pattern.cpp
  src/vehicle_model.cpp
  src/world_map.cpp)
set_target_properties(sensor_dummy_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(sensor_dummy_core PUBLIC src)
target_include_directories(sensor_dummy_core SYSTEM PUBLIC ${GeographicLib_INCLUDE_DIRS})
target_link_libraries(sensor_dummy_core PUBLIC Eigen3::Eigen yaml-cpp ${GeographicLib_LIBRARIES})

# fault_traits.hpp sees every message type, so both components link them all.
set(node_libraries sensor_dummy_core
  ${geometry_msgs_TARGETS} ${hunter_msgs_TARGETS} ${nav_msgs_TARGETS} ${sensor_msgs_TARGETS}
  ${std_msgs_TARGETS} ${tf2_msgs_TARGETS} ${ublox_msgs_TARGETS}
  rclcpp::rclcpp rclcpp_components::component)

add_library(sensor_sim_component SHARED src/sensor_sim.cpp)
target_link_libraries(sensor_sim_component ${node_libraries})
rclcpp_components_register_node(sensor_sim_component
  PLUGIN "sensor_dummy::SensorSim" EXECUTABLE sensor_sim_node)

add_library(camera_dummy_component SHARED src/camera_dummy.cpp)
target_link_libraries(camera_dummy_component ${node_libraries})
rclcpp_components_register_node(camera_dummy_component
  PLUGIN "sensor_dummy::CameraDummy" EXECUTABLE camera_dummy_node)

install(TARGETS sensor_sim_component camera_dummy_component
  ARCHIVE DESTINATION lib LIBRARY DESTINATION lib RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})
# The real calibration, so the beam angles cannot drift from the driver's file.
install(FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/../../sensor_pkg/velodyne/velodyne_pointcloud/params/VeloView-VLP-32C.yaml
  DESTINATION share/${PROJECT_NAME}/config)
ament_python_install_package(${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  find_package(ament_cmake_pytest REQUIRED)
  find_package(launch_testing_ament_cmake REQUIRED)

  ament_add_gtest(test_sensor_dummy_core
    test/test_fault.cpp
    test/test_gnss_model.cpp
    test/test_imu_model.cpp
    test/test_lidar_model.cpp
    test/test_test_pattern.cpp
    test/test_vehicle_model.cpp
    test/test_world_map.cpp)
  target_link_libraries(test_sensor_dummy_core sensor_dummy_core)
  target_compile_definitions(test_sensor_dummy_core PRIVATE
    VLP32C_CALIBRATION="${CMAKE_CURRENT_SOURCE_DIR}/../../sensor_pkg/velodyne/velodyne_pointcloud/params/VeloView-VLP-32C.yaml")

  ament_add_pytest_test(test_launch_helpers test/test_launch_helpers.py)
  add_launch_test(test/test_sensor_dummy_launch.py TIMEOUT 240 ENV ROS_DOMAIN_ID=87)
endif()

ament_package()
