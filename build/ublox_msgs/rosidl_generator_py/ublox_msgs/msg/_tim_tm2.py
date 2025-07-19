# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/TimTM2.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TimTM2(type):
    """Metaclass of message 'TimTM2'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 13,
        'MESSAGE_ID': 3,
        'FLAGS_MODE_RUNNING': 1,
        'FLAGS_RUN': 2,
        'FLAGS_NEWFALLINGEDGE': 4,
        'FLAGS_TIMEBASE_GNSS': 8,
        'FLAGS_TIMEBASE_UTC': 16,
        'FLAGS_UTC_AVAIL': 32,
        'FLAGS_TIME_VALID': 64,
        'FLAGS_NEWRISINGEDGE': 128,
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
                'ublox_msgs.msg.TimTM2')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__tim_tm2
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__tim_tm2
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__tim_tm2
            cls._TYPE_SUPPORT = module.type_support_msg__msg__tim_tm2
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__tim_tm2

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_MODE_RUNNING': cls.__constants['FLAGS_MODE_RUNNING'],
            'FLAGS_RUN': cls.__constants['FLAGS_RUN'],
            'FLAGS_NEWFALLINGEDGE': cls.__constants['FLAGS_NEWFALLINGEDGE'],
            'FLAGS_TIMEBASE_GNSS': cls.__constants['FLAGS_TIMEBASE_GNSS'],
            'FLAGS_TIMEBASE_UTC': cls.__constants['FLAGS_TIMEBASE_UTC'],
            'FLAGS_UTC_AVAIL': cls.__constants['FLAGS_UTC_AVAIL'],
            'FLAGS_TIME_VALID': cls.__constants['FLAGS_TIME_VALID'],
            'FLAGS_NEWRISINGEDGE': cls.__constants['FLAGS_NEWRISINGEDGE'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_TimTM2.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_TimTM2.__constants['MESSAGE_ID']

    @property
    def FLAGS_MODE_RUNNING(self):
        """Message constant 'FLAGS_MODE_RUNNING'."""
        return Metaclass_TimTM2.__constants['FLAGS_MODE_RUNNING']

    @property
    def FLAGS_RUN(self):
        """Message constant 'FLAGS_RUN'."""
        return Metaclass_TimTM2.__constants['FLAGS_RUN']

    @property
    def FLAGS_NEWFALLINGEDGE(self):
        """Message constant 'FLAGS_NEWFALLINGEDGE'."""
        return Metaclass_TimTM2.__constants['FLAGS_NEWFALLINGEDGE']

    @property
    def FLAGS_TIMEBASE_GNSS(self):
        """Message constant 'FLAGS_TIMEBASE_GNSS'."""
        return Metaclass_TimTM2.__constants['FLAGS_TIMEBASE_GNSS']

    @property
    def FLAGS_TIMEBASE_UTC(self):
        """Message constant 'FLAGS_TIMEBASE_UTC'."""
        return Metaclass_TimTM2.__constants['FLAGS_TIMEBASE_UTC']

    @property
    def FLAGS_UTC_AVAIL(self):
        """Message constant 'FLAGS_UTC_AVAIL'."""
        return Metaclass_TimTM2.__constants['FLAGS_UTC_AVAIL']

    @property
    def FLAGS_TIME_VALID(self):
        """Message constant 'FLAGS_TIME_VALID'."""
        return Metaclass_TimTM2.__constants['FLAGS_TIME_VALID']

    @property
    def FLAGS_NEWRISINGEDGE(self):
        """Message constant 'FLAGS_NEWRISINGEDGE'."""
        return Metaclass_TimTM2.__constants['FLAGS_NEWRISINGEDGE']


class TimTM2(metaclass=Metaclass_TimTM2):
    """
    Message class 'TimTM2'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_MODE_RUNNING
      FLAGS_RUN
      FLAGS_NEWFALLINGEDGE
      FLAGS_TIMEBASE_GNSS
      FLAGS_TIMEBASE_UTC
      FLAGS_UTC_AVAIL
      FLAGS_TIME_VALID
      FLAGS_NEWRISINGEDGE
    """

    __slots__ = [
        '_ch',
        '_flags',
        '_rising_edge_count',
        '_wn_r',
        '_wn_f',
        '_tow_ms_r',
        '_tow_sub_ms_r',
        '_tow_ms_f',
        '_tow_sub_ms_f',
        '_acc_est',
    ]

    _fields_and_field_types = {
        'ch': 'uint8',
        'flags': 'uint8',
        'rising_edge_count': 'uint16',
        'wn_r': 'uint16',
        'wn_f': 'uint16',
        'tow_ms_r': 'uint32',
        'tow_sub_ms_r': 'uint32',
        'tow_ms_f': 'uint32',
        'tow_sub_ms_f': 'uint32',
        'acc_est': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.ch = kwargs.get('ch', int())
        self.flags = kwargs.get('flags', int())
        self.rising_edge_count = kwargs.get('rising_edge_count', int())
        self.wn_r = kwargs.get('wn_r', int())
        self.wn_f = kwargs.get('wn_f', int())
        self.tow_ms_r = kwargs.get('tow_ms_r', int())
        self.tow_sub_ms_r = kwargs.get('tow_sub_ms_r', int())
        self.tow_ms_f = kwargs.get('tow_ms_f', int())
        self.tow_sub_ms_f = kwargs.get('tow_sub_ms_f', int())
        self.acc_est = kwargs.get('acc_est', int())

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
        if self.ch != other.ch:
            return False
        if self.flags != other.flags:
            return False
        if self.rising_edge_count != other.rising_edge_count:
            return False
        if self.wn_r != other.wn_r:
            return False
        if self.wn_f != other.wn_f:
            return False
        if self.tow_ms_r != other.tow_ms_r:
            return False
        if self.tow_sub_ms_r != other.tow_sub_ms_r:
            return False
        if self.tow_ms_f != other.tow_ms_f:
            return False
        if self.tow_sub_ms_f != other.tow_sub_ms_f:
            return False
        if self.acc_est != other.acc_est:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def ch(self):
        """Message field 'ch'."""
        return self._ch

    @ch.setter
    def ch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ch' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ch' field must be an unsigned integer in [0, 255]"
        self._ch = value

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
    def rising_edge_count(self):
        """Message field 'rising_edge_count'."""
        return self._rising_edge_count

    @rising_edge_count.setter
    def rising_edge_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'rising_edge_count' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'rising_edge_count' field must be an unsigned integer in [0, 65535]"
        self._rising_edge_count = value

    @builtins.property
    def wn_r(self):
        """Message field 'wn_r'."""
        return self._wn_r

    @wn_r.setter
    def wn_r(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wn_r' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'wn_r' field must be an unsigned integer in [0, 65535]"
        self._wn_r = value

    @builtins.property
    def wn_f(self):
        """Message field 'wn_f'."""
        return self._wn_f

    @wn_f.setter
    def wn_f(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wn_f' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'wn_f' field must be an unsigned integer in [0, 65535]"
        self._wn_f = value

    @builtins.property
    def tow_ms_r(self):
        """Message field 'tow_ms_r'."""
        return self._tow_ms_r

    @tow_ms_r.setter
    def tow_ms_r(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tow_ms_r' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tow_ms_r' field must be an unsigned integer in [0, 4294967295]"
        self._tow_ms_r = value

    @builtins.property
    def tow_sub_ms_r(self):
        """Message field 'tow_sub_ms_r'."""
        return self._tow_sub_ms_r

    @tow_sub_ms_r.setter
    def tow_sub_ms_r(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tow_sub_ms_r' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tow_sub_ms_r' field must be an unsigned integer in [0, 4294967295]"
        self._tow_sub_ms_r = value

    @builtins.property
    def tow_ms_f(self):
        """Message field 'tow_ms_f'."""
        return self._tow_ms_f

    @tow_ms_f.setter
    def tow_ms_f(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tow_ms_f' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tow_ms_f' field must be an unsigned integer in [0, 4294967295]"
        self._tow_ms_f = value

    @builtins.property
    def tow_sub_ms_f(self):
        """Message field 'tow_sub_ms_f'."""
        return self._tow_sub_ms_f

    @tow_sub_ms_f.setter
    def tow_sub_ms_f(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tow_sub_ms_f' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'tow_sub_ms_f' field must be an unsigned integer in [0, 4294967295]"
        self._tow_sub_ms_f = value

    @builtins.property
    def acc_est(self):
        """Message field 'acc_est'."""
        return self._acc_est

    @acc_est.setter
    def acc_est(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acc_est' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'acc_est' field must be an unsigned integer in [0, 4294967295]"
        self._acc_est = value
