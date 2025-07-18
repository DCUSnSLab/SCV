// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgRATE.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ublox_msgs/msg/detail/cfg_rate__struct.h"
#include "ublox_msgs/msg/detail/cfg_rate__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_rate__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[33];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ublox_msgs.msg._cfg_rate.CfgRATE", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__CfgRATE * ros_message = _ros_message;
  {  // meas_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "meas_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->meas_rate = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // nav_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "nav_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nav_rate = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // time_ref
    PyObject * field = PyObject_GetAttrString(_pymsg, "time_ref");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->time_ref = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_rate__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgRATE */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_rate");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgRATE");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgRATE * ros_message = (ublox_msgs__msg__CfgRATE *)raw_ros_message;
  {  // meas_rate
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->meas_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "meas_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nav_rate
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->nav_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nav_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // time_ref
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->time_ref);
    {
      int rc = PyObject_SetAttrString(_pymessage, "time_ref", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
