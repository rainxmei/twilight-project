#include <ros/ros.h>
#include <std_msgs/UInt8.h>
#include <actionlib/client/simple_action_client.h>
#include <robot_soccer/MotionAction.h>
#include <geometry_msgs/Point.h>

enum GameState
{
    IDLE = 0,
    READY = 1,
    START = 2
};

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

geometry_msgs::Point ball_pos;
uint8_t game_state = IDLE;

bool ball_received = false;

void gameStateCallback(const std_msgs::UInt8::ConstPtr &msg)
{
    // simpan hasil subscribe ke variable
    game_state = msg->data;
}

void visionCallback(const geometry_msgs::Point::ConstPtr &msg)
{
    ball_pos = *msg;
    ball_received = true;
    ROS_INFO_THROTTLE(1.0, "x: %.1f | y: %.1f",
                      ball_pos.x, ball_pos.y);
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "decision_node");
    ros::NodeHandle nh;

    ros::Subscriber game_state_sub = nh.subscribe("/game/state", 1, gameStateCallback);
    ros::Subscriber vision_position_sub = nh.subscribe("/vision/ball_position", 1, visionCallback);

    actionlib::SimpleActionClient<robot_soccer::MotionAction> as("motion_action", true);

    as.waitForServer();

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ros::spinOnce();

        if (!ball_received)
        {
            ROS_WARN_THROTTLE(1.0, "bola tidak terdeteksi");
            loop_rate.sleep();
            continue;
        }

        robot_soccer::MotionGoal goal;
        bool send = false;

        switch (game_state)
        {
        case IDLE:
            goal.command = DIAM;
            ROS_INFO_THROTTLE(1.0, "IDLE");
            send = true;
            break;

        case READY:
            goal.command = DIAM;
            ROS_INFO_THROTTLE(1.0, "Jalan ditempat!");
            send = true;
            break;

        case START:

            if (ball_pos.y > 0 && ball_pos.x >= 10 && ball_pos.x <= 20)
            {
                goal.command = MAJU;
                ROS_INFO_THROTTLE(1.0, "MAJU");
            }
            else if (ball_pos.y == 0 && (ball_pos.x == 13 || ball_pos.x == 17))
            {
                goal.command = KICK;
                ROS_INFO_THROTTLE(1.0, "KICK");
            }
            else if (ball_pos.y > 0 && ball_pos.x <= 10)
            {
                goal.command = MAJU_SERONG_KIRI;
                ROS_INFO_THROTTLE(1.0, "MAJU SERONG KIRI");
            }
            else if (ball_pos.y > 0 && ball_pos.x >= 20)
            {
                goal.command = MAJU_SERONG_KANAN;
                ROS_INFO_THROTTLE(1.0, "MAJU SERONG KANAN");
            }
            else if (ball_pos.y <= 0 && ball_pos.x < 17)
            {
                goal.command = JALAN_KEKIRI;
                ROS_INFO_THROTTLE(1.0, "JALAN KEKIRI");
            }
            else if (ball_pos.y <= 0 && ball_pos.x > 13)
            {
                goal.command = JALAN_KEKANAN;
                ROS_INFO_THROTTLE(1.0, "JALAN KEKANAN");
            }
            else
            {
                goal.command = DIAM;
                ROS_INFO_THROTTLE(1.0, "DIAM");
            }

            send = true;
            break;
        }

        if (send)
        {
            as.sendGoal(goal);
            as.waitForResult();
        }

        loop_rate.sleep();
    }

    return 0;
}