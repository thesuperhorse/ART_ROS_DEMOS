#include "ros/ros.h"
#include "beginner_tutorials/AddTwoFloats.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_floats_client");
  if (argc != 3)
  {
    ROS_INFO_STREAM("usage: add_two_floats_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<beginner_tutorials::AddTwoFloats>("add_two_floats");
  beginner_tutorials::AddTwoFloats srv;
  srv.request.a = atof(argv[1]);
  srv.request.b = atof(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO_STREAM("Sum: " << (float)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_floats");
    return 1;
  }

  return 0;
}
