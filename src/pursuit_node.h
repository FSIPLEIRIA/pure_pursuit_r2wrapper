/** ==========================================
* @title: Pursuit Node Class
* @class: This class is meant to be the interface with ros2 functionalities as such it derives node, Here you will find all the boilerplate for node common node behaviour.
* @author: João Vieira
* @date:   2023-06-14
========================================== **/


#ifndef PURSUIT_NODE_H_
#define PURSUIT_NODE_H_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/executors.hpp>
#include <string>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/executors.hpp>

#include <geometry_msgs/msg/detail/pose2_d__struct.hpp>
#include <geometry_msgs/msg/detail/pose__struct.hpp>

#include <lart_common/Point.h>
#include <lart_common/Path.h>

#include <path_tracker/PathTracker.h>
#include <path_tracker/Math.h>


#define PURSUIT_NODE_NAME "PursuitNode"
#define PARAMS_FREQUENCY "frequency"
#define PARAMS_TOPIC_WAYPOINT "wp_topic"
#define PARAMS_SPEED "speed"

class PursuitNode : public rclcpp::Node{
	public: 
		PursuitNode();
		virtual ~PursuitNode() = default;
	 	double g_Speed();
		int g_Frequency();
        void s_Speed(double speed);
		void s_Frequency(int frequency);
		std::string g_WaypointTopic();
	protected:
		//publisher 
		
		void callee_PointCallback(lart_common::Point incoming_point); 
		double m_speed=0.0;
		int m_frequency=0; 
		std::string m_waypoint_topic;
		
		path_tracker::PathTracker m_path_tracker;
	//private:
		//rclcpp::Subscription<geometry_msgs::msg::Pose2D>::SharedPtr m_waypoint_publisher;
		//rclcpp::Publish::SharedPointer m_waypoint_publisher;
};
#endif // PURSUIT_NODE_H_