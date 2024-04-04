#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"

struct Scene;
struct ChooseSchoolYearScene
{
    sf::RectangleShape chooseSchoolYearBackground;
    sf::Text chooseSchoolYearText;



    sf::ConvexShape* buttons;
    sf::Text* labels;
    schoolYear *listSchoolYear = nullptr; // LL


    int numSchoolYears = 0;

    sf::ConvexShape  preButton;
    sf::Text preText;

    sf::Text pleaseAddYear;

    ChooseSchoolYearScene(Static* a);
    ~ChooseSchoolYearScene();
    void drawChooseSchoolYear(sf::RenderWindow& window, Static* a);
    void renderChooseSchoolYear(sf::Event event, Scene *scene, sf::RenderWindow& window);
};