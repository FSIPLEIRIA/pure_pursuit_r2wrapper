#include "pursuit_node.h"
#include <string>

PursuitNode::PursuitNode(): Node(PURSUIT_NODE_NAME){
	this->declare_parameter(PARAMS_FREQUENCY, 10);
	this->g_Frequency();
	this->declare_parameter(PARAMS_TOPIC_WAYPOINT, "/");
	this->g_WaypointTopic(); 
	//declare publisher
    // TODO: perform macro migration to core library so the whole pipeline is flexible
	//auto m_publisher = this->create_publisher<std::string>(m_waypoint_topic, 10);
	m_path_tracker.setRate(m_frequency);
	m_path_tracker.setSpeed(m_speed);
	
	
}
void PursuitNode::callee_PointCallback(lart_common::Point point){
	geometry_msgs::msg::Pose2D pose2d;
	pose2d.x = point.getX();
	pose2d.y = point.getY();

	//m_publisher->publish(pose2d);
}
int PursuitNode::g_Frequency(){
	m_frequency = this->get_parameter(PARAMS_FREQUENCY).as_int();
	return m_frequency;
}
double PursuitNode::g_Speed(){
	m_speed = this->get_parameter(PARAMS_SPEED).as_double();
	return m_speed;
}

std::string PursuitNode::g_WaypointTopic(){
	m_waypoint_topic = this->get_parameter(PARAMS_TOPIC_WAYPOINT).as_string();
	return m_waypoint_topic;
}


void PursuitNode::s_Speed(double speed){
	this->set_parameter(rclcpp::Parameter(PARAMS_SPEED, speed));
	m_speed = speed;

}
void PursuitNode::s_Frequency(int frequency){
	this->set_parameter(rclcpp::Parameter(PARAMS_FREQUENCY, frequency));
	m_frequency = frequency;
}