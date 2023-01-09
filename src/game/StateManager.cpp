

#include "StateManager.h"

StateManager::StateManager(std::shared_ptr<sf::RenderWindow> &_window)
{
    window = _window;
    ConcreteFactory factory = ConcreteFactory(window);
    world = std::shared_ptr<World>(new World(factory));
    currentState = std::shared_ptr<State>(new MenuState(window, world));
    this->draw();
};