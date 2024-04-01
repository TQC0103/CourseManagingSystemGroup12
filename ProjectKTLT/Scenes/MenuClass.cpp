#include "MenuClass.h"
#include "../UserInterface.h"
#include "../config.h"
#include "../Class.h"
#include "Scene.h"

MenuClassScene::MenuClassScene(Static* a)
{
	createABox(menuClassBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(menuClassText, a->fontB, a->textColorBlue, "Menu Class", 100, a->width / 2.0f, 100.0f);
	createAButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f));
	createAButton(addStudentButton, addStudentText, sf::Vector2f(400.0f, 155.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add student", sf::Vector2f(a->width / 2.0f - 300.0f, 500.0f));
	createAButton(viewStudentGPA, viewStudentGPAText, sf::Vector2f(400.0f, 155.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "View students GPA", sf::Vector2f(a->width / 2.0f - 300.0f, 750.0f));
	createAButton(viewMembers, viewMembersText, sf::Vector2f(400.0f, 155.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "View members", sf::Vector2f(a->width / 2.0f + 300.0f, 500.0f));
}

void MenuClassScene::drawMenuClass(sf::RenderWindow& window, Static* a)
{
	if (i == 0)
	{
		createText(classText, a->fontB, a->textColorBlue, a->curClass->name, 100, a->width / 2.0f, 250.0f);
		i++;
	}
	window.draw(menuClassBackground);
	window.draw(menuClassText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(addStudentButton);
	window.draw(addStudentText);
	window.draw(viewStudentGPA);
	window.draw(viewStudentGPAText);
	window.draw(viewMembers);
	window.draw(viewMembersText);
	if (i == 0)
	{
		std::string className = "- " + a->curClass->name + " -";
		createText(classText, a->fontB, a->textColorBlue, className, 100, a->width / 2.0f, 250.0f);
		i++;
	}
	window.draw(classText);
}

void MenuClassScene::renderMenuClass(sf::Event event, Scene *scene, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				scene->a->curClass = nullptr;
				delete scene->menuclass;
				scene->menuclass = nullptr;
				if(scene->chooseclass == nullptr)
					scene->chooseclass = new ChooseClassScene(scene->a);
				scene->a->currentState = programState::ChooseClass;
			}
			else if (addStudentButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{

			}
			else if (viewStudentGPA.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{

			}
			else if (viewMembers.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{

			}
		}
	}
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::MenuClass && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuClass && addStudentButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		addStudentButton.setFillColor(scene->a->pastelTitleCyan);
		addStudentText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuClass && viewStudentGPA.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewStudentGPA.setFillColor(scene->a->pastelTitleCyan);
		viewStudentGPAText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuClass && viewMembers.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewMembers.setFillColor(scene->a->pastelTitleCyan);
		viewMembersText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		addStudentButton.setFillColor(scene->a->highlightCyan);
		addStudentText.setFillColor(sf::Color::White);
		viewStudentGPA.setFillColor(scene->a->highlightCyan);
		viewStudentGPAText.setFillColor(sf::Color::White);
		viewMembers.setFillColor(scene->a->highlightCyan);
		viewMembersText.setFillColor(sf::Color::White);
	}

}