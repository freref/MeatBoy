

#include "StateManager.h"

StateManager::StateManager(std::shared_ptr<sf::RenderWindow> &_window)
{
    window = _window;
    ConcreteFactory factory = ConcreteFactory(window);
    camera = std::make_shared<Camera>(window->getSize().x, window->getSize().y);
    world = std::shared_ptr<World>(new World(factory, camera));
    currentState = std::shared_ptr<State>(new MenuState(window, world));
    this->draw();
};

void StateManager::handleEvent(sf::Event &event) {
    int result = currentState->handleEvent(event);
    if (result == 1){
        currentState = std::shared_ptr<State>(new MenuState(window, world));
        this->draw();
    }

    else if (result == 2){
        currentState = std::shared_ptr<State>(new LevelState(camera, window, world));
        this->draw();
    }
}