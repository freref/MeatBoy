

#ifndef MEATBOY_GOALVIEW_H
#define MEATBOY_GOALVIEW_H

#include "Entity.h"
#include "../logic/Goal.h"

namespace view {
class Goal : public view::Entity {
        Goal(std::shared_ptr<model::Goal> &goal) : view::Entity(goal){};
    };
}

#endif //MEATBOY_GOALVIEW_H
