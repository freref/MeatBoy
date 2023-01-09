

#ifndef MEATBOY_SUBJECT_H
#define MEATBOY_SUBJECT_H

#include <list>
#include <memory>
#include "Observer.h"

class Subject {
    std::list<std::shared_ptr<Observer>> observers;
public:
    void attach(std::shared_ptr<Observer> observer) {observers.push_back(observer);};
};


#endif //MEATBOY_SUBJECT_H
