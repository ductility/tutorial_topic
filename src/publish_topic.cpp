#include <iostream>
#include <string>

#include <termios.h>
#include <unistd.h>

#include <ros/ros.h>

#include <std_msgs/Int16.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;
  ros::Publisher chatter_pub = nh.advertise<std_msgs::Int16>("chatter", 1000);
  ros::Rate loop_rate(10);

  std::string input_string;
  std_msgs::Int16 msg;

  while (ros::ok())
  {    
    std::cout << "(-1 : Stop) Input Int Value: ";
    std::cin >> input_string;

    int value = std::stoi(input_string);

    if(value == -1)
    {
      break;
    }
    
    msg.data = value;

    // ROS_INFO("%d", msg);

    chatter_pub.publish(msg);

    ros::spinOnce();
  }

  return 0;
}
