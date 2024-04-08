#include "ChooseClassCourse.h"
#include "../Class.h"
#include "Scene.h"

ChooseClassCourseScene::ChooseClassCourseScene(Static* a)
{
	scrollOffset = 0.0f;


	createABox(chooseClassBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(chooseClassText, a->fontB, a->textColorBlue, "Choose Class in", 60, a->width / 2.0f, 50.0f);
	createText(classCText, a->fontB, a->textColorBlue, a->curCourse->Name, 60, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createABox(hideBack, sf::Vector2f((float)a->width, 250.0f), a->backGroundWhite, sf::Vector2f(a->width / 2.0f, 100.0f));

	listClassesC = new Course();
	numClass = listClassesC->loadClassesInCourse(a);
	tmpHead = listClassesC->pHeadClasses;
	
	buttons = new sf::ConvexShape[numClass];
	labels = new sf::Text[numClass];
	for (int i = 0; i < numClass; ++i) {
		sf::ConvexShape button;
		sf::Text label;
		if (i % 2 == 0)
			createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, tmpHead->className, sf::Vector2f((float)a->width / 2.0f - 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
		else
		{
			createCornerRoundedButton(button, label, sf::Vector2f(500.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, tmpHead->className, sf::Vector2f((float)a->width / 2.0f + 350.0f, 400.0f + (i / 2) * 300.0f), 2.0f, sf::Color::Black);
		}

		buttons[i] = button;
		tmpHead = tmpHead->pNext;
		labels[i] = label;
	}

	if (numClass % 2 == 0)
		times = numClass / 2;
	else
	{
		times = numClass / 2 + 1;
	}
	sizedisplay = a->height - 300.0f;
	fullsize = (times * 200 + (times - 1) * 100);

	createAScrollbar(scrollbar, scrollbarArea, sf::Vector2f(20.0f, 50.0f), a->backGroundWhiteDarkerStill, a->backGroundWhiteDarker, sf::Vector2f(1700.0f, 625.0f), 15);
}

void ChooseClassCourseScene::drawChooseClassCourses(sf::RenderWindow& window, Static* a)
{
	window.draw(chooseClassBackground);
	window.draw(preButton);
	window.draw(preText);
	for (int i = 0; i < numClass; i++) {
		buttons[i].setPosition(buttons[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - scrollOffset);
		labels[i].setPosition(labels[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - scrollOffset);
		window.draw(buttons[i]);
		window.draw(labels[i]);
	}
	window.draw(hideBack);
	window.draw(chooseClassText);
	window.draw(classCText);
	drawScrollBar(scrollbar, scrollbarArea, window, scrollOffset, sizedisplay, fullsize, sf::Vector2f(1700.0f, 275.0f));

}

void ChooseClassCourseScene::renderChooseClassCourses(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	for (int i = 0; i < numClass; i++) {
		if (scene->a->currentState == programState::ChooseClassCourse && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
			buttons[i].setFillColor(scene->a->pastelTitleCyan);
			labels[i].setFillColor(scene->a->titleGreyColor);
		}
		else {
			buttons[i].setFillColor(scene->a->highlightCyan);
			labels[i].setFillColor(sf::Color::White);
		}
	}
	if (scene->a->currentState == programState::ChooseClassCourse && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else
	{
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}

	tmpHead = listClassesC->pHeadClasses;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->chooseclasscourse;
				scene->chooseclasscourse = nullptr;
				if (scene->menucourse == nullptr)
					scene->menucourse = new MenuCourseScene(scene->a);
				scene->a->currentState = programState::MenuCourse;
			}
			else if (scrollbar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				isDragging = true;
				scrollbar.setFillColor(scene->a->backGroundWhiteMuchDarker);
			}
			else for (int i = 0; i < numClass; i++)
			{
				if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					//scene->a->curCourse->className = tmpHead->className;
					//if (scene->menuclass == nullptr)
					//	scene->menuclass = new MenuClassScene(scene->a);
					//scene->a->currentState = programState::MenuClass;
					//delete scene->chooseclasscourse;
					//scene->chooseclasscourse = nullptr;
					//break;
				}
				tmpHead = tmpHead->pNext;
			}
		}
	}

	if (numClass >= 6)
		renderScrollbar(scrollbar, scrollbarArea, window, scrollOffset, event, isDragging, scene->a, sf::Vector2f(1700.0f, 275.0f), sizedisplay, fullsize);



}

ChooseClassCourseScene::~ChooseClassCourseScene()
{
	delete[] buttons;
	delete[] labels;
	delete listClassesC;
}