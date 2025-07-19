// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmSFRB.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_sfrb__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmSFRB_dwrd
{
public:
  explicit Init_RxmSFRB_dwrd(::ublox_msgs::msg::RxmSFRB & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmSFRB dwrd(::ublox_msgs::msg::RxmSFRB::_dwrd_type arg)
  {
    msg_.dwrd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRB msg_;
};

class Init_RxmSFRB_svid
{
public:
  explicit Init_RxmSFRB_svid(::ublox_msgs::msg::RxmSFRB & msg)
  : msg_(msg)
  {}
  Init_RxmSFRB_dwrd svid(::ublox_msgs::msg::RxmSFRB::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_RxmSFRB_dwrd(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRB msg_;
};

class Init_RxmSFRB_chn
{
public:
  Init_RxmSFRB_chn()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmSFRB_svid chn(::ublox_msgs::msg::RxmSFRB::_chn_type arg)
  {
    msg_.chn = std::move(arg);
    return Init_RxmSFRB_svid(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmSFRB>()
{
  return ublox_msgs::msg::builder::Init_RxmSFRB_chn();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRB__BUILDER_HPP_
