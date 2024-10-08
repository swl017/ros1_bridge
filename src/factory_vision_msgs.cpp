#include <ros1_bridge/factory.hpp>
#include <vision_msgs/BoundingBox2D.h>
#include <vision_msgs/msg/bounding_box2_d.hpp>
#include <vision_msgs/BoundingBox3D.h>
#include <vision_msgs/msg/bounding_box3_d.hpp>
#include <vision_msgs/BoundingBox2DArray.h>
#include <vision_msgs/msg/bounding_box2_d_array.hpp>
#include <vision_msgs/BoundingBox3DArray.h>
#include <vision_msgs/msg/bounding_box3_d_array.hpp>
// #include <vision_msgs/Classification2D.h>
// #include <vision_msgs/msg/classification2_d.hpp>
// #include <vision_msgs/Classification3D.h>
// #include <vision_msgs/msg/classification3_d.hpp>
#include <vision_msgs/Detection2DArray.h>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <vision_msgs/Detection3DArray.h>
#include <vision_msgs/msg/detection3_d_array.hpp>
#include <vision_msgs/ObjectHypothesis.h>
#include <vision_msgs/msg/object_hypothesis.hpp>
#include <vision_msgs/ObjectHypothesisWithPose.h>
#include <vision_msgs/msg/object_hypothesis_with_pose.hpp>
#include <vision_msgs/VisionInfo.h>
#include <vision_msgs/msg/vision_info.hpp>

namespace ros1_bridge
{

// BoundingBox2D
template<>
void
Factory<vision_msgs::BoundingBox2D, vision_msgs::msg::BoundingBox2D>::convert_1_to_2(
  const vision_msgs::BoundingBox2D & ros1_msg,
  vision_msgs::msg::BoundingBox2D & ros2_msg)
{
//   convert_1_to_2(ros1_msg.center, ros2_msg.center);
//   convert_1_to_2(ros1_msg.size_x, ros2_msg.size_x);
//   convert_1_to_2(ros1_msg.size_y, ros2_msg.size_y);
  ros2_msg.center.position.x = ros1_msg.center.x;
  ros2_msg.center.position.y = ros1_msg.center.y;
  ros2_msg.center.theta = ros1_msg.center.theta;
  ros2_msg.size_x = ros1_msg.size_x;
  ros2_msg.size_y = ros1_msg.size_y;
}

template<>
void
Factory<vision_msgs::BoundingBox2D, vision_msgs::msg::BoundingBox2D>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox2D & ros2_msg,
  vision_msgs::BoundingBox2D & ros1_msg)
{
//   convert_2_to_1(ros2_msg.center, ros1_msg.center);
//   convert_2_to_1(ros2_msg.size_x, ros1_msg.size_x);
//   convert_2_to_1(ros2_msg.size_y, ros1_msg.size_y);
  ros1_msg.center.x = ros2_msg.center.position.x;
  ros1_msg.center.y = ros2_msg.center.position.y;
  ros1_msg.center.theta = ros2_msg.center.theta;
  ros1_msg.size_x = ros2_msg.size_x;
  ros1_msg.size_y = ros2_msg.size_y;

}

// BoundingBox3D
template<>
void
Factory<vision_msgs::BoundingBox3D, vision_msgs::msg::BoundingBox3D>::convert_1_to_2(
  const vision_msgs::BoundingBox3D & ros1_msg,
  vision_msgs::msg::BoundingBox3D & ros2_msg)
{
  convert_1_to_2(ros1_msg.center, ros2_msg.center);
  convert_1_to_2(ros1_msg.size, ros2_msg.size);
}

template<>
void
Factory<vision_msgs::BoundingBox3D, vision_msgs::msg::BoundingBox3D>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox3D & ros2_msg,
  vision_msgs::BoundingBox3D & ros1_msg)
{
  convert_2_to_1(ros2_msg.center, ros1_msg.center);
  convert_2_to_1(ros2_msg.size, ros1_msg.size);
}

// BoundingBox2DArray
template<>
void
Factory<vision_msgs::BoundingBox2DArray, vision_msgs::msg::BoundingBox2DArray>::convert_1_to_2(
  const vision_msgs::BoundingBox2DArray & ros1_msg,
  vision_msgs::msg::BoundingBox2DArray & ros2_msg)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for (const auto & box : ros1_msg.boxes) {
    vision_msgs::msg::BoundingBox2D ros2_box;
    convert_1_to_2(box, ros2_box);
    ros2_msg.boxes.push_back(ros2_box);
  }
}

template<>
void
Factory<vision_msgs::BoundingBox2DArray, vision_msgs::msg::BoundingBox2DArray>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox2DArray & ros2_msg,
  vision_msgs::BoundingBox2DArray & ros1_msg)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for (const auto & box : ros2_msg.boxes) {
    vision_msgs::BoundingBox2D ros1_box;
    convert_2_to_1(box, ros1_box);
    ros1_msg.boxes.push_back(ros1_box);
  }
}

// BoundingBox3DArray
template<>
void
Factory<vision_msgs::BoundingBox3DArray, vision_msgs::msg::BoundingBox3DArray>::convert_1_to_2(
  const vision_msgs::BoundingBox3DArray & ros1_msg,
  vision_msgs::msg::BoundingBox3DArray & ros2_msg)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for (const auto & box : ros1_msg.boxes) {
    vision_msgs::msg::BoundingBox3D ros2_box;
    convert_1_to_2(box, ros2_box);
    ros2_msg.boxes.push_back(ros2_box);
  }
}

template<>
void
Factory<vision_msgs::BoundingBox3DArray, vision_msgs::msg::BoundingBox3DArray>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox3DArray & ros2_msg,
  vision_msgs::BoundingBox3DArray & ros1_msg)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for (const auto & box : ros2_msg.boxes) {
    vision_msgs::BoundingBox3D ros1_box;
    convert_2_to_1(box, ros1_box);
    ros1_msg.boxes.push_back(ros1_box);
  }
}

// // Classification2D
// template<>
// void
// Factory<vision_msgs::Classification2D, vision_msgs::msg::Classification2D>::convert_1_to_2(
//   const vision_msgs::Classification2D & ros1_msg,
//   vision_msgs::msg::Classification2D & ros2_msg)
// {
//   convert_1_to_2(ros1_msg.header, ros2_msg.header);
//   for (const auto & result : ros1_msg.results) {
//     vision_msgs::msg::ObjectHypothesis ros2_hypothesis;
//     convert_1_to_2(result, ros2_hypothesis);
//     ros2_msg.results.push_back(ros2_hypothesis);
//   }
// }

// template<>
// void
// Factory<vision_msgs::Classification2D, vision_msgs::msg::Classification2D>::convert_2_to_1(
//   const vision_msgs::msg::Classification2D & ros2_msg,
//   vision_msgs::Classification2D & ros1_msg)
// {
//   convert_2_to_1(ros2_msg.header, ros1_msg.header);
//   for (const auto & hypothesis : ros2_msg.results) {
//     vision_msgs::ObjectHypothesis ros1_result;
//     convert_2_to_1(hypothesis, ros1_result);
//     ros1_msg.results.push_back(ros1_result);
//   }
// }

// // Classification3D
// template<>
// void
// Factory<vision_msgs::Classification3D, vision_msgs::msg::Classification3D>::convert_1_to_2(
//   const vision_msgs::Classification3D & ros1_msg,
//   vision_msgs::msg::Classification3D & ros2_msg)
// {
//   convert_1_to_2(ros1_msg.header, ros2_msg.header);
//   for (const auto & result : ros1_msg.results) {
//     vision_msgs::msg::ObjectHypothesis ros2_hypothesis;
//     convert_1_to_2(result, ros2_hypothesis);
//     ros2_msg.results.push_back(ros2_hypothesis);
//   }
// }

// template<>
// void
// Factory<vision_msgs::Classification3D, vision_msgs::msg::Classification3D>::convert_2_to_1(
//   const vision_msgs::msg::Classification3D & ros2_msg,
//   vision_msgs::Classification3D & ros1_msg)
// {
//   convert_2_to_1(ros2_msg.header, ros1_msg.header);
//   for (const auto & hypothesis : ros2_msg.results) {
//     vision_msgs::ObjectHypothesis ros1_result;
//     convert_2_to_1(hypothesis, ros1_result);
//     ros1_msg.results.push_back(ros1_result);
//   }
// }

// Detection2DArray
template<>
void
Factory<vision_msgs::Detection2DArray, vision_msgs::msg::Detection2DArray>::convert_1_to_2(
  const vision_msgs::Detection2DArray & ros1_msg,
  vision_msgs::msg::Detection2DArray & ros2_msg)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for (const auto & detection : ros1_msg.detections) {
    vision_msgs::msg::Detection2D ros2_detection;
    convert_1_to_2(detection, ros2_detection);
    ros2_msg.detections.push_back(ros2_detection);
  }
}

template<>
void
Factory<vision_msgs::Detection2DArray, vision_msgs::msg::Detection2DArray>::convert_2_to_1(
  const vision_msgs::msg::Detection2DArray & ros2_msg,
  vision_msgs::Detection2DArray & ros1_msg)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for (const auto & detection : ros2_msg.detections) {
    vision_msgs::Detection2D ros1_detection;
    convert_2_to_1(detection, ros1_detection);
    ros1_msg.detections.push_back(ros1_detection);
  }
}

// Detection3DArray
template<>
void
Factory<vision_msgs::Detection3DArray, vision_msgs::msg::Detection3DArray>::convert_1_to_2(
  const vision_msgs::Detection3DArray & ros1_msg,
  vision_msgs::msg::Detection3DArray & ros2_msg)
{
  convert_1_to_2(ros1_msg.header, ros2_msg.header);
  for (const auto & detection : ros1_msg.detections) {
    vision_msgs::msg::Detection3D ros2_detection;
    convert_1_to_2(detection, ros2_detection);
    ros2_msg.detections.push_back(ros2_detection);
  }
}

template<>
void
Factory<vision_msgs::Detection3DArray, vision_msgs::msg::Detection3DArray>::convert_2_to_1(
  const vision_msgs::msg::Detection3DArray & ros2_msg,
  vision_msgs::Detection3DArray & ros1_msg)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  for (const auto & detection : ros2_msg.detections) {
    vision_msgs::Detection3D ros1_detection;
    convert_2_to_1(detection, ros1_detection);
    ros1_msg.detections.push_back(ros1_detection);
  }
}

// ObjectHypothesis
template<>
void
Factory<vision_msgs::ObjectHypothesis, vision_msgs::msg::ObjectHypothesis>::convert_1_to_2(
  const vision_msgs::ObjectHypothesis & ros1_msg,
  vision_msgs::msg::ObjectHypothesis & ros2_msg)
{
//   convert_1_to_2(ros1_msg.id, ros2_msg.class_id);
  ros2_msg.hypothesis.class_id = std::to_string(ros1_msg.id);
  convert_1_to_2(ros1_msg.score, ros2_msg.score);
}

template<>
void
Factory<vision_msgs::ObjectHypothesis, vision_msgs::msg::ObjectHypothesis>::convert_2_to_1(
  const vision_msgs::msg::ObjectHypothesis & ros2_msg,
  vision_msgs::ObjectHypothesis & ros1_msg)
{
//   convert_2_to_1(ros2_msg.class_id, ros1_msg.id);
  try
  {
    ros1_msg.id = std::stoi(ros2_msg.hypothesis.class_id);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  convert_2_to_1(ros2_msg.score, ros1_msg.score);
}

// ObjectHypothesisWithPose
template<>
void
Factory<vision_msgs::ObjectHypothesisWithPose, vision_msgs::msg::ObjectHypothesisWithPose>::convert_1_to_2(
  const vision_msgs::ObjectHypothesisWithPose & ros1_msg,
  vision_msgs::msg::ObjectHypothesisWithPose & ros2_msg)
{
  ros2_msg.hypothesis.class_id = std::to_string(ros1_msg.id);
//   convert_1_to_2(ros1_msg.id, ros2_msg.hypothesis.class_id);
  convert_1_to_2(ros1_msg.score, ros2_msg.hypothesis.score);
  convert_1_to_2(ros1_msg.pose, ros2_msg.pose);
}

template<>
void
Factory<vision_msgs::ObjectHypothesisWithPose, vision_msgs::msg::ObjectHypothesisWithPose>::convert_2_to_1(
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
  convert_2_to_1(ros2_msg.hypothesis.score, ros1_msg.score);
  convert_2_to_1(ros2_msg.pose, ros1_msg.pose);
}

// VisionInfo (continued)
template<>
void
Factory<vision_msgs::VisionInfo, vision_msgs::msg::VisionInfo>::convert_2_to_1(
  const vision_msgs::msg::VisionInfo & ros2_msg,
  vision_msgs::VisionInfo & ros1_msg)
{
  convert_2_to_1(ros2_msg.header, ros1_msg.header);
  convert_2_to_1(ros2_msg.method, ros1_msg.method);
  convert_2_to_1(ros2_msg.database_location, ros1_msg.database_location);
  convert_2_to_1(ros2_msg.database_version, ros1_msg.database_version);
}

}  // namespace ros1_bridge