

#include "World.h"
#include <iostream>

World::World(AbstractFactory &_factory) : factory(_factory) {
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


void World::levelSetup() {
    std::cout << "factory: " << &factory << std::endl;

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
    while (std::getline(file, line)) {
        for(int x = 0; x < line.length(); x++){
            if(line[x] == '-'){
                factory.createWall(x, y);
            }
        }
        y++;
    }

    // Close the file
    file.close();
}