#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Semester.h"
#include "../Student.h"

struct Scene;
struct ViewCoursesStudentScene
{
	sf::RectangleShape viewCourseStudentBackground;
	sf::Text viewCourseStudentText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;
	sf::Text needParticipationText;

	student* stu;

	std::string** table = nullptr;
	float tableWidth = 0;
	float tableHeight = 0;
	sf::RectangleShape** recA;
	sf::Text** textA;

	int numCourse = 0;
	

	ViewCoursesStudentScene(Static* a);
	void drawViewCourseStudent(sf::RenderWindow& window, Static *a);
	void renderViewCourseStudent(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewCoursesStudentScene();
};