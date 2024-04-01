#pragma once
#include <SFML/Graphics.hpp>
#include "config.h"

// Functions
void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position);
void createText(sf::Text& text, const sf::Font &font, const sf::Color &fillColor, const std::string &content, unsigned int characterSize, float x, float y);
void createABox(sf::RectangleShape& box, const sf::Vector2f size, const sf::Color& fillColor, const sf::Vector2f position);
void setOriginRecToMiddle(sf::RectangleShape& rectangle);
void setOriginTextToMiddle(sf::Text& text);
void setBlinkingCursorInTypingBox(sf::Text& typingText, sf::RectangleShape& cursor, sf::RenderWindow& window, sf::Clock& cursorClock, bool& isCursorVisible);
void createAScrollbar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, const sf::Vector2f& size, const sf::Color& fillColorScrollBar, const sf::Color& fillColorArea, const sf::Vector2f& position, int times);
void renderScrollbar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, sf::RenderWindow& window, float& scrollOffset, sf::Event& event, bool& isDragging, Static* a, sf::Vector2f& startingPoint, float& sizeDisplay, float& fullSize);
void drawScrollBar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, sf::RenderWindow& window, float& scrollOffset, float& sizeDisplay, float& fullSize, sf::Vector2f& startingOriginPos);
sf::ConvexShape RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius, const sf::Color& Col, float Outline, const sf::Color& OutlineCol);
void createCornerRoundedButton(sf::ConvexShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position, float outlineSize, const sf::Color &outlineColor);