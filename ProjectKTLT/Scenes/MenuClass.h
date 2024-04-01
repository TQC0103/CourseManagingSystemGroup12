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

	sf::RectangleShape preButton;
	sf::Text preText;

	sf::RectangleShape viewStudentGPA;
	sf::Text viewStudentGPAText;

	sf::RectangleShape viewMembers;
	sf::Text viewMembersText;

	sf::RectangleShape addStudentButton;
	sf::Text addStudentText;

	int i = 0;

	MenuClassScene(Static* a);

	void drawMenuClass(sf::RenderWindow& window, Static* a);
	void renderMenuClass(sf::Event event, Scene *scene, sf::RenderWindow& window);
};