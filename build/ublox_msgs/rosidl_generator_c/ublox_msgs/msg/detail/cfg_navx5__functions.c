// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/CfgNAVX5.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/cfg_navx5__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__CfgNAVX5__init(ublox_msgs__msg__CfgNAVX5 * msg)
{
  if (!msg) {
    return false;
  }
  // version
  // mask1
  // mask2
  // reserved1
  // min_svs
  // max_svs
  // min_cno
  // reserved2
  // ini_fix3d
  // reserved3
  // ack_aiding
  // wkn_rollover
  // sig_atten_comp_mode
  // reserved4
  // use_ppp
  // aop_cfg
  // reserved5
  // aop_orb_max_err
  // reserved6
  // use_adr
  return true;
}

void
ublox_msgs__msg__CfgNAVX5__fini(ublox_msgs__msg__CfgNAVX5 * msg)
{
  if (!msg) {
    return;
  }
  // version
  // mask1
  // mask2
  // reserved1
  // min_svs
  // max_svs
  // min_cno
  // reserved2
  // ini_fix3d
  // reserved3
  // ack_aiding
  // wkn_rollover
  // sig_atten_comp_mode
  // reserved4
  // use_ppp
  // aop_cfg
  // reserved5
  // aop_orb_max_err
  // reserved6
  // use_adr
}

bool
ublox_msgs__msg__CfgNAVX5__are_equal(const ublox_msgs__msg__CfgNAVX5 * lhs, const ublox_msgs__msg__CfgNAVX5 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // mask1
  if (lhs->mask1 != rhs->mask1) {
    return false;
  }
  // mask2
  if (lhs->mask2 != rhs->mask2) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // min_svs
  if (lhs->min_svs != rhs->min_svs) {
    return false;
  }
  // max_svs
  if (lhs->max_svs != rhs->max_svs) {
    return false;
  }
  // min_cno
  if (lhs->min_cno != rhs->min_cno) {
    return false;
  }
  // reserved2
  if (lhs->reserved2 != rhs->reserved2) {
    return false;
  }
  // ini_fix3d
  if (lhs->ini_fix3d != rhs->ini_fix3d) {
    return false;
  }
  // reserved3
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved3[i] != rhs->reserved3[i]) {
      return false;
    }
  }
  // ack_aiding
  if (lhs->ack_aiding != rhs->ack_aiding) {
    return false;
  }
  // wkn_rollover
  if (lhs->wkn_rollover != rhs->wkn_rollover) {
    return false;
  }
  // sig_atten_comp_mode
  if (lhs->sig_atten_comp_mode != rhs->sig_atten_comp_mode) {
    return false;
  }
  // reserved4
  for (size_t i = 0; i < 5; ++i) {
    if (lhs->reserved4[i] != rhs->reserved4[i]) {
      return false;
    }
  }
  // use_ppp
  if (lhs->use_ppp != rhs->use_ppp) {
    return false;
  }
  // aop_cfg
  if (lhs->aop_cfg != rhs->aop_cfg) {
    return false;
  }
  // reserved5
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved5[i] != rhs->reserved5[i]) {
      return false;
    }
  }
  // aop_orb_max_err
  if (lhs->aop_orb_max_err != rhs->aop_orb_max_err) {
    return false;
  }
  // reserved6
  for (size_t i = 0; i < 7; ++i) {
    if (lhs->reserved6[i] != rhs->reserved6[i]) {
      return false;
    }
  }
  // use_adr
  if (lhs->use_adr != rhs->use_adr) {
    return false;
  }
  return true;
}

bool
ublox_msgs__msg__CfgNAVX5__copy(
  const ublox_msgs__msg__CfgNAVX5 * input,
  ublox_msgs__msg__CfgNAVX5 * output)
{
  if (!input || !output) {
    return false;
  }
  // version
  output->version = input->version;
  // mask1
  output->mask1 = input->mask1;
  // mask2
  output->mask2 = input->mask2;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // min_svs
  output->min_svs = input->min_svs;
  // max_svs
  output->max_svs = input->max_svs;
  // min_cno
  output->min_cno = input->min_cno;
  // reserved2
  output->reserved2 = input->reserved2;
  // ini_fix3d
  output->ini_fix3d = input->ini_fix3d;
  // reserved3
  for (size_t i = 0; i < 2; ++i) {
    output->reserved3[i] = input->reserved3[i];
  }
  // ack_aiding
  output->ack_aiding = input->ack_aiding;
  // wkn_rollover
  output->wkn_rollover = input->wkn_rollover;
  // sig_atten_comp_mode
  output->sig_atten_comp_mode = input->sig_atten_comp_mode;
  // reserved4
  for (size_t i = 0; i < 5; ++i) {
    output->reserved4[i] = input->reserved4[i];
  }
  // use_ppp
  output->use_ppp = input->use_ppp;
  // aop_cfg
  output->aop_cfg = input->aop_cfg;
  // reserved5
  for (size_t i = 0; i < 2; ++i) {
    output->reserved5[i] = input->reserved5[i];
  }
  // aop_orb_max_err
  output->aop_orb_max_err = input->aop_orb_max_err;
  // reserved6
  for (size_t i = 0; i < 7; ++i) {
    output->reserved6[i] = input->reserved6[i];
  }
  // use_adr
  output->use_adr = input->use_adr;
  return true;
}

ublox_msgs__msg__CfgNAVX5 *
ublox_msgs__msg__CfgNAVX5__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAVX5 * msg = (ublox_msgs__msg__CfgNAVX5 *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNAVX5), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__CfgNAVX5));
  bool success = ublox_msgs__msg__CfgNAVX5__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__CfgNAVX5__destroy(ublox_msgs__msg__CfgNAVX5 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__CfgNAVX5__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__CfgNAVX5__Sequence__init(ublox_msgs__msg__CfgNAVX5__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAVX5 * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__CfgNAVX5 *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__CfgNAVX5), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__CfgNAVX5__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__CfgNAVX5__fini(&data[i - 1]);
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
ublox_msgs__msg__CfgNAVX5__Sequence__fini(ublox_msgs__msg__CfgNAVX5__Sequence * array)
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
      ublox_msgs__msg__CfgNAVX5__fini(&array->data[i]);
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

ublox_msgs__msg__CfgNAVX5__Sequence *
ublox_msgs__msg__CfgNAVX5__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__CfgNAVX5__Sequence * array = (ublox_msgs__msg__CfgNAVX5__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__CfgNAVX5__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__CfgNAVX5__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__CfgNAVX5__Sequence__destroy(ublox_msgs__msg__CfgNAVX5__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__CfgNAVX5__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__CfgNAVX5__Sequence__are_equal(const ublox_msgs__msg__CfgNAVX5__Sequence * lhs, const ublox_msgs__msg__CfgNAVX5__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__CfgNAVX5__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__CfgNAVX5__Sequence__copy(
  const ublox_msgs__msg__CfgNAVX5__Sequence * input,
  ublox_msgs__msg__CfgNAVX5__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__CfgNAVX5);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__CfgNAVX5 * data =
      (ublox_msgs__msg__CfgNAVX5 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__CfgNAVX5__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__CfgNAVX5__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__CfgNAVX5__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
