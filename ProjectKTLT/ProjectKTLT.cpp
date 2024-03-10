#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    // Create the window
    int width = 2000;
    int height = 1200;
    sf::RenderWindow window(sf::VideoMode(width, height), "CourseManagingSystem");

    // Set font
    sf::Font fontB;
    if (!fontB.loadFromFile("Palatino Linotype Bold.ttf"))
        return -1;
    // Set color
    sf::Color pastelGrey(192, 192, 192);
    sf::Color pastelCyan(156, 217, 207);
    sf::Color pastelPink1(255, 230, 230);
    sf::Color pastelYellow1(255, 247, 212);
    sf::Color pastelTitleCyan(185, 204, 218);
    sf::Color pastelSoftBlue(155, 184, 205);
    sf::Color titleGreyColor(64, 64, 64);
    // Create text
    sf::Text text;
    text.setFont(fontB);
    // Set the color pastel cyan
    text.setFillColor(titleGreyColor);
    text.setString("HCMUS.FIT");
    text.setCharacterSize(120);
    text.setPosition((float)(width / 2), 0.f);

    // Centralize 
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(width / 2.0f, 150));

    // Define two rectangles to represent different pages
    sf::RectangleShape page1(sf::Vector2f((float)width, (float)height));
    page1.setFillColor(pastelSoftBlue);

    sf::RectangleShape page2(sf::Vector2f((float)width, (float)height));
    page2.setFillColor(sf::Color::Cyan);

    // Flag
    bool isPage1Visible = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the left mouse button is clicked
                    // and toggle between pages
                    isPage1Visible = !isPage1Visible;
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the appropriate page based on the flag
        if (isPage1Visible)
        {
            window.draw(page1);
            window.draw(text);
        }
        else
            window.draw(page2);



        // Display the content
        window.display();
    }

    return 0;
}



