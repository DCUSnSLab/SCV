// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/EsfMEAS.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/esf_meas__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
// Member `calib_t_tag`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ublox_msgs__msg__EsfMEAS__init(ublox_msgs__msg__EsfMEAS * msg)
{
  if (!msg) {
    return false;
  }
  // time_tag
  // flags
  // id
  // data
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->data, 0)) {
    ublox_msgs__msg__EsfMEAS__fini(msg);
    return false;
  }
  // calib_t_tag
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->calib_t_tag, 0)) {
    ublox_msgs__msg__EsfMEAS__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__EsfMEAS__fini(ublox_msgs__msg__EsfMEAS * msg)
{
  if (!msg) {
    return;
  }
  // time_tag
  // flags
  // id
  // data
  rosidl_runtime_c__uint32__Sequence__fini(&msg->data);
  // calib_t_tag
  rosidl_runtime_c__uint32__Sequence__fini(&msg->calib_t_tag);
}

bool
ublox_msgs__msg__EsfMEAS__are_equal(const ublox_msgs__msg__EsfMEAS * lhs, const ublox_msgs__msg__EsfMEAS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // time_tag
  if (lhs->time_tag != rhs->time_tag) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  // calib_t_tag
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->calib_t_tag), &(rhs->calib_t_tag)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__EsfMEAS__copy(
  const ublox_msgs__msg__EsfMEAS * input,
  ublox_msgs__msg__EsfMEAS * output)
{
  if (!input || !output) {
    return false;
  }
  // time_tag
  output->time_tag = input->time_tag;
  // flags
  output->flags = input->flags;
  // id
  output->id = input->id;
  // data
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  // calib_t_tag
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->calib_t_tag), &(output->calib_t_tag)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__EsfMEAS *
ublox_msgs__msg__EsfMEAS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfMEAS * msg = (ublox_msgs__msg__EsfMEAS *)allocator.allocate(sizeof(ublox_msgs__msg__EsfMEAS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__EsfMEAS));
  bool success = ublox_msgs__msg__EsfMEAS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__EsfMEAS__destroy(ublox_msgs__msg__EsfMEAS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__EsfMEAS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__EsfMEAS__Sequence__init(ublox_msgs__msg__EsfMEAS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfMEAS * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__EsfMEAS *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__EsfMEAS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__EsfMEAS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__EsfMEAS__fini(&data[i - 1]);
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
ublox_msgs__msg__EsfMEAS__Sequence__fini(ublox_msgs__msg__EsfMEAS__Sequence * array)
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
      ublox_msgs__msg__EsfMEAS__fini(&array->data[i]);
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

ublox_msgs__msg__EsfMEAS__Sequence *
ublox_msgs__msg__EsfMEAS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfMEAS__Sequence * array = (ublox_msgs__msg__EsfMEAS__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__EsfMEAS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__EsfMEAS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__EsfMEAS__Sequence__destroy(ublox_msgs__msg__EsfMEAS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__EsfMEAS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__EsfMEAS__Sequence__are_equal(const ublox_msgs__msg__EsfMEAS__Sequence * lhs, const ublox_msgs__msg__EsfMEAS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__EsfMEAS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__EsfMEAS__Sequence__copy(
  const ublox_msgs__msg__EsfMEAS__Sequence * input,
  ublox_msgs__msg__EsfMEAS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__EsfMEAS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__EsfMEAS * data =
      (ublox_msgs__msg__EsfMEAS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__EsfMEAS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__EsfMEAS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__EsfMEAS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
