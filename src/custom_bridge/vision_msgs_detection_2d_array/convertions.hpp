#pragma once
#include <iostream>
#include <memory>
#include <string>

// include ROS 1
#include "ros/message.h"
#ifdef __clang__
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wunused-parameter"
#endif
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "vision_msgs/Detection2D.h"
#include "vision_msgs/Detection2DArray.h"
#ifdef __clang__
# pragma clang diagnostic pop
#endif

// include ROS 2
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "vision_msgs/msg/detection2_d.hpp"
#include "vision_msgs/msg/detection2_d_array.hpp"

/**
 * @brief Header
 */
void convert_1_to_2(
  const std_msgs::Header & ros1_msg,
  std_msgs::msg::Header & ros2_msg
)
{
  ros2_msg.stamp.sec = ros1_msg.stamp.sec;
  ros2_msg.stamp.nanosec = ros1_msg.stamp.nsec;
  ros2_msg.frame_id = ros1_msg.frame_id;
}

void convert_2_to_1(
  const std_msgs::msg::Header & ros2_msg,
  std_msgs::Header & ros1_msg
)
{
  ros1_msg.stamp.sec = ros2_msg.stamp.sec;
  ros1_msg.stamp.nsec = ros2_msg.stamp.nanosec;
  ros1_msg.frame_id = ros2_msg.frame_id;
}

/**
 * @brief Detection2D
 */
void convert_1_to_2(
  const vision_msgs::Detection2D & ros1_msg,
  vision_msgs::msg::Detection2D & ros2_msg
)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for(auto result : ros1_msg.results)
  {
    vision_msgs::msg::ObjectHypothesisWithPose ros2_result;
    convert_1_to_2(result, ros2_result);
    ros2_msg.results.push_back(ros2_result);
  }
}

void convert_2_to_1(
  const vision_msgs::msg::Detection2D & ros2_msg,
  vision_msgs::Detection2D & ros1_msg
)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for(auto result : ros2_msg.results)
  {
    vision_msgs::ObjectHypothesisWithPose ros1_result;
    convert_2_to_1(result, ros1_result);
    ros1_msg.results.push_back(ros1_result);
  }
}