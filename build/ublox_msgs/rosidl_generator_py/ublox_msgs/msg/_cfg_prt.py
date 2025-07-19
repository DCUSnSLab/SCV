# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ublox_msgs:msg/CfgPRT.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CfgPRT(type):
    """Metaclass of message 'CfgPRT'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'CLASS_ID': 6,
        'MESSAGE_ID': 0,
        'PORT_ID_DDC': 0,
        'PORT_ID_UART1': 1,
        'PORT_ID_UART2': 2,
        'PORT_ID_USB': 3,
        'PORT_ID_SPI': 4,
        'TX_READY_EN': 1,
        'TX_READY_POLARITY_HIGH_ACTIVE': 0,
        'TX_READY_POLARITY_LOW_ACTIVE': 2,
        'TX_READY_PIN_SHIFT': 2,
        'TX_READY_PIN_MASK': 124,
        'TX_READY_THRES_SHIFT': 7,
        'TX_READY_THRES_MASK': 65408,
        'MODE_DDC_SLAVE_ADDR_SHIFT': 1,
        'MODE_DDC_SLAVE_ADDR_MASK': 254,
        'MODE_RESERVED1': 16,
        'MODE_CHAR_LEN_MASK': 192,
        'MODE_CHAR_LEN_5BIT': 0,
        'MODE_CHAR_LEN_6BIT': 64,
        'MODE_CHAR_LEN_7BIT': 128,
        'MODE_CHAR_LEN_8BIT': 192,
        'MODE_PARITY_MASK': 3584,
        'MODE_PARITY_EVEN': 0,
        'MODE_PARITY_ODD': 512,
        'MODE_PARITY_NO': 2048,
        'MODE_STOP_BITS_MASK': 12288,
        'MODE_STOP_BITS_1': 0,
        'MODE_STOP_BITS_15': 4096,
        'MODE_STOP_BITS_2': 8192,
        'MODE_STOP_BITS_05': 12288,
        'MODE_SPI_SPI_MODE_CPOL': 4,
        'MODE_SPI_SPI_MODE_CPHA': 2,
        'MODE_SPI_FLOW_CONTROL': 64,
        'MODE_SPI_FF_COUNT_SHIFT': 8,
        'MODE_SPI_FF_COUNT_MASK': 16128,
        'PROTO_UBX': 1,
        'PROTO_NMEA': 2,
        'PROTO_RTCM': 4,
        'PROTO_RTCM3': 32,
        'FLAGS_EXTENDED_TX_TIMEOUT': 2,
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
                'ublox_msgs.msg.CfgPRT')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cfg_prt
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cfg_prt
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cfg_prt
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cfg_prt
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cfg_prt

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'CLASS_ID': cls.__constants['CLASS_ID'],
            'MESSAGE_ID': cls.__constants['MESSAGE_ID'],
            'PORT_ID_DDC': cls.__constants['PORT_ID_DDC'],
            'PORT_ID_UART1': cls.__constants['PORT_ID_UART1'],
            'PORT_ID_UART2': cls.__constants['PORT_ID_UART2'],
            'PORT_ID_USB': cls.__constants['PORT_ID_USB'],
            'PORT_ID_SPI': cls.__constants['PORT_ID_SPI'],
            'TX_READY_EN': cls.__constants['TX_READY_EN'],
            'TX_READY_POLARITY_HIGH_ACTIVE': cls.__constants['TX_READY_POLARITY_HIGH_ACTIVE'],
            'TX_READY_POLARITY_LOW_ACTIVE': cls.__constants['TX_READY_POLARITY_LOW_ACTIVE'],
            'TX_READY_PIN_SHIFT': cls.__constants['TX_READY_PIN_SHIFT'],
            'TX_READY_PIN_MASK': cls.__constants['TX_READY_PIN_MASK'],
            'TX_READY_THRES_SHIFT': cls.__constants['TX_READY_THRES_SHIFT'],
            'TX_READY_THRES_MASK': cls.__constants['TX_READY_THRES_MASK'],
            'MODE_DDC_SLAVE_ADDR_SHIFT': cls.__constants['MODE_DDC_SLAVE_ADDR_SHIFT'],
            'MODE_DDC_SLAVE_ADDR_MASK': cls.__constants['MODE_DDC_SLAVE_ADDR_MASK'],
            'MODE_RESERVED1': cls.__constants['MODE_RESERVED1'],
            'MODE_CHAR_LEN_MASK': cls.__constants['MODE_CHAR_LEN_MASK'],
            'MODE_CHAR_LEN_5BIT': cls.__constants['MODE_CHAR_LEN_5BIT'],
            'MODE_CHAR_LEN_6BIT': cls.__constants['MODE_CHAR_LEN_6BIT'],
            'MODE_CHAR_LEN_7BIT': cls.__constants['MODE_CHAR_LEN_7BIT'],
            'MODE_CHAR_LEN_8BIT': cls.__constants['MODE_CHAR_LEN_8BIT'],
            'MODE_PARITY_MASK': cls.__constants['MODE_PARITY_MASK'],
            'MODE_PARITY_EVEN': cls.__constants['MODE_PARITY_EVEN'],
            'MODE_PARITY_ODD': cls.__constants['MODE_PARITY_ODD'],
            'MODE_PARITY_NO': cls.__constants['MODE_PARITY_NO'],
            'MODE_STOP_BITS_MASK': cls.__constants['MODE_STOP_BITS_MASK'],
            'MODE_STOP_BITS_1': cls.__constants['MODE_STOP_BITS_1'],
            'MODE_STOP_BITS_15': cls.__constants['MODE_STOP_BITS_15'],
            'MODE_STOP_BITS_2': cls.__constants['MODE_STOP_BITS_2'],
            'MODE_STOP_BITS_05': cls.__constants['MODE_STOP_BITS_05'],
            'MODE_SPI_SPI_MODE_CPOL': cls.__constants['MODE_SPI_SPI_MODE_CPOL'],
            'MODE_SPI_SPI_MODE_CPHA': cls.__constants['MODE_SPI_SPI_MODE_CPHA'],
            'MODE_SPI_FLOW_CONTROL': cls.__constants['MODE_SPI_FLOW_CONTROL'],
            'MODE_SPI_FF_COUNT_SHIFT': cls.__constants['MODE_SPI_FF_COUNT_SHIFT'],
            'MODE_SPI_FF_COUNT_MASK': cls.__constants['MODE_SPI_FF_COUNT_MASK'],
            'PROTO_UBX': cls.__constants['PROTO_UBX'],
            'PROTO_NMEA': cls.__constants['PROTO_NMEA'],
            'PROTO_RTCM': cls.__constants['PROTO_RTCM'],
            'PROTO_RTCM3': cls.__constants['PROTO_RTCM3'],
            'FLAGS_EXTENDED_TX_TIMEOUT': cls.__constants['FLAGS_EXTENDED_TX_TIMEOUT'],
        }

    @property
    def CLASS_ID(self):
        """Message constant 'CLASS_ID'."""
        return Metaclass_CfgPRT.__constants['CLASS_ID']

    @property
    def MESSAGE_ID(self):
        """Message constant 'MESSAGE_ID'."""
        return Metaclass_CfgPRT.__constants['MESSAGE_ID']

    @property
    def PORT_ID_DDC(self):
        """Message constant 'PORT_ID_DDC'."""
        return Metaclass_CfgPRT.__constants['PORT_ID_DDC']

    @property
    def PORT_ID_UART1(self):
        """Message constant 'PORT_ID_UART1'."""
        return Metaclass_CfgPRT.__constants['PORT_ID_UART1']

    @property
    def PORT_ID_UART2(self):
        """Message constant 'PORT_ID_UART2'."""
        return Metaclass_CfgPRT.__constants['PORT_ID_UART2']

    @property
    def PORT_ID_USB(self):
        """Message constant 'PORT_ID_USB'."""
        return Metaclass_CfgPRT.__constants['PORT_ID_USB']

    @property
    def PORT_ID_SPI(self):
        """Message constant 'PORT_ID_SPI'."""
        return Metaclass_CfgPRT.__constants['PORT_ID_SPI']

    @property
    def TX_READY_EN(self):
        """Message constant 'TX_READY_EN'."""
        return Metaclass_CfgPRT.__constants['TX_READY_EN']

    @property
    def TX_READY_POLARITY_HIGH_ACTIVE(self):
        """Message constant 'TX_READY_POLARITY_HIGH_ACTIVE'."""
        return Metaclass_CfgPRT.__constants['TX_READY_POLARITY_HIGH_ACTIVE']

    @property
    def TX_READY_POLARITY_LOW_ACTIVE(self):
        """Message constant 'TX_READY_POLARITY_LOW_ACTIVE'."""
        return Metaclass_CfgPRT.__constants['TX_READY_POLARITY_LOW_ACTIVE']

    @property
    def TX_READY_PIN_SHIFT(self):
        """Message constant 'TX_READY_PIN_SHIFT'."""
        return Metaclass_CfgPRT.__constants['TX_READY_PIN_SHIFT']

    @property
    def TX_READY_PIN_MASK(self):
        """Message constant 'TX_READY_PIN_MASK'."""
        return Metaclass_CfgPRT.__constants['TX_READY_PIN_MASK']

    @property
    def TX_READY_THRES_SHIFT(self):
        """Message constant 'TX_READY_THRES_SHIFT'."""
        return Metaclass_CfgPRT.__constants['TX_READY_THRES_SHIFT']

    @property
    def TX_READY_THRES_MASK(self):
        """Message constant 'TX_READY_THRES_MASK'."""
        return Metaclass_CfgPRT.__constants['TX_READY_THRES_MASK']

    @property
    def MODE_DDC_SLAVE_ADDR_SHIFT(self):
        """Message constant 'MODE_DDC_SLAVE_ADDR_SHIFT'."""
        return Metaclass_CfgPRT.__constants['MODE_DDC_SLAVE_ADDR_SHIFT']

    @property
    def MODE_DDC_SLAVE_ADDR_MASK(self):
        """Message constant 'MODE_DDC_SLAVE_ADDR_MASK'."""
        return Metaclass_CfgPRT.__constants['MODE_DDC_SLAVE_ADDR_MASK']

    @property
    def MODE_RESERVED1(self):
        """Message constant 'MODE_RESERVED1'."""
        return Metaclass_CfgPRT.__constants['MODE_RESERVED1']

    @property
    def MODE_CHAR_LEN_MASK(self):
        """Message constant 'MODE_CHAR_LEN_MASK'."""
        return Metaclass_CfgPRT.__constants['MODE_CHAR_LEN_MASK']

    @property
    def MODE_CHAR_LEN_5BIT(self):
        """Message constant 'MODE_CHAR_LEN_5BIT'."""
        return Metaclass_CfgPRT.__constants['MODE_CHAR_LEN_5BIT']

    @property
    def MODE_CHAR_LEN_6BIT(self):
        """Message constant 'MODE_CHAR_LEN_6BIT'."""
        return Metaclass_CfgPRT.__constants['MODE_CHAR_LEN_6BIT']

    @property
    def MODE_CHAR_LEN_7BIT(self):
        """Message constant 'MODE_CHAR_LEN_7BIT'."""
        return Metaclass_CfgPRT.__constants['MODE_CHAR_LEN_7BIT']

    @property
    def MODE_CHAR_LEN_8BIT(self):
        """Message constant 'MODE_CHAR_LEN_8BIT'."""
        return Metaclass_CfgPRT.__constants['MODE_CHAR_LEN_8BIT']

    @property
    def MODE_PARITY_MASK(self):
        """Message constant 'MODE_PARITY_MASK'."""
        return Metaclass_CfgPRT.__constants['MODE_PARITY_MASK']

    @property
    def MODE_PARITY_EVEN(self):
        """Message constant 'MODE_PARITY_EVEN'."""
        return Metaclass_CfgPRT.__constants['MODE_PARITY_EVEN']

    @property
    def MODE_PARITY_ODD(self):
        """Message constant 'MODE_PARITY_ODD'."""
        return Metaclass_CfgPRT.__constants['MODE_PARITY_ODD']

    @property
    def MODE_PARITY_NO(self):
        """Message constant 'MODE_PARITY_NO'."""
        return Metaclass_CfgPRT.__constants['MODE_PARITY_NO']

    @property
    def MODE_STOP_BITS_MASK(self):
        """Message constant 'MODE_STOP_BITS_MASK'."""
        return Metaclass_CfgPRT.__constants['MODE_STOP_BITS_MASK']

    @property
    def MODE_STOP_BITS_1(self):
        """Message constant 'MODE_STOP_BITS_1'."""
        return Metaclass_CfgPRT.__constants['MODE_STOP_BITS_1']

    @property
    def MODE_STOP_BITS_15(self):
        """Message constant 'MODE_STOP_BITS_15'."""
        return Metaclass_CfgPRT.__constants['MODE_STOP_BITS_15']

    @property
    def MODE_STOP_BITS_2(self):
        """Message constant 'MODE_STOP_BITS_2'."""
        return Metaclass_CfgPRT.__constants['MODE_STOP_BITS_2']

    @property
    def MODE_STOP_BITS_05(self):
        """Message constant 'MODE_STOP_BITS_05'."""
        return Metaclass_CfgPRT.__constants['MODE_STOP_BITS_05']

    @property
    def MODE_SPI_SPI_MODE_CPOL(self):
        """Message constant 'MODE_SPI_SPI_MODE_CPOL'."""
        return Metaclass_CfgPRT.__constants['MODE_SPI_SPI_MODE_CPOL']

    @property
    def MODE_SPI_SPI_MODE_CPHA(self):
        """Message constant 'MODE_SPI_SPI_MODE_CPHA'."""
        return Metaclass_CfgPRT.__constants['MODE_SPI_SPI_MODE_CPHA']

    @property
    def MODE_SPI_FLOW_CONTROL(self):
        """Message constant 'MODE_SPI_FLOW_CONTROL'."""
        return Metaclass_CfgPRT.__constants['MODE_SPI_FLOW_CONTROL']

    @property
    def MODE_SPI_FF_COUNT_SHIFT(self):
        """Message constant 'MODE_SPI_FF_COUNT_SHIFT'."""
        return Metaclass_CfgPRT.__constants['MODE_SPI_FF_COUNT_SHIFT']

    @property
    def MODE_SPI_FF_COUNT_MASK(self):
        """Message constant 'MODE_SPI_FF_COUNT_MASK'."""
        return Metaclass_CfgPRT.__constants['MODE_SPI_FF_COUNT_MASK']

    @property
    def PROTO_UBX(self):
        """Message constant 'PROTO_UBX'."""
        return Metaclass_CfgPRT.__constants['PROTO_UBX']

    @property
    def PROTO_NMEA(self):
        """Message constant 'PROTO_NMEA'."""
        return Metaclass_CfgPRT.__constants['PROTO_NMEA']

    @property
    def PROTO_RTCM(self):
        """Message constant 'PROTO_RTCM'."""
        return Metaclass_CfgPRT.__constants['PROTO_RTCM']

    @property
    def PROTO_RTCM3(self):
        """Message constant 'PROTO_RTCM3'."""
        return Metaclass_CfgPRT.__constants['PROTO_RTCM3']

    @property
    def FLAGS_EXTENDED_TX_TIMEOUT(self):
        """Message constant 'FLAGS_EXTENDED_TX_TIMEOUT'."""
        return Metaclass_CfgPRT.__constants['FLAGS_EXTENDED_TX_TIMEOUT']


class CfgPRT(metaclass=Metaclass_CfgPRT):
    """
    Message class 'CfgPRT'.

    Constants:
      CLASS_ID
      MESSAGE_ID
      PORT_ID_DDC
      PORT_ID_UART1
      PORT_ID_UART2
      PORT_ID_USB
      PORT_ID_SPI
      TX_READY_EN
      TX_READY_POLARITY_HIGH_ACTIVE
      TX_READY_POLARITY_LOW_ACTIVE
      TX_READY_PIN_SHIFT
      TX_READY_PIN_MASK
      TX_READY_THRES_SHIFT
      TX_READY_THRES_MASK
      MODE_DDC_SLAVE_ADDR_SHIFT
      MODE_DDC_SLAVE_ADDR_MASK
      MODE_RESERVED1
      MODE_CHAR_LEN_MASK
      MODE_CHAR_LEN_5BIT
      MODE_CHAR_LEN_6BIT
      MODE_CHAR_LEN_7BIT
      MODE_CHAR_LEN_8BIT
      MODE_PARITY_MASK
      MODE_PARITY_EVEN
      MODE_PARITY_ODD
      MODE_PARITY_NO
      MODE_STOP_BITS_MASK
      MODE_STOP_BITS_1
      MODE_STOP_BITS_15
      MODE_STOP_BITS_2
      MODE_STOP_BITS_05
      MODE_SPI_SPI_MODE_CPOL
      MODE_SPI_SPI_MODE_CPHA
      MODE_SPI_FLOW_CONTROL
      MODE_SPI_FF_COUNT_SHIFT
      MODE_SPI_FF_COUNT_MASK
      PROTO_UBX
      PROTO_NMEA
      PROTO_RTCM
      PROTO_RTCM3
      FLAGS_EXTENDED_TX_TIMEOUT
    """

    __slots__ = [
        '_port_id',
        '_reserved0',
        '_tx_ready',
        '_mode',
        '_baud_rate',
        '_in_proto_mask',
        '_out_proto_mask',
        '_flags',
        '_reserved1',
    ]

    _fields_and_field_types = {
        'port_id': 'uint8',
        'reserved0': 'uint8',
        'tx_ready': 'uint16',
        'mode': 'uint32',
        'baud_rate': 'uint32',
        'in_proto_mask': 'uint16',
        'out_proto_mask': 'uint16',
        'flags': 'uint16',
        'reserved1': 'uint16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.port_id = kwargs.get('port_id', int())
        self.reserved0 = kwargs.get('reserved0', int())
        self.tx_ready = kwargs.get('tx_ready', int())
        self.mode = kwargs.get('mode', int())
        self.baud_rate = kwargs.get('baud_rate', int())
        self.in_proto_mask = kwargs.get('in_proto_mask', int())
        self.out_proto_mask = kwargs.get('out_proto_mask', int())
        self.flags = kwargs.get('flags', int())
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
        if self.port_id != other.port_id:
            return False
        if self.reserved0 != other.reserved0:
            return False
        if self.tx_ready != other.tx_ready:
            return False
        if self.mode != other.mode:
            return False
        if self.baud_rate != other.baud_rate:
            return False
        if self.in_proto_mask != other.in_proto_mask:
            return False
        if self.out_proto_mask != other.out_proto_mask:
            return False
        if self.flags != other.flags:
            return False
        if self.reserved1 != other.reserved1:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def port_id(self):
        """Message field 'port_id'."""
        return self._port_id

    @port_id.setter
    def port_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'port_id' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'port_id' field must be an unsigned integer in [0, 255]"
        self._port_id = value

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
    def tx_ready(self):
        """Message field 'tx_ready'."""
        return self._tx_ready

    @tx_ready.setter
    def tx_ready(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'tx_ready' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'tx_ready' field must be an unsigned integer in [0, 65535]"
        self._tx_ready = value

    @builtins.property
    def mode(self):
        """Message field 'mode'."""
        return self._mode

    @mode.setter
    def mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'mode' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'mode' field must be an unsigned integer in [0, 4294967295]"
        self._mode = value

    @builtins.property
    def baud_rate(self):
        """Message field 'baud_rate'."""
        return self._baud_rate

    @baud_rate.setter
    def baud_rate(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'baud_rate' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'baud_rate' field must be an unsigned integer in [0, 4294967295]"
        self._baud_rate = value

    @builtins.property
    def in_proto_mask(self):
        """Message field 'in_proto_mask'."""
        return self._in_proto_mask

    @in_proto_mask.setter
    def in_proto_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'in_proto_mask' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'in_proto_mask' field must be an unsigned integer in [0, 65535]"
        self._in_proto_mask = value

    @builtins.property
    def out_proto_mask(self):
        """Message field 'out_proto_mask'."""
        return self._out_proto_mask

    @out_proto_mask.setter
    def out_proto_mask(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'out_proto_mask' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'out_proto_mask' field must be an unsigned integer in [0, 65535]"
        self._out_proto_mask = value

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
    def reserved1(self):
        """Message field 'reserved1'."""
        return self._reserved1

    @reserved1.setter
    def reserved1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'reserved1' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'reserved1' field must be an unsigned integer in [0, 65535]"
        self._reserved1 = value
