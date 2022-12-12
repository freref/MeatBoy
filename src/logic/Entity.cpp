

#include "Entity.h"

model::Entity::Entity(int _x, int _y) {
    x = _x;
    y = _y;
}

int model::Entity::getX() const {
    return x;
}

int model::Entity::getY() const {
    return y;
}

void model::Entity::setX(int _x) {
    x = _x;
}

void model::Entity::setY(int _y) {
    y = _y;
}