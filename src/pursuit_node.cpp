#include "pursuit_node.h"
PursuitNode::PursuitNode(): Node(PURSUIT_NODE_NAME){
	this->declare_parameter(PARAMS_FREQUENCY, 10);
	this->g_Frequency();
	this->declare_parameter(PARAMS_TOPIC_WAYPOINT, "/");
	this->
}