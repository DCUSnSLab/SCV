// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from hunter_msgs:msg/HunterLightCmd.idl
// generated code does not contain a copyright notice
#include "hunter_msgs/msg/detail/hunter_light_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
hunter_msgs__msg__HunterLightCmd__init(hunter_msgs__msg__HunterLightCmd * msg)
{
  if (!msg) {
    return false;
  }
  // cmd_ctrl_allowed
  // front_mode
  // front_custom_value
  // rear_mode
  // rear_custom_value
  return true;
}

void
hunter_msgs__msg__HunterLightCmd__fini(hunter_msgs__msg__HunterLightCmd * msg)
{
  if (!msg) {
    return;
  }
  // cmd_ctrl_allowed
  // front_mode
  // front_custom_value
  // rear_mode
  // rear_custom_value
}

bool
hunter_msgs__msg__HunterLightCmd__are_equal(const hunter_msgs__msg__HunterLightCmd * lhs, const hunter_msgs__msg__HunterLightCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cmd_ctrl_allowed
  if (lhs->cmd_ctrl_allowed != rhs->cmd_ctrl_allowed) {
    return false;
  }
  // front_mode
  if (lhs->front_mode != rhs->front_mode) {
    return false;
  }
  // front_custom_value
  if (lhs->front_custom_value != rhs->front_custom_value) {
    return false;
  }
  // rear_mode
  if (lhs->rear_mode != rhs->rear_mode) {
    return false;
  }
  // rear_custom_value
  if (lhs->rear_custom_value != rhs->rear_custom_value) {
    return false;
  }
  return true;
}

bool
hunter_msgs__msg__HunterLightCmd__copy(
  const hunter_msgs__msg__HunterLightCmd * input,
  hunter_msgs__msg__HunterLightCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // cmd_ctrl_allowed
  output->cmd_ctrl_allowed = input->cmd_ctrl_allowed;
  // front_mode
  output->front_mode = input->front_mode;
  // front_custom_value
  output->front_custom_value = input->front_custom_value;
  // rear_mode
  output->rear_mode = input->rear_mode;
  // rear_custom_value
  output->rear_custom_value = input->rear_custom_value;
  return true;
}

hunter_msgs__msg__HunterLightCmd *
hunter_msgs__msg__HunterLightCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterLightCmd * msg = (hunter_msgs__msg__HunterLightCmd *)allocator.allocate(sizeof(hunter_msgs__msg__HunterLightCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(hunter_msgs__msg__HunterLightCmd));
  bool success = hunter_msgs__msg__HunterLightCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
hunter_msgs__msg__HunterLightCmd__destroy(hunter_msgs__msg__HunterLightCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    hunter_msgs__msg__HunterLightCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
hunter_msgs__msg__HunterLightCmd__Sequence__init(hunter_msgs__msg__HunterLightCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterLightCmd * data = NULL;

  if (size) {
    data = (hunter_msgs__msg__HunterLightCmd *)allocator.zero_allocate(size, sizeof(hunter_msgs__msg__HunterLightCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = hunter_msgs__msg__HunterLightCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        hunter_msgs__msg__HunterLightCmd__fini(&data[i - 1]);
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
hunter_msgs__msg__HunterLightCmd__Sequence__fini(hunter_msgs__msg__HunterLightCmd__Sequence * array)
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
      hunter_msgs__msg__HunterLightCmd__fini(&array->data[i]);
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

hunter_msgs__msg__HunterLightCmd__Sequence *
hunter_msgs__msg__HunterLightCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  hunter_msgs__msg__HunterLightCmd__Sequence * array = (hunter_msgs__msg__HunterLightCmd__Sequence *)allocator.allocate(sizeof(hunter_msgs__msg__HunterLightCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = hunter_msgs__msg__HunterLightCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
hunter_msgs__msg__HunterLightCmd__Sequence__destroy(hunter_msgs__msg__HunterLightCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    hunter_msgs__msg__HunterLightCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
hunter_msgs__msg__HunterLightCmd__Sequence__are_equal(const hunter_msgs__msg__HunterLightCmd__Sequence * lhs, const hunter_msgs__msg__HunterLightCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!hunter_msgs__msg__HunterLightCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
hunter_msgs__msg__HunterLightCmd__Sequence__copy(
  const hunter_msgs__msg__HunterLightCmd__Sequence * input,
  hunter_msgs__msg__HunterLightCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(hunter_msgs__msg__HunterLightCmd);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    hunter_msgs__msg__HunterLightCmd * data =
      (hunter_msgs__msg__HunterLightCmd *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!hunter_msgs__msg__HunterLightCmd__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          hunter_msgs__msg__HunterLightCmd__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!hunter_msgs__msg__HunterLightCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
