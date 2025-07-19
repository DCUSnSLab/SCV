# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavTIMEGPS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavTIMEGPS(type):
    """Metaclass of message 'NavTIMEGPS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 32,
        'VALID_TOW': 1,
        'VALID_WEEK': 2,
        'VALID_LEAP_S': 4,
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
                'ublox_msgs.msg.NavTIMEGPS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_timegps
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_timegps
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_timegps
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_timegps
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_timegps

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'VALID_TOW': cls.__constants['VALID_TOW'],
            'VALID_WEEK': cls.__constants['VALID_WEEK'],
            'VALID_LEAP_S': cls.__constants['VALID_LEAP_S'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavTIMEGPS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavTIMEGPS.__constants['MESSAGE_ID']

    @property
    def VALID_TOW(self):
        """Message constant 'VALID_TOW'."""
        return Metaclass_NavTIMEGPS.__constants['VALID_TOW']

    @property
    def VALID_WEEK(self):
        """Message constant 'VALID_WEEK'."""
        return Metaclass_NavTIMEGPS.__constants['VALID_WEEK']

    @property
    def VALID_LEAP_S(self):
        """Message constant 'VALID_LEAP_S'."""
        return Metaclass_NavTIMEGPS.__constants['VALID_LEAP_S']


class NavTIMEGPS(metaclass=Metaclass_NavTIMEGPS):
    """
    Message class 'NavTIMEGPS'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      VALID_TOW
      VALID_WEEK
      VALID_LEAP_S
    """

    __slots__ = [
        '_i_tow',
        '_f_tow',
        '_week',
        '_leap_s',
        '_valid',
        '_t_acc',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'f_tow': 'int32',
        'week': 'int16',
        'leap_s': 'int8',
        'valid': 'uint8',
        't_acc': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.f_tow = kwargs.get('f_tow', int())
        self.week = kwargs.get('week', int())
        self.leap_s = kwargs.get('leap_s', int())
        self.valid = kwargs.get('valid', int())
        self.t_acc = kwargs.get('t_acc', int())

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
        if self.f_tow != other.f_tow:
            return False
        if self.week != other.week:
            return False
        if self.leap_s != other.leap_s:
            return False
        if self.valid != other.valid:
            return False
        if self.t_acc != other.t_acc:
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
    def f_tow(self):
        """Message field 'f_tow'."""
        return self._f_tow

    @f_tow.setter
    def f_tow(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'f_tow' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'f_tow' field must be an integer in [-2147483648, 2147483647]"
        self._f_tow = value

    @builtins.property
    def week(self):
        """Message field 'week'."""
        return self._week

    @week.setter
    def week(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'week' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'week' field must be an integer in [-32768, 32767]"
        self._week = value

    @builtins.property
    def leap_s(self):
        """Message field 'leap_s'."""
        return self._leap_s

    @leap_s.setter
    def leap_s(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'leap_s' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'leap_s' field must be an integer in [-128, 127]"
        self._leap_s = value

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
    def t_acc(self):
        """Message field 't_acc'."""
        return self._t_acc

    @t_acc.setter
    def t_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 't_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 't_acc' field must be an unsigned integer in [0, 4294967295]"
        self._t_acc = value
