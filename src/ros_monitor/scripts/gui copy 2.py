#!/usr/bin/env python3
import sys
import os
import signal
import rospy
import psutil
import json
from PySide6.QtWidgets import (
    QWidget,
    QVBoxLayout,
    QGridLayout,
    QLabel,
    QTableWidget,
    QTableWidgetItem,
    QHeaderView,
    QApplication
)
from PySide6.QtCore import Qt, QTimer
from std_msgs.msg import Float32MultiArray, String

def signal_handler(sig, frame):
    QApplication.quit()
    sys.exit(0)

class RosMonitor(QWidget):
    def __init__(self):
        super().__init__()

        rospy.init_node('ros_monitor_ui', anonymous=True)

        self.setWindowTitle('ROS Monitor UI')
        self.resize(1920, 1080)

        self.total_resource_data = {}
        self.topic_hzbw_data = {}
        self.nodes_resource_data = {}
        self.gpu_proc_data = {}

        self.cpu_label = QLabel('CPU Info: -')
        self.mem_label = QLabel('Memory Info: -')
        self.gpu_label = QLabel('GPU Info: -')

        self.init_ui()

        self.subscriber_setup()

        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_ui)
        self.timer.start(1000)

    def init_ui(self):
        logical_cores = psutil.cpu_count(logical=True)

        self.layout = QGridLayout(self)

        label_layout = QVBoxLayout()
        label_layout.addWidget(self.cpu_label)
        label_layout.addWidget(self.mem_label)
        label_layout.addWidget(self.gpu_label)
        self.layout.addLayout(label_layout, 0, 0, 1, 2)

        self.topics_table = QTableWidget(0, 3)
        self.topics_table.setHorizontalHeaderLabels(['Topic name', 'Hz', 'Bandwidth'])
        self.topics_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.topics_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.topics_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.topics_table, 1, 0, 3, 1)

        # 노드 테이블
        self.nodes_table = QTableWidget(0, 3)
        self.nodes_table.setHorizontalHeaderLabels(['Node name', f'CPU (%) \nLogical Core : {logical_cores}', 'Ram'])
        self.nodes_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.nodes_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.nodes_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.nodes_table, 1, 1, 3, 1)

        # GPU 프로세스 테이블
        self.gpu_proc_table = QTableWidget(0, 9)
        self.gpu_proc_table.setHorizontalHeaderLabels([
            'pid', 'type', 'sm', 'mem',
            'enc', 'dec', 'jpg', 'ofa', 'command'
        ])
        for i in range(0, 8):
            self.gpu_proc_table.horizontalHeader().setSectionResizeMode(i, QHeaderView.ResizeToContents)
        self.gpu_proc_table.horizontalHeader().setSectionResizeMode(8, QHeaderView.Stretch)
        self.layout.addWidget(self.gpu_proc_table, 4, 0, 3, 2)

        
        self.setLayout(self.layout)

    def subscriber_setup(self):
        rospy.Subscriber('/total_resource', Float32MultiArray, self.total_resource_callback)
        rospy.Subscriber('/topics_hzbw', String, self.topic_hzbw_callback)
        rospy.Subscriber('/nodes_resource', String, self.nodes_resource_callback)
        rospy.Subscriber('/gpu_pmon', String, self.gpu_pmon_callback)

    
    def total_resource_callback(self, msg):
        f = [
            'cpu_user', 'cpu_nice', 'cpu_system', 'cpu_idle', 'cpu_iowait',
            'cpu_irq', 'cpu_softirq', 'cpu_steal', 'cpu_guest', 'cpu_guest_nice',
            'cpu_usage_percent', 'cpu_temp',
            'cpu_load_1min', 'cpu_load_5min', 'cpu_load_15min',
            'mem_used', 'mem_total', 'mem_usage_percent',
            'gpu_usage_percent', 'gpu_mem_used', 'gpu_mem_total', 'gpu_mem_usage', 'gpu_temp'
        ]
        self.total_resource_data = {
            n: v for n, v in zip(f, msg.data)
        }
        
    def topic_hzbw_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)
        for i in arr:
            tmp[i['topic']] = {
                'hz': i['hz'],
                'bw': i['bw']
            }
            
        self.topic_hzbw_data = tmp
        
    def nodes_resource_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)
        for i in arr:
            tmp[i['node']] = {
                'cpu': i['cpu'],
                'mem': i['mem']
            }
            
        self.nodes_resource_data = tmp
        
    def gpu_pmon_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)
        for i in arr:
            tmp[i['pid']] = {
                'gpu_idx': i['gpu_idx'],
                'type': i['type'],
                'sm': i['sm'],
                'mem': i['mem'],
                'enc': i['enc'],
                'dec': i['dec'],
                'jpg': i['jpg'],
                'ofa': i['ofa'],
                'command': i['command'],
            }
            
        self.gpu_proc_data = tmp
        
    def update_ui(self):
        self.update_labels()
        self.update_topics_table()
        self.update_nodes_table()
        self.update_gpu_table()


    def update_labels(self):
        cpu_usage = self.total_resource_data.get('cpu_usage_percent', 0.0)
        cpu_temp = self.total_resource_data.get('cpu_temp', 0.0)
        load_1 = self.total_resource_data.get('cpu_load_1min', 0.0)
        load_5 = self.total_resource_data.get('cpu_load_5min', 0.0)
        load_15 = self.total_resource_data.get('cpu_load_15min', 0.0)

        mem_usage_percent = self.total_resource_data.get('mem_usage_percent', 0.0)
        mem_used = self.total_resource_data.get('mem_used', 0.0)
        mem_total = self.total_resource_data.get('mem_total', 0.0)

        gpu_usage = self.total_resource_data.get('gpu_usage_percent', 0.0)
        gpu_mem_used = self.total_resource_data.get('gpu_mem_used', 0.0)
        gpu_mem_total = self.total_resource_data.get('gpu_mem_total', 0.0)
        gpu_temp = self.total_resource_data.get('gpu_temp', 0.0)

        self.cpu_label.setText(
            f'CPU: {cpu_usage:.2f}% | Temp: {cpu_temp:.1f}C | Load: {load_1:.2f}, {load_5:.2f}, {load_15:.2f}'
        )
        self.mem_label.setText(
            f'Mem: {mem_used:.1f}/{mem_total:.1f} MB ({mem_usage_percent:.2f}%)'
        )
        self.gpu_label.setText(
            f'GPU: {gpu_usage:.2f}% | Mem: {gpu_mem_used:.1f}/{gpu_mem_total:.1f} MB | Temp: {gpu_temp:.1f}C'
        )
        

    def update_topics_table(self):
        self.topics_table.setRowCount(len(self.topic_hzbw_data))
        for idx, (n, v) in enumerate(self.topic_hzbw_data.items()):
            hz_val = v.get('hz', 0.0)
            bw_val = v.get('bw', '0 B/s')

            t_item = QTableWidgetItem(n)
            hz_item = QTableWidgetItem(str(hz_val))
            bw_item = QTableWidgetItem(str(bw_val))

            for it in [t_item, hz_item, bw_item]:
                it.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            self.topics_table.setItem(idx, 0, t_item)
            self.topics_table.setItem(idx, 1, hz_item)
            self.topics_table.setItem(idx, 2, bw_item)

    def update_nodes_table(self):
        self.nodes_table.setRowCount(len(self.nodes_resource_data))
        for idx, (n, resources) in enumerate(self.nodes_resource_data.items()):
            cpu_val = resources.get('cpu', 0.0)
            mem_val = resources.get('mem', 'N/A')

            n_item = QTableWidgetItem(n)
            cpu_item = QTableWidgetItem(f'{cpu_val:.2f}')
            mem_item = QTableWidgetItem(str(mem_val))

            for it in [n_item, cpu_item, mem_item]:
                it.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            self.nodes_table.setItem(idx, 0, n_item)
            self.nodes_table.setItem(idx, 1, cpu_item)
            self.nodes_table.setItem(idx, 2, mem_item)
            
    def update_gpu_table(self):
        self.gpu_proc_table.setRowCount(len(self.gpu_proc_data))
        for idx, (pid_str, info) in enumerate(self.gpu_proc_data.items()):
            type_ = info.get('type', '-')
            sm_ = info.get('sm', 0.0)
            mem_ = info.get('mem', 0.0)
            enc_ = info.get('enc', 0.0)
            dec_ = info.get('dec', 0.0)
            jpg_ = info.get('jpg', 0.0)
            ofa_ = info.get('ofa', 0.0)
            cmd_ = info.get('command', '-')

            pid_item = QTableWidgetItem(pid_str)
            type_item = QTableWidgetItem(type_)
            sm_item = QTableWidgetItem(f'{sm_}')
            mem_item = QTableWidgetItem(f'{mem_}')
            enc_item = QTableWidgetItem(f'{enc_}')
            dec_item = QTableWidgetItem(f'{dec_}')
            jpg_item = QTableWidgetItem(f'{jpg_}')
            ofa_item = QTableWidgetItem(f'{ofa_}')
            cmd_item = QTableWidgetItem(cmd_)

            for it in [pid_item, type_item, sm_item, mem_item,
                       enc_item, dec_item, jpg_item, ofa_item, cmd_item]:
                it.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            self.gpu_proc_table.setItem(idx, 0, pid_item)
            self.gpu_proc_table.setItem(idx, 1, type_item)
            self.gpu_proc_table.setItem(idx, 2, sm_item)
            self.gpu_proc_table.setItem(idx, 3, mem_item)
            self.gpu_proc_table.setItem(idx, 4, enc_item)
            self.gpu_proc_table.setItem(idx, 5, dec_item)
            self.gpu_proc_table.setItem(idx, 6, jpg_item)
            self.gpu_proc_table.setItem(idx, 7, ofa_item)
            self.gpu_proc_table.setItem(idx, 8, cmd_item)


def main():
    signal.signal(signal.SIGINT, signal_handler)

    app = QApplication(sys.argv)
    window = RosMonitor()
    window.show()

    # ROS 스핀 (QApplication.exec_()와 병행 시, 스레드를 쓰거나
    # python 실행 순서에 따라 조정 필요. 간단히는 spinOnce를 타이머에 넣는 방법도 있음.)
    #
    # 방법1) rospy와 QT 모두 메인스레드에서 돌리기는 tricky하므로, 다음처럼:
    #   import threading
    #   spinner = threading.Thread(target=rospy.spin)
    #   spinner.start()
    #
    # 방법2) or ros::spinOnce를 QTimer에서 주기적으로 돌리는 식.
    #
    # 여기서는 예시로 threading 사용 (간단히 시연)
    
    import threading
    spinner = threading.Thread(target=rospy.spin)
    spinner.start()

    sys.exit(app.exec())

if __name__ == '__main__':
    main()
