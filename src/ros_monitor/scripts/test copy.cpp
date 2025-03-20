#include <ros/ros.h>
#include <std_msgs/String.h>
#include <nvml.h>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

// PID에 해당하는 프로세스 이름을 반환 (/proc/[pid]/comm 이용)
std::string getProcessName(unsigned int pid)
{
    std::ifstream commFile("/proc/" + std::to_string(pid) + "/comm");
    std::string name;
    if (commFile.good() && std::getline(commFile, name))
        return name;
    return "Unknown";
}

// Compute 또는 Graphics 프로세스 정보를 출력하는 함수
std::string formatProcessInfo(nvmlDevice_t device, bool compute)
{
    std::stringstream ss;
    const char* processType;
    if (compute)
    {
        processType = "Compute";
    }
    else
    {
        processType = "Graphics";
    }

    unsigned int count = 64;
    nvmlProcessInfo_t infos[64];
    nvmlReturn_t result;
    if (compute)
    {
        result = nvmlDeviceGetComputeRunningProcesses(device, &count, infos);
    }
    else
    {
        result = nvmlDeviceGetGraphicsRunningProcesses(device, &count, infos);
    }
    
    if (result == NVML_SUCCESS && count > 0)
    {
        ss << "  Running " << processType << " Processes:\n";
        ss << "    " << std::setw(6) << "PID" 
           << "    " << std::setw(6) << "Mem(MiB)" 
           << "    " << "Process Name\n";
        for (unsigned int j = 0; j < count; j++)
        {
            unsigned int pid = infos[j].pid;
            unsigned long long usedMem = infos[j].usedGpuMemory;
            ss << "    " << std::setw(6) << pid 
               << "    " << std::setw(6) << (usedMem / (1024 * 1024)) 
               << "    " << getProcessName(pid) << "\n";
        }
    }
    else
    {
        ss << "  No running " << processType << " processes.\n";
    }
    return ss.str();
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "gpu_monitor_node");
    ros::NodeHandle nh;
    ros::Publisher gpu_pub = nh.advertise<std_msgs::String>("gpu_usage", 10);
    ros::Rate loop_rate(1); // 1Hz 업데이트

    if (nvmlInit_v2() != NVML_SUCCESS)
    {
        ROS_ERROR("NVML 초기화 실패");
        return 1;
    }

    unsigned int deviceCount = 0;
    if (nvmlDeviceGetCount_v2(&deviceCount) != NVML_SUCCESS)
    {
        ROS_ERROR("GPU 개수 가져오기 실패");
        nvmlShutdown();
        return 1;
    }

    // std::vector를 사용하여 GPU 핸들을 관리
    std::vector<nvmlDevice_t> devices(deviceCount);
    for (unsigned int i = 0; i < deviceCount; i++)
    {
        if (nvmlDeviceGetHandleByIndex_v2(i, &devices[i]) != NVML_SUCCESS)
            ROS_ERROR("GPU %u 핸들 가져오기 실패", i);
    }

    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        //ss << "Detected " << deviceCount << " GPU(s).\n";

        for (unsigned int i = 0; i < deviceCount; i++)
        {
            char name[64];
            if (nvmlDeviceGetName(devices[i], name, sizeof(name)) != NVML_SUCCESS)
                snprintf(name, sizeof(name), "Unknown");

            nvmlUtilization_t util;
            if (nvmlDeviceGetUtilizationRates(devices[i], &util) != NVML_SUCCESS)
            {
                ss << "GPU " << i << " (" << name << "): 사용률 가져오기 실패\n";
                continue;
            }

            ss << "GPU " << i << " (" << name << "):\n"
               << "  Core Utilization: " << util.gpu << "%\n"
               << "  Memory Utilization: " << util.memory << "%\n";
            
            // Compute 및 Graphics 프로세스 정보 출력
            ss << formatProcessInfo(devices[i], true);
            ss << formatProcessInfo(devices[i], false);
            ss << "\n";
        }

        msg.data = ss.str();
        gpu_pub.publish(msg);
        ROS_INFO_STREAM(msg.data);

        ros::spinOnce();
        loop_rate.sleep();
    }

    nvmlShutdown();
    return 0;
}
