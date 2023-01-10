

#ifndef MEATBOY_SUBJECT_H
#define MEATBOY_SUBJECT_H

#include <vector>
#include <memory>
#include "Observer.h"

class Subject {
public:
    std::vector<std::shared_ptr<Observer>> observers;

    Subject();
    void attach(std::shared_ptr<Observer> observer) {observers.push_back(observer);};
};


#endif //MEATBOY_SUBJECT_H
