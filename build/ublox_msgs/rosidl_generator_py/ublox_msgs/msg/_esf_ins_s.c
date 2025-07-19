// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/EsfINS.idl
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
#include "ublox_msgs/msg/detail/esf_ins__struct.h"
#include "ublox_msgs/msg/detail/esf_ins__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__esf_ins__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._esf_ins.EsfINS", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__EsfINS * ros_message = _ros_message;
  {  // bitfield0
    PyObject * field = PyObject_GetAttrString(_pymsg, "bitfield0");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->bitfield0 = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved1
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved1");
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
      Py_ssize_t size = 4;
      uint8_t * dest = ros_message->reserved1;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // x_ang_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_ang_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->x_ang_rate = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // y_ang_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_ang_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->y_ang_rate = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // z_ang_rate
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_ang_rate");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->z_ang_rate = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // x_accel
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_accel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->x_accel = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // y_accel
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_accel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->y_accel = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // z_accel
    PyObject * field = PyObject_GetAttrString(_pymsg, "z_accel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->z_accel = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__esf_ins__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of EsfINS */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._esf_ins");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "EsfINS");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__EsfINS * ros_message = (ublox_msgs__msg__EsfINS *)raw_ros_message;
  {  // bitfield0
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->bitfield0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "bitfield0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved1
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved1");
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
    uint8_t * src = &(ros_message->reserved1[0]);
    memcpy(dst, src, 4 * sizeof(uint8_t));
    Py_DECREF(field);
  }
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
  {  // x_ang_rate
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->x_ang_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_ang_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_ang_rate
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->y_ang_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_ang_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_ang_rate
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->z_ang_rate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_ang_rate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_accel
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->x_accel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_accel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_accel
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->y_accel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_accel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z_accel
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->z_accel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z_accel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
