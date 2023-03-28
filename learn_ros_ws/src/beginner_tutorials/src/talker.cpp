#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "talker_node");

  ros::NodeHandle nh;
  
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    
    ss << "hello humanity, I am robot base on ROS! " << count;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());
    
    chatter_pub.publish(msg);

    ros::spinOnce(); // 如果此节点需要订阅其他话题消息，为了消息回调起作用，需要调用此方法
    loop_rate.sleep();
    count++;
  }


  return 0;
}
