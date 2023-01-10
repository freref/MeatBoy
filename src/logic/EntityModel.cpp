

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