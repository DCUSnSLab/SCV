// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/MonVER.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/mon_ver__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `extension`
#include "ublox_msgs/msg/detail/mon_ver_extension__functions.h"

bool
ublox_msgs__msg__MonVER__init(ublox_msgs__msg__MonVER * msg)
{
  if (!msg) {
    return false;
  }
  // sw_version
  // hw_version
  // extension
  if (!ublox_msgs__msg__MonVERExtension__Sequence__init(&msg->extension, 0)) {
    ublox_msgs__msg__MonVER__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__MonVER__fini(ublox_msgs__msg__MonVER * msg)
{
  if (!msg) {
    return;
  }
  // sw_version
  // hw_version
  // extension
  ublox_msgs__msg__MonVERExtension__Sequence__fini(&msg->extension);
}

bool
ublox_msgs__msg__MonVER__are_equal(const ublox_msgs__msg__MonVER * lhs, const ublox_msgs__msg__MonVER * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sw_version
  for (size_t i = 0; i < 30; ++i) {
    if (lhs->sw_version[i] != rhs->sw_version[i]) {
      return false;
    }
  }
  // hw_version
  for (size_t i = 0; i < 10; ++i) {
    if (lhs->hw_version[i] != rhs->hw_version[i]) {
      return false;
    }
  }
  // extension
  if (!ublox_msgs__msg__MonVERExtension__Sequence__are_equal(
      &(lhs->extension), &(rhs->extension)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__MonVER__copy(
  const ublox_msgs__msg__MonVER * input,
  ublox_msgs__msg__MonVER * output)
{
  if (!input || !output) {
    return false;
  }
  // sw_version
  for (size_t i = 0; i < 30; ++i) {
    output->sw_version[i] = input->sw_version[i];
  }
  // hw_version
  for (size_t i = 0; i < 10; ++i) {
    output->hw_version[i] = input->hw_version[i];
  }
  // extension
  if (!ublox_msgs__msg__MonVERExtension__Sequence__copy(
      &(input->extension), &(output->extension)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__MonVER *
ublox_msgs__msg__MonVER__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonVER * msg = (ublox_msgs__msg__MonVER *)allocator.allocate(sizeof(ublox_msgs__msg__MonVER), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__MonVER));
  bool success = ublox_msgs__msg__MonVER__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__MonVER__destroy(ublox_msgs__msg__MonVER * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__MonVER__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__MonVER__Sequence__init(ublox_msgs__msg__MonVER__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonVER * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__MonVER *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__MonVER), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__MonVER__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__MonVER__fini(&data[i - 1]);
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
ublox_msgs__msg__MonVER__Sequence__fini(ublox_msgs__msg__MonVER__Sequence * array)
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
      ublox_msgs__msg__MonVER__fini(&array->data[i]);
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

ublox_msgs__msg__MonVER__Sequence *
ublox_msgs__msg__MonVER__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MonVER__Sequence * array = (ublox_msgs__msg__MonVER__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__MonVER__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__MonVER__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__MonVER__Sequence__destroy(ublox_msgs__msg__MonVER__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__MonVER__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__MonVER__Sequence__are_equal(const ublox_msgs__msg__MonVER__Sequence * lhs, const ublox_msgs__msg__MonVER__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__MonVER__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__MonVER__Sequence__copy(
  const ublox_msgs__msg__MonVER__Sequence * input,
  ublox_msgs__msg__MonVER__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__MonVER);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__MonVER * data =
      (ublox_msgs__msg__MonVER *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__MonVER__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__MonVER__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__MonVER__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
