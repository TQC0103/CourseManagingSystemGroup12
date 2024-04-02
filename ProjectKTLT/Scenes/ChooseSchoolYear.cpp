#include "ChooseSchoolYear.h"
#include "../SchoolYear.h"
#include <fstream>
#include "Scene.h"

ChooseSchoolYearScene::ChooseSchoolYearScene(Static* a)
{
    createABox(chooseSchoolYearBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(chooseSchoolYearText, a->fontB, a->textColorBlue, "Choose school year", 100, (float)a->width / 2.0f, 150.0f);
    createAButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f));
    
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
    
    buttons = new sf::RectangleShape[numSchoolYears];
    labels = new sf::Text[numSchoolYears];


    // Create buttons and labels

    for (int i = 0; i < numSchoolYears ; ++i) {
        sf::RectangleShape button;
        if(i % 2 == 0)
            createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f - 350.0f, 400.0f + (i / 2) * 300.0f));
        else
        {
            createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f + 350.0f, 400.0f + (i / 2) * 300.0f));
        }

        buttons[i] = button;

       sf::Text label;
       createText(label, a->fontB, sf::Color::White, tmpHead->year, 60, buttons[i].getPosition().x, buttons[i].getPosition().y);
       tmpHead = tmpHead->pNext;
       labels[i] = label;
    }
}

void ChooseSchoolYearScene::drawChooseSchoolYear(sf::RenderWindow &window, Static *a)
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

void ChooseSchoolYearScene::renderChooseSchoolYear(sf::Event event, Scene *scene, sf::RenderWindow& window)
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::ChooseSchoolYear && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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
        if (scene->a->currentState == programState::ChooseSchoolYear && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
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
                if (scene->menustaff == nullptr)
                    scene->menustaff = new MenuStaffScene(scene->a);
                scene->a->currentState = programState::MenuStaff;

            }
            else for (int i = 0; i < numSchoolYears; i++) {
                if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                    scene->a->curSchoolYear = new schoolYear();
                    *(scene->a->curSchoolYear) = *tmpHead;
                    if(scene->menuschoolyear == nullptr)
                        scene->menuschoolyear = new MenuSchoolYearScene(scene->a);
                    scene->a->currentState = programState::MenuSchoolYear;
                    delete scene->chooseschoolyear;
                    scene->chooseschoolyear = nullptr;
                    break;
                }
                else {
					tmpHead = tmpHead->pNext;
				}
            }
            
            
            
        }
    }
    
}

ChooseSchoolYearScene::~ChooseSchoolYearScene()
{
    delete[] buttons;
    delete[] labels;
    listSchoolYear->~schoolYear();
}

