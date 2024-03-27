#pragma once
#include "../config.h"
#include "../UserInterface.h"

struct Scene;
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

	sf::RectangleShape createClassButton;
	sf::Text createClassText;

	sf::RectangleShape chooseClassButton;
	sf::Text chooseClassText;

	//Constructor
	MenuStaffScene(Static *a);

	//Functions
	void drawMenuStaff(sf::RenderWindow& win);
	void renderMenuStaff(sf::Event event, Static *a, Scene *scene, sf::RenderWindow& win);
};