

#include "EntityView.h"


void MenuView::draw() {
    // Load the font from a file
    sf::Font font;
    if (!font.loadFromFile("../../assets/Zag.ttf")) {
    }

    // Set the number of rectangles
    int numRectangles = menuModel->levels.size();

    // Set the spacing between the rectangles and the window borders
    float rectangleSpacing = 10.0f;

    // Get the size of the window
    sf::Vector2u windowSize = window->getSize();

    std::vector<sf::RectangleShape> rectangles;
    std::vector<sf::Text> rectangleTexts;
    // Calculate the size and position of each rectangle
    for (int i = 0; i < numRectangles; i++) {
        // Calculate the size of the rectangle
        float rectangleWidth = windowSize.x * 0.8f;
        float rectangleHeight = (windowSize.y - (2 * rectangleSpacing)) / numRectangles;

        // Calculate the position of the rectangle
        float x = (windowSize.x - rectangleWidth) / 2;
        float y = rectangleSpacing + i * (rectangleHeight + rectangleSpacing);

        // Create the rectangle
        sf::RectangleShape rectangle;
        if(menuModel->selectedLevel == i){
            rectangle.setFillColor(sf::Color::Green);
        }
        rectangle.setSize(sf::Vector2f(rectangleWidth, rectangleHeight));
        rectangle.setPosition(x, y);
        rectangles.push_back(rectangle);

        // Create the rectangle text
        std::string rectangleTextString = menuModel->levels[i];
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