#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
struct Scene;
struct AddStudentToCourseScene
{
	sf::RectangleShape addStudentToCourseBackground;
	sf::Text addStudentToCourseText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;

	sf::ConvexShape addManually;
	sf::Text addManuallyText;

	sf::ConvexShape addFile;
	sf::Text addFileText;

	AddStudentToCourseScene(Static* a);

	void drawAddStudentToCourse(sf::RenderWindow& window, Static* a);
	void renderAddStudentToCourse(sf::Event event, Scene* scene, sf::RenderWindow& window);
};



