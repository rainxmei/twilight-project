#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

enum class Status
{
    SUCCESS,
    FAILURE,
    RUNNING
};

class Node
{
public:
    virtual Status tick() = 0;
    virtual ~Node() {}
};

class Sequence : public Node
{
private:
    std::vector<Node *> children;

public:
    Sequence(const std::vector<Node *> &nodes) : children(nodes) {}

    Status tick() override
    {
        for (Node *child : children)
        {
            Status s = child->tick();

            if (s == Status::FAILURE)
                return Status::FAILURE;

            if (s == Status::RUNNING)
                return Status::RUNNING;
        }

        return Status::SUCCESS;
    }
};

class Selector : public Node
{
private:
    std::vector<Node *> children;

public:
    Selector(const std::vector<Node *> &nodes) : children(nodes) {}

    Status tick() override
    {
        for (Node *child : children)
        {
            Status s = child->tick();

            if (s == Status::SUCCESS)
                return Status::SUCCESS;

            if (s == Status::RUNNING)
                return Status::RUNNING;
        }

        return Status::FAILURE;
    }
};

class SeeBall : public Node
{
public:
    bool *ballVisible; // pointer supaya bisa berubah dari luar

    SeeBall(bool *visible) : ballVisible(visible) {}

    Status tick() override
    {
        if (*ballVisible)
        {
            std::cout << "[Condition] Ball Visible\n";
            return Status::SUCCESS;
        }
        else
        {
            std::cout << "[Condition] Ball Not Visible\n";
            return Status::FAILURE;
        }
    }
};

class WalkToBall : public Node
{
private:
    int step = 0;

public:
    Status tick() override
    {
        std::cout << "[Action] Walking to ball... step " << step << "\n";

        step++;

        if (step < 3)
            return Status::RUNNING;

        std::cout << "[Action] Reached Ball!\n";
        return Status::SUCCESS;
    }
};

class ScanForBall : public Node
{
private:
    int scanCount = 0;
    bool *ballVisible;

public:
    ScanForBall(bool *visible) : ballVisible(visible) {}

    Status tick() override
    {
        std::cout << "[Action] Scanning for ball...\n";

        scanCount++;

        if (scanCount >= 2)
        {
            std::cout << "[Action] Ball Found!\n";
            *ballVisible = true;
            return Status::SUCCESS;
        }

        return Status::RUNNING;
    }
};

int main(int argc, char const *argv[])
{
    bool ballVisible = false;

    SeeBall seeBall(&ballVisible);
    WalkToBall walkToBall;
    ScanForBall scan(&ballVisible);

    Sequence approach({&seeBall, &walkToBall});
    Selector root({&approach, &scan});

    while (true)
    {
        std::cout << "-------------------\n";

        Status result = root.tick();

        if (result == Status::SUCCESS)
            std::cout << "ROOT: SUCCESS\n";
        else if (result == Status::FAILURE)
            std::cout << "ROOT: FAILURE\n";
        else
            std::cout << "ROOT: RUNNING\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    return 0;
}
