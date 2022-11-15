#include "ros/ros.h"
#include "std_msgs/String.h"

void Callback_func(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("Callback : [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "sub_node");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("topic", 1000, Callback_func);
	ros::spin();

	return 0;
}
