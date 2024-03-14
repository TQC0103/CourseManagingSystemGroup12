#pragma once
#include "config.h"
#include <SFML/Graphics.hpp>
#include "UserInterface.h"

struct SignInAsStudentScene
{
	Static a;
	sf::RectangleShape signInStudentPage;
	sf::Text studentSignInPageText;

	sf::RectangleShape signInStudentPreviousButton;
	sf::Text signInStudentPreviousText;

	sf::RectangleShape usernameStudentBox;
	sf::Text usernameStudentText;
	std::string usernameStudentInput = "";

	sf::RectangleShape passwordStudentBox;
	sf::Text passwordStudentText;
	std::string passwordStudentInput = "";

	bool usernameInputEnable = false;
	int maxUsernameLength = 15;
	bool passwordInputEnable = false;
	int maxPassWordLength = 15;
	// Constructors
	SignInAsStudentScene();

	// Functions
	void drawSignInAsStudent(sf::RenderWindow& win);
	void renderSignInAsStudent(sf::Event event, programState& currentState, sf::RenderWindow& win);
};