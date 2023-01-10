

#include "StateManager.h"

StateManager::StateManager(std::shared_ptr<sf::RenderWindow> &_window)
{
    window = _window;
    ConcreteFactory factory = ConcreteFactory(window);
    world = std::shared_ptr<World>(new World(factory));
    currentState = std::shared_ptr<State>(new MenuState(window, world));
    this->draw();
};

void StateManager::handleEvent(sf::Event &event) {
    int result = currentState->handleEvent(event);
    if (result == 1)
        currentState = std::shared_ptr<State>(new MenuState(window, world));
    else if (result == 2)
        currentState = std::shared_ptr<State>(new LevelState(window, world));

    this->draw();
}