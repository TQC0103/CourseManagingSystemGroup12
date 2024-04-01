#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
struct Scene;
struct MenuStudentScene
{
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
	

	MenuStudentScene(Static *a);

	//Functions
	void drawMenuStudent(sf::RenderWindow& win);
	void renderMenuStudent(sf::Event event, Scene *scene, sf::RenderWindow &win);

};