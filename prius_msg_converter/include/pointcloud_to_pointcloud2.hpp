#ifndef POINTCLOUD_TO_POINTCLOUD2_HPP_INCLUDED
#define POINTCLOUD_TO_POINTCLOUD2_HPP_INCLUDED

#include <ros/ros.h>

#include <sensor_msgs/PointCloud.h>

namespace prius {
namespace msg_converter {
class PCtoPC2 {
public:
  PCtoPC2();
  ~PCtoPC2();

private:
  void PCCallback(const sensor_msgs::PointCloud::ConstPtr &msg);

  // node handler
  ros::NodeHandle nh_;

  // subscriber
  ros::Subscriber pc2_sub_;
  // publisher
  ros::Publisher pc2_msg_pub_;

  // parameters
  std::string frame_name_;
};
}
}

#endif
