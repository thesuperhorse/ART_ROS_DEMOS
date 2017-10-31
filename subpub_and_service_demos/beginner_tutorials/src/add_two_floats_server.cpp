#include "ros/ros.h"
#include "beginner_tutorials/AddTwoFloats.h"

bool add(beginner_tutorials::AddTwoFloats::Request  &req,
         beginner_tutorials::AddTwoFloats::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%f, y=%f", (float)req.a, (float)req.b);
  ROS_INFO_STREAM("sending back response: [" << (float)res.sum << "]");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_floats_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_floats", add);
  ROS_INFO_STREAM("Ready to add two floats.");
  ros::spin();

  return 0;
}
