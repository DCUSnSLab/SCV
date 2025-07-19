# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavTIMEUTC.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavTIMEUTC(type):
    """Metaclass of message 'NavTIMEUTC'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 33,
        'VALID_TOW': 1,
        'VALID_WKN': 2,
        'VALID_UTC': 4,
        'VALID_UTC_STANDARD_MASK': 240,
        'UTC_STANDARD_NOT_AVAILABLE': 0,
        'UTC_STANDARD_CRL': 16,
        'UTC_STANDARD_NIST': 32,
        'UTC_STANDARD_USNO': 48,
        'UTC_STANDARD_BIPM': 64,
        'UTC_STANDARD_EL': 80,
        'UTC_STANDARD_SU': 96,
        'UTC_STANDARD_NTSC': 112,
        'UTC_STANDARD_UNKNOWN': 240,
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
                'ublox_msgs.msg.NavTIMEUTC')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_timeutc
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_timeutc
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_timeutc
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_timeutc
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_timeutc

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'VALID_TOW': cls.__constants['VALID_TOW'],
            'VALID_WKN': cls.__constants['VALID_WKN'],
            'VALID_UTC': cls.__constants['VALID_UTC'],
            'VALID_UTC_STANDARD_MASK': cls.__constants['VALID_UTC_STANDARD_MASK'],
            'UTC_STANDARD_NOT_AVAILABLE': cls.__constants['UTC_STANDARD_NOT_AVAILABLE'],
            'UTC_STANDARD_CRL': cls.__constants['UTC_STANDARD_CRL'],
            'UTC_STANDARD_NIST': cls.__constants['UTC_STANDARD_NIST'],
            'UTC_STANDARD_USNO': cls.__constants['UTC_STANDARD_USNO'],
            'UTC_STANDARD_BIPM': cls.__constants['UTC_STANDARD_BIPM'],
            'UTC_STANDARD_EL': cls.__constants['UTC_STANDARD_EL'],
            'UTC_STANDARD_SU': cls.__constants['UTC_STANDARD_SU'],
            'UTC_STANDARD_NTSC': cls.__constants['UTC_STANDARD_NTSC'],
            'UTC_STANDARD_UNKNOWN': cls.__constants['UTC_STANDARD_UNKNOWN'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavTIMEUTC.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavTIMEUTC.__constants['MESSAGE_ID']

    @property
    def VALID_TOW(self):
        """Message constant 'VALID_TOW'."""
        return Metaclass_NavTIMEUTC.__constants['VALID_TOW']

    @property
    def VALID_WKN(self):
        """Message constant 'VALID_WKN'."""
        return Metaclass_NavTIMEUTC.__constants['VALID_WKN']

    @property
    def VALID_UTC(self):
        """Message constant 'VALID_UTC'."""
        return Metaclass_NavTIMEUTC.__constants['VALID_UTC']

    @property
    def VALID_UTC_STANDARD_MASK(self):
        """Message constant 'VALID_UTC_STANDARD_MASK'."""
        return Metaclass_NavTIMEUTC.__constants['VALID_UTC_STANDARD_MASK']

    @property
    def UTC_STANDARD_NOT_AVAILABLE(self):
        """Message constant 'UTC_STANDARD_NOT_AVAILABLE'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_NOT_AVAILABLE']

    @property
    def UTC_STANDARD_CRL(self):
        """Message constant 'UTC_STANDARD_CRL'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_CRL']

    @property
    def UTC_STANDARD_NIST(self):
        """Message constant 'UTC_STANDARD_NIST'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_NIST']

    @property
    def UTC_STANDARD_USNO(self):
        """Message constant 'UTC_STANDARD_USNO'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_USNO']

    @property
    def UTC_STANDARD_BIPM(self):
        """Message constant 'UTC_STANDARD_BIPM'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_BIPM']

    @property
    def UTC_STANDARD_EL(self):
        """Message constant 'UTC_STANDARD_EL'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_EL']

    @property
    def UTC_STANDARD_SU(self):
        """Message constant 'UTC_STANDARD_SU'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_SU']

    @property
    def UTC_STANDARD_NTSC(self):
        """Message constant 'UTC_STANDARD_NTSC'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_NTSC']

    @property
    def UTC_STANDARD_UNKNOWN(self):
        """Message constant 'UTC_STANDARD_UNKNOWN'."""
        return Metaclass_NavTIMEUTC.__constants['UTC_STANDARD_UNKNOWN']


class NavTIMEUTC(metaclass=Metaclass_NavTIMEUTC):
    """
    Message class 'NavTIMEUTC'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      VALID_TOW
      VALID_WKN
      VALID_UTC
      VALID_UTC_STANDARD_MASK
      UTC_STANDARD_NOT_AVAILABLE
      UTC_STANDARD_CRL
      UTC_STANDARD_NIST
      UTC_STANDARD_USNO
      UTC_STANDARD_BIPM
      UTC_STANDARD_EL
      UTC_STANDARD_SU
      UTC_STANDARD_NTSC
      UTC_STANDARD_UNKNOWN
    """

    __slots__ = [
        '_i_tow',
        '_t_acc',
        '_nano',
        '_year',
        '_month',
        '_day',
        '_hour',
        '_min',
        '_sec',
        '_valid',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        't_acc': 'uint32',
        'nano': 'int32',
        'year': 'uint16',
        'month': 'uint8',
        'day': 'uint8',
        'hour': 'uint8',
        'min': 'uint8',
        'sec': 'uint8',
        'valid': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.t_acc = kwargs.get('t_acc', int())
        self.nano = kwargs.get('nano', int())
        self.year = kwargs.get('year', int())
        self.month = kwargs.get('month', int())
        self.day = kwargs.get('day', int())
        self.hour = kwargs.get('hour', int())
        self.min = kwargs.get('min', int())
        self.sec = kwargs.get('sec', int())
        self.valid = kwargs.get('valid', int())

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
        if self.t_acc != other.t_acc:
            return False
        if self.nano != other.nano:
            return False
        if self.year != other.year:
            return False
        if self.month != other.month:
            return False
        if self.day != other.day:
            return False
        if self.hour != other.hour:
            return False
        if self.min != other.min:
            return False
        if self.sec != other.sec:
            return False
        if self.valid != other.valid:
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

    @builtins.property
    def nano(self):
        """Message field 'nano'."""
        return self._nano

    @nano.setter
    def nano(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nano' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'nano' field must be an integer in [-2147483648, 2147483647]"
        self._nano = value

    @builtins.property
    def year(self):
        """Message field 'year'."""
        return self._year

    @year.setter
    def year(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'year' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'year' field must be an unsigned integer in [0, 65535]"
        self._year = value

    @builtins.property
    def month(self):
        """Message field 'month'."""
        return self._month

    @month.setter
    def month(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'month' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'month' field must be an unsigned integer in [0, 255]"
        self._month = value

    @builtins.property
    def day(self):
        """Message field 'day'."""
        return self._day

    @day.setter
    def day(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'day' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'day' field must be an unsigned integer in [0, 255]"
        self._day = value

    @builtins.property
    def hour(self):
        """Message field 'hour'."""
        return self._hour

    @hour.setter
    def hour(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'hour' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'hour' field must be an unsigned integer in [0, 255]"
        self._hour = value

    @builtins.property  # noqa: A003
    def min(self):  # noqa: A003
        """Message field 'min'."""
        return self._min

    @min.setter  # noqa: A003
    def min(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'min' field must be an unsigned integer in [0, 255]"
        self._min = value

    @builtins.property
    def sec(self):
        """Message field 'sec'."""
        return self._sec

    @sec.setter
    def sec(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sec' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sec' field must be an unsigned integer in [0, 255]"
        self._sec = value

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
