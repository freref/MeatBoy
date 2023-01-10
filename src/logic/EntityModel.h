

#ifndef MEATBOY_ENTITYMODEL_H
#define MEATBOY_ENTITYMODEL_H


#include "Subject.h"
#include <string>
#include <vector>
#include <iostream>


class EntityModel : public Subject {
    int x;
    int y;
public:
    EntityModel(){};
    EntityModel(int _x, int _y) : x(_x), y(_y){};
};

class MenuModel : public EntityModel {
public:
    std::vector<std::string> levels;
    int selectedLevel;

    MenuModel() {selectedLevel = 0;};
    void addLevel(std::string &title);
    void nextLevel();
    void previousLevel();
};

class WallModel : public EntityModel {
public:
    WallModel(int x, int y): EntityModel(x, y){};
};


#endif //MEATBOY_ENTITYMODEL_H
