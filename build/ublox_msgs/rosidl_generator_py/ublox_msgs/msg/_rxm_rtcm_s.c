// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/RxmRTCM.idl
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
#include "ublox_msgs/msg/detail/rxm_rtcm__struct.h"
#include "ublox_msgs/msg/detail/rxm_rtcm__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__rxm_rtcm__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._rxm_rtcm.RxmRTCM", full_classname_dest, 32) == 0);
  }
  ublox_msgs__msg__RxmRTCM * ros_message = _ros_message;
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint8_t)PyLong_AsUnsignedLong(field);
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
  {  // reserved0
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved0");
    if (!field) {
      return false;
    }
    {
      // TODO(dirk-thomas) use a better way to check the type before casting
      assert(field->ob_type != NULL);
      assert(field->ob_type->tp_name != NULL);
      assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
      PyArrayObject * seq_field = (PyArrayObject *)field;
      Py_INCREF(seq_field);
      assert(PyArray_NDIM(seq_field) == 1);
      assert(PyArray_TYPE(seq_field) == NPY_UINT8);
      Py_ssize_t size = 2;
      uint8_t * dest = ros_message->reserved0;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // ref_station
    PyObject * field = PyObject_GetAttrString(_pymsg, "ref_station");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ref_station = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // msg_type
    PyObject * field = PyObject_GetAttrString(_pymsg, "msg_type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->msg_type = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__rxm_rtcm__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RxmRTCM */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._rxm_rtcm");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RxmRTCM");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__RxmRTCM * ros_message = (ublox_msgs__msg__RxmRTCM *)raw_ros_message;
  {  // version
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->version);
    {
      int rc = PyObject_SetAttrString(_pymessage, "version", field);
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
  {  // reserved0
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved0");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "numpy.ndarray") == 0);
    PyArrayObject * seq_field = (PyArrayObject *)field;
    assert(PyArray_NDIM(seq_field) == 1);
    assert(PyArray_TYPE(seq_field) == NPY_UINT8);
    assert(sizeof(npy_uint8) == sizeof(uint8_t));
    npy_uint8 * dst = (npy_uint8 *)PyArray_GETPTR1(seq_field, 0);
    uint8_t * src = &(ros_message->reserved0[0]);
    memcpy(dst, src, 2 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // ref_station
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ref_station);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ref_station", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // msg_type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->msg_type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "msg_type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
