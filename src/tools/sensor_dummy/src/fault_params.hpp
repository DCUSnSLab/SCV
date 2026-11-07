#ifndef FAULT_PARAMS_HPP_
#define FAULT_PARAMS_HPP_

#include "fault.hpp"

#include <rclcpp/rclcpp.hpp>

#include <string>

namespace sensor_dummy
{

inline FaultSpec declare_fault(rclcpp::Node & node, const std::string & prefix)
{
  return {
    parse_fault_mode(node.declare_parameter<std::string>(prefix + ".mode")),
    node.declare_parameter<double>(prefix + ".latency_s")};
}

// Returns false when the name is not under prefix. Throws on an unknown mode name.
inline bool update_fault(FaultSpec & spec, const std::string & prefix, const rclcpp::Parameter & p)
{
  if (p.get_name() == prefix + ".mode") {
    spec.mode = parse_fault_mode(p.as_string());
    return true;
  }
  if (p.get_name() == prefix + ".latency_s") {
    spec.latency_s = p.as_double();
    return true;
  }
  return false;
}

}  // namespace sensor_dummy

#endif  // FAULT_PARAMS_HPP_
