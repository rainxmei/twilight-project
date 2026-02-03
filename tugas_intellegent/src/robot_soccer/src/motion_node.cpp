#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <robot_soccer/MotionAction.h>
#include <geometry_msgs/Point.h>

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

class MotionServer
{
private:
    ros::NodeHandle nh;
    actionlib::SimpleActionServer<robot_soccer::MotionAction> as;

    ros::Publisher vision_pub;
    ros::Timer vision_timer;
    geometry_msgs::Point ball;

public:
    MotionServer() : as(nh, "motion_action", boost::bind(&MotionServer::executeCB, this, _1), false)
    {
        nh.param("ball_x", ball.x, 15.0);
        nh.param("ball_y", ball.y, 20.0);

        vision_pub = nh.advertise<geometry_msgs::Point>("/vision/ball_position", 1);
        vision_timer =
            nh.createTimer(ros::Duration(0.5),
                           &MotionServer::publishBall, this);

        as.start();
        ros::Duration(0.5).sleep();
        vision_pub.publish(ball);
        ROS_INFO("Motion action Server Started");
    }

    void publishBall(const ros::TimerEvent &)
    {
        vision_pub.publish(ball);
        ROS_INFO_THROTTLE(1.0,
                          "[VISION SIM] ball(%.1f, %.1f)",
                          ball.x, ball.y);
    }

    void executeCB(const robot_soccer::MotionGoalConstPtr &goal)
    {
        robot_soccer::MotionFeedback feedback;
        robot_soccer::MotionResult result;

        ROS_INFO("command diterima: %d", goal->command);

        feedback.status_message = "Motion Started";
        as.publishFeedback(feedback);

        ros::Duration(1.0).sleep();

        switch (goal->command)
        {
        case DIAM:
            break;

        case MAJU:
            ball.y -= 1;
            break;

        case MAJU_SERONG_KIRI:
            ball.y -= 1;
            ball.x += 1;
            break;

        case MAJU_SERONG_KANAN:
            ball.y -= 1;
            ball.x -= 1;
            break;

        case JALAN_KEKIRI:
            ball.x += 1;
            break;

        case JALAN_KEKANAN:
            ball.x -= 1;
            break;

        case KICK:
            ball.x = 17;
            ball.y = 20;
            break;
        }

        if (ball.x <= 0)
            ball.x = 0;

        if (ball.y <= 0)
            ball.y = 0;

        if (ball.x >= 30)
            ball.x = 30;

        if (ball.y >= 30)
            ball.y = 30;

        vision_pub.publish(ball);

        ROS_INFO("ball(%.1f, %.1f)", ball.x, ball.y);
        result.success = true;
        as.setSucceeded(result);
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "motion_action_server");
    MotionServer server;
    ros::spin();
    return 0;
}
