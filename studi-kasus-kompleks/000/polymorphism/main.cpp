#include "Player.h"
#include "Enemy.h"

int main() {
    Character* hero = new Player("Knight");
    Character* enemy = new Enemy("Goblin");

    hero->attack(*enemy);
    enemy->attack(*hero);

    hero->showStatus();
    enemy->showStatus();

    delete hero;
    delete enemy;
    return 0;
}
