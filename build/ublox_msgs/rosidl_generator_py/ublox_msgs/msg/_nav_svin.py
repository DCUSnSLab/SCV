# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSVIN.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved0'
# Member 'reserved3'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSVIN(type):
    """Metaclass of message 'NavSVIN'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 59,
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
                'ublox_msgs.msg.NavSVIN')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_svin
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_svin
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_svin
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_svin
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_svin

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
        return Metaclass_NavSVIN.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavSVIN.__constants['MESSAGE_ID']


class NavSVIN(metaclass=Metaclass_NavSVIN):
    """
    Message class 'NavSVIN'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_version',
        '_reserved0',
        '_i_tow',
        '_dur',
        '_mean_x',
        '_mean_y',
        '_mean_z',
        '_mean_xhp',
        '_mean_yhp',
        '_mean_zhp',
        '_reserved1',
        '_mean_acc',
        '_obs',
        '_valid',
        '_active',
        '_reserved3',
    ]

    _fields_and_field_types = {
        'version': 'uint8',
        'reserved0': 'uint8[3]',
        'i_tow': 'uint32',
        'dur': 'uint32',
        'mean_x': 'int32',
        'mean_y': 'int32',
        'mean_z': 'int32',
        'mean_xhp': 'int8',
        'mean_yhp': 'int8',
        'mean_zhp': 'int8',
        'reserved1': 'uint8',
        'mean_acc': 'uint32',
        'obs': 'uint32',
        'valid': 'uint8',
        'active': 'uint8',
        'reserved3': 'uint8[2]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 3),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(3, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (3, )
        self.i_tow = kwargs.get('i_tow', int())
        self.dur = kwargs.get('dur', int())
        self.mean_x = kwargs.get('mean_x', int())
        self.mean_y = kwargs.get('mean_y', int())
        self.mean_z = kwargs.get('mean_z', int())
        self.mean_xhp = kwargs.get('mean_xhp', int())
        self.mean_yhp = kwargs.get('mean_yhp', int())
        self.mean_zhp = kwargs.get('mean_zhp', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.mean_acc = kwargs.get('mean_acc', int())
        self.obs = kwargs.get('obs', int())
        self.valid = kwargs.get('valid', int())
        self.active = kwargs.get('active', int())
        if 'reserved3' not in kwargs:
            self.reserved3 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved3 = numpy.array(kwargs.get('reserved3'), dtype=numpy.uint8)
            assert self.reserved3.shape == (2, )

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
        if self.version != other.version:
            return False
        if all(self.reserved0 != other.reserved0):
            return False
        if self.i_tow != other.i_tow:
            return False
        if self.dur != other.dur:
            return False
        if self.mean_x != other.mean_x:
            return False
        if self.mean_y != other.mean_y:
            return False
        if self.mean_z != other.mean_z:
            return False
        if self.mean_xhp != other.mean_xhp:
            return False
        if self.mean_yhp != other.mean_yhp:
            return False
        if self.mean_zhp != other.mean_zhp:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.mean_acc != other.mean_acc:
            return False
        if self.obs != other.obs:
            return False
        if self.valid != other.valid:
            return False
        if self.active != other.active:
            return False
        if all(self.reserved3 != other.reserved3):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def dur(self):
        """Message field 'dur'."""
        return self._dur

    @dur.setter
    def dur(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dur' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'dur' field must be an unsigned integer in [0, 4294967295]"
        self._dur = value

    @builtins.property
    def mean_x(self):
        """Message field 'mean_x'."""
        return self._mean_x

    @mean_x.setter
    def mean_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mean_x' field must be an integer in [-2147483648, 2147483647]"
        self._mean_x = value

    @builtins.property
    def mean_y(self):
        """Message field 'mean_y'."""
        return self._mean_y

    @mean_y.setter
    def mean_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mean_y' field must be an integer in [-2147483648, 2147483647]"
        self._mean_y = value

    @builtins.property
    def mean_z(self):
        """Message field 'mean_z'."""
        return self._mean_z

    @mean_z.setter
    def mean_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_z' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'mean_z' field must be an integer in [-2147483648, 2147483647]"
        self._mean_z = value

    @builtins.property
    def mean_xhp(self):
        """Message field 'mean_xhp'."""
        return self._mean_xhp

    @mean_xhp.setter
    def mean_xhp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_xhp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'mean_xhp' field must be an integer in [-128, 127]"
        self._mean_xhp = value

    @builtins.property
    def mean_yhp(self):
        """Message field 'mean_yhp'."""
        return self._mean_yhp

    @mean_yhp.setter
    def mean_yhp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_yhp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'mean_yhp' field must be an integer in [-128, 127]"
        self._mean_yhp = value

    @builtins.property
    def mean_zhp(self):
        """Message field 'mean_zhp'."""
        return self._mean_zhp

    @mean_zhp.setter
    def mean_zhp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_zhp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'mean_zhp' field must be an integer in [-128, 127]"
        self._mean_zhp = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved1' field must be an unsigned integer in [0, 255]"
        self._reserved1 = value

    @builtins.property
    def mean_acc(self):
        """Message field 'mean_acc'."""
        return self._mean_acc

    @mean_acc.setter
    def mean_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mean_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'mean_acc' field must be an unsigned integer in [0, 4294967295]"
        self._mean_acc = value

    @builtins.property
    def obs(self):
        """Message field 'obs'."""
        return self._obs

    @obs.setter
    def obs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'obs' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'obs' field must be an unsigned integer in [0, 4294967295]"
        self._obs = value

    @builtins.property
    def valid(self):
        """Message field 'valid'."""
        return self._valid

    @valid.setter
    def valid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'valid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'valid' field must be an unsigned integer in [0, 255]"
        self._valid = value

    @builtins.property
    def active(self):
        """Message field 'active'."""
        return self._active

    @active.setter
    def active(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'active' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'active' field must be an unsigned integer in [0, 255]"
        self._active = value

    @builtins.property
    def reserved3(self):
        """Message field 'reserved3'."""
        return self._reserved3

    @reserved3.setter
    def reserved3(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved3' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved3' numpy.ndarray() must have a size of 2"
            self._reserved3 = value
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved3' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved3 = numpy.array(value, dtype=numpy.uint8)
