// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ublox_msgs:msg/CfgINF.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__CFG_INF__FUNCTIONS_H_
#define UBLOX_MSGS__MSG__DETAIL__CFG_INF__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ublox_msgs/msg/detail/cfg_inf__struct.h"

/// Initialize msg/CfgINF message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ublox_msgs__msg__CfgINF
 * )) before or use
 * ublox_msgs__msg__CfgINF__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__init(ublox_msgs__msg__CfgINF * msg);

/// Finalize msg/CfgINF message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__CfgINF__fini(ublox_msgs__msg__CfgINF * msg);

/// Create msg/CfgINF message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ublox_msgs__msg__CfgINF__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__CfgINF *
ublox_msgs__msg__CfgINF__create();

/// Destroy msg/CfgINF message.
/**
 * It calls
 * ublox_msgs__msg__CfgINF__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__CfgINF__destroy(ublox_msgs__msg__CfgINF * msg);

/// Check for msg/CfgINF message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__are_equal(const ublox_msgs__msg__CfgINF * lhs, const ublox_msgs__msg__CfgINF * rhs);

/// Copy a msg/CfgINF message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__copy(
  const ublox_msgs__msg__CfgINF * input,
  ublox_msgs__msg__CfgINF * output);

/// Initialize array of msg/CfgINF messages.
/**
 * It allocates the memory for the number of elements and calls
 * ublox_msgs__msg__CfgINF__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__Sequence__init(ublox_msgs__msg__CfgINF__Sequence * array, size_t size);

/// Finalize array of msg/CfgINF messages.
/**
 * It calls
 * ublox_msgs__msg__CfgINF__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__CfgINF__Sequence__fini(ublox_msgs__msg__CfgINF__Sequence * array);

/// Create array of msg/CfgINF messages.
/**
 * It allocates the memory for the array and calls
 * ublox_msgs__msg__CfgINF__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__CfgINF__Sequence *
ublox_msgs__msg__CfgINF__Sequence__create(size_t size);

/// Destroy array of msg/CfgINF messages.
/**
 * It calls
 * ublox_msgs__msg__CfgINF__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__CfgINF__Sequence__destroy(ublox_msgs__msg__CfgINF__Sequence * array);

/// Check for msg/CfgINF message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__Sequence__are_equal(const ublox_msgs__msg__CfgINF__Sequence * lhs, const ublox_msgs__msg__CfgINF__Sequence * rhs);

/// Copy an array of msg/CfgINF messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__CfgINF__Sequence__copy(
  const ublox_msgs__msg__CfgINF__Sequence * input,
  ublox_msgs__msg__CfgINF__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__CFG_INF__FUNCTIONS_H_
