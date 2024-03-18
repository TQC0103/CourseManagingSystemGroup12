#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"

struct MenuStudentScene
{
	Static a;
	sf::RectangleShape menuStudentPage;

	sf::Text menu;

	sf::RectangleShape preButton;
	sf::Text preText;
	
	sf::RectangleShape viewScoreBoard;
	sf::Text viewScoreBoardText;

	sf::RectangleShape viewListsOfCourses;
	sf::Text viewListsOfCoursesText;

	sf::RectangleShape viewStudentInfo;
	sf::Text viewStudentInfoText;

	sf::RectangleShape changePass;
	sf::Text changePassText;
	

	MenuStudentScene();

	//Functions
	void drawMenuStudent(sf::RenderWindow& win);
	void renderMenuStudent(sf::Event event, programState &currentState, sf::RenderWindow &win);

};