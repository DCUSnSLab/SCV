// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/RxmRAWXMeas.idl
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
#include "ublox_msgs/msg/detail/rxm_rawx_meas__struct.h"
#include "ublox_msgs/msg/detail/rxm_rawx_meas__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__rxm_rawx_meas__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
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
    assert(strncmp("ublox_msgs.msg._rxm_rawx_meas.RxmRAWXMeas", full_classname_dest, 41) == 0);
  }
  ublox_msgs__msg__RxmRAWXMeas * ros_message = _ros_message;
  {  // pr_mes
    PyObject * field = PyObject_GetAttrString(_pymsg, "pr_mes");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pr_mes = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // cp_mes
    PyObject * field = PyObject_GetAttrString(_pymsg, "cp_mes");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->cp_mes = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // do_mes
    PyObject * field = PyObject_GetAttrString(_pymsg, "do_mes");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->do_mes = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // gnss_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "gnss_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gnss_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // sv_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "sv_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->sv_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved0
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved0 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // freq_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "freq_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->freq_id = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // locktime
    PyObject * field = PyObject_GetAttrString(_pymsg, "locktime");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->locktime = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cno
    PyObject * field = PyObject_GetAttrString(_pymsg, "cno");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cno = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // pr_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "pr_stdev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pr_stdev = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // cp_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "cp_stdev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->cp_stdev = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // do_stdev
    PyObject * field = PyObject_GetAttrString(_pymsg, "do_stdev");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->do_stdev = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trk_stat
    PyObject * field = PyObject_GetAttrString(_pymsg, "trk_stat");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->trk_stat = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved1");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->reserved1 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__rxm_rawx_meas__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RxmRAWXMeas */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._rxm_rawx_meas");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RxmRAWXMeas");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__RxmRAWXMeas * ros_message = (ublox_msgs__msg__RxmRAWXMeas *)raw_ros_message;
  {  // pr_mes
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pr_mes);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pr_mes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cp_mes
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->cp_mes);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cp_mes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // do_mes
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->do_mes);
    {
      int rc = PyObject_SetAttrString(_pymessage, "do_mes", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gnss_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gnss_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gnss_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sv_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->sv_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sv_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved0
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->reserved0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // freq_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->freq_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "freq_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // locktime
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->locktime);
    {
      int rc = PyObject_SetAttrString(_pymessage, "locktime", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cno
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->cno);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cno", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pr_stdev
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pr_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pr_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cp_stdev
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->cp_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "cp_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // do_stdev
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->do_stdev);
    {
      int rc = PyObject_SetAttrString(_pymessage, "do_stdev", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trk_stat
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->trk_stat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "trk_stat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved1
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->reserved1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
