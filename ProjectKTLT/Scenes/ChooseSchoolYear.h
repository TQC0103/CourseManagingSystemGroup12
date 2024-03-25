#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"
#include "../config.h"

struct ChooseSchoolYearScene
{
    sf::RectangleShape chooseSchoolYearBackground;
    sf::Text chooseSchoolYearText;



    sf::RectangleShape* buttons;
    sf::Text* labels;
    std::string* schoolYears; // LL


    int numSchoolYears = 0;

    sf::RectangleShape preButton;
    sf::Text preText;

    ChooseSchoolYearScene(Static* a);
    ~ChooseSchoolYearScene();
    void drawChooseSchoolYear(sf::RenderWindow& window, Static* a);
    void renderChooseSchoolYear(sf::Event event, Static* a, sf::RenderWindow& window);
};