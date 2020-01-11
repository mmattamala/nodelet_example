#include "../include/kill_test_nodelet/Chatter.h"
#include "pluginlib/class_list_macros.h"
#include <std_msgs/Float64MultiArray.h>


#include <iomanip>
#include <pwd.h>
#include <ctime>
#include <chrono>

PLUGINLIB_EXPORT_CLASS(kill_test_nodelet::Chatter, nodelet::Nodelet);

namespace kill_test_nodelet
{

Chatter::Chatter()
{
}

void Chatter::callback(const std_msgs::StringPtr msg)
{
    msg->data = msg->data + "_" + name_;
    publisher_.publish(msg);
}

void Chatter::onInit()
{
    nh_ = getNodeHandle();
    private_nh_ = getPrivateNodeHandle();
    name_ = getName();

    // Configure subscribers
    subscriber_ = nh_.subscribe("in", 10, &Chatter::callback, this);

    // Configure publisher
    publisher_ = nh_.advertise<std_msgs::String>("out", 10);
}

} // namespace realsense_rig
