// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hunter_msgs:msg/HunterStatus.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `actuator_states`
#include "hunter_msgs/msg/detail/hunter_actuator_state__functions.h"

bool
hunter_msgs__msg__HunterStatus__init(hunter_msgs__msg__HunterStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    hunter_msgs__msg__HunterStatus__fini(msg);
    return false;
  }
  // linear_velocity
  // steering_angle
  // vehicle_state
  // control_mode
  // error_code
  // battery_voltage
  // actuator_states
  for (size_t i = 0; i < 3; ++i) {
    if (!hunter_msgs__msg__HunterActuatorState__init(&msg->actuator_states[i])) {
      hunter_msgs__msg__HunterStatus__fini(msg);
      return false;
    }
  }
  return true;
}

void
hunter_msgs__msg__HunterStatus__fini(hunter_msgs__msg__HunterStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // linear_velocity
  // steering_angle
  // vehicle_state
  // control_mode
  // error_code
  // battery_voltage
  // actuator_states
  for (size_t i = 0; i < 3; ++i) {
    hunter_msgs__msg__HunterActuatorState__fini(&msg->actuator_states[i]);
  }
}

bool
hunter_msgs__msg__HunterStatus__are_equal(const hunter_msgs__msg__HunterStatus * lhs, const hunter_msgs__msg__HunterStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // linear_velocity
  if (lhs->linear_velocity != rhs->linear_velocity) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  // vehicle_state
  if (lhs->vehicle_state != rhs->vehicle_state) {
    return false;
  }
  // control_mode
  if (lhs->control_mode != rhs->control_mode) {
    return false;
  }
  // error_code
  if (lhs->error_code != rhs->error_code) {
    return false;
  }
  // battery_voltage
  if (lhs->battery_voltage != rhs->battery_voltage) {
    return false;
  }
  // actuator_states
  for (size_t i = 0; i < 3; ++i) {
    if (!hunter_msgs__msg__HunterActuatorState__are_equal(
        &(lhs->actuator_states[i]), &(rhs->actuator_states[i])))
    {
      return false;
    }
  }
  return true;
}

bool
hunter_msgs__msg__HunterStatus__copy(
  const hunter_msgs__msg__HunterStatus * input,
  hunter_msgs__msg__HunterStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // linear_velocity
  output->linear_velocity = input->linear_velocity;
  // steering_angle
  output->steering_angle = input->steering_angle;
  // vehicle_state
  output->vehicle_state = input->vehicle_state;
  // control_mode
  output->control_mode = input->control_mode;
  // error_code
  output->error_code = input->error_code;
  // battery_voltage
  output->battery_voltage = input->battery_voltage;
  // actuator_states
  for (size_t i = 0; i < 3; ++i) {
    if (!hunter_msgs__msg__HunterActuatorState__copy(
        &(input->actuator_states[i]), &(output->actuator_states[i])))
    {
      return false;
    }
  }
  return true;
}

hunter_msgs__msg__HunterStatus *
hunter_msgs__msg__HunterStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterStatus * msg = (hunter_msgs__msg__HunterStatus *)allocator.allocate(sizeof(hunter_msgs__msg__HunterStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hunter_msgs__msg__HunterStatus));
  bool success = hunter_msgs__msg__HunterStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hunter_msgs__msg__HunterStatus__destroy(hunter_msgs__msg__HunterStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hunter_msgs__msg__HunterStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hunter_msgs__msg__HunterStatus__Sequence__init(hunter_msgs__msg__HunterStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterStatus * data = NULL;

  if (size) {
    data = (hunter_msgs__msg__HunterStatus *)allocator.zero_allocate(size, sizeof(hunter_msgs__msg__HunterStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hunter_msgs__msg__HunterStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hunter_msgs__msg__HunterStatus__fini(&data[i - 1]);
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
hunter_msgs__msg__HunterStatus__Sequence__fini(hunter_msgs__msg__HunterStatus__Sequence * array)
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
      hunter_msgs__msg__HunterStatus__fini(&array->data[i]);
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

hunter_msgs__msg__HunterStatus__Sequence *
hunter_msgs__msg__HunterStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterStatus__Sequence * array = (hunter_msgs__msg__HunterStatus__Sequence *)allocator.allocate(sizeof(hunter_msgs__msg__HunterStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hunter_msgs__msg__HunterStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hunter_msgs__msg__HunterStatus__Sequence__destroy(hunter_msgs__msg__HunterStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hunter_msgs__msg__HunterStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hunter_msgs__msg__HunterStatus__Sequence__are_equal(const hunter_msgs__msg__HunterStatus__Sequence * lhs, const hunter_msgs__msg__HunterStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hunter_msgs__msg__HunterStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hunter_msgs__msg__HunterStatus__Sequence__copy(
  const hunter_msgs__msg__HunterStatus__Sequence * input,
  hunter_msgs__msg__HunterStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hunter_msgs__msg__HunterStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hunter_msgs__msg__HunterStatus * data =
      (hunter_msgs__msg__HunterStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hunter_msgs__msg__HunterStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hunter_msgs__msg__HunterStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hunter_msgs__msg__HunterStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
