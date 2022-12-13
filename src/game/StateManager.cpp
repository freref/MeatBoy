

#include "StateManager.h"

StateManager::StateManager() {
    currentState = std::make_shared<MenuState>();
}

void StateManager::setState(std::shared_ptr<State> &state) {
    currentState = state;
}