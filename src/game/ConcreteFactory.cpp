

#include "ConcreteFactory.h"

std::shared_ptr<MenuItemModel> ConcreteFactory::createMenuItem(std::string &title) {
    std::shared_ptr<MenuItemModel> menuItem = std::make_shared<MenuItemModel>(title);
    menuItem->attach(std::make_shared<EntityView>(menuItem));
    return menuItem;
}