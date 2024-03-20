#include "MenuStudent.h"
#include "../UserInterface.h"

MenuStudentScene::MenuStudentScene(Static* a)
{
	createAButton(preButton, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createABox(menuStudentPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(menu, a->fontB, a->textColorBlue, "MENU", 120, (float)a->width / 2.0f, 150.0f);
	createAButton(viewScoreBoard, viewScoreBoardText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "         VIEW\nSCOREBOARD", sf::Vector2f((float)(a->width / 2.0f - 400.0f), (float)(a->height / 2.0f - 150.0f)));
	createAButton(viewListsOfCourses, viewListsOfCoursesText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "    VIEW\nCOURSES", sf::Vector2f((float)(a->width / 2.0f + 400.0f), (float)(a->height / 2.0f - 150.0f)));
	createAButton(viewStudentInfo, viewStudentInfoText, sf::Vector2f(1400.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "VIEW STUDENTS INFORMATION", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)));
	createAButton(changePass, changePassText, sf::Vector2f(400.0f, 150.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "  CHANGE\nPASSWORD", sf::Vector2f(a->width - 200.0f, a->height - 1000.0f));
}

void MenuStudentScene::drawMenuStudent(sf::RenderWindow& win)
{
	win.draw(menuStudentPage);
	win.draw(preButton);
	win.draw(preText);
	win.draw(viewScoreBoard);
	win.draw(viewScoreBoardText);
	win.draw(menu);
	win.draw(viewListsOfCourses);
	win.draw(viewListsOfCoursesText);
	win.draw(changePass);
	win.draw(changePassText);
	win.draw(viewStudentInfo);
	win.draw(viewStudentInfoText);
}

void MenuStudentScene::renderMenuStudent(sf::Event event, Static *a, sf::RenderWindow& win)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::SignInAsStudent;
			}
			if (changePass.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::ChangePassStu;
			}
			if (viewStudentInfo.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::ViewStudentProfile;
			}
		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (a->currentState == programState::MenuStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(a->pastelTitleCyan);
		preText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStudent && changePass.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		changePass.setFillColor(a->pastelTitleCyan);
		changePassText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStudent && viewStudentInfo.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewStudentInfo.setFillColor(a->pastelTitleCyan);
		viewStudentInfoText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStudent && viewListsOfCourses.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewListsOfCourses.setFillColor(a->pastelTitleCyan);
		viewListsOfCoursesText.setFillColor(a->titleGreyColor);
	}
	else if (a->currentState == programState::MenuStudent && viewScoreBoard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewScoreBoard.setFillColor(a->pastelTitleCyan);
		viewScoreBoardText.setFillColor(a->titleGreyColor);
	}
	else {
		preButton.setFillColor(a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		changePass.setFillColor(a->highlightCyan);
		changePassText.setFillColor(sf::Color::White);
		viewStudentInfo.setFillColor(a->highlightCyan);
		viewStudentInfoText.setFillColor(sf::Color::White);
		viewListsOfCourses.setFillColor(a->highlightCyan);
		viewListsOfCoursesText.setFillColor(sf::Color::White);
		viewScoreBoard.setFillColor(a->highlightCyan);
		viewScoreBoardText.setFillColor(sf::Color::White);
	}
}