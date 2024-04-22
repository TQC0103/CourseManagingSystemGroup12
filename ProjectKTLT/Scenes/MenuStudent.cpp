#include "MenuStudent.h"
#include "../UserInterface.h"
#include "Scene.h"

MenuStudentScene::MenuStudentScene(Static* a)
{
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createABox(menuStudentPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(menu, a->fontB, a->textColorBlue, "Menu", 120, (float)a->width / 2.0f, 150.0f);
	createCornerRoundedButton(viewScoreBoard, viewScoreBoardText, sf::Vector2f(1000.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "View scoreboard and courses", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
	createCornerRoundedButton(viewStudentInfo, viewStudentInfoText, sf::Vector2f(1000.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "View student information", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
	createCornerRoundedButton(changePass, changePassText, sf::Vector2f(400.0f, 150.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "  Change\npassword", sf::Vector2f(a->width - 200.0f, a->height - 1000.0f), 2.0f, sf::Color::Black);
}

void MenuStudentScene::drawMenuStudent(sf::RenderWindow& win)
{
	win.draw(menuStudentPage);
	win.draw(preButton);
	win.draw(preText);
	win.draw(viewScoreBoard);
	win.draw(viewScoreBoardText);
	win.draw(menu);
	win.draw(changePass);
	win.draw(changePassText);
	win.draw(viewStudentInfo);
	win.draw(viewStudentInfoText);
}

void MenuStudentScene::renderMenuStudent(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::MenuStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStudent && changePass.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		changePass.setFillColor(scene->a->pastelTitleCyan);
		changePassText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStudent && viewStudentInfo.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewStudentInfo.setFillColor(scene->a->pastelTitleCyan);
		viewStudentInfoText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::MenuStudent && viewScoreBoard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewScoreBoard.setFillColor(scene->a->pastelTitleCyan);
		viewScoreBoardText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		changePass.setFillColor(scene->a->highlightCyan);
		changePassText.setFillColor(sf::Color::White);
		viewStudentInfo.setFillColor(scene->a->highlightCyan);
		viewStudentInfoText.setFillColor(sf::Color::White);
		viewScoreBoard.setFillColor(scene->a->highlightCyan);
		viewScoreBoardText.setFillColor(sf::Color::White);
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustudent;
				scene->menustudent = nullptr;
				if(scene->signinasstudent == nullptr)
					scene->signinasstudent = new SignInAsStudentScene(scene->a);
				scene->a->currentState = programState::SignInAsStudent;
			}
			else if (changePass.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustudent;
				scene->menustudent = nullptr;
				if(scene->changepassstu == nullptr)
					scene->changepassstu = new ChangePassStudentScene(scene->a);
				scene->a->currentState = programState::ChangePassStu;
			}
			else if (viewStudentInfo.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustudent;
				scene->menustudent = nullptr;
				if(scene->viewstudentprofile == nullptr)
					scene->viewstudentprofile = new ViewStudentProfileScene(scene->a);
				scene->a->currentState = programState::ViewStudentProfile;
			}
			else if (viewScoreBoard.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menustudent;
				scene->menustudent = nullptr;
				if (scene->chooseschoolyearstudent == nullptr)
					scene->chooseschoolyearstudent = new ChooseSchoolYearStudentScene(scene->a);
				scene->a->currentState = programState::ChooseSchoolYearStudent;
			}
		}
	}

	

}