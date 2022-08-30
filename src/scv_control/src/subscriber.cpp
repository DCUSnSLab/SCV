//
// Created by jeonsoobin on 2022-08-24.
//
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "scv_control/test_library.h"

void Callback_func(const std_msgs::String::ConstPtr& msg){
    ROS_INFO("I heard: [%s]",msg->data.c_str());
}

int main(int argc, char **argv){
    sayHello();
    ros::init(argc, argv, "sub_node");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("topic", 1000, Callback_func);
    ros::spin();

    return 0;
}
