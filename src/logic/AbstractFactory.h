

#ifndef MEATBOY_ABSTRACTFACTORY_H
#define MEATBOY_ABSTRACTFACTORY_H



#include <memory>
#include "EntityModel.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<MenuModel> createMenu() = 0;
    virtual std::shared_ptr<WallModel> createWall(int x, int y) = 0;
};

#endif //MEATBOY_ABSTRACTFACTORY_H