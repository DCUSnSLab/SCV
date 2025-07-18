// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgGNSSBlock.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_gnss_block__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgGNSSBlock_flags
{
public:
  explicit Init_CfgGNSSBlock_flags(::ublox_msgs::msg::CfgGNSSBlock & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgGNSSBlock flags(::ublox_msgs::msg::CfgGNSSBlock::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSSBlock msg_;
};

class Init_CfgGNSSBlock_reserved1
{
public:
  explicit Init_CfgGNSSBlock_reserved1(::ublox_msgs::msg::CfgGNSSBlock & msg)
  : msg_(msg)
  {}
  Init_CfgGNSSBlock_flags reserved1(::ublox_msgs::msg::CfgGNSSBlock::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_CfgGNSSBlock_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSSBlock msg_;
};

class Init_CfgGNSSBlock_max_trk_ch
{
public:
  explicit Init_CfgGNSSBlock_max_trk_ch(::ublox_msgs::msg::CfgGNSSBlock & msg)
  : msg_(msg)
  {}
  Init_CfgGNSSBlock_reserved1 max_trk_ch(::ublox_msgs::msg::CfgGNSSBlock::_max_trk_ch_type arg)
  {
    msg_.max_trk_ch = std::move(arg);
    return Init_CfgGNSSBlock_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSSBlock msg_;
};

class Init_CfgGNSSBlock_res_trk_ch
{
public:
  explicit Init_CfgGNSSBlock_res_trk_ch(::ublox_msgs::msg::CfgGNSSBlock & msg)
  : msg_(msg)
  {}
  Init_CfgGNSSBlock_max_trk_ch res_trk_ch(::ublox_msgs::msg::CfgGNSSBlock::_res_trk_ch_type arg)
  {
    msg_.res_trk_ch = std::move(arg);
    return Init_CfgGNSSBlock_max_trk_ch(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSSBlock msg_;
};

class Init_CfgGNSSBlock_gnss_id
{
public:
  Init_CfgGNSSBlock_gnss_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgGNSSBlock_res_trk_ch gnss_id(::ublox_msgs::msg::CfgGNSSBlock::_gnss_id_type arg)
  {
    msg_.gnss_id = std::move(arg);
    return Init_CfgGNSSBlock_res_trk_ch(msg_);
  }

private:
  ::ublox_msgs::msg::CfgGNSSBlock msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgGNSSBlock>()
{
  return ublox_msgs::msg::builder::Init_CfgGNSSBlock_gnss_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_GNSS_BLOCK__BUILDER_HPP_
