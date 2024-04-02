#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Semester.h"

struct Scene;
struct ChooseSchoolSemesterScene
{
    sf::RectangleShape chooseSemesterYearBackground;
    sf::Text chooseSemesterYearText;

    semester* listSemester = nullptr;  

    sf::ConvexShape* buttons;
    sf::Text* labels;

    int numSemester = 0;

    sf::ConvexShape preButton;
    sf::Text preText;

    ChooseSchoolSemesterScene(Static* a);
    ~ChooseSchoolSemesterScene();
    void drawChooseSemester(sf::RenderWindow& window, Static* a);
    void renderChooseSemester(sf::Event event, Scene* scene, sf::RenderWindow& window);
};