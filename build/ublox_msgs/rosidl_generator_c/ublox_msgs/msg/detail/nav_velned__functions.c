// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/NavVELNED.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/nav_velned__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__NavVELNED__init(ublox_msgs__msg__NavVELNED * msg)
{
  if (!msg) {
    return false;
  }
  // i_tow
  // vel_n
  // vel_e
  // vel_d
  // speed
  // g_speed
  // heading
  // s_acc
  // c_acc
  return true;
}

void
ublox_msgs__msg__NavVELNED__fini(ublox_msgs__msg__NavVELNED * msg)
{
  if (!msg) {
    return;
  }
  // i_tow
  // vel_n
  // vel_e
  // vel_d
  // speed
  // g_speed
  // heading
  // s_acc
  // c_acc
}

bool
ublox_msgs__msg__NavVELNED__are_equal(const ublox_msgs__msg__NavVELNED * lhs, const ublox_msgs__msg__NavVELNED * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // i_tow
  if (lhs->i_tow != rhs->i_tow) {
    return false;
  }
  // vel_n
  if (lhs->vel_n != rhs->vel_n) {
    return false;
  }
  // vel_e
  if (lhs->vel_e != rhs->vel_e) {
    return false;
  }
  // vel_d
  if (lhs->vel_d != rhs->vel_d) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // g_speed
  if (lhs->g_speed != rhs->g_speed) {
    return false;
  }
  // heading
  if (lhs->heading != rhs->heading) {
    return false;
  }
  // s_acc
  if (lhs->s_acc != rhs->s_acc) {
    return false;
  }
  // c_acc
  if (lhs->c_acc != rhs->c_acc) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__NavVELNED__copy(
  const ublox_msgs__msg__NavVELNED * input,
  ublox_msgs__msg__NavVELNED * output)
{
  if (!input || !output) {
    return false;
  }
  // i_tow
  output->i_tow = input->i_tow;
  // vel_n
  output->vel_n = input->vel_n;
  // vel_e
  output->vel_e = input->vel_e;
  // vel_d
  output->vel_d = input->vel_d;
  // speed
  output->speed = input->speed;
  // g_speed
  output->g_speed = input->g_speed;
  // heading
  output->heading = input->heading;
  // s_acc
  output->s_acc = input->s_acc;
  // c_acc
  output->c_acc = input->c_acc;
  return true;
}

ublox_msgs__msg__NavVELNED *
ublox_msgs__msg__NavVELNED__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavVELNED * msg = (ublox_msgs__msg__NavVELNED *)allocator.allocate(sizeof(ublox_msgs__msg__NavVELNED), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__NavVELNED));
  bool success = ublox_msgs__msg__NavVELNED__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__NavVELNED__destroy(ublox_msgs__msg__NavVELNED * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__NavVELNED__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__NavVELNED__Sequence__init(ublox_msgs__msg__NavVELNED__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavVELNED * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__NavVELNED *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__NavVELNED), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__NavVELNED__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__NavVELNED__fini(&data[i - 1]);
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
ublox_msgs__msg__NavVELNED__Sequence__fini(ublox_msgs__msg__NavVELNED__Sequence * array)
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
      ublox_msgs__msg__NavVELNED__fini(&array->data[i]);
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

ublox_msgs__msg__NavVELNED__Sequence *
ublox_msgs__msg__NavVELNED__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__NavVELNED__Sequence * array = (ublox_msgs__msg__NavVELNED__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__NavVELNED__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__NavVELNED__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__NavVELNED__Sequence__destroy(ublox_msgs__msg__NavVELNED__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__NavVELNED__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__NavVELNED__Sequence__are_equal(const ublox_msgs__msg__NavVELNED__Sequence * lhs, const ublox_msgs__msg__NavVELNED__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__NavVELNED__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__NavVELNED__Sequence__copy(
  const ublox_msgs__msg__NavVELNED__Sequence * input,
  ublox_msgs__msg__NavVELNED__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__NavVELNED);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__NavVELNED * data =
      (ublox_msgs__msg__NavVELNED *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__NavVELNED__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__NavVELNED__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__NavVELNED__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
