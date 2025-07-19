# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgANT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgANT(type):
    """Metaclass of message 'CfgANT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 19,
        'FLAGS_SVCS': 1,
        'FLAGS_SCD': 2,
        'FLAGS_OCD': 4,
        'FLAGS_PDWN_ON_SCD': 8,
        'FLAGS_RECOVERY': 16,
        'PIN_SWITCH_MASK': 31,
        'PIN_SCD_MASK': 992,
        'PIN_OCD_MASK': 31744,
        'PIN_RECONFIG': 32678,
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
                'ublox_msgs.msg.CfgANT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_ant
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_ant
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_ant
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_ant
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_ant

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'FLAGS_SVCS': cls.__constants['FLAGS_SVCS'],
            'FLAGS_SCD': cls.__constants['FLAGS_SCD'],
            'FLAGS_OCD': cls.__constants['FLAGS_OCD'],
            'FLAGS_PDWN_ON_SCD': cls.__constants['FLAGS_PDWN_ON_SCD'],
            'FLAGS_RECOVERY': cls.__constants['FLAGS_RECOVERY'],
            'PIN_SWITCH_MASK': cls.__constants['PIN_SWITCH_MASK'],
            'PIN_SCD_MASK': cls.__constants['PIN_SCD_MASK'],
            'PIN_OCD_MASK': cls.__constants['PIN_OCD_MASK'],
            'PIN_RECONFIG': cls.__constants['PIN_RECONFIG'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgANT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgANT.__constants['MESSAGE_ID']

    @property
    def FLAGS_SVCS(self):
        """Message constant 'FLAGS_SVCS'."""
        return Metaclass_CfgANT.__constants['FLAGS_SVCS']

    @property
    def FLAGS_SCD(self):
        """Message constant 'FLAGS_SCD'."""
        return Metaclass_CfgANT.__constants['FLAGS_SCD']

    @property
    def FLAGS_OCD(self):
        """Message constant 'FLAGS_OCD'."""
        return Metaclass_CfgANT.__constants['FLAGS_OCD']

    @property
    def FLAGS_PDWN_ON_SCD(self):
        """Message constant 'FLAGS_PDWN_ON_SCD'."""
        return Metaclass_CfgANT.__constants['FLAGS_PDWN_ON_SCD']

    @property
    def FLAGS_RECOVERY(self):
        """Message constant 'FLAGS_RECOVERY'."""
        return Metaclass_CfgANT.__constants['FLAGS_RECOVERY']

    @property
    def PIN_SWITCH_MASK(self):
        """Message constant 'PIN_SWITCH_MASK'."""
        return Metaclass_CfgANT.__constants['PIN_SWITCH_MASK']

    @property
    def PIN_SCD_MASK(self):
        """Message constant 'PIN_SCD_MASK'."""
        return Metaclass_CfgANT.__constants['PIN_SCD_MASK']

    @property
    def PIN_OCD_MASK(self):
        """Message constant 'PIN_OCD_MASK'."""
        return Metaclass_CfgANT.__constants['PIN_OCD_MASK']

    @property
    def PIN_RECONFIG(self):
        """Message constant 'PIN_RECONFIG'."""
        return Metaclass_CfgANT.__constants['PIN_RECONFIG']


class CfgANT(metaclass=Metaclass_CfgANT):
    """
    Message class 'CfgANT'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      FLAGS_SVCS
      FLAGS_SCD
      FLAGS_OCD
      FLAGS_PDWN_ON_SCD
      FLAGS_RECOVERY
      PIN_SWITCH_MASK
      PIN_SCD_MASK
      PIN_OCD_MASK
      PIN_RECONFIG
    """

    __slots__ = [
        '_flags',
        '_pins',
    ]

    _fields_and_field_types = {
        'flags': 'uint16',
        'pins': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.flags = kwargs.get('flags', int())
        self.pins = kwargs.get('pins', int())

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
        if self.flags != other.flags:
            return False
        if self.pins != other.pins:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

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
    def pins(self):
        """Message field 'pins'."""
        return self._pins

    @pins.setter
    def pins(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pins' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'pins' field must be an unsigned integer in [0, 65535]"
        self._pins = value
