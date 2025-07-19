# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgGNSSBlock.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgGNSSBlock(type):
    """Metaclass of message 'CfgGNSSBlock'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GNSS_ID_GPS': 0,
        'GNSS_ID_SBAS': 1,
        'GNSS_ID_GALILEO': 2,
        'GNSS_ID_BEIDOU': 3,
        'GNSS_ID_IMES': 4,
        'GNSS_ID_QZSS': 5,
        'GNSS_ID_GLONASS': 6,
        'RES_TRK_CH_GPS': 8,
        'RES_TRK_CH_QZSS': 0,
        'RES_TRK_CH_SBAS': 0,
        'RES_TRK_CH_GLONASS': 8,
        'MAX_TRK_CH_MAJOR_MIN': 4,
        'MAX_TRK_CH_GPS': 16,
        'MAX_TRK_CH_GLONASS': 14,
        'MAX_TRK_CH_QZSS': 3,
        'MAX_TRK_CH_SBAS': 3,
        'FLAGS_ENABLE': 1,
        'FLAGS_SIG_CFG_MASK': 16711680,
        'SIG_CFG_GPS_L1CA': 65536,
        'SIG_CFG_SBAS_L1CA': 65536,
        'SIG_CFG_GALILEO_E1OS': 65536,
        'SIG_CFG_BEIDOU_B1I': 65536,
        'SIG_CFG_IMES_L1': 65536,
        'SIG_CFG_QZSS_L1CA': 65536,
        'SIG_CFG_QZSS_L1SAIF': 262144,
        'SIG_CFG_GLONASS_L1OF': 65536,
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
                'ublox_msgs.msg.CfgGNSSBlock')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_gnss_block
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_gnss_block
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_gnss_block
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_gnss_block
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_gnss_block

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GNSS_ID_GPS': cls.__constants['GNSS_ID_GPS'],
            'GNSS_ID_SBAS': cls.__constants['GNSS_ID_SBAS'],
            'GNSS_ID_GALILEO': cls.__constants['GNSS_ID_GALILEO'],
            'GNSS_ID_BEIDOU': cls.__constants['GNSS_ID_BEIDOU'],
            'GNSS_ID_IMES': cls.__constants['GNSS_ID_IMES'],
            'GNSS_ID_QZSS': cls.__constants['GNSS_ID_QZSS'],
            'GNSS_ID_GLONASS': cls.__constants['GNSS_ID_GLONASS'],
            'RES_TRK_CH_GPS': cls.__constants['RES_TRK_CH_GPS'],
            'RES_TRK_CH_QZSS': cls.__constants['RES_TRK_CH_QZSS'],
            'RES_TRK_CH_SBAS': cls.__constants['RES_TRK_CH_SBAS'],
            'RES_TRK_CH_GLONASS': cls.__constants['RES_TRK_CH_GLONASS'],
            'MAX_TRK_CH_MAJOR_MIN': cls.__constants['MAX_TRK_CH_MAJOR_MIN'],
            'MAX_TRK_CH_GPS': cls.__constants['MAX_TRK_CH_GPS'],
            'MAX_TRK_CH_GLONASS': cls.__constants['MAX_TRK_CH_GLONASS'],
            'MAX_TRK_CH_QZSS': cls.__constants['MAX_TRK_CH_QZSS'],
            'MAX_TRK_CH_SBAS': cls.__constants['MAX_TRK_CH_SBAS'],
            'FLAGS_ENABLE': cls.__constants['FLAGS_ENABLE'],
            'FLAGS_SIG_CFG_MASK': cls.__constants['FLAGS_SIG_CFG_MASK'],
            'SIG_CFG_GPS_L1CA': cls.__constants['SIG_CFG_GPS_L1CA'],
            'SIG_CFG_SBAS_L1CA': cls.__constants['SIG_CFG_SBAS_L1CA'],
            'SIG_CFG_GALILEO_E1OS': cls.__constants['SIG_CFG_GALILEO_E1OS'],
            'SIG_CFG_BEIDOU_B1I': cls.__constants['SIG_CFG_BEIDOU_B1I'],
            'SIG_CFG_IMES_L1': cls.__constants['SIG_CFG_IMES_L1'],
            'SIG_CFG_QZSS_L1CA': cls.__constants['SIG_CFG_QZSS_L1CA'],
            'SIG_CFG_QZSS_L1SAIF': cls.__constants['SIG_CFG_QZSS_L1SAIF'],
            'SIG_CFG_GLONASS_L1OF': cls.__constants['SIG_CFG_GLONASS_L1OF'],
        }

    @property
    def GNSS_ID_GPS(self):
        """Message constant 'GNSS_ID_GPS'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_GPS']

    @property
    def GNSS_ID_SBAS(self):
        """Message constant 'GNSS_ID_SBAS'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_SBAS']

    @property
    def GNSS_ID_GALILEO(self):
        """Message constant 'GNSS_ID_GALILEO'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_GALILEO']

    @property
    def GNSS_ID_BEIDOU(self):
        """Message constant 'GNSS_ID_BEIDOU'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_BEIDOU']

    @property
    def GNSS_ID_IMES(self):
        """Message constant 'GNSS_ID_IMES'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_IMES']

    @property
    def GNSS_ID_QZSS(self):
        """Message constant 'GNSS_ID_QZSS'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_QZSS']

    @property
    def GNSS_ID_GLONASS(self):
        """Message constant 'GNSS_ID_GLONASS'."""
        return Metaclass_CfgGNSSBlock.__constants['GNSS_ID_GLONASS']

    @property
    def RES_TRK_CH_GPS(self):
        """Message constant 'RES_TRK_CH_GPS'."""
        return Metaclass_CfgGNSSBlock.__constants['RES_TRK_CH_GPS']

    @property
    def RES_TRK_CH_QZSS(self):
        """Message constant 'RES_TRK_CH_QZSS'."""
        return Metaclass_CfgGNSSBlock.__constants['RES_TRK_CH_QZSS']

    @property
    def RES_TRK_CH_SBAS(self):
        """Message constant 'RES_TRK_CH_SBAS'."""
        return Metaclass_CfgGNSSBlock.__constants['RES_TRK_CH_SBAS']

    @property
    def RES_TRK_CH_GLONASS(self):
        """Message constant 'RES_TRK_CH_GLONASS'."""
        return Metaclass_CfgGNSSBlock.__constants['RES_TRK_CH_GLONASS']

    @property
    def MAX_TRK_CH_MAJOR_MIN(self):
        """Message constant 'MAX_TRK_CH_MAJOR_MIN'."""
        return Metaclass_CfgGNSSBlock.__constants['MAX_TRK_CH_MAJOR_MIN']

    @property
    def MAX_TRK_CH_GPS(self):
        """Message constant 'MAX_TRK_CH_GPS'."""
        return Metaclass_CfgGNSSBlock.__constants['MAX_TRK_CH_GPS']

    @property
    def MAX_TRK_CH_GLONASS(self):
        """Message constant 'MAX_TRK_CH_GLONASS'."""
        return Metaclass_CfgGNSSBlock.__constants['MAX_TRK_CH_GLONASS']

    @property
    def MAX_TRK_CH_QZSS(self):
        """Message constant 'MAX_TRK_CH_QZSS'."""
        return Metaclass_CfgGNSSBlock.__constants['MAX_TRK_CH_QZSS']

    @property
    def MAX_TRK_CH_SBAS(self):
        """Message constant 'MAX_TRK_CH_SBAS'."""
        return Metaclass_CfgGNSSBlock.__constants['MAX_TRK_CH_SBAS']

    @property
    def FLAGS_ENABLE(self):
        """Message constant 'FLAGS_ENABLE'."""
        return Metaclass_CfgGNSSBlock.__constants['FLAGS_ENABLE']

    @property
    def FLAGS_SIG_CFG_MASK(self):
        """Message constant 'FLAGS_SIG_CFG_MASK'."""
        return Metaclass_CfgGNSSBlock.__constants['FLAGS_SIG_CFG_MASK']

    @property
    def SIG_CFG_GPS_L1CA(self):
        """Message constant 'SIG_CFG_GPS_L1CA'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_GPS_L1CA']

    @property
    def SIG_CFG_SBAS_L1CA(self):
        """Message constant 'SIG_CFG_SBAS_L1CA'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_SBAS_L1CA']

    @property
    def SIG_CFG_GALILEO_E1OS(self):
        """Message constant 'SIG_CFG_GALILEO_E1OS'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_GALILEO_E1OS']

    @property
    def SIG_CFG_BEIDOU_B1I(self):
        """Message constant 'SIG_CFG_BEIDOU_B1I'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_BEIDOU_B1I']

    @property
    def SIG_CFG_IMES_L1(self):
        """Message constant 'SIG_CFG_IMES_L1'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_IMES_L1']

    @property
    def SIG_CFG_QZSS_L1CA(self):
        """Message constant 'SIG_CFG_QZSS_L1CA'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_QZSS_L1CA']

    @property
    def SIG_CFG_QZSS_L1SAIF(self):
        """Message constant 'SIG_CFG_QZSS_L1SAIF'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_QZSS_L1SAIF']

    @property
    def SIG_CFG_GLONASS_L1OF(self):
        """Message constant 'SIG_CFG_GLONASS_L1OF'."""
        return Metaclass_CfgGNSSBlock.__constants['SIG_CFG_GLONASS_L1OF']


class CfgGNSSBlock(metaclass=Metaclass_CfgGNSSBlock):
    """
    Message class 'CfgGNSSBlock'.

    Constants:
      GNSS_ID_GPS
      GNSS_ID_SBAS
      GNSS_ID_GALILEO
      GNSS_ID_BEIDOU
      GNSS_ID_IMES
      GNSS_ID_QZSS
      GNSS_ID_GLONASS
      RES_TRK_CH_GPS
      RES_TRK_CH_QZSS
      RES_TRK_CH_SBAS
      RES_TRK_CH_GLONASS
      MAX_TRK_CH_MAJOR_MIN
      MAX_TRK_CH_GPS
      MAX_TRK_CH_GLONASS
      MAX_TRK_CH_QZSS
      MAX_TRK_CH_SBAS
      FLAGS_ENABLE
      FLAGS_SIG_CFG_MASK
      SIG_CFG_GPS_L1CA
      SIG_CFG_SBAS_L1CA
      SIG_CFG_GALILEO_E1OS
      SIG_CFG_BEIDOU_B1I
      SIG_CFG_IMES_L1
      SIG_CFG_QZSS_L1CA
      SIG_CFG_QZSS_L1SAIF
      SIG_CFG_GLONASS_L1OF
    """

    __slots__ = [
        '_gnss_id',
        '_res_trk_ch',
        '_max_trk_ch',
        '_reserved1',
        '_flags',
    ]

    _fields_and_field_types = {
        'gnss_id': 'uint8',
        'res_trk_ch': 'uint8',
        'max_trk_ch': 'uint8',
        'reserved1': 'uint8',
        'flags': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.gnss_id = kwargs.get('gnss_id', int())
        self.res_trk_ch = kwargs.get('res_trk_ch', int())
        self.max_trk_ch = kwargs.get('max_trk_ch', int())
        self.reserved1 = kwargs.get('reserved1', int())
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
        if self.res_trk_ch != other.res_trk_ch:
            return False
        if self.max_trk_ch != other.max_trk_ch:
            return False
        if self.reserved1 != other.reserved1:
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
    def res_trk_ch(self):
        """Message field 'res_trk_ch'."""
        return self._res_trk_ch

    @res_trk_ch.setter
    def res_trk_ch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'res_trk_ch' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'res_trk_ch' field must be an unsigned integer in [0, 255]"
        self._res_trk_ch = value

    @builtins.property
    def max_trk_ch(self):
        """Message field 'max_trk_ch'."""
        return self._max_trk_ch

    @max_trk_ch.setter
    def max_trk_ch(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_trk_ch' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'max_trk_ch' field must be an unsigned integer in [0, 255]"
        self._max_trk_ch = value

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
