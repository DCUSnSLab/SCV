// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/EsfRAWBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/esf_raw_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_EsfRAWBlock_s_t_tag
{
public:
  explicit Init_EsfRAWBlock_s_t_tag(::ublox_msgs::msg::EsfRAWBlock & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::EsfRAWBlock s_t_tag(::ublox_msgs::msg::EsfRAWBlock::_s_t_tag_type arg)
  {
    msg_.s_t_tag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::EsfRAWBlock msg_;
};

class Init_EsfRAWBlock_data
{
public:
  Init_EsfRAWBlock_data()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EsfRAWBlock_s_t_tag data(::ublox_msgs::msg::EsfRAWBlock::_data_type arg)
  {
    msg_.data = std::move(arg);
    return Init_EsfRAWBlock_s_t_tag(msg_);
  }

private:
  ::ublox_msgs::msg::EsfRAWBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::EsfRAWBlock>()
{
  return ublox_msgs::msg::builder::Init_EsfRAWBlock_data();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__ESF_RAW_BLOCK__BUILDER_HPP_
