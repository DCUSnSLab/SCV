// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/EsfSTATUSSens.idl
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
#include "ublox_msgs/msg/detail/esf_status_sens__struct.h"
#include "ublox_msgs/msg/detail/esf_status_sens__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__esf_status_sens__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("ublox_msgs.msg._esf_status_sens.EsfSTATUSSens", full_classname_dest, 45) == 0);
  }
  ublox_msgs__msg__EsfSTATUSSens * ros_message = _ros_message;
  {  // sens_status1
    PyObject * field = PyObject_GetAttrString(_pymsg, "sens_status1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sens_status1 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sens_status2
    PyObject * field = PyObject_GetAttrString(_pymsg, "sens_status2");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sens_status2 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // freq
    PyObject * field = PyObject_GetAttrString(_pymsg, "freq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->freq = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // faults
    PyObject * field = PyObject_GetAttrString(_pymsg, "faults");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->faults = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__esf_status_sens__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EsfSTATUSSens */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._esf_status_sens");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EsfSTATUSSens");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__EsfSTATUSSens * ros_message = (ublox_msgs__msg__EsfSTATUSSens *)raw_ros_message;
  {  // sens_status1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sens_status1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sens_status1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sens_status2
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sens_status2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sens_status2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // freq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->freq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "freq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // faults
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->faults);
    {
      int rc = PyObject_SetAttrString(_pymessage, "faults", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
