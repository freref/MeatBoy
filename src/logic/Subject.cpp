

#include "Subject.h"

Subject::Subject(){
    observers = std::vector<std::shared_ptr<Observer>>();
}