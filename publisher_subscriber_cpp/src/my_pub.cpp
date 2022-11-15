#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"


const int freq = 10;

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pub_node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::String>("topic", 1000);
	ros::Rate rate(freq);

	int count = 0;

	while (ros::ok())
	{
		std_msgs::String msg;
		std::stringstream ss;

		ss << "Message : " << count;

		msg.data = ss.str();
		
		ROS_INFO("%s", msg.data.c_str());

		pub.publish(msg);
		
		ros::spinOnce();
		
		rate.sleep();
		
		++count;
	}
	return 0;
}
