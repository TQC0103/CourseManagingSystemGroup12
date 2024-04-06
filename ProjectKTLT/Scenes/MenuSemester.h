#pragma once

#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"
#include "../Semester.h"

struct Scene;
struct MenuSemesterScene
{
    sf::RectangleShape menuSemesterBackground;
    sf::Text menuSemesterText;
    sf::Text title;

    sf::ConvexShape preButton;
    sf::Text preText;

    sf::ConvexShape manageC;
    sf::Text manageCText;

    sf::ConvexShape addC;
    sf::Text addCText;

    MenuSemesterScene(Static* a);
    void drawMenuSemester(sf::RenderWindow& window, Static* a);
    void renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window);
};