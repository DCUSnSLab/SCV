# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/MonHW6.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'vp'
# Member 'reserved1'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MonHW6(type):
    """Metaclass of message 'MonHW6'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 10,
        'MESSAGE_ID': 9,
        'A_STATUS_INIT': 0,
        'A_STATUS_UNKNOWN': 1,
        'A_STATUS_OK': 2,
        'A_STATUS_SHORT': 3,
        'A_STATUS_OPEN': 4,
        'A_POWER_OFF': 0,
        'A_POWER_ON': 1,
        'A_POWER_UNKNOWN': 2,
        'FLAGS_RTC_CALIB': 1,
        'FLAGS_SAFE_BOOT': 2,
        'FLAGS_JAMMING_STATE_MASK': 12,
        'JAMMING_STATE_UNKNOWN_OR_DISABLED': 0,
        'JAMMING_STATE_OK': 4,
        'JAMMING_STATE_WARNING': 8,
        'JAMMING_STATE_CRITICAL': 12,
        'FLAGS_XTAL_ABSENT': 16,
        'JAM_IND_NONE': 0,
        'JAM_IND_STRONG': 255,
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
                'ublox_msgs.msg.MonHW6')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__mon_hw6
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__mon_hw6
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__mon_hw6
            cls._TYPE_SUPPORT = module.type_support_msg__msg__mon_hw6
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__mon_hw6

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'A_STATUS_INIT': cls.__constants['A_STATUS_INIT'],
            'A_STATUS_UNKNOWN': cls.__constants['A_STATUS_UNKNOWN'],
            'A_STATUS_OK': cls.__constants['A_STATUS_OK'],
            'A_STATUS_SHORT': cls.__constants['A_STATUS_SHORT'],
            'A_STATUS_OPEN': cls.__constants['A_STATUS_OPEN'],
            'A_POWER_OFF': cls.__constants['A_POWER_OFF'],
            'A_POWER_ON': cls.__constants['A_POWER_ON'],
            'A_POWER_UNKNOWN': cls.__constants['A_POWER_UNKNOWN'],
            'FLAGS_RTC_CALIB': cls.__constants['FLAGS_RTC_CALIB'],
            'FLAGS_SAFE_BOOT': cls.__constants['FLAGS_SAFE_BOOT'],
            'FLAGS_JAMMING_STATE_MASK': cls.__constants['FLAGS_JAMMING_STATE_MASK'],
            'JAMMING_STATE_UNKNOWN_OR_DISABLED': cls.__constants['JAMMING_STATE_UNKNOWN_OR_DISABLED'],
            'JAMMING_STATE_OK': cls.__constants['JAMMING_STATE_OK'],
            'JAMMING_STATE_WARNING': cls.__constants['JAMMING_STATE_WARNING'],
            'JAMMING_STATE_CRITICAL': cls.__constants['JAMMING_STATE_CRITICAL'],
            'FLAGS_XTAL_ABSENT': cls.__constants['FLAGS_XTAL_ABSENT'],
            'JAM_IND_NONE': cls.__constants['JAM_IND_NONE'],
            'JAM_IND_STRONG': cls.__constants['JAM_IND_STRONG'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_MonHW6.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_MonHW6.__constants['MESSAGE_ID']

    @property
    def A_STATUS_INIT(self):
        """Message constant 'A_STATUS_INIT'."""
        return Metaclass_MonHW6.__constants['A_STATUS_INIT']

    @property
    def A_STATUS_UNKNOWN(self):
        """Message constant 'A_STATUS_UNKNOWN'."""
        return Metaclass_MonHW6.__constants['A_STATUS_UNKNOWN']

    @property
    def A_STATUS_OK(self):
        """Message constant 'A_STATUS_OK'."""
        return Metaclass_MonHW6.__constants['A_STATUS_OK']

    @property
    def A_STATUS_SHORT(self):
        """Message constant 'A_STATUS_SHORT'."""
        return Metaclass_MonHW6.__constants['A_STATUS_SHORT']

    @property
    def A_STATUS_OPEN(self):
        """Message constant 'A_STATUS_OPEN'."""
        return Metaclass_MonHW6.__constants['A_STATUS_OPEN']

    @property
    def A_POWER_OFF(self):
        """Message constant 'A_POWER_OFF'."""
        return Metaclass_MonHW6.__constants['A_POWER_OFF']

    @property
    def A_POWER_ON(self):
        """Message constant 'A_POWER_ON'."""
        return Metaclass_MonHW6.__constants['A_POWER_ON']

    @property
    def A_POWER_UNKNOWN(self):
        """Message constant 'A_POWER_UNKNOWN'."""
        return Metaclass_MonHW6.__constants['A_POWER_UNKNOWN']

    @property
    def FLAGS_RTC_CALIB(self):
        """Message constant 'FLAGS_RTC_CALIB'."""
        return Metaclass_MonHW6.__constants['FLAGS_RTC_CALIB']

    @property
    def FLAGS_SAFE_BOOT(self):
        """Message constant 'FLAGS_SAFE_BOOT'."""
        return Metaclass_MonHW6.__constants['FLAGS_SAFE_BOOT']

    @property
    def FLAGS_JAMMING_STATE_MASK(self):
        """Message constant 'FLAGS_JAMMING_STATE_MASK'."""
        return Metaclass_MonHW6.__constants['FLAGS_JAMMING_STATE_MASK']

    @property
    def JAMMING_STATE_UNKNOWN_OR_DISABLED(self):
        """Message constant 'JAMMING_STATE_UNKNOWN_OR_DISABLED'."""
        return Metaclass_MonHW6.__constants['JAMMING_STATE_UNKNOWN_OR_DISABLED']

    @property
    def JAMMING_STATE_OK(self):
        """Message constant 'JAMMING_STATE_OK'."""
        return Metaclass_MonHW6.__constants['JAMMING_STATE_OK']

    @property
    def JAMMING_STATE_WARNING(self):
        """Message constant 'JAMMING_STATE_WARNING'."""
        return Metaclass_MonHW6.__constants['JAMMING_STATE_WARNING']

    @property
    def JAMMING_STATE_CRITICAL(self):
        """Message constant 'JAMMING_STATE_CRITICAL'."""
        return Metaclass_MonHW6.__constants['JAMMING_STATE_CRITICAL']

    @property
    def FLAGS_XTAL_ABSENT(self):
        """Message constant 'FLAGS_XTAL_ABSENT'."""
        return Metaclass_MonHW6.__constants['FLAGS_XTAL_ABSENT']

    @property
    def JAM_IND_NONE(self):
        """Message constant 'JAM_IND_NONE'."""
        return Metaclass_MonHW6.__constants['JAM_IND_NONE']

    @property
    def JAM_IND_STRONG(self):
        """Message constant 'JAM_IND_STRONG'."""
        return Metaclass_MonHW6.__constants['JAM_IND_STRONG']


class MonHW6(metaclass=Metaclass_MonHW6):
    """
    Message class 'MonHW6'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      A_STATUS_INIT
      A_STATUS_UNKNOWN
      A_STATUS_OK
      A_STATUS_SHORT
      A_STATUS_OPEN
      A_POWER_OFF
      A_POWER_ON
      A_POWER_UNKNOWN
      FLAGS_RTC_CALIB
      FLAGS_SAFE_BOOT
      FLAGS_JAMMING_STATE_MASK
      JAMMING_STATE_UNKNOWN_OR_DISABLED
      JAMMING_STATE_OK
      JAMMING_STATE_WARNING
      JAMMING_STATE_CRITICAL
      FLAGS_XTAL_ABSENT
      JAM_IND_NONE
      JAM_IND_STRONG
    """

    __slots__ = [
        '_pin_sel',
        '_pin_bank',
        '_pin_dir',
        '_pin_val',
        '_noise_per_ms',
        '_agc_cnt',
        '_a_status',
        '_a_power',
        '_flags',
        '_reserved0',
        '_used_mask',
        '_vp',
        '_jam_ind',
        '_reserved1',
        '_pin_irq',
        '_pull_h',
        '_pull_l',
    ]

    _fields_and_field_types = {
        'pin_sel': 'uint32',
        'pin_bank': 'uint32',
        'pin_dir': 'uint32',
        'pin_val': 'uint32',
        'noise_per_ms': 'uint16',
        'agc_cnt': 'uint16',
        'a_status': 'uint8',
        'a_power': 'uint8',
        'flags': 'uint8',
        'reserved0': 'uint8',
        'used_mask': 'uint32',
        'vp': 'uint8[25]',
        'jam_ind': 'uint8',
        'reserved1': 'uint8[2]',
        'pin_irq': 'uint32',
        'pull_h': 'uint32',
        'pull_l': 'uint32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 25),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pin_sel = kwargs.get('pin_sel', int())
        self.pin_bank = kwargs.get('pin_bank', int())
        self.pin_dir = kwargs.get('pin_dir', int())
        self.pin_val = kwargs.get('pin_val', int())
        self.noise_per_ms = kwargs.get('noise_per_ms', int())
        self.agc_cnt = kwargs.get('agc_cnt', int())
        self.a_status = kwargs.get('a_status', int())
        self.a_power = kwargs.get('a_power', int())
        self.flags = kwargs.get('flags', int())
        self.reserved0 = kwargs.get('reserved0', int())
        self.used_mask = kwargs.get('used_mask', int())
        if 'vp' not in kwargs:
            self.vp = numpy.zeros(25, dtype=numpy.uint8)
        else:
            self.vp = numpy.array(kwargs.get('vp'), dtype=numpy.uint8)
            assert self.vp.shape == (25, )
        self.jam_ind = kwargs.get('jam_ind', int())
        if 'reserved1' not in kwargs:
            self.reserved1 = numpy.zeros(2, dtype=numpy.uint8)
        else:
            self.reserved1 = numpy.array(kwargs.get('reserved1'), dtype=numpy.uint8)
            assert self.reserved1.shape == (2, )
        self.pin_irq = kwargs.get('pin_irq', int())
        self.pull_h = kwargs.get('pull_h', int())
        self.pull_l = kwargs.get('pull_l', int())

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
        if self.pin_sel != other.pin_sel:
            return False
        if self.pin_bank != other.pin_bank:
            return False
        if self.pin_dir != other.pin_dir:
            return False
        if self.pin_val != other.pin_val:
            return False
        if self.noise_per_ms != other.noise_per_ms:
            return False
        if self.agc_cnt != other.agc_cnt:
            return False
        if self.a_status != other.a_status:
            return False
        if self.a_power != other.a_power:
            return False
        if self.flags != other.flags:
            return False
        if self.reserved0 != other.reserved0:
            return False
        if self.used_mask != other.used_mask:
            return False
        if all(self.vp != other.vp):
            return False
        if self.jam_ind != other.jam_ind:
            return False
        if all(self.reserved1 != other.reserved1):
            return False
        if self.pin_irq != other.pin_irq:
            return False
        if self.pull_h != other.pull_h:
            return False
        if self.pull_l != other.pull_l:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pin_sel(self):
        """Message field 'pin_sel'."""
        return self._pin_sel

    @pin_sel.setter
    def pin_sel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin_sel' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pin_sel' field must be an unsigned integer in [0, 4294967295]"
        self._pin_sel = value

    @builtins.property
    def pin_bank(self):
        """Message field 'pin_bank'."""
        return self._pin_bank

    @pin_bank.setter
    def pin_bank(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin_bank' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pin_bank' field must be an unsigned integer in [0, 4294967295]"
        self._pin_bank = value

    @builtins.property
    def pin_dir(self):
        """Message field 'pin_dir'."""
        return self._pin_dir

    @pin_dir.setter
    def pin_dir(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin_dir' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pin_dir' field must be an unsigned integer in [0, 4294967295]"
        self._pin_dir = value

    @builtins.property
    def pin_val(self):
        """Message field 'pin_val'."""
        return self._pin_val

    @pin_val.setter
    def pin_val(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin_val' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pin_val' field must be an unsigned integer in [0, 4294967295]"
        self._pin_val = value

    @builtins.property
    def noise_per_ms(self):
        """Message field 'noise_per_ms'."""
        return self._noise_per_ms

    @noise_per_ms.setter
    def noise_per_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'noise_per_ms' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'noise_per_ms' field must be an unsigned integer in [0, 65535]"
        self._noise_per_ms = value

    @builtins.property
    def agc_cnt(self):
        """Message field 'agc_cnt'."""
        return self._agc_cnt

    @agc_cnt.setter
    def agc_cnt(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'agc_cnt' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'agc_cnt' field must be an unsigned integer in [0, 65535]"
        self._agc_cnt = value

    @builtins.property
    def a_status(self):
        """Message field 'a_status'."""
        return self._a_status

    @a_status.setter
    def a_status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'a_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'a_status' field must be an unsigned integer in [0, 255]"
        self._a_status = value

    @builtins.property
    def a_power(self):
        """Message field 'a_power'."""
        return self._a_power

    @a_power.setter
    def a_power(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'a_power' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'a_power' field must be an unsigned integer in [0, 255]"
        self._a_power = value

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
    def reserved0(self):
        """Message field 'reserved0'."""
        return self._reserved0

    @reserved0.setter
    def reserved0(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved0' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'reserved0' field must be an unsigned integer in [0, 255]"
        self._reserved0 = value

    @builtins.property
    def used_mask(self):
        """Message field 'used_mask'."""
        return self._used_mask

    @used_mask.setter
    def used_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'used_mask' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'used_mask' field must be an unsigned integer in [0, 4294967295]"
        self._used_mask = value

    @builtins.property
    def vp(self):
        """Message field 'vp'."""
        return self._vp

    @vp.setter
    def vp(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'vp' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 25, \
                "The 'vp' numpy.ndarray() must have a size of 25"
            self._vp = value
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
                 len(value) == 25 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'vp' field must be a set or sequence with length 25 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._vp = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def jam_ind(self):
        """Message field 'jam_ind'."""
        return self._jam_ind

    @jam_ind.setter
    def jam_ind(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'jam_ind' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'jam_ind' field must be an unsigned integer in [0, 255]"
        self._jam_ind = value

    @builtins.property
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'reserved1' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2, \
                "The 'reserved1' numpy.ndarray() must have a size of 2"
            self._reserved1 = value
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
                 len(value) == 2 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'reserved1' field must be a set or sequence with length 2 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._reserved1 = numpy.array(value, dtype=numpy.uint8)

    @builtins.property
    def pin_irq(self):
        """Message field 'pin_irq'."""
        return self._pin_irq

    @pin_irq.setter
    def pin_irq(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pin_irq' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pin_irq' field must be an unsigned integer in [0, 4294967295]"
        self._pin_irq = value

    @builtins.property
    def pull_h(self):
        """Message field 'pull_h'."""
        return self._pull_h

    @pull_h.setter
    def pull_h(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pull_h' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pull_h' field must be an unsigned integer in [0, 4294967295]"
        self._pull_h = value

    @builtins.property
    def pull_l(self):
        """Message field 'pull_l'."""
        return self._pull_l

    @pull_l.setter
    def pull_l(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'pull_l' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'pull_l' field must be an unsigned integer in [0, 4294967295]"
        self._pull_l = value
