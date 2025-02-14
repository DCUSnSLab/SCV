cmake_minimum_required(VERSION 3.0.2)
project(ros_monitor)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP jsoncpp)

add_message_files(
  FILES
  NodeStatus.msg
  # Message1.msg
  # Message2.msg
)


generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES vehicle_diag
#  CATKIN_DEPENDS rospy_std_msgs
#  DEPENDS system_lib
  CATKIN_DEPENDS roscpp std_msgs geometry_msgs message_runtime
)

include_directories(
  #include
  ${catkin_INCLUDE_DIRS}
  ${JSONCPP_INCLUDE_DIRS}
  /usr/local/cuda-12.6/targets/x86_64-linux/include  # NVML header path
)

link_directories(
  /usr/local/cuda-12.6/targets/x86_64-linux/lib/stubs  # NVML library path
)