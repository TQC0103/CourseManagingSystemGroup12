#include "ChooseSchoolYearStudent.h"
#include "../SchoolYear.h"
#include <fstream>
#include "Scene.h"

ChooseSchoolYearStudentScene::ChooseSchoolYearStudentScene(Static* a)
{
    createABox(chooseSchoolYearBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(chooseSchoolYearText, a->fontB, a->textColorBlue, "Choose School Year", 100, (float)a->width / 2.0f, 150.0f);
    createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);

    listSchoolYear = new schoolYear();
    listSchoolYear->loadSchoolYear();
    schoolYear* tmpHead = listSchoolYear->pHead;
    while (tmpHead)
    {
        numSchoolYears++;
        tmpHead = tmpHead->pNext;
    }
    if (numSchoolYears > 6)
    {
        numSchoolYears = 6;
    }
    tmpHead = listSchoolYear->pHead;

    buttons = new sf::ConvexShape[numSchoolYears];
    labels = new sf::Text[numSchoolYears];


    // Create buttons and labels

    for (int i = 0; i < numSchoolYears; ++i) {
        sf::ConvexShape button;
        sf::Text label;
        if (i % 2 == 0)
            createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, tmpHead->year,  sf::Vector2f((float)a->width / 2.0f - 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
        else
        {
            createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, tmpHead->year, sf::Vector2f((float)a->width / 2.0f + 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
        }

        buttons[i] = button;
        tmpHead = tmpHead->pNext;
        labels[i] = label;
    }
}

void ChooseSchoolYearStudentScene::drawChooseSchoolYear(sf::RenderWindow& window, Static* a)
{
    window.draw(chooseSchoolYearBackground);
    window.draw(chooseSchoolYearText);
    window.draw(preButton);
    window.draw(preText);

    for (int i = 0; i < numSchoolYears; i++) {
        window.draw(buttons[i]);
        window.draw(labels[i]);
    }
}

void ChooseSchoolYearStudentScene::renderChooseSchoolYear(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::ChooseSchoolYearStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        preButton.setFillColor(scene->a->pastelTitleCyan);
        preText.setFillColor(scene->a->titleGreyColor);
    }
    else
    {
        preButton.setFillColor(scene->a->highlightCyan);
        preText.setFillColor(sf::Color::White);
    }
    for (int i = 0; i < numSchoolYears; i++) {
        if (scene->a->currentState == programState::ChooseSchoolYearStudent && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            buttons[i].setFillColor(scene->a->pastelTitleCyan);
            labels[i].setFillColor(scene->a->titleGreyColor);
        }
        else {
            buttons[i].setFillColor(scene->a->highlightCyan);
            labels[i].setFillColor(sf::Color::White);
        }
    }

    schoolYear* tmpHead = listSchoolYear->pHead;
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->chooseschoolyear;
                scene->chooseschoolyear = nullptr;
                if (scene->menustudent == nullptr)
                    scene->menustudent = new MenuStudentScene(scene->a);
                scene->a->currentState = programState::MenuStudent;

            }
            else for (int i = 0; i < numSchoolYears; i++) {
                if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    scene->a->curSchoolYear = new schoolYear();
                    *(scene->a->curSchoolYear) = *tmpHead;
                    if (scene->choosesemesterstudent == nullptr)
                        scene->choosesemesterstudent = new ChooseSemesterStudentScene(scene->a);
                    scene->a->currentState = programState::ChooseSemesterStudent;
                    delete scene->chooseschoolyearstudent;
                    scene->chooseschoolyearstudent = nullptr;
                    break;
                }
                tmpHead = tmpHead->pNext;
            }



        }
    }

}

ChooseSchoolYearStudentScene::~ChooseSchoolYearStudentScene()
{
    delete[] buttons;
    delete[] labels;
    delete listSchoolYear;
}

