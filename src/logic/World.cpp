

#include "World.h"

World::World(AbstractFactory &_factory) : factory(_factory){
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
                menuItems.push_back(factory.createMenuItem(result));
            }
        }
        closedir(dir);
    }
}