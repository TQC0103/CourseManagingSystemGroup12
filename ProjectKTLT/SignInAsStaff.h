#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>
#include "UserInterface.h"

struct SignInAsStaffScene
{
	Static a;
	sf::RectangleShape signInStudentPage;
	sf::Text studentSignInPageText;

	sf::RectangleShape signInStudentPreviousButton;
	sf::Text signInStudentPreviousText;

	sf::RectangleShape usernameStudentBox;
	sf::Text usernameStudentText;
	std::string usernameStaffInput = "";

	sf::RectangleShape passwordStudentBox;
	sf::Text passwordStudentText;
	std::string passwordStaffInput = "";

	sf::RectangleShape submit;
	sf::Text submitText;

	bool usernameInputEnable = false;
	int maxUsernameLength = 15;
	bool passwordInputEnable = false;
	int maxPassWordLength = 15;
	// Constructors
	SignInAsStaffScene();

	// Functions
	void drawSignInAsStaff(sf::RenderWindow& win);
	void renderSignInAsStaff(sf::Event event, programState& currentState, sf::RenderWindow& win);
};