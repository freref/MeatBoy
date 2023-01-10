

#ifndef MEATBOY_ENTITYVIEW_H
#define MEATBOY_ENTITYVIEW_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "../logic/Observer.h"
#include "../logic/EntityModel.h"


class EntityView : public Observer {
public:
    std::shared_ptr<sf::RenderWindow> window;

    EntityView(std::shared_ptr<sf::RenderWindow> &_window)
            : window(_window) {};

    using Observer::draw;
};

class MenuView : public EntityView {
public:
    std::shared_ptr<MenuModel> menuModel;

    MenuView(const std::shared_ptr<MenuModel> &menu, std::shared_ptr<sf::RenderWindow> &window): EntityView(window), menuModel(menu){};
    void draw() override;
};

class WallView : public EntityView {
public:
    WallView(const std::shared_ptr<WallModel> &wall, std::shared_ptr<sf::RenderWindow> &window) : EntityView(window){};
    void draw() override {};
};


#endif //MEATBOY_ENTITYVIEW_H
