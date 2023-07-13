/** ==========================================
* @title: Main Class
* @class: The main class for a profile environment context. 
* @author: João Vieira
* @date:   2023-06-14
========================================== **/

#include <cstdio>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/rclcpp.hpp>
#include "pursuit_node.h"
//include odometry message
int main(int argc, char ** argv){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<PursuitNode>());

	rclcpp::shutdown();

	return 0;
}