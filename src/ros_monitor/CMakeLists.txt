cmake_minimum_required(VERSION 3.10)
project(ros_monitor LANGUAGES CXX CUDA)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  message_generation
)

find_library(NVML_LIBRARY NAMES nvidia-ml libnvidia-ml)

if(NVML_LIBRARY)
  message(STATUS "Found NVML: ${NVML_LIBRARY}")
else()
  message(FATAL_ERROR "NVML library not found")
endif()

find_package(PkgConfig REQUIRED)
find_package(CUDA REQUIRED)

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
  ${catkin_INCLUDE_DIRS}
  ${JSONCPP_INCLUDE_DIRS}
  ${CUDA_TOOLKIT_INCLUDE_DIRS}
  ${CUDA_BASE}/targets/x86_64-linux/include  # NVML 헤더 경로
  ${CUDA_BASE}/extras/CUPTI/include           # CUPTI 헤더 경로 (사용하는 경우)
)

link_directories(
  ${CUDA_BASE}/targets/x86_64-linux/lib/stubs  # NVML library path
)

set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

set(CUPTI_LIB_PATH "/usr/local/cuda-12.6/targets/x86_64-linux/lib/") #lib의 부모 디렉토리

find_library(CUPTI_LIBRARY NAMES cupti PATHS ${CUPTI_LIB_PATH})
if(CUPTI_LIBRARY)
  message(STATUS "Found CUPTI: ${CUPTI_LIBRARY}")
else()
  message(WARNING "CUPTI library not found in ${CUPTI_LIB_PATH}")
endif()


#add_executable(dummy_cuda_node scripts/test/dummy_cuda_node.cu)
#set_target_properties(dummy_cuda_node PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
#target_link_libraries(dummy_cuda_node ${catkin_LIBRARIES} ${NVML_LIBRARY} cudart)

#add_executable(total_resource_cpp scripts/cpp/total_resource.cpp)
#target_link_libraries(total_resource_cpp ${catkin_LIBRARIES} ${NVML_LIBRARY})

#add_executable(gpu_mon_cupti scripts/GpuMonCupti.cu)
#target_link_libraries(gpu_mon_cupti ${catkin_LIBRARIES} ${NVML_LIBRARY} ${CUPTI_LIBRARY} ${CUDA_CUDART_LIBRARY} cudart)