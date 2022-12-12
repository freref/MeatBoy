

#include "Entity.h"

Entity::Entity(int _x, int _y) {
    x = _x;
    y = _y;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int _x) {
    x = _x;
}

void Entity::setY(int _y) {
    y = _y;
}