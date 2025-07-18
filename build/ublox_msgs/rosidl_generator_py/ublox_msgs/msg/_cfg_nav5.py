# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgNAV5.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved1'
# Member 'reserved2'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgNAV5(type):
    """Metaclass of message 'CfgNAV5'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 36,
        'MASK_DYN': 1,
        'MASK_MIN_EL': 2,
        'MASK_FIX_MODE': 4,
        'MASK_DR_LIM': 8,
        'MASK_POS_MASK': 16,
        'MASK_TIME_MASK': 32,
        'MASK_STATIC_HOLD_MASK': 64,
        'MASK_DGPS_MASK': 128,
        'MASK_CNO': 256,
        'MASK_UTC': 1024,
        'DYN_MODEL_PORTABLE': 0,
        'DYN_MODEL_STATIONARY': 2,
        'DYN_MODEL_PEDESTRIAN': 3,
        'DYN_MODEL_AUTOMOTIVE': 4,
        'DYN_MODEL_SEA': 5,
        'DYN_MODEL_AIRBORNE_1G': 6,
        'DYN_MODEL_AIRBORNE_2G': 7,
        'DYN_MODEL_AIRBORNE_4G': 8,
        'DYN_MODEL_WRIST_WATCH': 9,
        'FIX_MODE_2D_ONLY': 1,
        'FIX_MODE_3D_ONLY': 2,
        'FIX_MODE_AUTO': 3,
        'UTC_STANDARD_AUTOMATIC': 0,
        'UTC_STANDARD_GPS': 3,
        'UTC_STANDARD_GLONASS': 6,
        'UTC_STANDARD_BEIDOU': 7,
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
                'ublox_msgs.msg.CfgNAV5')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_nav5
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_nav5
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_nav5
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_nav5
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_nav5

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'MASK_DYN': cls.__constants['MASK_DYN'],
            'MASK_MIN_EL': cls.__constants['MASK_MIN_EL'],
            'MASK_FIX_MODE': cls.__constants['MASK_FIX_MODE'],
            'MASK_DR_LIM': cls.__constants['MASK_DR_LIM'],
            'MASK_POS_MASK': cls.__constants['MASK_POS_MASK'],
            'MASK_TIME_MASK': cls.__constants['MASK_TIME_MASK'],
            'MASK_STATIC_HOLD_MASK': cls.__constants['MASK_STATIC_HOLD_MASK'],
            'MASK_DGPS_MASK': cls.__constants['MASK_DGPS_MASK'],
            'MASK_CNO': cls.__constants['MASK_CNO'],
            'MASK_UTC': cls.__constants['MASK_UTC'],
            'DYN_MODEL_PORTABLE': cls.__constants['DYN_MODEL_PORTABLE'],
            'DYN_MODEL_STATIONARY': cls.__constants['DYN_MODEL_STATIONARY'],
            'DYN_MODEL_PEDESTRIAN': cls.__constants['DYN_MODEL_PEDESTRIAN'],
            'DYN_MODEL_AUTOMOTIVE': cls.__constants['DYN_MODEL_AUTOMOTIVE'],
            'DYN_MODEL_SEA': cls.__constants['DYN_MODEL_SEA'],
            'DYN_MODEL_AIRBORNE_1G': cls.__constants['DYN_MODEL_AIRBORNE_1G'],
            'DYN_MODEL_AIRBORNE_2G': cls.__constants['DYN_MODEL_AIRBORNE_2G'],
            'DYN_MODEL_AIRBORNE_4G': cls.__constants['DYN_MODEL_AIRBORNE_4G'],
            'DYN_MODEL_WRIST_WATCH': cls.__constants['DYN_MODEL_WRIST_WATCH'],
            'FIX_MODE_2D_ONLY': cls.__constants['FIX_MODE_2D_ONLY'],
            'FIX_MODE_3D_ONLY': cls.__constants['FIX_MODE_3D_ONLY'],
            'FIX_MODE_AUTO': cls.__constants['FIX_MODE_AUTO'],
            'UTC_STANDARD_AUTOMATIC': cls.__constants['UTC_STANDARD_AUTOMATIC'],
            'UTC_STANDARD_GPS': cls.__constants['UTC_STANDARD_GPS'],
            'UTC_STANDARD_GLONASS': cls.__constants['UTC_STANDARD_GLONASS'],
            'UTC_STANDARD_BEIDOU': cls.__constants['UTC_STANDARD_BEIDOU'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgNAV5.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgNAV5.__constants['MESSAGE_ID']

    @property
    def MASK_DYN(self):
        """Message constant 'MASK_DYN'."""
        return Metaclass_CfgNAV5.__constants['MASK_DYN']

    @property
    def MASK_MIN_EL(self):
        """Message constant 'MASK_MIN_EL'."""
        return Metaclass_CfgNAV5.__constants['MASK_MIN_EL']

    @property
    def MASK_FIX_MODE(self):
        """Message constant 'MASK_FIX_MODE'."""
        return Metaclass_CfgNAV5.__constants['MASK_FIX_MODE']

    @property
    def MASK_DR_LIM(self):
        """Message constant 'MASK_DR_LIM'."""
        return Metaclass_CfgNAV5.__constants['MASK_DR_LIM']

    @property
    def MASK_POS_MASK(self):
        """Message constant 'MASK_POS_MASK'."""
        return Metaclass_CfgNAV5.__constants['MASK_POS_MASK']

    @property
    def MASK_TIME_MASK(self):
        """Message constant 'MASK_TIME_MASK'."""
        return Metaclass_CfgNAV5.__constants['MASK_TIME_MASK']

    @property
    def MASK_STATIC_HOLD_MASK(self):
        """Message constant 'MASK_STATIC_HOLD_MASK'."""
        return Metaclass_CfgNAV5.__constants['MASK_STATIC_HOLD_MASK']

    @property
    def MASK_DGPS_MASK(self):
        """Message constant 'MASK_DGPS_MASK'."""
        return Metaclass_CfgNAV5.__constants['MASK_DGPS_MASK']

    @property
    def MASK_CNO(self):
        """Message constant 'MASK_CNO'."""
        return Metaclass_CfgNAV5.__constants['MASK_CNO']

    @property
    def MASK_UTC(self):
        """Message constant 'MASK_UTC'."""
        return Metaclass_CfgNAV5.__constants['MASK_UTC']

    @property
    def DYN_MODEL_PORTABLE(self):
        """Message constant 'DYN_MODEL_PORTABLE'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_PORTABLE']

    @property
    def DYN_MODEL_STATIONARY(self):
        """Message constant 'DYN_MODEL_STATIONARY'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_STATIONARY']

    @property
    def DYN_MODEL_PEDESTRIAN(self):
        """Message constant 'DYN_MODEL_PEDESTRIAN'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_PEDESTRIAN']

    @property
    def DYN_MODEL_AUTOMOTIVE(self):
        """Message constant 'DYN_MODEL_AUTOMOTIVE'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_AUTOMOTIVE']

    @property
    def DYN_MODEL_SEA(self):
        """Message constant 'DYN_MODEL_SEA'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_SEA']

    @property
    def DYN_MODEL_AIRBORNE_1G(self):
        """Message constant 'DYN_MODEL_AIRBORNE_1G'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_AIRBORNE_1G']

    @property
    def DYN_MODEL_AIRBORNE_2G(self):
        """Message constant 'DYN_MODEL_AIRBORNE_2G'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_AIRBORNE_2G']

    @property
    def DYN_MODEL_AIRBORNE_4G(self):
        """Message constant 'DYN_MODEL_AIRBORNE_4G'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_AIRBORNE_4G']

    @property
    def DYN_MODEL_WRIST_WATCH(self):
        """Message constant 'DYN_MODEL_WRIST_WATCH'."""
        return Metaclass_CfgNAV5.__constants['DYN_MODEL_WRIST_WATCH']

    @property
    def FIX_MODE_2D_ONLY(self):
        """Message constant 'FIX_MODE_2D_ONLY'."""
        return Metaclass_CfgNAV5.__constants['FIX_MODE_2D_ONLY']

    @property
    def FIX_MODE_3D_ONLY(self):
        """Message constant 'FIX_MODE_3D_ONLY'."""
        return Metaclass_CfgNAV5.__constants['FIX_MODE_3D_ONLY']

    @property
    def FIX_MODE_AUTO(self):
        """Message constant 'FIX_MODE_AUTO'."""
        return Metaclass_CfgNAV5.__constants['FIX_MODE_AUTO']

    @property
    def UTC_STANDARD_AUTOMATIC(self):
        """Message constant 'UTC_STANDARD_AUTOMATIC'."""
        return Metaclass_CfgNAV5.__constants['UTC_STANDARD_AUTOMATIC']

    @property
    def UTC_STANDARD_GPS(self):
        """Message constant 'UTC_STANDARD_GPS'."""
        return Metaclass_CfgNAV5.__constants['UTC_STANDARD_GPS']

    @property
    def UTC_STANDARD_GLONASS(self):
        """Message constant 'UTC_STANDARD_GLONASS'."""
        return Metaclass_CfgNAV5.__constants['UTC_STANDARD_GLONASS']

    @property
    def UTC_STANDARD_BEIDOU(self):
        """Message constant 'UTC_STANDARD_BEIDOU'."""
        return Metaclass_CfgNAV5.__constants['UTC_STANDARD_BEIDOU']


class CfgNAV5(metaclass=Metaclass_CfgNAV5):
    """
    Message class 'CfgNAV5'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      MASK_DYN
      MASK_MIN_EL
      MASK_FIX_MODE
      MASK_DR_LIM
      MASK_POS_MASK
      MASK_TIME_MASK
      MASK_STATIC_HOLD_MASK
      MASK_DGPS_MASK
      MASK_CNO
      MASK_UTC
      DYN_MODEL_PORTABLE
      DYN_MODEL_STATIONARY
      DYN_MODEL_PEDESTRIAN
      DYN_MODEL_AUTOMOTIVE
      DYN_MODEL_SEA
      DYN_MODEL_AIRBORNE_1G
      DYN_MODEL_AIRBORNE_2G
      DYN_MODEL_AIRBORNE_4G
      DYN_MODEL_WRIST_WATCH
      FIX_MODE_2D_ONLY
      FIX_MODE_3D_ONLY
      FIX_MODE_AUTO
      UTC_STANDARD_AUTOMATIC
      UTC_STANDARD_GPS
      UTC_STANDARD_GLONASS
      UTC_STANDARD_BEIDOU
    """

    __slots__ = [
        '_mask',
        '_dyn_model',
        '_fix_mode',
        '_fixed_alt',
        '_fixed_alt_var',
        '_min_elev',
        '_dr_limit',
        '_p_dop',
        '_t_dop',
        '_p_acc',
        '_t_acc',
        '_static_hold_thresh',
        '_dgnss_time_out',
        '_cno_thresh_num_svs',
        '_cno_thresh',
        '_reserved1',
        '_static_hold_max_dist',
        '_utc_standard',
        '_reserved2',
    ]

    _fields_and_field_types = {
        'mask': 'uint16',
        'dyn_model': 'uint8',
        'fix_mode': 'uint8',
        'fixed_alt': 'int32',
        'fixed_alt_var': 'uint32',
        'min_elev': 'int8',
        'dr_limit': 'uint8',
        'p_dop': 'uint16',
        't_dop': 'uint16',
        'p_acc': 'uint16',
        't_acc': 'uint16',
        'static_hold_thresh': 'uint8',
        'dgnss_time_out': 'uint8',
        'cno_thresh_num_svs': 'uint8',
        'cno_thresh': 'uint8',
        'reserved1': 'uint8[2]',
        'static_hold_max_dist': 'uint16',
        'utc_standard': 'uint8',
        'reserved2': 'uint8[5]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 5),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.mask = kwargs.get('mask', int())
        self.dyn_model = kwargs.get('dyn_model', int())
        self.fix_mode = kwargs.get('fix_mode', int())
        self.fixed_alt = kwargs.get('fixed_alt', int())
        self.fixed_alt_var = kwargs.get('fixed_alt_var', int())
        self.min_elev = kwargs.get('min_elev', int())
        self.dr_limit = kwargs.get('dr_limit', int())
        self.p_dop = kwargs.get('p_dop', int())
        self.t_dop = kwargs.get('t_dop', int())
        self.p_acc = kwargs.get('p_acc', int())
        self.t_acc = kwargs.get('t_acc', int())
        self.static_hold_thresh = kwargs.get('static_hold_thresh', int())
        self.dgnss_time_out = kwargs.get('dgnss_time_out', int())
        self.cno_thresh_num_svs = kwargs.get('cno_thresh_num_svs', int())
        self.cno_thresh = kwargs.get('cno_thresh', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        self.static_hold_max_dist = kwargs.get('static_hold_max_dist', int())
        self.utc_standard = kwargs.get('utc_standard', int())
        if 'reserved2' not in kwargs:
            self.reserved2 = numpy.zeros(5, dtype=numpy.uint8)
        else:
            self.reserved2 = numpy.array(kwargs.get('reserved2'), dtype=numpy.uint8)
            assert self.reserved2.shape == (5, )

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
        if self.mask != other.mask:
            return False
        if self.dyn_model != other.dyn_model:
            return False
        if self.fix_mode != other.fix_mode:
            return False
        if self.fixed_alt != other.fixed_alt:
            return False
        if self.fixed_alt_var != other.fixed_alt_var:
            return False
        if self.min_elev != other.min_elev:
            return False
        if self.dr_limit != other.dr_limit:
            return False
        if self.p_dop != other.p_dop:
            return False
        if self.t_dop != other.t_dop:
            return False
        if self.p_acc != other.p_acc:
            return False
        if self.t_acc != other.t_acc:
            return False
        if self.static_hold_thresh != other.static_hold_thresh:
            return False
        if self.dgnss_time_out != other.dgnss_time_out:
            return False
        if self.cno_thresh_num_svs != other.cno_thresh_num_svs:
            return False
        if self.cno_thresh != other.cno_thresh:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.static_hold_max_dist != other.static_hold_max_dist:
            return False
        if self.utc_standard != other.utc_standard:
            return False
        if all(self.reserved2 != other.reserved2):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def mask(self):
        """Message field 'mask'."""
        return self._mask

    @mask.setter
    def mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mask' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'mask' field must be an unsigned integer in [0, 65535]"
        self._mask = value

    @builtins.property
    def dyn_model(self):
        """Message field 'dyn_model'."""
        return self._dyn_model

    @dyn_model.setter
    def dyn_model(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dyn_model' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dyn_model' field must be an unsigned integer in [0, 255]"
        self._dyn_model = value

    @builtins.property
    def fix_mode(self):
        """Message field 'fix_mode'."""
        return self._fix_mode

    @fix_mode.setter
    def fix_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fix_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fix_mode' field must be an unsigned integer in [0, 255]"
        self._fix_mode = value

    @builtins.property
    def fixed_alt(self):
        """Message field 'fixed_alt'."""
        return self._fixed_alt

    @fixed_alt.setter
    def fixed_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fixed_alt' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'fixed_alt' field must be an integer in [-2147483648, 2147483647]"
        self._fixed_alt = value

    @builtins.property
    def fixed_alt_var(self):
        """Message field 'fixed_alt_var'."""
        return self._fixed_alt_var

    @fixed_alt_var.setter
    def fixed_alt_var(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fixed_alt_var' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'fixed_alt_var' field must be an unsigned integer in [0, 4294967295]"
        self._fixed_alt_var = value

    @builtins.property
    def min_elev(self):
        """Message field 'min_elev'."""
        return self._min_elev

    @min_elev.setter
    def min_elev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_elev' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'min_elev' field must be an integer in [-128, 127]"
        self._min_elev = value

    @builtins.property
    def dr_limit(self):
        """Message field 'dr_limit'."""
        return self._dr_limit

    @dr_limit.setter
    def dr_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dr_limit' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dr_limit' field must be an unsigned integer in [0, 255]"
        self._dr_limit = value

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
    def t_dop(self):
        """Message field 't_dop'."""
        return self._t_dop

    @t_dop.setter
    def t_dop(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 't_dop' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 't_dop' field must be an unsigned integer in [0, 65535]"
        self._t_dop = value

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
            assert value >= 0 and value < 65536, \
                "The 'p_acc' field must be an unsigned integer in [0, 65535]"
        self._p_acc = value

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
            assert value >= 0 and value < 65536, \
                "The 't_acc' field must be an unsigned integer in [0, 65535]"
        self._t_acc = value

    @builtins.property
    def static_hold_thresh(self):
        """Message field 'static_hold_thresh'."""
        return self._static_hold_thresh

    @static_hold_thresh.setter
    def static_hold_thresh(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'static_hold_thresh' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'static_hold_thresh' field must be an unsigned integer in [0, 255]"
        self._static_hold_thresh = value

    @builtins.property
    def dgnss_time_out(self):
        """Message field 'dgnss_time_out'."""
        return self._dgnss_time_out

    @dgnss_time_out.setter
    def dgnss_time_out(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'dgnss_time_out' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'dgnss_time_out' field must be an unsigned integer in [0, 255]"
        self._dgnss_time_out = value

    @builtins.property
    def cno_thresh_num_svs(self):
        """Message field 'cno_thresh_num_svs'."""
        return self._cno_thresh_num_svs

    @cno_thresh_num_svs.setter
    def cno_thresh_num_svs(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cno_thresh_num_svs' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cno_thresh_num_svs' field must be an unsigned integer in [0, 255]"
        self._cno_thresh_num_svs = value

    @builtins.property
    def cno_thresh(self):
        """Message field 'cno_thresh'."""
        return self._cno_thresh

    @cno_thresh.setter
    def cno_thresh(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cno_thresh' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cno_thresh' field must be an unsigned integer in [0, 255]"
        self._cno_thresh = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved1' numpy.ndarray() must have a size of 2"
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def static_hold_max_dist(self):
        """Message field 'static_hold_max_dist'."""
        return self._static_hold_max_dist

    @static_hold_max_dist.setter
    def static_hold_max_dist(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'static_hold_max_dist' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'static_hold_max_dist' field must be an unsigned integer in [0, 65535]"
        self._static_hold_max_dist = value

    @builtins.property
    def utc_standard(self):
        """Message field 'utc_standard'."""
        return self._utc_standard

    @utc_standard.setter
    def utc_standard(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'utc_standard' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'utc_standard' field must be an unsigned integer in [0, 255]"
        self._utc_standard = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved2' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 5, \
                "The 'reserved2' numpy.ndarray() must have a size of 5"
            self._reserved2 = value
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
                 len(value) == 5 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved2' field must be a set or sequence with length 5 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved2 = numpy.array(value, dtype=numpy.uint8)
