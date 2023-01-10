

#include "State.h"
#include "iostream"

#include "ConcreteFactory.h"

int State::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::Closed)
    {
        window->close();
    }
    return 0;
}

int LevelState::handleEvent(sf::Event &event) {
    State::handleEvent(event);
}

void LevelState::draw(){
    window->clear();
    window->display();
}

int MenuState::handleEvent(sf::Event &event) {
    State::handleEvent(event);

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            world->menu->previousLevel();
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            world->menu->nextLevel();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            world->levelSetup();
            return 2;
        }
        draw();
    }
    return 0;
}

void MenuState::draw() {
    world->menu->observers.back()->draw();
}