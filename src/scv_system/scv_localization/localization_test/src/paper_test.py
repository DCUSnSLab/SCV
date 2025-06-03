import rosbag
import matplotlib.pyplot as plt
import os
import json
import numpy as np
from pyproj import Proj

bag_folder = "/home/hanbaek2004/bag/"
map_file = "/home/hanbaek2004/map/map1.json"

bag_files = [
    ("dual_gps1.bag", "/odom/ekf_dual"),
    ("dual_gps2.bag", "/odom/ekf_dual"),
    ("dual_gps3.bag", "/odom/ekf_dual"),
    ("single_gps1.bag", "/odom/ekf_single"),
    ("single_gps2.bag", "/odom/ekf_single"),
    ("single_gps3.bag", "/odom/ekf_single"),
    ("gps1.bag", "/odom/gps"),
    ("gps2.bag", "/odom/gps"),
    ("gps3.bag", "/odom/gps"),
]


proj_utm = Proj(proj="utm", zone=52, ellps="WGS84", south=False)

with open(map_file, 'r') as f:
    map_data = json.load(f)

map_raw_x = []
map_raw_y = []
for node in map_data["Node"]:
    e = node["UtmInfo"]["Easting"]
    n = node["UtmInfo"]["Northing"]
    map_raw_x.append(e)
    map_raw_y.append(n)

map_raw_points = np.vstack((map_raw_x, map_raw_y)).T


def point_to_segment_distance(px, py, x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1
    if dx == dy == 0:
        return np.hypot(px - x1, py - y1)
    t = ((px - x1) * dx + (py - y1) * dy) / (dx*dx + dy*dy)
    t = np.clip(t, 0, 1)
    nearest_x = x1 + t * dx
    nearest_y = y1 + t * dy
    return np.hypot(px - nearest_x, py - nearest_y)


results = []


plt.figure(figsize=(14, 10))


colors = ['red', 'blue', 'green', 'purple', 'orange', 'cyan', 'magenta', 'brown', 'lime']
markers = ['o', 's', '^', 'D', 'v', '<', '>', 'p', '*']
line_styles = ['-', '--', '-.', ':']


map_plotted = False

for i, (bag_file, topic_name) in enumerate(bag_files):
    full_path = os.path.join(bag_folder, bag_file)
    if not os.path.exists(full_path):
        print(f"파일 {full_path} 존재하지 않음. 스킵.")
        continue

    print(f"Processing {bag_file} ({topic_name})...")

    bag = rosbag.Bag(full_path)

    init_x = init_y = None
    for topic, msg, t in bag.read_messages(topics=["/ublox_f9k/fix"]):
        if not (msg.status.status >= 0):
            continue
        lat = msg.latitude
        lon = msg.longitude
        init_x, init_y = proj_utm(lon, lat)
        print(f"  초기 UTM 기준점 (E, N): {init_x:.2f}, {init_y:.2f}")
        break

    if init_x is None:
        print(f"  -> /ublox_f9k/fix 데이터 없음. 스킵")
        bag.close()
        continue

    x_list = []
    y_list = []
    for topic, msg, t in bag.read_messages(topics=[topic_name]):
        x_list.append(msg.pose.pose.position.x)
        y_list.append(msg.pose.pose.position.y)

    bag.close()

    odom_points = np.vstack((x_list, y_list)).T

    map_x = map_raw_points[:, 0] - init_x
    map_y = map_raw_points[:, 1] - init_y
    map_points = np.vstack((map_x, map_y)).T

    map_segments = list(zip(map_points[:-1], map_points[1:]))

    errors = []
    for (px, py) in odom_points:
        min_dist = float('inf')
        for (p1, p2) in map_segments:
            dist = point_to_segment_distance(px, py, p1[0], p1[1], p2[0], p2[1])
            if dist < min_dist:
                min_dist = dist
        errors.append(min_dist)
    errors = np.array(errors)

    # 주요 통계량 계산
    mean_error = np.mean(errors)
    max_error  = np.max(errors)
    rmse       = np.sqrt(np.mean(errors**2))
    p90_error  = np.percentile(errors, 90)
    variance   = np.var(errors)
    std_error  = np.sqrt(variance)  # 표준편차

    print(f"  -> 평균 오차: {mean_error:.2f} m, 최대 오차: {max_error:.2f} m, "
          f"RMSE: {rmse:.2f} m, 90% 오차: {p90_error:.2f} m, 분산: {variance:.4f}, "
          f"표준편차: {std_error:.2f} m")

    # 결과 리스트에 추가
    results.append((bag_file, mean_error, max_error, rmse, p90_error, variance, std_error))

    # 궤적 플롯
    color_idx      = i % len(colors)
    marker_idx     = i % len(markers)
    line_style_idx = (i // len(colors)) % len(line_styles)
    if "dual_gps" in bag_file:
        label_prefix, zorder = "Dual GPS", 3
    elif "single_gps" in bag_file:
        label_prefix, zorder = "Single GPS", 2
    else:
        label_prefix, zorder = "GPS", 1
    run_number = bag_file[-5]
    label = f"{label_prefix} {run_number}"

    plt.plot(x_list, y_list,
             color=colors[color_idx],
             marker=markers[marker_idx],
             markersize=4,
             markevery=max(1, len(x_list)//30),
             linestyle=line_styles[line_style_idx],
             linewidth=2,
             label=label,
             zorder=zorder)

    if not map_plotted:
        plt.plot(map_x, map_y, 'k-', linewidth=3, label='Map Path', zorder=0)
        map_plotted = True

# 결과 테이블 출력
print("\n==== 전체 결과 ====")
header = f"{'Bag 파일명':<20} {'평균오차(m)':<12} {'최대오차(m)':<12} {'RMSE(m)':<10} {'90%오차(m)':<12} {'분산(m^2)':<12} {'표준편차(m)':<12}"
print(header)
for row in results:
    bag_file, mean_err, max_err, rmse, p90, var, std = row
    print(f"{bag_file:<20} {mean_err:<12.2f} {max_err:<12.2f} {rmse:<10.2f} {p90:<12.2f} {var:<12.4f} {std:<12.2f}")

# 그래프 마무리
plt.xlabel('X position (m)', fontsize=12, fontweight='bold')
plt.ylabel('Y position (m)', fontsize=12, fontweight='bold')
plt.title('Odometry Trajectories Comparison', fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.7)
plt.axis('equal')
plt.legend(loc='center left', bbox_to_anchor=(1, 0.5), frameon=True,
           fancybox=True, shadow=True, fontsize=10)
plt.tight_layout()
plt.show()
