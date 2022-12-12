

#ifndef MEATBOY_CONCRETEFACTORY_H
#define MEATBOY_CONCRETEFACTORY_H

#include "../logic/AbstractFactory.h"

class ConcreteFactory : public AbstractFactory {
    std::shared_ptr<model::Wall> createWall(int _x, int _y) const override;
    std::shared_ptr<model::Player> createPlayer(int _x, int _y) const override;
    std::shared_ptr<model::Goal> createGoal(int _x, int _y) const override;
};


#endif //MEATBOY_CONCRETEFACTORY_H
