# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/NavSBASSV.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_NavSBASSV(type):
    """Metaclass of message 'NavSBASSV'."""

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
                'ublox_msgs.msg.NavSBASSV')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__nav_sbassv
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__nav_sbassv
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__nav_sbassv
            cls._TYPE_SUPPORT = module.type_support_msg__msg__nav_sbassv
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__nav_sbassv

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class NavSBASSV(metaclass=Metaclass_NavSBASSV):
    """Message class 'NavSBASSV'."""

    __slots__ = [
        '_svid',
        '_flags',
        '_udre',
        '_sv_sys',
        '_sv_service',
        '_reserved1',
        '_prc',
        '_reserved2',
        '_ic',
    ]

    _fields_and_field_types = {
        'svid': 'uint8',
        'flags': 'uint8',
        'udre': 'uint8',
        'sv_sys': 'uint8',
        'sv_service': 'uint8',
        'reserved1': 'uint8',
        'prc': 'int16',
        'reserved2': 'uint16',
        'ic': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.svid = kwargs.get('svid', int())
        self.flags = kwargs.get('flags', int())
        self.udre = kwargs.get('udre', int())
        self.sv_sys = kwargs.get('sv_sys', int())
        self.sv_service = kwargs.get('sv_service', int())
        self.reserved1 = kwargs.get('reserved1', int())
        self.prc = kwargs.get('prc', int())
        self.reserved2 = kwargs.get('reserved2', int())
        self.ic = kwargs.get('ic', int())

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
        if self.svid != other.svid:
            return False
        if self.flags != other.flags:
            return False
        if self.udre != other.udre:
            return False
        if self.sv_sys != other.sv_sys:
            return False
        if self.sv_service != other.sv_service:
            return False
        if self.reserved1 != other.reserved1:
            return False
        if self.prc != other.prc:
            return False
        if self.reserved2 != other.reserved2:
            return False
        if self.ic != other.ic:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def udre(self):
        """Message field 'udre'."""
        return self._udre

    @udre.setter
    def udre(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'udre' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'udre' field must be an unsigned integer in [0, 255]"
        self._udre = value

    @builtins.property
    def sv_sys(self):
        """Message field 'sv_sys'."""
        return self._sv_sys

    @sv_sys.setter
    def sv_sys(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_sys' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_sys' field must be an unsigned integer in [0, 255]"
        self._sv_sys = value

    @builtins.property
    def sv_service(self):
        """Message field 'sv_service'."""
        return self._sv_service

    @sv_service.setter
    def sv_service(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'sv_service' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'sv_service' field must be an unsigned integer in [0, 255]"
        self._sv_service = value

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
    def prc(self):
        """Message field 'prc'."""
        return self._prc

    @prc.setter
    def prc(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'prc' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'prc' field must be an integer in [-32768, 32767]"
        self._prc = value

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
            assert value >= 0 and value < 65536, \
                "The 'reserved2' field must be an unsigned integer in [0, 65535]"
        self._reserved2 = value

    @builtins.property
    def ic(self):
        """Message field 'ic'."""
        return self._ic

    @ic.setter
    def ic(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ic' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'ic' field must be an integer in [-32768, 32767]"
        self._ic = value
