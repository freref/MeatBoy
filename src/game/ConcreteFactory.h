

#ifndef MEATBOY_CONCRETEFACTORY_H
#define MEATBOY_CONCRETEFACTORY_H

#include <SFML/Graphics.hpp>

#include "EntityView.h"
#include "../logic/AbstractFactory.h"


class ConcreteFactory : public AbstractFactory{
    std::shared_ptr<sf::RenderWindow> window;
public:
    ConcreteFactory(const std::shared_ptr<sf::RenderWindow> _window): window(_window) {};

    std::shared_ptr<MenuItemModel> createMenuItem(std::string &title) override;
};


#endif //MEATBOY_CONCRETEFACTORY_H
