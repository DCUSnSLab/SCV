#include "fault.hpp"

#include <stdexcept>
#include <string>

namespace sensor_dummy
{

FaultMode parse_fault_mode(const std::string & name)
{
  if (name == "none") {
    return FaultMode::None;
  }
  if (name == "dropout") {
    return FaultMode::Dropout;
  }
  if (name == "latency") {
    return FaultMode::Latency;
  }
  if (name == "nan") {
    return FaultMode::Nan;
  }
  if (name == "freeze") {
    return FaultMode::Freeze;
  }
  throw std::invalid_argument("unknown fault mode: " + name);
}

}  // namespace sensor_dummy
