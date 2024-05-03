#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../SchoolYear.h"

struct Scene;
struct ChooseSchoolYearStudentScene
{
    sf::RectangleShape chooseSchoolYearBackground;
    sf::Text chooseSchoolYearText;

    sf::ConvexShape* buttons;
    sf::Text* labels;
    schoolYear* listSchoolYear = nullptr; // LL
    sf::Text needParticipation;

    int numSchoolYears = 0;

    sf::ConvexShape preButton;
    sf::Text preText;

    ChooseSchoolYearStudentScene(Static* a);
    ~ChooseSchoolYearStudentScene();
    void drawChooseSchoolYear(sf::RenderWindow& window, Static* a);
    void renderChooseSchoolYear(sf::Event event, Scene* scene, sf::RenderWindow& window);
};