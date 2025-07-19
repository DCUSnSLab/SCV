# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSOL.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSOL(type):
    """Metaclass of message 'NavSOL'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 6,
        'GPS_NO_FIX': 0,
        'GPS_DEAD_RECKONING_ONLY': 1,
        'GPS_2D_FIX': 2,
        'GPS_3D_FIX': 3,
        'GPS_GPS_DEAD_RECKONING_COMBINED': 4,
        'GPS_TIME_ONLY_FIX': 5,
        'FLAGS_GPS_FIX_OK': 1,
        'FLAGS_DIFF_SOLN': 2,
        'FLAGS_WKNSET': 4,
        'FLAGS_TOWSET': 8,
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
                'ublox_msgs.msg.NavSOL')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_sol
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_sol
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_sol
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_sol
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_sol

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'GPS_NO_FIX': cls.__constants['GPS_NO_FIX'],
            'GPS_DEAD_RECKONING_ONLY': cls.__constants['GPS_DEAD_RECKONING_ONLY'],
            'GPS_2D_FIX': cls.__constants['GPS_2D_FIX'],
            'GPS_3D_FIX': cls.__constants['GPS_3D_FIX'],
            'GPS_GPS_DEAD_RECKONING_COMBINED': cls.__constants['GPS_GPS_DEAD_RECKONING_COMBINED'],
            'GPS_TIME_ONLY_FIX': cls.__constants['GPS_TIME_ONLY_FIX'],
            'FLAGS_GPS_FIX_OK': cls.__constants['FLAGS_GPS_FIX_OK'],
            'FLAGS_DIFF_SOLN': cls.__constants['FLAGS_DIFF_SOLN'],
            'FLAGS_WKNSET': cls.__constants['FLAGS_WKNSET'],
            'FLAGS_TOWSET': cls.__constants['FLAGS_TOWSET'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavSOL.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavSOL.__constants['MESSAGE_ID']

    @property
    def GPS_NO_FIX(self):
        """Message constant 'GPS_NO_FIX'."""
        return Metaclass_NavSOL.__constants['GPS_NO_FIX']

    @property
    def GPS_DEAD_RECKONING_ONLY(self):
        """Message constant 'GPS_DEAD_RECKONING_ONLY'."""
        return Metaclass_NavSOL.__constants['GPS_DEAD_RECKONING_ONLY']

    @property
    def GPS_2D_FIX(self):
        """Message constant 'GPS_2D_FIX'."""
        return Metaclass_NavSOL.__constants['GPS_2D_FIX']

    @property
    def GPS_3D_FIX(self):
        """Message constant 'GPS_3D_FIX'."""
        return Metaclass_NavSOL.__constants['GPS_3D_FIX']

    @property
    def GPS_GPS_DEAD_RECKONING_COMBINED(self):
        """Message constant 'GPS_GPS_DEAD_RECKONING_COMBINED'."""
        return Metaclass_NavSOL.__constants['GPS_GPS_DEAD_RECKONING_COMBINED']

    @property
    def GPS_TIME_ONLY_FIX(self):
        """Message constant 'GPS_TIME_ONLY_FIX'."""
        return Metaclass_NavSOL.__constants['GPS_TIME_ONLY_FIX']

    @property
    def FLAGS_GPS_FIX_OK(self):
        """Message constant 'FLAGS_GPS_FIX_OK'."""
        return Metaclass_NavSOL.__constants['FLAGS_GPS_FIX_OK']

    @property
    def FLAGS_DIFF_SOLN(self):
        """Message constant 'FLAGS_DIFF_SOLN'."""
        return Metaclass_NavSOL.__constants['FLAGS_DIFF_SOLN']

    @property
    def FLAGS_WKNSET(self):
        """Message constant 'FLAGS_WKNSET'."""
        return Metaclass_NavSOL.__constants['FLAGS_WKNSET']

    @property
    def FLAGS_TOWSET(self):
        """Message constant 'FLAGS_TOWSET'."""
        return Metaclass_NavSOL.__constants['FLAGS_TOWSET']


class NavSOL(metaclass=Metaclass_NavSOL):
    """
    Message class 'NavSOL'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      GPS_NO_FIX
      GPS_DEAD_RECKONING_ONLY
      GPS_2D_FIX
      GPS_3D_FIX
      GPS_GPS_DEAD_RECKONING_COMBINED
      GPS_TIME_ONLY_FIX
      FLAGS_GPS_FIX_OK
      FLAGS_DIFF_SOLN
      FLAGS_WKNSET
      FLAGS_TOWSET
    """

    __slots__ = [
        '_i_tow',
        '_f_tow',
        '_week',
        '_gps_fix',
        '_flags',
        '_ecef_x',
        '_ecef_y',
        '_ecef_z',
        '_p_acc',
        '_ecef_vx',
        '_ecef_vy',
        '_ecef_vz',
        '_s_acc',
        '_p_dop',
        '_reserved1',
        '_num_sv',
        '_reserved2',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'f_tow': 'int32',
        'week': 'int16',
        'gps_fix': 'uint8',
        'flags': 'uint8',
        'ecef_x': 'int32',
        'ecef_y': 'int32',
        'ecef_z': 'int32',
        'p_acc': 'uint32',
        'ecef_vx': 'int32',
        'ecef_vy': 'int32',
        'ecef_vz': 'int32',
        's_acc': 'uint32',
        'p_dop': 'uint16',
        'reserved1': 'uint8',
        'num_sv': 'uint8',
        'reserved2': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
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
        self.gps_fix = kwargs.get('gps_fix', int())
        self.flags = kwargs.get('flags', int())
        self.ecef_x = kwargs.get('ecef_x', int())
        self.ecef_y = kwargs.get('ecef_y', int())
        self.ecef_z = kwargs.get('ecef_z', int())
        self.p_acc = kwargs.get('p_acc', int())
        self.ecef_vx = kwargs.get('ecef_vx', int())
        self.ecef_vy = kwargs.get('ecef_vy', int())
        self.ecef_vz = kwargs.get('ecef_vz', int())
        self.s_acc = kwargs.get('s_acc', int())
        self.p_dop = kwargs.get('p_dop', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.num_sv = kwargs.get('num_sv', int())
        self.reserved2 = kwargs.get('reserved2', int())

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
        if self.gps_fix != other.gps_fix:
            return False
        if self.flags != other.flags:
            return False
        if self.ecef_x != other.ecef_x:
            return False
        if self.ecef_y != other.ecef_y:
            return False
        if self.ecef_z != other.ecef_z:
            return False
        if self.p_acc != other.p_acc:
            return False
        if self.ecef_vx != other.ecef_vx:
            return False
        if self.ecef_vy != other.ecef_vy:
            return False
        if self.ecef_vz != other.ecef_vz:
            return False
        if self.s_acc != other.s_acc:
            return False
        if self.p_dop != other.p_dop:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.reserved2 != other.reserved2:
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
    def gps_fix(self):
        """Message field 'gps_fix'."""
        return self._gps_fix

    @gps_fix.setter
    def gps_fix(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gps_fix' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gps_fix' field must be an unsigned integer in [0, 255]"
        self._gps_fix = value

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
    def ecef_x(self):
        """Message field 'ecef_x'."""
        return self._ecef_x

    @ecef_x.setter
    def ecef_x(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_x' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_x' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_x = value

    @builtins.property
    def ecef_y(self):
        """Message field 'ecef_y'."""
        return self._ecef_y

    @ecef_y.setter
    def ecef_y(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_y' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_y' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_y = value

    @builtins.property
    def ecef_z(self):
        """Message field 'ecef_z'."""
        return self._ecef_z

    @ecef_z.setter
    def ecef_z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_z' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_z' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_z = value

    @builtins.property
    def p_acc(self):
        """Message field 'p_acc'."""
        return self._p_acc

    @p_acc.setter
    def p_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'p_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'p_acc' field must be an unsigned integer in [0, 4294967295]"
        self._p_acc = value

    @builtins.property
    def ecef_vx(self):
        """Message field 'ecef_vx'."""
        return self._ecef_vx

    @ecef_vx.setter
    def ecef_vx(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vx' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vx' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vx = value

    @builtins.property
    def ecef_vy(self):
        """Message field 'ecef_vy'."""
        return self._ecef_vy

    @ecef_vy.setter
    def ecef_vy(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vy' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vy' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vy = value

    @builtins.property
    def ecef_vz(self):
        """Message field 'ecef_vz'."""
        return self._ecef_vz

    @ecef_vz.setter
    def ecef_vz(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_vz' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_vz' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_vz = value

    @builtins.property
    def s_acc(self):
        """Message field 's_acc'."""
        return self._s_acc

    @s_acc.setter
    def s_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 's_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 's_acc' field must be an unsigned integer in [0, 4294967295]"
        self._s_acc = value

    @builtins.property
    def p_dop(self):
        """Message field 'p_dop'."""
        return self._p_dop

    @p_dop.setter
    def p_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'p_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'p_dop' field must be an unsigned integer in [0, 65535]"
        self._p_dop = value

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
    def num_sv(self):
        """Message field 'num_sv'."""
        return self._num_sv

    @num_sv.setter
    def num_sv(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'num_sv' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'num_sv' field must be an unsigned integer in [0, 255]"
        self._num_sv = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved2' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'reserved2' field must be an unsigned integer in [0, 4294967295]"
        self._reserved2 = value
