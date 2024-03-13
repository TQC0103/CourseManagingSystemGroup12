#pragma once
#include "config.h"

struct WelcomePage
{	
    sf::Text welcomeText;
    sf::Text course;
    sf::RectangleShape welcomeRect;
    sf::RectangleShape signInRect;
    sf::RectangleShape exitRect;
    sf::Text signInText;
    sf::Text exitText;
    sf::RenderWindow& window;
	void drawWelcome();
	void renderWelcome(sf::Event event);
	

};


