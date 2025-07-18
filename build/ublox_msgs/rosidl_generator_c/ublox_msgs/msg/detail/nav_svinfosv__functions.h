// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
// generated code does not contain a copyright notice

#ifndef UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__FUNCTIONS_H_
#define UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "ublox_msgs/msg/detail/nav_svinfosv__struct.h"

/// Initialize msg/NavSVINFOSV message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * ublox_msgs__msg__NavSVINFOSV
 * )) before or use
 * ublox_msgs__msg__NavSVINFOSV__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavSVINFOSV__init(ublox_msgs__msg__NavSVINFOSV * msg);

/// Finalize msg/NavSVINFOSV message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavSVINFOSV__fini(ublox_msgs__msg__NavSVINFOSV * msg);

/// Create msg/NavSVINFOSV message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * ublox_msgs__msg__NavSVINFOSV__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__NavSVINFOSV *
ublox_msgs__msg__NavSVINFOSV__create();

/// Destroy msg/NavSVINFOSV message.
/**
 * It calls
 * ublox_msgs__msg__NavSVINFOSV__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavSVINFOSV__destroy(ublox_msgs__msg__NavSVINFOSV * msg);

/// Check for msg/NavSVINFOSV message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavSVINFOSV__are_equal(const ublox_msgs__msg__NavSVINFOSV * lhs, const ublox_msgs__msg__NavSVINFOSV * rhs);

/// Copy a msg/NavSVINFOSV message.
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
ublox_msgs__msg__NavSVINFOSV__copy(
  const ublox_msgs__msg__NavSVINFOSV * input,
  ublox_msgs__msg__NavSVINFOSV * output);

/// Initialize array of msg/NavSVINFOSV messages.
/**
 * It allocates the memory for the number of elements and calls
 * ublox_msgs__msg__NavSVINFOSV__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavSVINFOSV__Sequence__init(ublox_msgs__msg__NavSVINFOSV__Sequence * array, size_t size);

/// Finalize array of msg/NavSVINFOSV messages.
/**
 * It calls
 * ublox_msgs__msg__NavSVINFOSV__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavSVINFOSV__Sequence__fini(ublox_msgs__msg__NavSVINFOSV__Sequence * array);

/// Create array of msg/NavSVINFOSV messages.
/**
 * It allocates the memory for the array and calls
 * ublox_msgs__msg__NavSVINFOSV__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
ublox_msgs__msg__NavSVINFOSV__Sequence *
ublox_msgs__msg__NavSVINFOSV__Sequence__create(size_t size);

/// Destroy array of msg/NavSVINFOSV messages.
/**
 * It calls
 * ublox_msgs__msg__NavSVINFOSV__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
void
ublox_msgs__msg__NavSVINFOSV__Sequence__destroy(ublox_msgs__msg__NavSVINFOSV__Sequence * array);

/// Check for msg/NavSVINFOSV message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_ublox_msgs
bool
ublox_msgs__msg__NavSVINFOSV__Sequence__are_equal(const ublox_msgs__msg__NavSVINFOSV__Sequence * lhs, const ublox_msgs__msg__NavSVINFOSV__Sequence * rhs);

/// Copy an array of msg/NavSVINFOSV messages.
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
ublox_msgs__msg__NavSVINFOSV__Sequence__copy(
  const ublox_msgs__msg__NavSVINFOSV__Sequence * input,
  ublox_msgs__msg__NavSVINFOSV__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UBLOX_MSGS__MSG__DETAIL__NAV_SVINFOSV__FUNCTIONS_H_
