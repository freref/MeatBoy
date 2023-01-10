

#ifndef MEATBOY_WORLD_H
#define MEATBOY_WORLD_H

#include "AbstractFactory.h"
#include <memory>
#include <dirent.h>
#include <regex>
#include <fstream>

class AbstractFactory;
class World {
public:
    std::shared_ptr<MenuModel> menu;
    std::vector<std::shared_ptr<WallModel>> walls;
    AbstractFactory &factory;

    World(AbstractFactory &_factory);
    void menuSetup();
    void levelSetup();
};


#endif //MEATBOY_WORLD_H
