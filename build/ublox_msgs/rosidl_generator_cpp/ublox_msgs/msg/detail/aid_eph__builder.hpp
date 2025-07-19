// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/AidEPH.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_EPH__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_EPH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/aid_eph__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_AidEPH_sf3d
{
public:
  explicit Init_AidEPH_sf3d(::ublox_msgs::msg::AidEPH & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::AidEPH sf3d(::ublox_msgs::msg::AidEPH::_sf3d_type arg)
  {
    msg_.sf3d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::AidEPH msg_;
};

class Init_AidEPH_sf2d
{
public:
  explicit Init_AidEPH_sf2d(::ublox_msgs::msg::AidEPH & msg)
  : msg_(msg)
  {}
  Init_AidEPH_sf3d sf2d(::ublox_msgs::msg::AidEPH::_sf2d_type arg)
  {
    msg_.sf2d = std::move(arg);
    return Init_AidEPH_sf3d(msg_);
  }

private:
  ::ublox_msgs::msg::AidEPH msg_;
};

class Init_AidEPH_sf1d
{
public:
  explicit Init_AidEPH_sf1d(::ublox_msgs::msg::AidEPH & msg)
  : msg_(msg)
  {}
  Init_AidEPH_sf2d sf1d(::ublox_msgs::msg::AidEPH::_sf1d_type arg)
  {
    msg_.sf1d = std::move(arg);
    return Init_AidEPH_sf2d(msg_);
  }

private:
  ::ublox_msgs::msg::AidEPH msg_;
};

class Init_AidEPH_how
{
public:
  explicit Init_AidEPH_how(::ublox_msgs::msg::AidEPH & msg)
  : msg_(msg)
  {}
  Init_AidEPH_sf1d how(::ublox_msgs::msg::AidEPH::_how_type arg)
  {
    msg_.how = std::move(arg);
    return Init_AidEPH_sf1d(msg_);
  }

private:
  ::ublox_msgs::msg::AidEPH msg_;
};

class Init_AidEPH_svid
{
public:
  Init_AidEPH_svid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AidEPH_how svid(::ublox_msgs::msg::AidEPH::_svid_type arg)
  {
    msg_.svid = std::move(arg);
    return Init_AidEPH_how(msg_);
  }

private:
  ::ublox_msgs::msg::AidEPH msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::AidEPH>()
{
  return ublox_msgs::msg::builder::Init_AidEPH_svid();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_EPH__BUILDER_HPP_
