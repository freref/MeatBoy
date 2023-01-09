

#ifndef MEATBOY_STATE_H
#define MEATBOY_STATE_H

#include <SFML/Graphics.hpp>
#include "../logic/World.h"
#include <iostream>

class State {
public:
    State(const std::shared_ptr<sf::RenderWindow> &_window,
    const std::shared_ptr<World> &_world) : window(_window), world(_world) {};

    virtual int handleEvent(sf::Event& event);
    virtual void draw() {};

    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<World> world;
};

class MenuState : public State {
    //void handleEvent(sf::Event& event);
public:
    using State::State;
    void draw() override;
    int handleEvent(sf::Event& event);

    int levelSelected;
};


#endif //MEATBOY_STATE_H
