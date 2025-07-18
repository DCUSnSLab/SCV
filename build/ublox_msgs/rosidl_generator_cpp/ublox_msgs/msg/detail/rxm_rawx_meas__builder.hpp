// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__BUILDER_HPP_
#define UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ublox_msgs/msg/detail/rxm_rawx_meas__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ublox_msgs
{

namespace msg
{

namespace builder
{

class Init_RxmRAWXMeas_reserved1
{
public:
  explicit Init_RxmRAWXMeas_reserved1(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  ::ublox_msgs::msg::RxmRAWXMeas reserved1(::ublox_msgs::msg::RxmRAWXMeas::_reserved1_type arg)
  {
    msg_.reserved1 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_trk_stat
{
public:
  explicit Init_RxmRAWXMeas_trk_stat(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_reserved1 trk_stat(::ublox_msgs::msg::RxmRAWXMeas::_trk_stat_type arg)
  {
    msg_.trk_stat = std::move(arg);
    return Init_RxmRAWXMeas_reserved1(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_do_stdev
{
public:
  explicit Init_RxmRAWXMeas_do_stdev(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_trk_stat do_stdev(::ublox_msgs::msg::RxmRAWXMeas::_do_stdev_type arg)
  {
    msg_.do_stdev = std::move(arg);
    return Init_RxmRAWXMeas_trk_stat(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_cp_stdev
{
public:
  explicit Init_RxmRAWXMeas_cp_stdev(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_do_stdev cp_stdev(::ublox_msgs::msg::RxmRAWXMeas::_cp_stdev_type arg)
  {
    msg_.cp_stdev = std::move(arg);
    return Init_RxmRAWXMeas_do_stdev(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_pr_stdev
{
public:
  explicit Init_RxmRAWXMeas_pr_stdev(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_cp_stdev pr_stdev(::ublox_msgs::msg::RxmRAWXMeas::_pr_stdev_type arg)
  {
    msg_.pr_stdev = std::move(arg);
    return Init_RxmRAWXMeas_cp_stdev(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_cno
{
public:
  explicit Init_RxmRAWXMeas_cno(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_pr_stdev cno(::ublox_msgs::msg::RxmRAWXMeas::_cno_type arg)
  {
    msg_.cno = std::move(arg);
    return Init_RxmRAWXMeas_pr_stdev(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_locktime
{
public:
  explicit Init_RxmRAWXMeas_locktime(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_cno locktime(::ublox_msgs::msg::RxmRAWXMeas::_locktime_type arg)
  {
    msg_.locktime = std::move(arg);
    return Init_RxmRAWXMeas_cno(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_freq_id
{
public:
  explicit Init_RxmRAWXMeas_freq_id(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_locktime freq_id(::ublox_msgs::msg::RxmRAWXMeas::_freq_id_type arg)
  {
    msg_.freq_id = std::move(arg);
    return Init_RxmRAWXMeas_locktime(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_reserved0
{
public:
  explicit Init_RxmRAWXMeas_reserved0(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_freq_id reserved0(::ublox_msgs::msg::RxmRAWXMeas::_reserved0_type arg)
  {
    msg_.reserved0 = std::move(arg);
    return Init_RxmRAWXMeas_freq_id(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_sv_id
{
public:
  explicit Init_RxmRAWXMeas_sv_id(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_reserved0 sv_id(::ublox_msgs::msg::RxmRAWXMeas::_sv_id_type arg)
  {
    msg_.sv_id = std::move(arg);
    return Init_RxmRAWXMeas_reserved0(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_gnss_id
{
public:
  explicit Init_RxmRAWXMeas_gnss_id(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_sv_id gnss_id(::ublox_msgs::msg::RxmRAWXMeas::_gnss_id_type arg)
  {
    msg_.gnss_id = std::move(arg);
    return Init_RxmRAWXMeas_sv_id(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_do_mes
{
public:
  explicit Init_RxmRAWXMeas_do_mes(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_gnss_id do_mes(::ublox_msgs::msg::RxmRAWXMeas::_do_mes_type arg)
  {
    msg_.do_mes = std::move(arg);
    return Init_RxmRAWXMeas_gnss_id(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_cp_mes
{
public:
  explicit Init_RxmRAWXMeas_cp_mes(::ublox_msgs::msg::RxmRAWXMeas & msg)
  : msg_(msg)
  {}
  Init_RxmRAWXMeas_do_mes cp_mes(::ublox_msgs::msg::RxmRAWXMeas::_cp_mes_type arg)
  {
    msg_.cp_mes = std::move(arg);
    return Init_RxmRAWXMeas_do_mes(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

class Init_RxmRAWXMeas_pr_mes
{
public:
  Init_RxmRAWXMeas_pr_mes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RxmRAWXMeas_cp_mes pr_mes(::ublox_msgs::msg::RxmRAWXMeas::_pr_mes_type arg)
  {
    msg_.pr_mes = std::move(arg);
    return Init_RxmRAWXMeas_cp_mes(msg_);
  }

private:
  ::ublox_msgs::msg::RxmRAWXMeas msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ublox_msgs::msg::RxmRAWXMeas>()
{
  return ublox_msgs::msg::builder::Init_RxmRAWXMeas_pr_mes();
}

}  // namespace ublox_msgs

#endif  // UBLOX_MSGS__MSG__DETAIL__RXM_RAWX_MEAS__BUILDER_HPP_
