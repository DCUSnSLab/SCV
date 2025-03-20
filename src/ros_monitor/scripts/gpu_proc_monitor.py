#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
from std_msgs.msg import String
import subprocess
import json
import psutil

def parse_pmon_output(lines):
    """
    nvidia-smi pmon -c 1 output example:

    10-column format:
    # gpu       pid  type  sm   mem  enc  dec  jpg  ofa  command 
    # Idx         #   C/G   %    %    %    %    %    %   name 
        0      1234   C    50   30    -    -    -    -   python

    8-column format:
    # gpu         pid  type    sm    mem    enc    dec    command
    # Idx           #   C/G     %      %      %      %    name
        0        981     G      -      -      -      -    Xorg
        0    1204448     G      -      -      -      -    Xorg
    """
    parsed_data_list = []
    
    for line in lines:
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        
        cols = line.split()
        # 10 column format
        if len(cols) >= 10:
            print('asdf')

            gpu_idx = cols[0]
            pid = cols[1]
            process_type = cols[2]
            sm_usage = cols[3]
            mem_usage = cols[4]
            enc_usage = cols[5]
            dec_usage = cols[6]
            jpg_usage = cols[7]
            ofa_usage = cols[8]
            command = " ".join(cols[9:])
            
            # Convert '-' to None
            sm_usage = None if sm_usage == '-' else float(sm_usage)
            mem_usage = None if mem_usage == '-' else float(mem_usage)
            enc_usage = None if enc_usage == '-' else float(enc_usage)
            dec_usage = None if dec_usage == '-' else float(dec_usage)
            jpg_usage = None if jpg_usage == '-' else float(jpg_usage)
            ofa_usage = None if ofa_usage == '-' else float(ofa_usage)
            
            parsed_data = {
                'gpu_idx': gpu_idx,
                'pid': pid,
                'type': process_type,
                'sm_usage': sm_usage,
                'mem_usage': mem_usage,
                'enc_usage': enc_usage,
                'dec_usage': dec_usage,
                'jpg_usage': jpg_usage,
                'ofa_usage': ofa_usage,
                'command': command
            }
        
        # 8 column format
        elif len(cols) == 8:
            gpu_idx = cols[0]
            pid = cols[1]
            process_type = cols[2]
            sm_usage = cols[3]
            mem_usage = cols[4]
            enc_usage = cols[5]
            dec_usage = cols[6]
            command = cols[7]
            
            sm_usage = None if sm_usage == '-' else float(sm_usage)
            mem_usage = None if mem_usage == '-' else float(mem_usage)
            enc_usage = None if enc_usage == '-' else float(enc_usage)
            dec_usage = None if dec_usage == '-' else float(dec_usage)
            
            parsed_data = {
                'gpu_idx': gpu_idx,
                'pid': pid,
                'type': process_type,
                'sm_usage': sm_usage,
                'mem_usage': mem_usage,
                'enc_usage': enc_usage,
                'dec_usage': dec_usage,
                'jpg_usage': None,
                'ofa_usage': None,
                'command': command
            }

        if pid == '-':
            continue
        else:
            print(parsed_data)
            parsed_data_list.append(parsed_data)
        
    return parsed_data_list

def get_pmon_data():

    cmd = ["nvidia-smi", "pmon", "-c", "1"]
    
    try:
        output = subprocess.check_output(cmd, universal_newlines=True)

    except subprocess.CalledProcessError as e:
        rospy.logerr("Error executing nvidia-smi pmon: %s" % e)
        return []

    lines = output.split("\n")
    data = parse_pmon_output(lines)
    return data

def main():
    rospy.init_node("gpu_pmon_publisher", anonymous=True)
    pub = rospy.Publisher("/gpu_pmon", String, queue_size=100)

    rate = rospy.Rate(1)

    while not rospy.is_shutdown():
        pmon_data = get_pmon_data()
        json_str = json.dumps(pmon_data)
        msg = String(data=json_str)

        pub.publish(msg)

        for proc_data in pmon_data:
            pid_str = proc_data.get('pid')
            #print(pid_str)
            if pid_str and pid_str.isdigit():
                pid = int(pid_str)
                try:
                    proc = psutil.Process(pid)
                    #print(f"PID: {pid}, Name: {proc.name()}, Cmdline: {proc.cmdline()}")
                except psutil.NoSuchProcess:
                    print(f"PID: {pid} - Process no longer exists")
                    
        rate.sleep()

if __name__ == "__main__":
    main()
