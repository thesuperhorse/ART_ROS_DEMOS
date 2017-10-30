#include "ros/ros.h"
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("arduino", 1000);
  ros::Rate loop_rate(30000);

  float count = 5;
  while (ros::ok())
  {
    std_msgs::Float32 msg;
    msg.data = count;

    ROS_INFO_STREAM(msg.data);

    
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    //++count;
  }


  return 0;
}
