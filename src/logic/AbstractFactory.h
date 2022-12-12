

#ifndef MEATBOY_ABSTRACTFACTORY_H
#define MEATBOY_ABSTRACTFACTORY_H

#include <memory>

#include "Wall.h"
#include "Goal.h"
#include "Player.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<model::Wall> createWall(int _x, int _y) const = 0;
    virtual std::shared_ptr<model::Player> createPlayer(int _x, int _y) const = 0;
    virtual std::shared_ptr<model::Goal> createGoal(int _x, int _y) const = 0;
};


#endif //MEATBOY_ABSTRACTFACTORY_H
