// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/NavCOV.idl
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
#include "ublox_msgs/msg/detail/nav_cov__struct.h"
#include "ublox_msgs/msg/detail/nav_cov__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__nav_cov__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._nav_cov.NavCOV", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__NavCOV * ros_message = _ros_message;
  {  // i_tow
    PyObject * field = PyObject_GetAttrString(_pymsg, "i_tow");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->i_tow = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // version
    PyObject * field = PyObject_GetAttrString(_pymsg, "version");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->version = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // pos_cov_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_valid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->pos_cov_valid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // vel_cov_valid
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_valid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->vel_cov_valid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // reserved_0
    PyObject * field = PyObject_GetAttrString(_pymsg, "reserved_0");
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
      Py_ssize_t size = 9;
      uint8_t * dest = ros_message->reserved_0;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // pos_cov_nn
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_nn");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_nn = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_cov_ne
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_ne");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_ne = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_cov_nd
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_nd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_nd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_cov_ee
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_ee");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_ee = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_cov_ed
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_ed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_ed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pos_cov_dd
    PyObject * field = PyObject_GetAttrString(_pymsg, "pos_cov_dd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pos_cov_dd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_nn
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_nn");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_nn = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_ne
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_ne");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_ne = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_nd
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_nd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_nd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_ee
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_ee");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_ee = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_ed
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_ed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_ed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // vel_cov_dd
    PyObject * field = PyObject_GetAttrString(_pymsg, "vel_cov_dd");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->vel_cov_dd = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__nav_cov__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NavCOV */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._nav_cov");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NavCOV");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__NavCOV * ros_message = (ublox_msgs__msg__NavCOV *)raw_ros_message;
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
  {  // pos_cov_valid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->pos_cov_valid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_valid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->vel_cov_valid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_valid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // reserved_0
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "reserved_0");
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
    uint8_t * src = &(ros_message->reserved_0[0]);
    memcpy(dst, src, 9 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // pos_cov_nn
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_nn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_nn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_cov_ne
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_ne);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_ne", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_cov_nd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_nd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_nd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_cov_ee
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_ee);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_ee", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_cov_ed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_ed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_ed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pos_cov_dd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pos_cov_dd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pos_cov_dd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_nn
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_nn);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_nn", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_ne
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_ne);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_ne", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_nd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_nd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_nd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_ee
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_ee);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_ee", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_ed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_ed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_ed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vel_cov_dd
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->vel_cov_dd);
    {
      int rc = PyObject_SetAttrString(_pymessage, "vel_cov_dd", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
