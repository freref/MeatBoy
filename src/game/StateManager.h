

#ifndef MEATBOY_STATEMANAGER_H
#define MEATBOY_STATEMANAGER_H

#include <memory>
#include "State.h"
#include "../logic/World.h"
#include "../logic/Camera.h"
#include "ConcreteFactory.h"


class StateManager
{
public:
    StateManager(std::shared_ptr<sf::RenderWindow> &_window);

    void setState(std::shared_ptr<State> &state) { currentState = state; }
    void handleEvent();
    void draw() { currentState->draw();};
    void update() {currentState->update();};

private:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<State> menuState;
    std::shared_ptr<State> currentState;
    std::shared_ptr<World> world;

};

#endif //MEATBOY_STATEMANAGER_H
