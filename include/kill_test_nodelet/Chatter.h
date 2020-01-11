#pragma once

#include <memory>
#include <vector>
#include <fstream>

#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <ros/package.h>
#include <std_msgs/String.h>

namespace kill_test_nodelet
{

class Chatter : public nodelet::Nodelet
{
public : 
    Chatter();
    void callback(const std_msgs::StringPtr msg);

private:
    // Nodelet initialization
    virtual void onInit();

    // Nodelet
    std::string name_;
    ros::NodeHandle nh_;
    ros::NodeHandle private_nh_;

    // Publishers and subscribers
    ros::Subscriber subscriber_;
    ros::Publisher publisher_;
};

} // namespace kill_test_nodelet