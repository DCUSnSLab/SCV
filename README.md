# SCV(Service Co-operation Vehicle)
SCV(Service Co-operation Vehicle) is a self-driving vehicle aimed at campus driving and services.

# Sub Project Lists (meaning submodules)
All sub Projects are in **src** directory
- SCV System
  - scv controller
- Sensors
  - GPS
  - Velodyne Lidar
  - ZED2 Wrapper
- Msgs
- Hunter Library
  - vehicle_control : vehicle controller for hunter
  - vehicle_sdk : hunter sdk

# Installation
### Build workspace
When you clone this repository for the first time, You need to build workspace as follow.
in the your workspace

install libasio-dev for boost
```
sudo apt update -y
sudo apt install -y libasio-dev
```

install msgs for GPS
```
sudo apt install ros-{ROS DISTRO}-mavros-msgs
sudo apt install ros-{ROS DISTRO}-uuid-msgs
sudo apt install ros-{ROS DISTRO}-nmea-msgs
```

- install ZED SDK suitable for environment

https://www.stereolabs.com/developers/release/

- installing ROS dependencies for Velodyne LiDARs

```
sudo apt-get install ros-{ROS DISTRO}-velodyne
```

Check your ROS version and change symbolic link of CmakeLists.txt in src directory of Workspace
- Check symbolic link of CMakeLists.txt
```
$ls -al ./src
```

- Verify your link status of CMakeLists.txt
```
total 28
drwxrwxr-x  7 scv scv 4096  8월 31 16:08 .
drwxrwxr-x  6 scv scv 4096  8월 31 16:13 ..
drwxrwxr-x 14 scv scv 4096  8월 31 16:08 cmake-build-debug
lrwxrwxrwx  1 root   root     49  8월 31 16:08 CMakeLists.txt -> /opt/ros/noetic/share/catkin/cmake/toplevel.cmake
drwxrwxr-x  2 scv scv 4096  8월 31 16:09 .idea
drwxrwxr-x  4 scv scv 4096  8월 31 16:05 scv_control
drwxrwxr-x  5 scv scv 4096  8월 30 10:45 vehicle_control
drwxrwxr-x 11 scv scv 4096  8월 30 10:45 vehicle_sdk

```
- Change symbolic link
```
#if ROS version is noetic,
$sudo ln -Tfs /opt/ros/noetic/share/catkin/cmake/toplevel.cmake ./src/CMakeLists.txt

#Melodic,
$sudo ln -Tfs /opt/ros/melodic/share/catkin/cmake/toplevel.cmake ./src/CMakeLists.txt  
```

Build Workspace
```
#make workspace
$catkin_make
```
