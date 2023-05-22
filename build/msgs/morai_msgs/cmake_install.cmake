# Install script for directory: /home/dong/Development/SCV/src/msgs/morai_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/dong/Development/SCV/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/msg" TYPE FILE FILES
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/CtrlCmd.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/EgoVehicleStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/GPSMessage.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/GhostMessage.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/ObjectStatusList.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/ObjectStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/TrafficLight.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/ERP42Info.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/GetTrafficLightStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SetTrafficLight.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/IntersectionControl.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/IntersectionStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/CollisionData.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MultiEgoSetting.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/IntscnTL.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SensorPosControl.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MoraiSimProcHandle.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MoraiSimProcStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MoraiSrvResponse.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/ScenarioLoad.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MoraiTLIndex.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MoraiTLInfo.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SaveSensorData.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/ReplayInfo.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/EventInfo.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/Lamps.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/VehicleSpec.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/VehicleSpecIndex.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/NpcGhostCmd.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/NpcGhostInfo.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/VehicleCollisionData.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/VehicleCollision.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeAddObject.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeInfo.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/WaitForTickResponse.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeCmd.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeRemoveObject.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeCmdResponse.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/WaitForTick.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MapSpec.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/MapSpecIndex.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeCtrlCmd.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeSetGear.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeResultResponse.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/SyncModeScenarioLoad.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/RadarDetection.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/RadarDetections.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/PRStatus.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/PRCtrlCmd.msg"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/msg/PREvent.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/srv" TYPE FILE FILES
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiScenarioLoadSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSimProcSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiTLInfoSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiEventCmdSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiVehicleSpecSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeCmdSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiWaitForTickSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiMapSpecSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeCtrlCmdSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeSetGearSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeSLSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/PREventSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeAddObjectSrv.srv"
    "/home/dong/Development/SCV/src/msgs/morai_msgs/srv/MoraiSyncModeRemoveObjectSrv.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES "/home/dong/Development/SCV/build/msgs/morai_msgs/catkin_generated/installspace/morai_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/dong/Development/SCV/devel/include/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/dong/Development/SCV/devel/share/roseus/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/dong/Development/SCV/devel/share/common-lisp/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/dong/Development/SCV/devel/share/gennodejs/ros/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/dong/Development/SCV/devel/lib/python3/dist-packages/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/dong/Development/SCV/devel/lib/python3/dist-packages/morai_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/dong/Development/SCV/build/msgs/morai_msgs/catkin_generated/installspace/morai_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES "/home/dong/Development/SCV/build/msgs/morai_msgs/catkin_generated/installspace/morai_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs/cmake" TYPE FILE FILES
    "/home/dong/Development/SCV/build/msgs/morai_msgs/catkin_generated/installspace/morai_msgsConfig.cmake"
    "/home/dong/Development/SCV/build/msgs/morai_msgs/catkin_generated/installspace/morai_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/morai_msgs" TYPE FILE FILES "/home/dong/Development/SCV/src/msgs/morai_msgs/package.xml")
endif()

