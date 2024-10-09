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
#include "vision_msgs/ObjectHypothesisWithPose.h"
#include "vision_msgs/BoundingBox2D.h"
#include "vision_msgs/Detection3D.h"
#include "vision_msgs/Detection3DArray.h"
#include "vision_msgs/BoundingBox3D.h"
#ifdef __clang__
# pragma clang diagnostic pop
#endif

// include ROS 2
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "vision_msgs/msg/detection2_d.hpp"
#include "vision_msgs/msg/detection2_d_array.hpp"
#include "vision_msgs/msg/object_hypothesis_with_pose.hpp"
#include "vision_msgs/msg/bounding_box2_d.hpp"
#include "vision_msgs/msg/detection3_d.hpp"
#include "vision_msgs/msg/detection3_d_array.hpp"
#include "vision_msgs/msg/bounding_box3_d.hpp"

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
 * @brief ObjectHypothesisWithPose
 */
void convert_1_to_2(
  const vision_msgs::ObjectHypothesisWithPose & ros1_msg,
  vision_msgs::msg::ObjectHypothesisWithPose & ros2_msg
)
{
  ros2_msg.hypothesis.class_id = std::to_string(ros1_msg.id);
  ros2_msg.hypothesis.score = ros1_msg.score;
  // TODO: Convert pose
}

void convert_2_to_1(
  const vision_msgs::msg::ObjectHypothesisWithPose & ros2_msg,
  vision_msgs::ObjectHypothesisWithPose & ros1_msg
)
{
  try
  {
    ros1_msg.id = std::stoi(ros2_msg.hypothesis.class_id);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  
  ros1_msg.score = ros2_msg.hypothesis.score;
  // TODO: Convert pose
}

/**
 * @brief BoundingBox2D
 */
void convert_1_to_2(
  const vision_msgs::BoundingBox2D & ros1_msg,
  vision_msgs::msg::BoundingBox2D & ros2_msg
)
{
  ros2_msg.center.position.x = ros1_msg.center.x;
  ros2_msg.center.position.y = ros1_msg.center.y;
  ros2_msg.center.theta = ros1_msg.center.theta;
  ros2_msg.size_x = ros1_msg.size_x;
  ros2_msg.size_y = ros1_msg.size_y;
}

void convert_2_to_1(
  const vision_msgs::msg::BoundingBox2D & ros2_msg,
  vision_msgs::BoundingBox2D & ros1_msg
)
{
  ros1_msg.center.x = ros2_msg.center.position.x;
  ros1_msg.center.y = ros2_msg.center.position.y;
  ros1_msg.center.theta = ros2_msg.center.theta;
  ros1_msg.size_x = ros2_msg.size_x;
  ros1_msg.size_y = ros2_msg.size_y;
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
  convert_1_to_2(ros1_msg.bbox, ros2_msg.bbox);
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
  convert_2_to_1(ros2_msg.bbox, ros1_msg.bbox);
  for(auto result : ros2_msg.results)
  {
    vision_msgs::ObjectHypothesisWithPose ros1_result;
    convert_2_to_1(result, ros1_result);
    ros1_msg.results.push_back(ros1_result);
  }
}

/**
 * @brief Detection2DArray
 */
void convert_1_to_2(
  const vision_msgs::Detection2DArray & ros1_msg,
  vision_msgs::msg::Detection2DArray & ros2_msg
)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for(auto detection : ros1_msg.detections)
  {
    vision_msgs::msg::Detection2D ros2_detection;
    convert_1_to_2(detection, ros2_detection);
    ros2_msg.detections.push_back(ros2_detection);
  }
}

void convert_2_to_1(
  const vision_msgs::msg::Detection2DArray & ros2_msg,
  vision_msgs::Detection2DArray & ros1_msg
)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for(auto detection : ros2_msg.detections)
  {
    vision_msgs::Detection2D ros1_detection;
    convert_2_to_1(detection, ros1_detection);
    ros1_msg.detections.push_back(ros1_detection);
  }
}

/**
 * @brief BoundingBox3D
 */
void convert_1_to_2(
  const vision_msgs::BoundingBox3D & ros1_msg,
  vision_msgs::msg::BoundingBox3D & ros2_msg
)
{
  // Convert center and size
  ros2_msg.center.position.x = ros1_msg.center.position.x;
  ros2_msg.center.position.y = ros1_msg.center.position.y;
  ros2_msg.center.position.z = ros1_msg.center.position.z;
  ros2_msg.center.orientation.x = ros1_msg.center.orientation.x;
  ros2_msg.center.orientation.y = ros1_msg.center.orientation.y;
  ros2_msg.center.orientation.z = ros1_msg.center.orientation.z;
  ros2_msg.center.orientation.w = ros1_msg.center.orientation.w;
  ros2_msg.size.x = ros1_msg.size.x;
  ros2_msg.size.y = ros1_msg.size.y;
  ros2_msg.size.z = ros1_msg.size.z;
}

void convert_2_to_1(
  const vision_msgs::msg::BoundingBox3D & ros2_msg,
  vision_msgs::BoundingBox3D & ros1_msg
)
{
  // Convert center and size
  ros1_msg.center.position.x = ros2_msg.center.position.x;
  ros1_msg.center.position.y = ros2_msg.center.position.y;
  ros1_msg.center.position.z = ros2_msg.center.position.z;
  ros1_msg.center.orientation.x = ros2_msg.center.orientation.x;
  ros1_msg.center.orientation.y = ros2_msg.center.orientation.y;
  ros1_msg.center.orientation.z = ros2_msg.center.orientation.z;
  ros1_msg.center.orientation.w = ros2_msg.center.orientation.w;
  ros1_msg.size.x = ros2_msg.size.x;
  ros1_msg.size.y = ros2_msg.size.y;
  ros1_msg.size.z = ros2_msg.size.z;
}

/**
 * @brief Detection3D
 */
void convert_1_to_2(
  const vision_msgs::Detection3D & ros1_msg,
  vision_msgs::msg::Detection3D & ros2_msg
)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  convert_1_to_2(ros1_msg.bbox, ros2_msg.bbox);
  for(auto result : ros1_msg.results)
  {
    vision_msgs::msg::ObjectHypothesisWithPose ros2_result;
    convert_1_to_2(result, ros2_result);
    ros2_msg.results.push_back(ros2_result);
  }
}

void convert_2_to_1(
  const vision_msgs::msg::Detection3D & ros2_msg,
  vision_msgs::Detection3D & ros1_msg
)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  convert_2_to_1(ros2_msg.bbox, ros1_msg.bbox);
  for(auto result : ros2_msg.results)
  {
    vision_msgs::ObjectHypothesisWithPose ros1_result;
    convert_2_to_1(result, ros1_result);
    ros1_msg.results.push_back(ros1_result);
  }
}

/**
 * @brief Detection3DArray
 */
void convert_1_to_2(
  const vision_msgs::Detection3DArray & ros1_msg,
  vision_msgs::msg::Detection3DArray & ros2_msg
)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for(auto detection : ros1_msg.detections)
  {
    vision_msgs::msg::Detection3D ros2_detection;
    convert_1_to_2(detection, ros2_detection);
    ros2_msg.detections.push_back(ros2_detection);
  }
}

void convert_2_to_1(
  const vision_msgs::msg::Detection3DArray & ros2_msg,
  vision_msgs::Detection3DArray & ros1_msg
)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for(auto detection : ros2_msg.detections)
  {
    vision_msgs::Detection3D ros1_detection;
    convert_2_to_1(detection, ros1_detection);
    ros1_msg.detections.push_back(ros1_detection);
  }
}