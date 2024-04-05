#include "ChooseSemester.h"
#include "../Semester.h"
#include <fstream>
#include "Scene.h"

ChooseSemesterScene::ChooseSemesterScene(Static* a)
{
    createABox(chooseSemesterBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(chooseSemesterText, a->fontB, a->textColorBlue, "Choose Semester", 80, (float)a->width / 2.0f, 75.0f);
    createText(pleaseAddSemester, a->fontB, a->blurGrey, "     There are no\nsemester currently", 100, a->width / 2.0f, a->height / 2.0f);
    createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
    year = new schoolYear();
    year->loadSemester(a->curSchoolYear->year);
    tmpHead = year->pHeadSemester;
    if (tmpHead == nullptr)
        numSemester = 0;
    else {
        while (tmpHead != nullptr)
        {
            numSemester++;
            tmpHead = tmpHead->pNext;
        }
        tmpHead = year->pHeadSemester;

        buttons = new sf::ConvexShape[numSemester];
        labels = new sf::Text[numSemester];
    }

    // Create buttons and labels

    for (int i = 0; i < numSemester; ++i) {
        sf::ConvexShape button;
        sf::Text label;
        std::string text = tmpHead->semesterData;
        text = text + text[text.size() - 1];
        text[8] = ' ';
        createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 60, a->highlightCyan, a->fontB, sf::Color::White, text, sf::Vector2f((float)a->width / 2.0f, 400.0f + i * 300.0f), 2.0f, sf::Color::Black);
        buttons[i] = button;
        labels[i] = label;
        tmpHead = tmpHead->pNext;
    }
}

void ChooseSemesterScene::drawChooseSemester(sf::RenderWindow& window, Static* a)
{
    window.draw(chooseSemesterBackground);
    window.draw(chooseSemesterText);
    window.draw(preButton);
    window.draw(preText);
    if (numSemester == 0)
        window.draw(pleaseAddSemester);
    for (int i = 0; i < numSemester; i++) {
        if (i == 0)
            createText(yearText, a->fontB, a->textColorBlue, a->curSchoolYear->year, 80, (float)a->width / 2.0f, 200.0f);
        window.draw(buttons[i]);
        window.draw(labels[i]);
    }
    window.draw(yearText);
}

void ChooseSemesterScene::renderChooseSemester(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::ChooseSemester && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        preButton.setFillColor(scene->a->pastelTitleCyan);
        preText.setFillColor(scene->a->titleGreyColor);
    }
    else
    {
        preButton.setFillColor(scene->a->highlightCyan);
        preText.setFillColor(sf::Color::White);
    }
    for (int i = 0; i < numSemester; i++) {
        if (scene->a->currentState == programState::ChooseSemester && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            buttons[i].setFillColor(scene->a->pastelTitleCyan);
            labels[i].setFillColor(scene->a->titleGreyColor);
        }
        else {
            buttons[i].setFillColor(scene->a->highlightCyan);
            labels[i].setFillColor(sf::Color::White);
        }
    }
    tmpHead = year->pHeadSemester;
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->choosesemester;
                scene->choosesemester = nullptr;
                if (scene->menuschoolyear == nullptr)
                    scene->menuschoolyear = new MenuSchoolYearScene(scene->a);
                scene->a->currentState = programState::MenuSchoolYear;
            }
            else for (int i = 0; i < numSemester; i++) {
                if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    scene->a->curSemester = new semester();
                    *(scene->a->curSemester) = *tmpHead;
                    if (scene->menusemester == nullptr)
                        scene->menusemester = new MenuSemesterScene(scene->a);
                    scene->a->currentState = programState::MenuSemester;
                    delete scene->choosesemester;
                    scene->choosesemester = nullptr;
                    break;
                }
                tmpHead = tmpHead->pNext;
            }
        }
    }

}

ChooseSemesterScene::~ChooseSemesterScene()
{
    if(numSemester != 0)
    {
        delete[] buttons;
        delete[] labels;
    }
    delete year;
}

