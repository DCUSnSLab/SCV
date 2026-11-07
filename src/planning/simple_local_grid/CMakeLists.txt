cmake_minimum_required(VERSION 3.16)
project(simple_local_grid)

# colcon passes no build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(flux_cpp REQUIRED)
find_package(flux_std_adapters REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_eigen REQUIRED)
find_package(tf2_ros REQUIRED)

add_library(simple_local_grid_component SHARED
  src/rolling_grid.cpp
  src/simple_local_grid.cpp)
target_compile_features(simple_local_grid_component PRIVATE cxx_std_17)
target_compile_options(simple_local_grid_component PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(simple_local_grid_component PRIVATE ${flux_std_adapters_INCLUDE_DIRS})
target_link_libraries(simple_local_grid_component flux_cpp::flux_cpp Eigen3::Eigen)
ament_target_dependencies(simple_local_grid_component nav_msgs rclcpp rclcpp_components sensor_msgs
  tf2_eigen tf2_ros)
rclcpp_components_register_node(simple_local_grid_component
  PLUGIN "simple_local_grid::SimpleLocalGrid" EXECUTABLE simple_local_grid_node)

install(TARGETS simple_local_grid_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_rolling_grid test/test_rolling_grid.cpp src/rolling_grid.cpp)
  target_include_directories(test_rolling_grid PRIVATE src)
  target_link_libraries(test_rolling_grid Eigen3::Eigen)

  # A private domain keeps /tf from any robot or simulator on this host out of the test.
  ament_add_gtest(test_simple_local_grid_node test/test_simple_local_grid_node.cpp
    ENV ROS_DOMAIN_ID=87 ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST)
  target_compile_features(test_simple_local_grid_node PRIVATE cxx_std_17)
  target_include_directories(test_simple_local_grid_node PRIVATE src
    ${flux_std_adapters_INCLUDE_DIRS})
  target_link_libraries(test_simple_local_grid_node simple_local_grid_component)
  ament_target_dependencies(test_simple_local_grid_node nav_msgs rclcpp sensor_msgs tf2_ros)

  # Not a test: prints the time of one scan. Pin it to a core with taskset.
  add_executable(bench_grid_insert test/bench_grid_insert.cpp src/rolling_grid.cpp)
  target_compile_features(bench_grid_insert PRIVATE cxx_std_17)
  target_include_directories(bench_grid_insert PRIVATE src)
  target_link_libraries(bench_grid_insert Eigen3::Eigen)
endif()

ament_package()
