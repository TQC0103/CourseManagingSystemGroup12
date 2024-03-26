#pragma once
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
void setOriginTextToMiddle(sf::Text& text) {
    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.left + bounds.width / 2.f, bounds.top + bounds.height / 2.f);
}

void setOriginRecToMiddle(sf::RectangleShape& rectangle) {
    sf::FloatRect bounds = rectangle.getLocalBounds();
    rectangle.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}
void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position) {
    // Set button properties
    button.setSize(size);
    button.setFillColor(fillColor);

    // Set button text properties
    buttonText.setFont(font);
    buttonText.setFillColor(textColor);
    buttonText.setString(text);
    buttonText.setCharacterSize((int)textSize);

    // Set text origin to center if requested
    setOriginRecToMiddle(button);

    setOriginTextToMiddle(buttonText);

    // Set button position
    button.setPosition(position);
    buttonText.setPosition(position);
}

void createText(sf::Text& text, const sf::Font &font, const sf::Color &fillColor, const std::string &content, unsigned int characterSize, float x, float y) {
    text.setFont(font);
    text.setFillColor(fillColor);
    text.setString(content);
    text.setCharacterSize(characterSize);
    // Centralize
    setOriginTextToMiddle(text);
    text.setPosition(sf::Vector2f(x, y));
}

void createABox(sf::RectangleShape& box, const sf::Vector2f size, const sf::Color& fillColor, const sf::Vector2f position) {
    box.setSize(size);
    box.setFillColor(fillColor);
    setOriginRecToMiddle(box);
    box.setPosition(position);
}

void setBlinkingCursorInTypingBox(sf::Text& typingText, sf::RectangleShape& cursor, sf::RenderWindow& window, sf::Clock& cursorClock, bool& isCursorVisible) {
    // Calculate cursor position
    sf::Vector2f cursorPos(typingText.getPosition().x + typingText.getLocalBounds().width / 2.0f + 10.0f, typingText.getPosition().y);

    // Draw cursor as a vertical line
    cursor.setSize(sf::Vector2f(3.0f, static_cast<float>(typingText.getCharacterSize())));
    cursor.setOrigin(cursor.getSize().x / 2.0f, cursor.getSize().y / 2.0f); // Set origin to the middle
    cursor.setPosition(cursorPos);

    // Toggle cursor visibility every 1 second
    if (cursorClock.getElapsedTime().asSeconds() > 0.5f) {
        isCursorVisible = !isCursorVisible;
        cursorClock.restart();
    }

    // Set cursor color based on visibility
    cursor.setFillColor(isCursorVisible ? sf::Color::White : sf::Color::Transparent);

    // Draw cursor only if it's visible
    if (isCursorVisible) {
        window.draw(cursor);
    }
}