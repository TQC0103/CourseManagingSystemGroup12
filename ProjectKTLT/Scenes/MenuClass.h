#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../Class.h"
struct Scene;
struct MenuClassScene
{
	sf::RectangleShape menuClassBackground;
	sf::Text menuClassText;
	sf::Text classText;

	sf::ConvexShape preButton;
	sf::Text preText;

	sf::ConvexShape viewStudentGPA;
	sf::Text viewStudentGPAText;

	sf::ConvexShape viewMembers;
	sf::Text viewMembersText;

	sf::ConvexShape addStudentButton;
	sf::Text addStudentText;

	int i = 0;

	MenuClassScene(Static* a);

	void drawMenuClass(sf::RenderWindow& window, Static* a);
	void renderMenuClass(sf::Event event, Scene *scene, sf::RenderWindow& window);
};