

#include "World.h"
#include <iostream>

World::World(AbstractFactory &_factory, std::shared_ptr<Camera> &_camera) : factory(_factory), camera(_camera) {
    menuSetup();
}

void World::menuSetup(){
    menu = factory.createMenu();
    DIR *dir;
    struct dirent *ent;
    dir = opendir("../../assets/levels");
    std::regex pattern("^\\w+\\.level$");

    if (dir != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (std::regex_match(ent->d_name, pattern)){
                std::string menuItemName(ent->d_name);
                std::string result = menuItemName.substr(0, menuItemName.find(".level"));
                menu->addLevel(result);
            }
        }
        closedir(dir);
    }
}


void World::levelSetup(AbstractFactory &_factory) {
    walls.clear();

    std::string levelName = menu->levels[menu->selectedLevel] + ".level";

    std::ifstream file("../../assets/levels/"+levelName);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // Read the contents of the file line by line
    std::string line;
    int y = 0;
    int playerX = 0;
    int playerY = 0;
    while (std::getline(file, line)) {
        camera->setSizeWidth(line.length());
        for(int x = 0; x < line.length(); x++){
            if(line == "auto: on"){
                goUpAuto = true;
                continue;
            }
            if(line[x] == '-'){
                walls.push_back(_factory.createWall(x, y));
            }
            else if(line[x] == 'x'){
                goal = _factory.createGoal(x, y);
            }
            else if(line[x] == 'o'){
                playerX = x;
                playerY = y;
            }
        }
        y++;
    }
    camera->setSizeHeight(y);
    player = _factory.createPlayer(camera->projectX(playerX)+1.5*camera->getSizeWidth()/4, camera->projectY(playerY)+3*camera->getSizeWidth()/4);
    // Close the file
    file.close();
}

int World::update(){
    player->update(floorCollision(), ceilingCollision(), leftWallCollision(), rightWallCollision());
    if(player->y < 0.2* camera->windowHeight && !goUpAuto){
        float deltaTime = Stopwatch::getInstance().elapsed();
        camera->goUp(0.2);
    }

    if(goUpAuto){
        camera->goUp(0.05);
    }
    if(player->y > camera->windowHeight){
        return 1;
    }

    return 0;
}

bool World::floorCollision(){
    for(auto &wall : walls){
        if(wall->x == int(player->x / camera->getSizeWidth())){
            float wallCoordX = camera->projectX(wall->x);
            float wallCoordY = camera->projectY(wall->y)+camera->height;

            double epsilon = 20;
            double diff = fabs(player->y - (wallCoordY - camera->getSizeWidth()/4));
            if (diff <= epsilon) {
                return true;
            }
        }
    }
    return false;
}

bool World::ceilingCollision(){
    for(auto &wall : walls){
        if(wall->x == int(player->x / camera->getSizeWidth())){
            float wallCoordX = camera->projectX(wall->x);
            float wallCoordY = camera->projectY(wall->y)+camera->height;

            double epsilon = 20;
            double diff = fabs((player->y - camera->getSizeWidth())- (wallCoordY));
            if (diff <= epsilon) {
                return true;
            }
        }
    }
    return false;
}

bool World::leftWallCollision(){
    if(player->x <= 0){
        return true;
    }
    for(auto &wall : walls){
            float wallCoordX = camera->projectX(wall->x);
            float wallCoordY = camera->projectY(wall->y)+camera->height;

            if(wallCoordY < player->y && player->y < wallCoordY + camera->getSizeWidth()){
                double epsilon = 20;
                double diff = fabs((player->x - camera->getSizeWidth())- (wallCoordX));
                if (diff <= epsilon) {
                    return true;
                }
            }
    }
    return false;
}

bool World::rightWallCollision(){
    if(player->x + camera->getSizeWidth()/4 > camera->windowWidth){
        return true;
    }
    for(auto &wall : walls){
        float wallCoordX = camera->projectX(wall->x);
        float wallCoordY = camera->projectY(wall->y)+camera->height;

        if(wallCoordY < player->y && player->y < wallCoordY + camera->getSizeWidth()){
            double epsilon = 20;
            double diff = fabs((player->x + camera->getSizeWidth()/4) - (wallCoordX));
            if (diff <= epsilon) {
                return true;
            }
        }
    }
    return false;
}