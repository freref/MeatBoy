

#include "Game.h"

Game::Game() {
    window = std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow);
    window->setFramerateLimit(60);
    window->create(sf::VideoMode(1080, 1920, 32), "Meat Boy");

    stateManager = std::shared_ptr<StateManager>(new StateManager(window));
}

void Game::run()
{
    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;

        while(window->pollEvent(event)){
            stateManager->handleEvent(event);
        }

        stateManager->update();
    }
}