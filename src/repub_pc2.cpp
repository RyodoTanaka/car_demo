#include <repub_pc2.hpp>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>

namespace pmc = prius::msg_converter;
using namespace std;

pmc::RePubPC2::RePubPC2()
{
  nh_.subscribe("/prius/center_laser/scan", 1, &pmc::RePubPC2::PCCallback, this);

  pc2_msg_pub_ = nh_.advertise<sensor_msgs::PointCloud2>("/prius/center_laser/scan2", 1);
}

pmc::RePubPC2::~RePubPC2(){ }

void pmc::RePubPC2::PCCallback(const sensor_msgs::PointCloud::ConstPtr &msg)
{
  sensor_msgs::PointCloud2 pub_msg;
  sensor_msgs::convertPointCloudToPointCloud2(*msg, pub_msg);

  pc2_msg_pub_.publish(pub_msg);
}
