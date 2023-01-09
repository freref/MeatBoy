

#ifndef MEATBOY_ENTITYMODEL_H
#define MEATBOY_ENTITYMODEL_H


#include "Subject.h"
#include <string>
#include <vector>



class EntityModel : public Subject {
};

class MenuItemModel : public EntityModel {
public:
    std::string title;
    MenuItemModel(std::string &_title) : title(_title){};
};


#endif //MEATBOY_ENTITYMODEL_H
