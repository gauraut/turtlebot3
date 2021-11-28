#include <ros/ros.h>
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <sensor_msgs/LaserScan.h>
#include "std_msgs/Float32.h"

ros::Publisher vel_pub;

void auto_navi(const sensor_msgs::LaserScan::ConstPtr& msg) {
  geometry_msgs::Twist turn;
  while (ros::ok) {
    if (msg->ranges[0] >= 0.5 && msg->ranges[29] >= 0.5 && msg->ranges[339] >= 0.5) {
      turn.linear.x = 0.3;
      turn.angular.z = 0;
    } else {
        if (msg->ranges[89] >= msg->ranges[179]) {
          turn.linear.x = -0.6;
          turn.angular.z = 1.571;
        } else {
          turn.linear.x = -0.6;
          turn.angular.z = -1.571;
      }
    }
    vel_pub.publish(turn);
    ros::spin();
  }   
}

int main (int argc, char **argv) {
  ros::init(argc, argv, "walker");
  ros::NodeHandle nh;
  std_msgs::Float32 msg;
  ros::Subscriber sub_laser = nh.subscribe("/scan", 1, auto_navi);
  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
  ros::spin();
  return 0;
}
