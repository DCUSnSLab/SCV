# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavPVT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavPVT(type):
    """Metaclass of message 'NavPVT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 1,
        'MESSAGE_ID': 7,
        'VALID_DATE': 1,
        'VALID_TIME': 2,
        'VALID_FULLY_RESOLVED': 4,
        'VALID_MAG': 8,
        'FIX_TYPE_NO_FIX': 0,
        'FIX_TYPE_DEAD_RECKONING_ONLY': 1,
        'FIX_TYPE_2D': 2,
        'FIX_TYPE_3D': 3,
        'FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED': 4,
        'FIX_TYPE_TIME_ONLY': 5,
        'FLAGS_GNSS_FIX_OK': 1,
        'FLAGS_DIFF_SOLN': 2,
        'FLAGS_PSM_MASK': 28,
        'PSM_OFF': 0,
        'PSM_ENABLED': 4,
        'PSM_ACQUIRED': 8,
        'PSM_TRACKING': 12,
        'PSM_POWER_OPTIMIZED_TRACKING': 16,
        'PSM_INACTIVE': 20,
        'FLAGS_HEAD_VEH_VALID': 32,
        'FLAGS_CARRIER_PHASE_MASK': 192,
        'CARRIER_PHASE_NO_SOLUTION': 0,
        'CARRIER_PHASE_FLOAT': 64,
        'CARRIER_PHASE_FIXED': 128,
        'FLAGS2_CONFIRMED_AVAILABLE': 32,
        'FLAGS2_CONFIRMED_DATE': 64,
        'FLAGS2_CONFIRMED_TIME': 128,
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
                'ublox_msgs.msg.NavPVT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_pvt
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_pvt
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_pvt
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_pvt
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_pvt

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
            'FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED': cls.__constants['FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED'],
            'FIX_TYPE_TIME_ONLY': cls.__constants['FIX_TYPE_TIME_ONLY'],
            'FLAGS_GNSS_FIX_OK': cls.__constants['FLAGS_GNSS_FIX_OK'],
            'FLAGS_DIFF_SOLN': cls.__constants['FLAGS_DIFF_SOLN'],
            'FLAGS_PSM_MASK': cls.__constants['FLAGS_PSM_MASK'],
            'PSM_OFF': cls.__constants['PSM_OFF'],
            'PSM_ENABLED': cls.__constants['PSM_ENABLED'],
            'PSM_ACQUIRED': cls.__constants['PSM_ACQUIRED'],
            'PSM_TRACKING': cls.__constants['PSM_TRACKING'],
            'PSM_POWER_OPTIMIZED_TRACKING': cls.__constants['PSM_POWER_OPTIMIZED_TRACKING'],
            'PSM_INACTIVE': cls.__constants['PSM_INACTIVE'],
            'FLAGS_HEAD_VEH_VALID': cls.__constants['FLAGS_HEAD_VEH_VALID'],
            'FLAGS_CARRIER_PHASE_MASK': cls.__constants['FLAGS_CARRIER_PHASE_MASK'],
            'CARRIER_PHASE_NO_SOLUTION': cls.__constants['CARRIER_PHASE_NO_SOLUTION'],
            'CARRIER_PHASE_FLOAT': cls.__constants['CARRIER_PHASE_FLOAT'],
            'CARRIER_PHASE_FIXED': cls.__constants['CARRIER_PHASE_FIXED'],
            'FLAGS2_CONFIRMED_AVAILABLE': cls.__constants['FLAGS2_CONFIRMED_AVAILABLE'],
            'FLAGS2_CONFIRMED_DATE': cls.__constants['FLAGS2_CONFIRMED_DATE'],
            'FLAGS2_CONFIRMED_TIME': cls.__constants['FLAGS2_CONFIRMED_TIME'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_NavPVT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_NavPVT.__constants['MESSAGE_ID']

    @property
    def VALID_DATE(self):
        """Message constant 'VALID_DATE'."""
        return Metaclass_NavPVT.__constants['VALID_DATE']

    @property
    def VALID_TIME(self):
        """Message constant 'VALID_TIME'."""
        return Metaclass_NavPVT.__constants['VALID_TIME']

    @property
    def VALID_FULLY_RESOLVED(self):
        """Message constant 'VALID_FULLY_RESOLVED'."""
        return Metaclass_NavPVT.__constants['VALID_FULLY_RESOLVED']

    @property
    def VALID_MAG(self):
        """Message constant 'VALID_MAG'."""
        return Metaclass_NavPVT.__constants['VALID_MAG']

    @property
    def FIX_TYPE_NO_FIX(self):
        """Message constant 'FIX_TYPE_NO_FIX'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_NO_FIX']

    @property
    def FIX_TYPE_DEAD_RECKONING_ONLY(self):
        """Message constant 'FIX_TYPE_DEAD_RECKONING_ONLY'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_DEAD_RECKONING_ONLY']

    @property
    def FIX_TYPE_2D(self):
        """Message constant 'FIX_TYPE_2D'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_2D']

    @property
    def FIX_TYPE_3D(self):
        """Message constant 'FIX_TYPE_3D'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_3D']

    @property
    def FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED(self):
        """Message constant 'FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED']

    @property
    def FIX_TYPE_TIME_ONLY(self):
        """Message constant 'FIX_TYPE_TIME_ONLY'."""
        return Metaclass_NavPVT.__constants['FIX_TYPE_TIME_ONLY']

    @property
    def FLAGS_GNSS_FIX_OK(self):
        """Message constant 'FLAGS_GNSS_FIX_OK'."""
        return Metaclass_NavPVT.__constants['FLAGS_GNSS_FIX_OK']

    @property
    def FLAGS_DIFF_SOLN(self):
        """Message constant 'FLAGS_DIFF_SOLN'."""
        return Metaclass_NavPVT.__constants['FLAGS_DIFF_SOLN']

    @property
    def FLAGS_PSM_MASK(self):
        """Message constant 'FLAGS_PSM_MASK'."""
        return Metaclass_NavPVT.__constants['FLAGS_PSM_MASK']

    @property
    def PSM_OFF(self):
        """Message constant 'PSM_OFF'."""
        return Metaclass_NavPVT.__constants['PSM_OFF']

    @property
    def PSM_ENABLED(self):
        """Message constant 'PSM_ENABLED'."""
        return Metaclass_NavPVT.__constants['PSM_ENABLED']

    @property
    def PSM_ACQUIRED(self):
        """Message constant 'PSM_ACQUIRED'."""
        return Metaclass_NavPVT.__constants['PSM_ACQUIRED']

    @property
    def PSM_TRACKING(self):
        """Message constant 'PSM_TRACKING'."""
        return Metaclass_NavPVT.__constants['PSM_TRACKING']

    @property
    def PSM_POWER_OPTIMIZED_TRACKING(self):
        """Message constant 'PSM_POWER_OPTIMIZED_TRACKING'."""
        return Metaclass_NavPVT.__constants['PSM_POWER_OPTIMIZED_TRACKING']

    @property
    def PSM_INACTIVE(self):
        """Message constant 'PSM_INACTIVE'."""
        return Metaclass_NavPVT.__constants['PSM_INACTIVE']

    @property
    def FLAGS_HEAD_VEH_VALID(self):
        """Message constant 'FLAGS_HEAD_VEH_VALID'."""
        return Metaclass_NavPVT.__constants['FLAGS_HEAD_VEH_VALID']

    @property
    def FLAGS_CARRIER_PHASE_MASK(self):
        """Message constant 'FLAGS_CARRIER_PHASE_MASK'."""
        return Metaclass_NavPVT.__constants['FLAGS_CARRIER_PHASE_MASK']

    @property
    def CARRIER_PHASE_NO_SOLUTION(self):
        """Message constant 'CARRIER_PHASE_NO_SOLUTION'."""
        return Metaclass_NavPVT.__constants['CARRIER_PHASE_NO_SOLUTION']

    @property
    def CARRIER_PHASE_FLOAT(self):
        """Message constant 'CARRIER_PHASE_FLOAT'."""
        return Metaclass_NavPVT.__constants['CARRIER_PHASE_FLOAT']

    @property
    def CARRIER_PHASE_FIXED(self):
        """Message constant 'CARRIER_PHASE_FIXED'."""
        return Metaclass_NavPVT.__constants['CARRIER_PHASE_FIXED']

    @property
    def FLAGS2_CONFIRMED_AVAILABLE(self):
        """Message constant 'FLAGS2_CONFIRMED_AVAILABLE'."""
        return Metaclass_NavPVT.__constants['FLAGS2_CONFIRMED_AVAILABLE']

    @property
    def FLAGS2_CONFIRMED_DATE(self):
        """Message constant 'FLAGS2_CONFIRMED_DATE'."""
        return Metaclass_NavPVT.__constants['FLAGS2_CONFIRMED_DATE']

    @property
    def FLAGS2_CONFIRMED_TIME(self):
        """Message constant 'FLAGS2_CONFIRMED_TIME'."""
        return Metaclass_NavPVT.__constants['FLAGS2_CONFIRMED_TIME']


class NavPVT(metaclass=Metaclass_NavPVT):
    """
    Message class 'NavPVT'.

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
      FIX_TYPE_GNSS_DEAD_RECKONING_COMBINED
      FIX_TYPE_TIME_ONLY
      FLAGS_GNSS_FIX_OK
      FLAGS_DIFF_SOLN
      FLAGS_PSM_MASK
      PSM_OFF
      PSM_ENABLED
      PSM_ACQUIRED
      PSM_TRACKING
      PSM_POWER_OPTIMIZED_TRACKING
      PSM_INACTIVE
      FLAGS_HEAD_VEH_VALID
      FLAGS_CARRIER_PHASE_MASK
      CARRIER_PHASE_NO_SOLUTION
      CARRIER_PHASE_FLOAT
      CARRIER_PHASE_FIXED
      FLAGS2_CONFIRMED_AVAILABLE
      FLAGS2_CONFIRMED_DATE
      FLAGS2_CONFIRMED_TIME
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
        '_t_acc',
        '_nano',
        '_fix_type',
        '_flags',
        '_flags2',
        '_num_sv',
        '_lon',
        '_lat',
        '_height',
        '_h_msl',
        '_h_acc',
        '_v_acc',
        '_vel_n',
        '_vel_e',
        '_vel_d',
        '_g_speed',
        '_heading',
        '_s_acc',
        '_head_acc',
        '_p_dop',
        '_reserved1',
        '_head_veh',
        '_mag_dec',
        '_mag_acc',
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
        't_acc': 'uint32',
        'nano': 'int32',
        'fix_type': 'uint8',
        'flags': 'uint8',
        'flags2': 'uint8',
        'num_sv': 'uint8',
        'lon': 'int32',
        'lat': 'int32',
        'height': 'int32',
        'h_msl': 'int32',
        'h_acc': 'uint32',
        'v_acc': 'uint32',
        'vel_n': 'int32',
        'vel_e': 'int32',
        'vel_d': 'int32',
        'g_speed': 'int32',
        'heading': 'int32',
        's_acc': 'uint32',
        'head_acc': 'uint32',
        'p_dop': 'uint16',
        'reserved1': 'uint8[6]',
        'head_veh': 'int32',
        'mag_dec': 'int16',
        'mag_acc': 'uint16',
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
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 6),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
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
        self.t_acc = kwargs.get('t_acc', int())
        self.nano = kwargs.get('nano', int())
        self.fix_type = kwargs.get('fix_type', int())
        self.flags = kwargs.get('flags', int())
        self.flags2 = kwargs.get('flags2', int())
        self.num_sv = kwargs.get('num_sv', int())
        self.lon = kwargs.get('lon', int())
        self.lat = kwargs.get('lat', int())
        self.height = kwargs.get('height', int())
        self.h_msl = kwargs.get('h_msl', int())
        self.h_acc = kwargs.get('h_acc', int())
        self.v_acc = kwargs.get('v_acc', int())
        self.vel_n = kwargs.get('vel_n', int())
        self.vel_e = kwargs.get('vel_e', int())
        self.vel_d = kwargs.get('vel_d', int())
        self.g_speed = kwargs.get('g_speed', int())
        self.heading = kwargs.get('heading', int())
        self.s_acc = kwargs.get('s_acc', int())
        self.head_acc = kwargs.get('head_acc', int())
        self.p_dop = kwargs.get('p_dop', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(6, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (6, )
        self.head_veh = kwargs.get('head_veh', int())
        self.mag_dec = kwargs.get('mag_dec', int())
        self.mag_acc = kwargs.get('mag_acc', int())

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
        if self.t_acc != other.t_acc:
            return False
        if self.nano != other.nano:
            return False
        if self.fix_type != other.fix_type:
            return False
        if self.flags != other.flags:
            return False
        if self.flags2 != other.flags2:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.lon != other.lon:
            return False
        if self.lat != other.lat:
            return False
        if self.height != other.height:
            return False
        if self.h_msl != other.h_msl:
            return False
        if self.h_acc != other.h_acc:
            return False
        if self.v_acc != other.v_acc:
            return False
        if self.vel_n != other.vel_n:
            return False
        if self.vel_e != other.vel_e:
            return False
        if self.vel_d != other.vel_d:
            return False
        if self.g_speed != other.g_speed:
            return False
        if self.heading != other.heading:
            return False
        if self.s_acc != other.s_acc:
            return False
        if self.head_acc != other.head_acc:
            return False
        if self.p_dop != other.p_dop:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.head_veh != other.head_veh:
            return False
        if self.mag_dec != other.mag_dec:
            return False
        if self.mag_acc != other.mag_acc:
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
    def fix_type(self):
        """Message field 'fix_type'."""
        return self._fix_type

    @fix_type.setter
    def fix_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fix_type' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fix_type' field must be an unsigned integer in [0, 255]"
        self._fix_type = value

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
    def vel_n(self):
        """Message field 'vel_n'."""
        return self._vel_n

    @vel_n.setter
    def vel_n(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_n' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vel_n' field must be an integer in [-2147483648, 2147483647]"
        self._vel_n = value

    @builtins.property
    def vel_e(self):
        """Message field 'vel_e'."""
        return self._vel_e

    @vel_e.setter
    def vel_e(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_e' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vel_e' field must be an integer in [-2147483648, 2147483647]"
        self._vel_e = value

    @builtins.property
    def vel_d(self):
        """Message field 'vel_d'."""
        return self._vel_d

    @vel_d.setter
    def vel_d(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vel_d' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vel_d' field must be an integer in [-2147483648, 2147483647]"
        self._vel_d = value

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
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 6, \
                "The 'reserved1' numpy.ndarray() must have a size of 6"
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
                 len(value) == 6 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 6 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

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
    def mag_dec(self):
        """Message field 'mag_dec'."""
        return self._mag_dec

    @mag_dec.setter
    def mag_dec(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mag_dec' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'mag_dec' field must be an integer in [-32768, 32767]"
        self._mag_dec = value

    @builtins.property
    def mag_acc(self):
        """Message field 'mag_acc'."""
        return self._mag_acc

    @mag_acc.setter
    def mag_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mag_acc' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'mag_acc' field must be an unsigned integer in [0, 65535]"
        self._mag_acc = value
