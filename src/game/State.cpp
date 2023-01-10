

#include "State.h"
#include "iostream"

#include "ConcreteFactory.h"

int State::handleEvent() {
    return 0;
}

void LevelState::update(){
    world->update();
    window->clear();
    world->player->observers.back()->draw(world->player->x, world->player->y, camera->getSizeWidth());
    //window->display();
}

int LevelState::handleEvent() {
    sf::Event event;
    window->pollEvent(event);

    if (event.type == sf::Event::Closed)
        this->window->close();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        world->player->moveUp();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        world->player->moveLeft();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        world->player->moveRight();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        return 1;
    }


    int result = world->update();
    window->clear();
    draw();
    window->display();
    return result;
}

void LevelState::draw(){
    window->clear();

    for(auto wall : world->walls){
        wall->observers.back()->draw(camera->projectX(wall->x), camera->projectY(wall->y)+camera->height, camera->getSizeWidth());
        //window->display();
    }

    world->goal->observers.back()->draw(camera->projectX(world->goal->x), camera->projectY(world->goal->y)+camera->height, camera->getSizeWidth());
    world->player->observers.back()->draw(world->player->x, world->player->y, camera->getSizeWidth());

    //
    //window->display();
}

int MenuState::handleEvent() {
        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                this->window->close();
            else if (event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::Up ){
                    world->menu->previousLevel();
                    draw();
                }

                if(event.key.code == sf::Keyboard::Down ){
                    world->menu->nextLevel();
                    draw();
                }

                if(event.key.code == sf::Keyboard::Enter ){
                    //window->clear();
                    //window->display();
                    ConcreteFactory factory = ConcreteFactory(window);
                    world->levelSetup(factory);
                    return 2;
                }
            }
        }

    return 0;
}

void MenuState::draw() {
    window->clear();
    world->menu->observers.back()->draw();
}