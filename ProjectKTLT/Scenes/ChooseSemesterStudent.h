#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Semester.h"

struct Scene;
struct ChooseSemesterStudentScene
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

    sf::Text needParticipation;

    ChooseSemesterStudentScene(Static* a);
    ~ChooseSemesterStudentScene();
    void drawChooseSemester(sf::RenderWindow& window, Static* a);
    void renderChooseSemester(sf::Event event, Scene* scene, sf::RenderWindow& window);
};