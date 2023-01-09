

#ifndef MEATBOY_WORLD_H
#define MEATBOY_WORLD_H

#include "AbstractFactory.h"
#include <memory>
#include <dirent.h>
#include <regex>

class World {
public:
    AbstractFactory &factory;
    World(AbstractFactory &_factory);

    std::vector<std::shared_ptr<MenuItemModel>> menuItems;
};


#endif //MEATBOY_WORLD_H
