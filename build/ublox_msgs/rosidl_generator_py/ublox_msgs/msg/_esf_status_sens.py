# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/EsfSTATUSSens.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EsfSTATUSSens(type):
    """Metaclass of message 'EsfSTATUSSens'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
                'ublox_msgs.msg.EsfSTATUSSens')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__esf_status_sens
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__esf_status_sens
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__esf_status_sens
            cls._TYPE_SUPPORT = module.type_support_msg__msg__esf_status_sens
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__esf_status_sens

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EsfSTATUSSens(metaclass=Metaclass_EsfSTATUSSens):
    """Message class 'EsfSTATUSSens'."""

    __slots__ = [
        '_sens_status1',
        '_sens_status2',
        '_freq',
        '_faults',
    ]

    _fields_and_field_types = {
        'sens_status1': 'uint8',
        'sens_status2': 'uint8',
        'freq': 'uint8',
        'faults': 'uint8',
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
        self.sens_status1 = kwargs.get('sens_status1', int())
        self.sens_status2 = kwargs.get('sens_status2', int())
        self.freq = kwargs.get('freq', int())
        self.faults = kwargs.get('faults', int())

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
        if self.sens_status1 != other.sens_status1:
            return False
        if self.sens_status2 != other.sens_status2:
            return False
        if self.freq != other.freq:
            return False
        if self.faults != other.faults:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def sens_status1(self):
        """Message field 'sens_status1'."""
        return self._sens_status1

    @sens_status1.setter
    def sens_status1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sens_status1' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sens_status1' field must be an unsigned integer in [0, 255]"
        self._sens_status1 = value

    @builtins.property
    def sens_status2(self):
        """Message field 'sens_status2'."""
        return self._sens_status2

    @sens_status2.setter
    def sens_status2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sens_status2' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sens_status2' field must be an unsigned integer in [0, 255]"
        self._sens_status2 = value

    @builtins.property
    def freq(self):
        """Message field 'freq'."""
        return self._freq

    @freq.setter
    def freq(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'freq' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'freq' field must be an unsigned integer in [0, 255]"
        self._freq = value

    @builtins.property
    def faults(self):
        """Message field 'faults'."""
        return self._faults

    @faults.setter
    def faults(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'faults' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'faults' field must be an unsigned integer in [0, 255]"
        self._faults = value
