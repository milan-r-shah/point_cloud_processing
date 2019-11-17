#include "point_cloud_processing.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_cloud_processing");
    ros::NodeHandle nh;
    ros::NodeHandle pnh("~");

    PointCloudProcessing node(nh, pnh);

    ros::Rate rate(1.0);

    while (ros::ok())
    {
        node.runOnce();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}