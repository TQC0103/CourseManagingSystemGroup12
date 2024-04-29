#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"

struct Scene;
struct ChooseSchoolYearClassScene
{
    sf::RectangleShape chooseSchoolYearBackground;
    sf::Text chooseSchoolYearText;

    sf::ConvexShape* buttons;
    sf::Text* labels;
    schoolYear* listSchoolYear = nullptr; // LL


    int numSchoolYears = 0;

    sf::ConvexShape preButton;
    sf::Text preText;

    ChooseSchoolYearClassScene(Static* a);
    ~ChooseSchoolYearClassScene();
    void drawChooseSchoolYearClassScene(sf::RenderWindow& window, Static* a);
    void renderChooseSchoolYearClassScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
};