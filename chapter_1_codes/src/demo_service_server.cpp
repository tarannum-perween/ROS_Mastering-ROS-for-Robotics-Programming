#include "ros/ros.h"
#include "chapter_1_codes/demo_srv.h"
#include <iostream>
#include <sstream>

using namespace std;

bool demo_service_callback(chapter_1_codes::demo_srv::Request &req, chapter_1_codes::demo_srv::Response &res)
{
    std::stringstream ss;
    ss << "Received Here";
    res.out = ss.str();
    ROS_INFO("From Client %s, Server says %s", req.in.c_str(), res.out.c_str());
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "demo_service_server");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("demo_service",demo_service_callback);
    ROS_INFO("Ready to receive from client.");
    ros::spin();
    
    return 0;
}
