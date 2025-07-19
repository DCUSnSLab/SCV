// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from hunter_msgs:msg/HunterActuatorState.idl
// generated code does not contain a copyright notice

#ifndef HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_H_
#define HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/HunterActuatorState in the package hunter_msgs.
/**
  * define DRIVER_STATE_INPUT_VOLTAGE_LOW_MASK ((uint8_t)0x01)
  * define DRIVER_STATE_MOTOR_OVERHEAT_MASK ((uint8_t)0x02)
  * define DRIVER_STATE_DRIVER_OVERLOAD_MASK ((uint8_t)0x04)
  * define DRIVER_STATE_DRIVER_OVERHEAT_MASK ((uint8_t)0x08)
  * define DRIVER_STATE_SENSOR_FAULT_MASK ((uint8_t)0x10)
  * define DRIVER_STATE_DRIVER_FAULT_MASK ((uint8_t)0x20)
  * define DRIVER_STATE_DRIVER_ENABLED_MASK ((uint8_t)0x40)
  * define DRIVER_STATE_DRIVER_RESET_MASK ((uint8_t)0x80)
 */
typedef struct hunter_msgs__msg__HunterActuatorState
{
  uint8_t motor_id;
  int16_t rpm;
  double current;
  int32_t pulse_count;
  float driver_voltage;
  float driver_temperature;
  int8_t motor_temperature;
  uint8_t driver_state;
} hunter_msgs__msg__HunterActuatorState;

// Struct for a sequence of hunter_msgs__msg__HunterActuatorState.
typedef struct hunter_msgs__msg__HunterActuatorState__Sequence
{
  hunter_msgs__msg__HunterActuatorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} hunter_msgs__msg__HunterActuatorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // HUNTER_MSGS__MSG__DETAIL__HUNTER_ACTUATOR_STATE__STRUCT_H_
