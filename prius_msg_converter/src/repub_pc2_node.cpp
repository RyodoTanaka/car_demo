#include <repub_pc2.hpp>
#include <ros/ros.h>

namespace pmc = prius::msg_converter;

int main(int argc, char** argv)
{
  ros::init(argc, argv, "point_cloud_to_point_cloud2_node");
  pmc::RePubPC2 rpp2;
  ros::spin();
}
