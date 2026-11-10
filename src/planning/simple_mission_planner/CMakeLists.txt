cmake_minimum_required(VERSION 3.16)
project(simple_mission_planner)

# colcon passes no build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(simple_sd_map_msgs REQUIRED)
find_package(std_msgs REQUIRED)

add_library(simple_mission_planner_component SHARED
  src/route_graph.cpp
  src/simple_mission_planner.cpp)
target_compile_features(simple_mission_planner_component PRIVATE cxx_std_17)
target_compile_options(simple_mission_planner_component PRIVATE -Wall -Wextra -Wpedantic)
ament_target_dependencies(simple_mission_planner_component geometry_msgs nav_msgs rclcpp
  rclcpp_components simple_sd_map_msgs std_msgs)
rclcpp_components_register_node(simple_mission_planner_component
  PLUGIN "simple_mission_planner::SimpleMissionPlanner" EXECUTABLE simple_mission_planner_node)

install(TARGETS simple_mission_planner_component
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_route_graph test/test_route_graph.cpp src/route_graph.cpp)
  target_compile_features(test_route_graph PRIVATE cxx_std_17)
  target_include_directories(test_route_graph PRIVATE src)

  # A private domain keeps other nodes on this host out of the test.
  ament_add_gtest(test_simple_mission_planner_node test/test_simple_mission_planner_node.cpp
    ENV ROS_DOMAIN_ID=90 ROS_AUTOMATIC_DISCOVERY_RANGE=LOCALHOST)
  target_compile_features(test_simple_mission_planner_node PRIVATE cxx_std_17)
  target_include_directories(test_simple_mission_planner_node PRIVATE src)
  target_link_libraries(test_simple_mission_planner_node simple_mission_planner_component)
  ament_target_dependencies(test_simple_mission_planner_node geometry_msgs nav_msgs rclcpp
    simple_sd_map_msgs)
endif()

ament_package()
