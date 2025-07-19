# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgCFG.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgCFG(type):
    """Metaclass of message 'CfgCFG'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 9,
        'MASK_IO_PORT': 1,
        'MASK_MSG_CONF': 2,
        'MASK_INF_MSG': 4,
        'MASK_NAV_CONF': 8,
        'MASK_RXM_CONF': 16,
        'MASK_SEN_CONF': 256,
        'MASK_RINV_CONF': 512,
        'MASK_ANT_CONF': 1024,
        'MASK_LOG_CONF': 2048,
        'MASK_FTS_CONF': 4096,
        'DEV_BBR': 1,
        'DEV_FLASH': 2,
        'DEV_EEPROM': 4,
        'DEV_SPI_FLASH': 16,
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
                'ublox_msgs.msg.CfgCFG')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_cfg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_cfg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_cfg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_cfg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_cfg

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'MASK_IO_PORT': cls.__constants['MASK_IO_PORT'],
            'MASK_MSG_CONF': cls.__constants['MASK_MSG_CONF'],
            'MASK_INF_MSG': cls.__constants['MASK_INF_MSG'],
            'MASK_NAV_CONF': cls.__constants['MASK_NAV_CONF'],
            'MASK_RXM_CONF': cls.__constants['MASK_RXM_CONF'],
            'MASK_SEN_CONF': cls.__constants['MASK_SEN_CONF'],
            'MASK_RINV_CONF': cls.__constants['MASK_RINV_CONF'],
            'MASK_ANT_CONF': cls.__constants['MASK_ANT_CONF'],
            'MASK_LOG_CONF': cls.__constants['MASK_LOG_CONF'],
            'MASK_FTS_CONF': cls.__constants['MASK_FTS_CONF'],
            'DEV_BBR': cls.__constants['DEV_BBR'],
            'DEV_FLASH': cls.__constants['DEV_FLASH'],
            'DEV_EEPROM': cls.__constants['DEV_EEPROM'],
            'DEV_SPI_FLASH': cls.__constants['DEV_SPI_FLASH'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgCFG.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgCFG.__constants['MESSAGE_ID']

    @property
    def MASK_IO_PORT(self):
        """Message constant 'MASK_IO_PORT'."""
        return Metaclass_CfgCFG.__constants['MASK_IO_PORT']

    @property
    def MASK_MSG_CONF(self):
        """Message constant 'MASK_MSG_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_MSG_CONF']

    @property
    def MASK_INF_MSG(self):
        """Message constant 'MASK_INF_MSG'."""
        return Metaclass_CfgCFG.__constants['MASK_INF_MSG']

    @property
    def MASK_NAV_CONF(self):
        """Message constant 'MASK_NAV_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_NAV_CONF']

    @property
    def MASK_RXM_CONF(self):
        """Message constant 'MASK_RXM_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_RXM_CONF']

    @property
    def MASK_SEN_CONF(self):
        """Message constant 'MASK_SEN_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_SEN_CONF']

    @property
    def MASK_RINV_CONF(self):
        """Message constant 'MASK_RINV_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_RINV_CONF']

    @property
    def MASK_ANT_CONF(self):
        """Message constant 'MASK_ANT_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_ANT_CONF']

    @property
    def MASK_LOG_CONF(self):
        """Message constant 'MASK_LOG_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_LOG_CONF']

    @property
    def MASK_FTS_CONF(self):
        """Message constant 'MASK_FTS_CONF'."""
        return Metaclass_CfgCFG.__constants['MASK_FTS_CONF']

    @property
    def DEV_BBR(self):
        """Message constant 'DEV_BBR'."""
        return Metaclass_CfgCFG.__constants['DEV_BBR']

    @property
    def DEV_FLASH(self):
        """Message constant 'DEV_FLASH'."""
        return Metaclass_CfgCFG.__constants['DEV_FLASH']

    @property
    def DEV_EEPROM(self):
        """Message constant 'DEV_EEPROM'."""
        return Metaclass_CfgCFG.__constants['DEV_EEPROM']

    @property
    def DEV_SPI_FLASH(self):
        """Message constant 'DEV_SPI_FLASH'."""
        return Metaclass_CfgCFG.__constants['DEV_SPI_FLASH']


class CfgCFG(metaclass=Metaclass_CfgCFG):
    """
    Message class 'CfgCFG'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      MASK_IO_PORT
      MASK_MSG_CONF
      MASK_INF_MSG
      MASK_NAV_CONF
      MASK_RXM_CONF
      MASK_SEN_CONF
      MASK_RINV_CONF
      MASK_ANT_CONF
      MASK_LOG_CONF
      MASK_FTS_CONF
      DEV_BBR
      DEV_FLASH
      DEV_EEPROM
      DEV_SPI_FLASH
    """

    __slots__ = [
        '_clear_mask',
        '_save_mask',
        '_load_mask',
        '_device_mask',
    ]

    _fields_and_field_types = {
        'clear_mask': 'uint32',
        'save_mask': 'uint32',
        'load_mask': 'uint32',
        'device_mask': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.clear_mask = kwargs.get('clear_mask', int())
        self.save_mask = kwargs.get('save_mask', int())
        self.load_mask = kwargs.get('load_mask', int())
        self.device_mask = kwargs.get('device_mask', int())

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
        if self.clear_mask != other.clear_mask:
            return False
        if self.save_mask != other.save_mask:
            return False
        if self.load_mask != other.load_mask:
            return False
        if self.device_mask != other.device_mask:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def clear_mask(self):
        """Message field 'clear_mask'."""
        return self._clear_mask

    @clear_mask.setter
    def clear_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'clear_mask' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'clear_mask' field must be an unsigned integer in [0, 4294967295]"
        self._clear_mask = value

    @builtins.property
    def save_mask(self):
        """Message field 'save_mask'."""
        return self._save_mask

    @save_mask.setter
    def save_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'save_mask' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'save_mask' field must be an unsigned integer in [0, 4294967295]"
        self._save_mask = value

    @builtins.property
    def load_mask(self):
        """Message field 'load_mask'."""
        return self._load_mask

    @load_mask.setter
    def load_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'load_mask' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'load_mask' field must be an unsigned integer in [0, 4294967295]"
        self._load_mask = value

    @builtins.property
    def device_mask(self):
        """Message field 'device_mask'."""
        return self._device_mask

    @device_mask.setter
    def device_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'device_mask' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'device_mask' field must be an unsigned integer in [0, 255]"
        self._device_mask = value
