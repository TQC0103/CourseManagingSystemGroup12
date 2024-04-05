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

    sf::ConvexShape preButton;
    sf::Text preText;

    MenuSemesterScene(Static* a);
    ~MenuSemesterScene();
    void drawMenuSemester(sf::RenderWindow& window, Static* a);
    void renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window);
};