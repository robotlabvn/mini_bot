#include "ros/ros.h"
#include "std_msgs/Empty.h"
int main(int argc, char **argv)
{
	// initial ros with node name "talker" and node handle
	ros::init (argc, argv, "talker");
	ros::NodeHandle n;

	//Create publisher
	ros::Publisher chatter_pub = n.advertise<std_msgs::Empty>("toggle_led", 1000);
	ros::Rate loop_rate(10);

	while (ros::ok())
	{
		std_msgs::Empty msg;
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
