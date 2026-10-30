use std::cmp::Ordering;
use std::collections::{BinaryHeap, HashMap};

#[derive(PartialEq)]
struct Open {
    f: f64,
    id: i64,
}

impl Eq for Open {}

impl Ord for Open {
    // Reversed so that BinaryHeap, a max-heap, pops the smallest f first.
    fn cmp(&self, other: &Self) -> Ordering {
        other.f.total_cmp(&self.f)
    }
}

impl PartialOrd for Open {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

/// The SD map as a graph of node positions and edge lengths.
pub struct Graph {
    pos: HashMap<i64, (f64, f64)>,
    neighbors: HashMap<i64, Vec<(i64, f64)>>,
}

impl Graph {
    /// `nodes` are (id, x, y), `edges` are (from, to, length).
    pub fn new(
        nodes: impl IntoIterator<Item = (i64, f64, f64)>,
        edges: impl IntoIterator<Item = (i64, i64, f64)>,
    ) -> Self {
        let pos = nodes.into_iter().map(|(id, x, y)| (id, (x, y))).collect();
        // OSM ways are stored in drawing order; the robot can drive a sidewalk both ways.
        let mut neighbors: HashMap<i64, Vec<(i64, f64)>> = HashMap::new();
        for (from, to, length) in edges {
            neighbors.entry(from).or_default().push((to, length));
            neighbors.entry(to).or_default().push((from, length));
        }
        Self { pos, neighbors }
    }

    pub fn nearest(&self, x: f64, y: f64) -> i64 {
        *self
            .pos
            .iter()
            .min_by(|a, b| {
                (a.1 .0 - x)
                    .hypot(a.1 .1 - y)
                    .total_cmp(&(b.1 .0 - x).hypot(b.1 .1 - y))
            })
            .unwrap()
            .0
    }

    /// Node ids of the shortest route from start to goal, or None if goal is unreachable.
    pub fn astar(&self, start: i64, goal: i64) -> Option<Vec<i64>> {
        let h = |id: i64| {
            let (a, b) = (self.pos[&id], self.pos[&goal]);
            (b.0 - a.0).hypot(b.1 - a.1)
        };
        let mut cost = HashMap::from([(start, 0.0)]);
        let mut parent = HashMap::new();
        let mut open = BinaryHeap::from([Open {
            f: h(start),
            id: start,
        }]);
        while let Some(Open { id, .. }) = open.pop() {
            if id == goal {
                let mut route = vec![goal];
                while let Some(&p) = parent.get(route.last().unwrap()) {
                    route.push(p);
                }
                route.reverse();
                return Some(route);
            }
            for &(next, length) in self.neighbors.get(&id).into_iter().flatten() {
                let c = cost[&id] + length;
                if c < cost.get(&next).copied().unwrap_or(f64::INFINITY) {
                    cost.insert(next, c);
                    parent.insert(next, id);
                    open.push(Open {
                        f: c + h(next),
                        id: next,
                    });
                }
            }
        }
        None
    }
}

#[cfg(test)]
mod tests {
    use super::Graph;

    // 1 - 2 - 4 is 2 m long; 1 - 3 - 4 is 4 m; 5 stands apart.
    fn diamond() -> Graph {
        Graph::new(
            [
                (1, 0.0, 0.0),
                (2, 1.0, 0.0),
                (3, 1.0, 2.0),
                (4, 2.0, 0.0),
                (5, 9.0, 9.0),
            ],
            [(1, 2, 1.0), (2, 4, 1.0), (1, 3, 2.0), (3, 4, 2.0)],
        )
    }

    #[test]
    fn takes_the_shorter_branch() {
        assert_eq!(diamond().astar(1, 4), Some(vec![1, 2, 4]));
    }

    #[test]
    fn drives_an_edge_against_its_drawing_order() {
        assert_eq!(diamond().astar(4, 1), Some(vec![4, 2, 1]));
    }

    #[test]
    fn reports_an_unreachable_goal() {
        assert_eq!(diamond().astar(1, 5), None);
    }

    #[test]
    fn snaps_to_the_nearest_node() {
        assert_eq!(diamond().nearest(1.1, 1.8), 3);
    }
}
