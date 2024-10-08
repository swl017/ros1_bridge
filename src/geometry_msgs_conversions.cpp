#include "ros1_bridge/convert_builtin_interfaces.hpp"
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/msg/pose_with_covariance.hpp>

namespace ros1_bridge
{

template<>
void
convert_1_to_2(
  const geometry_msgs::PoseWithCovariance & ros1_msg,
  geometry_msgs::msg::PoseWithCovariance & ros2_msg)
{
  convert_1_to_2(ros1_msg.pose, ros2_msg.pose);
  for (size_t i = 0; i < 36; ++i) {
    ros2_msg.covariance[i] = ros1_msg.covariance[i];
  }
}

template<>
void
convert_2_to_1(
  const geometry_msgs::msg::PoseWithCovariance & ros2_msg,
  geometry_msgs::PoseWithCovariance & ros1_msg)
{
  convert_2_to_1(ros2_msg.pose, ros1_msg.pose);
  for (size_t i = 0; i < 36; ++i) {
    ros1_msg.covariance[i] = ros2_msg.covariance[i];
  }
}

}  // namespace ros1_bridge