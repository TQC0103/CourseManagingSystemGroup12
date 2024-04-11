#pragma once
#include "../config.h"
#include "../UserInterface.h"

struct Scene;
struct CourseManageScoreBoardScene
{
	sf::RectangleShape courseManageScoreBoardBackground;
	sf::Text courseManageScoreBoardText;
	sf::Text title;

	sf::ConvexShape preButton;
	sf::Text preText;

	sf::ConvexShape exportListStudent;
	sf::Text exportListStudentText;

	sf::ConvexShape viewCourseScoreBoard;
	sf::Text viewCourseScoreBoardText;

	sf::ConvexShape update1StuRes;
	sf::Text update1StuResText;

	sf::ConvexShape importScoreBoard;
	sf::Text importScoreBoardText;


	CourseManageScoreBoardScene(Static* a);
	void drawCourseManageScoreBoard(sf::RenderWindow& window, Static* a);
	void renderCourseManageScoreBoard(sf::Event event, Scene* scene, sf::RenderWindow& window);
};
