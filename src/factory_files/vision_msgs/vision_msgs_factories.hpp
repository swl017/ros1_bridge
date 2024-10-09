// generated from ros1_bridge/resource/pkg_factories.hpp.em

#include <memory>
#include <string>

#include <ros1_bridge/factory.hpp>

// include ROS 1 messages
#include <vision_msgs/BoundingBox2DArray.h>
#include <vision_msgs/BoundingBox3D.h>
#include <vision_msgs/BoundingBox3DArray.h>
#include <vision_msgs/Detection2DArray.h>
#include <vision_msgs/Detection3DArray.h>
#include <vision_msgs/VisionInfo.h>

// include ROS 2 messages
#include <vision_msgs/msg/bounding_box2_d_array.hpp>
#include <vision_msgs/msg/bounding_box3_d.hpp>
#include <vision_msgs/msg/bounding_box3_d_array.hpp>
#include <vision_msgs/msg/detection2_d_array.hpp>
#include <vision_msgs/msg/detection3_d_array.hpp>
#include <vision_msgs/msg/vision_info.hpp>

namespace ros1_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__BoundingBox2D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__BoundingBox2DArray(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__BoundingBox3D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__BoundingBox3DArray(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Classification(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Detection2D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Detection2DArray(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Detection3D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Detection3DArray(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__LabelInfo(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__ObjectHypothesis(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__ObjectHypothesisWithPose(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Point2D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__Pose2D(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__VisionClass(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__VisionInfo(const std::string & ros1_type_name, const std::string & ros2_type_name);

std::unique_ptr<ServiceFactoryInterface>
get_service_factory_vision_msgs(const std::string & ros_id, const std::string & package_name, const std::string & service_name);

// conversion functions for available interfaces

template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_1_to_2(
  const vision_msgs::BoundingBox2DArray & ros1_msg,
  vision_msgs::msg::BoundingBox2DArray & ros2_msg);

template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox2DArray & ros2_msg,
  vision_msgs::BoundingBox2DArray & ros1_msg);


template<>
void
Factory<
  vision_msgs::BoundingBox3D,
  vision_msgs::msg::BoundingBox3D
>::convert_1_to_2(
  const vision_msgs::BoundingBox3D & ros1_msg,
  vision_msgs::msg::BoundingBox3D & ros2_msg);

template<>
void
Factory<
  vision_msgs::BoundingBox3D,
  vision_msgs::msg::BoundingBox3D
>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox3D & ros2_msg,
  vision_msgs::BoundingBox3D & ros1_msg);


template<>
void
Factory<
  vision_msgs::BoundingBox3DArray,
  vision_msgs::msg::BoundingBox3DArray
>::convert_1_to_2(
  const vision_msgs::BoundingBox3DArray & ros1_msg,
  vision_msgs::msg::BoundingBox3DArray & ros2_msg);

template<>
void
Factory<
  vision_msgs::BoundingBox3DArray,
  vision_msgs::msg::BoundingBox3DArray
>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox3DArray & ros2_msg,
  vision_msgs::BoundingBox3DArray & ros1_msg);


template<>
void
Factory<
  vision_msgs::Detection2DArray,
  vision_msgs::msg::Detection2DArray
>::convert_1_to_2(
  const vision_msgs::Detection2DArray & ros1_msg,
  vision_msgs::msg::Detection2DArray & ros2_msg);

template<>
void
Factory<
  vision_msgs::Detection2DArray,
  vision_msgs::msg::Detection2DArray
>::convert_2_to_1(
  const vision_msgs::msg::Detection2DArray & ros2_msg,
  vision_msgs::Detection2DArray & ros1_msg);


template<>
void
Factory<
  vision_msgs::Detection3DArray,
  vision_msgs::msg::Detection3DArray
>::convert_1_to_2(
  const vision_msgs::Detection3DArray & ros1_msg,
  vision_msgs::msg::Detection3DArray & ros2_msg);

template<>
void
Factory<
  vision_msgs::Detection3DArray,
  vision_msgs::msg::Detection3DArray
>::convert_2_to_1(
  const vision_msgs::msg::Detection3DArray & ros2_msg,
  vision_msgs::Detection3DArray & ros1_msg);


template<>
void
Factory<
  vision_msgs::VisionInfo,
  vision_msgs::msg::VisionInfo
>::convert_1_to_2(
  const vision_msgs::VisionInfo & ros1_msg,
  vision_msgs::msg::VisionInfo & ros2_msg);

template<>
void
Factory<
  vision_msgs::VisionInfo,
  vision_msgs::msg::VisionInfo
>::convert_2_to_1(
  const vision_msgs::msg::VisionInfo & ros2_msg,
  vision_msgs::VisionInfo & ros1_msg);

}  // namespace ros1_bridge
