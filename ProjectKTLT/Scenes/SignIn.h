#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"

struct SignInScene
{
	Static a;
	// Scene elements
	sf::RectangleShape signInPage;
	sf::RectangleShape goBackToWelcome;
	sf::Text prePageToWelcome;
	sf::Text ChooseAcc;
	sf::RectangleShape signInAsStudentButton;
	sf::RectangleShape signInAsStaffButton;
	sf::Text signInAsStudentText;
	sf::Text signInAsStaffText;

	// Constructor
	SignInScene();

	// Member functions
	void drawSignIn(sf::RenderWindow& win);
	void renderSignIn(sf::Event event, programState& currentState, sf::RenderWindow& win);
};