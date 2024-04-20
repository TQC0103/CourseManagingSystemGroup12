#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Student.h"
#include "../Class.h"

struct Scene;
struct ViewStudentInClassScene
{
	sf::RectangleShape viewClassStudentsBackgr;
	sf::Text viewClassStudentsText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;
	sf::Text needParticipationText;

	Class* cl = nullptr;

	std::string** table = nullptr;
	float tableWidth = 0;
	float tableHeight = 0;
	sf::RectangleShape** recA;
	sf::Text** textA;

	int numStudents = 0;

	bool isDragging = false;
	float scrollOffset;
	sf::RectangleShape hideBack;
	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollbarArea;

	int times = 0;
	float sizedisplay = 0;
	float fullsize = 0;
	ViewStudentInClassScene(Static* a);
	void drawViewStudentInClassScene(sf::RenderWindow& window, Static* a);
	void renderViewStudentInClassScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewStudentInClassScene();
};