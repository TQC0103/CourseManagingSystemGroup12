#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
struct Scene;
struct MenuSchoolYearScene
{
	sf::RectangleShape menuSchoolYearBackground;
	sf::Text menuSchoolYearText;
	sf::Text yearText;

	sf::RectangleShape preButton;
	sf::Text preText;

	sf::RectangleShape chooseSemesterButton;
	sf::Text chooseSemesterText;

	sf::RectangleShape createSemestersButton;
	sf::Text createSemestersText;

	int i = 0;

	MenuSchoolYearScene(Static* a);
	
	void drawMenuSchoolYear(sf::RenderWindow& window, Static* a);
	void renderMenuSchoolYear(sf::Event event, Scene *scene, sf::RenderWindow& window);
};