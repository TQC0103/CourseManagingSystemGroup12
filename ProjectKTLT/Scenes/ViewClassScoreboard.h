#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Class.h"
#include "../SchoolYear.h"
#include "../Semester.h"

struct Scene;
struct ViewClassScoreboardScene
{
	sf::RectangleShape viewClassScoreBackgr;
	sf::Text viewClassScoreText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;
	sf::Text needParticipationText;

	Class* cl = nullptr;
	schoolYear* year = nullptr;
	semester* sem = nullptr;


	std::string** table = nullptr;
	float tableWidth = 0;
	float tableHeight = 0;
	sf::RectangleShape** recA;
	sf::Text** textA;
	sf::RectangleShape* recSem;
	sf::Text* textSem;
	sf::RectangleShape* recYear;
	sf::Text* textYear;
	sf::RectangleShape* recNo;
	sf::Text* textNo;

	int numStudents = 0;
	int numS = 0;

	bool isDragging = false;
	float scrollOffset;
	sf::RectangleShape hideBack;
	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollbarArea;

	int times = 0;
	float sizedisplay = 0;
	float fullsize = 0;
	ViewClassScoreboardScene(Static* a);
	void drawViewClassScoreboardScene(sf::RenderWindow& window, Static* a);
	void renderViewClassScoreboardScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewClassScoreboardScene();
};