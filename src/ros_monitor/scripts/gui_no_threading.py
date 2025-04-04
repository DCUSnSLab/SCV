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
    QApplication,
    QPlainTextEdit
)
from PySide6.QtCore import Qt, QTimer
from std_msgs.msg import Float32MultiArray, String

# ros_topic_tracker.py에 find_topic_connections, find_node_connections가 정의되어 있다고 가정
import ros_topic_tracker

def signal_handler(sig, frame):
    QApplication.quit()
    sys.exit(0)

class RosMonitor(QWidget):
    def __init__(self):
        super().__init__()

        # ROS 노드 초기화
        rospy.init_node('ros_monitor_ui', anonymous=True)

        self.setWindowTitle('ROS Monitor UI')
        self.resize(1920, 1080)

        # 내부 상태 보관용 딕셔너리
        self.total_resource_data = {}
        self.topic_hzbw_data = {}
        self.nodes_resource_data = {}
        self.gpu_proc_data = {}

        # CPU/RAM/GPU 라벨
        self.cpu_label = QLabel('CPU Info: -')
        self.mem_label = QLabel('Memory Info: -')
        self.gpu_label = QLabel('GPU Info: -')

        # 로그 표시용 (터미널 스타일)
        self.log_widget = QPlainTextEdit()
        self.log_widget.setReadOnly(True)

        # UI 초기화
        self.init_ui()

        # ROS Subscriber 설정
        self.subscriber_setup()

        # 1초마다 UI 업데이트
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_ui)
        self.timer.start(1000)


    def init_ui(self):
        """GridLayout 구성"""
        logical_cores = psutil.cpu_count(logical=True)

        self.layout = QGridLayout(self)

        # ------------------------------------------------
        # 왼쪽 칼럼(0)에 로그 위젯 배치
        # ------------------------------------------------
        self.layout.addWidget(self.log_widget, 0, 0, 10, 1)

        # ------------------------------------------------
        # 상단 라벨 (CPU/RAM/GPU)
        # ------------------------------------------------
        label_layout = QVBoxLayout()
        label_layout.addWidget(self.cpu_label)
        label_layout.addWidget(self.mem_label)
        label_layout.addWidget(self.gpu_label)
        # row=0, col=1, rowSpan=1, colSpan=2
        self.layout.addLayout(label_layout, 0, 1, 1, 2)

        # ------------------------------------------------
        # Topics 테이블
        # ------------------------------------------------
        self.topics_table = QTableWidget(0, 3)
        self.topics_table.setHorizontalHeaderLabels(['Topic name', 'Hz', 'Bandwidth'])
        self.topics_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.topics_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.topics_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.topics_table, 1, 1, 3, 1)

        # (중요) 토픽 테이블 클릭 시그널 -> topic_clicked 함수
        self.topics_table.cellClicked.connect(self.topic_clicked)

        # ------------------------------------------------
        # 노드 테이블
        # ------------------------------------------------
        self.nodes_table = QTableWidget(0, 3)
        self.nodes_table.setHorizontalHeaderLabels([
            'Node name',
            f'CPU (%)\nLogical Core: {logical_cores}',
            'Ram'
        ])
        self.nodes_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.nodes_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.nodes_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.nodes_table, 1, 2, 3, 1)

        # ------------------------------------------------
        # GPU 프로세스 테이블
        # ------------------------------------------------
        self.gpu_proc_table = QTableWidget(0, 9)
        self.gpu_proc_table.setHorizontalHeaderLabels([
            'pid', 'type', 'sm', 'mem', 'enc', 'dec', 'jpg', 'ofa', 'command'
        ])
        for i in range(8):
            self.gpu_proc_table.horizontalHeader().setSectionResizeMode(i, QHeaderView.ResizeToContents)
        self.gpu_proc_table.horizontalHeader().setSectionResizeMode(8, QHeaderView.Stretch)

        self.layout.addWidget(self.gpu_proc_table, 4, 1, 3, 2)

        self.setLayout(self.layout)
        
    def timer_callback(self):
        # 1) ROS 콜백 한 번 수행
        rospy.spinOnce()
        # 2) UI 업데이트
        self.update_ui()


    def subscriber_setup(self):
        """ROS 토픽 구독 설정"""
        rospy.Subscriber('/total_resource', Float32MultiArray, self.total_resource_callback)
        rospy.Subscriber('/topics_hzbw', String, self.topic_hzbw_callback)
        rospy.Subscriber('/nodes_resource', String, self.nodes_resource_callback)
        rospy.Subscriber('/gpu_pmon', String, self.gpu_pmon_callback)

    # ===================== 콜백 함수들 =====================
    def total_resource_callback(self, msg):
        """Float32MultiArray -> 총 23개 필드"""
        f = [
            'cpu_user', 'cpu_nice', 'cpu_system', 'cpu_idle', 'cpu_iowait',
            'cpu_irq', 'cpu_softirq', 'cpu_steal', 'cpu_guest', 'cpu_guest_nice',
            'cpu_usage_percent', 'cpu_temp',
            'cpu_load_1min', 'cpu_load_5min', 'cpu_load_15min',
            'mem_used', 'mem_total', 'mem_usage_percent',
            'gpu_usage_percent', 'gpu_mem_used', 'gpu_mem_total', 'gpu_mem_usage', 'gpu_temp'
        ]
        self.total_resource_data = {n: v for n, v in zip(f, msg.data)}

    def topic_hzbw_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)  # 예: [{ "topic": "/gpu_pmon", "hz":1, "bw":180 }, ...]
        for i in arr:
            tmp[i['topic']] = {
                'hz': i['hz'],
                'bw': i['bw']
            }
        self.topic_hzbw_data = tmp

    def nodes_resource_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)  # 예: [{ "node":"nodeA", "cpu":0.1, "mem":"50MB/s"}, ...]
        for i in arr:
            tmp[i['node']] = {
                'cpu': i['cpu'],
                'mem': i['mem']
            }
        self.nodes_resource_data = tmp

    def gpu_pmon_callback(self, msg):
        tmp = {}
        arr = json.loads(msg.data)  # 예: [{ "pid":"1234", "type":"C", "sm":10, ...}, ...]
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

    # ===================== UI 주기 갱신 =====================
    def update_ui(self):
        """1초마다 호출 -> 라벨 + 테이블 갱신"""
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
            f'CPU: {cpu_usage:.2f}% | Temp: {cpu_temp:.1f}C | '
            f'Load: {load_1:.2f}, {load_5:.2f}, {load_15:.2f}'
        )
        self.mem_label.setText(
            f'Mem: {mem_used:.1f}/{mem_total:.1f} MB ({mem_usage_percent:.2f}%)'
        )
        self.gpu_label.setText(
            f'GPU: {gpu_usage:.2f}% | Mem: {gpu_mem_used:.1f}/{gpu_mem_total:.1f} MB '
            f'| Temp: {gpu_temp:.1f}C'
        )

    def update_topics_table(self):
        self.topics_table.setRowCount(len(self.topic_hzbw_data))
        for row_idx, (topic_name, val_dict) in enumerate(self.topic_hzbw_data.items()):
            hz_val = val_dict.get('hz', 0.0)
            bw_val = val_dict.get('bw', '0 B/s')

            t_item = QTableWidgetItem(topic_name)
            hz_item = QTableWidgetItem(str(hz_val))
            bw_item = QTableWidgetItem(str(bw_val))

            for it in [t_item, hz_item, bw_item]:
                it.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            self.topics_table.setItem(row_idx, 0, t_item)
            self.topics_table.setItem(row_idx, 1, hz_item)
            self.topics_table.setItem(row_idx, 2, bw_item)

    def update_nodes_table(self):
        self.nodes_table.setRowCount(len(self.nodes_resource_data))
        for row_idx, (node_name, resources) in enumerate(self.nodes_resource_data.items()):
            cpu_val = resources.get('cpu', 0.0)
            mem_val = resources.get('mem', 'N/A')

            n_item = QTableWidgetItem(node_name)
            cpu_item = QTableWidgetItem(f'{cpu_val:.2f}')
            mem_item = QTableWidgetItem(str(mem_val))

            for it in [n_item, cpu_item, mem_item]:
                it.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

            self.nodes_table.setItem(row_idx, 0, n_item)
            self.nodes_table.setItem(row_idx, 1, cpu_item)
            self.nodes_table.setItem(row_idx, 2, mem_item)

    def update_gpu_table(self):
        self.gpu_proc_table.setRowCount(len(self.gpu_proc_data))
        for row_idx, (pid_str, info) in enumerate(self.gpu_proc_data.items()):
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

            self.gpu_proc_table.setItem(row_idx, 0, pid_item)
            self.gpu_proc_table.setItem(row_idx, 1, type_item)
            self.gpu_proc_table.setItem(row_idx, 2, sm_item)
            self.gpu_proc_table.setItem(row_idx, 3, mem_item)
            self.gpu_proc_table.setItem(row_idx, 4, enc_item)
            self.gpu_proc_table.setItem(row_idx, 5, dec_item)
            self.gpu_proc_table.setItem(row_idx, 6, jpg_item)
            self.gpu_proc_table.setItem(row_idx, 7, ofa_item)
            self.gpu_proc_table.setItem(row_idx, 8, cmd_item)

    # ----------------------
    # 로그창에 메시지 출력
    # ----------------------
    def append_log(self, text: str):
        self.log_widget.appendPlainText(text)

    # ----------------------
    # 토픽 목록 업데이트
    # ----------------------
    def update_topic_list(self):
        """ROS Master에서 가져온 토픽 목록을 topics_table에 표시"""
        master = rospy.get_master()
        state = master.getSystemState()
        pubs = state[0]  # [(topic_name, [node1, node2...]), ...]
        # subs = state[1]
        # etc.

        all_topics = sorted([t for t, _ in pubs])
        self.topics_table.setRowCount(len(all_topics))
        for i, topic_name in enumerate(all_topics):
            item = QTableWidgetItem(topic_name)
            item.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
            self.topics_table.setItem(i, 0, item)

    # ----------------------
    # 토픽 테이블 클릭 핸들러
    # ----------------------
    def topic_clicked(self, row, col):
        """
        토픽 테이블에서 셀 클릭 시 호출
        row, col = 클릭된 행, 열
        """
        topic_item = self.topics_table.item(row, 0)
        if not topic_item:
            return

        clicked_topic = topic_item.text()
        # ros_topic_tracker 모듈 사용
        pubs, subs = ros_topic_tracker.find_topic_connections(clicked_topic)

        self.append_log(f"\n\n=== Topic clicked: {clicked_topic} ===")
        self.append_log(f"Publishers: {pubs}")
        self.append_log(f"Subscribers: {subs}")

        # 각 노드의 pub/sub 토픽도 표시
        for p_node in pubs:
            pub_topics, sub_topics = ros_topic_tracker.find_node_connections(p_node)
            self.append_log(f" Node: {p_node}")
            self.append_log(f"   Publishes: {pub_topics}")
            self.append_log(f"   Subscribes: {sub_topics}")

        for s_node in subs:
            pub_topics, sub_topics = ros_topic_tracker.find_node_connections(s_node)
            self.append_log(f" Node: {s_node}")
            self.append_log(f"   Publishes: {pub_topics}")
            self.append_log(f"   Subscribes: {sub_topics}")

def main():
    signal.signal(signal.SIGINT, signal_handler)

    app = QApplication(sys.argv)
    window = RosMonitor()
    window.show()

    # 수동 메인 루프
    import time
    while not rospy.is_shutdown():
        # 1) Qt 이벤트 처리
        app.processEvents()

        # 2) rospy 콜백은?
        # Python rospy 콜백들은 이미 백그라운드 스레드에서
        # 소켓을 수신하면 자동으로 돌긴 하지만,
        # 실제로는 spin()이 블록하는 구조라... 
        # *파이썬 내부적으로 CallbackThread가 동작 중이긴 합니다만
        #  rospy.spin() 호출 안 하면?
        # -> rospy.spin()이 없어도 Subscriber 콜백은 "internal thread"에서
        #    동작하긴 하지만, 안정적 보장을 못 합니다.
        #
        # 사실상 Python rospy는 spin()을 불러주길 권장하지만,
        # spin()이 꼭 필요한 건 아니고, subscriber 콜백 자체는
        # internal thread에서 돌아가게 되어 있습니다.

        if app.allWindows() == []:
            # 윈도우가 닫혔으면 종료
            break
        time.sleep(0.01)

if __name__ == '__main__':
    main()
