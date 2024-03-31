#pragma once
#include "../config.h"
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"

struct Scene;
struct SignInAsStaffScene
{
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

	sf::Text incorrect;
	sf::Text successful;

	sf::Clock cursorClock;
	bool isCursorVisible = false;

	int isWrong = 0;
	bool usernameInputEnable = false;
	int maxUsernameLength = 15;
	bool passwordInputEnable = false;
	int maxPassWordLength = 15;

	sf::Text enterUsernameHere;
	sf::Text enterPasswordHere;
	// Constructors
	SignInAsStaffScene(Static *a);

	// Functions
	void drawSignInAsStaff(sf::RenderWindow& win, Static *a);
	void renderSignInAsStaff(sf::Event event, Scene *scene, sf::RenderWindow& win);
	bool checkAccount();
};