# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/RxmRAWXMeas.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RxmRAWXMeas(type):
    """Metaclass of message 'RxmRAWXMeas'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TRK_STAT_PR_VALID': 1,
        'TRK_STAT_CP_VALID': 2,
        'TRK_STAT_HALF_CYC': 4,
        'TRK_STAT_SUB_HALF_CYC': 8,
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
                'ublox_msgs.msg.RxmRAWXMeas')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rxm_rawx_meas
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rxm_rawx_meas
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rxm_rawx_meas
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rxm_rawx_meas
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rxm_rawx_meas

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TRK_STAT_PR_VALID': cls.__constants['TRK_STAT_PR_VALID'],
            'TRK_STAT_CP_VALID': cls.__constants['TRK_STAT_CP_VALID'],
            'TRK_STAT_HALF_CYC': cls.__constants['TRK_STAT_HALF_CYC'],
            'TRK_STAT_SUB_HALF_CYC': cls.__constants['TRK_STAT_SUB_HALF_CYC'],
        }

    @property
    def TRK_STAT_PR_VALID(self):
        """Message constant 'TRK_STAT_PR_VALID'."""
        return Metaclass_RxmRAWXMeas.__constants['TRK_STAT_PR_VALID']

    @property
    def TRK_STAT_CP_VALID(self):
        """Message constant 'TRK_STAT_CP_VALID'."""
        return Metaclass_RxmRAWXMeas.__constants['TRK_STAT_CP_VALID']

    @property
    def TRK_STAT_HALF_CYC(self):
        """Message constant 'TRK_STAT_HALF_CYC'."""
        return Metaclass_RxmRAWXMeas.__constants['TRK_STAT_HALF_CYC']

    @property
    def TRK_STAT_SUB_HALF_CYC(self):
        """Message constant 'TRK_STAT_SUB_HALF_CYC'."""
        return Metaclass_RxmRAWXMeas.__constants['TRK_STAT_SUB_HALF_CYC']


class RxmRAWXMeas(metaclass=Metaclass_RxmRAWXMeas):
    """
    Message class 'RxmRAWXMeas'.

    Constants:
      TRK_STAT_PR_VALID
      TRK_STAT_CP_VALID
      TRK_STAT_HALF_CYC
      TRK_STAT_SUB_HALF_CYC
    """

    __slots__ = [
        '_pr_mes',
        '_cp_mes',
        '_do_mes',
        '_gnss_id',
        '_sv_id',
        '_reserved0',
        '_freq_id',
        '_locktime',
        '_cno',
        '_pr_stdev',
        '_cp_stdev',
        '_do_stdev',
        '_trk_stat',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'pr_mes': 'double',
        'cp_mes': 'double',
        'do_mes': 'float',
        'gnss_id': 'uint8',
        'sv_id': 'uint8',
        'reserved0': 'uint8',
        'freq_id': 'uint8',
        'locktime': 'uint16',
        'cno': 'int8',
        'pr_stdev': 'uint8',
        'cp_stdev': 'uint8',
        'do_stdev': 'uint8',
        'trk_stat': 'uint8',
        'reserved1': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
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
        self.pr_mes = kwargs.get('pr_mes', float())
        self.cp_mes = kwargs.get('cp_mes', float())
        self.do_mes = kwargs.get('do_mes', float())
        self.gnss_id = kwargs.get('gnss_id', int())
        self.sv_id = kwargs.get('sv_id', int())
        self.reserved0 = kwargs.get('reserved0', int())
        self.freq_id = kwargs.get('freq_id', int())
        self.locktime = kwargs.get('locktime', int())
        self.cno = kwargs.get('cno', int())
        self.pr_stdev = kwargs.get('pr_stdev', int())
        self.cp_stdev = kwargs.get('cp_stdev', int())
        self.do_stdev = kwargs.get('do_stdev', int())
        self.trk_stat = kwargs.get('trk_stat', int())
        self.reserved1 = kwargs.get('reserved1', int())

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
        if self.pr_mes != other.pr_mes:
            return False
        if self.cp_mes != other.cp_mes:
            return False
        if self.do_mes != other.do_mes:
            return False
        if self.gnss_id != other.gnss_id:
            return False
        if self.sv_id != other.sv_id:
            return False
        if self.reserved0 != other.reserved0:
            return False
        if self.freq_id != other.freq_id:
            return False
        if self.locktime != other.locktime:
            return False
        if self.cno != other.cno:
            return False
        if self.pr_stdev != other.pr_stdev:
            return False
        if self.cp_stdev != other.cp_stdev:
            return False
        if self.do_stdev != other.do_stdev:
            return False
        if self.trk_stat != other.trk_stat:
            return False
        if self.reserved1 != other.reserved1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pr_mes(self):
        """Message field 'pr_mes'."""
        return self._pr_mes

    @pr_mes.setter
    def pr_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pr_mes' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pr_mes' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pr_mes = value

    @builtins.property
    def cp_mes(self):
        """Message field 'cp_mes'."""
        return self._cp_mes

    @cp_mes.setter
    def cp_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'cp_mes' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'cp_mes' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._cp_mes = value

    @builtins.property
    def do_mes(self):
        """Message field 'do_mes'."""
        return self._do_mes

    @do_mes.setter
    def do_mes(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'do_mes' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'do_mes' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._do_mes = value

    @builtins.property
    def gnss_id(self):
        """Message field 'gnss_id'."""
        return self._gnss_id

    @gnss_id.setter
    def gnss_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gnss_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gnss_id' field must be an unsigned integer in [0, 255]"
        self._gnss_id = value

    @builtins.property
    def sv_id(self):
        """Message field 'sv_id'."""
        return self._sv_id

    @sv_id.setter
    def sv_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_id' field must be an unsigned integer in [0, 255]"
        self._sv_id = value

    @builtins.property
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved0' field must be an unsigned integer in [0, 255]"
        self._reserved0 = value

    @builtins.property
    def freq_id(self):
        """Message field 'freq_id'."""
        return self._freq_id

    @freq_id.setter
    def freq_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'freq_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'freq_id' field must be an unsigned integer in [0, 255]"
        self._freq_id = value

    @builtins.property
    def locktime(self):
        """Message field 'locktime'."""
        return self._locktime

    @locktime.setter
    def locktime(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'locktime' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'locktime' field must be an unsigned integer in [0, 65535]"
        self._locktime = value

    @builtins.property
    def cno(self):
        """Message field 'cno'."""
        return self._cno

    @cno.setter
    def cno(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cno' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'cno' field must be an integer in [-128, 127]"
        self._cno = value

    @builtins.property
    def pr_stdev(self):
        """Message field 'pr_stdev'."""
        return self._pr_stdev

    @pr_stdev.setter
    def pr_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pr_stdev' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'pr_stdev' field must be an unsigned integer in [0, 255]"
        self._pr_stdev = value

    @builtins.property
    def cp_stdev(self):
        """Message field 'cp_stdev'."""
        return self._cp_stdev

    @cp_stdev.setter
    def cp_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'cp_stdev' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'cp_stdev' field must be an unsigned integer in [0, 255]"
        self._cp_stdev = value

    @builtins.property
    def do_stdev(self):
        """Message field 'do_stdev'."""
        return self._do_stdev

    @do_stdev.setter
    def do_stdev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'do_stdev' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'do_stdev' field must be an unsigned integer in [0, 255]"
        self._do_stdev = value

    @builtins.property
    def trk_stat(self):
        """Message field 'trk_stat'."""
        return self._trk_stat

    @trk_stat.setter
    def trk_stat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'trk_stat' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'trk_stat' field must be an unsigned integer in [0, 255]"
        self._trk_stat = value

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
