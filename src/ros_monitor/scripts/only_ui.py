#!/usr/bin/env python3
import sys
import signal
from PySide6.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QGridLayout, QLabel,
    QTableWidget, QTableWidgetItem, QHeaderView
)
from PySide6.QtCore import Qt, QTimer
import psutil

def signal_handler(sig, frame):
    QApplication.quit()
    sys.exit(0)

class RosMonitor(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('ROS Monitor UI (Only Layout)')
        self.resize(1200, 900)
        self.init_ui()

    def init_ui(self):
        self.layout = QGridLayout(self)

        # 상단 CPU/RAM/GPU 정보 라벨
        self.label_layout = QVBoxLayout()
        self.cpu_label = QLabel('CPU Info: ...')
        self.mem_label = QLabel('Memory Info: ...')
        self.gpu_label = QLabel('GPU Info: ...')

        self.label_layout.addWidget(self.cpu_label)
        self.label_layout.addWidget(self.mem_label)
        self.label_layout.addWidget(self.gpu_label)
        self.layout.addLayout(self.label_layout, 0, 0, 1, 1)

        # Topic Hz/BW 테이블
        self.topics_table = QTableWidget(0, 3)
        self.topics_table.setHorizontalHeaderLabels(['Topic name', 'Hz', 'Bandwidth'])
        self.topics_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.topics_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.topics_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.topics_table, 3, 0, 3, 1)

        # Node 자원 사용 테이블
        self.nodes_table = QTableWidget(0, 3)
        self.nodes_table.setHorizontalHeaderLabels(['Node name', 'CPU (%)', 'Ram'])
        self.nodes_table.horizontalHeader().setSectionResizeMode(0, QHeaderView.Stretch)
        self.nodes_table.horizontalHeader().setSectionResizeMode(1, QHeaderView.ResizeToContents)
        self.nodes_table.horizontalHeader().setSectionResizeMode(2, QHeaderView.ResizeToContents)
        self.layout.addWidget(self.nodes_table, 3, 1, 3, 1)

        # GPU 프로세스 테이블
        self.gpu_proc_table = QTableWidget(0, 10)
        self.gpu_proc_table.setHorizontalHeaderLabels([
            'pid', 'proc_name', 'type (C/G)', 'sm(%)', 'mem(%)',
            'enc(%)', 'dec(%)', 'jpg(%)', 'ofa(%)', 'command'
        ])
        for i in range(0, 9):
            self.gpu_proc_table.horizontalHeader().setSectionResizeMode(i, QHeaderView.ResizeToContents)
        self.gpu_proc_table.horizontalHeader().setSectionResizeMode(9, QHeaderView.Stretch)
        self.layout.addWidget(self.gpu_proc_table, 7, 0, 3, 2)

        self.setLayout(self.layout)

if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal_handler)
    app = QApplication(sys.argv)
    window = RosMonitor()
    window.show()
    sys.exit(app.exec())
