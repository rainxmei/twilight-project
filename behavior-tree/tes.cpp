#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    bool ballVisible = false;
    bool *ball;
    ball = &ballVisible;
    cout << ball;
    return 0;
}
