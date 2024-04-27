#include "MenuClassCourse.h"
#include "Scene.h"


MenuClassCourseScene::MenuClassCourseScene(Static* a)
{
	createABox(menuClassCourseBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Menu Class Course", 80, (float)a->width / 2.0f, 75.0f);
	createText(menuClassCourseText, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 80, (float)a->width / 2.0f, 200.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Re-select", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(manageScoreboard, manageScoreboardText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Manage scoreboard", sf::Vector2f((float)(a->width / 2.0f), 400.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(manageStudent, manageStudentText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Manage students", sf::Vector2f((float)(a->width / 2.0f), 700.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(updateInfo, updateInfoText, sf::Vector2f(600.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Update course info", sf::Vector2f((float)(a->width / 2.0f), 1000.0f), 2.0f, sf::Color::Black);
}

void MenuClassCourseScene::drawMenuClassCourse(sf::RenderWindow& window, Static* a)
{
	window.draw(menuClassCourseBackground);
	window.draw(title);
	window.draw(menuClassCourseText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(manageScoreboard);
	window.draw(manageScoreboardText);
	window.draw(manageStudent);
	window.draw(manageStudentText);
	window.draw(updateInfo);
	window.draw(updateInfoText);

}

void MenuClassCourseScene::renderMenuClassCourse(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::MenuClassCourse)
	{
		if (preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			preButton.setFillColor(scene->a->pastelTitleCyan);
			preText.setFillColor(scene->a->titleGreyColor);
		}
		else if (manageScoreboard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			manageScoreboard.setFillColor(scene->a->pastelTitleCyan);
			manageScoreboardText.setFillColor(scene->a->titleGreyColor);
		}
		else if (manageStudent.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			manageStudent.setFillColor(scene->a->pastelTitleCyan);
			manageStudentText.setFillColor(scene->a->titleGreyColor);
		}
		else if (updateInfo.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			updateInfo.setFillColor(scene->a->pastelTitleCyan);
			updateInfoText.setFillColor(scene->a->titleGreyColor);
		}
		else {
			preButton.setFillColor(scene->a->highlightCyan);
			preText.setFillColor(sf::Color::White);
			manageScoreboard.setFillColor(scene->a->highlightCyan);
			manageScoreboardText.setFillColor(sf::Color::White);
			manageStudent.setFillColor(scene->a->highlightCyan);
			manageStudentText.setFillColor(sf::Color::White);
			updateInfo.setFillColor(scene->a->highlightCyan);
			updateInfoText.setFillColor(sf::Color::White);
		}
		
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menuclasscourse;
				scene->menuclasscourse = nullptr;
				scene->a->curCourse->className = "";
				if (scene->chooseclasscourse == nullptr)
					scene->chooseclasscourse = new ChooseClassCourseScene(scene->a);
				scene->a->currentState = programState::ChooseClassCourse;
			}
			else if (manageScoreboard.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menuclasscourse;
				scene->menuclasscourse = nullptr;
				if (scene->coursemanagescoreboard == nullptr)
					scene->coursemanagescoreboard = new CourseManageScoreBoardScene(scene->a);
				scene->a->currentState = programState::CourseManageScoreBoard;
			}
			else if (manageStudent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menuclasscourse;
				scene->menuclasscourse = nullptr;
				if (scene->coursemanagestudent == nullptr)
					scene->coursemanagestudent = new CourseManageStudentScene(scene->a);
				scene->a->currentState = programState::CourseManageStudent;
			}
			else if (updateInfo.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->menuclasscourse;
				scene->menuclasscourse = nullptr;
				if (scene->updatecourseinformation == nullptr)
					scene->updatecourseinformation = new UpdateCourseInformationScene(scene->a);
				scene->a->currentState = programState::UpdateCourseInformation;
			}
		}
	}
}

