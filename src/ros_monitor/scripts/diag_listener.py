#!/usr/bin/python3
# -*- coding: utf-8 -*-

import os
import json

import rospy
from std_msgs.msg import Float32MultiArray, String
from typing import List, Dict, Any, Union

import psutil


class JSONManager:
    def __init__(self):
        self.data = {
            'total_resource': {
                'cpu_user' : None,
                'cpu_nice' : None,
                'cpu_system' : None,
                'cpu_idle' : None,
                'cpu_iowait' : None,
                'cpu_irq' : None,
                'cpu_softirq' : None,
                'cpu_steal' : None,
                'cpu_guest' : None,
                'cpu_guest_nice' : None,
                'cpu_usage_percent' : None,
                'cpu_temp' : None,
                'cpu_load_1min' : None,
                'cpu_load_5min' : None,
                'cpu_load_15min' : None,
                
                'mem_used' : None,
                'mem_total' : None,
                'mem_usage_percent' : None,
                
                'gpu_usage_percent' : None,
                'gpu_mem_used' : None,
                'gpu_mem_total' : None,
                'gpu_mem_usage' : None,
                'gpu_temp' : None,
            },
            
            'topics_hzbw': {},
            'node_resource_usage': {},
            'gpu_pmon': {},
        }
        
        self.file_path = os.path.join(os.path.dirname(__file__), "../data/diag.json")
        
        #check directory
        # directory = os.path.dirname(self.file_path)
        # if not os.path.exists(directory):
        #     os.makedirs(directory)
        os.makedirs(os.path.dirname(self.file_path), exist_ok=True)
        
        #open json file
        if os.path.exists(self.file_path):
            try:
                with open(self.file_path, 'r') as file:
                    content = file.read().strip()
                    if content:
                        self.data = json.loads(content)
                    else:
                        rospy.logwarn('json file is empty.')
            except json.JSONDecodeError as e:
                rospy.logwarn(f'failed to decode json file: {e}')
        else:
            rospy.logwarn('json file not found.')


    def save_to_file(self, event=None):
        '''save json data to file'''
        try:
            with open(self.file_path, 'w') as file:
                json.dump(self.data, file, indent=4)
        except Exception as e:
            rospy.logwarn(f'Failed to save JSON file: {e}')


    def update_total_resource(self, key, value):
        self.data['total_resource'][key] = value

    def update_topic_hzbw(self, topic_name, hz, bw):
        if 'topics_hzbw' not in self.data:
            self.data['topics_hzbw'] = {}
        self.data['topics_hzbw'][topic_name] = {'hz': hz, 'bw': bw}

    def update_node_resource(self, node_name, cpu, mem):
        if 'node_resource_usage' not in self.data:
            self.data['node_resource_usage'] = {}
        self.data['node_resource_usage'][node_name] = {'cpu': cpu, 'mem': mem}


logical_cores = psutil.cpu_count(logical=True)
manager = JSONManager()

def convert_bytes(v):
    if v < 1 << 10:
        result = f"{v:.2f} B/s"
    elif v < 1 << 20:
        result = f"{v / (1 << 10):.2f} KB/s"
    elif v < 1 << 30:
        result = f"{v / (1 << 20):.2f} MB/s"
    else:
        result = f"{v / (1 << 30):.2f} GB/s"
    
    return result
            
    
def total_resource_callback(total_resource_sub):
    keys = [
        'cpu_user', 'cpu_nice', 'cpu_system', 'cpu_idle', 'cpu_iowait',
        'cpu_irq', 'cpu_softirq', 'cpu_steal', 'cpu_guest', 'cpu_guest_nice',
        'cpu_usage_percent', 'cpu_temp', 'cpu_load_1min', 'cpu_load_5min', 'cpu_load_15min',
        'mem_used', 'mem_total', 'mem_usage_percent',
        'gpu_usage_percent', 'gpu_mem_used', 'gpu_mem_total', 'gpu_mem_usage', 'gpu_temp'
    ]

    try:
        data = total_resource_sub.data

        for i, key in enumerate(keys):
            manager.update_total_resource(key, data[i])
            
    except IndexError:
        rospy.logwarn('Invalid total_resource data')

def topics_hzbw_callback(topics_hzbw_sub):
    try:
        data = json.loads(topics_hzbw_sub.data)
        
        '''
        topic['topic'] : str
        topic['hz'] : float
        topic['bw'] : float
        '''
        current_topics = {topic['topic']: {'hz': topic['hz'], 'bw': convert_bytes(v=topic['bw'])} for topic in data if 'topic' in topic}
        
                
        manager.data['topics_hzbw'] = current_topics

        # for topic in data:
        #     #print(topic)
        #     manager.update_topic_hzbw(
        #         topic_name=topic.get('topic'),
        #         hz=topic.get('hz'),
        #         bw=topic.get('bw'),
        #     )
            
    except json.JSONDecodeError as e:
        rospy.logwarn(f'failed to parse topics_hzbw json: {e}')

def nodes_resource_callback(nodes_resource_sub):
    try:
        data = json.loads(nodes_resource_sub.data)
        #print(type(data))
        '''
        node['node'] : str
        node['cpu'] : float
        node['mem'] : str
        '''
        
        current_nodes = {node['node']: {'cpu': round(node['cpu']/logical_cores, 3), 'mem': convert_bytes(v=node['mem'])} for node in data if 'node' in node}
        
        manager.data['node_resource_usage'] = current_nodes

        # for node in data:
        #     manager.update_node_resource(
        #         node_name=node.get('node'),
        #         cpu=node.get('cpu'),
        #         mem=node.get('mem'),
        #     )
            
    except json.JSONDecodeError as e:
        rospy.logwarn(f'failed to parse nodes_resource json: {e}')

def gpu_pmon_callback(gpu_pmon_sub):
    try:
        data = json.loads(gpu_pmon_sub.data)
        '''
        10 colum or 8 colum
        '''
        parsed_data_list = {}
        
        for parsed_data in data:
            key = parsed_data['pid']
            
            if len(parsed_data) >= 10:
                parsed_data_list[parsed_data['pid']] = {
                    'gpu_idx': parsed_data['gpu_idx'],
                    'type': parsed_data['type'],
                    'sm_usage': parsed_data['sm_usage'],
                    'mem_usage': parsed_data['mem_usage'],
                    'enc_usage': parsed_data['enc_usage'],
                    'dec_usage': parsed_data['dec_usage'],
                    'jpg_usage': parsed_data['jpg_usage'],
                    'ofa_usage': parsed_data['ofa_usage'],
                    'command': parsed_data['command'],
                }
                
            elif len(parsed_data) >= 8:
                parsed_data_list[parsed_data['pid']] = {
                    'gpu_idx': parsed_data['gpu_idx'],
                    'type': parsed_data['type'],
                    'sm_usage': parsed_data['sm_usage'],
                    'mem_usage': parsed_data['mem_usage'],
                    'enc_usage': parsed_data['enc_usage'],
                    'dec_usage': parsed_data['dec_usage'],
                    'command': parsed_data['command'],
                }
        
        manager.data['gpu_pmon'] = parsed_data_list

    except json.JSONDecodeError as e:
        rospy.logwarn(f'failed to parse gpu_pmon json: {e}')
        
def main():
    rospy.init_node('diag_listener', anonymous=True)

    #save 1 sec
    rospy.Timer(rospy.Duration(1), manager.save_to_file)

    total_resource_sub = rospy.Subscriber('/total_resource', Float32MultiArray, total_resource_callback)
    topic_hzbw_sub = rospy.Subscriber('/topics_hzbw', String, topics_hzbw_callback)
    nodes_resource_sub = rospy.Subscriber('/nodes_resource', String, nodes_resource_callback)
    gpu_pmon_sub = rospy.Subscriber('/gpu_pmon', String, gpu_pmon_callback)
    rospy.spin()

if __name__ == '__main__':
    main()