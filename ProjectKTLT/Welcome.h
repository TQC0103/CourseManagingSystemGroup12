#pragma once
#include "config.h"
#include "UserInterface.h"
#include "config.h"

struct WelcomeScene {
    // Scene elements
    sf::Text welcomeText;
    sf::Text course;
    sf::RectangleShape welcomeRect;
    sf::RectangleShape signInRect;
    sf::RectangleShape exitRect;
    sf::Text signInText;
    sf::Text exitText;

    // Constructor
    WelcomeScene() {
        // Initialize scene elements using Static
        Static a; 
        createText(welcomeText, a.fontB, a.textColorBlue, "WELCOME TO", 80, a.width / 2, 100.0f);

        createText(course, a.fontB, a.highlightCyan, "COURSE MANAGING SYSTEM", 120, a.width, 250.0f);

        welcomeRect.setSize(sf::Vector2f(a.width, a.height));
        welcomeRect.setFillColor(a.backGroundWhite);
        
        createAButton(signInRect, signInText, sf::Vector2f(500.0f, 625.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "SIGN IN", sf::Vector2f(575.0f, 675.0f));

        createAButton(exitRect, exitText, sf::Vector2f(600.0f, 200.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "EXIT", sf::Vector2f(610.0f, 975.0f));
    }

    // Member functions
    void drawWelcome(sf::RenderWindow &win);
    void renderWelcome(sf::Event event, programState &currentState, sf::RenderWindow &win);
};


