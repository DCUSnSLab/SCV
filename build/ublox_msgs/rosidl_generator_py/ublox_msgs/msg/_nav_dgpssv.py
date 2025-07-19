# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavDGPSSV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavDGPSSV(type):
    """Metaclass of message 'NavDGPSSV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FLAGS_CHANNEL_MASK': 15,
        'FLAGS_DGPS': 16,
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
                'ublox_msgs.msg.NavDGPSSV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_dgpssv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_dgpssv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_dgpssv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_dgpssv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_dgpssv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FLAGS_CHANNEL_MASK': cls.__constants['FLAGS_CHANNEL_MASK'],
            'FLAGS_DGPS': cls.__constants['FLAGS_DGPS'],
        }

    @property
    def FLAGS_CHANNEL_MASK(self):
        """Message constant 'FLAGS_CHANNEL_MASK'."""
        return Metaclass_NavDGPSSV.__constants['FLAGS_CHANNEL_MASK']

    @property
    def FLAGS_DGPS(self):
        """Message constant 'FLAGS_DGPS'."""
        return Metaclass_NavDGPSSV.__constants['FLAGS_DGPS']


class NavDGPSSV(metaclass=Metaclass_NavDGPSSV):
    """
    Message class 'NavDGPSSV'.

    Constants:
      FLAGS_CHANNEL_MASK
      FLAGS_DGPS
    """

    __slots__ = [
        '_svid',
        '_flags',
        '_age_c',
        '_prc',
        '_prrc',
    ]

    _fields_and_field_types = {
        'svid': 'uint8',
        'flags': 'uint8',
        'age_c': 'uint16',
        'prc': 'float',
        'prrc': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.svid = kwargs.get('svid', int())
        self.flags = kwargs.get('flags', int())
        self.age_c = kwargs.get('age_c', int())
        self.prc = kwargs.get('prc', float())
        self.prrc = kwargs.get('prrc', float())

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
        if self.svid != other.svid:
            return False
        if self.flags != other.flags:
            return False
        if self.age_c != other.age_c:
            return False
        if self.prc != other.prc:
            return False
        if self.prrc != other.prrc:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def svid(self):
        """Message field 'svid'."""
        return self._svid

    @svid.setter
    def svid(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'svid' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'svid' field must be an unsigned integer in [0, 255]"
        self._svid = value

    @builtins.property
    def flags(self):
        """Message field 'flags'."""
        return self._flags

    @flags.setter
    def flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'flags' field must be an unsigned integer in [0, 255]"
        self._flags = value

    @builtins.property
    def age_c(self):
        """Message field 'age_c'."""
        return self._age_c

    @age_c.setter
    def age_c(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'age_c' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'age_c' field must be an unsigned integer in [0, 65535]"
        self._age_c = value

    @builtins.property
    def prc(self):
        """Message field 'prc'."""
        return self._prc

    @prc.setter
    def prc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'prc' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'prc' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._prc = value

    @builtins.property
    def prrc(self):
        """Message field 'prrc'."""
        return self._prrc

    @prrc.setter
    def prrc(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'prrc' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'prrc' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._prrc = value
