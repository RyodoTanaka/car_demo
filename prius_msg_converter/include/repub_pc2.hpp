#ifndef REPUB_PC2_HPP_INCLUDED
#define REPUB_PC2_HPP_INCLUDED

#include <ros/ros.h>

#include <sensor_msgs/PointCloud.h>

namespace prius {
  namespace msg_converter {
    class RePubPC2 {
    public:
      RePubPC2();
      ~RePubPC2();
    private:
      void PCCallback(const sensor_msgs::PointCloud::ConstPtr &msg);

      ros::NodeHandle nh_;

      ros::Publisher pc2_msg_pub_;
    };
  }
}

#endif
