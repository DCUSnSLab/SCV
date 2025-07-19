# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/HnrPVT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved0'
# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HnrPVT(type):
    """Metaclass of message 'HnrPVT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 40,
        'MESSAGE_ID': 0,
        'VALID_DATE': 1,
        'VALID_TIME': 2,
        'VALID_FULLY_RESOLVED': 4,
        'VALID_MAG': 8,
        'FIX_TYPE_NO_FIX': 0,
        'FIX_TYPE_DEAD_RECKONING_ONLY': 1,
        'FIX_TYPE_2D': 2,
        'FIX_TYPE_3D': 3,
        'FIX_TYPE_GPS_DEAD_RECKONING_COMBINED': 4,
        'FIX_TYPE_TIME_ONLY': 5,
        'FLAGS_GNSS_FIX_OK': 1,
        'FLAGS_DIFF_SOLN': 2,
        'FLAGS_WKN_SET': 4,
        'FLAGS_TOW_SET': 8,
        'FLAGS_HEAD_VEH_VALID': 32,
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
                'ublox_msgs.msg.HnrPVT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__hnr_pvt
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__hnr_pvt
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__hnr_pvt
            cls._TYPE_SUPPORT = module.type_support_msg__msg__hnr_pvt
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__hnr_pvt

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'VALID_DATE': cls.__constants['VALID_DATE'],
            'VALID_TIME': cls.__constants['VALID_TIME'],
            'VALID_FULLY_RESOLVED': cls.__constants['VALID_FULLY_RESOLVED'],
            'VALID_MAG': cls.__constants['VALID_MAG'],
            'FIX_TYPE_NO_FIX': cls.__constants['FIX_TYPE_NO_FIX'],
            'FIX_TYPE_DEAD_RECKONING_ONLY': cls.__constants['FIX_TYPE_DEAD_RECKONING_ONLY'],
            'FIX_TYPE_2D': cls.__constants['FIX_TYPE_2D'],
            'FIX_TYPE_3D': cls.__constants['FIX_TYPE_3D'],
            'FIX_TYPE_GPS_DEAD_RECKONING_COMBINED': cls.__constants['FIX_TYPE_GPS_DEAD_RECKONING_COMBINED'],
            'FIX_TYPE_TIME_ONLY': cls.__constants['FIX_TYPE_TIME_ONLY'],
            'FLAGS_GNSS_FIX_OK': cls.__constants['FLAGS_GNSS_FIX_OK'],
            'FLAGS_DIFF_SOLN': cls.__constants['FLAGS_DIFF_SOLN'],
            'FLAGS_WKN_SET': cls.__constants['FLAGS_WKN_SET'],
            'FLAGS_TOW_SET': cls.__constants['FLAGS_TOW_SET'],
            'FLAGS_HEAD_VEH_VALID': cls.__constants['FLAGS_HEAD_VEH_VALID'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_HnrPVT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_HnrPVT.__constants['MESSAGE_ID']

    @property
    def VALID_DATE(self):
        """Message constant 'VALID_DATE'."""
        return Metaclass_HnrPVT.__constants['VALID_DATE']

    @property
    def VALID_TIME(self):
        """Message constant 'VALID_TIME'."""
        return Metaclass_HnrPVT.__constants['VALID_TIME']

    @property
    def VALID_FULLY_RESOLVED(self):
        """Message constant 'VALID_FULLY_RESOLVED'."""
        return Metaclass_HnrPVT.__constants['VALID_FULLY_RESOLVED']

    @property
    def VALID_MAG(self):
        """Message constant 'VALID_MAG'."""
        return Metaclass_HnrPVT.__constants['VALID_MAG']

    @property
    def FIX_TYPE_NO_FIX(self):
        """Message constant 'FIX_TYPE_NO_FIX'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_NO_FIX']

    @property
    def FIX_TYPE_DEAD_RECKONING_ONLY(self):
        """Message constant 'FIX_TYPE_DEAD_RECKONING_ONLY'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_DEAD_RECKONING_ONLY']

    @property
    def FIX_TYPE_2D(self):
        """Message constant 'FIX_TYPE_2D'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_2D']

    @property
    def FIX_TYPE_3D(self):
        """Message constant 'FIX_TYPE_3D'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_3D']

    @property
    def FIX_TYPE_GPS_DEAD_RECKONING_COMBINED(self):
        """Message constant 'FIX_TYPE_GPS_DEAD_RECKONING_COMBINED'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_GPS_DEAD_RECKONING_COMBINED']

    @property
    def FIX_TYPE_TIME_ONLY(self):
        """Message constant 'FIX_TYPE_TIME_ONLY'."""
        return Metaclass_HnrPVT.__constants['FIX_TYPE_TIME_ONLY']

    @property
    def FLAGS_GNSS_FIX_OK(self):
        """Message constant 'FLAGS_GNSS_FIX_OK'."""
        return Metaclass_HnrPVT.__constants['FLAGS_GNSS_FIX_OK']

    @property
    def FLAGS_DIFF_SOLN(self):
        """Message constant 'FLAGS_DIFF_SOLN'."""
        return Metaclass_HnrPVT.__constants['FLAGS_DIFF_SOLN']

    @property
    def FLAGS_WKN_SET(self):
        """Message constant 'FLAGS_WKN_SET'."""
        return Metaclass_HnrPVT.__constants['FLAGS_WKN_SET']

    @property
    def FLAGS_TOW_SET(self):
        """Message constant 'FLAGS_TOW_SET'."""
        return Metaclass_HnrPVT.__constants['FLAGS_TOW_SET']

    @property
    def FLAGS_HEAD_VEH_VALID(self):
        """Message constant 'FLAGS_HEAD_VEH_VALID'."""
        return Metaclass_HnrPVT.__constants['FLAGS_HEAD_VEH_VALID']


class HnrPVT(metaclass=Metaclass_HnrPVT):
    """
    Message class 'HnrPVT'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      VALID_DATE
      VALID_TIME
      VALID_FULLY_RESOLVED
      VALID_MAG
      FIX_TYPE_NO_FIX
      FIX_TYPE_DEAD_RECKONING_ONLY
      FIX_TYPE_2D
      FIX_TYPE_3D
      FIX_TYPE_GPS_DEAD_RECKONING_COMBINED
      FIX_TYPE_TIME_ONLY
      FLAGS_GNSS_FIX_OK
      FLAGS_DIFF_SOLN
      FLAGS_WKN_SET
      FLAGS_TOW_SET
      FLAGS_HEAD_VEH_VALID
    """

    __slots__ = [
        '_i_tow',
        '_year',
        '_month',
        '_day',
        '_hour',
        '_min',
        '_sec',
        '_valid',
        '_nano',
        '_gps_fix',
        '_flags',
        '_reserved0',
        '_lon',
        '_lat',
        '_height',
        '_h_msl',
        '_g_speed',
        '_speed',
        '_head_mot',
        '_head_veh',
        '_h_acc',
        '_v_acc',
        '_s_acc',
        '_head_acc',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'year': 'uint16',
        'month': 'uint8',
        'day': 'uint8',
        'hour': 'uint8',
        'min': 'uint8',
        'sec': 'uint8',
        'valid': 'uint8',
        'nano': 'int32',
        'gps_fix': 'uint8',
        'flags': 'uint8',
        'reserved0': 'uint8[2]',
        'lon': 'int32',
        'lat': 'int32',
        'height': 'int32',
        'h_msl': 'int32',
        'g_speed': 'int32',
        'speed': 'int32',
        'head_mot': 'int32',
        'head_veh': 'int32',
        'h_acc': 'uint32',
        'v_acc': 'uint32',
        's_acc': 'uint32',
        'head_acc': 'uint32',
        'reserved1': 'uint8[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.year = kwargs.get('year', int())
        self.month = kwargs.get('month', int())
        self.day = kwargs.get('day', int())
        self.hour = kwargs.get('hour', int())
        self.min = kwargs.get('min', int())
        self.sec = kwargs.get('sec', int())
        self.valid = kwargs.get('valid', int())
        self.nano = kwargs.get('nano', int())
        self.gps_fix = kwargs.get('gps_fix', int())
        self.flags = kwargs.get('flags', int())
        if 'reserved0' not in kwargs:
            self.reserved0 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved0 = numpy.array(kwargs.get('reserved0'), dtype=numpy.uint8)
            assert self.reserved0.shape == (2, )
        self.lon = kwargs.get('lon', int())
        self.lat = kwargs.get('lat', int())
        self.height = kwargs.get('height', int())
        self.h_msl = kwargs.get('h_msl', int())
        self.g_speed = kwargs.get('g_speed', int())
        self.speed = kwargs.get('speed', int())
        self.head_mot = kwargs.get('head_mot', int())
        self.head_veh = kwargs.get('head_veh', int())
        self.h_acc = kwargs.get('h_acc', int())
        self.v_acc = kwargs.get('v_acc', int())
        self.s_acc = kwargs.get('s_acc', int())
        self.head_acc = kwargs.get('head_acc', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(4, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (4, )

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
        if self.nano != other.nano:
            return False
        if self.gps_fix != other.gps_fix:
            return False
        if self.flags != other.flags:
            return False
        if all(self.reserved0 != other.reserved0):
            return False
        if self.lon != other.lon:
            return False
        if self.lat != other.lat:
            return False
        if self.height != other.height:
            return False
        if self.h_msl != other.h_msl:
            return False
        if self.g_speed != other.g_speed:
            return False
        if self.speed != other.speed:
            return False
        if self.head_mot != other.head_mot:
            return False
        if self.head_veh != other.head_veh:
            return False
        if self.h_acc != other.h_acc:
            return False
        if self.v_acc != other.v_acc:
            return False
        if self.s_acc != other.s_acc:
            return False
        if self.head_acc != other.head_acc:
            return False
        if all(self.reserved1 != other.reserved1):
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
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved0' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved0' numpy.ndarray() must have a size of 2"
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved0' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved0 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lon' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lon' field must be an integer in [-2147483648, 2147483647]"
        self._lon = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'lat' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'lat' field must be an integer in [-2147483648, 2147483647]"
        self._lat = value

    @builtins.property
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'height' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'height' field must be an integer in [-2147483648, 2147483647]"
        self._height = value

    @builtins.property
    def h_msl(self):
        """Message field 'h_msl'."""
        return self._h_msl

    @h_msl.setter
    def h_msl(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_msl' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'h_msl' field must be an integer in [-2147483648, 2147483647]"
        self._h_msl = value

    @builtins.property
    def g_speed(self):
        """Message field 'g_speed'."""
        return self._g_speed

    @g_speed.setter
    def g_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'g_speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'g_speed' field must be an integer in [-2147483648, 2147483647]"
        self._g_speed = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed' field must be an integer in [-2147483648, 2147483647]"
        self._speed = value

    @builtins.property
    def head_mot(self):
        """Message field 'head_mot'."""
        return self._head_mot

    @head_mot.setter
    def head_mot(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'head_mot' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'head_mot' field must be an integer in [-2147483648, 2147483647]"
        self._head_mot = value

    @builtins.property
    def head_veh(self):
        """Message field 'head_veh'."""
        return self._head_veh

    @head_veh.setter
    def head_veh(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'head_veh' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'head_veh' field must be an integer in [-2147483648, 2147483647]"
        self._head_veh = value

    @builtins.property
    def h_acc(self):
        """Message field 'h_acc'."""
        return self._h_acc

    @h_acc.setter
    def h_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'h_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'h_acc' field must be an unsigned integer in [0, 4294967295]"
        self._h_acc = value

    @builtins.property
    def v_acc(self):
        """Message field 'v_acc'."""
        return self._v_acc

    @v_acc.setter
    def v_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'v_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'v_acc' field must be an unsigned integer in [0, 4294967295]"
        self._v_acc = value

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
    def head_acc(self):
        """Message field 'head_acc'."""
        return self._head_acc

    @head_acc.setter
    def head_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'head_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'head_acc' field must be an unsigned integer in [0, 4294967295]"
        self._head_acc = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 4, \
                "The 'reserved1' numpy.ndarray() must have a size of 4"
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
                 len(value) == 4 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 4 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)
