# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavATT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved0'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavATT(type):
    """Metaclass of message 'NavATT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 5,
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
                'ublox_msgs.msg.NavATT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_att
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_att
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_att
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_att
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_att

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
        return Metaclass_NavATT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavATT.__constants['MESSAGE_ID']


class NavATT(metaclass=Metaclass_NavATT):
    """
    Message class 'NavATT'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_version',
        '_reserved0',
        '_roll',
        '_pitch',
        '_heading',
        '_acc_roll',
        '_acc_pitch',
        '_acc_heading',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'version': 'uint8',
        'reserved0': 'uint8[3]',
        'roll': 'int32',
        'pitch': 'int32',
        'heading': 'int32',
        'acc_roll': 'uint32',
        'acc_pitch': 'uint32',
        'acc_heading': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.version = kwargs.get('version', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (3, )
        self.roll = kwargs.get('roll', int())
        self.pitch = kwargs.get('pitch', int())
        self.heading = kwargs.get('heading', int())
        self.acc_roll = kwargs.get('acc_roll', int())
        self.acc_pitch = kwargs.get('acc_pitch', int())
        self.acc_heading = kwargs.get('acc_heading', int())

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
        if self.i_tow != other.i_tow:
            return False
        if self.version != other.version:
            return False
        if all(self.reserved0 != other.reserved0):
            return False
        if self.roll != other.roll:
            return False
        if self.pitch != other.pitch:
            return False
        if self.heading != other.heading:
            return False
        if self.acc_roll != other.acc_roll:
            return False
        if self.acc_pitch != other.acc_pitch:
            return False
        if self.acc_heading != other.acc_heading:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def i_tow(self):
        """Message field 'i_tow'."""
        return self._i_tow

    @i_tow.setter
    def i_tow(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'i_tow' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'i_tow' field must be an unsigned integer in [0, 4294967295]"
        self._i_tow = value

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'version' field must be an unsigned integer in [0, 255]"
        self._version = value

    @builtins.property
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved0' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 3, \
                "The 'reserved0' numpy.ndarray() must have a size of 3"
            self._reserved0 = value
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
                "The 'reserved0' field must be a set or sequence with length 3 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved0 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def roll(self):
        """Message field 'roll'."""
        return self._roll

    @roll.setter
    def roll(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'roll' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'roll' field must be an integer in [-2147483648, 2147483647]"
        self._roll = value

    @builtins.property
    def pitch(self):
        """Message field 'pitch'."""
        return self._pitch

    @pitch.setter
    def pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pitch' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pitch' field must be an integer in [-2147483648, 2147483647]"
        self._pitch = value

    @builtins.property
    def heading(self):
        """Message field 'heading'."""
        return self._heading

    @heading.setter
    def heading(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'heading' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'heading' field must be an integer in [-2147483648, 2147483647]"
        self._heading = value

    @builtins.property
    def acc_roll(self):
        """Message field 'acc_roll'."""
        return self._acc_roll

    @acc_roll.setter
    def acc_roll(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_roll' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_roll' field must be an unsigned integer in [0, 4294967295]"
        self._acc_roll = value

    @builtins.property
    def acc_pitch(self):
        """Message field 'acc_pitch'."""
        return self._acc_pitch

    @acc_pitch.setter
    def acc_pitch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_pitch' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_pitch' field must be an unsigned integer in [0, 4294967295]"
        self._acc_pitch = value

    @builtins.property
    def acc_heading(self):
        """Message field 'acc_heading'."""
        return self._acc_heading

    @acc_heading.setter
    def acc_heading(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_heading' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_heading' field must be an unsigned integer in [0, 4294967295]"
        self._acc_heading = value
