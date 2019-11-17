#include "point_cloud_processing.hpp"

PointCloudProcessing::PointCloudProcessing(ros::NodeHandle &nh, ros::NodeHandle &pnh)
{
    nh_ = nh;
    std::cout << "from Constructor \n";
}

PointCloudProcessing::~PointCloudProcessing()
{
    std::cout << "from Destructor \n";
}

void PointCloudProcessing::runOnce()
{
    std::cout << "from runOnce() \n";
}