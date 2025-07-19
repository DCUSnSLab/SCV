// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/MonHW.idl
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
#include "ublox_msgs/msg/detail/mon_hw__struct.h"
#include "ublox_msgs/msg/detail/mon_hw__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__mon_hw__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[29];
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
    assert(strncmp("ublox_msgs.msg._mon_hw.MonHW", full_classname_dest, 28) == 0);
  }
  ublox_msgs__msg__MonHW * ros_message = _ros_message;
  {  // pin_sel
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin_sel");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin_sel = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pin_bank
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin_bank");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin_bank = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pin_dir
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin_dir");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin_dir = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pin_val
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin_val");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin_val = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // noise_per_ms
    PyObject * field = PyObject_GetAttrString(_pymsg, "noise_per_ms");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->noise_per_ms = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // agc_cnt
    PyObject * field = PyObject_GetAttrString(_pymsg, "agc_cnt");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->agc_cnt = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // a_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_status");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->a_status = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // a_power
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_power");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->a_power = (uint8_t)PyLong_AsUnsignedLong(field);
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
    assert(PyLong_Check(field));
    ros_message->reserved0 = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // used_mask
    PyObject * field = PyObject_GetAttrString(_pymsg, "used_mask");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->used_mask = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vp
    PyObject * field = PyObject_GetAttrString(_pymsg, "vp");
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
      Py_ssize_t size = 17;
      uint8_t * dest = ros_message->vp;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // jam_ind
    PyObject * field = PyObject_GetAttrString(_pymsg, "jam_ind");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->jam_ind = (uint8_t)PyLong_AsUnsignedLong(field);
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
      Py_ssize_t size = 2;
      uint8_t * dest = ros_message->reserved1;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // pin_irq
    PyObject * field = PyObject_GetAttrString(_pymsg, "pin_irq");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pin_irq = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pull_h
    PyObject * field = PyObject_GetAttrString(_pymsg, "pull_h");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pull_h = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pull_l
    PyObject * field = PyObject_GetAttrString(_pymsg, "pull_l");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pull_l = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__mon_hw__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MonHW */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._mon_hw");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MonHW");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__MonHW * ros_message = (ublox_msgs__msg__MonHW *)raw_ros_message;
  {  // pin_sel
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin_sel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin_sel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pin_bank
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin_bank);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin_bank", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pin_dir
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin_dir);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin_dir", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pin_val
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin_val);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin_val", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // noise_per_ms
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->noise_per_ms);
    {
      int rc = PyObject_SetAttrString(_pymessage, "noise_per_ms", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // agc_cnt
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->agc_cnt);
    {
      int rc = PyObject_SetAttrString(_pymessage, "agc_cnt", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_status
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->a_status);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_power
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->a_power);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_power", field);
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
    field = PyLong_FromUnsignedLong(ros_message->reserved0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "reserved0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // used_mask
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->used_mask);
    {
      int rc = PyObject_SetAttrString(_pymessage, "used_mask", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vp
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "vp");
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
    uint8_t * src = &(ros_message->vp[0]);
    memcpy(dst, src, 17 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // jam_ind
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->jam_ind);
    {
      int rc = PyObject_SetAttrString(_pymessage, "jam_ind", field);
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
    memcpy(dst, src, 2 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // pin_irq
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pin_irq);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pin_irq", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pull_h
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pull_h);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pull_h", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pull_l
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pull_l);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pull_l", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
