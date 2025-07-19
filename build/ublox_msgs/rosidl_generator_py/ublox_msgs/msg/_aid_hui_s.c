// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/AidHUI.idl
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
#include "ublox_msgs/msg/detail/aid_hui__struct.h"
#include "ublox_msgs/msg/detail/aid_hui__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__aid_hui__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._aid_hui.AidHUI", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__AidHUI * ros_message = _ros_message;
  {  // health
    PyObject * field = PyObject_GetAttrString(_pymsg, "health");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->health = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // utc_a0
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_a0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->utc_a0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // utc_a1
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_a1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->utc_a1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // utc_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_tow = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_wnt
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_wnt");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_wnt = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_ls
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_ls");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_ls = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_wnf
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_wnf");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_wnf = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_dn
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_dn");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_dn = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_lsf
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_lsf");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_lsf = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // utc_spare
    PyObject * field = PyObject_GetAttrString(_pymsg, "utc_spare");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->utc_spare = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // klob_a0
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_a0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_a0 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_a1
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_a1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_a1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_a2
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_a2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_a2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_a3
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_a3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_a3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_b0
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_b0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_b0 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_b1
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_b1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_b1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_b2
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_b2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_b2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // klob_b3
    PyObject * field = PyObject_GetAttrString(_pymsg, "klob_b3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->klob_b3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->flags = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__aid_hui__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of AidHUI */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._aid_hui");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "AidHUI");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__AidHUI * ros_message = (ublox_msgs__msg__AidHUI *)raw_ros_message;
  {  // health
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->health);
    {
      int rc = PyObject_SetAttrString(_pymessage, "health", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_a0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->utc_a0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_a0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_a1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->utc_a1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_a1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_tow
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_tow);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_tow", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_wnt
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_wnt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_wnt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_ls
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_ls);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_ls", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_wnf
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_wnf);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_wnf", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_dn
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_dn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_dn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_lsf
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_lsf);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_lsf", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // utc_spare
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->utc_spare);
    {
      int rc = PyObject_SetAttrString(_pymessage, "utc_spare", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_a0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_a0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_a0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_a1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_a1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_a1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_a2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_a2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_a2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_a3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_a3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_a3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_b0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_b0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_b0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_b1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_b1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_b1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_b2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_b2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_b2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // klob_b3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->klob_b3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "klob_b3", field);
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

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
