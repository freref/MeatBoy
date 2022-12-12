

#ifndef MEATBOY_GAME_H
#define MEATBOY_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>

class Game {
public:
    std::unique_ptr<sf::Window> window;

    Game();
    void run();
};


#endif //MEATBOY_GAME_H
