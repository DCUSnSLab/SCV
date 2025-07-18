// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgNAV5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_nav5__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgNAV5__init(ublox_msgs__msg__CfgNAV5 * msg)
{
  if (!msg) {
    return false;
  }
  // mask
  // dyn_model
  // fix_mode
  // fixed_alt
  // fixed_alt_var
  // min_elev
  // dr_limit
  // p_dop
  // t_dop
  // p_acc
  // t_acc
  // static_hold_thresh
  // dgnss_time_out
  // cno_thresh_num_svs
  // cno_thresh
  // reserved1
  // static_hold_max_dist
  // utc_standard
  // reserved2
  return true;
}

void
ublox_msgs__msg__CfgNAV5__fini(ublox_msgs__msg__CfgNAV5 * msg)
{
  if (!msg) {
    return;
  }
  // mask
  // dyn_model
  // fix_mode
  // fixed_alt
  // fixed_alt_var
  // min_elev
  // dr_limit
  // p_dop
  // t_dop
  // p_acc
  // t_acc
  // static_hold_thresh
  // dgnss_time_out
  // cno_thresh_num_svs
  // cno_thresh
  // reserved1
  // static_hold_max_dist
  // utc_standard
  // reserved2
}

bool
ublox_msgs__msg__CfgNAV5__are_equal(const ublox_msgs__msg__CfgNAV5 * lhs, const ublox_msgs__msg__CfgNAV5 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mask
  if (lhs->mask != rhs->mask) {
    return false;
  }
  // dyn_model
  if (lhs->dyn_model != rhs->dyn_model) {
    return false;
  }
  // fix_mode
  if (lhs->fix_mode != rhs->fix_mode) {
    return false;
  }
  // fixed_alt
  if (lhs->fixed_alt != rhs->fixed_alt) {
    return false;
  }
  // fixed_alt_var
  if (lhs->fixed_alt_var != rhs->fixed_alt_var) {
    return false;
  }
  // min_elev
  if (lhs->min_elev != rhs->min_elev) {
    return false;
  }
  // dr_limit
  if (lhs->dr_limit != rhs->dr_limit) {
    return false;
  }
  // p_dop
  if (lhs->p_dop != rhs->p_dop) {
    return false;
  }
  // t_dop
  if (lhs->t_dop != rhs->t_dop) {
    return false;
  }
  // p_acc
  if (lhs->p_acc != rhs->p_acc) {
    return false;
  }
  // t_acc
  if (lhs->t_acc != rhs->t_acc) {
    return false;
  }
  // static_hold_thresh
  if (lhs->static_hold_thresh != rhs->static_hold_thresh) {
    return false;
  }
  // dgnss_time_out
  if (lhs->dgnss_time_out != rhs->dgnss_time_out) {
    return false;
  }
  // cno_thresh_num_svs
  if (lhs->cno_thresh_num_svs != rhs->cno_thresh_num_svs) {
    return false;
  }
  // cno_thresh
  if (lhs->cno_thresh != rhs->cno_thresh) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // static_hold_max_dist
  if (lhs->static_hold_max_dist != rhs->static_hold_max_dist) {
    return false;
  }
  // utc_standard
  if (lhs->utc_standard != rhs->utc_standard) {
    return false;
  }
  // reserved2
  for (size_t i = 0; i < 5; ++i) {
    if (lhs->reserved2[i] != rhs->reserved2[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgNAV5__copy(
  const ublox_msgs__msg__CfgNAV5 * input,
  ublox_msgs__msg__CfgNAV5 * output)
{
  if (!input || !output) {
    return false;
  }
  // mask
  output->mask = input->mask;
  // dyn_model
  output->dyn_model = input->dyn_model;
  // fix_mode
  output->fix_mode = input->fix_mode;
  // fixed_alt
  output->fixed_alt = input->fixed_alt;
  // fixed_alt_var
  output->fixed_alt_var = input->fixed_alt_var;
  // min_elev
  output->min_elev = input->min_elev;
  // dr_limit
  output->dr_limit = input->dr_limit;
  // p_dop
  output->p_dop = input->p_dop;
  // t_dop
  output->t_dop = input->t_dop;
  // p_acc
  output->p_acc = input->p_acc;
  // t_acc
  output->t_acc = input->t_acc;
  // static_hold_thresh
  output->static_hold_thresh = input->static_hold_thresh;
  // dgnss_time_out
  output->dgnss_time_out = input->dgnss_time_out;
  // cno_thresh_num_svs
  output->cno_thresh_num_svs = input->cno_thresh_num_svs;
  // cno_thresh
  output->cno_thresh = input->cno_thresh;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // static_hold_max_dist
  output->static_hold_max_dist = input->static_hold_max_dist;
  // utc_standard
  output->utc_standard = input->utc_standard;
  // reserved2
  for (size_t i = 0; i < 5; ++i) {
    output->reserved2[i] = input->reserved2[i];
  }
  return true;
}

ublox_msgs__msg__CfgNAV5 *
ublox_msgs__msg__CfgNAV5__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAV5 * msg = (ublox_msgs__msg__CfgNAV5 *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNAV5), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgNAV5));
  bool success = ublox_msgs__msg__CfgNAV5__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgNAV5__destroy(ublox_msgs__msg__CfgNAV5 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgNAV5__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgNAV5__Sequence__init(ublox_msgs__msg__CfgNAV5__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAV5 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgNAV5 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgNAV5), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgNAV5__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgNAV5__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgNAV5__Sequence__fini(ublox_msgs__msg__CfgNAV5__Sequence * array)
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
      ublox_msgs__msg__CfgNAV5__fini(&array->data[i]);
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

ublox_msgs__msg__CfgNAV5__Sequence *
ublox_msgs__msg__CfgNAV5__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAV5__Sequence * array = (ublox_msgs__msg__CfgNAV5__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNAV5__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgNAV5__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgNAV5__Sequence__destroy(ublox_msgs__msg__CfgNAV5__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgNAV5__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgNAV5__Sequence__are_equal(const ublox_msgs__msg__CfgNAV5__Sequence * lhs, const ublox_msgs__msg__CfgNAV5__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgNAV5__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgNAV5__Sequence__copy(
  const ublox_msgs__msg__CfgNAV5__Sequence * input,
  ublox_msgs__msg__CfgNAV5__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgNAV5);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgNAV5 * data =
      (ublox_msgs__msg__CfgNAV5 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgNAV5__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgNAV5__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgNAV5__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
