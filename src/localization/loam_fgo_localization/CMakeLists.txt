cmake_minimum_required(VERSION 3.8)
project(loam_fgo_localization)

include(CheckLanguage)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(
    $<$<COMPILE_LANGUAGE:CXX>:-Wall>
    $<$<COMPILE_LANGUAGE:CXX>:-Wextra>
    $<$<COMPILE_LANGUAGE:CXX>:-Wpedantic>
  )
endif()

option(SCV_LOCALIZATION_ENABLE_CUDA "Build the CUDA lookup backend when CUDA is available" ON)
set(SCV_LOCALIZATION_CUDA_ARCHITECTURES "86" CACHE STRING
  "CUDA architectures for the fixed-map lookup backend")

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(pcl_conversions REQUIRED)
find_package(lio_sam REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PCL REQUIRED COMPONENTS common io filters kdtree)
list(APPEND CMAKE_MODULE_PATH "/usr/share/cmake/geographiclib")
find_package(GeographicLib REQUIRED)
find_package(GTSAM REQUIRED)
find_package(GTSAM_UNSTABLE REQUIRED)

include_directories(
  include
  ${EIGEN3_INCLUDE_DIRS}
)

add_library(loam_fgo_localization_se2_bbs
  src/global_localization/se2_branch_and_bound.cpp
)
target_include_directories(loam_fgo_localization_se2_bbs PUBLIC
  include
  ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(loam_fgo_localization_se2_bbs
  ${OpenCV_LIBS}
)

if(SCV_LOCALIZATION_ENABLE_CUDA AND NOT CMAKE_CUDA_COMPILER)
  find_program(SCV_LOCALIZATION_NVCC
    NAMES nvcc
    HINTS /usr/local/cuda/bin /usr/local/cuda-12.6/bin
  )
  if(SCV_LOCALIZATION_NVCC)
    set(CMAKE_CUDA_COMPILER "${SCV_LOCALIZATION_NVCC}" CACHE FILEPATH
      "CUDA compiler" FORCE)
  endif()
endif()
check_language(CUDA)
if(SCV_LOCALIZATION_ENABLE_CUDA AND CMAKE_CUDA_COMPILER)
  enable_language(CUDA)
  find_package(CUDAToolkit REQUIRED)
  add_library(loam_fgo_localization_cuda_knn src/global_localization/cuda_knn.cu)
  target_include_directories(loam_fgo_localization_cuda_knn PUBLIC include)
  target_link_libraries(loam_fgo_localization_cuda_knn CUDA::cudart)
  target_compile_options(loam_fgo_localization_cuda_knn PRIVATE
    $<$<COMPILE_LANGUAGE:CUDA>:-Xcompiler=-Wno-pedantic>
  )
  set_target_properties(loam_fgo_localization_cuda_knn PROPERTIES
    CUDA_ARCHITECTURES "${SCV_LOCALIZATION_CUDA_ARCHITECTURES}"
    POSITION_INDEPENDENT_CODE ON
  )
elseif(SCV_LOCALIZATION_ENABLE_CUDA)
  message(WARNING "CUDA lookup requested, but no CUDA compiler was found")
endif()

add_executable(local_odometry_node
  src/local_odometry/local_odometry_node.cpp
  src/local_odometry/local_odometry.cpp
  src/local_odometry/eskf_odometry.cpp
)
ament_target_dependencies(local_odometry_node
  rclcpp
  sensor_msgs
  std_msgs
  nav_msgs
  geometry_msgs
  tf2
  tf2_ros
)

add_executable(lio_feature_map_localizer_node
  src/global_localization/lio_feature_map_localizer_node.cpp
)
target_include_directories(lio_feature_map_localizer_node PUBLIC
  include
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)
target_link_libraries(lio_feature_map_localizer_node
  loam_fgo_localization_se2_bbs
  ${PCL_LIBRARIES}
  ${OpenCV_LIBS}
)
ament_target_dependencies(lio_feature_map_localizer_node
  rclcpp
  sensor_msgs
  std_msgs
  nav_msgs
  geometry_msgs
  tf2
  tf2_ros
  pcl_conversions
  lio_sam
)
if(TARGET loam_fgo_localization_cuda_knn)
  target_link_libraries(lio_feature_map_localizer_node
    loam_fgo_localization_cuda_knn
  )
  target_compile_definitions(lio_feature_map_localizer_node PRIVATE
    LIO_SAM_LOCALIZATION_HAS_CUDA=1
  )
endif()

# ---- FGO 파이프라인 (신규): GPS frontend + FGO 융합 ----
add_executable(gps_measurement_node
  src/global_localization/gps_measurement_node.cpp
)
target_include_directories(gps_measurement_node PUBLIC
  include
  ${GeographicLib_INCLUDE_DIRS}
)
target_link_libraries(gps_measurement_node
  ${GeographicLib_LIBRARIES}
)
ament_target_dependencies(gps_measurement_node
  rclcpp
  sensor_msgs
  std_msgs
  geometry_msgs
)

add_executable(fgo_fusion_node
  src/fusion/fgo_fusion_node.cpp
  src/fusion/fgo_core.cpp
)
target_include_directories(fgo_fusion_node PUBLIC include)
target_link_libraries(fgo_fusion_node
  gtsam
  gtsam_unstable
)
ament_target_dependencies(fgo_fusion_node
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  tf2_ros
)

# ---- 앵커링 파이프라인 (FGO 대체안): RTK EKF + PCD 이벤트 앵커. GTSAM 비의존 ----
add_executable(anchor_manager_node
  src/fusion/anchor_manager_node.cpp
  src/fusion/anchor_core.cpp
)
target_include_directories(anchor_manager_node PUBLIC include)
ament_target_dependencies(anchor_manager_node
  rclcpp
  std_msgs
  nav_msgs
  geometry_msgs
  tf2_ros
)

install(TARGETS
  local_odometry_node
  lio_feature_map_localizer_node
  gps_measurement_node
  fgo_fusion_node
  anchor_manager_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch config LICENSES
  DESTINATION share/${PROJECT_NAME}/)

if(BUILD_TESTING)
  add_executable(test_anchor_output_slew
    test/test_anchor_output_slew.cpp
    src/fusion/anchor_core.cpp
  )
  target_compile_options(test_anchor_output_slew PRIVATE -UNDEBUG)
  add_test(NAME anchor_output_slew COMMAND test_anchor_output_slew)

  add_executable(test_fgo_bootstrap
    test/test_fgo_bootstrap.cpp
    src/fusion/fgo_core.cpp
  )
  target_link_libraries(test_fgo_bootstrap gtsam)
  add_test(NAME fgo_bootstrap COMMAND test_fgo_bootstrap)

  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
