

#include "EntityModel.h"

#include <iostream>

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
    //float deltaTime = Stopwatch::getInstance().elapsed();
    //Stopwatch::getInstance().newFrame();
    x++;
    // Apply gravity
    //vv -= g * deltaTime;

    // Apply acceleration
    //vh += a * deltaTime;

    // Limit the velocity to the terminal velocity
    //if (vh > maxVh) vh = maxVh;
    //if (vh < -maxVh) vh = -maxVh;
    //if (vv > maxVv) vv = maxVv;
    //if (vv < -maxVv) vv = -maxVv;

    // Update the position based on the velocity
    //x += vh * deltaTime;
    //y += vv * deltaTime;
}

// Handle input from the left arrow or A key
void PlayerModel::moveLeft() {
    a = -0.5;
}

// Handle input from the right arrow or D key
void PlayerModel::moveRight() {
    a = 0.5;
}