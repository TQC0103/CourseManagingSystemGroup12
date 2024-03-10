#include "UserInterface.h"
#include <SFML/Graphics.hpp>

void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position) {
    // Set button properties
    button.setSize(size);
    button.setFillColor(fillColor);
    button.setPosition(position);

    // Set button text properties
    buttonText.setFont(font);
    buttonText.setFillColor(textColor);
    buttonText.setString(text);
    buttonText.setCharacterSize(80);

    // Set text origin to center
    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    buttonText.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
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