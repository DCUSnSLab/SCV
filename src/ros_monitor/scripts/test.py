import rosgraph
import rosnode

master = rosgraph.Master('/rqt_graph')

state = master.getSystemState()
publishers, subscribers, _ = state

for topic, nodes in publishers:
    for node in nodes:
        print(f"{node} publishes {topic}")

for topic, nodes in subscribers:
    for node in nodes:
        print(f"{node} subscribes {topic}")
