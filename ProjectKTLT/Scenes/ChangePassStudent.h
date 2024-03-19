#pragma once
#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "SFML/Graphics.hpp"

struct ChangePassStudentScene
{
	sf::Text changePassText;
	sf::RectangleShape changePassPage;

	sf::Text preText;
	sf::RectangleShape preButton;

	sf::RectangleShape oldPassBox;
	sf::Text oldPassText;
	std::string oldPassInput = "";

	sf::RectangleShape newPassBox;
	sf::Text newPassText;
	std::string newPassInput = "";

	sf::RectangleShape submit;
	sf::Text submitText;

	sf::Text enterOldPass;
	sf::Text enterNewPass;

	bool oldPassInputEnable = false;
	bool newPassInputEnable = false;
	bool incorrect = false;
	int maxPassLength = 15;

	ChangePassStudentScene(Static* a);
	void drawChangePass(sf::RenderWindow& win, Static* a);
	void renderChangePass(sf::Event event, Static* a, sf::RenderWindow& win);
	bool checkOldPass(std::string oldPass);
};