# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgNMEA6.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgNMEA6(type):
    """Metaclass of message 'CfgNMEA6'."""

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
        'FILTER_SBAS_FILT': 16,
        'FILTER_TRACK': 32,
        'NMEA_VERSION_2_3': 35,
        'NMEA_VERSION_2_1': 33,
        'FLAGS_COMPAT': 1,
        'FLAGS_CONSIDER': 2,
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
                'ublox_msgs.msg.CfgNMEA6')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_nmea6
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_nmea6
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_nmea6
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_nmea6
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_nmea6

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
            'FILTER_SBAS_FILT': cls.__constants['FILTER_SBAS_FILT'],
            'FILTER_TRACK': cls.__constants['FILTER_TRACK'],
            'NMEA_VERSION_2_3': cls.__constants['NMEA_VERSION_2_3'],
            'NMEA_VERSION_2_1': cls.__constants['NMEA_VERSION_2_1'],
            'FLAGS_COMPAT': cls.__constants['FLAGS_COMPAT'],
            'FLAGS_CONSIDER': cls.__constants['FLAGS_CONSIDER'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgNMEA6.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgNMEA6.__constants['MESSAGE_ID']

    @property
    def FILTER_POS(self):
        """Message constant 'FILTER_POS'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_POS']

    @property
    def FILTER_MSK_POS(self):
        """Message constant 'FILTER_MSK_POS'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_MSK_POS']

    @property
    def FILTER_TIME(self):
        """Message constant 'FILTER_TIME'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_TIME']

    @property
    def FILTER_DATE(self):
        """Message constant 'FILTER_DATE'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_DATE']

    @property
    def FILTER_SBAS_FILT(self):
        """Message constant 'FILTER_SBAS_FILT'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_SBAS_FILT']

    @property
    def FILTER_TRACK(self):
        """Message constant 'FILTER_TRACK'."""
        return Metaclass_CfgNMEA6.__constants['FILTER_TRACK']

    @property
    def NMEA_VERSION_2_3(self):
        """Message constant 'NMEA_VERSION_2_3'."""
        return Metaclass_CfgNMEA6.__constants['NMEA_VERSION_2_3']

    @property
    def NMEA_VERSION_2_1(self):
        """Message constant 'NMEA_VERSION_2_1'."""
        return Metaclass_CfgNMEA6.__constants['NMEA_VERSION_2_1']

    @property
    def FLAGS_COMPAT(self):
        """Message constant 'FLAGS_COMPAT'."""
        return Metaclass_CfgNMEA6.__constants['FLAGS_COMPAT']

    @property
    def FLAGS_CONSIDER(self):
        """Message constant 'FLAGS_CONSIDER'."""
        return Metaclass_CfgNMEA6.__constants['FLAGS_CONSIDER']


class CfgNMEA6(metaclass=Metaclass_CfgNMEA6):
    """
    Message class 'CfgNMEA6'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FILTER_POS
      FILTER_MSK_POS
      FILTER_TIME
      FILTER_DATE
      FILTER_SBAS_FILT
      FILTER_TRACK
      NMEA_VERSION_2_3
      NMEA_VERSION_2_1
      FLAGS_COMPAT
      FLAGS_CONSIDER
    """

    __slots__ = [
        '_filter',
        '_version',
        '_num_sv',
        '_flags',
    ]

    _fields_and_field_types = {
        'filter': 'uint8',
        'version': 'uint8',
        'num_sv': 'uint8',
        'flags': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.filter = kwargs.get('filter', int())
        self.version = kwargs.get('version', int())
        self.num_sv = kwargs.get('num_sv', int())
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
        if self.filter != other.filter:
            return False
        if self.version != other.version:
            return False
        if self.num_sv != other.num_sv:
            return False
        if self.flags != other.flags:
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
