#pragma once
#include "../config.h"
#include "../UserInterface.h"

struct MenuStaffScene
{
	sf::Text menu;

	sf::RectangleShape MenuStaffPage;

	sf::RectangleShape createSchoolYearButton;
	sf::Text createSchoolYearText;

	sf::RectangleShape chooseSchoolYearButton;
	sf::Text chooseSchoolYearText;

	sf::RectangleShape preButtonStaff;
	sf::Text preText;

	sf::RectangleShape changePassButton;
	sf::Text changePassText;

	//Constructor
	MenuStaffScene(Static *a);

	//Functions
	void drawMenuStaff(sf::RenderWindow& win);
	void renderMenuStaff(sf::Event event, Static *a, sf::RenderWindow& win);
	void changePassword();
};