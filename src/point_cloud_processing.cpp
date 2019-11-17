#include "point_cloud_processing.hpp"

PointCloudProcessing::PointCloudProcessing(ros::NodeHandle &nh, ros::NodeHandle &pnh)
{
    nh_ = nh;
    std::cout << "from Constructor \n";

    // ROS Subscriber Initialization
    // Input ROS topic: /zed/zed_node/point_cloud/cloud_registered
    sub_cloud_ = nh_.subscribe("/zed/zed_node/point_cloud/cloud_registered", 1, &PointCloudProcessing::subCallback, this);

    // In the beginning, there is no PointCloud, so flag value is 'false'
    has_point_cloud = false;
}

PointCloudProcessing::~PointCloudProcessing()
{
    std::cout << "from Destructor \n";
}

void PointCloudProcessing::runOnce()
{
    std::cout << "from runOnce() \n";
}

// ROS Subsriber callback function definition
void PointCloudProcessing::subCallback(const sensor_msgs::PointCloud2 &msg)
{
    // storing input PointCloud into PointCloud vector
    if (input_pc2_vec_.size() < NO_OF_POINT_CLOUD)
    {
        input_pc2_vec_.push_back(msg);
    }
    else
    {
        // once the required number of PointCloudss has been received set this flag to'true'
        has_point_cloud = true;
    }
}
