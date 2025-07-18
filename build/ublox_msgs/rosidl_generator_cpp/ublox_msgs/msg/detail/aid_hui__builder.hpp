// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/AidHUI.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__AID_HUI__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__AID_HUI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/aid_hui__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_AidHUI_flags
{
public:
  explicit Init_AidHUI_flags(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::AidHUI flags(::ublox_msgs::msg::AidHUI::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_b3
{
public:
  explicit Init_AidHUI_klob_b3(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_flags klob_b3(::ublox_msgs::msg::AidHUI::_klob_b3_type arg)
  {
    msg_.klob_b3 = std::move(arg);
    return Init_AidHUI_flags(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_b2
{
public:
  explicit Init_AidHUI_klob_b2(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_b3 klob_b2(::ublox_msgs::msg::AidHUI::_klob_b2_type arg)
  {
    msg_.klob_b2 = std::move(arg);
    return Init_AidHUI_klob_b3(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_b1
{
public:
  explicit Init_AidHUI_klob_b1(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_b2 klob_b1(::ublox_msgs::msg::AidHUI::_klob_b1_type arg)
  {
    msg_.klob_b1 = std::move(arg);
    return Init_AidHUI_klob_b2(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_b0
{
public:
  explicit Init_AidHUI_klob_b0(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_b1 klob_b0(::ublox_msgs::msg::AidHUI::_klob_b0_type arg)
  {
    msg_.klob_b0 = std::move(arg);
    return Init_AidHUI_klob_b1(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_a3
{
public:
  explicit Init_AidHUI_klob_a3(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_b0 klob_a3(::ublox_msgs::msg::AidHUI::_klob_a3_type arg)
  {
    msg_.klob_a3 = std::move(arg);
    return Init_AidHUI_klob_b0(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_a2
{
public:
  explicit Init_AidHUI_klob_a2(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_a3 klob_a2(::ublox_msgs::msg::AidHUI::_klob_a2_type arg)
  {
    msg_.klob_a2 = std::move(arg);
    return Init_AidHUI_klob_a3(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_a1
{
public:
  explicit Init_AidHUI_klob_a1(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_a2 klob_a1(::ublox_msgs::msg::AidHUI::_klob_a1_type arg)
  {
    msg_.klob_a1 = std::move(arg);
    return Init_AidHUI_klob_a2(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_klob_a0
{
public:
  explicit Init_AidHUI_klob_a0(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_a1 klob_a0(::ublox_msgs::msg::AidHUI::_klob_a0_type arg)
  {
    msg_.klob_a0 = std::move(arg);
    return Init_AidHUI_klob_a1(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_spare
{
public:
  explicit Init_AidHUI_utc_spare(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_klob_a0 utc_spare(::ublox_msgs::msg::AidHUI::_utc_spare_type arg)
  {
    msg_.utc_spare = std::move(arg);
    return Init_AidHUI_klob_a0(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_lsf
{
public:
  explicit Init_AidHUI_utc_lsf(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_spare utc_lsf(::ublox_msgs::msg::AidHUI::_utc_lsf_type arg)
  {
    msg_.utc_lsf = std::move(arg);
    return Init_AidHUI_utc_spare(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_dn
{
public:
  explicit Init_AidHUI_utc_dn(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_lsf utc_dn(::ublox_msgs::msg::AidHUI::_utc_dn_type arg)
  {
    msg_.utc_dn = std::move(arg);
    return Init_AidHUI_utc_lsf(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_wnf
{
public:
  explicit Init_AidHUI_utc_wnf(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_dn utc_wnf(::ublox_msgs::msg::AidHUI::_utc_wnf_type arg)
  {
    msg_.utc_wnf = std::move(arg);
    return Init_AidHUI_utc_dn(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_ls
{
public:
  explicit Init_AidHUI_utc_ls(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_wnf utc_ls(::ublox_msgs::msg::AidHUI::_utc_ls_type arg)
  {
    msg_.utc_ls = std::move(arg);
    return Init_AidHUI_utc_wnf(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_wnt
{
public:
  explicit Init_AidHUI_utc_wnt(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_ls utc_wnt(::ublox_msgs::msg::AidHUI::_utc_wnt_type arg)
  {
    msg_.utc_wnt = std::move(arg);
    return Init_AidHUI_utc_ls(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_tow
{
public:
  explicit Init_AidHUI_utc_tow(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_wnt utc_tow(::ublox_msgs::msg::AidHUI::_utc_tow_type arg)
  {
    msg_.utc_tow = std::move(arg);
    return Init_AidHUI_utc_wnt(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_a1
{
public:
  explicit Init_AidHUI_utc_a1(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_tow utc_a1(::ublox_msgs::msg::AidHUI::_utc_a1_type arg)
  {
    msg_.utc_a1 = std::move(arg);
    return Init_AidHUI_utc_tow(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_utc_a0
{
public:
  explicit Init_AidHUI_utc_a0(::ublox_msgs::msg::AidHUI & msg)
  : msg_(msg)
  {}
  Init_AidHUI_utc_a1 utc_a0(::ublox_msgs::msg::AidHUI::_utc_a0_type arg)
  {
    msg_.utc_a0 = std::move(arg);
    return Init_AidHUI_utc_a1(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

class Init_AidHUI_health
{
public:
  Init_AidHUI_health()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AidHUI_utc_a0 health(::ublox_msgs::msg::AidHUI::_health_type arg)
  {
    msg_.health = std::move(arg);
    return Init_AidHUI_utc_a0(msg_);
  }

private:
  ::ublox_msgs::msg::AidHUI msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::AidHUI>()
{
  return ublox_msgs::msg::builder::Init_AidHUI_health();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__AID_HUI__BUILDER_HPP_
