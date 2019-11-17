#pragma once
#ifndef POINT_CLOUD_PROCESSING
#define POINT_CLOUD_PROCESSING

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>

#define NO_OF_POINT_CLOUD 10

class PointCloudProcessing
{
public:
    PointCloudProcessing(ros::NodeHandle &nh, ros::NodeHandle &pnh);
    ~PointCloudProcessing();
    void runOnce();

private:
    ros::NodeHandle nh_;

    // ROS Subscriber for subscribing to a ROS topic having input PointCloud data
    // ROS Subscriber Declaration
    ros::Subscriber sub_cloud_;

    // ROS Subscriber Callback function declaration
    void subCallback(const sensor_msgs::PointCloud2 &msg);

    // input PointCloud having datatype - sensor_msgs::PointCloud2
    sensor_msgs::PointCloud2 input_pc2_;
    std::vector<sensor_msgs::PointCloud2> input_pc2_vec_;

    // flag for checking whether required number of PointCloud has been received
    bool has_point_cloud;
};

#endif