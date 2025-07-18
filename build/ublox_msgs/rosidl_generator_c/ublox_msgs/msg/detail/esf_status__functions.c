// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/EsfSTATUS.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/esf_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `sens`
#include "ublox_msgs/msg/detail/esf_status_sens__functions.h"

bool
ublox_msgs__msg__EsfSTATUS__init(ublox_msgs__msg__EsfSTATUS * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // version
  // reserved1
  // fusion_mode
  // reserved2
  // num_sens
  // sens
  if (!ublox_msgs__msg__EsfSTATUSSens__Sequence__init(&msg->sens, 0)) {
    ublox_msgs__msg__EsfSTATUS__fini(msg);
    return false;
  }
  return true;
}

void
ublox_msgs__msg__EsfSTATUS__fini(ublox_msgs__msg__EsfSTATUS * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // version
  // reserved1
  // fusion_mode
  // reserved2
  // num_sens
  // sens
  ublox_msgs__msg__EsfSTATUSSens__Sequence__fini(&msg->sens);
}

bool
ublox_msgs__msg__EsfSTATUS__are_equal(const ublox_msgs__msg__EsfSTATUS * lhs, const ublox_msgs__msg__EsfSTATUS * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // fusion_mode
  if (lhs->fusion_mode != rhs->fusion_mode) {
    return false;
  }
  // reserved2
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved2[i] != rhs->reserved2[i]) {
      return false;
    }
  }
  // num_sens
  if (lhs->num_sens != rhs->num_sens) {
    return false;
  }
  // sens
  if (!ublox_msgs__msg__EsfSTATUSSens__Sequence__are_equal(
      &(lhs->sens), &(rhs->sens)))
  {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__EsfSTATUS__copy(
  const ublox_msgs__msg__EsfSTATUS * input,
  ublox_msgs__msg__EsfSTATUS * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // version
  output->version = input->version;
  // reserved1
  for (size_t i = 0; i < 7; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // fusion_mode
  output->fusion_mode = input->fusion_mode;
  // reserved2
  for (size_t i = 0; i < 2; ++i) {
    output->reserved2[i] = input->reserved2[i];
  }
  // num_sens
  output->num_sens = input->num_sens;
  // sens
  if (!ublox_msgs__msg__EsfSTATUSSens__Sequence__copy(
      &(input->sens), &(output->sens)))
  {
    return false;
  }
  return true;
}

ublox_msgs__msg__EsfSTATUS *
ublox_msgs__msg__EsfSTATUS__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUS * msg = (ublox_msgs__msg__EsfSTATUS *)allocator.allocate(sizeof(ublox_msgs__msg__EsfSTATUS), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__EsfSTATUS));
  bool success = ublox_msgs__msg__EsfSTATUS__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__EsfSTATUS__destroy(ublox_msgs__msg__EsfSTATUS * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__EsfSTATUS__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__EsfSTATUS__Sequence__init(ublox_msgs__msg__EsfSTATUS__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUS * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__EsfSTATUS *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__EsfSTATUS), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__EsfSTATUS__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__EsfSTATUS__fini(&data[i - 1]);
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
ublox_msgs__msg__EsfSTATUS__Sequence__fini(ublox_msgs__msg__EsfSTATUS__Sequence * array)
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
      ublox_msgs__msg__EsfSTATUS__fini(&array->data[i]);
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

ublox_msgs__msg__EsfSTATUS__Sequence *
ublox_msgs__msg__EsfSTATUS__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__EsfSTATUS__Sequence * array = (ublox_msgs__msg__EsfSTATUS__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__EsfSTATUS__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__EsfSTATUS__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__EsfSTATUS__Sequence__destroy(ublox_msgs__msg__EsfSTATUS__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__EsfSTATUS__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__EsfSTATUS__Sequence__are_equal(const ublox_msgs__msg__EsfSTATUS__Sequence * lhs, const ublox_msgs__msg__EsfSTATUS__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__EsfSTATUS__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__EsfSTATUS__Sequence__copy(
  const ublox_msgs__msg__EsfSTATUS__Sequence * input,
  ublox_msgs__msg__EsfSTATUS__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__EsfSTATUS);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__EsfSTATUS * data =
      (ublox_msgs__msg__EsfSTATUS *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__EsfSTATUS__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__EsfSTATUS__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__EsfSTATUS__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
