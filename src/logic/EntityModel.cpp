

#include "EntityModel.h"

#include <iostream>
#include <unistd.h>

void MenuModel::addLevel(std::string &title) {
    levels.push_back(title);
}

void MenuModel::nextLevel(){
    selectedLevel++;
    if(selectedLevel > levels.size() -1)
        selectedLevel = 0;
}

void MenuModel::previousLevel(){
    selectedLevel--;
    if (selectedLevel < 0)
        selectedLevel = levels.size() -1;
}

void PlayerModel::update(bool floorCollision, bool ceilingCollision, bool leftWallCollision, bool rightWallCollision){
    float deltaTime = Stopwatch::getInstance().elapsed();
    Stopwatch::getInstance().newFrame();
    // Apply gravity
    vv -= g * deltaTime*0.1;

    if(ceilingCollision && vv > 0)
        vv = -g * deltaTime*0.1;

    if(floorCollision && vv < 0)
        vv = 0;

    // Apply acceleration
    vh += a * deltaTime;

    if(leftWallCollision && vh < 0)
        vh = 0;

    if(rightWallCollision && vh > 0)
        vh = 0;

    if(leftWallCollision && vh == 0 && jumped){
        a = 5;
        vv = 10;
        vh = 5;
        jumped = false;
    }


    if(rightWallCollision && vh == 0 && jumped){
        a = -5;
        vv = 10;
        vh = -5;
        jumped = false;
    }

    // Limit the velocity to the terminal velocity
    if (vh > maxVh) vh = maxVh;
    if (vh < -maxVh) vh = -maxVh;
    if (vv > maxVv) vv = maxVv;
    if (vv < -maxVv) vv = -maxVv;

    // Update the position based on the velocity
    x += vh * deltaTime * 1.25;
    y -= vv * deltaTime * 1.25;

    a = 0;
}

// Handle input from the left arrow or A key
void PlayerModel::moveLeft() {
    a -= 0.1;
}

// Handle input from the right arrow or D key
void PlayerModel::moveRight() {
    a += 0.1;
}

void PlayerModel::moveUp() {
    if(vv == 0)
        vv = 10;
    jumped = true;
}