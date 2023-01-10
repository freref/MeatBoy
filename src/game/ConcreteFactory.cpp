

#include "ConcreteFactory.h"

std::shared_ptr<MenuModel> ConcreteFactory::createMenu() {
    std::shared_ptr<MenuModel> menu = std::make_shared<MenuModel>();
    menu->attach(std::make_shared<MenuView>(menu, window));
    return menu;
}

std::shared_ptr<WallModel> ConcreteFactory::createWall(int x, int y) {
    std::shared_ptr<WallModel> wall = std::make_shared<WallModel>(x, y);
    wall->attach(std::make_shared<WallView>(wall, window));
    return wall;
}

std::shared_ptr<GoalModel> ConcreteFactory::createGoal(int x, int y) {
    std::shared_ptr<GoalModel> goal = std::make_shared<GoalModel>(x, y);
    goal->attach(std::make_shared<GoalView>(goal, window));
    return goal;
}

std::shared_ptr<PlayerModel> ConcreteFactory::createPlayer(int x, int y) {
    std::shared_ptr<PlayerModel> player = std::make_shared<PlayerModel>(x, y);
    player->attach(std::make_shared<PlayerView>(player, window));
    return player;
}