# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/UpdSOS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpdSOS(type):
    """Metaclass of message 'UpdSOS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 9,
        'MESSAGE_ID': 20,
        'CMD_FLASH_BACKUP_CREATE': 0,
        'CMD_FLASH_BACKUP_CLEAR': 1,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ublox_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ublox_msgs.msg.UpdSOS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__upd_sos
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__upd_sos
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__upd_sos
            cls._TYPE_SUPPORT = module.type_support_msg__msg__upd_sos
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__upd_sos

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'CMD_FLASH_BACKUP_CREATE': cls.__constants['CMD_FLASH_BACKUP_CREATE'],
            'CMD_FLASH_BACKUP_CLEAR': cls.__constants['CMD_FLASH_BACKUP_CLEAR'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_UpdSOS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_UpdSOS.__constants['MESSAGE_ID']

    @property
    def CMD_FLASH_BACKUP_CREATE(self):
        """Message constant 'CMD_FLASH_BACKUP_CREATE'."""
        return Metaclass_UpdSOS.__constants['CMD_FLASH_BACKUP_CREATE']

    @property
    def CMD_FLASH_BACKUP_CLEAR(self):
        """Message constant 'CMD_FLASH_BACKUP_CLEAR'."""
        return Metaclass_UpdSOS.__constants['CMD_FLASH_BACKUP_CLEAR']


class UpdSOS(metaclass=Metaclass_UpdSOS):
    """
    Message class 'UpdSOS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      CMD_FLASH_BACKUP_CREATE
      CMD_FLASH_BACKUP_CLEAR
    """

    __slots__ = [
        '_cmd',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'cmd': 'uint8',
        'reserved1': 'uint8[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd = kwargs.get('cmd', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (3, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.cmd != other.cmd:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd(self):
        """Message field 'cmd'."""
        return self._cmd

    @cmd.setter
    def cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cmd' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cmd' field must be an unsigned integer in [0, 255]"
        self._cmd = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 3, \
                "The 'reserved1' numpy.ndarray() must have a size of 3"
            self._reserved1 = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)
