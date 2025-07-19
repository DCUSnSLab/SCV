// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavPOSLLH.idl
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
#include "ublox_msgs/msg/detail/nav_posllh__struct.h"
#include "ublox_msgs/msg/detail/nav_posllh__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_posllh__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("ublox_msgs.msg._nav_posllh.NavPOSLLH", full_classname_dest, 36) == 0);
  }
  ublox_msgs__msg__NavPOSLLH * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // lon
    PyObject * field = PyObject_GetAttrString(_pymsg, "lon");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lon = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // lat
    PyObject * field = PyObject_GetAttrString(_pymsg, "lat");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->lat = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->height = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // h_msl
    PyObject * field = PyObject_GetAttrString(_pymsg, "h_msl");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->h_msl = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // h_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "h_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->h_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // v_acc
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_acc");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->v_acc = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_posllh__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavPOSLLH */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_posllh");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavPOSLLH");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavPOSLLH * ros_message = (ublox_msgs__msg__NavPOSLLH *)raw_ros_message;
  {  // i_tow
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->i_tow);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i_tow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lon
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lon);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lon", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lat
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->lat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // h_msl
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->h_msl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "h_msl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // h_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->h_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "h_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_acc
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->v_acc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_acc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
