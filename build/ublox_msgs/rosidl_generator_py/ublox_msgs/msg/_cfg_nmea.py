# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgNMEA.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'bds_talker_id'
# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgNMEA(type):
    """Metaclass of message 'CfgNMEA'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 23,
        'FILTER_POS': 1,
        'FILTER_MSK_POS': 2,
        'FILTER_TIME': 4,
        'FILTER_DATE': 8,
        'FILTER_GPS_ONLY': 16,
        'FILTER_TRACK': 32,
        'NMEA_VERSION_4_1': 65,
        'NMEA_VERSION_4_0': 64,
        'NMEA_VERSION_2_3': 35,
        'NMEA_VERSION_2_1': 33,
        'NUM_SV_UNLIMITED': 0,
        'FLAGS_COMPAT': 1,
        'FLAGS_CONSIDER': 2,
        'FLAGS_LIMIT82': 4,
        'FLAGS_HIGH_PREC': 8,
        'GNSS_TO_FILTER_GPS': 1,
        'GNSS_TO_FILTER_SBAS': 2,
        'GNSS_TO_FILTER_QZSS': 16,
        'GNSS_TO_FILTER_GLONASS': 32,
        'GNSS_TO_FILTER_BEIDOU': 64,
        'SV_NUMBERING_STRICT': 0,
        'SV_NUMBERING_EXTENDED': 1,
        'MAIN_TALKER_ID_NOT_OVERRIDDEN': 0,
        'MAIN_TALKER_ID_GP': 1,
        'MAIN_TALKER_ID_GL': 2,
        'MAIN_TALKER_ID_GN': 3,
        'MAIN_TALKER_ID_GA': 4,
        'MAIN_TALKER_ID_GB': 5,
        'GSV_TALKER_ID_GNSS_SPECIFIC': 0,
        'GSV_TALKER_ID_MAIN': 1,
        'VERSION': 1,
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
                'ublox_msgs.msg.CfgNMEA')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_nmea
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_nmea
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_nmea
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_nmea
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_nmea

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FILTER_POS': cls.__constants['FILTER_POS'],
            'FILTER_MSK_POS': cls.__constants['FILTER_MSK_POS'],
            'FILTER_TIME': cls.__constants['FILTER_TIME'],
            'FILTER_DATE': cls.__constants['FILTER_DATE'],
            'FILTER_GPS_ONLY': cls.__constants['FILTER_GPS_ONLY'],
            'FILTER_TRACK': cls.__constants['FILTER_TRACK'],
            'NMEA_VERSION_4_1': cls.__constants['NMEA_VERSION_4_1'],
            'NMEA_VERSION_4_0': cls.__constants['NMEA_VERSION_4_0'],
            'NMEA_VERSION_2_3': cls.__constants['NMEA_VERSION_2_3'],
            'NMEA_VERSION_2_1': cls.__constants['NMEA_VERSION_2_1'],
            'NUM_SV_UNLIMITED': cls.__constants['NUM_SV_UNLIMITED'],
            'FLAGS_COMPAT': cls.__constants['FLAGS_COMPAT'],
            'FLAGS_CONSIDER': cls.__constants['FLAGS_CONSIDER'],
            'FLAGS_LIMIT82': cls.__constants['FLAGS_LIMIT82'],
            'FLAGS_HIGH_PREC': cls.__constants['FLAGS_HIGH_PREC'],
            'GNSS_TO_FILTER_GPS': cls.__constants['GNSS_TO_FILTER_GPS'],
            'GNSS_TO_FILTER_SBAS': cls.__constants['GNSS_TO_FILTER_SBAS'],
            'GNSS_TO_FILTER_QZSS': cls.__constants['GNSS_TO_FILTER_QZSS'],
            'GNSS_TO_FILTER_GLONASS': cls.__constants['GNSS_TO_FILTER_GLONASS'],
            'GNSS_TO_FILTER_BEIDOU': cls.__constants['GNSS_TO_FILTER_BEIDOU'],
            'SV_NUMBERING_STRICT': cls.__constants['SV_NUMBERING_STRICT'],
            'SV_NUMBERING_EXTENDED': cls.__constants['SV_NUMBERING_EXTENDED'],
            'MAIN_TALKER_ID_NOT_OVERRIDDEN': cls.__constants['MAIN_TALKER_ID_NOT_OVERRIDDEN'],
            'MAIN_TALKER_ID_GP': cls.__constants['MAIN_TALKER_ID_GP'],
            'MAIN_TALKER_ID_GL': cls.__constants['MAIN_TALKER_ID_GL'],
            'MAIN_TALKER_ID_GN': cls.__constants['MAIN_TALKER_ID_GN'],
            'MAIN_TALKER_ID_GA': cls.__constants['MAIN_TALKER_ID_GA'],
            'MAIN_TALKER_ID_GB': cls.__constants['MAIN_TALKER_ID_GB'],
            'GSV_TALKER_ID_GNSS_SPECIFIC': cls.__constants['GSV_TALKER_ID_GNSS_SPECIFIC'],
            'GSV_TALKER_ID_MAIN': cls.__constants['GSV_TALKER_ID_MAIN'],
            'VERSION': cls.__constants['VERSION'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgNMEA.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgNMEA.__constants['MESSAGE_ID']

    @property
    def FILTER_POS(self):
        """Message constant 'FILTER_POS'."""
        return Metaclass_CfgNMEA.__constants['FILTER_POS']

    @property
    def FILTER_MSK_POS(self):
        """Message constant 'FILTER_MSK_POS'."""
        return Metaclass_CfgNMEA.__constants['FILTER_MSK_POS']

    @property
    def FILTER_TIME(self):
        """Message constant 'FILTER_TIME'."""
        return Metaclass_CfgNMEA.__constants['FILTER_TIME']

    @property
    def FILTER_DATE(self):
        """Message constant 'FILTER_DATE'."""
        return Metaclass_CfgNMEA.__constants['FILTER_DATE']

    @property
    def FILTER_GPS_ONLY(self):
        """Message constant 'FILTER_GPS_ONLY'."""
        return Metaclass_CfgNMEA.__constants['FILTER_GPS_ONLY']

    @property
    def FILTER_TRACK(self):
        """Message constant 'FILTER_TRACK'."""
        return Metaclass_CfgNMEA.__constants['FILTER_TRACK']

    @property
    def NMEA_VERSION_4_1(self):
        """Message constant 'NMEA_VERSION_4_1'."""
        return Metaclass_CfgNMEA.__constants['NMEA_VERSION_4_1']

    @property
    def NMEA_VERSION_4_0(self):
        """Message constant 'NMEA_VERSION_4_0'."""
        return Metaclass_CfgNMEA.__constants['NMEA_VERSION_4_0']

    @property
    def NMEA_VERSION_2_3(self):
        """Message constant 'NMEA_VERSION_2_3'."""
        return Metaclass_CfgNMEA.__constants['NMEA_VERSION_2_3']

    @property
    def NMEA_VERSION_2_1(self):
        """Message constant 'NMEA_VERSION_2_1'."""
        return Metaclass_CfgNMEA.__constants['NMEA_VERSION_2_1']

    @property
    def NUM_SV_UNLIMITED(self):
        """Message constant 'NUM_SV_UNLIMITED'."""
        return Metaclass_CfgNMEA.__constants['NUM_SV_UNLIMITED']

    @property
    def FLAGS_COMPAT(self):
        """Message constant 'FLAGS_COMPAT'."""
        return Metaclass_CfgNMEA.__constants['FLAGS_COMPAT']

    @property
    def FLAGS_CONSIDER(self):
        """Message constant 'FLAGS_CONSIDER'."""
        return Metaclass_CfgNMEA.__constants['FLAGS_CONSIDER']

    @property
    def FLAGS_LIMIT82(self):
        """Message constant 'FLAGS_LIMIT82'."""
        return Metaclass_CfgNMEA.__constants['FLAGS_LIMIT82']

    @property
    def FLAGS_HIGH_PREC(self):
        """Message constant 'FLAGS_HIGH_PREC'."""
        return Metaclass_CfgNMEA.__constants['FLAGS_HIGH_PREC']

    @property
    def GNSS_TO_FILTER_GPS(self):
        """Message constant 'GNSS_TO_FILTER_GPS'."""
        return Metaclass_CfgNMEA.__constants['GNSS_TO_FILTER_GPS']

    @property
    def GNSS_TO_FILTER_SBAS(self):
        """Message constant 'GNSS_TO_FILTER_SBAS'."""
        return Metaclass_CfgNMEA.__constants['GNSS_TO_FILTER_SBAS']

    @property
    def GNSS_TO_FILTER_QZSS(self):
        """Message constant 'GNSS_TO_FILTER_QZSS'."""
        return Metaclass_CfgNMEA.__constants['GNSS_TO_FILTER_QZSS']

    @property
    def GNSS_TO_FILTER_GLONASS(self):
        """Message constant 'GNSS_TO_FILTER_GLONASS'."""
        return Metaclass_CfgNMEA.__constants['GNSS_TO_FILTER_GLONASS']

    @property
    def GNSS_TO_FILTER_BEIDOU(self):
        """Message constant 'GNSS_TO_FILTER_BEIDOU'."""
        return Metaclass_CfgNMEA.__constants['GNSS_TO_FILTER_BEIDOU']

    @property
    def SV_NUMBERING_STRICT(self):
        """Message constant 'SV_NUMBERING_STRICT'."""
        return Metaclass_CfgNMEA.__constants['SV_NUMBERING_STRICT']

    @property
    def SV_NUMBERING_EXTENDED(self):
        """Message constant 'SV_NUMBERING_EXTENDED'."""
        return Metaclass_CfgNMEA.__constants['SV_NUMBERING_EXTENDED']

    @property
    def MAIN_TALKER_ID_NOT_OVERRIDDEN(self):
        """Message constant 'MAIN_TALKER_ID_NOT_OVERRIDDEN'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_NOT_OVERRIDDEN']

    @property
    def MAIN_TALKER_ID_GP(self):
        """Message constant 'MAIN_TALKER_ID_GP'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_GP']

    @property
    def MAIN_TALKER_ID_GL(self):
        """Message constant 'MAIN_TALKER_ID_GL'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_GL']

    @property
    def MAIN_TALKER_ID_GN(self):
        """Message constant 'MAIN_TALKER_ID_GN'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_GN']

    @property
    def MAIN_TALKER_ID_GA(self):
        """Message constant 'MAIN_TALKER_ID_GA'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_GA']

    @property
    def MAIN_TALKER_ID_GB(self):
        """Message constant 'MAIN_TALKER_ID_GB'."""
        return Metaclass_CfgNMEA.__constants['MAIN_TALKER_ID_GB']

    @property
    def GSV_TALKER_ID_GNSS_SPECIFIC(self):
        """Message constant 'GSV_TALKER_ID_GNSS_SPECIFIC'."""
        return Metaclass_CfgNMEA.__constants['GSV_TALKER_ID_GNSS_SPECIFIC']

    @property
    def GSV_TALKER_ID_MAIN(self):
        """Message constant 'GSV_TALKER_ID_MAIN'."""
        return Metaclass_CfgNMEA.__constants['GSV_TALKER_ID_MAIN']

    @property
    def VERSION(self):
        """Message constant 'VERSION'."""
        return Metaclass_CfgNMEA.__constants['VERSION']


class CfgNMEA(metaclass=Metaclass_CfgNMEA):
    """
    Message class 'CfgNMEA'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FILTER_POS
      FILTER_MSK_POS
      FILTER_TIME
      FILTER_DATE
      FILTER_GPS_ONLY
      FILTER_TRACK
      NMEA_VERSION_4_1
      NMEA_VERSION_4_0
      NMEA_VERSION_2_3
      NMEA_VERSION_2_1
      NUM_SV_UNLIMITED
      FLAGS_COMPAT
      FLAGS_CONSIDER
      FLAGS_LIMIT82
      FLAGS_HIGH_PREC
      GNSS_TO_FILTER_GPS
      GNSS_TO_FILTER_SBAS
      GNSS_TO_FILTER_QZSS
      GNSS_TO_FILTER_GLONASS
      GNSS_TO_FILTER_BEIDOU
      SV_NUMBERING_STRICT
      SV_NUMBERING_EXTENDED
      MAIN_TALKER_ID_NOT_OVERRIDDEN
      MAIN_TALKER_ID_GP
      MAIN_TALKER_ID_GL
      MAIN_TALKER_ID_GN
      MAIN_TALKER_ID_GA
      MAIN_TALKER_ID_GB
      GSV_TALKER_ID_GNSS_SPECIFIC
      GSV_TALKER_ID_MAIN
      VERSION
    """

    __slots__ = [
        '_filter',
        '_nmea_version',
        '_num_sv',
        '_flags',
        '_gnss_to_filter',
        '_sv_numbering',
        '_main_talker_id',
        '_gsv_talker_id',
        '_version',
        '_bds_talker_id',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'filter': 'uint8',
        'nmea_version': 'uint8',
        'num_sv': 'uint8',
        'flags': 'uint8',
        'gnss_to_filter': 'uint32',
        'sv_numbering': 'uint8',
        'main_talker_id': 'uint8',
        'gsv_talker_id': 'uint8',
        'version': 'uint8',
        'bds_talker_id': 'uint8[2]',
        'reserved1': 'uint8[6]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 6),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.filter = kwargs.get('filter', int())
        self.nmea_version = kwargs.get('nmea_version', int())
        self.num_sv = kwargs.get('num_sv', int())
        self.flags = kwargs.get('flags', int())
        self.gnss_to_filter = kwargs.get('gnss_to_filter', int())
        self.sv_numbering = kwargs.get('sv_numbering', int())
        self.main_talker_id = kwargs.get('main_talker_id', int())
        self.gsv_talker_id = kwargs.get('gsv_talker_id', int())
        self.version = kwargs.get('version', int())
        if 'bds_talker_id' not in kwargs:
            self.bds_talker_id = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.bds_talker_id = numpy.array(kwargs.get('bds_talker_id'), dtype=numpy.uint8)
            assert self.bds_talker_id.shape == (2, )
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(6, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (6, )

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
        if self.filter != other.filter:
            return False
        if self.nmea_version != other.nmea_version:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.flags != other.flags:
            return False
        if self.gnss_to_filter != other.gnss_to_filter:
            return False
        if self.sv_numbering != other.sv_numbering:
            return False
        if self.main_talker_id != other.main_talker_id:
            return False
        if self.gsv_talker_id != other.gsv_talker_id:
            return False
        if self.version != other.version:
            return False
        if all(self.bds_talker_id != other.bds_talker_id):
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property  # noqa: A003
    def filter(self):  # noqa: A003
        """Message field 'filter'."""
        return self._filter

    @filter.setter  # noqa: A003
    def filter(self, value):  # noqa: A003
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'filter' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'filter' field must be an unsigned integer in [0, 255]"
        self._filter = value

    @builtins.property
    def nmea_version(self):
        """Message field 'nmea_version'."""
        return self._nmea_version

    @nmea_version.setter
    def nmea_version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nmea_version' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'nmea_version' field must be an unsigned integer in [0, 255]"
        self._nmea_version = value

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
    def gnss_to_filter(self):
        """Message field 'gnss_to_filter'."""
        return self._gnss_to_filter

    @gnss_to_filter.setter
    def gnss_to_filter(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gnss_to_filter' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'gnss_to_filter' field must be an unsigned integer in [0, 4294967295]"
        self._gnss_to_filter = value

    @builtins.property
    def sv_numbering(self):
        """Message field 'sv_numbering'."""
        return self._sv_numbering

    @sv_numbering.setter
    def sv_numbering(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_numbering' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_numbering' field must be an unsigned integer in [0, 255]"
        self._sv_numbering = value

    @builtins.property
    def main_talker_id(self):
        """Message field 'main_talker_id'."""
        return self._main_talker_id

    @main_talker_id.setter
    def main_talker_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'main_talker_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'main_talker_id' field must be an unsigned integer in [0, 255]"
        self._main_talker_id = value

    @builtins.property
    def gsv_talker_id(self):
        """Message field 'gsv_talker_id'."""
        return self._gsv_talker_id

    @gsv_talker_id.setter
    def gsv_talker_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gsv_talker_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gsv_talker_id' field must be an unsigned integer in [0, 255]"
        self._gsv_talker_id = value

    @builtins.property
    def version(self):
        """Message field 'version'."""
        return self._version

    @version.setter
    def version(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'version' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'version' field must be an unsigned integer in [0, 255]"
        self._version = value

    @builtins.property
    def bds_talker_id(self):
        """Message field 'bds_talker_id'."""
        return self._bds_talker_id

    @bds_talker_id.setter
    def bds_talker_id(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'bds_talker_id' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'bds_talker_id' numpy.ndarray() must have a size of 2"
            self._bds_talker_id = value
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
                "The 'bds_talker_id' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._bds_talker_id = numpy.array(value, dtype=numpy.uint8)

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
