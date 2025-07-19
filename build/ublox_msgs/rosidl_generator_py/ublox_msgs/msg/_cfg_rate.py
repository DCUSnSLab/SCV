# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgRATE.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgRATE(type):
    """Metaclass of message 'CfgRATE'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 8,
        'TIME_REF_UTC': 0,
        'TIME_REF_GPS': 1,
        'TIME_REF_GLONASS': 2,
        'TIME_REF_BEIDOU': 3,
        'TIME_REF_GALILEO': 4,
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
                'ublox_msgs.msg.CfgRATE')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_rate
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_rate
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_rate
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_rate
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_rate

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'TIME_REF_UTC': cls.__constants['TIME_REF_UTC'],
            'TIME_REF_GPS': cls.__constants['TIME_REF_GPS'],
            'TIME_REF_GLONASS': cls.__constants['TIME_REF_GLONASS'],
            'TIME_REF_BEIDOU': cls.__constants['TIME_REF_BEIDOU'],
            'TIME_REF_GALILEO': cls.__constants['TIME_REF_GALILEO'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgRATE.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgRATE.__constants['MESSAGE_ID']

    @property
    def TIME_REF_UTC(self):
        """Message constant 'TIME_REF_UTC'."""
        return Metaclass_CfgRATE.__constants['TIME_REF_UTC']

    @property
    def TIME_REF_GPS(self):
        """Message constant 'TIME_REF_GPS'."""
        return Metaclass_CfgRATE.__constants['TIME_REF_GPS']

    @property
    def TIME_REF_GLONASS(self):
        """Message constant 'TIME_REF_GLONASS'."""
        return Metaclass_CfgRATE.__constants['TIME_REF_GLONASS']

    @property
    def TIME_REF_BEIDOU(self):
        """Message constant 'TIME_REF_BEIDOU'."""
        return Metaclass_CfgRATE.__constants['TIME_REF_BEIDOU']

    @property
    def TIME_REF_GALILEO(self):
        """Message constant 'TIME_REF_GALILEO'."""
        return Metaclass_CfgRATE.__constants['TIME_REF_GALILEO']


class CfgRATE(metaclass=Metaclass_CfgRATE):
    """
    Message class 'CfgRATE'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      TIME_REF_UTC
      TIME_REF_GPS
      TIME_REF_GLONASS
      TIME_REF_BEIDOU
      TIME_REF_GALILEO
    """

    __slots__ = [
        '_meas_rate',
        '_nav_rate',
        '_time_ref',
    ]

    _fields_and_field_types = {
        'meas_rate': 'uint16',
        'nav_rate': 'uint16',
        'time_ref': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.meas_rate = kwargs.get('meas_rate', int())
        self.nav_rate = kwargs.get('nav_rate', int())
        self.time_ref = kwargs.get('time_ref', int())

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
        if self.meas_rate != other.meas_rate:
            return False
        if self.nav_rate != other.nav_rate:
            return False
        if self.time_ref != other.time_ref:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def meas_rate(self):
        """Message field 'meas_rate'."""
        return self._meas_rate

    @meas_rate.setter
    def meas_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'meas_rate' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'meas_rate' field must be an unsigned integer in [0, 65535]"
        self._meas_rate = value

    @builtins.property
    def nav_rate(self):
        """Message field 'nav_rate'."""
        return self._nav_rate

    @nav_rate.setter
    def nav_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nav_rate' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'nav_rate' field must be an unsigned integer in [0, 65535]"
        self._nav_rate = value

    @builtins.property
    def time_ref(self):
        """Message field 'time_ref'."""
        return self._time_ref

    @time_ref.setter
    def time_ref(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'time_ref' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'time_ref' field must be an unsigned integer in [0, 65535]"
        self._time_ref = value
