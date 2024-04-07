#pragma once

#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"
#include "../Semester.h"

struct Scene;
struct CreateSemesterScene
{
	sf::RectangleShape createSemesterBackgr;
	sf::Text createSemesterText;

	schoolYear* year = nullptr;
	std::string semesterData = "";

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::RectangleShape startDay;
	sf::Text startDayText;
	std::string startDayInput = "";

	sf::RectangleShape endDay;
	sf::Text endDayText;
	std::string endDayInput = "";

	sf::ConvexShape create;
	sf::Text creatingText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Text successful;
	sf::Text fail;
	sf::Text enterStartDayHere;
	sf::Text enterEndDayHere;
	int isWrong = 0;
	bool startDayInputEnable = false;
	int maxInputLength = 15;
	bool endDayInputEnable = false;
	
	// Constructors
	CreateSemesterScene(Static* a);

	// Functions
	void drawCreateSemester(sf::RenderWindow& win, Static* a);
	void renderCreateSemester(sf::Event event, Scene* scene, sf::RenderWindow& win);
	~CreateSemesterScene();
};