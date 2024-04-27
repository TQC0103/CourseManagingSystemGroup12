#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "../Course.h"

struct Scene;
struct UpdateCourseInformationScene
{
	sf::RectangleShape updateCourseBackgr;
	sf::Text updateCourseText;
	sf::Text courseText;

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::Text curData;
	sf::Text newData;

	sf::RectangleShape lecturer;
	sf::Text lecturerText;

	sf::RectangleShape weekday;
	sf::Text weekdayText;

	sf::RectangleShape session;
	sf::Text sessionText;

	sf::RectangleShape newLecturer;
	sf::Text newLecturerText;
	std::string newLecturerInput = "";
	sf::Text enterNewLecturer;

	sf::RectangleShape newWeekday;
	sf::Text newWeekdayText;
	std::string newWeekdayInput = "";
	sf::Text enterNewWeekday;

	sf::RectangleShape newSession;
	sf::Text newSessionText;
	std::string newSessionInput = "";
	sf::Text enterNewSession;

	sf::ConvexShape update;
	sf::Text updatingText;

	sf::Clock cursorClock;
	bool isCursorVisible;

	sf::Text successful;
	sf::Text fail;

	Course* c = nullptr;

	int isWrong = 0;

	int inputEnable = -1;
	int maxInputLength = 15;
	
	UpdateCourseInformationScene(Static* a);
	void drawUpdateInfo(sf::RenderWindow& win, Static* a);
	void renderUpdateInfo(sf::Event event, Scene* scene, sf::RenderWindow& win);
	~UpdateCourseInformationScene();
};
