#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <nvml.h>
#include <sys/sysinfo.h>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <sstream>
#include <typeinfo>

class SystemStatusMonitor {
public:
    SystemStatusMonitor() : rate(1.0), gpu_initialized(false), KernalHZ(getKernelHZ()) {
        total_resource_pub = nh.advertise<std_msgs::Float32MultiArray>("/total_resource", 100);

        // Initialize NVML for GPU monitoring
        nvmlReturn_t result = nvmlInit();

        if (result == NVML_SUCCESS) {

            nvmlDeviceGetHandleByIndex(0, &gpu_handle); //get handle

            char gpu_name[NVML_DEVICE_NAME_BUFFER_SIZE];
            nvmlDeviceGetName(gpu_handle, gpu_name, NVML_DEVICE_NAME_BUFFER_SIZE);

            gpu_initialized = true;
            ROS_INFO("NVML initialized GPU: %s", gpu_name);

        } 
        else {
            ROS_WARN("GPU initialization failed: %s", nvmlErrorString(result));
        }

        ROS_INFO("Kernal HZ value detected: %d", KernalHZ);
    }

    ~SystemStatusMonitor() {
        if (gpu_initialized) {
            nvmlShutdown();
            ROS_INFO("GPU resources released.");
        }
    }

    void run() {
        //when node is running
        while (ros::ok()) {
            std_msgs::Float32MultiArray msg;

            //get values
            std::vector<float> cpu_info = getCpuInfo();
            // user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice   0 ~ 9
            // + cpu_usage_percent + cpu_temp   10 ~ 11
            // + load_1min + load_5min + load_15min   12 ~ 14
            std::vector<float> mem_info = getMemoryUsage(); 
            std::vector<float> gpu_info = getGpuInfo();

            msg.data.clear();

            msg.data.insert(msg.data.end(), cpu_info.begin(), cpu_info.end());
            msg.data.insert(msg.data.end(), mem_info.begin(), mem_info.end());
            msg.data.insert(msg.data.end(), gpu_info.begin(), gpu_info.end());
        
            total_resource_pub.publish(msg);

            // for (size_t i = 0; i < cpu_info.size(); i++) {
            //     ROS_INFO("cpu_info[%ld] = %f (type: %s)", i, (double)cpu_info[i], typeid(cpu_info[i]).name());
            // }


            ROS_INFO("CPU: user %.2f,  nice %.2f, system %.2f, idle, %.2f, iowait %.2f, irq %.2f, softirq %.2f, steal %.2f, guest %.2f, guest_nice %.2f",
                    cpu_info[0], cpu_info[1], cpu_info[2], cpu_info[3], cpu_info[4], cpu_info[5], cpu_info[6], cpu_info[7], cpu_info[8], cpu_info[9]);
            ROS_INFO("CPU: Usage %.2f%%, Temp %.2fC",cpu_info[10], cpu_info[11]);
            ROS_INFO("Mem: %.2f/%.2f MB (%.2f%%)", mem_info[0], mem_info[1], mem_info[2]);
            if (gpu_initialized) {
                ROS_INFO("GPU Usage: %.2f%%, Mem: %.2f/%.2f MB (%.2f%%), Temp: %.2fC",
                         gpu_info[0], gpu_info[1], gpu_info[2], gpu_info[3], gpu_info[4]);
            }

            rate.sleep();
        }
    }

private:
    ros::NodeHandle nh;
    ros::Publisher total_resource_pub;
    ros::Rate rate;

    nvmlDevice_t gpu_handle;
    bool gpu_initialized;

    const int KernalHZ;
    
    long prev_total_cpu_time = 0;
    long prev_total_idle_time = 0;

    int getKernelHZ() {
        FILE* pipe = popen("cat /boot/config-$(uname -r) | grep CONFIG_HZ= | cut -d '=' -f2", "r");
        if (!pipe) {
            ROS_WARN("Failed fetch Kernel HZ value");
            return 100;
        }

        char buffer[128];
        std::string result = "";

        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
        pclose(pipe);

        try {
            return std::stoi(result);
        } catch (...) {
            ROS_WARN("Invalid Kernel HZ value. Using default 100.");
            return 100;
        }
    }

    std::vector<float> getCpuInfo() {
        static std::ifstream cpu_stat_f("/proc/stat"); //리눅스 제공 가상 파일
        cpu_stat_f.clear();
        cpu_stat_f.seekg(0, std::ios::beg);

        std::string line;
        std::getline(cpu_stat_f, line);

        std::istringstream iss(line);
        std::string cpu_label;
        iss >> cpu_label;


        std::vector<long> cpu_times;
        long value;
        while (iss >> value) {
            //all values are in units of *jiffies*
            //user, system, nice, idle, iowait, irq, softirq, zero
            cpu_times.push_back(value);
        }
        

        //total_cpu_time (user + system + nice + idle + iowait + irq + softirq + steal)
        long total_cpu_time = std::accumulate(cpu_times.begin(), cpu_times.end(), 0L);

        //idle time (idle + iowait)
        long total_idle_time = cpu_times[3] + cpu_times[4]; // idle + iowait

        //convert jiffies to sec
        std::vector<float> cpu_info;
        for (const auto& val : cpu_times) {
            //sec = jiffies / hz
            cpu_info.push_back(static_cast<float>(val)/KernalHZ);
        }
        
        float cpu_usage_percent;
        //fst run
        static long prev_total_cpu_time = 0;
        static long prev_total_idle_time = 0;
        static bool first_run = true; //flag
        
        if (first_run) {
            cpu_usage_percent = -1.0;
            prev_total_cpu_time = total_cpu_time;
            prev_total_idle_time = total_idle_time;
            first_run = false;
        }

        long total_diff = total_cpu_time - prev_total_cpu_time;
        long idle_diff = total_idle_time - prev_total_idle_time;

        cpu_usage_percent = (total_diff - idle_diff) * 100.0 / total_diff;

        prev_total_cpu_time = total_cpu_time;
        prev_total_idle_time = total_idle_time;


        // get cpu loadavg
        std::ifstream loadavg_f("/proc/loadavg");
        float load_1min = -1.0;
        float load_5min = -1.0;
        float load_15min = -1.0;

        if (loadavg_f.is_open()) {
            std::getline(loadavg_f, line);
            std::istringstream ss(line);
            std::string load_1min_str, load_5min_str, load_15min_str;
            ss >> load_1min_str >> load_5min_str >> load_15min_str;
            loadavg_f.close();

            // printf("Load Average (1min): %s\n", load_1min_str.c_str());
            // printf("Load Average (5min): %s\n", load_5min_str.c_str());
            // printf("Load Average (15min): %s\n", load_15min_str.c_str());
            //convert to string to float
            load_1min = std::stof(load_1min_str);
            load_5min = std::stof(load_5min_str);
            load_15min = std::stof(load_15min_str);
        }
        
        //get cpu temp
        std::ifstream temp_f("/sys/class/thermal/thermal_zone0/temp");
        float cpu_temp = -1.0;
        if (temp_f >> cpu_temp) {
            cpu_temp /= 1000.0; //단위가 milli degree이므로 변환 필요
        }

        cpu_info.push_back(cpu_usage_percent);
        cpu_info.push_back(cpu_temp);
        cpu_info.push_back(load_1min);
        cpu_info.push_back(load_5min);
        cpu_info.push_back(load_15min);

        return cpu_info;
    }

    std::vector<float> getMemoryUsage() {
        struct sysinfo info;
        sysinfo(&info);

        float mem_used = (info.totalram - info.freeram) / (1024.0 * 1024.0);
        float mem_total = info.totalram / (1024.0 * 1024.0);
        float mem_usage_percent = (mem_used / mem_total) * 100.0;

        return {mem_used, mem_total, mem_usage_percent};
    }
    
    std::vector<float> getGpuInfo() {
        if (!gpu_initialized) {
            return {-1, -1, -1, -1, -1};
        }

        nvmlUtilization_t utilization;
        nvmlMemory_t memory;
        unsigned int temperature;

        nvmlDeviceGetUtilizationRates(gpu_handle, &utilization);
        nvmlDeviceGetMemoryInfo(gpu_handle, &memory);
        nvmlDeviceGetTemperature(gpu_handle, NVML_TEMPERATURE_GPU, &temperature);

        float gpu_usage_percent = utilization.gpu;
        float gpu_mem_used = memory.used / (1024.0 * 1024.0); // bytes -> mb
        float gpu_mem_total = memory.total / (1024.0 * 1024.0); // bytes -> mb
        float gpu_mem_usage = (gpu_mem_used / gpu_mem_total) * 100.0;
        float gpu_temp = temperature;

        return {gpu_usage_percent, gpu_mem_used, gpu_mem_total, gpu_mem_usage, gpu_temp};
    }
};

int main(int argc, char** argv) {
    ros::init(argc, argv, "total_resource");

    SystemStatusMonitor monitor;

    try {
        monitor.run();
    } catch (const ros::Exception& e) {
        ROS_ERROR("ROS Exception: %s", e.what());
    }

    return 0;
}
