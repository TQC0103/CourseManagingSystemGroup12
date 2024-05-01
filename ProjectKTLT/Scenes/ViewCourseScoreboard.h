#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Course.h"
#include "../Student.h"

struct Scene;
struct ViewScoreboardCourseScene
{
	sf::RectangleShape viewScoreCourseBackground;
	sf::Text viewScoreCourseText;
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

	sf::Sprite checked;
	bool* isClicked = nullptr;

	sf::Text finallText;
	std::string finalStr = "";

	sf::Text midtermText;
	std::string midtermStr = "";

	sf::Text othersText;
	std::string othersStr = "";

	sf::Text totalText;
	std::string totalStr = "";

	int inputEnable = 0;
	sf::Clock cursorClock;
	sf::Clock notiClock;
	bool isCursorVisible = false;

	int maxInputLength = 5;
	int isWrong = 0;

	sf::Text successful;
	sf::Text fail;

	ViewScoreboardCourseScene(Static* a);
	void drawViewScoreboardCourseScene(sf::RenderWindow& window, Static* a);
	void renderViewScoreboardCourseScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewScoreboardCourseScene();
};