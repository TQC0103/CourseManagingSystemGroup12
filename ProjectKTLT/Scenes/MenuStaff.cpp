#include "MenuStaff.h"
#include "../config.h"
#include "../UserInterface.h"
#include <fstream>

MenuStaffScene::MenuStaffScene(Static* a)
{
	createABox(MenuStaffPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createAButton(preButtonStaff, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createAButton(chooseSchoolYearButton, chooseSchoolYearText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "CHOOSE SCHOOL YEAR", sf::Vector2f(a->width / 2.0f - 400.0f, 750.0f));
	createAButton(createSchoolYearButton, createSchoolYearText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "CREATE SCHOOL YEAR", sf::Vector2f(a->width / 2.0f - 400.0f, 450.0f));
	createText(menu, a->fontB, a->textColorBlue, "MENU", 120, (float)a->width / 2.0f, 150.0f);
	createAButton(createClassButton, createClassText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "CREATE CLASS", sf::Vector2f(a->width / 2.0f + 400.0f, 450.0f));
	createAButton(chooseClassButton, chooseClassText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "CHOOSE CLASS", sf::Vector2f(a->width / 2.0f + 400.0f, 750.0f));
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
	win.draw(createClassButton);
	win.draw(createClassText);
	win.draw(chooseClassButton);
	win.draw(chooseClassText);
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
			if(chooseSchoolYearButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::ChooseSchoolYear;
			}
			if (chooseClassButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::ChooseClass;
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
	else if (a->currentState == programState::MenuStaff && chooseSchoolYearButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		chooseSchoolYearButton.setFillColor(a->pastelTitleCyan);
		chooseSchoolYearText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStaff && createSchoolYearButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		createSchoolYearButton.setFillColor(a->pastelTitleCyan);
		createSchoolYearText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStaff && createClassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		createClassButton.setFillColor(a->pastelTitleCyan);
		createClassText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStaff && chooseClassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		chooseClassButton.setFillColor(a->pastelTitleCyan);
		chooseClassText.setFillColor(a->titleGreyColor);
	}
	else {
		preButtonStaff.setFillColor(a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		changePassButton.setFillColor(a->highlightCyan);
		changePassText.setFillColor(sf::Color::White);
		chooseSchoolYearButton.setFillColor(a->highlightCyan);
		chooseSchoolYearText.setFillColor(sf::Color::White);
		createSchoolYearButton.setFillColor(a->highlightCyan);
		createSchoolYearText.setFillColor(sf::Color::White);
		createClassButton.setFillColor(a->highlightCyan);
		createClassText.setFillColor(sf::Color::White);
		chooseClassButton.setFillColor(a->highlightCyan);
		chooseClassText.setFillColor(sf::Color::White);
	}
}

void MenuStaffScene::changePassword()
{
	std::ofstream fOut;
	
}