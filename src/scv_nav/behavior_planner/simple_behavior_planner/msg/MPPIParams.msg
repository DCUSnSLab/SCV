# MPPI Controller parameters for dynamic adjustment
int32 num_samples           # Number of trajectory samples
float32 max_linear_vel      # Maximum linear velocity (m/s)
float32 max_angular_vel     # Maximum angular velocity (rad/s)
float32 lambda_             # Temperature parameter
float32 obstacle_penalty_weight  # Obstacle avoidance weight
float32 goal_weight         # Goal tracking weight