#include "ros/ros.h"
#include "std_msgs/Float32.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Float32>("chatter", 1000);

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  float count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::Float32 msg;

    msg.data += count;

    ROS_INFO_STREAM("Writing a Simple Publisher and Subscriber (C++)Msg: " << msg.data);

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    count++;
  }


  return 0;
}
