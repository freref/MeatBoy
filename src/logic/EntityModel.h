

#ifndef MEATBOY_ENTITYMODEL_H
#define MEATBOY_ENTITYMODEL_H


#include "Subject.h"
#include <string>
#include <vector>
#include <iostream>
#include "Stopwatch.h"



class EntityModel : public Subject {
public:
    float x;
    float y;
    EntityModel(){};
    EntityModel(int _x, int _y) : x(_x), y(_y) {};
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

class GoalModel : public EntityModel {
public:
    GoalModel(int x, int y): EntityModel(x, y){};
};

class PlayerModel : public EntityModel {
public:
    PlayerModel(int x, int y): EntityModel(x, y), vh(0), vv(0), a(0), g(0.3), maxVh(3), maxVv(5){};

    void update(bool floorCollision, bool ceilingCollision, bool leftWallCollision);
    void moveLeft();
    void moveRight();
    void moveUp();
    void jump();
    bool collidesWithWall();

    // Velocity
    float vh;
    float vv;

    // Acceleration
    float a;

    // Gravity
    float g;

    // Terminal velocity
    float maxVh;
    float maxVv;
};


#endif //MEATBOY_ENTITYMODEL_H
