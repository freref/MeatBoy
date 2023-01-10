

#ifndef MEATBOY_ENTITYVIEW_H
#define MEATBOY_ENTITYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../logic/Camera.h"
#include "../logic/Observer.h"
#include "../logic/EntityModel.h"


class EntityView : public Observer {
public:
    std::shared_ptr<sf::RenderWindow> window;
    std::shared_ptr<Camera> camera;

    EntityView(std::shared_ptr<sf::RenderWindow> &_window)
            : window(_window) {};

    using Observer::draw;
};

class MenuView : public EntityView {
public:
    std::shared_ptr<MenuModel> menuModel;

    MenuView(const std::shared_ptr<MenuModel> &menu, std::shared_ptr<sf::RenderWindow> &window): EntityView(window), menuModel(menu){};
    void draw() override;
    void draw(float x, float y, int size) override {};
};

class WallView : public EntityView {
public:
    std::shared_ptr<WallModel> wallModel;
    WallView(const std::shared_ptr<WallModel> &wall, std::shared_ptr<sf::RenderWindow> &window) : EntityView(window), wallModel(wall){};
    void draw() override{};
    void draw(float x, float y, int size) override;
};

class GoalView : public EntityView {
public:
    std::shared_ptr<GoalModel> goalModel;
    GoalView(const std::shared_ptr<GoalModel> &goal, std::shared_ptr<sf::RenderWindow> &window) : EntityView(window), goalModel(goal){};
    void draw() override{};
    void draw(float x, float y, int size) override;
};

class PlayerView : public EntityView {
public:
    std::shared_ptr<PlayerModel> playerModel;
    PlayerView(const std::shared_ptr<PlayerModel> &player, std::shared_ptr<sf::RenderWindow> &window) : EntityView(window), playerModel(player){};
    void draw() override{};
    void draw(float x, float y, int size) override;
};

#endif //MEATBOY_ENTITYVIEW_H
