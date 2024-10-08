#include "ros1_bridge/convert_builtin_interfaces.hpp"

#include <vision_msgs/ObjectHypothesisWithPose.h>
#include <vision_msgs/msg/object_hypothesis_with_pose.hpp>
#include <vision_msgs/Detection2D.h>
#include <vision_msgs/msg/detection2_d.hpp>
#include <vision_msgs/Detection2DArray.h>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <vision_msgs/Detection3D.h>
#include <vision_msgs/msg/detection3_d.hpp>

namespace ros1_bridge
{

// ObjectHypothesisWithPose conversion
template<>
void
convert_1_to_2(
  const vision_msgs::ObjectHypothesisWithPose & ros1_msg,
  vision_msgs::msg::ObjectHypothesisWithPose & ros2_msg)
{
  ros2_msg.hypothesis.class_id = std::to_string(ros1_msg.id);
  ros2_msg.hypothesis.score = ros1_msg.score;
  convert_1_to_2(ros1_msg.pose, ros2_msg.pose);
}

template<>
void
convert_2_to_1(
  const vision_msgs::msg::ObjectHypothesisWithPose & ros2_msg,
  vision_msgs::ObjectHypothesisWithPose & ros1_msg)
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
  convert_2_to_1(ros2_msg.pose, ros1_msg.pose);
}

// Detection2D conversion
template<>
void
convert_1_to_2(
  const vision_msgs::Detection2D & ros1_msg,
  vision_msgs::msg::Detection2D & ros2_msg)
{
  ros2_msg.header.stamp.sec = ros1_msg.header.stamp.sec;
  ros2_msg.header.stamp.nanosec = ros1_msg.header.stamp.nsec;
  ros2_msg.header.frame_id = ros1_msg.header.frame_id;
  // convert_1_to_2(ros1_msg.header, ros2_msg.header);

  for(size_t i = 0; i < ros1_msg.results.size(); i++)
  {
    ros2_msg.results.push_back(vision_msgs::msg::ObjectHypothesisWithPose());
    convert_1_to_2(ros1_msg.results[i], ros2_msg.results[i]);
  }
}

template<>
void
convert_2_to_1(
  const vision_msgs::msg::Detection2D & ros2_msg,
  vision_msgs::Detection2D & ros1_msg)
{
  ros1_msg.header.stamp.sec = ros2_msg.header.stamp.sec;
  ros1_msg.header.stamp.nsec = ros2_msg.header.stamp.nanosec;
  ros1_msg.header.frame_id = ros2_msg.header.frame_id;
  // convert_2_to_1(ros2_msg.header, ros1_msg.header);

  for(size_t i = 0; i < ros2_msg.results.size(); i++)
  {
    ros1_msg.results.push_back(vision_msgs::ObjectHypothesisWithPose());
    convert_2_to_1(ros2_msg.results[i], ros1_msg.results[i]);
  }
}

// Detection2DArray conversion
template<>
void
convert_1_to_2(
  const vision_msgs::Detection2DArray & ros1_msg,
  vision_msgs::msg::Detection2DArray & ros2_msg)
{
  ros2_msg.header.stamp.sec = ros1_msg.header.stamp.sec;
  ros2_msg.header.stamp.nanosec = ros1_msg.header.stamp.nsec;
  ros2_msg.header.frame_id = ros1_msg.header.frame_id;
  // convert_1_to_2(ros1_msg.header, ros2_msg.header);

  for(size_t i = 0; i < ros1_msg.detections.size(); i++)
  {
    ros2_msg.detections.push_back(vision_msgs::msg::Detection2D());
    convert_1_to_2(ros1_msg.detections[i], ros2_msg.detections[i]);
  }
}

template<>
void
convert_2_to_1(
  const vision_msgs::msg::Detection2DArray & ros2_msg,
  vision_msgs::Detection2DArray & ros1_msg)
{
  ros1_msg.header.stamp.sec = ros2_msg.header.stamp.sec;
  ros1_msg.header.stamp.nsec = ros2_msg.header.stamp.nanosec;
  ros1_msg.header.frame_id = ros2_msg.header.frame_id;
  // convert_2_to_1(ros2_msg.header, ros1_msg.header);

  for(size_t i = 0; i < ros2_msg.detections.size(); i++)
  {
    ros1_msg.detections.push_back(vision_msgs::Detection2D());
    convert_2_to_1(ros2_msg.detections[i], ros1_msg.detections[i]);
  }
}

}  // namespace ros1_bridge