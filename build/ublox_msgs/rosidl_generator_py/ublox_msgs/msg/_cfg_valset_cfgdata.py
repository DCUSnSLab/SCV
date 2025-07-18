# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgVALSETCfgdata.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'data'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgVALSETCfgdata(type):
    """Metaclass of message 'CfgVALSETCfgdata'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'GPS_ENABLE': 271646751,
        'GPS_L1CA_ENABLE': 271646721,
        'GPS_L2C_ENABLE': 271646723,
        'SBAS_ENABLE': 271646752,
        'SBAS_L1CA_ENABLE': 271646725,
        'GAL_ENABLE': 271646753,
        'GAL_E1_ENABLE': 271646727,
        'GAL_E5B_ENABLE': 271646730,
        'BDS_ENABLE': 271646754,
        'BDS_B1_ENABLE': 271646733,
        'BDS_B2_ENABLE': 271646734,
        'QZSS_ENABLE': 271646756,
        'QZSS_L1CA_ENABLE': 271646738,
        'QZSS_L1S_ENABLE': 271646740,
        'QZSS_L2C_ENABLE': 271646741,
        'GLO_ENABLE': 271646757,
        'GLO_L1_ENABLE': 271646744,
        'GLO_L2_ENABLE': 271646746,
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
                'ublox_msgs.msg.CfgVALSETCfgdata')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_valset_cfgdata
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_valset_cfgdata
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_valset_cfgdata
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_valset_cfgdata
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_valset_cfgdata

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'GPS_ENABLE': cls.__constants['GPS_ENABLE'],
            'GPS_L1CA_ENABLE': cls.__constants['GPS_L1CA_ENABLE'],
            'GPS_L2C_ENABLE': cls.__constants['GPS_L2C_ENABLE'],
            'SBAS_ENABLE': cls.__constants['SBAS_ENABLE'],
            'SBAS_L1CA_ENABLE': cls.__constants['SBAS_L1CA_ENABLE'],
            'GAL_ENABLE': cls.__constants['GAL_ENABLE'],
            'GAL_E1_ENABLE': cls.__constants['GAL_E1_ENABLE'],
            'GAL_E5B_ENABLE': cls.__constants['GAL_E5B_ENABLE'],
            'BDS_ENABLE': cls.__constants['BDS_ENABLE'],
            'BDS_B1_ENABLE': cls.__constants['BDS_B1_ENABLE'],
            'BDS_B2_ENABLE': cls.__constants['BDS_B2_ENABLE'],
            'QZSS_ENABLE': cls.__constants['QZSS_ENABLE'],
            'QZSS_L1CA_ENABLE': cls.__constants['QZSS_L1CA_ENABLE'],
            'QZSS_L1S_ENABLE': cls.__constants['QZSS_L1S_ENABLE'],
            'QZSS_L2C_ENABLE': cls.__constants['QZSS_L2C_ENABLE'],
            'GLO_ENABLE': cls.__constants['GLO_ENABLE'],
            'GLO_L1_ENABLE': cls.__constants['GLO_L1_ENABLE'],
            'GLO_L2_ENABLE': cls.__constants['GLO_L2_ENABLE'],
        }

    @property
    def GPS_ENABLE(self):
        """Message constant 'GPS_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GPS_ENABLE']

    @property
    def GPS_L1CA_ENABLE(self):
        """Message constant 'GPS_L1CA_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GPS_L1CA_ENABLE']

    @property
    def GPS_L2C_ENABLE(self):
        """Message constant 'GPS_L2C_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GPS_L2C_ENABLE']

    @property
    def SBAS_ENABLE(self):
        """Message constant 'SBAS_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['SBAS_ENABLE']

    @property
    def SBAS_L1CA_ENABLE(self):
        """Message constant 'SBAS_L1CA_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['SBAS_L1CA_ENABLE']

    @property
    def GAL_ENABLE(self):
        """Message constant 'GAL_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GAL_ENABLE']

    @property
    def GAL_E1_ENABLE(self):
        """Message constant 'GAL_E1_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GAL_E1_ENABLE']

    @property
    def GAL_E5B_ENABLE(self):
        """Message constant 'GAL_E5B_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GAL_E5B_ENABLE']

    @property
    def BDS_ENABLE(self):
        """Message constant 'BDS_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['BDS_ENABLE']

    @property
    def BDS_B1_ENABLE(self):
        """Message constant 'BDS_B1_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['BDS_B1_ENABLE']

    @property
    def BDS_B2_ENABLE(self):
        """Message constant 'BDS_B2_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['BDS_B2_ENABLE']

    @property
    def QZSS_ENABLE(self):
        """Message constant 'QZSS_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['QZSS_ENABLE']

    @property
    def QZSS_L1CA_ENABLE(self):
        """Message constant 'QZSS_L1CA_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['QZSS_L1CA_ENABLE']

    @property
    def QZSS_L1S_ENABLE(self):
        """Message constant 'QZSS_L1S_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['QZSS_L1S_ENABLE']

    @property
    def QZSS_L2C_ENABLE(self):
        """Message constant 'QZSS_L2C_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['QZSS_L2C_ENABLE']

    @property
    def GLO_ENABLE(self):
        """Message constant 'GLO_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GLO_ENABLE']

    @property
    def GLO_L1_ENABLE(self):
        """Message constant 'GLO_L1_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GLO_L1_ENABLE']

    @property
    def GLO_L2_ENABLE(self):
        """Message constant 'GLO_L2_ENABLE'."""
        return Metaclass_CfgVALSETCfgdata.__constants['GLO_L2_ENABLE']


class CfgVALSETCfgdata(metaclass=Metaclass_CfgVALSETCfgdata):
    """
    Message class 'CfgVALSETCfgdata'.

    Constants:
      GPS_ENABLE
      GPS_L1CA_ENABLE
      GPS_L2C_ENABLE
      SBAS_ENABLE
      SBAS_L1CA_ENABLE
      GAL_ENABLE
      GAL_E1_ENABLE
      GAL_E5B_ENABLE
      BDS_ENABLE
      BDS_B1_ENABLE
      BDS_B2_ENABLE
      QZSS_ENABLE
      QZSS_L1CA_ENABLE
      QZSS_L1S_ENABLE
      QZSS_L2C_ENABLE
      GLO_ENABLE
      GLO_L1_ENABLE
      GLO_L2_ENABLE
    """

    __slots__ = [
        '_key',
        '_data',
    ]

    _fields_and_field_types = {
        'key': 'uint32',
        'data': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.key = kwargs.get('key', int())
        self.data = array.array('B', kwargs.get('data', []))

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
        if self.key != other.key:
            return False
        if self.data != other.data:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def key(self):
        """Message field 'key'."""
        return self._key

    @key.setter
    def key(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'key' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'key' field must be an unsigned integer in [0, 4294967295]"
        self._key = value

    @builtins.property
    def data(self):
        """Message field 'data'."""
        return self._data

    @data.setter
    def data(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'data' array.array() must have the type code of 'B'"
            self._data = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'data' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._data = array.array('B', value)
