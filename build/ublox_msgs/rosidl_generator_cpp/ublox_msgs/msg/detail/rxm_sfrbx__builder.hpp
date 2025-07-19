// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmSFRBX.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_sfrbx__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmSFRBX_dwrd
{
public:
  explicit Init_RxmSFRBX_dwrd(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmSFRBX dwrd(::ublox_msgs::msg::RxmSFRBX::_dwrd_type arg)
  {
    msg_.dwrd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_reserved1
{
public:
  explicit Init_RxmSFRBX_reserved1(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_dwrd reserved1(::ublox_msgs::msg::RxmSFRBX::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return Init_RxmSFRBX_dwrd(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_version
{
public:
  explicit Init_RxmSFRBX_version(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_reserved1 version(::ublox_msgs::msg::RxmSFRBX::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_RxmSFRBX_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_chn
{
public:
  explicit Init_RxmSFRBX_chn(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_version chn(::ublox_msgs::msg::RxmSFRBX::_chn_type arg)
  {
    msg_.chn = std::move(arg);
    return Init_RxmSFRBX_version(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_num_words
{
public:
  explicit Init_RxmSFRBX_num_words(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_chn num_words(::ublox_msgs::msg::RxmSFRBX::_num_words_type arg)
  {
    msg_.num_words = std::move(arg);
    return Init_RxmSFRBX_chn(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_freq_id
{
public:
  explicit Init_RxmSFRBX_freq_id(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_num_words freq_id(::ublox_msgs::msg::RxmSFRBX::_freq_id_type arg)
  {
    msg_.freq_id = std::move(arg);
    return Init_RxmSFRBX_num_words(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_reserved0
{
public:
  explicit Init_RxmSFRBX_reserved0(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_freq_id reserved0(::ublox_msgs::msg::RxmSFRBX::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_RxmSFRBX_freq_id(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_sv_id
{
public:
  explicit Init_RxmSFRBX_sv_id(::ublox_msgs::msg::RxmSFRBX & msg)
  : msg_(msg)
  {}
  Init_RxmSFRBX_reserved0 sv_id(::ublox_msgs::msg::RxmSFRBX::_sv_id_type arg)
  {
    msg_.sv_id = std::move(arg);
    return Init_RxmSFRBX_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

class Init_RxmSFRBX_gnss_id
{
public:
  Init_RxmSFRBX_gnss_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmSFRBX_sv_id gnss_id(::ublox_msgs::msg::RxmSFRBX::_gnss_id_type arg)
  {
    msg_.gnss_id = std::move(arg);
    return Init_RxmSFRBX_sv_id(msg_);
  }

private:
  ::ublox_msgs::msg::RxmSFRBX msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmSFRBX>()
{
  return ublox_msgs::msg::builder::Init_RxmSFRBX_gnss_id();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_SFRBX__BUILDER_HPP_
