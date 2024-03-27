#include "MenuSchoolYear.h"
#include "../SchoolYear.h"


MenuSchoolYearScene::MenuSchoolYearScene(Static* a)
{
	createABox(menuSchoolYearBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(menuSchoolYearText, a->fontB, a->textColorBlue, "MENU SCHOOL YEAR", 80, a->width / 2.0f, 100.0f);
	createAButton(preButton, preText, sf::Vector2f(400.0f, 150.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "RE-SELECT YEAR", sf::Vector2f(200.0f, 1000.0f));
	createAButton(createSemestersButton, createSemestersText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "CREATE SEMESTER", sf::Vector2f(a->width / 2.0f, 500.0f));
	createAButton(chooseSemesterButton, chooseSemesterText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "CHOOSE SEMESTER", sf::Vector2f(a->width / 2.0f, 800.0f));	
}

void MenuSchoolYearScene::drawMenuSchoolYear(sf::RenderWindow& window, Static* a)
{
	window.draw(menuSchoolYearBackground);
	window.draw(menuSchoolYearText);
	
	if(i == 0)
		createText(yearText, a->fontB, a->textColorBlue, a->curSchoolYear->year, 100, a->width / 2.0f, 250.0f);
	window.draw(yearText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(createSemestersButton);
	window.draw(createSemestersText);
	window.draw(chooseSemesterButton);
	window.draw(chooseSemesterText);
}

void MenuSchoolYearScene::renderMenuSchoolYear(sf::Event event, Static* a, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->curSchoolYear->deallocateCurrentSchoolYear();
				delete a->curSchoolYear;
				a->curSchoolYear = nullptr;
				a->currentState = programState::ChooseSchoolYear;
			}
		}
	}
	
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (a->currentState == programState::MenuSchoolYear && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(a->pastelTitleCyan);
		preText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuSchoolYear && createSemestersButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		createSemestersButton.setFillColor(a->pastelTitleCyan);
		createSemestersText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuSchoolYear && chooseSemesterButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		chooseSemesterButton.setFillColor(a->pastelTitleCyan);
		chooseSemesterText.setFillColor(a->titleGreyColor);
	}
	else
	{
		createSemestersButton.setFillColor(a->highlightCyan);
		chooseSemesterButton.setFillColor(a->highlightCyan);
		createSemestersText.setFillColor(sf::Color::White);
		chooseSemesterText.setFillColor(sf::Color::White);
		preButton.setFillColor(a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}
	
}