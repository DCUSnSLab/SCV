#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import NavSatFix
import message_filters
import matplotlib.pyplot as plt
import utm
import numpy as np
import time
import statistics

class DualGPSPlot:
    def __init__(self):
        rospy.init_node("dual_gps_plot", anonymous=True)

        # UTM 좌표 저장 변수
        self.f9p_xy = None
        self.f9k_xy = None

        # 거리·시간 로그
        self.distance_log = []
        self.time_log = []

        # ±1.5m → 총 3m ENU 시야
        self.view_range = 1.5

        # 동기화된 subscriber 설정
        f9p_sub = message_filters.Subscriber("/ublox_f9p/fix", NavSatFix)
        f9k_sub = message_filters.Subscriber("/ublox_f9k/fix", NavSatFix)
        sync = message_filters.ApproximateTimeSynchronizer(
            [f9p_sub, f9k_sub],
            queue_size=10,
            slop=0.1  # 허용 시간 차 (초)
        )
        sync.registerCallback(self.synced_callback)

        self.start_time = time.time()
        self.run_plot_loop()

    def synced_callback(self, msg_f9p: NavSatFix, msg_f9k: NavSatFix):
        # 동기화된 두 메시지 처리
        try:
            utm_x1, utm_y1, _, _ = utm.from_latlon(msg_f9p.latitude, msg_f9p.longitude)
            utm_x2, utm_y2, _, _ = utm.from_latlon(msg_f9k.latitude, msg_f9k.longitude)
        except Exception as e:
            rospy.logwarn(f"UTM conversion failed: {e}")
            return

        self.f9p_xy = (utm_x1, utm_y1)
        self.f9k_xy = (utm_x2, utm_y2)

        # 거리 계산 및 로그
        distance = np.hypot(utm_x2 - utm_x1, utm_y2 - utm_y1)
        elapsed = time.time() - self.start_time
        self.distance_log.append(distance)
        self.time_log.append(elapsed)

        rospy.loginfo(f"Synchronized GPS distance: {distance:.3f} m")

    def run_plot_loop(self):
        plt.ion()
        fig, (ax_pos, ax_dist) = plt.subplots(2, 1, figsize=(8, 10))

        try:
            while not rospy.is_shutdown():
                if self.f9p_xy and self.f9k_xy:
                    x1, y1 = self.f9p_xy
                    x2, y2 = self.f9k_xy

                    # 상단: UTM 위치 (ENU 고정)
                    ax_pos.clear()
                    ax_pos.set_title("Dual GPS UTM Visualization")
                    ax_pos.set_xlabel("UTM X (East, meters)")
                    ax_pos.set_ylabel("UTM Y (North, meters)")
                    ax_pos.plot(x1, y1, 'ro', label="F9P (Reference)")
                    ax_pos.plot(x2, y2, 'go', label="F9K")
                    ax_pos.plot([x1, x2], [y1, y2], 'b--', label="Baseline")

                    # ±1.5m 창 고정
                    ax_pos.set_xlim(x1 - self.view_range, x1 + self.view_range)
                    ax_pos.set_ylim(y1 - self.view_range, y1 + self.view_range)
                    ax_pos.set_aspect("equal")
                    ax_pos.legend()
                    ax_pos.grid(True)

                    # 하단: 거리 vs 시간
                    ax_dist.clear()
                    ax_dist.set_title("Distance Between Two GPS Over Time")
                    ax_dist.set_xlabel("Time (s)")
                    ax_dist.set_ylabel("Distance (m)")
                    ax_dist.plot(self.time_log, self.distance_log, 'm-')
                    ax_dist.grid(True)

                    plt.pause(0.1)
        finally:
            plt.ioff()
            plt.show()
            self.print_stats()

    def print_stats(self):
        if len(self.distance_log) < 2:
            print("Not enough data for statistics.")
            return

        max_d = max(self.distance_log)
        min_d = min(self.distance_log)
        mean_d = statistics.mean(self.distance_log)
        std_d = statistics.stdev(self.distance_log)
        max_err_rate = ((max_d - min_d) / mean_d) * 100 if mean_d != 0 else 0

        print("\n====== GPS Distance Statistics ======")
        print(f"Max Distance:     {max_d:.4f} m")
        print(f"Min Distance:     {min_d:.4f} m")
        print(f"Mean Distance:    {mean_d:.4f} m")
        print(f"Std Deviation:    {std_d:.4f} m")
        print(f"Max Error Rate:   {max_err_rate:.2f}%")
        print("=====================================")


if __name__ == "__main__":
    try:
        DualGPSPlot()
    except rospy.ROSInterruptException:
        pass
