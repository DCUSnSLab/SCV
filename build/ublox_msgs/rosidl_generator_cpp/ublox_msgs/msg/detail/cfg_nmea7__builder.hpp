// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgNMEA7.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_nmea7__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgNMEA7_reserved
{
public:
  explicit Init_CfgNMEA7_reserved(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgNMEA7 reserved(::ublox_msgs::msg::CfgNMEA7::_reserved_type arg)
  {
    msg_.reserved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_gsv_talker_id
{
public:
  explicit Init_CfgNMEA7_gsv_talker_id(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_reserved gsv_talker_id(::ublox_msgs::msg::CfgNMEA7::_gsv_talker_id_type arg)
  {
    msg_.gsv_talker_id = std::move(arg);
    return Init_CfgNMEA7_reserved(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_main_talker_id
{
public:
  explicit Init_CfgNMEA7_main_talker_id(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_gsv_talker_id main_talker_id(::ublox_msgs::msg::CfgNMEA7::_main_talker_id_type arg)
  {
    msg_.main_talker_id = std::move(arg);
    return Init_CfgNMEA7_gsv_talker_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_sv_numbering
{
public:
  explicit Init_CfgNMEA7_sv_numbering(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_main_talker_id sv_numbering(::ublox_msgs::msg::CfgNMEA7::_sv_numbering_type arg)
  {
    msg_.sv_numbering = std::move(arg);
    return Init_CfgNMEA7_main_talker_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_gnss_to_filter
{
public:
  explicit Init_CfgNMEA7_gnss_to_filter(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_sv_numbering gnss_to_filter(::ublox_msgs::msg::CfgNMEA7::_gnss_to_filter_type arg)
  {
    msg_.gnss_to_filter = std::move(arg);
    return Init_CfgNMEA7_sv_numbering(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_flags
{
public:
  explicit Init_CfgNMEA7_flags(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_gnss_to_filter flags(::ublox_msgs::msg::CfgNMEA7::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgNMEA7_gnss_to_filter(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_num_sv
{
public:
  explicit Init_CfgNMEA7_num_sv(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_flags num_sv(::ublox_msgs::msg::CfgNMEA7::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_CfgNMEA7_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_nmea_version
{
public:
  explicit Init_CfgNMEA7_nmea_version(::ublox_msgs::msg::CfgNMEA7 & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA7_num_sv nmea_version(::ublox_msgs::msg::CfgNMEA7::_nmea_version_type arg)
  {
    msg_.nmea_version = std::move(arg);
    return Init_CfgNMEA7_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

class Init_CfgNMEA7_filter
{
public:
  Init_CfgNMEA7_filter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgNMEA7_nmea_version filter(::ublox_msgs::msg::CfgNMEA7::_filter_type arg)
  {
    msg_.filter = std::move(arg);
    return Init_CfgNMEA7_nmea_version(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA7 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgNMEA7>()
{
  return ublox_msgs::msg::builder::Init_CfgNMEA7_filter();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA7__BUILDER_HPP_
