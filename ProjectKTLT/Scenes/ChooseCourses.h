#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Course.h"
#include "../Semester.h"

struct Scene;
struct ChooseCoursesScene
{
    sf::RectangleShape chooseCoursesBackground;
    sf::Text chooseCoursesText;
    sf::RectangleShape hidden;
    
    sf::RectangleShape scrollbar;
    sf::RectangleShape scrollArea;

    semester* curSemester = nullptr;
    Course* tmpHead = nullptr;

    sf::ConvexShape* buttons;
    sf::Text* labels;
    sf::Text* labels2;

    int numCourses = 0;
    int times = 0;
    bool isDragging = false;
    float scrollOffset;
    float fullsize = 0;
    float displaysize = 0;

    sf::ConvexShape preButton;
    sf::Text preText;

    sf::Text pleaseAddCourse;

    ChooseCoursesScene(Static* a);
    ~ChooseCoursesScene();
    void drawChooseCourses(sf::RenderWindow& window, Static* a);
    void renderChooseCourses(sf::Event event, Scene* scene, sf::RenderWindow& window);
};