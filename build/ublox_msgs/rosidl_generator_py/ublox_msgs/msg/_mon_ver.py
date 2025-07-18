# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/MonVER.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'sw_version'
# Member 'hw_version'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MonVER(type):
    """Metaclass of message 'MonVER'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 10,
        'MESSAGE_ID': 4,
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
                'ublox_msgs.msg.MonVER')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mon_ver
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mon_ver
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mon_ver
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mon_ver
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mon_ver

            from ublox_msgs.msg import MonVERExtension
            if MonVERExtension.__class__._TYPE_SUPPORT is None:
                MonVERExtension.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_MonVER.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_MonVER.__constants['MESSAGE_ID']


class MonVER(metaclass=Metaclass_MonVER):
    """
    Message class 'MonVER'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_sw_version',
        '_hw_version',
        '_extension',
    ]

    _fields_and_field_types = {
        'sw_version': 'uint8[30]',
        'hw_version': 'uint8[10]',
        'extension': 'sequence<ublox_msgs/MonVERExtension>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 30),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 10),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['ublox_msgs', 'msg'], 'MonVERExtension')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'sw_version' not in kwargs:
            self.sw_version = numpy.zeros(30, dtype=numpy.uint8)
        else:
            self.sw_version = numpy.array(kwargs.get('sw_version'), dtype=numpy.uint8)
            assert self.sw_version.shape == (30, )
        if 'hw_version' not in kwargs:
            self.hw_version = numpy.zeros(10, dtype=numpy.uint8)
        else:
            self.hw_version = numpy.array(kwargs.get('hw_version'), dtype=numpy.uint8)
            assert self.hw_version.shape == (10, )
        self.extension = kwargs.get('extension', [])

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
        if all(self.sw_version != other.sw_version):
            return False
        if all(self.hw_version != other.hw_version):
            return False
        if self.extension != other.extension:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sw_version(self):
        """Message field 'sw_version'."""
        return self._sw_version

    @sw_version.setter
    def sw_version(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'sw_version' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 30, \
                "The 'sw_version' numpy.ndarray() must have a size of 30"
            self._sw_version = value
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
                 len(value) == 30 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'sw_version' field must be a set or sequence with length 30 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._sw_version = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def hw_version(self):
        """Message field 'hw_version'."""
        return self._hw_version

    @hw_version.setter
    def hw_version(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'hw_version' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 10, \
                "The 'hw_version' numpy.ndarray() must have a size of 10"
            self._hw_version = value
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
                 len(value) == 10 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'hw_version' field must be a set or sequence with length 10 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._hw_version = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def extension(self):
        """Message field 'extension'."""
        return self._extension

    @extension.setter
    def extension(self, value):
        if __debug__:
            from ublox_msgs.msg import MonVERExtension
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
                 all(isinstance(v, MonVERExtension) for v in value) and
                 True), \
                "The 'extension' field must be a set or sequence and each value of type 'MonVERExtension'"
        self._extension = value
