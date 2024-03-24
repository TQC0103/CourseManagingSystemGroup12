#pragma once
#include "../config.h"
#include "../UserInterface.h"
#include "SFML/Graphics.hpp"

struct WelcomeScene {
    // Scene elements
    
    sf::Text welcomeText;
    sf::Text welcomeTextBlur;
    sf::Text course;
    sf::RectangleShape welcomeRect;
    sf::RectangleShape signInRect;
    sf::RectangleShape exitRect;
    sf::Text signInText;
    sf::Text exitText;

    // Constructor
    WelcomeScene(Static *a);

    // Member functions
    void drawWelcome(sf::RenderWindow& win, Static *a);
    void renderWelcome(sf::Event event, Static *a, sf::RenderWindow& win);
};


