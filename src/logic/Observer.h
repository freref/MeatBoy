

#ifndef MEATBOY_OBSERVER_H
#define MEATBOY_OBSERVER_H


class Observer {
public:
    virtual void draw() = 0;
    virtual void draw(float x, float y, int size) = 0;
};


#endif //MEATBOY_OBSERVER_H
