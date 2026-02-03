#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <std_msgs/UInt8.h>

enum MotionCommand
{
    DIAM = 0,
    MAJU = 1,
    MAJU_SERONG_KIRI = 2,
    MAJU_SERONG_KANAN = 3,
    JALAN_KEKIRI = 4,
    JALAN_KEKANAN = 5,
    MUNDUR = 6,
    KICK = 7
};

uint8_t motion_command = DIAM;
geometry_msgs::Point ball;

void motionCallback(const std_msgs::UInt8::ConstPtr &msg)
{
    motion_command = msg->data;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "vision_node");

    ros::NodeHandle nh;

    ros::Publisher vision_pub = nh.advertise<geometry_msgs::Point>("/vision/ball_position", 1);

    nh.param("ball_x", ball.x, 15.0);
    nh.param("ball_y", ball.y, 20.0);

    ros::Rate loop_rate(1);

    while (ros::ok())
    {
        vision_pub.publish(ball);
        loop_rate.sleep();
    }
    return 0;
}
