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
                return s; // FAILURE atau RUNNING
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
        }

        return Status::FAILURE;
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
public:
    Status tick(Blackboard &bb) override
    {

        std::cout << "[Action] Walking to ball. Distance: "
                  << bb.ballDistance << "\n";

        return Status::RUNNING;
    }
};

class ScanHead : public Node
{
public:
    Status tick(Blackboard &bb) override
    {

        std::cout << "[Action] Scanning head...\n";
        return Status::RUNNING;
    }
};

int main()
{
    Blackboard bb;

    // Simulasi data vision
    bb.ballVisible = false;
    bb.ballDistance = 150;

    // Leaf
    SeeBall seeBall;
    WalkToBall walk;
    ScanHead scan;

// Selector
//  ├── Attack
//  ├── Defend
//  └── Search

    // Sequence attack
    Sequence attack({&seeBall,
                     &walk});

    // Root selector
    Selector root({&attack,
                   &scan});

    for (int i = 0; i < 10; i++)
    {

        std::cout << "\n===== TICK " << i << " =====\n";

        // simulasi: bola terlihat setelah tick ke-3
        if (i == 3)
        {
            bb.ballVisible = true;
            bb.ballDistance = 80;
        }

        root.tick(bb);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(1000));
    }

    return 0;
}