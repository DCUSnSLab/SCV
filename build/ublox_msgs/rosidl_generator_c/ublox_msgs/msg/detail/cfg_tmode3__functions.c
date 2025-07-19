// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgTMODE3.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_tmode3__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgTMODE3__init(ublox_msgs__msg__CfgTMODE3 * msg)
{
  if (!msg) {
    return false;
  }
  // version
  // reserved1
  // flags
  // ecef_x_or_lat
  // ecef_y_or_lon
  // ecef_z_or_alt
  // ecef_x_or_lat_hp
  // ecef_y_or_lon_hp
  // ecef_z_or_alt_hp
  // reserved2
  // fixed_pos_acc
  // svin_min_dur
  // svin_acc_limit
  // reserved3
  return true;
}

void
ublox_msgs__msg__CfgTMODE3__fini(ublox_msgs__msg__CfgTMODE3 * msg)
{
  if (!msg) {
    return;
  }
  // version
  // reserved1
  // flags
  // ecef_x_or_lat
  // ecef_y_or_lon
  // ecef_z_or_alt
  // ecef_x_or_lat_hp
  // ecef_y_or_lon_hp
  // ecef_z_or_alt_hp
  // reserved2
  // fixed_pos_acc
  // svin_min_dur
  // svin_acc_limit
  // reserved3
}

bool
ublox_msgs__msg__CfgTMODE3__are_equal(const ublox_msgs__msg__CfgTMODE3 * lhs, const ublox_msgs__msg__CfgTMODE3 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // reserved1
  if (lhs->reserved1 != rhs->reserved1) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  // ecef_x_or_lat
  if (lhs->ecef_x_or_lat != rhs->ecef_x_or_lat) {
    return false;
  }
  // ecef_y_or_lon
  if (lhs->ecef_y_or_lon != rhs->ecef_y_or_lon) {
    return false;
  }
  // ecef_z_or_alt
  if (lhs->ecef_z_or_alt != rhs->ecef_z_or_alt) {
    return false;
  }
  // ecef_x_or_lat_hp
  if (lhs->ecef_x_or_lat_hp != rhs->ecef_x_or_lat_hp) {
    return false;
  }
  // ecef_y_or_lon_hp
  if (lhs->ecef_y_or_lon_hp != rhs->ecef_y_or_lon_hp) {
    return false;
  }
  // ecef_z_or_alt_hp
  if (lhs->ecef_z_or_alt_hp != rhs->ecef_z_or_alt_hp) {
    return false;
  }
  // reserved2
  if (lhs->reserved2 != rhs->reserved2) {
    return false;
  }
  // fixed_pos_acc
  if (lhs->fixed_pos_acc != rhs->fixed_pos_acc) {
    return false;
  }
  // svin_min_dur
  if (lhs->svin_min_dur != rhs->svin_min_dur) {
    return false;
  }
  // svin_acc_limit
  if (lhs->svin_acc_limit != rhs->svin_acc_limit) {
    return false;
  }
  // reserved3
  for (size_t i = 0; i < 8; ++i) {
    if (lhs->reserved3[i] != rhs->reserved3[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgTMODE3__copy(
  const ublox_msgs__msg__CfgTMODE3 * input,
  ublox_msgs__msg__CfgTMODE3 * output)
{
  if (!input || !output) {
    return false;
  }
  // version
  output->version = input->version;
  // reserved1
  output->reserved1 = input->reserved1;
  // flags
  output->flags = input->flags;
  // ecef_x_or_lat
  output->ecef_x_or_lat = input->ecef_x_or_lat;
  // ecef_y_or_lon
  output->ecef_y_or_lon = input->ecef_y_or_lon;
  // ecef_z_or_alt
  output->ecef_z_or_alt = input->ecef_z_or_alt;
  // ecef_x_or_lat_hp
  output->ecef_x_or_lat_hp = input->ecef_x_or_lat_hp;
  // ecef_y_or_lon_hp
  output->ecef_y_or_lon_hp = input->ecef_y_or_lon_hp;
  // ecef_z_or_alt_hp
  output->ecef_z_or_alt_hp = input->ecef_z_or_alt_hp;
  // reserved2
  output->reserved2 = input->reserved2;
  // fixed_pos_acc
  output->fixed_pos_acc = input->fixed_pos_acc;
  // svin_min_dur
  output->svin_min_dur = input->svin_min_dur;
  // svin_acc_limit
  output->svin_acc_limit = input->svin_acc_limit;
  // reserved3
  for (size_t i = 0; i < 8; ++i) {
    output->reserved3[i] = input->reserved3[i];
  }
  return true;
}

ublox_msgs__msg__CfgTMODE3 *
ublox_msgs__msg__CfgTMODE3__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgTMODE3 * msg = (ublox_msgs__msg__CfgTMODE3 *)allocator.allocate(sizeof(ublox_msgs__msg__CfgTMODE3), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgTMODE3));
  bool success = ublox_msgs__msg__CfgTMODE3__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgTMODE3__destroy(ublox_msgs__msg__CfgTMODE3 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgTMODE3__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgTMODE3__Sequence__init(ublox_msgs__msg__CfgTMODE3__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgTMODE3 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgTMODE3 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgTMODE3), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgTMODE3__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgTMODE3__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgTMODE3__Sequence__fini(ublox_msgs__msg__CfgTMODE3__Sequence * array)
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
      ublox_msgs__msg__CfgTMODE3__fini(&array->data[i]);
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

ublox_msgs__msg__CfgTMODE3__Sequence *
ublox_msgs__msg__CfgTMODE3__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgTMODE3__Sequence * array = (ublox_msgs__msg__CfgTMODE3__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgTMODE3__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgTMODE3__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgTMODE3__Sequence__destroy(ublox_msgs__msg__CfgTMODE3__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgTMODE3__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgTMODE3__Sequence__are_equal(const ublox_msgs__msg__CfgTMODE3__Sequence * lhs, const ublox_msgs__msg__CfgTMODE3__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgTMODE3__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgTMODE3__Sequence__copy(
  const ublox_msgs__msg__CfgTMODE3__Sequence * input,
  ublox_msgs__msg__CfgTMODE3__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgTMODE3);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgTMODE3 * data =
      (ublox_msgs__msg__CfgTMODE3 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgTMODE3__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgTMODE3__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgTMODE3__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
