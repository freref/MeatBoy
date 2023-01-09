

#ifndef MEATBOY_ENTITYVIEW_H
#define MEATBOY_ENTITYVIEW_H

#include <memory>

#include "../logic/Observer.h"
#include "../logic/EntityModel.h"


class EntityView : public Observer {
public:
    EntityView(const std::shared_ptr<EntityModel>& entity_model) {};
};

class MenuItemView : public EntityView {
public:
    MenuItemView(const std::shared_ptr<MenuItemModel> &menuItem) : EntityView(menuItem){};
};


#endif //MEATBOY_ENTITYVIEW_H
