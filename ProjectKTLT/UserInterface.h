#pragma once
#include <SFML/Graphics.hpp>

// Functions
void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position);
void createText(sf::Text& text, const sf::Font &font, const sf::Color &fillColor, const std::string &content, unsigned int characterSize, float x, float y);
void createWelcomePage(sf::RenderWindow& window, int width, int height, const sf::Font& fontB, const sf::Color& textColorBlue, const sf::Color& highlightCyan, const sf::Color& backGroundWhite);
void createABox(sf::RectangleShape& box, const sf::Vector2f size, const sf::Color& fillColor, const sf::Vector2f position);
void setOriginRecToMiddle(sf::RectangleShape& rectangle);
void setOriginTextToMiddle(sf::Text& text);