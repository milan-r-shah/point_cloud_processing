#pragma once
#ifndef POINT_CLOUD_PROCESSING
#define POINT_CLOUD_PROCESSING

#include <ros/ros.h>

class PointCloudProcessing
{
public:
    PointCloudProcessing(ros::NodeHandle &nh, ros::NodeHandle &pnh);
    ~PointCloudProcessing();
    void runOnce();

private:
    ros::NodeHandle nh_;
};

#endif