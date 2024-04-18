#pragma once
#include <SFML/Graphics.hpp>
#include "../Semester.h"
#include "../config.h"

struct Scene;
struct AddCourseToSemesterScene
{
	sf::RectangleShape addCourseSemBackgr;
	sf::Text addCourseSemText;
	
	sf::Text semText;

	semester* sem = nullptr;
	std::string semesterData = "";

	sf::ConvexShape preButt;
	sf::Text preText;

	sf::RectangleShape id;
	sf::Text idText;
	std::string idInput = "";
	sf::Text enterIdHere;

	sf::RectangleShape name;
	sf::Text nameText;
	std::string nameInput = "";
	sf::Text enterNameHere;

	sf::RectangleShape credit;
	sf::Text creditText;
	std::string creditInput = "";
	sf::Text enterCreditHere;

	sf::RectangleShape maxStudent;
	sf::Text maxStudentText;
	std::string maxStudentInput = "";
	sf::Text enterMaxStudentHere;

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
	AddCourseToSemesterScene(Static* a);

	// Functions
	void drawAddCourseToSemesterScene(sf::RenderWindow& win, Static* a);
	void renderAddCourseToSemesterScene(sf::Event event, Scene* scene, sf::RenderWindow& win);
};