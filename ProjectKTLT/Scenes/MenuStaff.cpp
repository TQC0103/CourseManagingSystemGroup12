#include "MenuStaff.h"
#include "../config.h"
#include "../UserInterface.h"
#include <fstream>

MenuStaffScene::MenuStaffScene(Static* a)
{
	createABox(MenuStaffPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createAButton(preButtonStaff, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createAButton(chooseSchoolYearButton, chooseSchoolYearText, sf::Vector2f(800.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "Choose school year", sf::Vector2f(a->width / 2.0f, 800.0f));
	createAButton(createSchoolYearButton, createSchoolYearText, sf::Vector2f(800.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "Create school year", sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(menu, a->fontB, a->textColorBlue, "MENU", 120, (float)a->width / 2.0f, 150.0f);
	createAButton(changePassButton, changePassText, sf::Vector2f(400.0f, 150.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "  CHANGE\nPASSWORD", sf::Vector2f(a->width - 200.0f, a->height - 1000.0f));
}

void MenuStaffScene::drawMenuStaff(sf::RenderWindow& win)
{
	win.draw(MenuStaffPage);
	win.draw(menu);
	win.draw(preButtonStaff);
	win.draw(preText);
	win.draw(chooseSchoolYearButton);
	win.draw(chooseSchoolYearText);
	win.draw(createSchoolYearButton);
	win.draw(createSchoolYearText);
	win.draw(changePassButton);
	win.draw(changePassText);
}

void MenuStaffScene::renderMenuStaff(sf::Event event, Static *a, sf::RenderWindow& win)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButtonStaff.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::SignInAsStaff;
			}
			if (changePassButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::ChangePassSta;
			}
		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (a->currentState == programState::MenuStaff && preButtonStaff.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButtonStaff.setFillColor(a->pastelTitleCyan);
		preText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStaff && changePassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		changePassButton.setFillColor(a->pastelTitleCyan);
		changePassText.setFillColor(a->titleGreyColor);
	}
	else {
		preButtonStaff.setFillColor(a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		changePassButton.setFillColor(a->highlightCyan);
		changePassText.setFillColor(sf::Color::White);
		
	}
}

void MenuStaffScene::changePassword()
{
	std::ofstream fOut;
	
}