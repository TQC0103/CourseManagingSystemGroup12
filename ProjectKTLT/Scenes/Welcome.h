#pragma once
#include "../config.h"
#include "../UserInterface.h"
#include "SFML/Graphics.hpp"

struct WelcomeScene {
    // Scene elements
    Static a;
    sf::Text welcomeText;
    sf::Text course;
    sf::RectangleShape welcomeRect;
    sf::RectangleShape signInRect;
    sf::RectangleShape exitRect;
    sf::Text signInText;
    sf::Text exitText;

    // Constructor
    WelcomeScene();

    // Member functions
    void drawWelcome(sf::RenderWindow& win);
    void renderWelcome(sf::Event event, programState& currentState, sf::RenderWindow& win);
};


