

#ifndef MEATBOY_WALLVIEW_H
#define MEATBOY_WALLVIEW_H

#include "Entity.h"
#include "../logic/Wall.h";

namespace view {
    class Wall : view::Entity {
        Wall(std::shared_ptr<model::Wall> &wall) : view::Entity(wall){};
    };
}


#endif //MEATBOY_WALLVIEW_H
