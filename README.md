# SCV (Service Co-operation Vehicle)

SCV (Service Co-operation Vehicle) is a self-driving vehicle platform aimed at campus driving and services. This repository includes the full software stack for autonomous driving capabilities.

## Project Overview

The SCV project implements a comprehensive autonomous driving system with the following key capabilities:
- Localization using dual GPS and IMU fusion
- Environment perception and object detection
- Path planning and navigation
- Vehicle control

## Setup Development Environment

### Clone Repository
```bash
# Clone the repository with all submodules
git clone --recursive https://github.com/DCUSnSLab/SCV.git

# Enter the repository directory
cd SCV

# Update submodule branches (commit hash)
git submodule update --remote --recursive

# Update submodule branches (commit hash to branch name)
./scripts/SubUpdate.sh
```

## Project Structure

### Main System Components
- **SCV System**: Core system controller and integration
  - `scv_controller`: Main vehicle control module
  - `path_planning`: Global and local path planning
  - `localization`: GPS and IMU-based localization

### Sensors
- **GPS**
  - Supports dual GPS setup for improved accuracy
  - GPS-RTK (Real-Time Kinematic) capability
- **Velodyne Lidar**
  - Point cloud processing
  - Environment mapping
- **ZED2 Camera**
  - Stereo vision
  - Depth perception

### Perception
- **Object Detection**
  - Identifies and classifies obstacles
  - Supports sensor fusion for improved detection

### Communication
- **ROS Messages**: Custom message types for inter-module communication

### Vehicle Platform
- **Hunter Vehicle Support**
  - `vehicle_control`: Vehicle controller for Hunter platform
  - `vehicle_sdk`: Hunter SDK integration

## Installation

### System Requirements
- Ubuntu 18.04/20.04
- ROS Melodic/Noetic
- CUDA-enabled GPU (recommended for perception modules)

### Required Dependencies
```bash
# Install libasio-dev for boost
sudo apt update -y
sudo apt install -y libasio-dev

# Install ROS message dependencies for GPS
sudo apt install ros-${ROS_DISTRO}-mavros-msgs
sudo apt install ros-${ROS_DISTRO}-uuid-msgs
sudo apt install ros-${ROS_DISTRO}-nmea-msgs

# Install ZED SDK based on your environment
# Visit: https://www.stereolabs.com/developers/release/

# Install ROS dependencies for Velodyne LiDARs
sudo apt install ros-${ROS_DISTRO}-velodyne
```

### ROS Workspace Setup
Check your ROS version and update the symbolic link for CMakeLists.txt:

```bash
# Check the current symbolic link
ls -al ./src

# Update the symbolic link based on your ROS distribution
# For ROS Noetic:
sudo ln -Tfs /opt/ros/noetic/share/catkin/cmake/toplevel.cmake ./src/CMakeLists.txt

# For ROS Melodic:
sudo ln -Tfs /opt/ros/melodic/share/catkin/cmake/toplevel.cmake ./src/CMakeLists.txt
```

### Build Workspace
```bash
# Build the workspace
catkin_make
```

## Features and Capabilities

### Localization
- Dual GPS integration for high-precision positioning
- IMU-GNSS sensor fusion
- Real-time vehicle pose estimation

### Path Planning
- Global route planning for campus navigation
- Local path planning with obstacle avoidance
- Waypoint navigation

### Perception
- Camera-based object detection
- Lidar-based obstacle detection
- Sensor fusion for enhanced environmental awareness

### Vehicle Control
- Velocity and steering control
- Trajectory following
- Safety monitoring and emergency stop

## Launch Files
The system provides several launch files for different scenarios:

- `dual_gps.launch`: Starts the system with dual GPS configuration
- `perception.launch`: Launches the perception system
- `localization.launch`: Initializes localization modules
- `planning.launch`: Starts the path planning modules
- `full_system.launch`: Launches the complete autonomous driving stack
