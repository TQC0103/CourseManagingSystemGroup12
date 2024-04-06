#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
struct Scene;
struct MenuStudentScene
{
	sf::RectangleShape menuStudentPage;

	sf::Text menu;

	sf::ConvexShape preButton;
	sf::Text preText;
	
	sf::ConvexShape viewScoreBoard;
	sf::Text viewScoreBoardText;

	sf::ConvexShape viewStudentInfo;
	sf::Text viewStudentInfoText;

	sf::ConvexShape changePass;
	sf::Text changePassText;
	

	MenuStudentScene(Static *a);

	//Functions
	void drawMenuStudent(sf::RenderWindow& win);
	void renderMenuStudent(sf::Event event, Scene *scene, sf::RenderWindow &win);

};