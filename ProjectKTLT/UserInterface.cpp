#pragma once
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
#define POINTS 20.0f

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

void createAScrollbar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, const sf::Vector2f& size, const sf::Color& fillColorScrollBar, const sf::Color& fillColorArea, const sf::Vector2f& position, int times) {
	scrollbarArea.setSize(sf::Vector2f(size.x, size.y * times));
	scrollbarArea.setFillColor(fillColorArea);
	scrollbarArea.setOrigin(scrollbarArea.getSize().x / 2.0f, scrollbarArea.getSize().y / 2.0f);
	scrollbarArea.setPosition(position);

    scrollbar.setSize(sf::Vector2f(size.x, size.y));
    scrollbar.setFillColor(fillColorScrollBar);
    scrollbar.setOrigin(scrollbar.getSize().x / 2.0f, scrollbar.getSize().y / 2.0f);
    scrollbar.setPosition(position.x, scrollbarArea.getPosition().y - scrollbarArea.getSize().y / 2 + size.y);
}

void renderScrollbar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, sf::RenderWindow& window, float &scrollOffset, sf::Event &event, bool &isDragging, Static *a, sf::Vector2f startingPoint, float &sizeDisplay, float &fullSize) {
    if (event.type == sf::Event::MouseWheelScrolled) {
        scrollOffset += event.mouseWheelScroll.delta * -30.0f;
        if (scrollOffset < 0.0f) {
            scrollOffset = 0.0f;
        }
        if (scrollOffset > fullSize - scrollbar.getSize().y / scrollbarArea.getSize().y * fullSize ) {
            scrollOffset = fullSize - scrollbar.getSize().y / scrollbarArea.getSize().y * fullSize;
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
	{
		if (scrollbar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
		{
			isDragging = true;
			scrollbar.setFillColor(a->backGroundWhiteMuchDarker);
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		isDragging = false;
		scrollbar.setFillColor(a->backGroundWhiteDarkerStill);
	}
	if (event.type == sf::Event::MouseMoved && isDragging)
	{
		scrollOffset = (static_cast<float>(event.mouseMove.y - startingPoint.y) / scrollbarArea.getSize().y * (fullSize));
		if (scrollOffset < 0.0f) {
			scrollOffset = 0.0f;
		}
		if (scrollOffset > (fullSize - scrollbar.getSize().y / scrollbarArea.getSize().y * fullSize)) {
			scrollOffset = fullSize - scrollbar.getSize().y / scrollbarArea.getSize().y * fullSize;
		}
	}
}

void drawScrollBar(sf::RectangleShape& scrollbar, sf::RectangleShape& scrollbarArea, sf::RenderWindow& window, float& scrollOffset, float& sizeDisplay, float& fullSize, sf::Vector2f startingOriginPos)
{
    scrollbar.setPosition(startingOriginPos.x, startingOriginPos.y + scrollOffset / fullSize * scrollbarArea.getSize().y);
    window.draw(scrollbarArea);
    window.draw(scrollbar);
}

sf::ConvexShape RoundedRectangle(float x, float y, float rectWidth, float rectHeight, float radius, const sf::Color& Col, float Outline, const sf::Color& OutlineCol)
{
    sf::ConvexShape rrect;
    rrect.setOutlineThickness(Outline);
    rrect.setOutlineColor(OutlineCol);
    rrect.setFillColor(Col);
    rrect.setPointCount(4 * POINTS);

    float X = 0, Y = 0;
    for (int i = 0; i < POINTS; i++)
    {
        X += radius / POINTS;
        Y = sqrt(radius * radius - X * X);
        rrect.setPoint(i, sf::Vector2f(X + rectWidth - radius, -Y + radius));
    }
    Y = 0;
    for (int i = 0; i < POINTS; i++)
    {
        Y += radius / POINTS;
        X = sqrt(radius * radius - Y * Y);
        rrect.setPoint(i + POINTS, sf::Vector2f(rectWidth + X - radius, rectHeight - radius + Y));
    }
    X = 0;
    for (int i = 0; i < POINTS; i++)
    {
        X += radius / POINTS;
        Y = sqrt(radius * radius - X * X);
        rrect.setPoint(i + 2 * POINTS, sf::Vector2f(radius - X, rectHeight - radius + Y));
    }
    Y = 0;
    for (int i = 0; i < POINTS; i++)
    {
        Y += radius / POINTS;
        X = sqrt(radius * radius - Y * Y);
        rrect.setPoint(i + 3 * POINTS, sf::Vector2f(-X + radius, radius - Y));
    }

    rrect.setPosition(x, y);
    rrect.setOrigin(rectWidth / 2, rectHeight / 2);
    return rrect;
}

void createCornerRoundedButton(sf::ConvexShape& button, sf::Text& buttonText, const sf::Vector2f& size, float textSize, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position, float outlineSize, const sf::Color& outlineColor) {
    // Set button properties
    button = RoundedRectangle(position.x, position.y, size.x, size.y, 20.0f, fillColor, outlineSize, outlineColor);

    // Set button text properties
    buttonText.setFont(font);
    buttonText.setFillColor(textColor);
    buttonText.setString(text);
    buttonText.setCharacterSize((int)textSize);

    // Set text origin to center if requested

    setOriginTextToMiddle(buttonText);

    // Set button position
    button.setPosition(position);
    buttonText.setPosition(position);
}