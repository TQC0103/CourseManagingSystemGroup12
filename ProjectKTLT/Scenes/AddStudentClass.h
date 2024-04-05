#pragma once
#include "../UserInterface.h"
#include <SFML/Graphics.hpp>
#include "../Semester.h"

struct Scene;
struct AddStudentClassScene
{
    sf::RectangleShape addStudentBackgr;
    sf::Text addStudentText;

    sf::ConvexShape addManually;
    sf::Text addManuallyText;

    sf::ConvexShape addFile;
    sf::Text addFileText;

    sf::ConvexShape preButton;
    sf::Text preText;

    AddStudentClassScene(Static* a);
    void drawAddStudentClass(sf::RenderWindow& window, Static* a);
    void renderAddStudentClass(sf::Event event, Scene* scene, sf::RenderWindow& window);
};
