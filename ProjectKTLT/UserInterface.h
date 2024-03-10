#include <SFML/Graphics.hpp>

void createAButton(sf::RectangleShape& button, sf::Text& buttonText, const sf::Vector2f& size, const sf::Color& fillColor, const sf::Font& font, const sf::Color& textColor, const std::string& text, const sf::Vector2f& position);
void createText(sf::Text& text, const sf::Font& font, const sf::Color& fillColor, const std::string& content, unsigned int characterSize, float x, float y);
