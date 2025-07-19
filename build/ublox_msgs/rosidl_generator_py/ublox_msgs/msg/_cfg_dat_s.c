// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ublox_msgs:msg/CfgDAT.idl
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
#include "ublox_msgs/msg/detail/cfg_dat__struct.h"
#include "ublox_msgs/msg/detail/cfg_dat__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ublox_msgs__msg__cfg_dat__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("ublox_msgs.msg._cfg_dat.CfgDAT", full_classname_dest, 30) == 0);
  }
  ublox_msgs__msg__CfgDAT * ros_message = _ros_message;
  {  // datum_num
    PyObject * field = PyObject_GetAttrString(_pymsg, "datum_num");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->datum_num = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // datum_name
    PyObject * field = PyObject_GetAttrString(_pymsg, "datum_name");
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
      Py_ssize_t size = 6;
      uint8_t * dest = ros_message->datum_name;
      for (Py_ssize_t i = 0; i < size; ++i) {
        uint8_t tmp = *(npy_uint8 *)PyArray_GETPTR1(seq_field, i);
        memcpy(&dest[i], &tmp, sizeof(uint8_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // maj_a
    PyObject * field = PyObject_GetAttrString(_pymsg, "maj_a");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->maj_a = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // flat
    PyObject * field = PyObject_GetAttrString(_pymsg, "flat");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->flat = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "d_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "d_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "d_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rot_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "rot_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rot_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rot_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "rot_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rot_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rot_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "rot_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rot_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // scale
    PyObject * field = PyObject_GetAttrString(_pymsg, "scale");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->scale = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ublox_msgs__msg__cfg_dat__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CfgDAT */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ublox_msgs.msg._cfg_dat");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CfgDAT");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ublox_msgs__msg__CfgDAT * ros_message = (ublox_msgs__msg__CfgDAT *)raw_ros_message;
  {  // datum_num
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->datum_num);
    {
      int rc = PyObject_SetAttrString(_pymessage, "datum_num", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // datum_name
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "datum_name");
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
    uint8_t * src = &(ros_message->datum_name[0]);
    memcpy(dst, src, 6 * sizeof(uint8_t));
    Py_DECREF(field);
  }
  {  // maj_a
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->maj_a);
    {
      int rc = PyObject_SetAttrString(_pymessage, "maj_a", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // flat
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->flat);
    {
      int rc = PyObject_SetAttrString(_pymessage, "flat", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rot_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rot_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rot_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rot_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rot_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rot_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rot_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rot_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rot_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // scale
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->scale);
    {
      int rc = PyObject_SetAttrString(_pymessage, "scale", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
