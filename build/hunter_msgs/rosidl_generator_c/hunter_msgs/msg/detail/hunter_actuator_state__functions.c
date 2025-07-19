// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hunter_msgs:msg/HunterActuatorState.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_actuator_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hunter_msgs__msg__HunterActuatorState__init(hunter_msgs__msg__HunterActuatorState * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // rpm
  // current
  // pulse_count
  // driver_voltage
  // driver_temperature
  // motor_temperature
  // driver_state
  return true;
}

void
hunter_msgs__msg__HunterActuatorState__fini(hunter_msgs__msg__HunterActuatorState * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // rpm
  // current
  // pulse_count
  // driver_voltage
  // driver_temperature
  // motor_temperature
  // driver_state
}

bool
hunter_msgs__msg__HunterActuatorState__are_equal(const hunter_msgs__msg__HunterActuatorState * lhs, const hunter_msgs__msg__HunterActuatorState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_id
  if (lhs->motor_id != rhs->motor_id) {
    return false;
  }
  // rpm
  if (lhs->rpm != rhs->rpm) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // pulse_count
  if (lhs->pulse_count != rhs->pulse_count) {
    return false;
  }
  // driver_voltage
  if (lhs->driver_voltage != rhs->driver_voltage) {
    return false;
  }
  // driver_temperature
  if (lhs->driver_temperature != rhs->driver_temperature) {
    return false;
  }
  // motor_temperature
  if (lhs->motor_temperature != rhs->motor_temperature) {
    return false;
  }
  // driver_state
  if (lhs->driver_state != rhs->driver_state) {
    return false;
  }
  return true;
}

bool
hunter_msgs__msg__HunterActuatorState__copy(
  const hunter_msgs__msg__HunterActuatorState * input,
  hunter_msgs__msg__HunterActuatorState * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // rpm
  output->rpm = input->rpm;
  // current
  output->current = input->current;
  // pulse_count
  output->pulse_count = input->pulse_count;
  // driver_voltage
  output->driver_voltage = input->driver_voltage;
  // driver_temperature
  output->driver_temperature = input->driver_temperature;
  // motor_temperature
  output->motor_temperature = input->motor_temperature;
  // driver_state
  output->driver_state = input->driver_state;
  return true;
}

hunter_msgs__msg__HunterActuatorState *
hunter_msgs__msg__HunterActuatorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterActuatorState * msg = (hunter_msgs__msg__HunterActuatorState *)allocator.allocate(sizeof(hunter_msgs__msg__HunterActuatorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hunter_msgs__msg__HunterActuatorState));
  bool success = hunter_msgs__msg__HunterActuatorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hunter_msgs__msg__HunterActuatorState__destroy(hunter_msgs__msg__HunterActuatorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hunter_msgs__msg__HunterActuatorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hunter_msgs__msg__HunterActuatorState__Sequence__init(hunter_msgs__msg__HunterActuatorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterActuatorState * data = NULL;

  if (size) {
    data = (hunter_msgs__msg__HunterActuatorState *)allocator.zero_allocate(size, sizeof(hunter_msgs__msg__HunterActuatorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hunter_msgs__msg__HunterActuatorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hunter_msgs__msg__HunterActuatorState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
hunter_msgs__msg__HunterActuatorState__Sequence__fini(hunter_msgs__msg__HunterActuatorState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      hunter_msgs__msg__HunterActuatorState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

hunter_msgs__msg__HunterActuatorState__Sequence *
hunter_msgs__msg__HunterActuatorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterActuatorState__Sequence * array = (hunter_msgs__msg__HunterActuatorState__Sequence *)allocator.allocate(sizeof(hunter_msgs__msg__HunterActuatorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hunter_msgs__msg__HunterActuatorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hunter_msgs__msg__HunterActuatorState__Sequence__destroy(hunter_msgs__msg__HunterActuatorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hunter_msgs__msg__HunterActuatorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hunter_msgs__msg__HunterActuatorState__Sequence__are_equal(const hunter_msgs__msg__HunterActuatorState__Sequence * lhs, const hunter_msgs__msg__HunterActuatorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hunter_msgs__msg__HunterActuatorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hunter_msgs__msg__HunterActuatorState__Sequence__copy(
  const hunter_msgs__msg__HunterActuatorState__Sequence * input,
  hunter_msgs__msg__HunterActuatorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hunter_msgs__msg__HunterActuatorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hunter_msgs__msg__HunterActuatorState * data =
      (hunter_msgs__msg__HunterActuatorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hunter_msgs__msg__HunterActuatorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hunter_msgs__msg__HunterActuatorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hunter_msgs__msg__HunterActuatorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
