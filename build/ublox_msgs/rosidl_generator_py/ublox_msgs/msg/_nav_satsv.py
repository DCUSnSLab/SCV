# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSATSV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSATSV(type):
    """Metaclass of message 'NavSATSV'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'FLAGS_QUALITY_IND_MASK': 7,
        'QUALITY_IND_NO_SIGNAL': 0,
        'QUALITY_IND_SEARCHING_SIGNAL': 1,
        'QUALITY_IND_SIGNAL_ACQUIRED': 2,
        'QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE': 3,
        'QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC': 4,
        'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1': 5,
        'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2': 6,
        'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3': 7,
        'FLAGS_SV_USED': 8,
        'FLAGS_HEALTH_MASK': 48,
        'HEALTH_UNKNOWN': 0,
        'HEALTH_HEALTHY': 1,
        'HEALTH_UNHEALTHY': 2,
        'FLAGS_DIFF_CORR': 64,
        'FLAGS_SMOOTHED': 128,
        'FLAGS_ORBIT_SOURCE_MASK': 1792,
        'ORBIT_SOURCE_UNAVAILABLE': 0,
        'ORBIT_SOURCE_EPH': 256,
        'ORBIT_SOURCE_ALM': 512,
        'ORBIT_SOURCE_ASSIST_OFFLINE': 768,
        'ORBIT_SOURCE_ASSIST_AUTONOMOUS': 1024,
        'ORBIT_SOURCE_OTHER1': 1280,
        'ORBIT_SOURCE_OTHER2': 1536,
        'ORBIT_SOURCE_OTHER3': 1792,
        'FLAGS_EPH_AVAIL': 2048,
        'FLAGS_ALM_AVAIL': 4096,
        'FLAGS_ANO_AVAIL': 8192,
        'FLAGS_AOP_AVAIL': 16384,
        'FLAGS_SBAS_CORR_USED': 65536,
        'FLAGS_RTCM_CORR_USED': 131072,
        'FLAGS_PR_CORR_USED': 1048576,
        'FLAGS_CR_CORR_USED': 2097152,
        'FLAGS_DO_CORR_USED': 4194304,
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
                'ublox_msgs.msg.NavSATSV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_satsv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_satsv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_satsv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_satsv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_satsv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'FLAGS_QUALITY_IND_MASK': cls.__constants['FLAGS_QUALITY_IND_MASK'],
            'QUALITY_IND_NO_SIGNAL': cls.__constants['QUALITY_IND_NO_SIGNAL'],
            'QUALITY_IND_SEARCHING_SIGNAL': cls.__constants['QUALITY_IND_SEARCHING_SIGNAL'],
            'QUALITY_IND_SIGNAL_ACQUIRED': cls.__constants['QUALITY_IND_SIGNAL_ACQUIRED'],
            'QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE': cls.__constants['QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE'],
            'QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC': cls.__constants['QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC'],
            'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1': cls.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1'],
            'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2': cls.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2'],
            'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3': cls.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3'],
            'FLAGS_SV_USED': cls.__constants['FLAGS_SV_USED'],
            'FLAGS_HEALTH_MASK': cls.__constants['FLAGS_HEALTH_MASK'],
            'HEALTH_UNKNOWN': cls.__constants['HEALTH_UNKNOWN'],
            'HEALTH_HEALTHY': cls.__constants['HEALTH_HEALTHY'],
            'HEALTH_UNHEALTHY': cls.__constants['HEALTH_UNHEALTHY'],
            'FLAGS_DIFF_CORR': cls.__constants['FLAGS_DIFF_CORR'],
            'FLAGS_SMOOTHED': cls.__constants['FLAGS_SMOOTHED'],
            'FLAGS_ORBIT_SOURCE_MASK': cls.__constants['FLAGS_ORBIT_SOURCE_MASK'],
            'ORBIT_SOURCE_UNAVAILABLE': cls.__constants['ORBIT_SOURCE_UNAVAILABLE'],
            'ORBIT_SOURCE_EPH': cls.__constants['ORBIT_SOURCE_EPH'],
            'ORBIT_SOURCE_ALM': cls.__constants['ORBIT_SOURCE_ALM'],
            'ORBIT_SOURCE_ASSIST_OFFLINE': cls.__constants['ORBIT_SOURCE_ASSIST_OFFLINE'],
            'ORBIT_SOURCE_ASSIST_AUTONOMOUS': cls.__constants['ORBIT_SOURCE_ASSIST_AUTONOMOUS'],
            'ORBIT_SOURCE_OTHER1': cls.__constants['ORBIT_SOURCE_OTHER1'],
            'ORBIT_SOURCE_OTHER2': cls.__constants['ORBIT_SOURCE_OTHER2'],
            'ORBIT_SOURCE_OTHER3': cls.__constants['ORBIT_SOURCE_OTHER3'],
            'FLAGS_EPH_AVAIL': cls.__constants['FLAGS_EPH_AVAIL'],
            'FLAGS_ALM_AVAIL': cls.__constants['FLAGS_ALM_AVAIL'],
            'FLAGS_ANO_AVAIL': cls.__constants['FLAGS_ANO_AVAIL'],
            'FLAGS_AOP_AVAIL': cls.__constants['FLAGS_AOP_AVAIL'],
            'FLAGS_SBAS_CORR_USED': cls.__constants['FLAGS_SBAS_CORR_USED'],
            'FLAGS_RTCM_CORR_USED': cls.__constants['FLAGS_RTCM_CORR_USED'],
            'FLAGS_PR_CORR_USED': cls.__constants['FLAGS_PR_CORR_USED'],
            'FLAGS_CR_CORR_USED': cls.__constants['FLAGS_CR_CORR_USED'],
            'FLAGS_DO_CORR_USED': cls.__constants['FLAGS_DO_CORR_USED'],
        }

    @property
    def FLAGS_QUALITY_IND_MASK(self):
        """Message constant 'FLAGS_QUALITY_IND_MASK'."""
        return Metaclass_NavSATSV.__constants['FLAGS_QUALITY_IND_MASK']

    @property
    def QUALITY_IND_NO_SIGNAL(self):
        """Message constant 'QUALITY_IND_NO_SIGNAL'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_NO_SIGNAL']

    @property
    def QUALITY_IND_SEARCHING_SIGNAL(self):
        """Message constant 'QUALITY_IND_SEARCHING_SIGNAL'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_SEARCHING_SIGNAL']

    @property
    def QUALITY_IND_SIGNAL_ACQUIRED(self):
        """Message constant 'QUALITY_IND_SIGNAL_ACQUIRED'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_SIGNAL_ACQUIRED']

    @property
    def QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE(self):
        """Message constant 'QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE']

    @property
    def QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC(self):
        """Message constant 'QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC']

    @property
    def QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1(self):
        """Message constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1']

    @property
    def QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2(self):
        """Message constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2']

    @property
    def QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3(self):
        """Message constant 'QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3'."""
        return Metaclass_NavSATSV.__constants['QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3']

    @property
    def FLAGS_SV_USED(self):
        """Message constant 'FLAGS_SV_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_SV_USED']

    @property
    def FLAGS_HEALTH_MASK(self):
        """Message constant 'FLAGS_HEALTH_MASK'."""
        return Metaclass_NavSATSV.__constants['FLAGS_HEALTH_MASK']

    @property
    def HEALTH_UNKNOWN(self):
        """Message constant 'HEALTH_UNKNOWN'."""
        return Metaclass_NavSATSV.__constants['HEALTH_UNKNOWN']

    @property
    def HEALTH_HEALTHY(self):
        """Message constant 'HEALTH_HEALTHY'."""
        return Metaclass_NavSATSV.__constants['HEALTH_HEALTHY']

    @property
    def HEALTH_UNHEALTHY(self):
        """Message constant 'HEALTH_UNHEALTHY'."""
        return Metaclass_NavSATSV.__constants['HEALTH_UNHEALTHY']

    @property
    def FLAGS_DIFF_CORR(self):
        """Message constant 'FLAGS_DIFF_CORR'."""
        return Metaclass_NavSATSV.__constants['FLAGS_DIFF_CORR']

    @property
    def FLAGS_SMOOTHED(self):
        """Message constant 'FLAGS_SMOOTHED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_SMOOTHED']

    @property
    def FLAGS_ORBIT_SOURCE_MASK(self):
        """Message constant 'FLAGS_ORBIT_SOURCE_MASK'."""
        return Metaclass_NavSATSV.__constants['FLAGS_ORBIT_SOURCE_MASK']

    @property
    def ORBIT_SOURCE_UNAVAILABLE(self):
        """Message constant 'ORBIT_SOURCE_UNAVAILABLE'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_UNAVAILABLE']

    @property
    def ORBIT_SOURCE_EPH(self):
        """Message constant 'ORBIT_SOURCE_EPH'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_EPH']

    @property
    def ORBIT_SOURCE_ALM(self):
        """Message constant 'ORBIT_SOURCE_ALM'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_ALM']

    @property
    def ORBIT_SOURCE_ASSIST_OFFLINE(self):
        """Message constant 'ORBIT_SOURCE_ASSIST_OFFLINE'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_ASSIST_OFFLINE']

    @property
    def ORBIT_SOURCE_ASSIST_AUTONOMOUS(self):
        """Message constant 'ORBIT_SOURCE_ASSIST_AUTONOMOUS'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_ASSIST_AUTONOMOUS']

    @property
    def ORBIT_SOURCE_OTHER1(self):
        """Message constant 'ORBIT_SOURCE_OTHER1'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_OTHER1']

    @property
    def ORBIT_SOURCE_OTHER2(self):
        """Message constant 'ORBIT_SOURCE_OTHER2'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_OTHER2']

    @property
    def ORBIT_SOURCE_OTHER3(self):
        """Message constant 'ORBIT_SOURCE_OTHER3'."""
        return Metaclass_NavSATSV.__constants['ORBIT_SOURCE_OTHER3']

    @property
    def FLAGS_EPH_AVAIL(self):
        """Message constant 'FLAGS_EPH_AVAIL'."""
        return Metaclass_NavSATSV.__constants['FLAGS_EPH_AVAIL']

    @property
    def FLAGS_ALM_AVAIL(self):
        """Message constant 'FLAGS_ALM_AVAIL'."""
        return Metaclass_NavSATSV.__constants['FLAGS_ALM_AVAIL']

    @property
    def FLAGS_ANO_AVAIL(self):
        """Message constant 'FLAGS_ANO_AVAIL'."""
        return Metaclass_NavSATSV.__constants['FLAGS_ANO_AVAIL']

    @property
    def FLAGS_AOP_AVAIL(self):
        """Message constant 'FLAGS_AOP_AVAIL'."""
        return Metaclass_NavSATSV.__constants['FLAGS_AOP_AVAIL']

    @property
    def FLAGS_SBAS_CORR_USED(self):
        """Message constant 'FLAGS_SBAS_CORR_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_SBAS_CORR_USED']

    @property
    def FLAGS_RTCM_CORR_USED(self):
        """Message constant 'FLAGS_RTCM_CORR_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_RTCM_CORR_USED']

    @property
    def FLAGS_PR_CORR_USED(self):
        """Message constant 'FLAGS_PR_CORR_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_PR_CORR_USED']

    @property
    def FLAGS_CR_CORR_USED(self):
        """Message constant 'FLAGS_CR_CORR_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_CR_CORR_USED']

    @property
    def FLAGS_DO_CORR_USED(self):
        """Message constant 'FLAGS_DO_CORR_USED'."""
        return Metaclass_NavSATSV.__constants['FLAGS_DO_CORR_USED']


class NavSATSV(metaclass=Metaclass_NavSATSV):
    """
    Message class 'NavSATSV'.

    Constants:
      FLAGS_QUALITY_IND_MASK
      QUALITY_IND_NO_SIGNAL
      QUALITY_IND_SEARCHING_SIGNAL
      QUALITY_IND_SIGNAL_ACQUIRED
      QUALITY_IND_SIGNAL_DETECTED_BUT_UNUSABLE
      QUALITY_IND_CODE_LOCKED_AND_TIME_SYNC
      QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC1
      QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC2
      QUALITY_IND_CODE_AND_CARR_LOCK_AND_TIME_SYNC3
      FLAGS_SV_USED
      FLAGS_HEALTH_MASK
      HEALTH_UNKNOWN
      HEALTH_HEALTHY
      HEALTH_UNHEALTHY
      FLAGS_DIFF_CORR
      FLAGS_SMOOTHED
      FLAGS_ORBIT_SOURCE_MASK
      ORBIT_SOURCE_UNAVAILABLE
      ORBIT_SOURCE_EPH
      ORBIT_SOURCE_ALM
      ORBIT_SOURCE_ASSIST_OFFLINE
      ORBIT_SOURCE_ASSIST_AUTONOMOUS
      ORBIT_SOURCE_OTHER1
      ORBIT_SOURCE_OTHER2
      ORBIT_SOURCE_OTHER3
      FLAGS_EPH_AVAIL
      FLAGS_ALM_AVAIL
      FLAGS_ANO_AVAIL
      FLAGS_AOP_AVAIL
      FLAGS_SBAS_CORR_USED
      FLAGS_RTCM_CORR_USED
      FLAGS_PR_CORR_USED
      FLAGS_CR_CORR_USED
      FLAGS_DO_CORR_USED
    """

    __slots__ = [
        '_gnss_id',
        '_sv_id',
        '_cno',
        '_elev',
        '_azim',
        '_pr_res',
        '_flags',
    ]

    _fields_and_field_types = {
        'gnss_id': 'uint8',
        'sv_id': 'uint8',
        'cno': 'uint8',
        'elev': 'int8',
        'azim': 'int16',
        'pr_res': 'int16',
        'flags': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gnss_id = kwargs.get('gnss_id', int())
        self.sv_id = kwargs.get('sv_id', int())
        self.cno = kwargs.get('cno', int())
        self.elev = kwargs.get('elev', int())
        self.azim = kwargs.get('azim', int())
        self.pr_res = kwargs.get('pr_res', int())
        self.flags = kwargs.get('flags', int())

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
        if self.gnss_id != other.gnss_id:
            return False
        if self.sv_id != other.sv_id:
            return False
        if self.cno != other.cno:
            return False
        if self.elev != other.elev:
            return False
        if self.azim != other.azim:
            return False
        if self.pr_res != other.pr_res:
            return False
        if self.flags != other.flags:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
            assert value >= -32768 and value < 32768, \
                "The 'pr_res' field must be an integer in [-32768, 32767]"
        self._pr_res = value

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
            assert value >= 0 and value < 4294967296, \
                "The 'flags' field must be an unsigned integer in [0, 4294967295]"
        self._flags = value
