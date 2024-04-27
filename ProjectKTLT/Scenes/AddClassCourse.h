#pragma once
#include <SFML/Graphics.hpp>
#include "../Course.h"
#include "../config.h"

struct Scene;
struct AddClassCourseScene
{
	sf::RectangleShape addClassCourseBackgr;
	sf::Text addClassCourseText;

	sf::Text courseText;

	Course* c = nullptr;
	std::string courseData = "";

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::RectangleShape nameClass;
	sf::Text nameClassText;
	std::string nameClassInput = "";
	sf::Text enterNameClassHere;

	sf::RectangleShape lecturer;
	sf::Text lecturerText;
	std::string lecturerInput = "";
	sf::Text enterLecturerHere;

	sf::RectangleShape weekday;
	sf::Text weekdayText;
	std::string weekdayInput = "";
	sf::Text enterWeekdayHere;

	sf::RectangleShape session;
	sf::Text sessionText;
	std::string sessionInput = "";	
	sf::Text enterSessionHere;

	sf::ConvexShape create;
	sf::Text creatingText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Text successful;
	sf::Text fail;

	int isWrong = 0;

	int inputEnable = -1;
	int maxInputLength = 25;


	// Constructors
	AddClassCourseScene(Static* a);

	// Functions
	void drawAddClassCourseScene(sf::RenderWindow& win, Static* a);
	void renderAddClassCourseScene(sf::Event event, Scene* scene, sf::RenderWindow& win);
};