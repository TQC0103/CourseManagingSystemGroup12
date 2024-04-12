#pragma once

#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../Course.h"

struct Scene;
struct MenuClassCourseScene
{
	sf::RectangleShape menuClassCourseBackground;
	sf::Text menuClassCourseText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;

	sf::ConvexShape manageStudent;
	sf::Text manageStudentText;

	sf::ConvexShape manageScoreboard;
	sf::Text manageScoreboardText;

	sf::ConvexShape updateInfo;
	sf::Text updateInfoText;


	MenuClassCourseScene(Static* a);
	void drawMenuClassCourse(sf::RenderWindow& window, Static* a);
	void renderMenuClassCourse(sf::Event event, Scene* scene, sf::RenderWindow& window);
};
