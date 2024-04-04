#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Semester.h"

struct Scene;
struct MenuSemesterStudentScene
{
    sf::RectangleShape menuSemesterStudentBackground;
    sf::Text menuSemesterStudentText;

    sf::ConvexShape viewCourses;
    sf::Text viewCoursesText;

    sf::ConvexShape viewScoreboard;
    sf::Text viewScoreboardText;

    sf::ConvexShape preButton;
    sf::Text preText;

    MenuSemesterStudentScene(Static* a);
    void drawMenuSemester(sf::RenderWindow& window, Static* a);
    void renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window);
};
