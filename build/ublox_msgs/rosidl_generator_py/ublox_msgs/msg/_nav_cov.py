# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavCOV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'reserved_0'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavCOV(type):
    """Metaclass of message 'NavCOV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 54,
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
                'ublox_msgs.msg.NavCOV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_cov
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_cov
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_cov
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_cov
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_cov

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
        return Metaclass_NavCOV.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavCOV.__constants['MESSAGE_ID']


class NavCOV(metaclass=Metaclass_NavCOV):
    """
    Message class 'NavCOV'.

    Constants:
      CLASS_ID
      MESSAGE_ID
    """

    __slots__ = [
        '_i_tow',
        '_version',
        '_pos_cov_valid',
        '_vel_cov_valid',
        '_reserved_0',
        '_pos_cov_nn',
        '_pos_cov_ne',
        '_pos_cov_nd',
        '_pos_cov_ee',
        '_pos_cov_ed',
        '_pos_cov_dd',
        '_vel_cov_nn',
        '_vel_cov_ne',
        '_vel_cov_nd',
        '_vel_cov_ee',
        '_vel_cov_ed',
        '_vel_cov_dd',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'version': 'uint8',
        'pos_cov_valid': 'uint8',
        'vel_cov_valid': 'uint8',
        'reserved_0': 'uint8[9]',
        'pos_cov_nn': 'float',
        'pos_cov_ne': 'float',
        'pos_cov_nd': 'float',
        'pos_cov_ee': 'float',
        'pos_cov_ed': 'float',
        'pos_cov_dd': 'float',
        'vel_cov_nn': 'float',
        'vel_cov_ne': 'float',
        'vel_cov_nd': 'float',
        'vel_cov_ee': 'float',
        'vel_cov_ed': 'float',
        'vel_cov_dd': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 9),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.version = kwargs.get('version', int())
        self.pos_cov_valid = kwargs.get('pos_cov_valid', int())
        self.vel_cov_valid = kwargs.get('vel_cov_valid', int())
        if 'reserved_0' not in kwargs:
            self.reserved_0 = numpy.zeros(9, dtype=numpy.uint8)
        else:
            self.reserved_0 = numpy.array(kwargs.get('reserved_0'), dtype=numpy.uint8)
            assert self.reserved_0.shape == (9, )
        self.pos_cov_nn = kwargs.get('pos_cov_nn', float())
        self.pos_cov_ne = kwargs.get('pos_cov_ne', float())
        self.pos_cov_nd = kwargs.get('pos_cov_nd', float())
        self.pos_cov_ee = kwargs.get('pos_cov_ee', float())
        self.pos_cov_ed = kwargs.get('pos_cov_ed', float())
        self.pos_cov_dd = kwargs.get('pos_cov_dd', float())
        self.vel_cov_nn = kwargs.get('vel_cov_nn', float())
        self.vel_cov_ne = kwargs.get('vel_cov_ne', float())
        self.vel_cov_nd = kwargs.get('vel_cov_nd', float())
        self.vel_cov_ee = kwargs.get('vel_cov_ee', float())
        self.vel_cov_ed = kwargs.get('vel_cov_ed', float())
        self.vel_cov_dd = kwargs.get('vel_cov_dd', float())

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
        if self.pos_cov_valid != other.pos_cov_valid:
            return False
        if self.vel_cov_valid != other.vel_cov_valid:
            return False
        if all(self.reserved_0 != other.reserved_0):
            return False
        if self.pos_cov_nn != other.pos_cov_nn:
            return False
        if self.pos_cov_ne != other.pos_cov_ne:
            return False
        if self.pos_cov_nd != other.pos_cov_nd:
            return False
        if self.pos_cov_ee != other.pos_cov_ee:
            return False
        if self.pos_cov_ed != other.pos_cov_ed:
            return False
        if self.pos_cov_dd != other.pos_cov_dd:
            return False
        if self.vel_cov_nn != other.vel_cov_nn:
            return False
        if self.vel_cov_ne != other.vel_cov_ne:
            return False
        if self.vel_cov_nd != other.vel_cov_nd:
            return False
        if self.vel_cov_ee != other.vel_cov_ee:
            return False
        if self.vel_cov_ed != other.vel_cov_ed:
            return False
        if self.vel_cov_dd != other.vel_cov_dd:
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
    def pos_cov_valid(self):
        """Message field 'pos_cov_valid'."""
        return self._pos_cov_valid

    @pos_cov_valid.setter
    def pos_cov_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pos_cov_valid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'pos_cov_valid' field must be an unsigned integer in [0, 255]"
        self._pos_cov_valid = value

    @builtins.property
    def vel_cov_valid(self):
        """Message field 'vel_cov_valid'."""
        return self._vel_cov_valid

    @vel_cov_valid.setter
    def vel_cov_valid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_cov_valid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'vel_cov_valid' field must be an unsigned integer in [0, 255]"
        self._vel_cov_valid = value

    @builtins.property
    def reserved_0(self):
        """Message field 'reserved_0'."""
        return self._reserved_0

    @reserved_0.setter
    def reserved_0(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved_0' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 9, \
                "The 'reserved_0' numpy.ndarray() must have a size of 9"
            self._reserved_0 = value
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
                 len(value) == 9 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved_0' field must be a set or sequence with length 9 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved_0 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def pos_cov_nn(self):
        """Message field 'pos_cov_nn'."""
        return self._pos_cov_nn

    @pos_cov_nn.setter
    def pos_cov_nn(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_nn' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_nn' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_nn = value

    @builtins.property
    def pos_cov_ne(self):
        """Message field 'pos_cov_ne'."""
        return self._pos_cov_ne

    @pos_cov_ne.setter
    def pos_cov_ne(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_ne' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_ne' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_ne = value

    @builtins.property
    def pos_cov_nd(self):
        """Message field 'pos_cov_nd'."""
        return self._pos_cov_nd

    @pos_cov_nd.setter
    def pos_cov_nd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_nd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_nd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_nd = value

    @builtins.property
    def pos_cov_ee(self):
        """Message field 'pos_cov_ee'."""
        return self._pos_cov_ee

    @pos_cov_ee.setter
    def pos_cov_ee(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_ee' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_ee' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_ee = value

    @builtins.property
    def pos_cov_ed(self):
        """Message field 'pos_cov_ed'."""
        return self._pos_cov_ed

    @pos_cov_ed.setter
    def pos_cov_ed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_ed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_ed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_ed = value

    @builtins.property
    def pos_cov_dd(self):
        """Message field 'pos_cov_dd'."""
        return self._pos_cov_dd

    @pos_cov_dd.setter
    def pos_cov_dd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_cov_dd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pos_cov_dd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pos_cov_dd = value

    @builtins.property
    def vel_cov_nn(self):
        """Message field 'vel_cov_nn'."""
        return self._vel_cov_nn

    @vel_cov_nn.setter
    def vel_cov_nn(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_nn' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_nn' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_nn = value

    @builtins.property
    def vel_cov_ne(self):
        """Message field 'vel_cov_ne'."""
        return self._vel_cov_ne

    @vel_cov_ne.setter
    def vel_cov_ne(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_ne' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_ne' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_ne = value

    @builtins.property
    def vel_cov_nd(self):
        """Message field 'vel_cov_nd'."""
        return self._vel_cov_nd

    @vel_cov_nd.setter
    def vel_cov_nd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_nd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_nd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_nd = value

    @builtins.property
    def vel_cov_ee(self):
        """Message field 'vel_cov_ee'."""
        return self._vel_cov_ee

    @vel_cov_ee.setter
    def vel_cov_ee(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_ee' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_ee' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_ee = value

    @builtins.property
    def vel_cov_ed(self):
        """Message field 'vel_cov_ed'."""
        return self._vel_cov_ed

    @vel_cov_ed.setter
    def vel_cov_ed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_ed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_ed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_ed = value

    @builtins.property
    def vel_cov_dd(self):
        """Message field 'vel_cov_dd'."""
        return self._vel_cov_dd

    @vel_cov_dd.setter
    def vel_cov_dd(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'vel_cov_dd' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'vel_cov_dd' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._vel_cov_dd = value
