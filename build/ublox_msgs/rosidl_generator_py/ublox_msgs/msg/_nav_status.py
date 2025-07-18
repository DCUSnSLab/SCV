# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSTATUS.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSTATUS(type):
    """Metaclass of message 'NavSTATUS'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 3,
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
        'FIX_STAT_DIFF_CORR_MASK': 1,
        'FIX_STAT_MAP_MATCHING_MASK': 192,
        'MAP_MATCHING_NONE': 0,
        'MAP_MATCHING_VALID': 64,
        'MAP_MATCHING_USED': 128,
        'MAP_MATCHING_DR': 192,
        'FLAGS2_PSM_STATE_MASK': 3,
        'PSM_STATE_ACQUISITION': 0,
        'PSM_STATE_TRACKING': 1,
        'PSM_STATE_POWER_OPTIMIZED_TRACKING': 2,
        'PSM_STATE_INACTIVE': 3,
        'FLAGS2_SPOOF_DET_STATE_MASK': 24,
        'SPOOF_DET_STATE_UNKNOWN': 0,
        'SPOOF_DET_STATE_NONE': 8,
        'SPOOF_DET_STATE_SPOOFING': 16,
        'SPOOF_DET_STATE_MULTIPLE': 24,
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
                'ublox_msgs.msg.NavSTATUS')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_status
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_status
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_status
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_status
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_status

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
            'FIX_STAT_DIFF_CORR_MASK': cls.__constants['FIX_STAT_DIFF_CORR_MASK'],
            'FIX_STAT_MAP_MATCHING_MASK': cls.__constants['FIX_STAT_MAP_MATCHING_MASK'],
            'MAP_MATCHING_NONE': cls.__constants['MAP_MATCHING_NONE'],
            'MAP_MATCHING_VALID': cls.__constants['MAP_MATCHING_VALID'],
            'MAP_MATCHING_USED': cls.__constants['MAP_MATCHING_USED'],
            'MAP_MATCHING_DR': cls.__constants['MAP_MATCHING_DR'],
            'FLAGS2_PSM_STATE_MASK': cls.__constants['FLAGS2_PSM_STATE_MASK'],
            'PSM_STATE_ACQUISITION': cls.__constants['PSM_STATE_ACQUISITION'],
            'PSM_STATE_TRACKING': cls.__constants['PSM_STATE_TRACKING'],
            'PSM_STATE_POWER_OPTIMIZED_TRACKING': cls.__constants['PSM_STATE_POWER_OPTIMIZED_TRACKING'],
            'PSM_STATE_INACTIVE': cls.__constants['PSM_STATE_INACTIVE'],
            'FLAGS2_SPOOF_DET_STATE_MASK': cls.__constants['FLAGS2_SPOOF_DET_STATE_MASK'],
            'SPOOF_DET_STATE_UNKNOWN': cls.__constants['SPOOF_DET_STATE_UNKNOWN'],
            'SPOOF_DET_STATE_NONE': cls.__constants['SPOOF_DET_STATE_NONE'],
            'SPOOF_DET_STATE_SPOOFING': cls.__constants['SPOOF_DET_STATE_SPOOFING'],
            'SPOOF_DET_STATE_MULTIPLE': cls.__constants['SPOOF_DET_STATE_MULTIPLE'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavSTATUS.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavSTATUS.__constants['MESSAGE_ID']

    @property
    def GPS_NO_FIX(self):
        """Message constant 'GPS_NO_FIX'."""
        return Metaclass_NavSTATUS.__constants['GPS_NO_FIX']

    @property
    def GPS_DEAD_RECKONING_ONLY(self):
        """Message constant 'GPS_DEAD_RECKONING_ONLY'."""
        return Metaclass_NavSTATUS.__constants['GPS_DEAD_RECKONING_ONLY']

    @property
    def GPS_2D_FIX(self):
        """Message constant 'GPS_2D_FIX'."""
        return Metaclass_NavSTATUS.__constants['GPS_2D_FIX']

    @property
    def GPS_3D_FIX(self):
        """Message constant 'GPS_3D_FIX'."""
        return Metaclass_NavSTATUS.__constants['GPS_3D_FIX']

    @property
    def GPS_GPS_DEAD_RECKONING_COMBINED(self):
        """Message constant 'GPS_GPS_DEAD_RECKONING_COMBINED'."""
        return Metaclass_NavSTATUS.__constants['GPS_GPS_DEAD_RECKONING_COMBINED']

    @property
    def GPS_TIME_ONLY_FIX(self):
        """Message constant 'GPS_TIME_ONLY_FIX'."""
        return Metaclass_NavSTATUS.__constants['GPS_TIME_ONLY_FIX']

    @property
    def FLAGS_GPS_FIX_OK(self):
        """Message constant 'FLAGS_GPS_FIX_OK'."""
        return Metaclass_NavSTATUS.__constants['FLAGS_GPS_FIX_OK']

    @property
    def FLAGS_DIFF_SOLN(self):
        """Message constant 'FLAGS_DIFF_SOLN'."""
        return Metaclass_NavSTATUS.__constants['FLAGS_DIFF_SOLN']

    @property
    def FLAGS_WKNSET(self):
        """Message constant 'FLAGS_WKNSET'."""
        return Metaclass_NavSTATUS.__constants['FLAGS_WKNSET']

    @property
    def FLAGS_TOWSET(self):
        """Message constant 'FLAGS_TOWSET'."""
        return Metaclass_NavSTATUS.__constants['FLAGS_TOWSET']

    @property
    def FIX_STAT_DIFF_CORR_MASK(self):
        """Message constant 'FIX_STAT_DIFF_CORR_MASK'."""
        return Metaclass_NavSTATUS.__constants['FIX_STAT_DIFF_CORR_MASK']

    @property
    def FIX_STAT_MAP_MATCHING_MASK(self):
        """Message constant 'FIX_STAT_MAP_MATCHING_MASK'."""
        return Metaclass_NavSTATUS.__constants['FIX_STAT_MAP_MATCHING_MASK']

    @property
    def MAP_MATCHING_NONE(self):
        """Message constant 'MAP_MATCHING_NONE'."""
        return Metaclass_NavSTATUS.__constants['MAP_MATCHING_NONE']

    @property
    def MAP_MATCHING_VALID(self):
        """Message constant 'MAP_MATCHING_VALID'."""
        return Metaclass_NavSTATUS.__constants['MAP_MATCHING_VALID']

    @property
    def MAP_MATCHING_USED(self):
        """Message constant 'MAP_MATCHING_USED'."""
        return Metaclass_NavSTATUS.__constants['MAP_MATCHING_USED']

    @property
    def MAP_MATCHING_DR(self):
        """Message constant 'MAP_MATCHING_DR'."""
        return Metaclass_NavSTATUS.__constants['MAP_MATCHING_DR']

    @property
    def FLAGS2_PSM_STATE_MASK(self):
        """Message constant 'FLAGS2_PSM_STATE_MASK'."""
        return Metaclass_NavSTATUS.__constants['FLAGS2_PSM_STATE_MASK']

    @property
    def PSM_STATE_ACQUISITION(self):
        """Message constant 'PSM_STATE_ACQUISITION'."""
        return Metaclass_NavSTATUS.__constants['PSM_STATE_ACQUISITION']

    @property
    def PSM_STATE_TRACKING(self):
        """Message constant 'PSM_STATE_TRACKING'."""
        return Metaclass_NavSTATUS.__constants['PSM_STATE_TRACKING']

    @property
    def PSM_STATE_POWER_OPTIMIZED_TRACKING(self):
        """Message constant 'PSM_STATE_POWER_OPTIMIZED_TRACKING'."""
        return Metaclass_NavSTATUS.__constants['PSM_STATE_POWER_OPTIMIZED_TRACKING']

    @property
    def PSM_STATE_INACTIVE(self):
        """Message constant 'PSM_STATE_INACTIVE'."""
        return Metaclass_NavSTATUS.__constants['PSM_STATE_INACTIVE']

    @property
    def FLAGS2_SPOOF_DET_STATE_MASK(self):
        """Message constant 'FLAGS2_SPOOF_DET_STATE_MASK'."""
        return Metaclass_NavSTATUS.__constants['FLAGS2_SPOOF_DET_STATE_MASK']

    @property
    def SPOOF_DET_STATE_UNKNOWN(self):
        """Message constant 'SPOOF_DET_STATE_UNKNOWN'."""
        return Metaclass_NavSTATUS.__constants['SPOOF_DET_STATE_UNKNOWN']

    @property
    def SPOOF_DET_STATE_NONE(self):
        """Message constant 'SPOOF_DET_STATE_NONE'."""
        return Metaclass_NavSTATUS.__constants['SPOOF_DET_STATE_NONE']

    @property
    def SPOOF_DET_STATE_SPOOFING(self):
        """Message constant 'SPOOF_DET_STATE_SPOOFING'."""
        return Metaclass_NavSTATUS.__constants['SPOOF_DET_STATE_SPOOFING']

    @property
    def SPOOF_DET_STATE_MULTIPLE(self):
        """Message constant 'SPOOF_DET_STATE_MULTIPLE'."""
        return Metaclass_NavSTATUS.__constants['SPOOF_DET_STATE_MULTIPLE']


class NavSTATUS(metaclass=Metaclass_NavSTATUS):
    """
    Message class 'NavSTATUS'.

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
      FIX_STAT_DIFF_CORR_MASK
      FIX_STAT_MAP_MATCHING_MASK
      MAP_MATCHING_NONE
      MAP_MATCHING_VALID
      MAP_MATCHING_USED
      MAP_MATCHING_DR
      FLAGS2_PSM_STATE_MASK
      PSM_STATE_ACQUISITION
      PSM_STATE_TRACKING
      PSM_STATE_POWER_OPTIMIZED_TRACKING
      PSM_STATE_INACTIVE
      FLAGS2_SPOOF_DET_STATE_MASK
      SPOOF_DET_STATE_UNKNOWN
      SPOOF_DET_STATE_NONE
      SPOOF_DET_STATE_SPOOFING
      SPOOF_DET_STATE_MULTIPLE
    """

    __slots__ = [
        '_i_tow',
        '_gps_fix',
        '_flags',
        '_fix_stat',
        '_flags2',
        '_ttff',
        '_msss',
    ]

    _fields_and_field_types = {
        'i_tow': 'uint32',
        'gps_fix': 'uint8',
        'flags': 'uint8',
        'fix_stat': 'uint8',
        'flags2': 'uint8',
        'ttff': 'uint32',
        'msss': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.i_tow = kwargs.get('i_tow', int())
        self.gps_fix = kwargs.get('gps_fix', int())
        self.flags = kwargs.get('flags', int())
        self.fix_stat = kwargs.get('fix_stat', int())
        self.flags2 = kwargs.get('flags2', int())
        self.ttff = kwargs.get('ttff', int())
        self.msss = kwargs.get('msss', int())

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
        if self.gps_fix != other.gps_fix:
            return False
        if self.flags != other.flags:
            return False
        if self.fix_stat != other.fix_stat:
            return False
        if self.flags2 != other.flags2:
            return False
        if self.ttff != other.ttff:
            return False
        if self.msss != other.msss:
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
    def fix_stat(self):
        """Message field 'fix_stat'."""
        return self._fix_stat

    @fix_stat.setter
    def fix_stat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fix_stat' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fix_stat' field must be an unsigned integer in [0, 255]"
        self._fix_stat = value

    @builtins.property
    def flags2(self):
        """Message field 'flags2'."""
        return self._flags2

    @flags2.setter
    def flags2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'flags2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'flags2' field must be an unsigned integer in [0, 255]"
        self._flags2 = value

    @builtins.property
    def ttff(self):
        """Message field 'ttff'."""
        return self._ttff

    @ttff.setter
    def ttff(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ttff' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'ttff' field must be an unsigned integer in [0, 4294967295]"
        self._ttff = value

    @builtins.property
    def msss(self):
        """Message field 'msss'."""
        return self._msss

    @msss.setter
    def msss(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'msss' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'msss' field must be an unsigned integer in [0, 4294967295]"
        self._msss = value
