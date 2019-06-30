#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "chapter_1_codes/demo_msg.h"   // cek nya di ~/catkin_ws/devel/include/chapter_1_codes , disitu ada file demo_msg.h
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "demo_msg_publisher");    // inisialisasi ROS node dengan nama demo_msg_publisher
    ros::NodeHandle node_obj;                       // Membuat objek nodehandle
    ros::Publisher number_publisher = node_obj.advertise<chapter_1_codes::demo_msg>("/demo_msg_topic",10);  // Membuat objek publisher
    ros::Rate loop_rate(10);                        // Membuat objek rate
    int number_count = 0;

    while (ros::ok())
    {
        chapter_1_codes::demo_msg msg;              // Membuat message Int32

        // Menyisipkan data ke header message
        std::stringstream ss;
        ss << "hello world";
        msg.greeting = ss.str();

        msg.number = number_count;
        ROS_INFO("%d",msg.number);                  // Menampilkan data
        ROS_INFO("%s",msg.greeting.c_str());        // Menampilkan data

        number_publisher.publish(msg);              // Publishing the message
        ros::spinOnce();                             // Spining once untuk melakukan semua operasi
        loop_rate.sleep();                          // Setting the loop rate
        ++number_count;
    }
    


    return 0;
}
