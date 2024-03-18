#include "MenuStaff.h"
#include "../config.h"
#include "../UserInterface.h"

MenuStaffScene::MenuStaffScene()
{
	createABox(MenuStaffPage, sf::Vector2f((float)a.width, (float)a.height), a.backGroundWhite, sf::Vector2f((float)a.width / 2.0f, a.height / 2.0f));
	createAButton(preButtonStaff, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createAButton(chooseSchoolYearButton, chooseSchoolYearText, sf::Vector2f(800.0f, 200.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "CHOOSE SCHOOL YEAR", sf::Vector2f(a.width / 2.0f, 800.0f));
	createAButton(createSchoolYearButton, createSchoolYearText, sf::Vector2f(800.0f, 200.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "CREATE SCHOOL YEAR", sf::Vector2f(a.width / 2.0f, 475.0f));
	createText(menu, a.fontB, a.highlightCyan, "MENU", 120, (float)a.width / 2.0f, 150.0f);
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
}

void MenuStaffScene::renderMenuStaff(sf::Event event, programState& currentState, sf::RenderWindow& win)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButtonStaff.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				currentState = programState::SignInAsStaff;
			}
		}
	}
}