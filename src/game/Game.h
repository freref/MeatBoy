

#ifndef MEATBOY_GAME_H
#define MEATBOY_GAME_H

#include "StateManager.h"
#include "../logic/Stopwatch.h"

class Game {
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<StateManager> stateManager;
public:
    Game();
    void run();
};


#endif //MEATBOY_GAME_H
