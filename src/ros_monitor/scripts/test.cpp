#include <ros/ros.h>
#include <ros/master.h>
#include <ros/network.h>
#include <std_msgs/String.h>
#include <nvml.h>
#include <sstream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <dirent.h>
#include <xmlrpcpp/XmlRpcValue.h>
#include <xmlrpcpp/XmlRpcClient.h>

std::string getProcessName(unsigned int pid) {
    std::ifstream commFile("/proc/" + std::to_string(pid) + "/comm");
    std::string name;
    if (commFile.good() && std::getline(commFile, name))
        return name;
    return "Unknown";
}

unsigned int findRosNodePid(const std::string &node_name) {
    DIR* dir = opendir("/proc");
    if (!dir) return 0;

    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            std::string pidStr(entry->d_name);
            if (std::all_of(pidStr.begin(), pidStr.end(), ::isdigit)) {
                unsigned int pid = std::stoi(pidStr);
                std::ifstream cmdFile("/proc/" + pidStr + "/cmdline");
                std::string cmdLine;
                if (cmdFile.good() && std::getline(cmdFile, cmdLine)) {
                    if (cmdLine.find(node_name) != std::string::npos) {
                        closedir(dir);
                        return pid;
                    }
                }
            }
        }
    }

    closedir(dir);
    return 0;
}

// **ROS 마스터에서 노드의 PID를 가져오는 함수**
unsigned int getNodePid(const std::string &node_name) {
    std::string node_uri;
    XmlRpc::XmlRpcValue args, result, payload;

    args.clear();
    args[0] = ros::this_node::getName();
    args[1] = node_name;

    // **1. lookupNode 실행**
    if (!ros::master::execute("lookupNode", args, result, payload, true)) {
        ROS_WARN("Failed to lookup node URI for %s, trying /proc scan", node_name.c_str());
        return findRosNodePid(node_name);  // **lookupNode 실패 시 /proc 검색**
    }

    node_uri = static_cast<std::string>(result[2]);

    std::string host;
    uint32_t port;

    // **2. URI 파싱**
    if (!ros::network::splitURI(node_uri, host, port)) {
        ROS_WARN("Failed to split URI %s for node %s", node_uri.c_str(), node_name.c_str());
        return findRosNodePid(node_name);
    }

    // **3. XMLRPC 요청하여 getPid 실행**
    XmlRpc::XmlRpcClient client(host.c_str(), port, "/");
    args.clear();
    args[0] = ros::this_node::getName();
    if (!client.execute("getPid", args, result))
    {
        ROS_WARN("Failed to call getPid on node %s, trying /proc scan", node_name.c_str());
        return findRosNodePid(node_name);
    }

    // **4. 결과 변환**
    if (result[2].getType() == XmlRpc::XmlRpcValue::TypeInt) {
        return static_cast<unsigned int>(static_cast<int>(result[2]));
    }

    ROS_WARN("Invalid getPid response type from node %s, trying /proc scan", node_name.c_str());
    return findRosNodePid(node_name);
}

// **NVML을 사용하여 실행 중인 프로세스 목록을 가져오는 함수**
std::string formatProcessInfo(nvmlDevice_t device, bool compute, const std::set<unsigned int>& nodePIDs)
{
    std::stringstream ss;
    const char* processType = compute ? "Compute" : "Graphics";

    unsigned int count = 64;
    nvmlProcessInfo_t infos[64];
    nvmlReturn_t result = compute ? 
        nvmlDeviceGetComputeRunningProcesses(device, &count, infos) :
        nvmlDeviceGetGraphicsRunningProcesses(device, &count, infos);
    
    bool found = false;
    if (result == NVML_SUCCESS && count > 0)
    {
        for (unsigned int j = 0; j < count; j++)
        {
            unsigned int pid = infos[j].pid;
            if (nodePIDs.find(pid) == nodePIDs.end())
                continue;

            if (!found) {
                ss << "  Running " << processType << " Processes:\n";
                ss << "    " << std::setw(6) << "PID" 
                   << "    " << std::setw(6) << "Mem(MiB)" 
                   << "    " << "Process Name\n";
                found = true;
            }
            unsigned long long usedMem = infos[j].usedGpuMemory;
            ss << "    " << std::setw(6) << pid 
               << "    " << std::setw(6) << (usedMem / (1024 * 1024)) 
               << "    " << getProcessName(pid) << "\n";
        }
    }
    if (!found)
    {
        ss << "  No running " << processType << " processes.\n";
    }
    return ss.str();
}

// **메인 함수**
int main(int argc, char** argv)
{
    ros::init(argc, argv, "gpu_monitor_node");
    ros::NodeHandle nh;
    ros::Publisher gpu_pub = nh.advertise<std_msgs::String>("gpu_usage", 10);
    ros::Rate loop_rate(1);

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

    std::vector<nvmlDevice_t> devices(deviceCount);
    for (unsigned int i = 0; i < deviceCount; i++)
    {
        if (nvmlDeviceGetHandleByIndex_v2(i, &devices[i]) != NVML_SUCCESS)
            ROS_ERROR("GPU %u 핸들 가져오기 실패", i);
    }

    while (ros::ok())
    {
        std::vector<std::string> nodeNames;
        ros::master::getNodes(nodeNames);
        std::set<unsigned int> nodePIDs;

        for (const std::string &node : nodeNames)
        {
            unsigned int pid = getNodePid(node);
            if (pid != 0)
                nodePIDs.insert(pid);
        }

        std_msgs::String msg;
        std::stringstream ss;

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
            
            ss << formatProcessInfo(devices[i], true, nodePIDs);
            ss << formatProcessInfo(devices[i], false, nodePIDs);
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
