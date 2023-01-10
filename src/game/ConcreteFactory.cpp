

#include "ConcreteFactory.h"

std::shared_ptr<MenuModel> ConcreteFactory::createMenu() {
    std::shared_ptr<MenuModel> menu = std::make_shared<MenuModel>();
    menu->attach(std::make_shared<MenuView>(menu, window));
    return menu;
}

std::shared_ptr<WallModel> ConcreteFactory::createWall(int x, int y) {
    std::cout << "NICZBCUIZBUF" << std::endl;
    std::shared_ptr<WallModel> wall = std::make_shared<WallModel>(x, y);
    wall->attach(std::make_shared<WallView>(wall, window));
    return wall;
}