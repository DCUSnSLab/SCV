// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/CfgNMEA.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/cfg_nmea__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_CfgNMEA_reserved1
{
public:
  explicit Init_CfgNMEA_reserved1(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::CfgNMEA reserved1(::ublox_msgs::msg::CfgNMEA::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_bds_talker_id
{
public:
  explicit Init_CfgNMEA_bds_talker_id(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_reserved1 bds_talker_id(::ublox_msgs::msg::CfgNMEA::_bds_talker_id_type arg)
  {
    msg_.bds_talker_id = std::move(arg);
    return Init_CfgNMEA_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_version
{
public:
  explicit Init_CfgNMEA_version(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_bds_talker_id version(::ublox_msgs::msg::CfgNMEA::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_CfgNMEA_bds_talker_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_gsv_talker_id
{
public:
  explicit Init_CfgNMEA_gsv_talker_id(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_version gsv_talker_id(::ublox_msgs::msg::CfgNMEA::_gsv_talker_id_type arg)
  {
    msg_.gsv_talker_id = std::move(arg);
    return Init_CfgNMEA_version(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_main_talker_id
{
public:
  explicit Init_CfgNMEA_main_talker_id(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_gsv_talker_id main_talker_id(::ublox_msgs::msg::CfgNMEA::_main_talker_id_type arg)
  {
    msg_.main_talker_id = std::move(arg);
    return Init_CfgNMEA_gsv_talker_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_sv_numbering
{
public:
  explicit Init_CfgNMEA_sv_numbering(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_main_talker_id sv_numbering(::ublox_msgs::msg::CfgNMEA::_sv_numbering_type arg)
  {
    msg_.sv_numbering = std::move(arg);
    return Init_CfgNMEA_main_talker_id(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_gnss_to_filter
{
public:
  explicit Init_CfgNMEA_gnss_to_filter(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_sv_numbering gnss_to_filter(::ublox_msgs::msg::CfgNMEA::_gnss_to_filter_type arg)
  {
    msg_.gnss_to_filter = std::move(arg);
    return Init_CfgNMEA_sv_numbering(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_flags
{
public:
  explicit Init_CfgNMEA_flags(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_gnss_to_filter flags(::ublox_msgs::msg::CfgNMEA::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_CfgNMEA_gnss_to_filter(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_num_sv
{
public:
  explicit Init_CfgNMEA_num_sv(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_flags num_sv(::ublox_msgs::msg::CfgNMEA::_num_sv_type arg)
  {
    msg_.num_sv = std::move(arg);
    return Init_CfgNMEA_flags(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_nmea_version
{
public:
  explicit Init_CfgNMEA_nmea_version(::ublox_msgs::msg::CfgNMEA & msg)
  : msg_(msg)
  {}
  Init_CfgNMEA_num_sv nmea_version(::ublox_msgs::msg::CfgNMEA::_nmea_version_type arg)
  {
    msg_.nmea_version = std::move(arg);
    return Init_CfgNMEA_num_sv(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

class Init_CfgNMEA_filter
{
public:
  Init_CfgNMEA_filter()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CfgNMEA_nmea_version filter(::ublox_msgs::msg::CfgNMEA::_filter_type arg)
  {
    msg_.filter = std::move(arg);
    return Init_CfgNMEA_nmea_version(msg_);
  }

private:
  ::ublox_msgs::msg::CfgNMEA msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::CfgNMEA>()
{
  return ublox_msgs::msg::builder::Init_CfgNMEA_filter();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_NMEA__BUILDER_HPP_
