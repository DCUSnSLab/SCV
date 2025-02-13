import pynvml
import time

def monitor_gpu():
    try:
        # 첫 번째 GPU 핸들 가져오기
        handle = pynvml.nvmlDeviceGetHandleByIndex(0)
        name = pynvml.nvmlDeviceGetName(handle)  # GPU 이름

        # 전체 사용률 (GPU Utilization)
        utilization = pynvml.nvmlDeviceGetUtilizationRates(handle)
        gpu_utilization = utilization.gpu  # GPU 전체 사용률 (%)

        # 메모리 사용량
        mem_info = pynvml.nvmlDeviceGetMemoryInfo(handle)
        total_mem = mem_info.total / 1024**2  # MB
        used_mem = mem_info.used / 1024**2  # MB
        free_mem = mem_info.free / 1024**2  # MB
        mem_usage = (used_mem / total_mem) * 100  # 메모리 사용률 (%)

        # 출력
        print(f"\nMonitoring GPU: {name}")
        print(f"GPU Utilization: {gpu_utilization}%")
        print(f"Memory Usage: Used: {used_mem:.2f} MB / Total: {total_mem:.2f} MB ({mem_usage:.2f}%)")

    except pynvml.NVMLError as e:
        print(f"Error monitoring GPU: {e}")

if __name__ == "__main__":
    try:
        pynvml.nvmlInit()  # NVML 초기화
        print("NVML Initialized")
        while True:
            monitor_gpu()
            time.sleep(5)  # 5초 간격으로 모니터링
    except pynvml.NVMLError_Uninitialized:
        print("Failed to initialize NVML. Ensure the NVIDIA driver is installed and loaded.")
    except Exception as e:
        print(f"Unexpected error: {e}")
    finally:
        pynvml.nvmlShutdown()  # NVML 종료
