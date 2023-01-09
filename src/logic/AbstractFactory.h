

#ifndef MEATBOY_ABSTRACTFACTORY_H
#define MEATBOY_ABSTRACTFACTORY_H



#include <memory>
#include "EntityModel.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<MenuItemModel> createMenuItem(std::string &title) = 0;
};

#endif //MEATBOY_ABSTRACTFACTORY_H