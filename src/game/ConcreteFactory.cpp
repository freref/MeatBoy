

#include "ConcreteFactory.h"

std::shared_ptr<model::Wall> ConcreteFactory::createWall(int _x, int _y) const {
    std::shared_ptr<model::Wall> wall = std::make_shared<model::Wall>(_x, _y);
    // other logic
    return wall;
}

std::shared_ptr<model::Player> ConcreteFactory::createPlayer(int _x, int _y) const {
    std::shared_ptr<model::Player> player = std::make_shared<model::Player>(_x, _y);
    // other logic
    return player;
}


std::shared_ptr<model::Goal> ConcreteFactory::createGoal(int _x, int _y) const {
    std::shared_ptr<model::Goal> goal = std::make_shared<model::Goal>(_x, _y);
    // other logic
    return goal;
}