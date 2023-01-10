

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

void StateManager::handleEvent() {


    int result = currentState->handleEvent();

    if (result == 1){
        camera->reset();
        world->goUpAuto = false;
        currentState = std::shared_ptr<State>(new MenuState(window, world));
        window->clear();
        this->draw();
    }

    if (result == 2){
        camera->reset();
        currentState = std::shared_ptr<State>(new LevelState(camera, window, world));
        window->clear();
        this->draw();
        window->display();
    }
}