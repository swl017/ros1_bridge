// generated from ros1_bridge/resource/pkg_factories.cpp.em

#include "vision_msgs_factories.hpp"

namespace ros1_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs(const std::string & ros1_type_name, const std::string & ros2_type_name)
{
  std::shared_ptr<FactoryInterface> factory;
  factory = get_factory_vision_msgs__msg__BoundingBox2D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__BoundingBox2DArray(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__BoundingBox3D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__BoundingBox3DArray(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Classification(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Detection2D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Detection2DArray(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Detection3D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Detection3DArray(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__LabelInfo(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__ObjectHypothesis(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__ObjectHypothesisWithPose(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Point2D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__Pose2D(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__VisionClass(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  factory = get_factory_vision_msgs__msg__VisionInfo(ros1_type_name, ros2_type_name);
  if (factory) {
    return factory;
  }
  return std::shared_ptr<FactoryInterface>();
}

std::unique_ptr<ServiceFactoryInterface>
get_service_factory_vision_msgs(const std::string & ros_id, const std::string & package_name, const std::string & service_name)
{
  (void)ros_id;
  (void)package_name;
  (void)service_name;
  return nullptr;
}
}  // namespace ros1_bridge
