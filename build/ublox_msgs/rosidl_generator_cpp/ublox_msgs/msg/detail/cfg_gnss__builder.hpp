// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgGNSS.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_gnss__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgGNSS_blocks
{
public:
  explicit Init_CfgGNSS_blocks(::ublox_msgs::msg::CfgGNSS & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgGNSS blocks(::ublox_msgs::msg::CfgGNSS::_blocks_type arg)
  {
    msg_.blocks = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSS msg_;
};

class Init_CfgGNSS_num_config_blocks
{
public:
  explicit Init_CfgGNSS_num_config_blocks(::ublox_msgs::msg::CfgGNSS & msg)
  : msg_(msg)
  {}
  Init_CfgGNSS_blocks num_config_blocks(::ublox_msgs::msg::CfgGNSS::_num_config_blocks_type arg)
  {
    msg_.num_config_blocks = std::move(arg);
    return Init_CfgGNSS_blocks(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSS msg_;
};

class Init_CfgGNSS_num_trk_ch_use
{
public:
  explicit Init_CfgGNSS_num_trk_ch_use(::ublox_msgs::msg::CfgGNSS & msg)
  : msg_(msg)
  {}
  Init_CfgGNSS_num_config_blocks num_trk_ch_use(::ublox_msgs::msg::CfgGNSS::_num_trk_ch_use_type arg)
  {
    msg_.num_trk_ch_use = std::move(arg);
    return Init_CfgGNSS_num_config_blocks(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSS msg_;
};

class Init_CfgGNSS_num_trk_ch_hw
{
public:
  explicit Init_CfgGNSS_num_trk_ch_hw(::ublox_msgs::msg::CfgGNSS & msg)
  : msg_(msg)
  {}
  Init_CfgGNSS_num_trk_ch_use num_trk_ch_hw(::ublox_msgs::msg::CfgGNSS::_num_trk_ch_hw_type arg)
  {
    msg_.num_trk_ch_hw = std::move(arg);
    return Init_CfgGNSS_num_trk_ch_use(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSS msg_;
};

class Init_CfgGNSS_msg_ver
{
public:
  Init_CfgGNSS_msg_ver()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgGNSS_num_trk_ch_hw msg_ver(::ublox_msgs::msg::CfgGNSS::_msg_ver_type arg)
  {
    msg_.msg_ver = std::move(arg);
    return Init_CfgGNSS_num_trk_ch_hw(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSS msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgGNSS>()
{
  return ublox_msgs::msg::builder::Init_CfgGNSS_msg_ver();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS__BUILDER_HPP_
