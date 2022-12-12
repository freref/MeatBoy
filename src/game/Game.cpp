

#include "Game.h"

Game::Game() {
    window = std::unique_ptr<sf::Window>(new sf::Window);
    window->create(sf::VideoMode(1080, 1920), "Meat Boy");
}

void Game::run()
{
    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Update the window
        window->display();
    }
}