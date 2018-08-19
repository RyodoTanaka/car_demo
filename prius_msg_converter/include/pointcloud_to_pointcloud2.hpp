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

      ros::NodeHandle nh_;

      ros::Subscriber pc2_sub_;
      
      ros::Publisher pc2_msg_pub_;
    };
  }
}

#endif
