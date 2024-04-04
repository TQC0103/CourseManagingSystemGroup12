#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
struct Scene;

struct SignInScene
{
	// Scene elements
	sf::RectangleShape signInPage;
	sf::ConvexShape goBackToWelcome;
	sf::Text prePageToWelcome;
	sf::Text ChooseAcc;
	sf::ConvexShape signInAsStudentButton;
	sf::ConvexShape signInAsStaffButton;
	sf::Text signInAsStudentText;
	sf::Text signInAsStaffText;

	// Constructor
	SignInScene(Static *a);

	// Member functions
	void drawSignIn(sf::RenderWindow& win);
	void renderSignIn(sf::Event event, Scene *scene, sf::RenderWindow& win);
};