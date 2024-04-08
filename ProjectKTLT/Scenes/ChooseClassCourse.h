#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Course.h"
#include "../Semester.h"

struct Scene;
struct ChooseClassCourseScene
{
	sf::RectangleShape chooseClassBackground;
	sf::Text chooseClassText;
	sf::Text classCText;

	sf::ConvexShape preButton;
	sf::Text preText;

	int numClass = 0;
	bool isDragging = false;
	float scrollOffset;
	sf::RectangleShape hideBack;
	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollbarArea;

	sf::ConvexShape* buttons = nullptr;
	sf::Text* labels = nullptr;
	Course* listClassesC = nullptr;
	Course* tmpHead = nullptr;

	int times = 0;
	float sizedisplay = 0;
	float fullsize = 0;

    ChooseClassCourseScene(Static* a);
    ~ChooseClassCourseScene();
    void drawChooseClassCourses(sf::RenderWindow& window, Static* a);
    void renderChooseClassCourses(sf::Event event, Scene* scene, sf::RenderWindow& window);
};
