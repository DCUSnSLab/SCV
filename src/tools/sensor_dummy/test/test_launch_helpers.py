import math
import os

from ament_index_python.packages import get_package_share_directory
import pytest
from sensor_dummy.launch_helpers import camera_frames_urdf
from sensor_dummy.launch_helpers import camera_node_config
from sensor_dummy.launch_helpers import resolve_instances
from sensor_dummy.launch_helpers import urdf_mounts
import xacro
import yaml


def cameras_config():
    path = os.path.join(os.path.dirname(__file__), '..', 'config', 'cameras.yaml')
    with open(path) as f:
        return yaml.safe_load(f)


def robot_urdf():
    return xacro.process_file(
        os.path.join(
            get_package_share_directory('hunter2_description'), 'urdf', 'robot.urdf.xacro'
        )
    ).toxml()


def test_mounts_follow_the_urdf_chain_to_base_link():
    mounts = urdf_mounts(robot_urdf(), 'base_link', ('velodyne', 'vectornav', 'gnss_antenna'))
    assert mounts['velodyne'] == pytest.approx([0.21, 0.0, 0.905, 0.0, 0.0, 0.0, 1.0])
    assert mounts['gnss_antenna'][:3] == pytest.approx([0.008, 0.0, 0.84056])
    half = math.sin(1.570796 / 2.0)
    assert mounts['vectornav'][3:] == pytest.approx([0.0, 0.0, -half, math.cos(1.570796 / 2.0)])


def test_groups_expand_in_config_order():
    config = cameras_config()
    assert resolve_instances(config, ['zedxone', 'cam0'])[:2] == ['cam0', 'cam1']
    assert len(resolve_instances(config, ['zedxone'])) == 8
    assert resolve_instances(config, []) == []


def test_unknown_camera_is_an_error():
    with pytest.raises(RuntimeError):
        resolve_instances(cameras_config(), ['d999'])


def test_zed_x_one_ring_names_match_the_doc():
    parameters, remappings = camera_node_config(cameras_config(), 'cam3')
    assert parameters['stream.color.frame_id'] == 'cam3_camera_frame_optical'
    assert ('~/output/color/image', '/cam3/zed_node/rgb/color/rect/image') in remappings
    assert (
        '~/output/color/camera_info',
        '/cam3/zed_node/rgb/color/rect/camera_info',
    ) in remappings


def test_camera_without_imu_says_so():
    parameters, _ = camera_node_config(cameras_config(), 'd435_left')
    assert parameters['imu.enable'] is False


def test_frames_urdf_has_one_root_and_skips_urdf_mounted_cameras():
    config = cameras_config()
    assert camera_frames_urdf(config, ['d435_left'], 'base_link') is None
    urdf = camera_frames_urdf(config, ['d435i', 'cam0'], 'base_link')
    assert urdf.count('<link name="cam0_camera_frame_optical"/>') == 1
    mounts = urdf_mounts(urdf, 'base_link', ['cam0_camera_frame_optical'])
    assert mounts['cam0_camera_frame_optical'][:3] == pytest.approx([0.15, 0.0, 0.6])
