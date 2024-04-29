#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Semester.h"

struct Scene;
struct ChooseSemesterClassScene
{
    sf::RectangleShape chooseSemesterBackground;
    sf::Text chooseSemesterText;
    sf::Text yearText;

    schoolYear* year = nullptr;
    semester* tmpHead = nullptr;
    sf::ConvexShape* buttons;
    sf::Text* labels;

    int numSemester = 0;

    sf::ConvexShape preButton;
    sf::Text preText;

    ChooseSemesterClassScene(Static* a);
    ~ChooseSemesterClassScene();
    void drawChooseSemesterClassScene(sf::RenderWindow& window, Static* a);
    void renderChooseSemesterClassScene(sf::Event event, Scene* scene, sf::RenderWindow& window);
};