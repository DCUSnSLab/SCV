#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

class GazeboOdomNode : public rclcpp::Node
{
public:
    GazeboOdomNode() : Node("gazebo_odom_node")
    {
        // Parameters
        this->declare_parameter<std::string>("input_topic", "/ackermann_like_controller/odom");
        this->declare_parameter<std::string>("output_topic", "/odom");
        this->declare_parameter<std::string>("odom_frame_id", "odom");
        this->declare_parameter<std::string>("base_frame_id", "base_link");
        this->declare_parameter<bool>("publish_tf", true);

        // Get parameters
        input_topic_ = this->get_parameter("input_topic").as_string();
        output_topic_ = this->get_parameter("output_topic").as_string();
        odom_frame_id_ = this->get_parameter("odom_frame_id").as_string();
        base_frame_id_ = this->get_parameter("base_frame_id").as_string();
        publish_tf_ = this->get_parameter("publish_tf").as_bool();

        // Initialize TF broadcaster
        if (publish_tf_) {
            tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        }

        // Create subscriber
        odom_subscriber_ = this->create_subscription<nav_msgs::msg::Odometry>(
            input_topic_, 10,
            std::bind(&GazeboOdomNode::odomCallback, this, std::placeholders::_1));

        // Create publisher
        odom_publisher_ = this->create_publisher<nav_msgs::msg::Odometry>(output_topic_, 10);

        RCLCPP_INFO(this->get_logger(), "Gazebo Odom Node started");
        RCLCPP_INFO(this->get_logger(), "Subscribing to: %s", input_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing to: %s", output_topic_.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing TF: %s", publish_tf_ ? "true" : "false");
    }

private:
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        // Create output odometry message
        nav_msgs::msg::Odometry output_odom = *msg;
        
        // Update frame IDs
        output_odom.header.frame_id = odom_frame_id_;
        output_odom.child_frame_id = base_frame_id_;
        
        // Publish odometry topic
        odom_publisher_->publish(output_odom);

        // Publish TF transform if enabled
        if (publish_tf_) {
            geometry_msgs::msg::TransformStamped odom_tf;
            
            odom_tf.header.stamp = msg->header.stamp;
            odom_tf.header.frame_id = odom_frame_id_;
            odom_tf.child_frame_id = base_frame_id_;
            
            // Copy position
            odom_tf.transform.translation.x = msg->pose.pose.position.x;
            odom_tf.transform.translation.y = msg->pose.pose.position.y;
            odom_tf.transform.translation.z = msg->pose.pose.position.z;
            
            // Copy orientation
            odom_tf.transform.rotation = msg->pose.pose.orientation;
            
            tf_broadcaster_->sendTransform(odom_tf);
        }
    }

    // Parameters
    std::string input_topic_;
    std::string output_topic_;
    std::string odom_frame_id_;
    std::string base_frame_id_;
    bool publish_tf_;

    // ROS components
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscriber_;
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<GazeboOdomNode>());
    rclcpp::shutdown();
    return 0;
}