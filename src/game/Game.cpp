

#include "Game.h"

void Game::createWindow()
{
    sf::RenderWindow window(sf::VideoMode(1080, 1920), "Meat Boy");

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Update the window
        window.display();
    }
}