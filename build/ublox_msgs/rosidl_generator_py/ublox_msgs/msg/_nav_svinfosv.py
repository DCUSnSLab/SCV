# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSVINFOSV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSVINFOSV(type):
    """Metaclass of message 'NavSVINFOSV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FLAGS_SV_USED': 1,
        'FLAGS_DIFF_CORR': 2,
        'FLAGS_ORBIT_AVAIL': 4,
        'FLAGS_ORBIT_EPH': 8,
        'FLAGS_UNHEALTHY': 16,
        'FLAGS_ORBIT_ALM': 32,
        'FLAGS_ORBIT_AOP': 64,
        'FLAGS_SMOOTHED': 128,
        'QUALITY_IDLE': 0,
        'QUALITY_SEARCHING': 1,
        'QUALITY_ACQUIRED': 2,
        'QUALITY_DETECTED': 3,
        'QUALITY_CODE_LOCK': 4,
        'QUALITY_CODE_AND_CARRIER_LOCKED1': 5,
        'QUALITY_CODE_AND_CARRIER_LOCKED2': 6,
        'QUALITY_CODE_AND_CARRIER_LOCKED3': 7,
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
                'ublox_msgs.msg.NavSVINFOSV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_svinfosv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_svinfosv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_svinfosv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_svinfosv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_svinfosv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FLAGS_SV_USED': cls.__constants['FLAGS_SV_USED'],
            'FLAGS_DIFF_CORR': cls.__constants['FLAGS_DIFF_CORR'],
            'FLAGS_ORBIT_AVAIL': cls.__constants['FLAGS_ORBIT_AVAIL'],
            'FLAGS_ORBIT_EPH': cls.__constants['FLAGS_ORBIT_EPH'],
            'FLAGS_UNHEALTHY': cls.__constants['FLAGS_UNHEALTHY'],
            'FLAGS_ORBIT_ALM': cls.__constants['FLAGS_ORBIT_ALM'],
            'FLAGS_ORBIT_AOP': cls.__constants['FLAGS_ORBIT_AOP'],
            'FLAGS_SMOOTHED': cls.__constants['FLAGS_SMOOTHED'],
            'QUALITY_IDLE': cls.__constants['QUALITY_IDLE'],
            'QUALITY_SEARCHING': cls.__constants['QUALITY_SEARCHING'],
            'QUALITY_ACQUIRED': cls.__constants['QUALITY_ACQUIRED'],
            'QUALITY_DETECTED': cls.__constants['QUALITY_DETECTED'],
            'QUALITY_CODE_LOCK': cls.__constants['QUALITY_CODE_LOCK'],
            'QUALITY_CODE_AND_CARRIER_LOCKED1': cls.__constants['QUALITY_CODE_AND_CARRIER_LOCKED1'],
            'QUALITY_CODE_AND_CARRIER_LOCKED2': cls.__constants['QUALITY_CODE_AND_CARRIER_LOCKED2'],
            'QUALITY_CODE_AND_CARRIER_LOCKED3': cls.__constants['QUALITY_CODE_AND_CARRIER_LOCKED3'],
        }

    @property
    def FLAGS_SV_USED(self):
        """Message constant 'FLAGS_SV_USED'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_SV_USED']

    @property
    def FLAGS_DIFF_CORR(self):
        """Message constant 'FLAGS_DIFF_CORR'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_DIFF_CORR']

    @property
    def FLAGS_ORBIT_AVAIL(self):
        """Message constant 'FLAGS_ORBIT_AVAIL'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_ORBIT_AVAIL']

    @property
    def FLAGS_ORBIT_EPH(self):
        """Message constant 'FLAGS_ORBIT_EPH'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_ORBIT_EPH']

    @property
    def FLAGS_UNHEALTHY(self):
        """Message constant 'FLAGS_UNHEALTHY'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_UNHEALTHY']

    @property
    def FLAGS_ORBIT_ALM(self):
        """Message constant 'FLAGS_ORBIT_ALM'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_ORBIT_ALM']

    @property
    def FLAGS_ORBIT_AOP(self):
        """Message constant 'FLAGS_ORBIT_AOP'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_ORBIT_AOP']

    @property
    def FLAGS_SMOOTHED(self):
        """Message constant 'FLAGS_SMOOTHED'."""
        return Metaclass_NavSVINFOSV.__constants['FLAGS_SMOOTHED']

    @property
    def QUALITY_IDLE(self):
        """Message constant 'QUALITY_IDLE'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_IDLE']

    @property
    def QUALITY_SEARCHING(self):
        """Message constant 'QUALITY_SEARCHING'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_SEARCHING']

    @property
    def QUALITY_ACQUIRED(self):
        """Message constant 'QUALITY_ACQUIRED'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_ACQUIRED']

    @property
    def QUALITY_DETECTED(self):
        """Message constant 'QUALITY_DETECTED'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_DETECTED']

    @property
    def QUALITY_CODE_LOCK(self):
        """Message constant 'QUALITY_CODE_LOCK'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_CODE_LOCK']

    @property
    def QUALITY_CODE_AND_CARRIER_LOCKED1(self):
        """Message constant 'QUALITY_CODE_AND_CARRIER_LOCKED1'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_CODE_AND_CARRIER_LOCKED1']

    @property
    def QUALITY_CODE_AND_CARRIER_LOCKED2(self):
        """Message constant 'QUALITY_CODE_AND_CARRIER_LOCKED2'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_CODE_AND_CARRIER_LOCKED2']

    @property
    def QUALITY_CODE_AND_CARRIER_LOCKED3(self):
        """Message constant 'QUALITY_CODE_AND_CARRIER_LOCKED3'."""
        return Metaclass_NavSVINFOSV.__constants['QUALITY_CODE_AND_CARRIER_LOCKED3']


class NavSVINFOSV(metaclass=Metaclass_NavSVINFOSV):
    """
    Message class 'NavSVINFOSV'.

    Constants:
      FLAGS_SV_USED
      FLAGS_DIFF_CORR
      FLAGS_ORBIT_AVAIL
      FLAGS_ORBIT_EPH
      FLAGS_UNHEALTHY
      FLAGS_ORBIT_ALM
      FLAGS_ORBIT_AOP
      FLAGS_SMOOTHED
      QUALITY_IDLE
      QUALITY_SEARCHING
      QUALITY_ACQUIRED
      QUALITY_DETECTED
      QUALITY_CODE_LOCK
      QUALITY_CODE_AND_CARRIER_LOCKED1
      QUALITY_CODE_AND_CARRIER_LOCKED2
      QUALITY_CODE_AND_CARRIER_LOCKED3
    """

    __slots__ = [
        '_chn',
        '_svid',
        '_flags',
        '_quality',
        '_cno',
        '_elev',
        '_azim',
        '_pr_res',
    ]

    _fields_and_field_types = {
        'chn': 'uint8',
        'svid': 'uint8',
        'flags': 'uint8',
        'quality': 'uint8',
        'cno': 'uint8',
        'elev': 'int8',
        'azim': 'int16',
        'pr_res': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.chn = kwargs.get('chn', int())
        self.svid = kwargs.get('svid', int())
        self.flags = kwargs.get('flags', int())
        self.quality = kwargs.get('quality', int())
        self.cno = kwargs.get('cno', int())
        self.elev = kwargs.get('elev', int())
        self.azim = kwargs.get('azim', int())
        self.pr_res = kwargs.get('pr_res', int())

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
        if self.chn != other.chn:
            return False
        if self.svid != other.svid:
            return False
        if self.flags != other.flags:
            return False
        if self.quality != other.quality:
            return False
        if self.cno != other.cno:
            return False
        if self.elev != other.elev:
            return False
        if self.azim != other.azim:
            return False
        if self.pr_res != other.pr_res:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def chn(self):
        """Message field 'chn'."""
        return self._chn

    @chn.setter
    def chn(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'chn' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'chn' field must be an unsigned integer in [0, 255]"
        self._chn = value

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
    def quality(self):
        """Message field 'quality'."""
        return self._quality

    @quality.setter
    def quality(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'quality' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'quality' field must be an unsigned integer in [0, 255]"
        self._quality = value

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
            assert value >= 0 and value < 256, \
                "The 'cno' field must be an unsigned integer in [0, 255]"
        self._cno = value

    @builtins.property
    def elev(self):
        """Message field 'elev'."""
        return self._elev

    @elev.setter
    def elev(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'elev' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'elev' field must be an integer in [-128, 127]"
        self._elev = value

    @builtins.property
    def azim(self):
        """Message field 'azim'."""
        return self._azim

    @azim.setter
    def azim(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'azim' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'azim' field must be an integer in [-32768, 32767]"
        self._azim = value

    @builtins.property
    def pr_res(self):
        """Message field 'pr_res'."""
        return self._pr_res

    @pr_res.setter
    def pr_res(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pr_res' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'pr_res' field must be an integer in [-2147483648, 2147483647]"
        self._pr_res = value
