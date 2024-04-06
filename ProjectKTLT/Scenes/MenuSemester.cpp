#include "MenuSemester.h"
#include "Scene.h"

MenuSemesterScene::MenuSemesterScene(Static* a)
{
	createABox(menuSemesterBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Menu Semester", 80, (float)a->width / 2.0f, 75.0f);
	createText(menuSemesterText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 80, (float)a->width / 2.0f, 200.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(addC, addCText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add a course", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
	createCornerRoundedButton(manageC, manageCText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Manage courses", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
}

void MenuSemesterScene::drawMenuSemester(sf::RenderWindow& window, Static* a)
{
	window.draw(menuSemesterBackground);
	window.draw(title);
	window.draw(menuSemesterText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(addC);
	window.draw(addCText);
	window.draw(manageC);
	window.draw(manageCText);
}

void MenuSemesterScene::renderMenuSemester(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::MenuSemester)
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
				delete scene->menusemester;
				scene->menusemester = nullptr;
				delete scene->a->curSemester;
				scene->a->curSemester = nullptr;
				if (scene->choosesemester == nullptr)
					scene->choosesemester = new ChooseSemesterScene(scene->a);
				scene->a->currentState = programState::ChooseSemester;
			}
			else if (addC.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				
			}
			else if (manageC.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				
			}
		}
	}
}
