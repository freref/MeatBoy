

#include "State.h"
#include "iostream"

int State::handleEvent(sf::Event &event) {
    if (event.type == sf::Event::Closed)
    {
        window->close();
    }
}

int MenuState::handleEvent(sf::Event &event) {
    State::handleEvent(event);

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            levelSelected--;
            if(levelSelected < 0)
                levelSelected = world->menuItems.size()-1;
        }
        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            levelSelected++;
            if(levelSelected > world->menuItems.size()-1)
                levelSelected = 0;
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {

        }
        draw();
    }
    return 0;
}

void MenuState::draw() {
    std::vector<std::shared_ptr<MenuItemModel>> menuItems = world->menuItems;
    // Load the font from a file
    sf::Font font;
    if (!font.loadFromFile("../../assets/Zag.ttf")) {
        std::cout << "fuck" << std::endl;
    }

    // Set the number of rectangles
    int numRectangles = menuItems.size();

    // Set the spacing between the rectangles and the window borders
    float rectangleSpacing = 10.0f;

    // Get the size of the window
    sf::Vector2u windowSize = window->getSize();

    // Calculate the size and position of each rectangle
    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::Text> rectangleTexts;
    for (int i = 0; i < numRectangles; i++) {
        // Calculate the size of the rectangle
        float rectangleWidth = windowSize.x * 0.8f;
        float rectangleHeight = (windowSize.y - (2 * rectangleSpacing)) / numRectangles;

        // Calculate the position of the rectangle
        float x = (windowSize.x - rectangleWidth) / 2;
        float y = rectangleSpacing + i * (rectangleHeight + rectangleSpacing);

        // Create the rectangle
        sf::RectangleShape rectangle;
        if(levelSelected == i){
            rectangle.setFillColor(sf::Color::Green);
        }
        rectangle.setSize(sf::Vector2f(rectangleWidth, rectangleHeight));
        rectangle.setPosition(x, y);
        rectangles.push_back(rectangle);

        // Create the rectangle text
        std::string rectangleTextString = menuItems[i]->title;
        sf::Text rectangleText(rectangleTextString, font, 69);
        rectangleText.setFillColor(sf::Color::Black);
        sf::FloatRect rectangleTextRect = rectangleText.getLocalBounds();
        float textX = x + (rectangleWidth - rectangleTextRect.width) / 2;
        float textY = y + (rectangleHeight - rectangleTextRect.height) / 2;
        rectangleText.setPosition(textX, textY);
        rectangleTexts.push_back(rectangleText);
    }

    for (const sf::RectangleShape& rectangle : rectangles) {
        window->draw(rectangle);
    }

    for (const sf::Text& text : rectangleTexts) {
        window->draw(text);
    }

    window->display();
}