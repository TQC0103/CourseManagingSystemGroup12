#pragma once
#include "../config.h"
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"

struct Scene;

struct SignInAsStudentScene
{
	sf::RectangleShape signInStudentPage;
	sf::Text studentSignInPageText;

	sf::ConvexShape signInStudentPreviousButton;
	sf::Text signInStudentPreviousText;

	sf::RectangleShape usernameStudentBox;
	sf::Text usernameStudentText;
	std::string usernameStudentInput = "";

	sf::RectangleShape passwordStudentBox;
	sf::Text passwordStudentText;
	std::string passwordStudentInput = "";
	std::string passwordStudentInputHidden = "";

	sf::ConvexShape submit;
	sf::Text submitText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Sprite hidePassword;

	sf::Text incorrect;
	sf::Text successful;
	sf::Text enterUsernameHere;
	sf::Text enterPasswordHere;
	int isWrong = 0;
	bool usernameInputEnable = false;
	int maxUsernameLength = 15;
	bool passwordInputEnable = false;
	int maxPassWordLength = 15;
	bool passwordHiden = true;
	
	// Constructors
	SignInAsStudentScene(Static *a);

	// Functions
	void drawSignInAsStudent(sf::RenderWindow& win, Static *a);
	void renderSignInAsStudent(sf::Event event, Scene *scene, sf::RenderWindow& win);
	bool checkAccount();
};

