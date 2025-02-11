    def __init__(self, parent=None):
        super().__init__(parent)
        
        self.sys_status_data = {
            'CPU Usage': 'N/A',
            'CPU Freq': 'N/A',
            'GPU Usage': 'N/A',
            'Memory': 'N/A',
        }

        # 이전에 구독된 토픽들을 저장할 집합
        self.previous_topics = set()
        self.subscribers = {}  # 각 토픽의 Subscriber 객체를 저장

        self.init_components()
        self.init_layout()
        self.init_msgs_sync()

    def init_msgs_sync(self):
        """Initialize the ROS subscribers"""
        self.sys_status_sub = rospy.Subscriber('/get_sys_status', Float32MultiArray, self.sys_status_callback)
        self.topic_hzbw_sub = rospy.Subscriber('/topic_hzbw', String, self.topic_hzbw_callback)

        # 타이머를 사용해 퍼블리시된 토픽을 주기적으로 확인
        self.topic_timer = rospy.Timer(rospy.Duration(1), self.update_resource_topics)

    def update_resource_topics(self, event):
        """Check for topic additions/removals and update subscribers dynamically"""
        # 현재 퍼블리시된 모든 토픽 가져오기
        published_topics = rospy.get_published_topics()

        # '/node_resource_monitor'로 시작하는 토픽 필터링
        current_topics = {topic for topic, topic_type in published_topics if topic.startswith('/node_resource_monitor')}

        # 추가된 토픽 확인
        added_topics = current_topics - self.previous_topics
        # 삭제된 토픽 확인
        removed_topics = self.previous_topics - current_topics

        # 추가된 토픽 처리
        for topic in added_topics:
            rospy.loginfo(f"New topic detected: {topic}")
            self.subscribers[topic] = rospy.Subscriber(topic, String, self.node_resource_callback)

        # 삭제된 토픽 처리
        for topic in removed_topics:
            rospy.loginfo(f"Topic removed: {topic}")
            if topic in self.subscribers:
                self.subscribers[topic].unregister()
                del self.subscribers[topic]

        # 이전 토픽 목록 업데이트
        self.previous_topics = current_topics

    def node_resource_callback(self, msg):
        """Callback for node resource monitoring topics"""
        try:
            # JSON 데이터를 파싱하여 더미 값 출력
            resource_data = json.loads(msg.data)
            node_name = resource_data.get("node", "Unknown")
            cpu = resource_data.get("cpu", 0.0)
            ram = resource_data.get("mem", 0.0)

            rospy.loginfo(f"Node: {node_name}, CPU: {cpu}%, RAM: {ram} bytes")

            # 노드 리소스 테이블 업데이트
            row_count = self.node_resource_table.rowCount()
            for row in range(row_count):
                if self.node_resource_table.item(row, 0).text() == node_name:
                    self.node_resource_table.setItem(row, 1, QTableWidgetItem(f'{cpu:.2f}%'))
                    self.node_resource_table.setItem(row, 2, QTableWidgetItem(f'{ram} bytes'))
                    return

            # 새로운 노드 추가
            row = self.node_resource_table.rowCount()
            self.node_resource_table.insertRow(row)
            self.node_resource_table.setItem(row, 0, QTableWidgetItem(node_name))
            self.node_resource_table.setItem(row, 1, QTableWidgetItem(f'{cpu:.2f}%'))
            self.node_resource_table.setItem(row, 2, QTableWidgetItem(f'{ram} bytes'))
        except json.JSONDecodeError as e:
            rospy.logwarn(f"Failed to parse resource monitor data: {e}")
