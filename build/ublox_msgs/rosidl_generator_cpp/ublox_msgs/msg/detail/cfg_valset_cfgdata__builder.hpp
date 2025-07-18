// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgVALSETCfgdata.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_valset_cfgdata__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgVALSETCfgdata_data
{
public:
  explicit Init_CfgVALSETCfgdata_data(::ublox_msgs::msg::CfgVALSETCfgdata & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgVALSETCfgdata data(::ublox_msgs::msg::CfgVALSETCfgdata::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSETCfgdata msg_;
};

class Init_CfgVALSETCfgdata_key
{
public:
  Init_CfgVALSETCfgdata_key()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgVALSETCfgdata_data key(::ublox_msgs::msg::CfgVALSETCfgdata::_key_type arg)
  {
    msg_.key = std::move(arg);
    return Init_CfgVALSETCfgdata_data(msg_);
  }

private:
  ::ublox_msgs::msg::CfgVALSETCfgdata msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgVALSETCfgdata>()
{
  return ublox_msgs::msg::builder::Init_CfgVALSETCfgdata_key();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_VALSET_CFGDATA__BUILDER_HPP_
