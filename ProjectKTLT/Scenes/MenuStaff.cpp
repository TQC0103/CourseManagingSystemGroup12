#include "MenuStaff.h"
#include "../config.h"
#include "../UserInterface.h"
#include <fstream>
#include "../SchoolYear.h"
#include "../Scenes/Scene.h"
#include "../Scenes/ChooseSchoolYear.h"
MenuStaffScene::MenuStaffScene(Static* a)
{
	createABox(MenuStaffPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createAButton(preButtonStaff, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(200.0f, 1000.0f));
	createAButton(chooseSchoolYearButton, chooseSchoolYearText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Choose school year", sf::Vector2f(a->width / 2.0f - 400.0f, 750.0f));
	createAButton(createSchoolYearButton, createSchoolYearText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Create school year", sf::Vector2f(a->width / 2.0f - 400.0f, 450.0f));
	createText(menu, a->fontB, a->textColorBlue, "Menu", 120, (float)a->width / 2.0f, 150.0f);
	createAButton(createClassButton, createClassText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Create class", sf::Vector2f(a->width / 2.0f + 400.0f, 450.0f));
	createAButton(chooseClassButton, chooseClassText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Choose class", sf::Vector2f(a->width / 2.0f + 400.0f, 750.0f));
	createAButton(changePassButton, changePassText, sf::Vector2f(400.0f, 150.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "  Change\npassword", sf::Vector2f(a->width - 200.0f, a->height - 1000.0f));
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

void MenuStaffScene::renderMenuStaff(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::MenuStaff && preButtonStaff.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButtonStaff.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStaff && changePassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		changePassButton.setFillColor(scene->a->pastelTitleCyan);
		changePassText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStaff && chooseSchoolYearButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		chooseSchoolYearButton.setFillColor(scene->a->pastelTitleCyan);
		chooseSchoolYearText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStaff && createSchoolYearButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		createSchoolYearButton.setFillColor(scene->a->pastelTitleCyan);
		createSchoolYearText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStaff && createClassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		createClassButton.setFillColor(scene->a->pastelTitleCyan);
		createClassText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStaff && chooseClassButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		chooseClassButton.setFillColor(scene->a->pastelTitleCyan);
		chooseClassText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButtonStaff.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		changePassButton.setFillColor(scene->a->highlightCyan);
		changePassText.setFillColor(sf::Color::White);
		chooseSchoolYearButton.setFillColor(scene->a->highlightCyan);
		chooseSchoolYearText.setFillColor(sf::Color::White);
		createSchoolYearButton.setFillColor(scene->a->highlightCyan);
		createSchoolYearText.setFillColor(sf::Color::White);
		createClassButton.setFillColor(scene->a->highlightCyan);
		createClassText.setFillColor(sf::Color::White);
		chooseClassButton.setFillColor(scene->a->highlightCyan);
		chooseClassText.setFillColor(sf::Color::White);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButtonStaff.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustaff;
				scene->menustaff = nullptr;
				if(scene->signinasstaff == nullptr)
					scene->signinasstaff = new SignInAsStaffScene(scene->a);
				scene->a->currentState = programState::SignInAsStaff;
			}
			else if (changePassButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustaff;
				scene->menustaff = nullptr;
				if(scene->changepasssta == nullptr)
					scene->changepasssta = new ChangePassStaffScene(scene->a);
				scene->a->currentState = programState::ChangePassSta;
			}
			else if (chooseSchoolYearButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustaff;
				scene->menustaff = nullptr;
				if(scene->chooseschoolyear == nullptr)
					scene->chooseschoolyear = new ChooseSchoolYearScene(scene->a);
				
				scene->a->currentState = programState::ChooseSchoolYear;
			}
			else if (chooseClassButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->chooseclass == nullptr)
					scene->chooseclass = new ChooseClassScene(scene->a);
				delete scene->menustaff;
				scene->menustaff = nullptr;
				scene->a->currentState = programState::ChooseClass;
			}
			else if (createSchoolYearButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				schoolYear* tmp = new schoolYear();
				tmp->loadSchoolYear();
				tmp->addSchoolYear();
				delete tmp;
			}


		}
	}

	

}
