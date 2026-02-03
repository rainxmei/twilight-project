#include <ros/ros.h>
#include <robot_soccer/gameState.h>
#include <std_msgs/UInt8.h>

enum GameState
{
    IDLE = 0,
    READY = 1,
    START = 2
};

uint8_t game_state = IDLE;
ros::Publisher game_state_pub;

bool gameStatecallBack(robot_soccer::gameState::Request &req, robot_soccer::gameState::Response &res)
{
    game_state = req.state;

    std_msgs::UInt8 msg;
    msg.data = game_state;
    game_state_pub.publish(msg);

    res.success = true;
    switch (game_state)
    {
    case IDLE:
        res.message = "Game State: IDLE";
        break;
    case READY:
        res.message = "Game State: READY";
        break;
    case START:
        res.message = "Game State: START";
        break;
    }

    ROS_INFO("%s", res.message.c_str());
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "game_controller_node");
    ros::NodeHandle nh;

    game_state_pub = nh.advertise<std_msgs::UInt8>("/game/state", 1, true);
    // true = menyimpan pesan terakhir yang dikirim ketika subscriber baru connect

    ros::ServiceServer service = nh.advertiseService("/game/set_state", gameStatecallBack);

    ros::Rate rate(1);
    while (ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
