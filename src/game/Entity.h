

#ifndef MEATBOY_ENTITYVIEW_H
#define MEATBOY_ENTITYVIEW_H

#include <memory>

#include "../logic/Observer.h"
#include "../logic/Entity.h"

namespace view{
    class Entity : public Observer {
    public:
        std::shared_ptr<model::Entity> entity;
        Entity(std::shared_ptr<model::Entity> _entity);
    };
}



#endif //MEATBOY_ENTITY_H
