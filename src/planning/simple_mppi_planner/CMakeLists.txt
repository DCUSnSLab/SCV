cmake_minimum_required(VERSION 3.16)
project(simple_mppi_planner)

# colcon passes no build type, and an unoptimized rollout is about ten times slower.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(diagnostic_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(OpenMP REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)

add_library(simple_mppi_planner_core STATIC
  src/distance_map.cpp
  src/mppi_solver.cpp
  src/reference_path.cpp
  src/savitzky_golay.cpp)
set_target_properties(simple_mppi_planner_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_compile_features(simple_mppi_planner_core PUBLIC cxx_std_17)
target_compile_options(simple_mppi_planner_core PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(simple_mppi_planner_core PUBLIC OpenMP::OpenMP_CXX)

add_library(simple_mppi_planner_component SHARED src/simple_mppi_planner.cpp)
target_compile_features(simple_mppi_planner_component PRIVATE cxx_std_17)
target_compile_options(simple_mppi_planner_component PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(simple_mppi_planner_component simple_mppi_planner_core)
ament_target_dependencies(simple_mppi_planner_component diagnostic_msgs geometry_msgs nav_msgs
  rclcpp rclcpp_components)
rclcpp_components_register_node(simple_mppi_planner_component
  PLUGIN "simple_mppi_planner::SimpleMppiPlanner" EXECUTABLE simple_mppi_planner_node)

install(TARGETS simple_mppi_planner_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
install(DIRECTORY config launch DESTINATION share/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  foreach(name distance_map motion_model reference_path savitzky_golay progress_monitor mppi_solver)
    ament_add_gtest(test_${name} test/test_${name}.cpp TIMEOUT 120)
    target_include_directories(test_${name} PRIVATE src)
    target_link_libraries(test_${name} simple_mppi_planner_core)
  endforeach()

  # A private domain keeps other nodes on this host out of the test.
  ament_add_gtest(test_simple_mppi_planner_node test/test_simple_mppi_planner_node.cpp
    ENV ROS_DOMAIN_ID=88 ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST)
  target_compile_features(test_simple_mppi_planner_node PRIVATE cxx_std_17)
  target_include_directories(test_simple_mppi_planner_node PRIVATE src)
  target_link_libraries(test_simple_mppi_planner_node simple_mppi_planner_component)
  ament_target_dependencies(test_simple_mppi_planner_node diagnostic_msgs geometry_msgs nav_msgs
    rclcpp)

  # Not a test: prints the planning cycle time. Pin it to a core with taskset.
  add_executable(bench_planning_cycle test/bench_planning_cycle.cpp)
  target_include_directories(bench_planning_cycle PRIVATE src)
  target_link_libraries(bench_planning_cycle simple_mppi_planner_core)
endif()

ament_package()
