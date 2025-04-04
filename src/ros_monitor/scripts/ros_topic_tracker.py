import rosgraph

def find_topic_connections(target_topic):
    """
    target_topic: 문자열 (예: '/topic_c')
    return: (publishers, subscribers)
        publishers = [노드명1, 노드명2, ...]
        subscribers = [노드명A, 노드명B, ...]
    """
    master = rosgraph.Master('/ros_topic_tracker')
    pubs, subs, _ = master.getSystemState()

    publishers = []
    subscribers = []

    for topic, nodes in pubs:
        if topic == target_topic:
            publishers = nodes

    for topic, nodes in subs:
        if topic == target_topic:
            subscribers = nodes

    return publishers, subscribers


def find_node_connections(node_name):
    """
    node_name: 문자열 (예: 'nodeA')
    return: (pub_topics, sub_topics)
        pub_topics = [해당 노드가 publish 중인 토픽 목록]
        sub_topics = [해당 노드가 subscribe 중인 토픽 목록]
    """
    master = rosgraph.Master('/ros_topic_tracker')
    pubs, subs, _ = master.getSystemState()

    pub_topics = []
    sub_topics = []

    for topic, nodes in pubs:
        if node_name in nodes:
            pub_topics.append(topic)
    for topic, nodes in subs:
        if node_name in nodes:
            sub_topics.append(topic)

    return pub_topics, sub_topics
