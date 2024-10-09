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
get_factory_vision_msgs__msg__BoundingBox2DArray(const std::string & ros1_type_name, const std::string & ros2_type_name)
{
  // mapping from string to specialized template
  if (
    (ros1_type_name == "vision_msgs/BoundingBox2DArray" ||
     ros1_type_name == "") &&
    ros2_type_name == "vision_msgs/msg/BoundingBox2DArray")
  {
    return std::make_shared<
      Factory<
        vision_msgs::BoundingBox2DArray,
        vision_msgs::msg::BoundingBox2DArray
      >
    >("vision_msgs/BoundingBox2DArray", ros2_type_name);
  }
  return std::shared_ptr<FactoryInterface>();
}

std::unique_ptr<ServiceFactoryInterface>
get_service_factory_vision_msgs__msg__BoundingBox2DArray(const std::string & ros_id, const std::string & package_name, const std::string & service_name)
{
  (void)ros_id;
  (void)package_name;
  (void)service_name;
  return nullptr;
}
// conversion functions for available interfaces

template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_1_to_2(
  const vision_msgs::BoundingBox2DArray & ros1_msg,
  vision_msgs::msg::BoundingBox2DArray & ros2_msg)
{

  // convert non-array field
  // convert sub message field
  Factory<
    std_msgs::Header,
    std_msgs::msg::Header
  >::convert_1_to_2(
    ros1_msg.header, ros2_msg.header);

  // convert array or sequence field
  // dynamically sized sequence, ensure destination sequence/vector size is large enough
  // resize ros2 field to match the ros1 field
  ros2_msg.boxes.resize(ros1_msg.boxes.size());
  // copy element wise since the type is different
  {
    auto ros1_it = ros1_msg.boxes.cbegin();
    auto ros2_it = ros2_msg.boxes.begin();
    for (
      ;
      ros1_it != ros1_msg.boxes.cend() &&
      ros2_it != ros2_msg.boxes.end();
      ++ros1_it, ++ros2_it
    )
    {
      // convert sub message element
      Factory<
        vision_msgs::BoundingBox2D,
        vision_msgs::msg::BoundingBox2D
      >::convert_1_to_2(
        *ros1_it, *ros2_it);
    }
  }
}

template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_2_to_1(
  const vision_msgs::msg::BoundingBox2DArray & ros2_msg,
  vision_msgs::BoundingBox2DArray & ros1_msg)
{

  // convert non-array field
  // convert sub message field
  Factory<
    std_msgs::Header,
    std_msgs::msg::Header
  >::convert_2_to_1(
    ros2_msg.header, ros1_msg.header);

  // convert array or sequence field
  // dynamically sized sequence, ensure destination vector size is large enough
  // resize ros1 field to match the ros2 field
  ros1_msg.boxes.resize(ros2_msg.boxes.size());
  // copy element wise since the type is different
  {
    auto ros2_it = ros2_msg.boxes.cbegin();
    auto ros1_it = ros1_msg.boxes.begin();
    for (
      ;
      ros2_it != ros2_msg.boxes.cend() &&
      ros1_it != ros1_msg.boxes.end();
      ++ros2_it, ++ros1_it
    )
    {
      // convert sub message element
      Factory<
        vision_msgs::BoundingBox2D,
        vision_msgs::msg::BoundingBox2D
      >::convert_2_to_1(
        *ros2_it, *ros1_it);
    }
  }
}
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




template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::internal_stream_translate_helper(
  ros::serialization::OStream & stream,
  vision_msgs::msg::BoundingBox2DArray const & ros2_msg)
{

  // write non-array field
  // write sub message field
  Factory<
    std_msgs::Header,
    std_msgs::msg::Header
  >::internal_stream_translate_helper(stream, ros2_msg.header);

  // write array or sequence field
  // dynamically sized sequence
  streamVectorSize(stream, ros2_msg.boxes);
  // write element wise since the type is different
  {
    for (
      auto ros2_it = ros2_msg.boxes.begin();
      ros2_it != ros2_msg.boxes.end();
      ++ros2_it
    )
    {
      // write sub message element
      Factory<
        vision_msgs::BoundingBox2D,
        vision_msgs::msg::BoundingBox2D
      >::internal_stream_translate_helper(stream, *ros2_it);
    }
  }
}


template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::internal_stream_translate_helper(
  ros::serialization::IStream & stream,
  vision_msgs::msg::BoundingBox2DArray  & ros2_msg)
{

  // write non-array field
  // write sub message field
  Factory<
    std_msgs::Header,
    std_msgs::msg::Header
  >::internal_stream_translate_helper(stream, ros2_msg.header);

  // write array or sequence field
  // dynamically sized sequence
  streamVectorSize(stream, ros2_msg.boxes);
  // write element wise since the type is different
  {
    for (
      auto ros2_it = ros2_msg.boxes.begin();
      ros2_it != ros2_msg.boxes.end();
      ++ros2_it
    )
    {
      // write sub message element
      Factory<
        vision_msgs::BoundingBox2D,
        vision_msgs::msg::BoundingBox2D
      >::internal_stream_translate_helper(stream, *ros2_it);
    }
  }
}


template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::internal_stream_translate_helper(
  ros::serialization::LStream & stream,
  vision_msgs::msg::BoundingBox2DArray const & ros2_msg)
{

  // write non-array field
  // write sub message field
  Factory<
    std_msgs::Header,
    std_msgs::msg::Header
  >::internal_stream_translate_helper(stream, ros2_msg.header);

  // write array or sequence field
  // dynamically sized sequence
  streamVectorSize(stream, ros2_msg.boxes);
  // write element wise since the type is different
  {
    for (
      auto ros2_it = ros2_msg.boxes.begin();
      ros2_it != ros2_msg.boxes.end();
      ++ros2_it
    )
    {
      // write sub message element
      Factory<
        vision_msgs::BoundingBox2D,
        vision_msgs::msg::BoundingBox2D
      >::internal_stream_translate_helper(stream, *ros2_it);
    }
  }
}



template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_2_to_1(const vision_msgs::msg::BoundingBox2DArray& ros2_msg,
                  ros::serialization::OStream& out_stream)
{
  internal_stream_translate_helper(out_stream, ros2_msg);
}


template<>
void
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::convert_1_to_2(ros::serialization::IStream& in_stream,
                  vision_msgs::msg::BoundingBox2DArray& ros2_msg)
{
  internal_stream_translate_helper(in_stream, ros2_msg);
}

template<>
uint32_t
Factory<
  vision_msgs::BoundingBox2DArray,
  vision_msgs::msg::BoundingBox2DArray
>::length_2_as_1_stream(const vision_msgs::msg::BoundingBox2DArray& ros2_msg)
{
  ros::serialization::LStream len_stream;
  internal_stream_translate_helper(len_stream, ros2_msg);
  return len_stream.getLength();
}



}  // namespace ros1_bridge
