#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Semester.h"
#include "../Student.h"

struct Scene;
struct ViewScoreboardScene
{
	sf::RectangleShape viewScoreStudentBackground;
	sf::Text viewScoreStudentText;
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
	sf::RectangleShape* recAverage;
	sf::Text* textAverage;
	int numCourse = 0;
	ViewScoreboardScene(Static* a);
	void drawViewScoreboardScene(sf::RenderWindow& window, Static* a);
	void renderViewScoreboardScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
	~ViewScoreboardScene();
};