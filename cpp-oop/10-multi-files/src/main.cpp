#include <iostream>
#include <string>

// eksternal file
#include "player.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Player* playerObject = new Player("Marni");
    playerObject->display();

    cout << "get name: " << playerObject->getName() << endl;

    cout << "rubah nama" << endl;
    playerObject->setName("abyan");
    playerObject->display();
    return 0;
}