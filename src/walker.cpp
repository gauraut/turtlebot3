///============================================================================
/// @file        : walker.cpp
/// @author      : gauraut
/// @version     : 1.0
/// @copyright   : MIT License
/// @brief       : Walker definition
///============================================================================
#include <sensor_msgs/LaserScan.h>
#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"


ros::Publisher vel_pub;

/// @fn void auto_navi(const sensor_msgs::LaserScan::ConstPtr&)
/// @brief auto_navi is a callback function
/// of the subscriber which publishes which
/// runs the robot autonomously
///
/// @param msg
void auto_navi(const sensor_msgs::LaserScan::ConstPtr& msg) {
  geometry_msgs::Twist turn;
  while (ros::ok) {
    if (msg->ranges[0] >= 0.5 && msg->ranges[29]
                       >= 0.5 && msg->ranges[339] >= 0.5) {
      turn.linear.x = 0.3;
      turn.angular.z = 0;
      ROS_INFO_STREAM("Robot's speed is now " << turn.linear.x);
    } else {
        if (msg->ranges[89] >= msg->ranges[179]) {
          turn.linear.x = -0.6;
          turn.angular.z = 1.571;
          ROS_INFO_STREAM("Robot's speed is now "
              << turn.linear.x);
        } else {
          turn.linear.x = -0.6;
          turn.angular.z = -1.571;
          ROS_INFO_STREAM("Robot's speed is now "
              << turn.linear.x);
      }
    }
    vel_pub.publish(turn);  // publish the message
    ROS_INFO_STREAM("Now publishing data.");
    ros::spin();
  }
}

/// @fn int main(int, char**)
/// @brief Main function to run the walker node
///
/// @param argc
/// @param argv
/// @return
int main(int argc, char **argv) {
  ros::init(argc, argv, "walker");
  ros::NodeHandle nh;
  ros::Subscriber sub_laser = nh.subscribe("/scan", 1, auto_navi);
  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ros::spin();
  return 0;
}
