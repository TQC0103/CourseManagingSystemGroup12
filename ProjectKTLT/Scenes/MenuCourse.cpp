#include "MenuCourse.h"
#include "Scene.h"

MenuCourseScene::MenuCourseScene(Static* a)
{
	createABox(menuCourseBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Menu Course", 80, (float)a->width / 2.0f, 75.0f);
	createText(menuCourseText, a->fontB, a->textColorBlue,a->curCourse->Name, 80, (float)a->width / 2.0f, 200.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Re-select", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(addC, addCText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add a class course", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
	createCornerRoundedButton(manageC, manageCText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Manage classes this course", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
}

void MenuCourseScene::drawMenuCourse(sf::RenderWindow& window, Static* a)
{
	window.draw(menuCourseBackground);
	window.draw(title);
	window.draw(menuCourseText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(addC);
	window.draw(addCText);
	window.draw(manageC);
	window.draw(manageCText);
}

void MenuCourseScene::renderMenuCourse(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::MenuCourse)
	{
		if (preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			preButton.setFillColor(scene->a->pastelTitleCyan);
			preText.setFillColor(scene->a->titleGreyColor);
		}
		else if (addC.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			addC.setFillColor(scene->a->pastelTitleCyan);
			addCText.setFillColor(scene->a->titleGreyColor);
		}
		else if (manageC.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			manageC.setFillColor(scene->a->pastelTitleCyan);
			manageCText.setFillColor(scene->a->titleGreyColor);
		}
		else {
			preButton.setFillColor(scene->a->highlightCyan);
			preText.setFillColor(sf::Color::White);
			addC.setFillColor(scene->a->highlightCyan);
			addCText.setFillColor(sf::Color::White);
			manageC.setFillColor(scene->a->highlightCyan);
			manageCText.setFillColor(sf::Color::White);
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menucourse;
				scene->menucourse = nullptr;
				delete scene->a->curCourse;
				scene->a->curCourse = nullptr;
				if (scene->choosecoursescene == nullptr)
					scene->choosecoursescene = new ChooseCoursesScene(scene->a);
				scene->a->currentState = programState::ChooseCourses;
			}
			else if (addC.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menucourse;
				scene->menucourse = nullptr;
				if (scene->addclasscourse == nullptr)
					scene->addclasscourse = new AddClassCourseScene(scene->a);
				scene->a->currentState = programState::AddClassCourse;
			}
			else if (manageC.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menucourse;
				scene->menucourse = nullptr;
				if (scene->chooseclasscourse == nullptr)
					scene->chooseclasscourse = new ChooseClassCourseScene(scene->a);
				scene->a->currentState = programState::ChooseClassCourse;
			}
		}
	}
}
