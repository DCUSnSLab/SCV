// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ublox_msgs:msg/MgaGAL.idl
// generated code does not contain a copyright notice
#include "ublox_msgs/msg/detail/mga_gal__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ublox_msgs__msg__MgaGAL__init(ublox_msgs__msg__MgaGAL * msg)
{
  if (!msg) {
    return false;
  }
  // type
  // version
  // svid
  // reserved0
  // iod_nav
  // delta_n
  // m0
  // e
  // sqrt_a
  // omega0
  // i0
  // omega
  // omega_dot
  // i_dot
  // cuc
  // cus
  // crc
  // crs
  // cic
  // cis
  // toe
  // af0
  // af1
  // af2
  // sisaindex_e1_e5b
  // toc
  // bgd_e1_e5b
  // reserved1
  // health_e1b
  // data_validity_e1b
  // health_e5b
  // data_validity_e5b
  // reserved2
  return true;
}

void
ublox_msgs__msg__MgaGAL__fini(ublox_msgs__msg__MgaGAL * msg)
{
  if (!msg) {
    return;
  }
  // type
  // version
  // svid
  // reserved0
  // iod_nav
  // delta_n
  // m0
  // e
  // sqrt_a
  // omega0
  // i0
  // omega
  // omega_dot
  // i_dot
  // cuc
  // cus
  // crc
  // crs
  // cic
  // cis
  // toe
  // af0
  // af1
  // af2
  // sisaindex_e1_e5b
  // toc
  // bgd_e1_e5b
  // reserved1
  // health_e1b
  // data_validity_e1b
  // health_e5b
  // data_validity_e5b
  // reserved2
}

bool
ublox_msgs__msg__MgaGAL__are_equal(const ublox_msgs__msg__MgaGAL * lhs, const ublox_msgs__msg__MgaGAL * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // version
  if (lhs->version != rhs->version) {
    return false;
  }
  // svid
  if (lhs->svid != rhs->svid) {
    return false;
  }
  // reserved0
  if (lhs->reserved0 != rhs->reserved0) {
    return false;
  }
  // iod_nav
  if (lhs->iod_nav != rhs->iod_nav) {
    return false;
  }
  // delta_n
  if (lhs->delta_n != rhs->delta_n) {
    return false;
  }
  // m0
  if (lhs->m0 != rhs->m0) {
    return false;
  }
  // e
  if (lhs->e != rhs->e) {
    return false;
  }
  // sqrt_a
  if (lhs->sqrt_a != rhs->sqrt_a) {
    return false;
  }
  // omega0
  if (lhs->omega0 != rhs->omega0) {
    return false;
  }
  // i0
  if (lhs->i0 != rhs->i0) {
    return false;
  }
  // omega
  if (lhs->omega != rhs->omega) {
    return false;
  }
  // omega_dot
  if (lhs->omega_dot != rhs->omega_dot) {
    return false;
  }
  // i_dot
  if (lhs->i_dot != rhs->i_dot) {
    return false;
  }
  // cuc
  if (lhs->cuc != rhs->cuc) {
    return false;
  }
  // cus
  if (lhs->cus != rhs->cus) {
    return false;
  }
  // crc
  if (lhs->crc != rhs->crc) {
    return false;
  }
  // crs
  if (lhs->crs != rhs->crs) {
    return false;
  }
  // cic
  if (lhs->cic != rhs->cic) {
    return false;
  }
  // cis
  if (lhs->cis != rhs->cis) {
    return false;
  }
  // toe
  if (lhs->toe != rhs->toe) {
    return false;
  }
  // af0
  if (lhs->af0 != rhs->af0) {
    return false;
  }
  // af1
  if (lhs->af1 != rhs->af1) {
    return false;
  }
  // af2
  if (lhs->af2 != rhs->af2) {
    return false;
  }
  // sisaindex_e1_e5b
  if (lhs->sisaindex_e1_e5b != rhs->sisaindex_e1_e5b) {
    return false;
  }
  // toc
  if (lhs->toc != rhs->toc) {
    return false;
  }
  // bgd_e1_e5b
  if (lhs->bgd_e1_e5b != rhs->bgd_e1_e5b) {
    return false;
  }
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->reserved1[i] != rhs->reserved1[i]) {
      return false;
    }
  }
  // health_e1b
  if (lhs->health_e1b != rhs->health_e1b) {
    return false;
  }
  // data_validity_e1b
  if (lhs->data_validity_e1b != rhs->data_validity_e1b) {
    return false;
  }
  // health_e5b
  if (lhs->health_e5b != rhs->health_e5b) {
    return false;
  }
  // data_validity_e5b
  if (lhs->data_validity_e5b != rhs->data_validity_e5b) {
    return false;
  }
  // reserved2
  for (size_t i = 0; i < 4; ++i) {
    if (lhs->reserved2[i] != rhs->reserved2[i]) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__MgaGAL__copy(
  const ublox_msgs__msg__MgaGAL * input,
  ublox_msgs__msg__MgaGAL * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // version
  output->version = input->version;
  // svid
  output->svid = input->svid;
  // reserved0
  output->reserved0 = input->reserved0;
  // iod_nav
  output->iod_nav = input->iod_nav;
  // delta_n
  output->delta_n = input->delta_n;
  // m0
  output->m0 = input->m0;
  // e
  output->e = input->e;
  // sqrt_a
  output->sqrt_a = input->sqrt_a;
  // omega0
  output->omega0 = input->omega0;
  // i0
  output->i0 = input->i0;
  // omega
  output->omega = input->omega;
  // omega_dot
  output->omega_dot = input->omega_dot;
  // i_dot
  output->i_dot = input->i_dot;
  // cuc
  output->cuc = input->cuc;
  // cus
  output->cus = input->cus;
  // crc
  output->crc = input->crc;
  // crs
  output->crs = input->crs;
  // cic
  output->cic = input->cic;
  // cis
  output->cis = input->cis;
  // toe
  output->toe = input->toe;
  // af0
  output->af0 = input->af0;
  // af1
  output->af1 = input->af1;
  // af2
  output->af2 = input->af2;
  // sisaindex_e1_e5b
  output->sisaindex_e1_e5b = input->sisaindex_e1_e5b;
  // toc
  output->toc = input->toc;
  // bgd_e1_e5b
  output->bgd_e1_e5b = input->bgd_e1_e5b;
  // reserved1
  for (size_t i = 0; i < 2; ++i) {
    output->reserved1[i] = input->reserved1[i];
  }
  // health_e1b
  output->health_e1b = input->health_e1b;
  // data_validity_e1b
  output->data_validity_e1b = input->data_validity_e1b;
  // health_e5b
  output->health_e5b = input->health_e5b;
  // data_validity_e5b
  output->data_validity_e5b = input->data_validity_e5b;
  // reserved2
  for (size_t i = 0; i < 4; ++i) {
    output->reserved2[i] = input->reserved2[i];
  }
  return true;
}

ublox_msgs__msg__MgaGAL *
ublox_msgs__msg__MgaGAL__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MgaGAL * msg = (ublox_msgs__msg__MgaGAL *)allocator.allocate(sizeof(ublox_msgs__msg__MgaGAL), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ublox_msgs__msg__MgaGAL));
  bool success = ublox_msgs__msg__MgaGAL__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ublox_msgs__msg__MgaGAL__destroy(ublox_msgs__msg__MgaGAL * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ublox_msgs__msg__MgaGAL__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ublox_msgs__msg__MgaGAL__Sequence__init(ublox_msgs__msg__MgaGAL__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MgaGAL * data = NULL;

  if (size) {
    data = (ublox_msgs__msg__MgaGAL *)allocator.zero_allocate(size, sizeof(ublox_msgs__msg__MgaGAL), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ublox_msgs__msg__MgaGAL__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ublox_msgs__msg__MgaGAL__fini(&data[i - 1]);
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
ublox_msgs__msg__MgaGAL__Sequence__fini(ublox_msgs__msg__MgaGAL__Sequence * array)
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
      ublox_msgs__msg__MgaGAL__fini(&array->data[i]);
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

ublox_msgs__msg__MgaGAL__Sequence *
ublox_msgs__msg__MgaGAL__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ublox_msgs__msg__MgaGAL__Sequence * array = (ublox_msgs__msg__MgaGAL__Sequence *)allocator.allocate(sizeof(ublox_msgs__msg__MgaGAL__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ublox_msgs__msg__MgaGAL__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ublox_msgs__msg__MgaGAL__Sequence__destroy(ublox_msgs__msg__MgaGAL__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ublox_msgs__msg__MgaGAL__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ublox_msgs__msg__MgaGAL__Sequence__are_equal(const ublox_msgs__msg__MgaGAL__Sequence * lhs, const ublox_msgs__msg__MgaGAL__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ublox_msgs__msg__MgaGAL__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ublox_msgs__msg__MgaGAL__Sequence__copy(
  const ublox_msgs__msg__MgaGAL__Sequence * input,
  ublox_msgs__msg__MgaGAL__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ublox_msgs__msg__MgaGAL);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ublox_msgs__msg__MgaGAL * data =
      (ublox_msgs__msg__MgaGAL *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ublox_msgs__msg__MgaGAL__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ublox_msgs__msg__MgaGAL__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ublox_msgs__msg__MgaGAL__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
