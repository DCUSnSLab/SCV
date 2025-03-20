#!/usr/bin/python3
# -*- coding: utf-8 -*-
import functools
import os
import subprocess
import json

import rosnode
import rospy

import psutil
import pynvml

try:
  from xmlrpc.client import ServerProxy
except ImportError:
  from xmlrpclib import ServerProxy

from std_msgs.msg import String


def ns_join(*names):
    return functools.reduce(rospy.names.ns_join, names, "")

class NodeManager:
    def __init__(self, name, pid):
        self.name = name
        self.proc = psutil.Process(pid)

    def get_metrics(self):
        # self.cpu = self.proc.cpu_percent()
        # self.mem = self.proc.memory_info().rss
        
        # usage = {
        #     'node': self.name,
        #     'cpu': self.cpu,
        #     'mem': self.mem
        # }
        # usage = {key: value for key, value in zip(['cpu', 'mem'], [self.cpu, self.mem])}

        #return [self.name, self.cpu, self.mem]
        
        data = {
            'node': self.name,
            'cpu': self.proc.cpu_percent(),
            'mem': self.proc.memory_info().rss
        }
        
        
        print(data)
        return data

    def alive(self):
        return self.proc.is_running()

class GpuNodeManager:
    def __init__(self,):
        try:
            pynvml.nvmlInit()
        except pynvml.NVMLError as e:
            rospy.logerr("NVML initialization failed: {}".format(e))
        
        
def main():
    rospy.init_node('nodes_resource', anonymous=False)
    master = rospy.get_master()
    rate = rospy.Rate(1)

    poll_period = rospy.get_param('~poll_period', 1.0)
    #source_list = rospy.get_param('~source_list', [])
    node_map = {}
    
    nodes_resource_pub = rospy.Publisher('/nodes_resource', String, queue_size=100)
    
    #this_ip = os.environ.get("ROS_IP")
    #ignored_nodes = set()

    #node_manager = NodeManager()
    #cpu_NodeManager = rospy.Publisher("~total_cpu", Float32, queue_size=20)
    
    # mem_topics = ["available", "used", "free", "active", "inactive", "buffers", "cached", "shared", "slab"]

    # vm = psutil.virtual_memory()
    
    # tmp = []
    # for topic in mem_topics:
    #     if topic in dir(vm):
    #         tmp.append(topic)
    # mem_topics = tmp
    
    #mem_NodeManagerers = []
    #for mem_topic in mem_topics:
        #mem_NodeManagerers.append(rospy.Publisher("~total_%s_mem" % mem_topic, UInt64, queue_size=20))

    while not rospy.is_shutdown():
        
        valid_nodes = [
            node 
            for node in rosnode.get_node_names()
            if node not in node_map #and node_manager.monitored(node)
        ]

        for node in valid_nodes: #ros 마스터에 있는 모든 노드 순회
            # if node in node_map or node in ignored_nodes:
            #     continue

            # if not node_manager.monitored(node):
            #     continue
            
            try:
                    
                node_api = rosnode.get_api_uri(master, node, skip_cache=True)[2]

                if not node_api:
                    rospy.logerr("[monitor] failed to get api of node %s (%s)" % (node, node_api))
                    continue

                # ros_ip = node_api[7:] # strip http://
                # ros_ip = ros_ip.split(':')[0] # strip :<port>/
                # local_node = "localhost" in node_api or \
                #       "127.0.0.1" in node_api or \
                #       (this_ip is not None and this_ip == ros_ip) or \
                #       subprocess.check_output("hostname").decode('utf-8').strip() in node_api
                
                # if not local_node:
                #     ignored_nodes.add(node)
                #     rospy.loginfo("[monitor] ignoring node %s with URI %s" % (node, node_api))
                #     continue
                
                try:
                    resp = ServerProxy(node_api).getPid('/NODEINFO')
                except:
                    rospy.logerr("[monitor] failed to get pid of node %s (api is %s)" % (node, node_api))
                else:
                    try:
                        pid = resp[2]
                    except:
                        rospy.logerr("[monitor] failed to get pid for node %s from NODEINFO response: %s" % (node, resp))
                    else:
                        try:
                            node_map[node] = NodeManager(name=node, pid=pid)

                        except psutil.NoSuchProcess:
                            rospy.logwarn("[monitor] psutil can't see %s (pid = %d). Ignoring" % (node, pid))
                        else:
                            rospy.loginfo("[monitor] adding new node %s" % node)
                        
            except (IndexError, psutil.NoSuchProcess):
                rospy.logwarn(f"[monitor] Failed to get PID for node {node}")
                
            except Exception as e:
                rospy.logerr(f"[monitor] Unexpected error for node {node}: {e}")
                
        # nodes_data = [
        #     node.get_metrics()
        #     for node in node_map.values()
        #     if node.alive()
        # ]
        nodes_data = [
            node_manager.get_metrics()
            for node_manager in sorted(node_map.values(), key=lambda nm: nm.name)
            if node_manager.alive()
        ]

        node_map = {node_name: node_manager for node_name, node_manager in node_map.items() if node_manager.alive()} #node update
        
        # for node_name, node in list(node_map.items()):
        #     if node.alive():
        #         metrics = node.get_metrics()

        #         nodes_data.append({'node': metrics[0], 'cpu': metrics[1], 'mem': metrics[2]})
                
        #     else:
        #         rospy.logwarn("[monitor] lost node %s" % node_name)
        #         del node_map[node_name]

        nodes_resource_pub.publish(json.dumps(nodes_data))
        
        rospy.sleep(poll_period)

    rospy.loginfo("[monitor] shutting down")


if __name__ == "__main__":
    main()