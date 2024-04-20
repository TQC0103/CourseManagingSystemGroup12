#pragma once
#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "SFML/Graphics.hpp"
struct Scene;
struct ChangePassStudentScene
{
	sf::Text changePassText;
	sf::RectangleShape changePassPage;

	sf::Text preText;
	sf::ConvexShape preButton;

	sf::RectangleShape oldPassBox;
	sf::Text oldPassText;
	std::string oldPassInput = "";
	std::string oldPassInputHiden = "";

	sf::RectangleShape newPassBox;
	sf::Text newPassText;
	std::string newPassInput = "";
	std::string newPassInputHiden = "";

	sf::ConvexShape submit;
	sf::Text submitText;

	sf::Text enterOldPass;
	sf::Text enterNewPass;

	sf::Sprite hideOldPass;
	sf::Sprite hideNewPass;

	bool oldPassInputEnable = false;
	bool newPassInputEnable = false;
	bool oldPassHiden = true;
	bool newPassHiden = true;
	int incorrect = 0;
	sf::Text successful;
	int maxPassLength = 15;

	sf::Clock cursorClock;
	bool isCursorVisible = false;



	ChangePassStudentScene(Static* a);
	void drawChangePass(sf::RenderWindow& win, Static* a);
	void renderChangePass(sf::Event event, Scene *scene, sf::RenderWindow& win);
	bool checkOldPass(std::string oldPass);
};