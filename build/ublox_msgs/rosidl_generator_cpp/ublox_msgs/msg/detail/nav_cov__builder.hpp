// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/NavCOV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_COV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__NAV_COV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/nav_cov__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_NavCOV_vel_cov_dd
{
public:
  explicit Init_NavCOV_vel_cov_dd(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::NavCOV vel_cov_dd(::ublox_msgs::msg::NavCOV::_vel_cov_dd_type arg)
  {
    msg_.vel_cov_dd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_ed
{
public:
  explicit Init_NavCOV_vel_cov_ed(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_dd vel_cov_ed(::ublox_msgs::msg::NavCOV::_vel_cov_ed_type arg)
  {
    msg_.vel_cov_ed = std::move(arg);
    return Init_NavCOV_vel_cov_dd(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_ee
{
public:
  explicit Init_NavCOV_vel_cov_ee(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_ed vel_cov_ee(::ublox_msgs::msg::NavCOV::_vel_cov_ee_type arg)
  {
    msg_.vel_cov_ee = std::move(arg);
    return Init_NavCOV_vel_cov_ed(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_nd
{
public:
  explicit Init_NavCOV_vel_cov_nd(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_ee vel_cov_nd(::ublox_msgs::msg::NavCOV::_vel_cov_nd_type arg)
  {
    msg_.vel_cov_nd = std::move(arg);
    return Init_NavCOV_vel_cov_ee(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_ne
{
public:
  explicit Init_NavCOV_vel_cov_ne(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_nd vel_cov_ne(::ublox_msgs::msg::NavCOV::_vel_cov_ne_type arg)
  {
    msg_.vel_cov_ne = std::move(arg);
    return Init_NavCOV_vel_cov_nd(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_nn
{
public:
  explicit Init_NavCOV_vel_cov_nn(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_ne vel_cov_nn(::ublox_msgs::msg::NavCOV::_vel_cov_nn_type arg)
  {
    msg_.vel_cov_nn = std::move(arg);
    return Init_NavCOV_vel_cov_ne(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_dd
{
public:
  explicit Init_NavCOV_pos_cov_dd(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_nn pos_cov_dd(::ublox_msgs::msg::NavCOV::_pos_cov_dd_type arg)
  {
    msg_.pos_cov_dd = std::move(arg);
    return Init_NavCOV_vel_cov_nn(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_ed
{
public:
  explicit Init_NavCOV_pos_cov_ed(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_dd pos_cov_ed(::ublox_msgs::msg::NavCOV::_pos_cov_ed_type arg)
  {
    msg_.pos_cov_ed = std::move(arg);
    return Init_NavCOV_pos_cov_dd(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_ee
{
public:
  explicit Init_NavCOV_pos_cov_ee(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_ed pos_cov_ee(::ublox_msgs::msg::NavCOV::_pos_cov_ee_type arg)
  {
    msg_.pos_cov_ee = std::move(arg);
    return Init_NavCOV_pos_cov_ed(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_nd
{
public:
  explicit Init_NavCOV_pos_cov_nd(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_ee pos_cov_nd(::ublox_msgs::msg::NavCOV::_pos_cov_nd_type arg)
  {
    msg_.pos_cov_nd = std::move(arg);
    return Init_NavCOV_pos_cov_ee(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_ne
{
public:
  explicit Init_NavCOV_pos_cov_ne(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_nd pos_cov_ne(::ublox_msgs::msg::NavCOV::_pos_cov_ne_type arg)
  {
    msg_.pos_cov_ne = std::move(arg);
    return Init_NavCOV_pos_cov_nd(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_nn
{
public:
  explicit Init_NavCOV_pos_cov_nn(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_ne pos_cov_nn(::ublox_msgs::msg::NavCOV::_pos_cov_nn_type arg)
  {
    msg_.pos_cov_nn = std::move(arg);
    return Init_NavCOV_pos_cov_ne(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_reserved_0
{
public:
  explicit Init_NavCOV_reserved_0(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_nn reserved_0(::ublox_msgs::msg::NavCOV::_reserved_0_type arg)
  {
    msg_.reserved_0 = std::move(arg);
    return Init_NavCOV_pos_cov_nn(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_vel_cov_valid
{
public:
  explicit Init_NavCOV_vel_cov_valid(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_reserved_0 vel_cov_valid(::ublox_msgs::msg::NavCOV::_vel_cov_valid_type arg)
  {
    msg_.vel_cov_valid = std::move(arg);
    return Init_NavCOV_reserved_0(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_pos_cov_valid
{
public:
  explicit Init_NavCOV_pos_cov_valid(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_vel_cov_valid pos_cov_valid(::ublox_msgs::msg::NavCOV::_pos_cov_valid_type arg)
  {
    msg_.pos_cov_valid = std::move(arg);
    return Init_NavCOV_vel_cov_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_version
{
public:
  explicit Init_NavCOV_version(::ublox_msgs::msg::NavCOV & msg)
  : msg_(msg)
  {}
  Init_NavCOV_pos_cov_valid version(::ublox_msgs::msg::NavCOV::_version_type arg)
  {
    msg_.version = std::move(arg);
    return Init_NavCOV_pos_cov_valid(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

class Init_NavCOV_i_tow
{
public:
  Init_NavCOV_i_tow()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NavCOV_version i_tow(::ublox_msgs::msg::NavCOV::_i_tow_type arg)
  {
    msg_.i_tow = std::move(arg);
    return Init_NavCOV_version(msg_);
  }

private:
  ::ublox_msgs::msg::NavCOV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::NavCOV>()
{
  return ublox_msgs::msg::builder::Init_NavCOV_i_tow();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_COV__BUILDER_HPP_
