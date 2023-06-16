#include "pursuit_node.h"
PursuitNode::PursuitNode(): Node(PURSUIT_NODE_NAME){
	this->declare_parameter(PARAMS_FREQUENCY, 10);
	this->g_Frequency();
	this->declare_parameter(PARAMS_TOPIC_WAYPOINT, "/");
	this->g_WaypointTopic(); 
	
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