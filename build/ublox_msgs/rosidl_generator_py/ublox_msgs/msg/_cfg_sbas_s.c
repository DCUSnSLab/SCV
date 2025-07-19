// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgSBAS.idl
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
#include "ublox_msgs/msg/detail/cfg_sbas__struct.h"
#include "ublox_msgs/msg/detail/cfg_sbas__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_sbas__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_sbas.CfgSBAS", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__CfgSBAS * ros_message = _ros_message;
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // usage
    PyObject * field = PyObject_GetAttrString(_pymsg, "usage");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->usage = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // max_sbas
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_sbas");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_sbas = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // scanmode2
    PyObject * field = PyObject_GetAttrString(_pymsg, "scanmode2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->scanmode2 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // scanmode1
    PyObject * field = PyObject_GetAttrString(_pymsg, "scanmode1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->scanmode1 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_sbas__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgSBAS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_sbas");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgSBAS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgSBAS * ros_message = (ublox_msgs__msg__CfgSBAS *)raw_ros_message;
  {  // mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // usage
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->usage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "usage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_sbas
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->max_sbas);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_sbas", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scanmode2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->scanmode2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "scanmode2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scanmode1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->scanmode1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "scanmode1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
