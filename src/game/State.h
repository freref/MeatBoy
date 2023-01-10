

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
    virtual void update() {};

    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<World> world;
};

class MenuState : public State {
public:
    using State::State;
    void draw() override;
    void update() override{};
    int handleEvent(sf::Event& event) override;
};

class LevelState : public State {
    std::shared_ptr<Camera> camera;
public:
    LevelState(const std::shared_ptr<Camera> &_camera, const std::shared_ptr<sf::RenderWindow> &_window,
               const std::shared_ptr<World> &_world) : State(_window, _world), camera(_camera)
               {
        Stopwatch::getInstance().newFrame();
               };

    void draw() override;
    void update() override;
    int handleEvent(sf::Event& event) override;
};


#endif //MEATBOY_STATE_H
