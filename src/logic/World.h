

#ifndef MEATBOY_WORLD_H
#define MEATBOY_WORLD_H

#include "AbstractFactory.h"
#include "Camera.h"
#include <memory>
#include <dirent.h>
#include <regex>
#include <fstream>
#include <vector>

class AbstractFactory;
class World {
public:
    std::shared_ptr<Camera> camera;
    std::shared_ptr<MenuModel> menu;
    std::vector<std::vector<std::shared_ptr<WallModel>>> walls;
    AbstractFactory &factory;

    World(AbstractFactory &_factory, std::shared_ptr<Camera> &_camera);
    void menuSetup();
    void levelSetup(AbstractFactory &_factory);
};


#endif //MEATBOY_WORLD_H
