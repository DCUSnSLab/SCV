cmake_minimum_required(VERSION 3.16)
project(tensorrt_common LANGUAGES CXX)

# nvcc is rarely on PATH; the toolkit sits in /usr/local/cuda on Ubuntu and on Jetson.
if(NOT DEFINED CMAKE_CUDA_COMPILER AND NOT DEFINED ENV{CUDACXX})
  set(CMAKE_CUDA_COMPILER /usr/local/cuda/bin/nvcc)
endif()
# The GPU this is built on; Jetson builds on the Jetson.
if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES native)
endif()
enable_language(CUDA)

# colcon passes no build type.
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "" FORCE)
endif()

find_package(ament_cmake REQUIRED)
find_package(CUDAToolkit REQUIRED)
find_package(flux_wrapper REQUIRED)
find_package(OpenCV REQUIRED COMPONENTS core imgproc)
find_package(rclcpp REQUIRED)
find_library(NVINFER_LIBRARY nvinfer REQUIRED)
find_library(NVONNXPARSER_LIBRARY nvonnxparser REQUIRED)
find_path(NVINFER_INCLUDE_DIR NvInfer.h REQUIRED)

add_library(tensorrt_common SHARED
  src/depth.cpp
  src/engine.cpp
  src/image.cpp
  src/preprocess.cu
  src/yolo.cpp)
target_compile_features(tensorrt_common PUBLIC cxx_std_17)
target_compile_options(tensorrt_common PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-Wall -Wextra -Wpedantic>)
target_include_directories(tensorrt_common
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
  PRIVATE ${NVINFER_INCLUDE_DIR})
# TensorRT and CUDA stay private: the headers of this package do not include them.
target_link_libraries(tensorrt_common
  PUBLIC flux_wrapper::flux_wrapper opencv_core opencv_imgproc
  PRIVATE ${NVINFER_LIBRARY} ${NVONNXPARSER_LIBRARY} CUDA::cudart)

add_executable(build_engine src/build_engine.cpp)
target_link_libraries(build_engine tensorrt_common)
ament_target_dependencies(build_engine rclcpp)

install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})
install(TARGETS build_engine RUNTIME DESTINATION lib/${PROJECT_NAME})
install(TARGETS tensorrt_common EXPORT export_tensorrt_common
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
ament_export_targets(export_tensorrt_common HAS_LIBRARY_TARGET)
ament_export_dependencies(OpenCV flux_wrapper)

if(BUILD_TESTING)
  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(test_image test/test_image.cpp)
  target_link_libraries(test_image tensorrt_common)
  ament_add_gtest(test_depth test/test_depth.cpp)
  target_link_libraries(test_depth tensorrt_common)
  ament_add_gtest(test_yolo test/test_yolo.cpp)
  target_link_libraries(test_yolo tensorrt_common)
  # Both paths of the wrapper: the flux frame layout decides the alignment of the data. Needs a
  # GPU for the device frames.
  ament_add_gtest_executable(test_messages test/test_messages.cpp)
  target_link_libraries(test_messages tensorrt_common)
  target_compile_definitions(test_messages PRIVATE
    TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/data")
  foreach(run 0 1)
    ament_add_gtest_test(test_messages TEST_NAME test_messages_run${run}
      ENV ENABLE_FLUX=${run} TIMEOUT 300)
  endforeach()

  # Needs a GPU: the kernel output is read back through an identity engine.
  ament_add_gtest(test_preprocess test/test_preprocess.cpp TIMEOUT 300)
  target_link_libraries(test_preprocess tensorrt_common CUDA::cudart)
  target_compile_definitions(test_preprocess PRIVATE
    TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/data")

  # Not a test: prints the time of the CPU and GPU preprocessing. Pin it to a core with taskset.
  add_executable(bench_preprocess test/bench_preprocess.cpp)
  target_link_libraries(bench_preprocess tensorrt_common CUDA::cudart)
  target_compile_definitions(bench_preprocess PRIVATE
    TEST_DATA_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/data")

  # Not a test: prints the time of the CPU depth postprocessing. Pin it to a core with taskset.
  add_executable(bench_postprocess test/bench_postprocess.cpp)
  target_link_libraries(bench_postprocess tensorrt_common)
endif()

ament_package()
