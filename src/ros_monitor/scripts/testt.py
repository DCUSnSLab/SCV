#!/usr/bin/python3
# -*- coding: utf-8 -*-

import subprocess

def parse_pmon_output(lines):
    """
    nvidia-smi pmon -c 1 출력 예시:

    10컬럼 형식:
    # gpu       pid  type  sm   mem  enc  dec  jpg  ofa  command 
    # Idx         #   C/G   %    %    %    %    %    %   name 
        0      1234   C    50   30    -    -    -    -   python

    8컬럼 형식:
    # gpu         pid  type    sm    mem    enc    dec    command
    # Idx           #   C/G     %      %      %      %    name
        0        981     G      -      -      -      -    Xorg
        0    1204448     G      -      -      -      -    Xorg
    """
    parsed_data = []
    
    for line in lines:
        line = line.strip()
        if not line or line.startswith('#'):
            continue
        
        cols = line.split()
        
        # 10컬럼 형식 처리
        if len(cols) >= 10:
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
            
            # '-' 값은 None 처리, 나머지는 float 변환
            sm_usage = None if sm_usage == '-' else float(sm_usage)
            mem_usage = None if mem_usage == '-' else float(mem_usage)
            enc_usage = None if enc_usage == '-' else float(enc_usage)
            dec_usage = None if dec_usage == '-' else float(dec_usage)
            jpg_usage = None if jpg_usage == '-' else float(jpg_usage)
            ofa_usage = None if ofa_usage == '-' else float(ofa_usage)
            
            parsed_data.append({
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
            })
        
        # 8컬럼 형식 처리
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
            
            parsed_data.append({
                'gpu_idx': gpu_idx,
                'pid': pid,
                'type': process_type,
                'sm_usage': sm_usage,
                'mem_usage': mem_usage,
                'enc_usage': enc_usage,
                'dec_usage': dec_usage,
                'command': command
            })
    
    return parsed_data

def get_pmon_data():
    cmd = ["nvidia-smi", "pmon", "-c", "1"]
    try:
        output = subprocess.check_output(cmd, universal_newlines=True)
    except subprocess.CalledProcessError as e:
        print("Error executing nvidia-smi pmon:", e)
        return []

    lines = output.split("\n")
    data = parse_pmon_output(lines)
    return data

if __name__ == "__main__":
    pmon_data = get_pmon_data()
    for entry in pmon_data:
        print(entry)
