#pragma once

#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../Class.h"

struct Scene;
struct CreateClassScene
{
	sf::RectangleShape createClassBackgr;
	sf::Text createClassText;

	Class* list = nullptr;

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::RectangleShape className;
	sf::Text classNameText;
	std::string classNameInput = "";

	sf::ConvexShape create;
	sf::Text creatingText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Text successful;
	sf::Text fail;

	sf::Text enterClassnameHere;
	
	int isWrong = 0;
	int maxInputLength = 10;
	bool inputEnable = false;

	// Constructors
	CreateClassScene(Static* a);

	// Functions
	void drawCreateClass(sf::RenderWindow& win, Static* a);
	void renderCreateClass(sf::Event event, Scene* scene, sf::RenderWindow& win);
	~CreateClassScene();
};
