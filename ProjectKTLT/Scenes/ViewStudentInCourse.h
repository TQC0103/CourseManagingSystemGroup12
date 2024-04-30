#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Course.h"
#include "../Student.h"

struct Scene;
struct ViewStudentCourseScene
{
	sf::RectangleShape viewStuCourseBackground;
	sf::Text viewStuCourseText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;
	sf::Text needParticipationText;

	Course* c = nullptr;

	std::string** table = nullptr;
	float tableWidth = 0;
	float tableHeight = 0;
	sf::RectangleShape** recA;
	sf::Text** textA;
	int numStudent = 0;

	bool isDragging = false;
	float scrollOffset;
	sf::RectangleShape hideBack;
	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollbarArea;

	int times = 0;
	float sizedisplay = 0;
	float fullsize = 0;

	sf::Sprite remove;
	bool *isClicked = nullptr;

	ViewStudentCourseScene(Static* a);
	void drawViewStudentCourseScene(sf::RenderWindow& window, Static* a);
	void renderViewStudentCourseScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewStudentCourseScene();
};