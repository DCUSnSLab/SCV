#!/usr/bin/env python3
import rospy
import rosgraph

def find_topic_connections(target_topic):
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

if __name__ == "__main__":
    rospy.init_node("ros_topic_tracker", anonymous=True)

    target_topic = "/topic_c"

    pubs, subs = find_topic_connections(target_topic)

    print(f"\n[Nodes publishing to {target_topic}]:")
    for p in pubs:
        print(f"  ⤷ {p}")
        pub_topics, sub_topics = find_node_connections(p)
        print(f"     └ Publishes: {pub_topics}")
        print(f"     └ Subscribes: {sub_topics}")

    print(f"\n[Nodes subscribing to {target_topic}]:")
    for s in subs:
        print(f"  ⤷ {s}")
        pub_topics, sub_topics = find_node_connections(s)
        print(f"     └ Publishes: {pub_topics}")
        print(f"     └ Subscribes: {sub_topics}")
