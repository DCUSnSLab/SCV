#!/usr/bin/env python3
import os
import time
import psutil
import pynvml
import rospy
from std_msgs.msg import Float32MultiArray


class SystemStatusMonitor:
    def __init__(self):
        rospy.init_node("total_resource", anonymous=True)
        self.rate = rospy.Rate(1)  # 1Hz
        self.publisher = rospy.Publisher("/total_resource", Float32MultiArray, queue_size=100)

        # GPU 초기화
        self.gpu_initialized = False
        try:
            pynvml.nvmlInit()
            self.gpu_handle = pynvml.nvmlDeviceGetHandleByIndex(0)
            gpu_name = pynvml.nvmlDeviceGetName(self.gpu_handle)
            self.gpu_initialized = True
            rospy.loginfo(f"NVML initialized GPU: {gpu_name}")
        except pynvml.NVMLError as e:
            rospy.logwarn(f"GPU initialization failed: {e}")

        # CPU 사용량 계산을 위한 초기값
        self.prev_cpu_times = psutil.cpu_times()

    def run(self):
        while not rospy.is_shutdown():
            msg = Float32MultiArray()

            cpu_info = self.get_cpu_info()
            mem_info = self.get_memory_usage()
            gpu_info = self.get_gpu_info()

            msg.data.extend(cpu_info)
            msg.data.extend(mem_info)
            msg.data.extend(gpu_info)

            self.publisher.publish(msg)

            # 로그 출력 (원본 데이터 그대로)
            rospy.loginfo(f"CPU: {cpu_info}")
            rospy.loginfo(f"Mem: {mem_info}")
            if self.gpu_initialized:
                rospy.loginfo(f"GPU: {gpu_info}")

            self.rate.sleep()

    def get_cpu_info(self):
        """ CPU 사용량, 로드 평균, 온도 가져오기 """
        cpu_times = psutil.cpu_times()
        total_time = sum(cpu_times)
        idle_time = cpu_times.idle

        # CPU 사용량 계산
        total_diff = total_time - sum(self.prev_cpu_times)
        idle_diff = idle_time - self.prev_cpu_times.idle
        cpu_usage_percent = (total_diff - idle_diff) / total_diff * 100 if total_diff else 0

        self.prev_cpu_times = cpu_times

        # CPU 로드 평균 (1, 5, 15분)
        load_avg = os.getloadavg()

        # CPU 온도 가져오기
        try:
            temp = psutil.sensors_temperatures().get("coretemp", [])[0].current
        except (AttributeError, IndexError):
            temp = -1.0  # 온도를 가져올 수 없는 경우

        return [
            cpu_times.user, cpu_times.nice, cpu_times.system, cpu_times.idle,
            cpu_times.iowait, cpu_times.irq, cpu_times.softirq, cpu_times.steal,
            cpu_times.guest, cpu_times.guest_nice,
            cpu_usage_percent,  # round() 제거
            temp,
            load_avg[0], load_avg[1], load_avg[2]
        ]

    def get_memory_usage(self):
        """ 메모리 사용량 가져오기 """
        mem = psutil.virtual_memory()
        mem_used = (mem.total - mem.available) / (1024 * 1024)
        mem_total = mem.total / (1024 * 1024)
        mem_usage_percent = mem_used / mem_total * 100
        return [mem_used, mem_total, mem_usage_percent]  # round() 제거

    def get_gpu_info(self):
        """ GPU 사용량, 메모리 사용량, 온도 가져오기 """
        if not self.gpu_initialized:
            return [-1, -1, -1, -1, -1]

        try:
            utilization = pynvml.nvmlDeviceGetUtilizationRates(self.gpu_handle)
            memory = pynvml.nvmlDeviceGetMemoryInfo(self.gpu_handle)
            temperature = pynvml.nvmlDeviceGetTemperature(self.gpu_handle, pynvml.NVML_TEMPERATURE_GPU)

            gpu_usage_percent = utilization.gpu
            gpu_mem_used = memory.used / (1024 * 1024)  # Bytes → MB
            gpu_mem_total = memory.total / (1024 * 1024)  # Bytes → MB
            gpu_mem_usage = (gpu_mem_used / gpu_mem_total) * 100
            gpu_temp = temperature

            return [gpu_usage_percent, gpu_mem_used, gpu_mem_total, gpu_mem_usage, gpu_temp]  # round() 제거
        except pynvml.NVMLError as e:
            rospy.logwarn(f"Failed to fetch GPU info: {e}")
            return [-1, -1, -1, -1, -1]


if __name__ == "__main__":
    monitor = SystemStatusMonitor()

    try:
        monitor.run()
    except rospy.ROSInterruptException:
        pass
