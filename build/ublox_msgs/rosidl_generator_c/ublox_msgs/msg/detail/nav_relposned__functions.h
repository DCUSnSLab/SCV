// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ublox_msgs:msg/NavRELPOSNED.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__FUNCTIONS_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ublox_msgs/msg/detail/nav_relposned__struct.h"

/// Initialize msg/NavRELPOSNED message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ublox_msgs__msg__NavRELPOSNED
 * )) before or use
 * ublox_msgs__msg__NavRELPOSNED__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavRELPOSNED__init(ublox_msgs__msg__NavRELPOSNED * msg);

/// Finalize msg/NavRELPOSNED message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavRELPOSNED__fini(ublox_msgs__msg__NavRELPOSNED * msg);

/// Create msg/NavRELPOSNED message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ublox_msgs__msg__NavRELPOSNED__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__NavRELPOSNED *
ublox_msgs__msg__NavRELPOSNED__create();

/// Destroy msg/NavRELPOSNED message.
/**
 * It calls
 * ublox_msgs__msg__NavRELPOSNED__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavRELPOSNED__destroy(ublox_msgs__msg__NavRELPOSNED * msg);

/// Check for msg/NavRELPOSNED message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavRELPOSNED__are_equal(const ublox_msgs__msg__NavRELPOSNED * lhs, const ublox_msgs__msg__NavRELPOSNED * rhs);

/// Copy a msg/NavRELPOSNED message.
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
ublox_msgs__msg__NavRELPOSNED__copy(
  const ublox_msgs__msg__NavRELPOSNED * input,
  ublox_msgs__msg__NavRELPOSNED * output);

/// Initialize array of msg/NavRELPOSNED messages.
/**
 * It allocates the memory for the number of elements and calls
 * ublox_msgs__msg__NavRELPOSNED__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavRELPOSNED__Sequence__init(ublox_msgs__msg__NavRELPOSNED__Sequence * array, size_t size);

/// Finalize array of msg/NavRELPOSNED messages.
/**
 * It calls
 * ublox_msgs__msg__NavRELPOSNED__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavRELPOSNED__Sequence__fini(ublox_msgs__msg__NavRELPOSNED__Sequence * array);

/// Create array of msg/NavRELPOSNED messages.
/**
 * It allocates the memory for the array and calls
 * ublox_msgs__msg__NavRELPOSNED__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__NavRELPOSNED__Sequence *
ublox_msgs__msg__NavRELPOSNED__Sequence__create(size_t size);

/// Destroy array of msg/NavRELPOSNED messages.
/**
 * It calls
 * ublox_msgs__msg__NavRELPOSNED__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavRELPOSNED__Sequence__destroy(ublox_msgs__msg__NavRELPOSNED__Sequence * array);

/// Check for msg/NavRELPOSNED message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavRELPOSNED__Sequence__are_equal(const ublox_msgs__msg__NavRELPOSNED__Sequence * lhs, const ublox_msgs__msg__NavRELPOSNED__Sequence * rhs);

/// Copy an array of msg/NavRELPOSNED messages.
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
ublox_msgs__msg__NavRELPOSNED__Sequence__copy(
  const ublox_msgs__msg__NavRELPOSNED__Sequence * input,
  ublox_msgs__msg__NavRELPOSNED__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_RELPOSNED__FUNCTIONS_H_
