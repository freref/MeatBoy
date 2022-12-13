

#ifndef MEATBOY_ENTITY_H
#define MEATBOY_ENTITY_H

#include <string>

namespace model {
    class Entity {
    public:
        //std::string spritePath;
        int x;
        int y;

        Entity(int _x, int _y);

        // Getters and setters for x and y coordinates
        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);
    };
}


#endif //MEATBOY_ENTITY_H
