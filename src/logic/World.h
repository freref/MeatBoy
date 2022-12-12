

#ifndef MEATBOY_WORLD_H
#define MEATBOY_WORLD_H

#include <string>
#include <memory>
#include <string>

#include "AbstractFactory.h"

namespace controller{
    class World {
        World(std::shared_ptr<AbstractFactory> &factory, std::string &path);
    };
}


#endif //MEATBOY_WORLD_H
