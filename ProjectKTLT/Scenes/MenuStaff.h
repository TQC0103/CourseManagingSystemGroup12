#pragma once
#include "../config.h"
#include "../UserInterface.h"

struct Scene;
struct MenuStaffScene
{
	sf::Text menu;

	sf::RectangleShape MenuStaffPage;

	sf::ConvexShape createSchoolYearButton;
	sf::Text createSchoolYearText;

	sf::ConvexShape chooseSchoolYearButton;
	sf::Text chooseSchoolYearText;

	sf::ConvexShape preButtonStaff;
	sf::Text preText;

	sf::ConvexShape changePassButton;
	sf::Text changePassText;

	sf::ConvexShape createClassButton;
	sf::Text createClassText;

	sf::ConvexShape chooseClassButton;
	sf::Text chooseClassText;

	sf::Text createYearSuccessfulText;

	bool createYearSuccessful = false;
	sf::Clock cl;
	

	//Constructor
	MenuStaffScene(Static *a);

	//Functions
	void drawMenuStaff(sf::RenderWindow& win);
	void renderMenuStaff(sf::Event event, Scene *scene, sf::RenderWindow& win);
};