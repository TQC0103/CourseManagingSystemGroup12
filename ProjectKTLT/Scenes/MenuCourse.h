#pragma once

#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"
#include "../Semester.h"

struct Scene;
struct MenuCourseScene
{
    sf::RectangleShape menuCourseBackground;
    sf::Text menuCourseText;
    sf::Text title;

    sf::ConvexShape preButton;
    sf::Text preText;

    sf::ConvexShape manageC;
    sf::Text manageCText;

    sf::ConvexShape addC;
    sf::Text addCText;

    MenuCourseScene(Static* a);
    void drawMenuCourse(sf::RenderWindow& window, Static* a);
    void renderMenuCourse(sf::Event event, Scene* scene, sf::RenderWindow& window);
};