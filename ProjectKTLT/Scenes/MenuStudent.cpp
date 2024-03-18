#include "MenuStudent.h"
#include "../UserInterface.h"

MenuStudentScene::MenuStudentScene()
{
	createAButton(preButton, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createABox(menuStudentPage, sf::Vector2f((float)a.width, (float)a.height), a.backGroundWhite, sf::Vector2f((float)a.width / 2.0f, a.height / 2.0f));
	createText(menu, a.fontB, a.highlightCyan, "MENU", 120, (float)a.width / 2.0f, 150.0f);
	createAButton(viewScoreBoard, viewScoreBoardText, sf::Vector2f(500.0f, 200.0f), 60.0f, a.highlightCyan, a.fontN, sf::Color::White, "     View\nscoreboard", sf::Vector2f((float)(a.width / 2.0f - 350.0f), (float)(a.height / 2.0f - 150.0f)));
	createAButton(viewListsOfCourses, viewListsOfCoursesText, sf::Vector2f(500.0f, 200.0f), 60.0f, a.highlightCyan, a.fontN, sf::Color::White, "View lists\nof courses", sf::Vector2f((float)(a.width / 2.0f + 350.0f), (float)(a.height / 2.0f - 150.0f)));
	createAButton(viewStudentInfo, viewStudentInfoText, sf::Vector2f(500.0f, 200.0f), 60.0f, a.highlightCyan, a.fontN, sf::Color::White, "View students\n   information", sf::Vector2f((float)(a.width / 2.0f - 350.0f), (float)(a.height / 2.0f + 150.0f)));
	createAButton(changePass, changePassText, sf::Vector2f(500.0f, 200.0f), 60.0f, a.highlightCyan, a.fontN, sf::Color::White, "  Change\npassword", sf::Vector2f((float)(a.width / 2.0f + 350.0f), (float)(a.height / 2.0f + 150.0f)));
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

void MenuStudentScene::renderMenuStudent(sf::Event event, programState &currentState, sf::RenderWindow& win)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				currentState = programState::SignInAsStudent;
			}
		}
	}
}