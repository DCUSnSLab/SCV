# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgRST.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgRST(type):
    """Metaclass of message 'CfgRST'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 4,
        'NAV_BBR_HOT_START': 0,
        'NAV_BBR_WARM_START': 1,
        'NAV_BBR_COLD_START': 65535,
        'NAV_BBR_EPH': 1,
        'NAV_BBR_ALM': 2,
        'NAV_BBR_HEALTH': 4,
        'NAV_BBR_KLOB': 8,
        'NAV_BBR_POS': 16,
        'NAV_BBR_CLKD': 32,
        'NAV_BBR_OSC': 64,
        'NAV_BBR_UTC': 128,
        'NAV_BBR_RTC': 256,
        'NAV_BBR_AOP': 32768,
        'RESET_MODE_HW_IMMEDIATE': 0,
        'RESET_MODE_SW': 1,
        'RESET_MODE_GNSS': 2,
        'RESET_MODE_HW_AFTER_SHUTDOWN': 4,
        'RESET_MODE_GNSS_STOP': 8,
        'RESET_MODE_GNSS_START': 9,
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
                'ublox_msgs.msg.CfgRST')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_rst
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_rst
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_rst
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_rst
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_rst

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'NAV_BBR_HOT_START': cls.__constants['NAV_BBR_HOT_START'],
            'NAV_BBR_WARM_START': cls.__constants['NAV_BBR_WARM_START'],
            'NAV_BBR_COLD_START': cls.__constants['NAV_BBR_COLD_START'],
            'NAV_BBR_EPH': cls.__constants['NAV_BBR_EPH'],
            'NAV_BBR_ALM': cls.__constants['NAV_BBR_ALM'],
            'NAV_BBR_HEALTH': cls.__constants['NAV_BBR_HEALTH'],
            'NAV_BBR_KLOB': cls.__constants['NAV_BBR_KLOB'],
            'NAV_BBR_POS': cls.__constants['NAV_BBR_POS'],
            'NAV_BBR_CLKD': cls.__constants['NAV_BBR_CLKD'],
            'NAV_BBR_OSC': cls.__constants['NAV_BBR_OSC'],
            'NAV_BBR_UTC': cls.__constants['NAV_BBR_UTC'],
            'NAV_BBR_RTC': cls.__constants['NAV_BBR_RTC'],
            'NAV_BBR_AOP': cls.__constants['NAV_BBR_AOP'],
            'RESET_MODE_HW_IMMEDIATE': cls.__constants['RESET_MODE_HW_IMMEDIATE'],
            'RESET_MODE_SW': cls.__constants['RESET_MODE_SW'],
            'RESET_MODE_GNSS': cls.__constants['RESET_MODE_GNSS'],
            'RESET_MODE_HW_AFTER_SHUTDOWN': cls.__constants['RESET_MODE_HW_AFTER_SHUTDOWN'],
            'RESET_MODE_GNSS_STOP': cls.__constants['RESET_MODE_GNSS_STOP'],
            'RESET_MODE_GNSS_START': cls.__constants['RESET_MODE_GNSS_START'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgRST.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgRST.__constants['MESSAGE_ID']

    @property
    def NAV_BBR_HOT_START(self):
        """Message constant 'NAV_BBR_HOT_START'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_HOT_START']

    @property
    def NAV_BBR_WARM_START(self):
        """Message constant 'NAV_BBR_WARM_START'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_WARM_START']

    @property
    def NAV_BBR_COLD_START(self):
        """Message constant 'NAV_BBR_COLD_START'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_COLD_START']

    @property
    def NAV_BBR_EPH(self):
        """Message constant 'NAV_BBR_EPH'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_EPH']

    @property
    def NAV_BBR_ALM(self):
        """Message constant 'NAV_BBR_ALM'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_ALM']

    @property
    def NAV_BBR_HEALTH(self):
        """Message constant 'NAV_BBR_HEALTH'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_HEALTH']

    @property
    def NAV_BBR_KLOB(self):
        """Message constant 'NAV_BBR_KLOB'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_KLOB']

    @property
    def NAV_BBR_POS(self):
        """Message constant 'NAV_BBR_POS'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_POS']

    @property
    def NAV_BBR_CLKD(self):
        """Message constant 'NAV_BBR_CLKD'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_CLKD']

    @property
    def NAV_BBR_OSC(self):
        """Message constant 'NAV_BBR_OSC'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_OSC']

    @property
    def NAV_BBR_UTC(self):
        """Message constant 'NAV_BBR_UTC'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_UTC']

    @property
    def NAV_BBR_RTC(self):
        """Message constant 'NAV_BBR_RTC'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_RTC']

    @property
    def NAV_BBR_AOP(self):
        """Message constant 'NAV_BBR_AOP'."""
        return Metaclass_CfgRST.__constants['NAV_BBR_AOP']

    @property
    def RESET_MODE_HW_IMMEDIATE(self):
        """Message constant 'RESET_MODE_HW_IMMEDIATE'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_HW_IMMEDIATE']

    @property
    def RESET_MODE_SW(self):
        """Message constant 'RESET_MODE_SW'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_SW']

    @property
    def RESET_MODE_GNSS(self):
        """Message constant 'RESET_MODE_GNSS'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_GNSS']

    @property
    def RESET_MODE_HW_AFTER_SHUTDOWN(self):
        """Message constant 'RESET_MODE_HW_AFTER_SHUTDOWN'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_HW_AFTER_SHUTDOWN']

    @property
    def RESET_MODE_GNSS_STOP(self):
        """Message constant 'RESET_MODE_GNSS_STOP'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_GNSS_STOP']

    @property
    def RESET_MODE_GNSS_START(self):
        """Message constant 'RESET_MODE_GNSS_START'."""
        return Metaclass_CfgRST.__constants['RESET_MODE_GNSS_START']


class CfgRST(metaclass=Metaclass_CfgRST):
    """
    Message class 'CfgRST'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      NAV_BBR_HOT_START
      NAV_BBR_WARM_START
      NAV_BBR_COLD_START
      NAV_BBR_EPH
      NAV_BBR_ALM
      NAV_BBR_HEALTH
      NAV_BBR_KLOB
      NAV_BBR_POS
      NAV_BBR_CLKD
      NAV_BBR_OSC
      NAV_BBR_UTC
      NAV_BBR_RTC
      NAV_BBR_AOP
      RESET_MODE_HW_IMMEDIATE
      RESET_MODE_SW
      RESET_MODE_GNSS
      RESET_MODE_HW_AFTER_SHUTDOWN
      RESET_MODE_GNSS_STOP
      RESET_MODE_GNSS_START
    """

    __slots__ = [
        '_nav_bbr_mask',
        '_reset_mode',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'nav_bbr_mask': 'uint16',
        'reset_mode': 'uint8',
        'reserved1': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.nav_bbr_mask = kwargs.get('nav_bbr_mask', int())
        self.reset_mode = kwargs.get('reset_mode', int())
        self.reserved1 = kwargs.get('reserved1', int())

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
        if self.nav_bbr_mask != other.nav_bbr_mask:
            return False
        if self.reset_mode != other.reset_mode:
            return False
        if self.reserved1 != other.reserved1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def nav_bbr_mask(self):
        """Message field 'nav_bbr_mask'."""
        return self._nav_bbr_mask

    @nav_bbr_mask.setter
    def nav_bbr_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'nav_bbr_mask' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'nav_bbr_mask' field must be an unsigned integer in [0, 65535]"
        self._nav_bbr_mask = value

    @builtins.property
    def reset_mode(self):
        """Message field 'reset_mode'."""
        return self._reset_mode

    @reset_mode.setter
    def reset_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reset_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reset_mode' field must be an unsigned integer in [0, 255]"
        self._reset_mode = value

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
