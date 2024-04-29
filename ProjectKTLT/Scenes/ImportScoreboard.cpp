#include "ImportScoreboard.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>

ImportScoreboardScene::ImportScoreboardScene(Static* a)
{

	createABox(importScoreboardBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(importScoreboardText, a->fontB, a->textColorBlue, "Select Your Input File", 120, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preButtonText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(submitButton, submitButtonText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(chooseFileButton, sf::Vector2f(1200.0f, 250.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, a->height / 2.0f));
	createText(chooseFileButtonText, a->fontI, sf::Color::White, "CLICK HERE TO SELECT FILE", 40, chooseFileButton.getPosition().x, chooseFileButton.getPosition().y);
}

void ImportScoreboardScene::drawImportScoreboard(sf::RenderWindow& win, Static* a)
{
	win.draw(importScoreboardBackground);
	win.draw(importScoreboardText);
	win.draw(preButton);
	win.draw(preButtonText);
	win.draw(submitButton);
	win.draw(submitButtonText);
	win.draw(chooseFileButton);
	if (fileChosen == true) {
		win.draw(filePathText);
	}
	else {
		win.draw(chooseFileButtonText);
	}

	if (isWrong == 1)
	{
		createText(fail, a->fontB, sf::Color::Red, "Please choose a file", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == -1)
	{
		createText(successful, a->fontB, a->textColorGreen, "Import scoreboard for " + a->curCourse->Name + " - "  + a->curCourse->className+ " successfully", 35, a->width / 2.0f, 1000.0f);
		win.draw(successful);
	}
	else if (isWrong == 3)
	{
		createText(fail, a->fontB, sf::Color::Red, "Not matching header", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 2)
	{
		createText(fail, a->fontB, sf::Color::Red, "Fail to open files", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
}

void ImportScoreboardScene::renderImportScoreboard(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::ImportScoreboard && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preButtonText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::ImportScoreboard && submitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		submitButton.setFillColor(scene->a->pastelTitleCyan);
		submitButtonText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::ImportScoreboard) {
		preButton.setFillColor(scene->a->highlightCyan);
		preButtonText.setFillColor(sf::Color::White);
		submitButton.setFillColor(scene->a->highlightCyan);
		submitButtonText.setFillColor(sf::Color::White);
	}

	if (isWrong == -1)
	{
		sf::sleep(sf::seconds(1.0f));
		if (scene->menuclasscourse == nullptr)
			scene->menuclasscourse = new MenuClassCourseScene(scene->a);
		delete scene->importscoreboard;
		scene->importscoreboard = nullptr;
		scene->a->currentState = programState::MenuClassCourse;
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (scene->coursemanagescoreboard == nullptr)
					scene->coursemanagescoreboard = new CourseManageScoreBoardScene(scene->a);
				delete scene->importscoreboard;
				scene->importscoreboard = nullptr;
				scene->a->currentState = programState::CourseManageScoreBoard;
			}
			else if (chooseFileButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				std::wstring path = openFileDialog(win.getSystemHandle());
				if (!path.empty()) {
					// Convert the std::wstring to std::string
					std::string filePathStr(path.begin(), path.end());
					filePath = filePathStr;
					filePathDisplay = filePath;
					if (filePath.length() > 40) {
						filePathDisplay = "..." + filePath.substr(filePath.length() - 39);
					}
					createText(filePathText, scene->a->fontB, sf::Color::White, filePathDisplay, 50, chooseFileButton.getPosition().x, chooseFileButton.getPosition().y);
					fileChosen = true;
				}
			}
			else if (submitButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (fileChosen == false)
				{
					isWrong = 1;
				}
				else
				{
					Course* c = new Course();
					int check = c->ImportScoreboard(scene->a, filePath);
					delete c;
					if (check == 1)
					{
						isWrong = 2;
					}
					else if (check == 2)
					{
						isWrong = 3;
					}
					else if (check == 0)
					{
						isWrong = -1;
					}
				}
			}

		}
	}
}