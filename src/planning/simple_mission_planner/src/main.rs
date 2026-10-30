mod route;

use std::collections::HashMap;

use rclrs::*;
use ros_env::geometry_msgs::msg::{Pose, PoseStamped};
use ros_env::nav_msgs::msg::{Odometry, Path};
use ros_env::simple_sd_map_msgs::msg::SdMap;
use ros_env::std_msgs::msg::Header;

use route::Graph;

struct MissionPlanner {
    node: Node,
    route_pub: Publisher<Path>,
    map: Option<(SdMap, Graph)>,
    pose: Option<Pose>,
}

impl MissionPlanner {
    fn on_map(&mut self, msg: SdMap) {
        let graph = Graph::new(
            msg.nodes.iter().map(|n| (n.id, n.x, n.y)),
            msg.edges.iter().map(|e| (e.from_id, e.to_id, e.length)),
        );
        self.map = Some((msg, graph));
    }

    fn on_odom(&mut self, msg: Odometry) {
        self.pose = Some(msg.pose.pose);
    }

    fn on_goal(&mut self, goal: PoseStamped) {
        if let Some(route) = self.plan(goal) {
            self.route_pub.publish(route).unwrap();
        }
    }

    fn plan(&self, goal: PoseStamped) -> Option<Path> {
        let logger = self.node.logger();
        let (Some((map, graph)), Some(pose)) = (&self.map, &self.pose) else {
            log_warn!(logger, "goal ignored: no sd_map or pose yet");
            return None;
        };
        if goal.header.frame_id != map.header.frame_id {
            log_warn!(
                logger,
                "goal ignored: frame {}, sd_map is in {}",
                goal.header.frame_id,
                map.header.frame_id
            );
            return None;
        }
        let start = graph.nearest(pose.position.x, pose.position.y);
        let end = graph.nearest(goal.pose.position.x, goal.pose.position.y);
        let Some(ids) = graph.astar(start, end) else {
            log_warn!(logger, "no route from node {start} to node {end}");
            return None;
        };
        log_info!(logger, "route: {} nodes, {start} -> {end}", ids.len());
        let mut header = goal.header.clone();
        header.stamp = self.node.get_clock().now().to_ros_msg().unwrap();
        Some(to_path(header, map, &ids, goal.pose))
    }
}

fn to_path(header: Header, map: &SdMap, ids: &[i64], goal: Pose) -> Path {
    let by_id: HashMap<i64, _> = map.nodes.iter().map(|n| (n.id, n)).collect();
    let mut poses: Vec<PoseStamped> = ids
        .iter()
        .map(|id| {
            let mut p = PoseStamped {
                header: header.clone(),
                ..Default::default()
            };
            p.pose.position.x = by_id[id].x;
            p.pose.position.y = by_id[id].y;
            p.pose.orientation.w = 1.0;
            p
        })
        .collect();
    poses.push(PoseStamped {
        header: header.clone(),
        pose: goal,
    });
    Path { header, poses }
}

/// Owns the subscriptions; the worker runs their callbacks one at a time on the MissionPlanner.
struct MissionPlannerNode {
    _map_sub: WorkerSubscription<SdMap, MissionPlanner>,
    _odom_sub: WorkerSubscription<Odometry, MissionPlanner>,
    _goal_sub: WorkerSubscription<PoseStamped, MissionPlanner>,
}

impl MissionPlannerNode {
    fn new(executor: &Executor) -> Result<Self, RclrsError> {
        let node = executor.create_node("simple_mission_planner")?;
        // sd_map and route change rarely; transient local hands them to late joiners.
        let route_pub = node.create_publisher("~/output/route".reliable().transient_local())?;
        let worker = node.create_worker(MissionPlanner {
            node: node.clone(),
            route_pub,
            map: None,
            pose: None,
        });
        Ok(Self {
            _map_sub: worker.create_subscription(
                "~/input/sd_map".reliable().transient_local(),
                MissionPlanner::on_map,
            )?,
            _odom_sub: worker.create_subscription("~/input/odometry", MissionPlanner::on_odom)?,
            _goal_sub: worker.create_subscription("~/input/goal_pose", MissionPlanner::on_goal)?,
        })
    }
}

fn main() -> Result<(), RclrsError> {
    let context = Context::default_from_env()?;
    let mut executor = context.create_basic_executor();
    let _planner = MissionPlannerNode::new(&executor)?;
    executor.spin(SpinOptions::default()).first_error()
}
