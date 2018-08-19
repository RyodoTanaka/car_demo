#include <pointcloud_to_pointcloud2.hpp>
#include <ros/console.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/point_cloud_conversion.h>

namespace pmc = prius::msg_converter;
using namespace std;

pmc::PCtoPC2::PCtoPC2() : nh_("~"), frame_name_("") {
  // Get parameters
  nh_.param<std::string>("frame_name", frame_name_, frame_name_);

  // set subscriber
  pc2_sub_ = nh_.subscribe("/prius/center_laser/scan", 1,
                           &pmc::PCtoPC2::PCCallback, this);
  // set publisher
  pc2_msg_pub_ =
      nh_.advertise<sensor_msgs::PointCloud2>("/prius/center_laser/scan2", 1);

  ROS_INFO("point cloud to point cloud2 converter is ready.");
}

pmc::PCtoPC2::~PCtoPC2() {}

void pmc::PCtoPC2::PCCallback(const sensor_msgs::PointCloud::ConstPtr &msg) {
  sensor_msgs::PointCloud2 pub_msg;
  sensor_msgs::convertPointCloudToPointCloud2(*msg, pub_msg);

  // change frame id to frame_name parameter
  if (!frame_name_.empty())
    pub_msg.header.frame_id = frame_name_;

  pc2_msg_pub_.publish(pub_msg);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "point_cloud_to_point_cloud2_node");
  pmc::PCtoPC2 pc_to_pc2;
  ros::spin();
}
