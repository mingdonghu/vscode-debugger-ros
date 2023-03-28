#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
 public:
  MinimalPublisher() : Node("minimal_publisher") {
    // create publisher handle
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
    // publisher logical bind timer , in period.
    timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::TimerCallback, this));
  }

 private:
  void TimerCallback() {
    auto message = std_msgs::msg::String();
    message.data = "Hello humanity!" + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

 private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t  count_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<MinimalPublisher>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
