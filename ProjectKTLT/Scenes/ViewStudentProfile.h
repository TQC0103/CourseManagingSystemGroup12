#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../Student.h"
struct Scene;
struct ViewStudentProfileScene
{
	student* stu = new student;
	sf::RectangleShape ViewStudentProfilePage;
	sf::Text title;

	sf::RectangleShape preButton;
	sf::Text preText;

	sf::Text studentProfile;
	sf::RectangleShape backgr;

	int i = 0;
	ViewStudentProfileScene(Static* a);
	void drawProfile(sf::RenderWindow& win, Static *a);
	void renderProfile(sf::Event event, Scene *scene, sf::RenderWindow& win);
};