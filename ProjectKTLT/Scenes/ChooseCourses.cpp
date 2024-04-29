#include "ChooseCourses.h"
#include "../Course.h"
#include "../Semester.h"
#include <fstream>
#include "Scene.h"
#include "../UserInterface.h"

ChooseCoursesScene::ChooseCoursesScene(Static* a)
{
    scrollOffset = 0.0f;
    createABox(chooseCoursesBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(chooseCoursesText, a->fontB, a->textColorBlue, "Choose Course", 80, (float)a->width / 2.0f, 75.0f);
    createText(pleaseAddCourse, a->fontB, a->blurGrey, "   There are no\ncourse currently", 100, a->width / 2.0f, a->height / 2.0f);
    createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
    createABox(hidden, sf::Vector2f((float)a->width, 250.0f), a->backGroundWhite, sf::Vector2f(a->width / 2.0f, 100.0f));

    curSemester = new semester();
    numCourses = curSemester->loadCourse(a);
    tmpHead = curSemester->pHeadCourse;
    if (tmpHead == nullptr)
        numCourses = 0;
    else {
        buttons = new sf::ConvexShape[numCourses];
        labels = new sf::Text[numCourses];
        labels2 = new sf::Text[numCourses];
        isRightClicked = new bool[numCourses];
        for (int i = 0; i < numCourses; i++)
			isRightClicked[i] = false;
    }
    // Create buttons and labels

    for (int i = 0; i < numCourses; ++i) {
        sf::ConvexShape button;
        sf::Text label;
        sf::Text label2;
        if (i % 2 == 0)
        {
            std::string text = tmpHead->ID;
            std::string text2 =  tmpHead->Name;
            createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "", sf::Vector2f((float)a->width / 2.0f - 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
            createText(label, a->fontB, sf::Color::White, text, 40, button.getPosition().x, button.getPosition().y + 30);
            if(text2.length() > 25)
				createText(label2, a->fontB, sf::Color::White, text2, 27, button.getPosition().x, button.getPosition().y - 30);
            else if(text2.length() > 20)
                createText(label2, a->fontB, sf::Color::White, text2, 30, button.getPosition().x, button.getPosition().y - 30);
			else
				createText(label2, a->fontB, sf::Color::White, text2, 40, button.getPosition().x, button.getPosition().y - 30);
        }
        else
        {
            std::string text = tmpHead->ID;
            std::string text2 =  tmpHead->Name;
            createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "", sf::Vector2f((float)a->width / 2.0f + 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
            createText(label, a->fontB, sf::Color::White, text, 40, button.getPosition().x, button.getPosition().y + 30);
            if (text2.length() > 25)
                createText(label2, a->fontB, sf::Color::White, text2, 27, button.getPosition().x, button.getPosition().y - 30);
            else if (text2.length() > 20)
                createText(label2, a->fontB, sf::Color::White, text2, 30, button.getPosition().x, button.getPosition().y - 30);
            else
                createText(label2, a->fontB, sf::Color::White, text2, 40, button.getPosition().x, button.getPosition().y - 30);
        }
        buttons[i] = button;
        labels[i] = label;
        labels2[i] = label2;
        tmpHead = tmpHead->pNext;
    }

    if (numCourses % 2 == 0)
        times = numCourses / 2;
    else
    {
        times = numCourses / 2 + 1;
    }
    displaysize = a->height - 300.0f;
    fullsize = (float)(times * 200 + (times - 1) * 100 );
    if (numCourses > 6)
        createAScrollbar(scrollbar, scrollArea, sf::Vector2f(20.0f, 50.0f), a->backGroundWhiteDarkerStill, a->backGroundWhiteDarker, sf::Vector2f(1700.0f, 625.0f), 15);
}

void ChooseCoursesScene::drawChooseCourses(sf::RenderWindow& window, Static* a)
{
    window.draw(chooseCoursesBackground);
    window.draw(preButton);
    window.draw(preText);
    
    if (numCourses == 0)
        window.draw(pleaseAddCourse);
    else 
    {
        for (int i = 0; i < numCourses; i++) {
            buttons[i].setPosition(buttons[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - scrollOffset);
            window.draw(buttons[i]);
            if (isRightClicked[i] == true)
            {
                buttons[i].setFillColor(sf::Color::Red);
                sf::Text de;
                createText(de, a->fontB, sf::Color::White, "Delete", 60, buttons[i].getPosition().x, buttons[i].getPosition().y);
                window.draw(de);
            }
            else {
                labels[i].setPosition(labels[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - 30 - scrollOffset);
                labels2[i].setPosition(labels[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f + 30 - scrollOffset);
                window.draw(labels[i]);
                window.draw(labels2[i]);
            }
        }
    }
    window.draw(hidden);
    if (numCourses >= 6)
        drawScrollBar(scrollbar, scrollArea, window, scrollOffset, displaysize, fullsize, sf::Vector2f(1700.0f, 275.0f));
    window.draw(chooseCoursesText);
}

void ChooseCoursesScene::renderChooseCourses(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::ChooseCourses && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        preButton.setFillColor(scene->a->pastelTitleCyan);
        preText.setFillColor(scene->a->titleGreyColor);
    }
    else
    {
        preButton.setFillColor(scene->a->highlightCyan);
        preText.setFillColor(sf::Color::White);
    }
    for (int i = 0; i < numCourses; i++) {
        if ((isRightClicked[i] == false && scene->a->currentState == programState::ChooseCourses) && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            buttons[i].setFillColor(scene->a->pastelTitleCyan);
            labels[i].setFillColor(scene->a->titleGreyColor);
            labels2[i].setFillColor(scene->a->titleGreyColor);
        }
        else if (isRightClicked[i] == false) {
            buttons[i].setFillColor(scene->a->highlightCyan);
            labels[i].setFillColor(sf::Color::White);
            labels2[i].setFillColor(sf::Color::White);
        }
    }
    if(numCourses >= 6)
        renderScrollbar(scrollbar, scrollArea, window, scrollOffset, event, isDragging, scene->a, sf::Vector2f(1700.0f, 275.0f), displaysize, fullsize);
    tmpHead = curSemester->pHeadCourse;

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->choosecoursescene;
                scene->choosecoursescene = nullptr;
                if (scene->menusemester == nullptr)
                    scene->menusemester = new MenuSemesterScene(scene->a);
                scene->a->currentState = programState::MenuSemester;
            }
            else for (int i = 0; i < numCourses; i++) {
                if (isRightClicked[i] == false && buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    scene->a->curCourse = new Course();
                    *(scene->a->curCourse) = *tmpHead;
                    delete scene->choosecoursescene;
                    scene->choosecoursescene = nullptr;
                    if (scene->menucourse == nullptr)
                        scene->menucourse = new MenuCourseScene(scene->a);
                    scene->a->currentState = programState::MenuCourse;
                    break;
                }
                else if (isRightClicked[i] == true && buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                {
                    semester* tmp = new semester;
                    bool check = tmp->deleteCourse(tmpHead->Name, scene->a);
                    delete tmp;
                    if (check == true)
                    {
                        delete scene->choosecoursescene;
                        scene->choosecoursescene = nullptr;
                        if (scene->choosecoursescene == nullptr)
                            scene->choosecoursescene = new ChooseCoursesScene(scene->a); 
                        break;
                    }
                    
                }
                tmpHead = tmpHead->pNext;
            }
        }
        else if (event.mouseButton.button == sf::Mouse::Right)
        {
            for (int i = 0; i < numCourses; i++) {
                if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    
                    if (isRightClicked[i] == false)
                    {
                        isRightClicked[i] = true;
                        for (int j = 0; j < numCourses; j++)
                        {
							if (j != i)
								isRightClicked[j] = false;
						}
                    }
                    else {
                        isRightClicked[i] = false;
                    }
                    break;
                }
                tmpHead = tmpHead->pNext;
            }
        }
    }

}

ChooseCoursesScene::~ChooseCoursesScene()
{
    if (numCourses != 0)
    {
        delete[] buttons;
        delete[] labels;
        delete[] labels2;
        delete[] isRightClicked;
    }
    delete curSemester;
}


