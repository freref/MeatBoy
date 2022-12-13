

#ifndef MEATBOY_STATEMANAGER_H
#define MEATBOY_STATEMANAGER_H

#include <memory>

#include "MenuState.h"
#include "LevelState.h"
#include "State.h"

class StateManager {
private:
    std::shared_ptr<State> currentState;

public:
    StateManager();
    void setState(std::shared_ptr<State> &state);
};


#endif //MEATBOY_STATEMANAGER_H
