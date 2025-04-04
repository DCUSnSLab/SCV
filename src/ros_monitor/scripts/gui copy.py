#!/usr/bin/env python3
import sys
import os
import json
import signal
import rospy
import psutil

from PySide6.QtWidgets import (
    QWidget, 
    QVBoxLayout, 
    QGridLayout,
    QLabel,
    QTableWidget,
    QTableWidgetItem,
    QHeaderView,
    QApplication,
    QHBoxLayout,
    QBoxLayout
)
from PySide6.QtCore import Qt, QTimer


def signal_handler(sig, frame):
    QApplication.quit()
    sys.exit(0)


class RosMonitor(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('ROS Monitor UI')
        self.resize(1200, 900)

        # JSON 데이터 저장
        self.total_resource_data = {}
        self.topic_hzbw_data = {}
        self.node_resource_usage_data = {}

        #json path
        self.file_path = os.path.expanduser('/home/pgw/catkin_ws/src/ros_monitor/data/diag.json')

        self.init_ui()

        #ui refresh timer
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_ui_from_json)
        self.timer.start(1000)

    def init_ui(self):
        ''' UI 초기화 '''
        self.layout = QGridLayout(self)
        
        self.label_layout = QVBoxLayout()
        self.label_layout.setSpacing(0)
        
        #cpu info
        self.cpu_label = QLabel('CPU Info: Loading...')
        #Ram info
        self.mem_label = QLabel('Memory Info: Loading...')
        #gpu info
        self.gpu_label = QLabel('GPU Info: Loading...')

        self.label_layout.addWidget(self.cpu_label)
        self.label_layout.addWidget(self.mem_label)
        self.label_layout.addWidget(self.gpu_label)
        
        self.layout.addLayout(self.label_layout, 0, 0, 1, 1)
        
        #topics hz and bw table
        self.topics_table = QTableWidget(0, 3)
        self.topics_table.setHorizontalHeaderLabels(['Topic name', 'Hz', 'Bandwidth'])
        self.topics_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)  # Topic name 자동 확장
        self.topics_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)  # Hz 값 크기 맞춤
        self.topics_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)  # Bandwidth 크기 맞춤
        self.layout.addWidget(self.topics_table, 3, 0, 3, 1)

        #nodes resource table
        self.nodes_table = QTableWidget(0, 3)
        self.nodes_table.setHorizontalHeaderLabels(['Node name', 'CPU (%)', 'Ram'])
        self.nodes_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)  # Node name 자동 확장
        self.nodes_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)  # CPU 크기 맞춤
        self.nodes_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)  # Ram 크기 맞춤
        self.layout.addWidget(self.nodes_table, 3, 1, 3, 1)
        
        self.gpu_proc_table = QTableWidget(0, 10)
        self.gpu_proc_table.setHorizontalHeaderLabels(['pid', 'proc_name', 'type', 'sm', 'mem', 'enc', 'dec', 'jpg', 'ofa', 'command'])

        
        for i in range(0, 9):
            self.gpu_proc_table.horizontalHeader().setSectionResizeMode(i, QHeaderView.ResizeToContents)
            
        self.gpu_proc_table.horizontalHeader().setSectionResizeMode(9, QHeaderView.Stretch)
    
        
        self.layout.addWidget(self.gpu_proc_table, 7, 0, 3, 2) # (위젯, 시작 행, 시작 열, 행 개수, 열 개수)

        self.setLayout(self.layout)
        
    def update_ui_from_json(self):
        '''Read json file and update ui'''
        if not os.path.exists(self.file_path):
            return

        try:
            with open(self.file_path, 'r') as file:
                data = json.load(file)
                self.total_resource_data = data.get('total_resource', {})
                self.topic_hzbw_data = data.get('topics_hzbw', {})
                self.node_resource_usage_data = data.get('node_resource_usage', {})
                self.pmon_data = data.get('gpu_pmon', {})
                
                self.update_total_resource()
                self.update_topics_table()
                self.update_nodes_table()
                self.update_gpu_proc_table()
                
        except Exception as e:
            print(f'Error reading JSON file: {e}')

    def update_total_resource(self):
        '''cpu, ram, gpu info update'''
        self.cpu_label.setText(
            f"CPU: {self.total_resource_data.get('cpu_usage_percent'):.2f}% | "
            f"Temp: {self.total_resource_data.get('cpu_temp'):.2f} C | "
            f"Load Avg: {self.total_resource_data.get('cpu_load_1min'):.2f}, "
            f"{self.total_resource_data.get('cpu_load_5min'):.2f}, "
            f"{self.total_resource_data.get('cpu_load_15min'):.2f}"
        )

        self.mem_label.setText(
            f"Memory: {self.total_resource_data.get('mem_used'):.2f} / "
            f"{self.total_resource_data.get('mem_total'):.2f} MB"
            f"({self.total_resource_data.get('mem_usage_percent'):.2f}%)"
        )

        self.gpu_label.setText(
            f"GPU: {self.total_resource_data.get('gpu_usage_percent'):.2f}% | "
            f"Memory: {self.total_resource_data.get('gpu_mem_used'):.2f} / "
            f"{self.total_resource_data.get('gpu_mem_total'):.2f} MB "
            f"({self.total_resource_data.get('gpu_mem_usage'):.2f}%) | "
            f"Temp: {self.total_resource_data.get('gpu_temp'):.2f} C"
        )

    def update_topics_table(self):
        ''' Topics Hz/BW 테이블 업데이트 '''
        self.topics_table.setRowCount(len(self.topic_hzbw_data))
        
        for row, (topic, metrics) in enumerate(self.topic_hzbw_data.items()):
            
            
            # 각 셀을 생성한 후, 읽기 전용으로 설정
            topic_item = QTableWidgetItem(topic)
            hz_item = QTableWidgetItem(str(metrics.get('hz', -1)))
            bw_item = QTableWidgetItem(str(metrics.get('bw', -1)))

            # 셀을 수정할 수 없도록 설정 (읽기 전용)
            topic_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            hz_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            bw_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            
            self.topics_table.setItem(row, 0, topic_item)
            self.topics_table.setItem(row, 1, hz_item)
            self.topics_table.setItem(row, 2, bw_item)

    def update_nodes_table(self):
        ''' Node 리소스 테이블 업데이트 '''
        self.nodes_table.setRowCount(len(self.node_resource_usage_data))
        
        for row, (node, resources) in enumerate(self.node_resource_usage_data.items()):
            
            #node : str, metrics.get('cpu') : float , metrics.get('mem') : int

            # 각 셀을 생성한 후, 읽기 전용으로 설정
            node_item = QTableWidgetItem(node)
            cpu_item = QTableWidgetItem(str(resources.get('cpu','N/A')))
            mem_item = QTableWidgetItem(str(resources.get('mem','N/A')))

            # 셀을 수정할 수 없도록 설정 (읽기 전용)
            node_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            cpu_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            mem_item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            # 테이블에 값 추가
            self.nodes_table.setItem(row, 0, node_item)
            self.nodes_table.setItem(row, 1, cpu_item)
            self.nodes_table.setItem(row, 2, mem_item)
    
    def update_gpu_proc_table(self):
        self.gpu_proc_table.setRowCount(len(self.pmon_data))
        '''
        'pid', 'proc_name', 'type', 'sm', 'mem', 'enc', 'dec', 'jpg', 'ofa', 'command'
        '''
        for row, (pid_str, info) in enumerate(self.pmon_data.items()):
            
            if pid_str == '-' or not pid_str.isdigit():
                pid_i = QTableWidgetItem('-')
                proc_name_i = QTableWidgetItem('-')
            else:
                try:
                    pid_int = int(pid_str)
                    pid_i = QTableWidgetItem(pid_str)
                    # psutil로 프로세스 이름 가져오기 (프로세스가 존재하지 않으면 예외 처리)
                    try:
                        proc_name_text = psutil.Process(pid_int).name()
                    except psutil.NoSuchProcess:
                        proc_name_text = '-'
                    proc_name_i = QTableWidgetItem(proc_name_text)
                except Exception as e:
                    pid_i = QTableWidgetItem(pid_str)
                    proc_name_i = QTableWidgetItem('-')
                    
            type_i = QTableWidgetItem(str(info.get('type')))
            sm_i = QTableWidgetItem(str(info.get('sm_usage')))
            mem_i = QTableWidgetItem(str(info.get('mem_usage')))
            enc_i = QTableWidgetItem(str(info.get('enc_usage')))
            dec_i = QTableWidgetItem(str(info.get('dec_usage')))
            jpg_i = QTableWidgetItem(str(info.get('jpg_usage')))
            ofa_i = QTableWidgetItem(str(info.get('ofa_usage')))
            cmd_i = QTableWidgetItem(str(info.get('command')))
            
            pid_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            proc_name_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            type_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            sm_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            mem_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            enc_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            dec_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            jpg_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            ofa_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            cmd_i.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            
            self.gpu_proc_table.setItem(row, 0, pid_i)
            self.gpu_proc_table.setItem(row, 1, proc_name_i)
            self.gpu_proc_table.setItem(row, 2, type_i)
            self.gpu_proc_table.setItem(row, 3, sm_i)
            self.gpu_proc_table.setItem(row, 4, mem_i)
            self.gpu_proc_table.setItem(row, 5, enc_i)
            self.gpu_proc_table.setItem(row, 6, dec_i)
            self.gpu_proc_table.setItem(row, 7, jpg_i)
            self.gpu_proc_table.setItem(row, 8, ofa_i)
            self.gpu_proc_table.setItem(row, 9, cmd_i)

# Ensure this is run in a ROS node context
if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal_handler)

    app = QApplication(sys.argv)
    window = RosMonitor()
    window.show()

    sys.exit(app.exec())
