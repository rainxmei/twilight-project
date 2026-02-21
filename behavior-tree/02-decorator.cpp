#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

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
    virtual ~Node() = default;
};

class Sequence : public Node
{
private:
    std::vector<Node *> children;

public:
    Sequence(std::vector<Node *> nodes) : children(nodes) {}

    Status tick() override
    {
        for (auto child : children)
        {
            Status s = child->tick();
            if (s != Status::SUCCESS)
            {
                return s; // FAILURE atau RUNNING
            }
        }
        return Status::SUCCESS;
    }
};

class Selector : public Node
{
private:
    std::vector<Node *> children;

public:
    Selector(std::vector<Node *> nodes) : children(nodes) {}

    Status tick() override
    {
        for (auto child : children)
        {
            Status s = child->tick();
            if (s == Status::SUCCESS)
            {
                return Status::SUCCESS;
            }
        }
        return Status::FAILURE;
    }
};

//! Decorator
class Decorator : public Node
{
protected:
    Node *child;

public:
    Decorator(Node *c) : child(c) {}
};

class Inverter : public Decorator
{
public:
    Inverter(Node *c) : Decorator(c) {}

    Status tick() override
    {
        Status s = child->tick();

        if (s == Status::SUCCESS)
            return Status::FAILURE;

        if (s == Status::FAILURE)
            return Status::SUCCESS;

        return Status::RUNNING;
    }
};

class RepeaterUntilSuccess : public Decorator
{
public:
    RepeaterUntilSuccess(Node *c) : Decorator(c) {}

    Status tick() override
    {
        Status s = child->tick();

        if (s == Status::SUCCESS)
            return Status::SUCCESS;

        return Status::RUNNING;
    }
};

class Timeout : public Decorator
{
private:
    std::chrono::steady_clock::time_point start;
    int timeout_ms;
    bool started = false;

public:
    Timeout(Node *c, int ms)
        : Decorator(c), timeout_ms(ms) {}

    Status tick() override
    {

        if (!started)
        {
            start = std::chrono::steady_clock::now();
            started = true;
        }

        auto now = std::chrono::steady_clock::now();
        auto elapsed =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();

        if (elapsed > timeout_ms)
        {
            std::cout << "[Timeout] Failed due to time limit\n";
            started = false;
            return Status::FAILURE;
        }

        return child->tick();
    }
};

class SeeBall : public Node
{
private:
    int counter = 0;

public:
    Status tick() override
    {
        counter++;

        if (counter > 5)
        {
            std::cout << "Ball detected!\n";
            return Status::SUCCESS;
        }

        std::cout << "Looking for ball...\n";
        return Status::FAILURE;
    }
};

class WalkToBall : public Node
{
private:
    int steps = 0;

public:
    Status tick() override
    {
        steps++;

        if (steps < 4)
        {
            std::cout << "Walking to ball...\n";
            return Status::RUNNING;
        }

        std::cout << "Reached ball!\n";
        return Status::SUCCESS;
    }
};

class ScanHead : public Node
{
public:
    Status tick() override
    {
        std::cout << "Scanning head left-right...\n";
        return Status::RUNNING;
    }
};

int main()
{

    SeeBall seeBall;
    WalkToBall walk;
    ScanHead scan;

    // Selector (root)
    // │
    // ├── Sequence (attack)
    // │   ├── Repeater
    // │   │    └── SeeBall
    // │   └── Timeout
    // │        └── WalkToBall
    // │
    // └── ScanHead

    // Repeater scan sampai bola ketemu
    RepeaterUntilSuccess repeatSeeBall(&seeBall);

    // Timeout jalan ke bola max 3 detik
    Timeout walkWithTimeout(&walk, 3000);

    // Sequence attack
    Sequence attack({&repeatSeeBall,
                     &walkWithTimeout});

    // Root selector
    Selector root({&attack,
                   &scan});

    while (true)
    {

        Status s = root.tick();

        if (s == Status::SUCCESS)
        {
            std::cout << "Behavior finished successfully.\n";
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}