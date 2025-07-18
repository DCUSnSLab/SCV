// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgCFG.idl
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
#include "ublox_msgs/msg/detail/cfg_cfg__struct.h"
#include "ublox_msgs/msg/detail/cfg_cfg__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_cfg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[31];
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
    assert(strncmp("ublox_msgs.msg._cfg_cfg.CfgCFG", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__CfgCFG * ros_message = _ros_message;
  {  // clear_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "clear_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->clear_mask = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // save_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "save_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->save_mask = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // load_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "load_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->load_mask = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // device_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "device_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->device_mask = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_cfg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgCFG */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_cfg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgCFG");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgCFG * ros_message = (ublox_msgs__msg__CfgCFG *)raw_ros_message;
  {  // clear_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->clear_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "clear_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // save_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->save_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "save_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // load_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->load_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "load_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // device_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->device_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "device_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
