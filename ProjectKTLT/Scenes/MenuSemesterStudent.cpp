#include "MenuSemesterStudent.h"
#include "../Semester.h"
#include <fstream>
#include "Scene.h"

MenuSemesterStudentScene::MenuSemesterStudentScene(Static* a)
{
    createABox(menuSemesterStudentBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(menuSemesterStudentText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 100, (float)a->width / 2.0f, 150.0f);
    createCornerRoundedButton(viewCourses, viewCoursesText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "View courses", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
    createCornerRoundedButton(viewScoreboard, viewScoreboardText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "View scoreboard", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
    createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Re-select", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);

}

void MenuSemesterStudentScene::drawMenuSemester(sf::RenderWindow& window, Static* a)
{
    window.draw(menuSemesterStudentBackground);
    window.draw(menuSemesterStudentText);
    window.draw(viewCourses);
    window.draw(viewCoursesText);
    window.draw(viewScoreboard);
    window.draw(viewScoreboardText);
    window.draw(preButton);
    window.draw(preText);
}

void MenuSemesterStudentScene::renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::MenuSemesterStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        preButton.setFillColor(scene->a->pastelTitleCyan);
        preText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::MenuSemesterStudent && viewCourses.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        viewCourses.setFillColor(scene->a->pastelTitleCyan);
        viewCoursesText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::MenuSemesterStudent && viewScoreboard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        viewScoreboard.setFillColor(scene->a->pastelTitleCyan);
        viewScoreboardText.setFillColor(scene->a->titleGreyColor);
    }
    else
    {
        preButton.setFillColor(scene->a->highlightCyan);
        preText.setFillColor(sf::Color::White);
        viewCourses.setFillColor(scene->a->highlightCyan);
        viewCoursesText.setFillColor(sf::Color::White);
        viewScoreboard.setFillColor(scene->a->highlightCyan);
        viewScoreboardText.setFillColor(sf::Color::White);
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->menusemesterstudent;
                scene->menusemesterstudent = nullptr;
                if (scene->choosesemesterstudent == nullptr)
                    scene->choosesemesterstudent = new ChooseSemesterStudentScene(scene->a);
                scene->a->currentState = programState::ChooseSemesterStudent;
                delete scene->a->curSemester;
                scene->a->curSemester = nullptr;
            }
            else if (viewCourses.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
				delete scene->menusemesterstudent;
				scene->menusemesterstudent = nullptr;
				if (scene->viewcoursesstudent == nullptr)
					scene->viewcoursesstudent = new ViewCoursesStudentScene(scene->a);
                scene->a->currentState = programState::ViewCoursesStudent;
			}
            else if (viewScoreboard.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
				delete scene->menusemesterstudent;
                scene->menusemesterstudent = nullptr;
                if (scene->viewscoreboardstudent == nullptr)
					scene->viewscoreboardstudent = new ViewScoreboardScene(scene->a);
                scene->a->currentState = programState::ViewScoreboardStudent;
			}
        }
    }
}

