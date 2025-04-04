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
            gpu_idx = cols[0]
            pid = cols[1]
            process_type = cols[2]
            sm = cols[3]
            mem = cols[4]
            enc = cols[5]
            dec = cols[6]
            jpg = cols[7]
            ofa = cols[8]
            command = " ".join(cols[9:])
            
            # Convert '-' to None
            sm = None if sm == '-' else float(sm)
            mem = None if mem == '-' else float(mem)
            enc = None if enc == '-' else float(enc)
            dec = None if dec == '-' else float(dec)
            jpg = None if jpg == '-' else float(jpg)
            ofa = None if ofa == '-' else float(ofa)
            
            parsed_data = {
                'gpu_idx': gpu_idx,
                'pid': pid,
                'type': process_type,
                'sm': sm,
                'mem': mem,
                'enc': enc,
                'dec': dec,
                'jpg': jpg,
                'ofa': ofa,
                'command': command
            }
        
        # 8 column format
        elif len(cols) == 8:
            gpu_idx = cols[0]
            pid = cols[1]
            process_type = cols[2]
            sm = cols[3]
            mem = cols[4]
            enc = cols[5]
            dec = cols[6]
            command = cols[7]
            
            sm = None if sm == '-' else float(sm)
            mem = None if mem == '-' else float(mem)
            enc = None if enc == '-' else float(enc)
            dec = None if dec == '-' else float(dec)
            
            parsed_data = {
                'gpu_idx': gpu_idx,
                'pid': pid,
                'type': process_type,
                'sm': sm,
                'mem': mem,
                'enc': enc,
                'dec': dec,
                'jpg': None,
                'ofa': None,
                'command': command
            }

        if pid == '-':
            continue
        else:
            parsed_data_list.append(parsed_data)
            
    if len(parsed_data_list) == 0:
        parsed_data = {
            'gpu_idx': '-1',
            'pid': '-1',
            'type': '-1',
            'sm': '-1',
            'mem': '-1',
            'enc': '-1',
            'dec': '-1',
            'jpg': '-1',
            'ofa': '-1',
            'command': '-1'
        }
        parsed_data_list.append(parsed_data)
    print(parsed_data_list)
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
            if pid_str and pid_str.isdigit():
                pid = int(pid_str)
                try:
                    proc = psutil.Process(pid)
                    print(f"PID: {pid}, Name: {proc.name()}, Cmdline: {proc.cmdline()}")
                except psutil.NoSuchProcess:
                    print(f"PID: {pid} - Process no longer exists")
                    
        rate.sleep()

if __name__ == "__main__":
    main()
