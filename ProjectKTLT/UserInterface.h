#pragma once
#include <SFML/Graphics.hpp>

// Functions
void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position);
void createText(sf::Text& text, const sf::Font &font, const sf::Color &fillColor, const std::string &content, unsigned int characterSize, float x, float y);
void createABox(sf::RectangleShape& box, const sf::Vector2f size, const sf::Color& fillColor, const sf::Vector2f position);
void setOriginRecToMiddle(sf::RectangleShape& rectangle);
void setOriginTextToMiddle(sf::Text& text);
void setBlinkingCursorInTypingBox(sf::Text& typingText, sf::RectangleShape& cursor, sf::RenderWindow& window, sf::Clock& cursorClock, bool& isCursorVisible);
