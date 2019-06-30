#include "ros/ros.h"
#include "chapter_1_codes/demo_msg.h"
#include <iostream>
#include <sstream>

void number_callback(const chapter_1_codes::demo_msg::ConstPtr& msg)
{
    ROS_INFO("Received greeting %s", msg->greeting.c_str());
    ROS_INFO("Received %d", msg->number);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "demo_msg_subscriber");       // Inisialisasi ROS node dengan nama demo_msg_subscriber
    ros::NodeHandle node_obj;                           // Membuat objek nodehandle
    ros::Subscriber number_subscriber = node_obj.subscribe("/demo_msg_topic",10,number_callback);   // Membuat objek subscribe function
    ros::spin();                                        // Spinning the node
    
    return 0;
}
