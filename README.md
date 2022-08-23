# SCV(Service Co-operation Vehicle)
SCV(Service Co-operation Vehicle) is a self-driving vehicle aimed at campus driving and services.

# Sub Project Lists (meaning submodules)
All sub Projects are in **src** directory
- Hunter Library
  - vehicle_control : vehicle controller for hunter
  - vehicle_sdk : hunter sdk

# Installation
### Build workspace
When you clone this repository for the first time, You need to build workspace as follow.
```
#in the your workspace

#install libasio-dev for boost
sudo apt update -y
sudo apt install -y libasio-dev
s
#make workspace
$catkin_make
```
