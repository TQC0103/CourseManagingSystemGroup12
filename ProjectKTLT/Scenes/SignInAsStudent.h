#pragma once
#include "../config.h"
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"

struct SignInAsStudentScene
{
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

	sf::RectangleShape submit;
	sf::Text submitText;

	sf::Text incorrect;
	bool isWrong = false;
	bool usernameInputEnable = false;
	int maxUsernameLength = 15;
	bool passwordInputEnable = false;
	int maxPassWordLength = 15;
	// Constructors
	SignInAsStudentScene(Static *a);

	// Functions
	void drawSignInAsStudent(sf::RenderWindow& win, Static *a);
	void renderSignInAsStudent(sf::Event event, Static *a, sf::RenderWindow& win);
	bool checkAccount();
};

