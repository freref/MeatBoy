

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

void PlayerModel::update(){
    float deltaTime = Stopwatch::getInstance().elapsed();
    Stopwatch::getInstance().newFrame();
    // Apply gravity
    vv -= g * deltaTime * 0.002;

    // Apply acceleration
    vh += a * deltaTime;

    // Limit the velocity to the terminal velocity
    if (vh > maxVh) vh = maxVh;
    if (vh < -maxVh) vh = -maxVh;
    if (vv > maxVv) vv = maxVv;
    if (vv < -maxVv) vv = -maxVv;

    // Update the position based on the velocity
    //std::cout << y << " " << " " << vv << " " << deltaTime << std::endl;
    x += vh * deltaTime * 0.01;
    y -= vv * deltaTime * 0.01;
    usleep(1000000);
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
    if(vv <= 0)
        vv = 5;
}