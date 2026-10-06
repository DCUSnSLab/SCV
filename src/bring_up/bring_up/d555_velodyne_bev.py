"""Render calibrated D555 and Velodyne point clouds as a fused BEV image."""

import time

import cv2
import numpy as np
import rclpy
from cv_bridge import CvBridge
from rclpy.node import Node
from rclpy.qos import (DurabilityPolicy, HistoryPolicy, QoSProfile,
                       ReliabilityPolicy)
from rclpy.time import Time
from sensor_msgs.msg import Image, PointCloud2
from sensor_msgs_py import point_cloud2
from tf2_ros import Buffer, TransformException, TransformListener


def quaternion_matrix(x, y, z, w):
    """Return a 3x3 rotation matrix for a normalized quaternion."""
    norm = np.linalg.norm([x, y, z, w])
    if not np.isfinite(norm) or norm == 0.0:
        raise ValueError('invalid transform quaternion')
    x, y, z, w = np.asarray([x, y, z, w], dtype=np.float32) / norm
    return np.asarray([
        [1 - 2 * (y * y + z * z), 2 * (x * y - z * w),
         2 * (x * z + y * w)],
        [2 * (x * y + z * w), 1 - 2 * (x * x + z * z),
         2 * (y * z - x * w)],
        [2 * (x * z - y * w), 2 * (y * z + x * w),
         1 - 2 * (x * x + y * y)],
    ], dtype=np.float32)


def project_cells(points, x_min, x_max, y_min, y_max, resolution):
    """Project XYZ points into BEV row/column coordinates."""
    height = int(np.ceil((x_max - x_min) / resolution))
    width = int(np.ceil((y_max - y_min) / resolution))
    rows = np.floor((x_max - points[:, 0]) / resolution).astype(np.int64)
    cols = np.floor((y_max - points[:, 1]) / resolution).astype(np.int64)
    valid = ((rows >= 0) & (rows < height) &
             (cols >= 0) & (cols < width))
    return rows, cols, valid, (height, width)


def unpack_bgr(values):
    """Convert ROS packed float32/uint32 RGB values into OpenCV BGR."""
    array = np.asarray(values).reshape(-1)
    if array.dtype.kind == 'f':
        packed = np.ascontiguousarray(array.astype(np.float32)).view(np.uint32)
    else:
        packed = array.astype(np.uint32, copy=False)
    return np.column_stack((packed & 0xff,
                            (packed >> 8) & 0xff,
                            (packed >> 16) & 0xff)).astype(np.uint8)


class D555VelodyneBEV(Node):
    """Fuse the latest calibrated camera and LiDAR clouds into one image."""

    def __init__(self):
        super().__init__('d555_velodyne_bev')
        defaults = {
            'camera_topic': '/camera/camera/depth/color/points',
            'velodyne_topic': '/velodyne_points',
            'target_frame': 'velodyne',
            'output_topic': '/bev/d555_velodyne/image',
            'mask_topic': '/bev/d555_velodyne/mask',
            'x_min': -5.0,
            'x_max': 20.0,
            'y_min': -10.0,
            'y_max': 10.0,
            'z_min': -1.5,
            'z_max': 2.0,
            'resolution': 0.05,
            'publish_rate': 10.0,
            'stale_timeout': 1.0,
            'require_both': True,
            'velodyne_alpha': 0.8,
            'velodyne_point_radius': 1,
            'camera_stride': 2,
            'velodyne_stride': 1,
            'opencv_threads': 1,
        }
        for name, value in defaults.items():
            self.declare_parameter(name, value)
        params = {name: self.get_parameter(name).value for name in defaults}
        self._validate(params)

        self.target_frame = params['target_frame']
        self.x_min = params['x_min']
        self.x_max = params['x_max']
        self.y_min = params['y_min']
        self.y_max = params['y_max']
        self.z_min = params['z_min']
        self.z_max = params['z_max']
        self.resolution = params['resolution']
        self.stale_timeout = params['stale_timeout']
        self.require_both = params['require_both']
        self.velodyne_alpha = params['velodyne_alpha']
        self.velodyne_point_radius = params['velodyne_point_radius']
        self.strides = {
            'camera': params['camera_stride'],
            'velodyne': params['velodyne_stride'],
        }
        cv2.setNumThreads(params['opencv_threads'])
        self.shape = (
            int(np.ceil((self.x_max - self.x_min) / self.resolution)),
            int(np.ceil((self.y_max - self.y_min) / self.resolution)),
        )

        qos = QoSProfile(
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
            reliability=ReliabilityPolicy.BEST_EFFORT,
            durability=DurabilityPolicy.VOLATILE,
        )
        self.latest = {'camera': None, 'velodyne': None}
        self.generations = {'camera': 0, 'velodyne': 0}
        self.rendered = {}
        self.transform_cache = {}
        self.create_subscription(
            PointCloud2, params['camera_topic'],
            lambda message: self._receive('camera', message), qos)
        self.create_subscription(
            PointCloud2, params['velodyne_topic'],
            lambda message: self._receive('velodyne', message), qos)

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.bridge = CvBridge()
        self.image_publisher = self.create_publisher(
            Image, params['output_topic'], 1)
        self.mask_publisher = self.create_publisher(
            Image, params['mask_topic'], 1)
        self.create_timer(1.0 / params['publish_rate'], self.publish_bev)

    @staticmethod
    def _validate(params):
        if params['x_max'] <= params['x_min']:
            raise ValueError('x_max must be greater than x_min')
        if params['y_max'] <= params['y_min']:
            raise ValueError('y_max must be greater than y_min')
        if params['z_max'] <= params['z_min']:
            raise ValueError('z_max must be greater than z_min')
        if not 0.0 < params['resolution'] <= 1.0:
            raise ValueError('resolution must be in (0, 1]')
        if not 0.0 < params['publish_rate'] <= 60.0:
            raise ValueError('publish_rate must be in (0, 60]')
        if params['stale_timeout'] <= 0.0:
            raise ValueError('stale_timeout must be positive')
        if not 0.0 <= params['velodyne_alpha'] <= 1.0:
            raise ValueError('velodyne_alpha must be in [0, 1]')
        if not 0 <= params['velodyne_point_radius'] <= 5:
            raise ValueError('velodyne_point_radius must be from 0 to 5')
        for name in ('camera_stride', 'velodyne_stride'):
            if not 1 <= params[name] <= 16:
                raise ValueError(f'{name} must be from 1 to 16')
        if not 0 <= params['opencv_threads'] <= 8:
            raise ValueError('opencv_threads must be from 0 to 8')

    def _receive(self, source, message):
        self.generations[source] += 1
        self.latest[source] = (
            message, time.monotonic(), self.generations[source])

    @staticmethod
    def _read_cloud(message, wants_rgb, stride):
        names = {field.name for field in message.fields}
        requested = ['x', 'y', 'z']
        color_name = None
        if wants_rgb:
            if 'rgb' in names:
                color_name = 'rgb'
            elif 'rgba' in names:
                color_name = 'rgba'
            if color_name is not None:
                requested.append(color_name)
        data = point_cloud2.read_points(
            message, field_names=tuple(requested), skip_nans=False)
        # read_points is a zero-copy view over PointCloud2.data. Subsample that
        # view before allocating XYZ/color arrays.
        data = np.asarray(data).reshape(-1)[::stride]
        if len(data) == 0:
            return np.empty((0, 3), dtype=np.float32), None
        points = np.empty((len(data), 3), dtype=np.float32)
        points[:, 0] = data['x']
        points[:, 1] = data['y']
        points[:, 2] = data['z']
        colors = unpack_bgr(data[color_name]) if color_name else None
        return points, colors

    def _transform(self, points, message):
        source_frame = message.header.frame_id
        if source_frame == self.target_frame:
            return points
        cached = self.transform_cache.get(source_frame)
        if cached is not None:
            rotation, translation = cached
            return points @ rotation.T + translation
        transform = self.tf_buffer.lookup_transform(
            self.target_frame, source_frame,
            Time.from_msg(message.header.stamp))
        q = transform.transform.rotation
        rotation = quaternion_matrix(q.x, q.y, q.z, q.w)
        t = transform.transform.translation
        translation = np.asarray([t.x, t.y, t.z], dtype=np.float32)
        # The D555-to-Velodyne calibration and sensor mount TFs are static.
        self.transform_cache[source_frame] = (rotation, translation)
        return points @ rotation.T + translation

    def _rasterize(self, points, colors):
        layer = np.zeros((*self.shape, 3), dtype=np.uint8)
        mask = np.zeros(self.shape, dtype=np.uint8)
        if len(points) == 0:
            return layer, mask
        finite = np.isfinite(points).all(axis=1)
        height_ok = ((points[:, 2] >= self.z_min) &
                     (points[:, 2] <= self.z_max))
        valid_points = finite & height_ok
        points = points[valid_points]
        colors = colors[valid_points]
        if len(points) == 0:
            return layer, mask
        rows, cols, inside, _ = project_cells(
            points, self.x_min, self.x_max, self.y_min, self.y_max,
            self.resolution)
        points = points[inside]
        colors = colors[inside]
        rows = rows[inside]
        cols = cols[inside]
        # Keep the highest return per cell without sorting the entire cloud.
        flat_indices = rows * self.shape[1] + cols
        height_buffer = np.full(
            self.shape[0] * self.shape[1], -np.inf, dtype=np.float32)
        np.maximum.at(height_buffer, flat_indices, points[:, 2])
        winners = points[:, 2] >= height_buffer[flat_indices]
        layer[rows[winners], cols[winners]] = colors[winners]
        mask[rows, cols] = 255
        return layer, mask

    def _grid_background(self):
        image = np.full((*self.shape, 3), 12, dtype=np.uint8)
        interval = max(1, int(round(1.0 / self.resolution)))
        image[::interval, :] = 28
        image[:, ::interval] = 28
        origin_row = int(np.floor(self.x_max / self.resolution))
        origin_col = int(np.floor(self.y_max / self.resolution))
        if 0 <= origin_row < self.shape[0]:
            image[max(0, origin_row - 1):origin_row + 2, :] = (45, 45, 45)
        if 0 <= origin_col < self.shape[1]:
            image[:, max(0, origin_col - 1):origin_col + 2] = (45, 45, 45)
        return image

    def publish_bev(self):
        now = time.monotonic()
        current = {
            name: entry for name, entry in self.latest.items()
            if entry is not None and now - entry[1] <= self.stale_timeout
        }
        if self.require_both and len(current) != 2:
            return
        if not current:
            return

        layers = {}
        newest = None
        changed = False
        for source in ('camera', 'velodyne'):
            if source not in current:
                continue
            message, _, generation = current[source]
            cached = self.rendered.get(source)
            if cached is not None and cached[0] == generation:
                layers[source] = cached[1]
                stamp = cached[2]
                if newest is None or stamp[0] > newest[0]:
                    newest = stamp
                continue
            try:
                points, colors = self._read_cloud(
                    message, wants_rgb=(source == 'camera'),
                    stride=self.strides[source])
                points = self._transform(points, message)
                if source == 'camera':
                    if colors is None:
                        self.get_logger().warning(
                            'D555 cloud has no rgb field; using magenta',
                            throttle_duration_sec=5.0)
                        colors = np.tile([255, 0, 255], (len(points), 1))
                else:
                    normalized = np.clip(
                        (points[:, 2] - self.z_min) /
                        (self.z_max - self.z_min), 0.0, 1.0)
                    colors = cv2.applyColorMap(
                        (normalized * 255).astype(np.uint8),
                        cv2.COLORMAP_TURBO).reshape(-1, 3)
                rendered = self._rasterize(points, colors)
                stamp_seconds = (message.header.stamp.sec +
                                 message.header.stamp.nanosec * 1e-9)
                stamp = (stamp_seconds, message.header.stamp)
                self.rendered[source] = (generation, rendered, stamp)
                layers[source] = rendered
                changed = True
                if newest is None or stamp_seconds > newest[0]:
                    newest = stamp
            except (TransformException, ValueError, KeyError) as error:
                self.get_logger().warning(
                    f'{source} BEV unavailable: {error}',
                    throttle_duration_sec=5.0)

        if self.require_both and len(layers) != 2:
            return
        if not layers:
            return
        if not changed:
            return

        image = self._grid_background()
        union_mask = np.zeros(self.shape, dtype=np.uint8)
        camera = layers.get('camera')
        if camera is not None:
            layer, mask = camera
            image[mask > 0] = layer[mask > 0]
            union_mask = cv2.bitwise_or(union_mask, mask)

        lidar = layers.get('velodyne')
        if lidar is not None:
            layer, mask = lidar
            radius = self.velodyne_point_radius
            if radius > 0:
                size = radius * 2 + 1
                kernel = np.ones((size, size), dtype=np.uint8)
                mask = cv2.dilate(mask, kernel)
                layer = cv2.dilate(layer, kernel)
            active = mask > 0
            image[active] = cv2.addWeighted(
                image[active], 1.0 - self.velodyne_alpha,
                layer[active], self.velodyne_alpha, 0.0)
            union_mask = cv2.bitwise_or(union_mask, mask)

        cv2.putText(image, 'D555 RGB + Velodyne height', (10, 22),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 1,
                    cv2.LINE_AA)
        stamp = newest[1]
        for publisher, array, encoding in (
                (self.image_publisher, image, 'bgr8'),
                (self.mask_publisher, union_mask, 'mono8')):
            output = self.bridge.cv2_to_imgmsg(array, encoding=encoding)
            output.header.frame_id = self.target_frame
            output.header.stamp = stamp
            publisher.publish(output)


def main(args=None):
    rclpy.init(args=args)
    node = D555VelodyneBEV()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
