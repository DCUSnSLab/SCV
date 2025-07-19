// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavSVINFOSV.idl
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
#include "ublox_msgs/msg/detail/nav_svinfosv__struct.h"
#include "ublox_msgs/msg/detail/nav_svinfosv__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_svinfosv__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[41];
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
    assert(strncmp("ublox_msgs.msg._nav_svinfosv.NavSVINFOSV", full_classname_dest, 40) == 0);
  }
  ublox_msgs__msg__NavSVINFOSV * ros_message = _ros_message;
  {  // chn
    PyObject * field = PyObject_GetAttrString(_pymsg, "chn");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->chn = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // svid
    PyObject * field = PyObject_GetAttrString(_pymsg, "svid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->svid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // quality
    PyObject * field = PyObject_GetAttrString(_pymsg, "quality");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->quality = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cno
    PyObject * field = PyObject_GetAttrString(_pymsg, "cno");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cno = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // elev
    PyObject * field = PyObject_GetAttrString(_pymsg, "elev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->elev = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // azim
    PyObject * field = PyObject_GetAttrString(_pymsg, "azim");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->azim = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pr_res
    PyObject * field = PyObject_GetAttrString(_pymsg, "pr_res");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pr_res = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_svinfosv__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavSVINFOSV */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_svinfosv");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavSVINFOSV");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavSVINFOSV * ros_message = (ublox_msgs__msg__NavSVINFOSV *)raw_ros_message;
  {  // chn
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->chn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "chn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // svid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->svid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "svid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flags
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // quality
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->quality);
    {
      int rc = PyObject_SetAttrString(_pymessage, "quality", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cno
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cno);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cno", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // elev
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->elev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "elev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // azim
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->azim);
    {
      int rc = PyObject_SetAttrString(_pymessage, "azim", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pr_res
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->pr_res);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pr_res", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
