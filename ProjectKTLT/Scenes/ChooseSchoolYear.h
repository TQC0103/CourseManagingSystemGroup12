#pragma once
#include <SFML/Graphics.hpp>
#include "../UserInterface.h"
#include "../config.h"
#include "../SchoolYear.h"
<<<<<<< Updated upstream
=======
struct Scene;

>>>>>>> Stashed changes

struct ChooseSchoolYearScene
{
    sf::RectangleShape chooseSchoolYearBackground;
    sf::Text chooseSchoolYearText;



    sf::RectangleShape* buttons;
    sf::Text* labels;
    schoolYear *listSchoolYear = nullptr; // LL


    int numSchoolYears = 0;

    sf::RectangleShape preButton;
    sf::Text preText;

    ChooseSchoolYearScene(Static* a);
    ~ChooseSchoolYearScene();
    void drawChooseSchoolYear(sf::RenderWindow& window, Static* a);
    void renderChooseSchoolYear(sf::Event event, Scene *scene, sf::RenderWindow& window);
};