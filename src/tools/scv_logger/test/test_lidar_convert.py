import struct

import pytest

pytest.importorskip('rosbag2_py')

from scv_logger.ros.lidar_convert import header_stamp, storage_id_of  # noqa: E402


def test_header_stamp():
    cdr = b'\x00\x01\x00\x00' + struct.pack('<iI', 1791263748, 123456789) + b'\x07\x00\x00\x00velodyne'
    assert header_stamp(cdr) == (1791263748, 123456789)


def test_storage_id_of(tmp_path):
    (tmp_path / 'a').mkdir()
    (tmp_path / 'a' / 'metadata.yaml').write_text('rosbag2_bagfile_information:\n  storage_identifier: sqlite3\n')
    assert storage_id_of(tmp_path / 'a') == 'sqlite3'
    (tmp_path / 'b').mkdir()
    (tmp_path / 'b' / 'x_0.db3').write_bytes(b'')
    assert storage_id_of(tmp_path / 'b') == 'sqlite3'
    (tmp_path / 'c').mkdir()
    assert storage_id_of(tmp_path / 'c') == 'mcap'
