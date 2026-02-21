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

struct Blackboard
{
    bool ballVisible = false;
    float ballDistance = 0.0;
};

class Node
{
public:
    virtual Status tick(Blackboard &bb) = 0;
    virtual ~Node() = default;
};

class Sequence : public Node
{
private:
    std::vector<Node *> children;

public:
    Sequence(std::vector<Node *> nodes)
        : children(nodes) {}

    Status tick(Blackboard &bb) override
    {

        for (auto child : children)
        {
            Status s = child->tick(bb);

            if (s != Status::SUCCESS)
                return s;
        }

        return Status::SUCCESS;
    }
};

class Selector : public Node
{
private:
    std::vector<Node *> children;

public:
    Selector(std::vector<Node *> nodes)
        : children(nodes) {}

    Status tick(Blackboard &bb) override
    {

        for (auto child : children)
        {
            Status s = child->tick(bb);

            if (s == Status::SUCCESS)
                return Status::SUCCESS;

            if (s == Status::RUNNING)
                return Status::RUNNING;
        }

        return Status::FAILURE;
    }
};

class MemorySequence : public Node
{
private:
    std::vector<Node *> children;
    int currentIndex = 0;

public:
    MemorySequence(std::vector<Node *> nodes)
        : children(nodes) {}

    Status tick(Blackboard &bb) override
    {

        for (; currentIndex < children.size(); currentIndex++)
        {

            Status s = children[currentIndex]->tick(bb);

            if (s == Status::RUNNING)
                return Status::RUNNING;

            if (s == Status::FAILURE)
            {
                currentIndex = 0;
                return Status::FAILURE;
            }
        }

        currentIndex = 0;
        return Status::SUCCESS;
    }
};

class Parallel : public Node
{
private:
    std::vector<Node *> children;

public:
    Parallel(std::vector<Node *> nodes)
        : children(nodes) {}

    Status tick(Blackboard &bb) override
    {

        bool allSuccess = true;

        for (auto child : children)
        {

            Status s = child->tick(bb);

            if (s == Status::FAILURE)
                return Status::FAILURE;

            if (s == Status::RUNNING)
                allSuccess = false;
        }

        if (allSuccess)
            return Status::SUCCESS;

        return Status::RUNNING;
    }
};

class SeeBall : public Node
{
public:
    Status tick(Blackboard &bb) override
    {

        if (bb.ballVisible)
        {
            std::cout << "[Condition] Ball Visible\n";
            return Status::SUCCESS;
        }

        std::cout << "[Condition] Ball NOT Visible\n";
        return Status::FAILURE;
    }
};

class WalkToBall : public Node
{
private:
    int step = 0;

public:
    Status tick(Blackboard &bb) override
    {

        step++;

        std::cout << "[Action] Walking to ball... step "
                  << step << " distance: "
                  << bb.ballDistance << "\n";

        if (step < 5)
            return Status::RUNNING;

        std::cout << "[Action] Reached Ball\n";
        return Status::SUCCESS;
    }
};

class ScanHead : public Node
{
public:
    Status tick(Blackboard &bb) override
    {

        std::cout << "[Action] Head scanning...\n";
        return Status::RUNNING;
    }
};

class ScanAround : public Node
{
public:
    Status tick(Blackboard &bb) override
    {

        std::cout << "[Action] Searching ball around field...\n";
        return Status::RUNNING;
    }
};

int main()
{
    Blackboard bb;

    bb.ballVisible = false;
    bb.ballDistance = 150;

    SeeBall seeBall;
    WalkToBall walk;
    ScanHead scanHead;
    ScanAround scanAround;

    Parallel moveAndScan({&walk,
                          &scanHead});

    MemorySequence attack({&seeBall,
                           &moveAndScan});

    Selector root({&attack,
                   &scanAround});

    for (int i = 0; i < 12; i++)
    {

        std::cout << "\n===== TICK " << i << " =====\n";

        // simulasi bola terlihat setelah tick ke-3
        if (i == 3)
        {
            bb.ballVisible = true;
            bb.ballDistance = 80;
        }

        root.tick(bb);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(800));
    }

    return 0;
}