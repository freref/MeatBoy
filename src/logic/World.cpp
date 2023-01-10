

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
            if(line[x] == '-'){
                walls.push_back(_factory.createWall(x, y ));
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
    player = _factory.createPlayer(camera->projectX(playerX), camera->projectY(playerY)+3*camera->getSizeWidth()/4);
    // Close the file
    file.close();
}

void World::update(){
    player->update();
}