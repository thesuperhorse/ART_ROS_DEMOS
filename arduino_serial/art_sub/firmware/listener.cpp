#include <ros.h>
#include <std_msgs/Float32.h>

#include <Arduino.h>

ros::NodeHandle nh;

float count = 0;
std_msgs::Float32 chat_msg;

ros::Publisher chatter("chatter", &chat_msg);
void sub_cb ( const std_msgs::Float32& cmd_msg ){ 
  chat_msg.data = 3 * cmd_msg.data * cmd_msg.data;
  chatter.publish(&chat_msg);
}
ros::Subscriber<std_msgs::Float32> sub("arduino", &sub_cb);


void setup()
{
  Serial.begin(57600);
  nh.initNode();
  nh.subscribe(sub);
  nh.advertise(chatter);
}

void loop()
{
  nh.spinOnce();
  delay(1000);
  count++;
}
