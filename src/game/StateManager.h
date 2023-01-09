

#ifndef MEATBOY_STATEMANAGER_H
#define MEATBOY_STATEMANAGER_H

#include <memory>
#include "State.h"
#include "../logic/World.h"
#include "ConcreteFactory.h"

class StateManager
{
public:
    StateManager(std::shared_ptr<sf::RenderWindow> &_window);

    void setState(std::shared_ptr<State> &state) { currentState = state; }
    void handleEvent(sf::Event &event) { currentState->handleEvent(event); }
    void draw() { currentState->draw();};

private:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<State> currentState;
    std::shared_ptr<World> world;

};

#endif //MEATBOY_STATEMANAGER_H
