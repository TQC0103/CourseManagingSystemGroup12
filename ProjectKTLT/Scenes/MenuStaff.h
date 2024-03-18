#pragma once
#include "../config.h"
#include "../UserInterface.h"

struct MenuStaffScene
{
	Static a;
	sf::Text menu;

	sf::RectangleShape MenuStaffPage;

	sf::RectangleShape createSchoolYearButton;
	sf::Text createSchoolYearText;

	sf::RectangleShape chooseSchoolYearButton;
	sf::Text chooseSchoolYearText;

	sf::RectangleShape preButtonStaff;
	sf::Text preText;

	//Constructor
	MenuStaffScene();

	//Functions
	void drawMenuStaff(sf::RenderWindow& win);
	void renderMenuStaff(sf::Event event, programState& currentState, sf::RenderWindow& win);
};