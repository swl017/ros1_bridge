// generated from ros1_bridge/resource/interface_factories.cpp.em

#include "vision_msgs_factories.hpp"

#include <algorithm>
#include <stdexcept>

#include "rclcpp/rclcpp.hpp"

// include builtin interfaces
#include <ros1_bridge/convert_builtin_interfaces.hpp>

// include ROS 1 services

// include ROS 2 services

namespace ros1_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_vision_msgs__msg__ObjectHypothesis(const std::string & ros1_type_name, const std::string & ros2_type_name)
{
  (void)ros1_type_name;
  (void)ros2_type_name;
  return std::shared_ptr<FactoryInterface>();
}

std::unique_ptr<ServiceFactoryInterface>
get_service_factory_vision_msgs__msg__ObjectHypothesis(const std::string & ros_id, const std::string & package_name, const std::string & service_name)
{
  (void)ros_id;
  (void)package_name;
  (void)service_name;
  return nullptr;
}
// conversion functions for available interfaces
}  // namespace ros1_bridge


// ROS1 serialization functions
namespace ros1_bridge
{

// This version is for write or length
template<typename STREAM_T, typename VEC_T>
static void streamVectorSize(STREAM_T& stream, const VEC_T& vec)
{
  // Output size of vector to stream
  uint32_t data_len = vec.size();
  stream.next(data_len);
}

// This version is for read
template<typename STREAM_T, typename VEC_T>
static void streamVectorSize(STREAM_T& stream, VEC_T& vec)
{
  // Resize vector to match size in stream
  uint32_t data_len = 0;
  stream.next(data_len);
  vec.resize(data_len);
}

// This version is for write
template<typename VEC_PRIMITIVE_T>
static void streamPrimitiveVector(ros::serialization::OStream & stream, const VEC_PRIMITIVE_T& vec)
{
  const uint32_t data_len = vec.size() * sizeof(typename VEC_PRIMITIVE_T::value_type);
  // copy data from std::vector/std::array into stream
  memcpy(stream.advance(data_len), &vec.front(), data_len);
}

// This version is for length
template<typename VEC_PRIMITIVE_T>
static void streamPrimitiveVector(ros::serialization::LStream & stream, const VEC_PRIMITIVE_T& vec)
{
  const uint32_t data_len = vec.size() * sizeof(typename VEC_PRIMITIVE_T::value_type);
  stream.advance(data_len);
}

// This version is for read
template<typename VEC_PRIMITIVE_T>
static void streamPrimitiveVector(ros::serialization::IStream & stream, VEC_PRIMITIVE_T& vec)
{
  const uint32_t data_len = vec.size() * sizeof(typename VEC_PRIMITIVE_T::value_type);
  // copy data from stream into std::vector/std::array
  memcpy(&vec.front(), stream.advance(data_len), data_len);
}

}  // namespace ros1_bridge
