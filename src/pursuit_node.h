/** ==========================================
* @title: Pursuit Node Class
* @class: This class is meant to be the interface with ros2 functionalities as such it derives node, Here you will find all the boilerplate for node common node behaviour.
* @author: João Vieira
* @date:   2023-06-14
========================================== **/


#ifndef PURSUIT_NODE_H_
#define PURSUIT_NODE_H_
#include <geometry_msgs/msg/detail/pose__struct.hpp>
#include <geometry_msgs/msg/detail/pose2_d__struct.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/executors.hpp>
#include <string>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/executors.hpp>
#include <lart_common/Point.h>
#include <lart_common/Path.h>

#define PURSUIT_NODE_NAME "PursuitNode"
#define PARAMS_FREQUENCY "frequency"
#define PARAMS_TOPIC_WAYPOINT "wp_topic"


class PursuitNode : public rclcpp::Node{
	public: 
		PursuitNode();
		virtual ~PursuitNode() = default;
		
	 	double g_Speed();
		int g_Frequency();
        int s_Speed(double speed);
		int s_Frequency(int frequency);

	protected:
		double m_speed=0.0;
		int m_frequency=0; 
};
#endif // PURSUIT_NODE_H_