# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgTMODE3.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'reserved3'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgTMODE3(type):
    """Metaclass of message 'CfgTMODE3'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 113,
        'FLAGS_MODE_MASK': 255,
        'FLAGS_MODE_DISABLED': 0,
        'FLAGS_MODE_SURVEY_IN': 1,
        'FLAGS_MODE_FIXED': 2,
        'FLAGS_LLA': 256,
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
                'ublox_msgs.msg.CfgTMODE3')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_tmode3
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_tmode3
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_tmode3
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_tmode3
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_tmode3

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_MODE_MASK': cls.__constants['FLAGS_MODE_MASK'],
            'FLAGS_MODE_DISABLED': cls.__constants['FLAGS_MODE_DISABLED'],
            'FLAGS_MODE_SURVEY_IN': cls.__constants['FLAGS_MODE_SURVEY_IN'],
            'FLAGS_MODE_FIXED': cls.__constants['FLAGS_MODE_FIXED'],
            'FLAGS_LLA': cls.__constants['FLAGS_LLA'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgTMODE3.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgTMODE3.__constants['MESSAGE_ID']

    @property
    def FLAGS_MODE_MASK(self):
        """Message constant 'FLAGS_MODE_MASK'."""
        return Metaclass_CfgTMODE3.__constants['FLAGS_MODE_MASK']

    @property
    def FLAGS_MODE_DISABLED(self):
        """Message constant 'FLAGS_MODE_DISABLED'."""
        return Metaclass_CfgTMODE3.__constants['FLAGS_MODE_DISABLED']

    @property
    def FLAGS_MODE_SURVEY_IN(self):
        """Message constant 'FLAGS_MODE_SURVEY_IN'."""
        return Metaclass_CfgTMODE3.__constants['FLAGS_MODE_SURVEY_IN']

    @property
    def FLAGS_MODE_FIXED(self):
        """Message constant 'FLAGS_MODE_FIXED'."""
        return Metaclass_CfgTMODE3.__constants['FLAGS_MODE_FIXED']

    @property
    def FLAGS_LLA(self):
        """Message constant 'FLAGS_LLA'."""
        return Metaclass_CfgTMODE3.__constants['FLAGS_LLA']


class CfgTMODE3(metaclass=Metaclass_CfgTMODE3):
    """
    Message class 'CfgTMODE3'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_MODE_MASK
      FLAGS_MODE_DISABLED
      FLAGS_MODE_SURVEY_IN
      FLAGS_MODE_FIXED
      FLAGS_LLA
    """

    __slots__ = [
        '_version',
        '_reserved1',
        '_flags',
        '_ecef_x_or_lat',
        '_ecef_y_or_lon',
        '_ecef_z_or_alt',
        '_ecef_x_or_lat_hp',
        '_ecef_y_or_lon_hp',
        '_ecef_z_or_alt_hp',
        '_reserved2',
        '_fixed_pos_acc',
        '_svin_min_dur',
        '_svin_acc_limit',
        '_reserved3',
    ]

    _fields_and_field_types = {
        'version': 'uint8',
        'reserved1': 'uint8',
        'flags': 'uint16',
        'ecef_x_or_lat': 'int32',
        'ecef_y_or_lon': 'int32',
        'ecef_z_or_alt': 'int32',
        'ecef_x_or_lat_hp': 'int8',
        'ecef_y_or_lon_hp': 'int8',
        'ecef_z_or_alt_hp': 'int8',
        'reserved2': 'uint8',
        'fixed_pos_acc': 'uint32',
        'svin_min_dur': 'uint32',
        'svin_acc_limit': 'uint32',
        'reserved3': 'uint8[8]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 8),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.version = kwargs.get('version', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.flags = kwargs.get('flags', int())
        self.ecef_x_or_lat = kwargs.get('ecef_x_or_lat', int())
        self.ecef_y_or_lon = kwargs.get('ecef_y_or_lon', int())
        self.ecef_z_or_alt = kwargs.get('ecef_z_or_alt', int())
        self.ecef_x_or_lat_hp = kwargs.get('ecef_x_or_lat_hp', int())
        self.ecef_y_or_lon_hp = kwargs.get('ecef_y_or_lon_hp', int())
        self.ecef_z_or_alt_hp = kwargs.get('ecef_z_or_alt_hp', int())
        self.reserved2 = kwargs.get('reserved2', int())
        self.fixed_pos_acc = kwargs.get('fixed_pos_acc', int())
        self.svin_min_dur = kwargs.get('svin_min_dur', int())
        self.svin_acc_limit = kwargs.get('svin_acc_limit', int())
        if 'reserved3' not in kwargs:
            self.reserved3 = numpy.zeros(8, dtype=numpy.uint8)
        else:
            self.reserved3 = numpy.array(kwargs.get('reserved3'), dtype=numpy.uint8)
            assert self.reserved3.shape == (8, )

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
        if self.version != other.version:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.flags != other.flags:
            return False
        if self.ecef_x_or_lat != other.ecef_x_or_lat:
            return False
        if self.ecef_y_or_lon != other.ecef_y_or_lon:
            return False
        if self.ecef_z_or_alt != other.ecef_z_or_alt:
            return False
        if self.ecef_x_or_lat_hp != other.ecef_x_or_lat_hp:
            return False
        if self.ecef_y_or_lon_hp != other.ecef_y_or_lon_hp:
            return False
        if self.ecef_z_or_alt_hp != other.ecef_z_or_alt_hp:
            return False
        if self.reserved2 != other.reserved2:
            return False
        if self.fixed_pos_acc != other.fixed_pos_acc:
            return False
        if self.svin_min_dur != other.svin_min_dur:
            return False
        if self.svin_acc_limit != other.svin_acc_limit:
            return False
        if all(self.reserved3 != other.reserved3):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
            assert value >= 0 and value < 65536, \
                "The 'flags' field must be an unsigned integer in [0, 65535]"
        self._flags = value

    @builtins.property
    def ecef_x_or_lat(self):
        """Message field 'ecef_x_or_lat'."""
        return self._ecef_x_or_lat

    @ecef_x_or_lat.setter
    def ecef_x_or_lat(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_x_or_lat' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_x_or_lat' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_x_or_lat = value

    @builtins.property
    def ecef_y_or_lon(self):
        """Message field 'ecef_y_or_lon'."""
        return self._ecef_y_or_lon

    @ecef_y_or_lon.setter
    def ecef_y_or_lon(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_y_or_lon' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_y_or_lon' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_y_or_lon = value

    @builtins.property
    def ecef_z_or_alt(self):
        """Message field 'ecef_z_or_alt'."""
        return self._ecef_z_or_alt

    @ecef_z_or_alt.setter
    def ecef_z_or_alt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_z_or_alt' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'ecef_z_or_alt' field must be an integer in [-2147483648, 2147483647]"
        self._ecef_z_or_alt = value

    @builtins.property
    def ecef_x_or_lat_hp(self):
        """Message field 'ecef_x_or_lat_hp'."""
        return self._ecef_x_or_lat_hp

    @ecef_x_or_lat_hp.setter
    def ecef_x_or_lat_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_x_or_lat_hp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ecef_x_or_lat_hp' field must be an integer in [-128, 127]"
        self._ecef_x_or_lat_hp = value

    @builtins.property
    def ecef_y_or_lon_hp(self):
        """Message field 'ecef_y_or_lon_hp'."""
        return self._ecef_y_or_lon_hp

    @ecef_y_or_lon_hp.setter
    def ecef_y_or_lon_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_y_or_lon_hp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ecef_y_or_lon_hp' field must be an integer in [-128, 127]"
        self._ecef_y_or_lon_hp = value

    @builtins.property
    def ecef_z_or_alt_hp(self):
        """Message field 'ecef_z_or_alt_hp'."""
        return self._ecef_z_or_alt_hp

    @ecef_z_or_alt_hp.setter
    def ecef_z_or_alt_hp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ecef_z_or_alt_hp' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'ecef_z_or_alt_hp' field must be an integer in [-128, 127]"
        self._ecef_z_or_alt_hp = value

    @builtins.property
    def reserved2(self):
        """Message field 'reserved2'."""
        return self._reserved2

    @reserved2.setter
    def reserved2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved2' field must be an unsigned integer in [0, 255]"
        self._reserved2 = value

    @builtins.property
    def fixed_pos_acc(self):
        """Message field 'fixed_pos_acc'."""
        return self._fixed_pos_acc

    @fixed_pos_acc.setter
    def fixed_pos_acc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fixed_pos_acc' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'fixed_pos_acc' field must be an unsigned integer in [0, 4294967295]"
        self._fixed_pos_acc = value

    @builtins.property
    def svin_min_dur(self):
        """Message field 'svin_min_dur'."""
        return self._svin_min_dur

    @svin_min_dur.setter
    def svin_min_dur(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'svin_min_dur' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'svin_min_dur' field must be an unsigned integer in [0, 4294967295]"
        self._svin_min_dur = value

    @builtins.property
    def svin_acc_limit(self):
        """Message field 'svin_acc_limit'."""
        return self._svin_acc_limit

    @svin_acc_limit.setter
    def svin_acc_limit(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'svin_acc_limit' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'svin_acc_limit' field must be an unsigned integer in [0, 4294967295]"
        self._svin_acc_limit = value

    @builtins.property
    def reserved3(self):
        """Message field 'reserved3'."""
        return self._reserved3

    @reserved3.setter
    def reserved3(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved3' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 8, \
                "The 'reserved3' numpy.ndarray() must have a size of 8"
            self._reserved3 = value
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
                 len(value) == 8 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved3' field must be a set or sequence with length 8 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved3 = numpy.array(value, dtype=numpy.uint8)
