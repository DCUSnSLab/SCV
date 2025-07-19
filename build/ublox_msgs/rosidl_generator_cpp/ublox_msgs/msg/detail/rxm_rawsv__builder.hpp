// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmRAWSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_rawsv__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmRAWSV_lli
{
public:
  explicit Init_RxmRAWSV_lli(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmRAWSV lli(::ublox_msgs::msg::RxmRAWSV::_lli_type arg)
  {
    msg_.lli = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_cno
{
public:
  explicit Init_RxmRAWSV_cno(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  Init_RxmRAWSV_lli cno(::ublox_msgs::msg::RxmRAWSV::_cno_type arg)
  {
    msg_.cno = std::move(arg);
    return Init_RxmRAWSV_lli(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_mes_qi
{
public:
  explicit Init_RxmRAWSV_mes_qi(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  Init_RxmRAWSV_cno mes_qi(::ublox_msgs::msg::RxmRAWSV::_mes_qi_type arg)
  {
    msg_.mes_qi = std::move(arg);
    return Init_RxmRAWSV_cno(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_sv
{
public:
  explicit Init_RxmRAWSV_sv(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  Init_RxmRAWSV_mes_qi sv(::ublox_msgs::msg::RxmRAWSV::_sv_type arg)
  {
    msg_.sv = std::move(arg);
    return Init_RxmRAWSV_mes_qi(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_do_mes
{
public:
  explicit Init_RxmRAWSV_do_mes(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  Init_RxmRAWSV_sv do_mes(::ublox_msgs::msg::RxmRAWSV::_do_mes_type arg)
  {
    msg_.do_mes = std::move(arg);
    return Init_RxmRAWSV_sv(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_pr_mes
{
public:
  explicit Init_RxmRAWSV_pr_mes(::ublox_msgs::msg::RxmRAWSV & msg)
  : msg_(msg)
  {}
  Init_RxmRAWSV_do_mes pr_mes(::ublox_msgs::msg::RxmRAWSV::_pr_mes_type arg)
  {
    msg_.pr_mes = std::move(arg);
    return Init_RxmRAWSV_do_mes(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

class Init_RxmRAWSV_cp_mes
{
public:
  Init_RxmRAWSV_cp_mes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmRAWSV_pr_mes cp_mes(::ublox_msgs::msg::RxmRAWSV::_cp_mes_type arg)
  {
    msg_.cp_mes = std::move(arg);
    return Init_RxmRAWSV_pr_mes(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWSV msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmRAWSV>()
{
  return ublox_msgs::msg::builder::Init_RxmRAWSV_cp_mes();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWSV__BUILDER_HPP_
