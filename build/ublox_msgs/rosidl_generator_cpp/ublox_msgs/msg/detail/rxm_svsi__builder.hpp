// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmSVSI.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SVSI__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SVSI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_svsi__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmSVSI_sv
{
public:
  explicit Init_RxmSVSI_sv(::ublox_msgs::msg::RxmSVSI & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmSVSI sv(::ublox_msgs::msg::RxmSVSI::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSI msg_;
};

class Init_RxmSVSI_num_sv
{
public:
  explicit Init_RxmSVSI_num_sv(::ublox_msgs::msg::RxmSVSI & msg)
  : msg_(msg)
  {}
  Init_RxmSVSI_sv num_sv(::ublox_msgs::msg::RxmSVSI::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_RxmSVSI_sv(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSI msg_;
};

class Init_RxmSVSI_num_vis
{
public:
  explicit Init_RxmSVSI_num_vis(::ublox_msgs::msg::RxmSVSI & msg)
  : msg_(msg)
  {}
  Init_RxmSVSI_num_sv num_vis(::ublox_msgs::msg::RxmSVSI::_num_vis_type arg)
  {
    msg_.num_vis = std::move(arg);
    return Init_RxmSVSI_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSI msg_;
};

class Init_RxmSVSI_week
{
public:
  explicit Init_RxmSVSI_week(::ublox_msgs::msg::RxmSVSI & msg)
  : msg_(msg)
  {}
  Init_RxmSVSI_num_vis week(::ublox_msgs::msg::RxmSVSI::_week_type arg)
  {
    msg_.week = std::move(arg);
    return Init_RxmSVSI_num_vis(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSI msg_;
};

class Init_RxmSVSI_i_tow
{
public:
  Init_RxmSVSI_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmSVSI_week i_tow(::ublox_msgs::msg::RxmSVSI::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_RxmSVSI_week(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSVSI msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmSVSI>()
{
  return ublox_msgs::msg::builder::Init_RxmSVSI_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SVSI__BUILDER_HPP_
