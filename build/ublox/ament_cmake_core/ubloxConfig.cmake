# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ublox_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ublox_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ublox_FOUND FALSE)
  elseif(NOT ublox_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ublox_FOUND FALSE)
  endif()
  return()
endif()
set(_ublox_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ublox_FIND_QUIETLY)
  message(STATUS "Found ublox: 2.3.0 (${ublox_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ublox' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ublox_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ublox_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ublox_DIR}/${_extra}")
endforeach()
