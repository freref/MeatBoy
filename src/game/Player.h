

#ifndef MEATBOY_PLAYERVIEW_H
#define MEATBOY_PLAYERVIEW_H

#include <memory>

#include "Entity.h"
#include "../logic/Player.h"

namespace view {
    class Player : public view::Entity {
        Player(std::shared_ptr<model::Player> &player) : view::Entity(player){};
    };
}


#endif //MEATBOY_PLAYERVIEW_H
