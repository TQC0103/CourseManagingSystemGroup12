#include <SFML/Graphics.hpp>
#include "UserInterface.h"

void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position) {
    // Set button properties
    button.setSize(size);
    button.setFillColor(fillColor);

    // Set button text properties
    buttonText.setFont(font);
    buttonText.setFillColor(textColor);
    buttonText.setString(text);
    buttonText.setCharacterSize(textSize);

    // Set text origin to center if requested
    sf::FloatRect buttonBounds = button.getLocalBounds();
    button.setOrigin(buttonBounds.left + buttonBounds.width / 2.0f, buttonBounds.top + buttonBounds.height / 2.0f);
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);

    // Set button position
    button.setPosition(position);
    buttonText.setPosition(position);
}

void createText(sf::Text& text, const sf::Font& font, const sf::Color& fillColor, const std::string& content, unsigned int characterSize, float x, float y) {
    text.setFont(font);
    text.setFillColor(fillColor);
    text.setString(content);
    text.setCharacterSize(characterSize);
    text.setPosition(x, y);

    // Centralize
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(x, y));
}

void createWelcomePage(sf::RenderWindow& window, int width, int height, const sf::Font& fontB, const sf::Color& textColorBlue, const sf::Color& highlightCyan, const sf::Color& backGroundWhite) {
    // Create welcome text
    sf::Text welcomeText;
    createText(welcomeText, fontB, textColorBlue, "WELCOME TO", 80, (float)window.getSize().x / 2.0f, 150.0f);

    // Create program name
    sf::Text course;
    createText(course, fontB, highlightCyan, "COURSE MANAGING SYSTEM", 120, (float)window.getSize().x / 2.0f, 300.0f);

    // Define welcome page rectangle
    sf::RectangleShape welcomePage(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
    welcomePage.setFillColor(backGroundWhite);

    // Define Sign In button
    sf::RectangleShape SignInRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text SignInText;
    createAButton(SignInRec, SignInText, sf::Vector2f(600.0f, 200.0f), 80.0f, highlightCyan, fontB, sf::Color::White, "SIGN IN", sf::Vector2f(250.0f, 500.0f));

    // Define Exit button
    sf::RectangleShape ExitRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text ExitText;
    createAButton(ExitRec, ExitText, sf::Vector2f(600.0f, 200.0f), 80.0f, highlightCyan, fontB, sf::Color::White, "EXIT", sf::Vector2f(250.0f, 800.0f));
}

void createABox(sf::RectangleShape& box, const sf::Vector2f size, const sf::Color& fillColor, const sf::Vector2f position) {
    box.setSize(size);
    box.setFillColor(fillColor);
    box.setOrigin(size.x / 2, size.y / 2);
    box.setPosition(position);
}