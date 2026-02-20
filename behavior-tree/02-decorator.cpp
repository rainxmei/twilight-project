#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

enum class Status {
    SUCCESS,
    FAILURE,
    RUNNING
};

class Node {
public:
    virtual Status tick() = 0;
    virtual ~Node() = default;
};