#include <ros1_bridge/factory.hpp>
#include <std_msgs/Header.h>
#include <std_msgs/msg/header.hpp>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/msg/quaternion.hpp>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/msg/vector3.hpp>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/msg/twist.hpp>

namespace ros1_bridge
{

// std_msgs::Header
template<>
void
Factory<std_msgs::Header, std_msgs::msg::Header>::convert_1_to_2(
  const std_msgs::Header & ros1_msg,
  std_msgs::msg::Header & ros2_msg)
{
  ros2_msg.stamp.sec = ros1_msg.stamp.sec;
  ros2_msg.stamp.nanosec = ros1_msg.stamp.nsec;
  ros2_msg.frame_id = ros1_msg.frame_id;
}

template<>
void
Factory<std_msgs::Header, std_msgs::msg::Header>::convert_2_to_1(
  const std_msgs::msg::Header & ros2_msg,
  std_msgs::Header & ros1_msg)
{
  ros1_msg.stamp.sec = ros2_msg.stamp.sec;
  ros1_msg.stamp.nsec = ros2_msg.stamp.nanosec;
  ros1_msg.frame_id = ros2_msg.frame_id;
}

// geometry_msgs::Point
template<>
void
Factory<geometry_msgs::Point, geometry_msgs::msg::Point>::convert_1_to_2(
  const geometry_msgs::Point & ros1_msg,
  geometry_msgs::msg::Point & ros2_msg)
{
  ros2_msg.x = ros1_msg.x;
  ros2_msg.y = ros1_msg.y;
  ros2_msg.z = ros1_msg.z;
}

template<>
void
Factory<geometry_msgs::Point, geometry_msgs::msg::Point>::convert_2_to_1(
  const geometry_msgs::msg::Point & ros2_msg,
  geometry_msgs::Point & ros1_msg)
{
  ros1_msg.x = ros2_msg.x;
  ros1_msg.y = ros2_msg.y;
  ros1_msg.z = ros2_msg.z;
}

// geometry_msgs::Quaternion
template<>
void
Factory<geometry_msgs::Quaternion, geometry_msgs::msg::Quaternion>::convert_1_to_2(
  const geometry_msgs::Quaternion & ros1_msg,
  geometry_msgs::msg::Quaternion & ros2_msg)
{
  ros2_msg.x = ros1_msg.x;
  ros2_msg.y = ros1_msg.y;
  ros2_msg.z = ros1_msg.z;
  ros2_msg.w = ros1_msg.w;
}

template<>
void
Factory<geometry_msgs::Quaternion, geometry_msgs::msg::Quaternion>::convert_2_to_1(
  const geometry_msgs::msg::Quaternion & ros2_msg,
  geometry_msgs::Quaternion & ros1_msg)
{
  ros1_msg.x = ros2_msg.x;
  ros1_msg.y = ros2_msg.y;
  ros1_msg.z = ros2_msg.z;
  ros1_msg.w = ros2_msg.w;
}

// geometry_msgs::Pose
template<>
void
Factory<geometry_msgs::Pose, geometry_msgs::msg::Pose>::convert_1_to_2(
  const geometry_msgs::Pose & ros1_msg,
  geometry_msgs::msg::Pose & ros2_msg)
{
  Factory<geometry_msgs::Point, geometry_msgs::msg::Point>::convert_1_to_2(ros1_msg.position, ros2_msg.position);
  Factory<geometry_msgs::Quaternion, geometry_msgs::msg::Quaternion>::convert_1_to_2(ros1_msg.orientation, ros2_msg.orientation);
}

template<>
void
Factory<geometry_msgs::Pose, geometry_msgs::msg::Pose>::convert_2_to_1(
  const geometry_msgs::msg::Pose & ros2_msg,
  geometry_msgs::Pose & ros1_msg)
{
  Factory<geometry_msgs::Point, geometry_msgs::msg::Point>::convert_2_to_1(ros2_msg.position, ros1_msg.position);
  Factory<geometry_msgs::Quaternion, geometry_msgs::msg::Quaternion>::convert_2_to_1(ros2_msg.orientation, ros1_msg.orientation);
}

// geometry_msgs::PoseWithCovariance
template<>
void
Factory<geometry_msgs::PoseWithCovariance, geometry_msgs::msg::PoseWithCovariance>::convert_1_to_2(
  const geometry_msgs::PoseWithCovariance & ros1_msg,
  geometry_msgs::msg::PoseWithCovariance & ros2_msg)
{
  Factory<geometry_msgs::Pose, geometry_msgs::msg::Pose>::convert_1_to_2(ros1_msg.pose, ros2_msg.pose);
  std::copy(std::begin(ros1_msg.covariance), std::end(ros1_msg.covariance), std::begin(ros2_msg.covariance));
}

template<>
void
Factory<geometry_msgs::PoseWithCovariance, geometry_msgs::msg::PoseWithCovariance>::convert_2_to_1(
  const geometry_msgs::msg::PoseWithCovariance & ros2_msg,
  geometry_msgs::PoseWithCovariance & ros1_msg)
{
  Factory<geometry_msgs::Pose, geometry_msgs::msg::Pose>::convert_2_to_1(ros2_msg.pose, ros1_msg.pose);
  std::copy(std::begin(ros2_msg.covariance), std::end(ros2_msg.covariance), std::begin(ros1_msg.covariance));
}

// geometry_msgs::Vector3
template<>
void
Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_1_to_2(
  const geometry_msgs::Vector3 & ros1_msg,
  geometry_msgs::msg::Vector3 & ros2_msg)
{
  ros2_msg.x = ros1_msg.x;
  ros2_msg.y = ros1_msg.y;
  ros2_msg.z = ros1_msg.z;
}

template<>
void
Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_2_to_1(
  const geometry_msgs::msg::Vector3 & ros2_msg,
  geometry_msgs::Vector3 & ros1_msg)
{
  ros1_msg.x = ros2_msg.x;
  ros1_msg.y = ros2_msg.y;
  ros1_msg.z = ros2_msg.z;
}

// geometry_msgs::Twist
template<>
void
Factory<geometry_msgs::Twist, geometry_msgs::msg::Twist>::convert_1_to_2(
  const geometry_msgs::Twist & ros1_msg,
  geometry_msgs::msg::Twist & ros2_msg)
{
  Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_1_to_2(ros1_msg.linear, ros2_msg.linear);
  Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_1_to_2(ros1_msg.angular, ros2_msg.angular);
}

template<>
void
Factory<geometry_msgs::Twist, geometry_msgs::msg::Twist>::convert_2_to_1(
  const geometry_msgs::msg::Twist & ros2_msg,
  geometry_msgs::Twist & ros1_msg)
{
  Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_2_to_1(ros2_msg.linear, ros1_msg.linear);
  Factory<geometry_msgs::Vector3, geometry_msgs::msg::Vector3>::convert_2_to_1(ros2_msg.angular, ros1_msg.angular);
}

}  // namespace ros1_bridge