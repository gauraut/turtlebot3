# Turtlebot3 Walker
## Overview
This code is a simple walker node which uses the turtlebot3 model and autonomously navigates it through a world with obstacles. The walker node publishes messages to the /cmd_vel topic of the turtlebot3 which runs the robot in the simulation world. For this, the robot uses sensor_msgs/LaserScan data, more specifically, from the "ranges" array.
## License
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
MIT License

Copyright (c) 2021 Gaurav

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
## Dependencies

   - ROS Noetic
   - Modern C++ Programming Language
   - std_Msgs Package
   - sensor_msgs Package
   - geometry_msgs Package
   - Roscpp Package
   - Catkin_Make build system

## Build

### Create Catkin Workspace
```
cd ~/catkin_ws
catkin_make clean && catkin_make
```
### Copy the repository in src folder of catkin workspace
```
cd src 
git clone https://github.com/gauraut/walker.git
cd ..
catkin_make clean && catkin_make
source ./devel/setup.bash
```
## Downloading the turtlebot3 packge in you catkin workspace
In a new terminal window,
```
cd ~/catkin_ws/src/
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
cd ~/catkin_ws && catkin_make
cd ~/catkin_ws/src/
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
cd ~/catkin_ws && catkin_make
```
## Running the simulation

### Make sure Roscore is running
```
roscore
```
### Open the turtlebot3 in a simulation world with obstacles
In a new terminal window,
```
roslaunch turtlebot3_gazebo turtlebot3_world.launch  # Opens turtlebot in Gazebo environment
```
### To run the walker node's launch file
```
roslaunch walker walker_launch.launch # By default the rosbag recording is Off
```
The robot will autuonomously run and cover the whole world while avoiding obstacles.

## Bag files
### Recording with the launch file
```
roslaunch walker walker_launch.launch record_walker:=true  # By defalt, is set to false
```
The rosbag will be saved in the package's results folder with th name as "all_topics.bag"
### Disabling bag file recording
By default, the rosbag recording is disabled. Just run the launch file.
### Inspecting the bag file
```
rosbag info your_rosbag_file.bag
```
Example output:
```
path:        2021-11-14-21-16-20.bag
version:     2.0
duration:    18.3s
start:       Nov 14 2021 21:16:20.10 (1636942580.10)
end:         Nov 14 2021 21:16:38.43 (1636942598.43)
size:        94.6 KB
messages:    542
compression: none [1/1 chunks]
types:       rosgraph_msgs/Log [acffd30cd6b6de30f120938c17c593fb]
             std_msgs/String   [992ce8a1687cec8c8bd883ec73ca41d1]
topics:      /chatter   271 msgs    : std_msgs/String  
             rosout     271 msgs    : rosgraph_msgs/Log (2 connections)

```
### Playing the recorded rosbag
Make sure all processes related to ROS are killed.
Open a new terminal and enter,
```
roscore
```
On a separate terminal
```
rosbag play file_name.bag
```
