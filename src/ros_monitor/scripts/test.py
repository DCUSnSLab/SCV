#!/usr/bin/env python3

import glob
import os

# 모니터링할 각 모듈(프로세스)별 키워드 설정.
# 만약 여기가 비어 있다면(MONITOR_CONFIG = {}),
# "실행 중인 모든 프로세스"를 그대로 출력(OK 처리)하도록 함.
MONITOR_CONFIG = {
    # 예시) "planning": ["modules/planning", "mainboard"],
    #       "prediction": ["modules/prediction", "mainboard"],
    # 비워두면 아래 코드에서 전체 프로세스 리스트 출력
    ''
}

class ProcessMonitor:
    def __init__(self, monitor_config):
        """
        monitor_config: { module_name: [keyword1, keyword2, ...], ... }
        """
        self.monitor_config = monitor_config

    def get_running_commands(self):
        """
        /proc/[PID]/cmdline 파일에서 현재 실행 중인 프로세스의
        command line 전체 문자열 목록을 수집한다.
        """
        running_cmds = []
        for cmd_file in glob.glob("/proc/*/cmdline"):
            try:
                with open(cmd_file, "r") as f:
                    cmd_string = f.read().strip()
                    # cmdline은 각 인자를 '\0'로 구분하므로, 공백으로 바꿔준다.
                    cmd_string = cmd_string.replace('\0', ' ')
                    if cmd_string:
                        running_cmds.append(cmd_string)
            except (IOError, OSError):
                # 접근 권한이 없거나, 해당 파일이 없어지는 등 에러가 날 수 있다.
                pass
        return running_cmds

    def update_status(self):
        """
        현재 돌고 있는 프로세스 목록(running_cmds)을 읽고,
        모듈별로 OK / FATAL 상태를 판정한다.

        *추가*: 만약 monitor_config가 비어 있으면,
        "실행 중인 모든 프로세스"를 출력해준다.
        """
        running_cmds = self.get_running_commands()
        status_dict = {}

        # 1) 만약 monitor_config가 비어 있다면, 모든 프로세스를 출력
        if not self.monitor_config:
            # 여기서는 편의상 모든 프로세스를 'OK'로 표기
            # 혹은 실제 상황에 맞게 다른 처리를 해도 됨.
            for idx, cmd_line in enumerate(running_cmds, start=1):
                module_name = f"Process_{idx}"
                status_dict[module_name] = f"OK - {cmd_line}"
            return status_dict

        # 2) monitor_config가 있는 경우: 각 모듈에 대한 키워드 검색
        for module_name, keywords in self.monitor_config.items():
            # 기본값: FATAL (찾지 못했을 경우)
            module_status = "FATAL"

            # 하나라도 키워드를 전부 포함하는 프로세스를 찾으면 OK 처리
            for cmd_line in running_cmds:
                if all(keyword in cmd_line for keyword in keywords):
                    module_status = "OK"
                    break

            status_dict[module_name] = module_status

        return status_dict

    def run_once(self):
        """
        1회 모니터링 실행 (C++ 코드의 RunOnce와 유사).
        상태를 업데이트 후, 결과를 stdout에 출력.
        """
        status = self.update_status()
        for mod, st in status.items():
            print(f"[{mod}] status = {st}")

def main():
    monitor = ProcessMonitor(MONITOR_CONFIG)
    # 주기적으로 실행하려면 while True 루프 등을 이용하면 됨
    monitor.run_once()

if __name__ == "__main__":
    main()
