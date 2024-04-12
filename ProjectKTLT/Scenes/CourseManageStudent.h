#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
struct Scene;
struct CourseManageStudentScene
{
	sf::RectangleShape courseManageStudentBackground;
	sf::Text courseManageStudentText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;

	sf::ConvexShape addStudent;
	sf::Text addStudentText;

	sf::ConvexShape viewListStudent;
	sf::Text viewListStudentText;

	CourseManageStudentScene(Static* a);

	void drawCourseManageStudent(sf::RenderWindow& window, Static* a);
	void renderCourseManageStudent(sf::Event event, Scene* scene, sf::RenderWindow& window);
};


