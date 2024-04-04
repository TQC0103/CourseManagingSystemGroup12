#include "MenuSemesterStudent.h"
#include "../Semester.h"
#include <fstream>
#include "Scene.h"

MenuSemesterStudentScene::MenuSemesterStudentScene(Static* a)
{
    createABox(menuSemesterStudentBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(menuSemesterStudentText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 100, (float)a->width / 2.0f, 150.0f);
    createCornerRoundedButton(viewCourses, viewCoursesText, sf::Vector2f(1000.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "View scoreboard", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
    createCornerRoundedButton(viewScoreboard, viewScoreboardText, sf::Vector2f(1000.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "View courses", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
}

void MenuSemesterStudentScene::drawMenuSemester(sf::RenderWindow& window, Static* a)
{
    window.draw(menuSemesterStudentBackground);
    window.draw(menuSemesterStudentText);
    window.draw(viewCourses);
    window.draw(viewCoursesText);
    window.draw(viewScoreboard);
    window.draw(viewScoreboardText);
}

void MenuSemesterStudentScene::renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
 
}

