#include "CourseManageScoreBoard.h"
#include "Scene.h"
#include "SFML/Graphics.hpp"

CourseManageScoreBoardScene::CourseManageScoreBoardScene(Static* a)
{
	createText(title, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 80, a->width / 2.0f, 200.0f);
	createABox(courseManageScoreBoardBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(courseManageScoreBoardText, a->fontB, a->textColorBlue, "Manage Scoreboard", 80, (float)a->width / 2.0f, 75.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(exportListStudent, exportListStudentText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Export file list of students", sf::Vector2f(a->width / 2.0f, 700.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(importScoreBoard, importScoreBoardText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Import scoreboard file", sf::Vector2f(a->width / 2.0f, 400.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(viewCourseScoreBoard, viewCourseScoreBoardText, sf::Vector2f(600.0f, 200.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "View course scoreboard", sf::Vector2f(a->width / 2.0f, 1000.0f), 2.0f, sf::Color::Black);
}

void CourseManageScoreBoardScene::drawCourseManageScoreBoard(sf::RenderWindow& window, Static* a)
{
	window.draw(courseManageScoreBoardBackground);
	window.draw(courseManageScoreBoardText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(exportListStudent);
	window.draw(exportListStudentText);
	window.draw(importScoreBoard);
	window.draw(importScoreBoardText);
	window.draw(viewCourseScoreBoard);
	window.draw(viewCourseScoreBoardText);

	window.draw(title);
	if (clock.getElapsedTime().asSeconds() < 2.0f && isSuccessful == true)
	{
		createText(success, a->fontB, a->textColorGreen, "Export class list successfully", 50, a->width / 2.0f, 1000);
		window.draw(success);
	}
}

void CourseManageScoreBoardScene::renderCourseManageScoreBoard(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::CourseManageScoreBoard)
	{
		if (preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			preButton.setFillColor(scene->a->pastelTitleCyan);
			preText.setFillColor(scene->a->titleGreyColor);
		}
		else if (exportListStudent.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			exportListStudent.setFillColor(scene->a->pastelTitleCyan);
			exportListStudentText.setFillColor(scene->a->titleGreyColor);
		}
		else if (importScoreBoard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			importScoreBoard.setFillColor(scene->a->pastelTitleCyan);
			importScoreBoardText.setFillColor(scene->a->titleGreyColor);
		}
		else if (viewCourseScoreBoard.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
		{
			viewCourseScoreBoard.setFillColor(scene->a->pastelTitleCyan);
			viewCourseScoreBoardText.setFillColor(scene->a->titleGreyColor);
		}
		else {
			preButton.setFillColor(scene->a->highlightCyan);
			preText.setFillColor(sf::Color::White);
			exportListStudent.setFillColor(scene->a->highlightCyan);
			exportListStudentText.setFillColor(sf::Color::White);
			importScoreBoard.setFillColor(scene->a->highlightCyan);
			importScoreBoardText.setFillColor(sf::Color::White);
			viewCourseScoreBoard.setFillColor(scene->a->highlightCyan);
			viewCourseScoreBoardText.setFillColor(sf::Color::White);
		}
	}

	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->coursemanagescoreboard;
				scene->coursemanagescoreboard = nullptr;
				if (scene->menuclasscourse == nullptr)
					scene->menuclasscourse = new MenuClassCourseScene(scene->a);
				scene->a->currentState = programState::MenuClassCourse;
			}
			else if (exportListStudent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//export file list of students
				std::string filename = openFile();
				Course *c = new Course();	
				bool check = c->ExportClass(scene->a, filename);
				delete c;
				if (check == true)
				{
					isSuccessful = true;
					clock.restart();
				}
			}
			else if (importScoreBoard.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->coursemanagescoreboard;
				scene->coursemanagescoreboard = nullptr;	
				if (scene->importscoreboard == nullptr)
					scene->importscoreboard = new ImportScoreboardScene(scene->a);
				scene->a->currentState = programState::ImportScoreboard;
			}
			else if (viewCourseScoreBoard.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//view course scoreboard
				delete scene->coursemanagescoreboard;
				scene->coursemanagescoreboard = nullptr;
				if (scene->viewcoursescoreboard == nullptr)
					scene->viewcoursescoreboard = new ViewScoreboardCourseScene(scene->a);
				scene->a->currentState = programState::ViewCourseScoreboard;
			}
			
			


		}
	}



}
