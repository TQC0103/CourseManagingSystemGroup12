#include "ViewScoreboardStudent.h"
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Semester.h"
#include "../Student.h"

ViewScoreboardScene::ViewScoreboardScene(Static* a)
{
	recAverage = nullptr;
	textAverage = nullptr;
	recA = nullptr;
	textA = nullptr;
	createABox(viewScoreStudentBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Your Scoreboard This Semester", 60, (float)a->width / 2.0f, 75.0f);
	createText(viewScoreStudentText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 60, (float)a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(200.0f, 100.0f), 30.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(100.0f, a->height - 1100.0f), 2.0f, sf::Color::Black);
	stu = new student;
	table = stu->getStudentScoreBoard(a, numCourse);
	if (numCourse == 0)
	{
		createText(needParticipationText, a->fontB, a->blurGrey, "You have not participated\n           in any courses", 100, (float)a->width / 2.0f, (float)a->height / 2.0f);
	}
	else {
		recA = new sf::RectangleShape * [numCourse + 1];
		textA = new sf::Text * [numCourse + 1];
		for (int i = 0; i < numCourse + 1; i++)
		{
			recA[i] = new sf::RectangleShape[9];
			textA[i] = new sf::Text[9];
		}
		recAverage = new sf::RectangleShape[2];
		textAverage = new sf::Text[2];

		float cellHeight = 100.0f;
		float cellWidth = 100.0f;
		sf::Vector2f pos = sf::Vector2f(200.0f, 300.0f);
		for (int i = 0; i < numCourse + 1; i++) {
			for (int j = 0; j < 9; j++) {
				// Draw cell
				if (i == 0)
				{
					switch (j)
					{
					case 0:
					{
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(pos.x, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Course ID", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					}
					case 1:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Course Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 2:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Student ID", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 3:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Last Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 4:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "First Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 5:
						cellWidth = 120.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Final", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 6:
						cellWidth = 120.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Midterm", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 7:
						cellWidth = 120.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Others", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 8:
						cellWidth = 120.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Overall", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					default:
						break;
					}
				}
				else
				{
					float h = (float)recA[i - 1][j].getSize().y;
					createABox(recA[i][j], sf::Vector2f(recA[i - 1][j].getSize().x, h), a->pastelTitleCyan, sf::Vector2f(recA[i - 1][j].getPosition().x, recA[i - 1][j].getPosition().y + h));
					// Draw text
					if (table[i - 1][j].size() > 25)
					{
						createText(textA[i][j], a->fontN, a->titleGreyColor, table[i - 1][j], 18, recA[i][j].getPosition().x, recA[i][j].getPosition().y);

					}
					else if (table[i - 1][j].size() > 20)
						createText(textA[i][j], a->fontN, a->titleGreyColor, table[i - 1][j], 20, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					else {
						createText(textA[i][j], a->fontN, a->titleGreyColor, table[i - 1][j], 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					}
				}
			}
		}
		cellWidth = 120.0f;
		createABox(recAverage[0], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[0][8].getPosition().x + cellWidth / 2.0f + recA[0][8].getSize().x / 2.0f, pos.y));
		createText(textAverage[0], a->fontB, a->backGroundWhite, "GPA", 25, recAverage[0].getPosition().x, recAverage[0].getPosition().y);

		for (int i = 1; i <= numCourse / 4; i++)
		{
			createABox(recAverage[i], sf::Vector2f(recAverage[0].getSize().x, 4 * recA[i * 4][8].getSize().y), a->pastelTitleCyan, sf::Vector2f(recAverage[0].getPosition().x, recAverage[i - 1].getPosition().y + 250.0f));
			float GPA = 0.0f;
			for (int j = 1; j <= 4; j++)
			{
				GPA += std::stof(table[i * 4 - 5 + j][8]);
			}
			GPA = GPA / 4.0f;
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << GPA;
			createText(textAverage[i], a->fontB, a->titleGreyColor, ss.str(), 25, recAverage[i].getPosition().x, recAverage[i].getPosition().y);
		}
		for (int i = 0; i < numCourse + 1; i++)
		{
			tableHeight += recA[i][0].getSize().y;
		}
		for (int i = 0; i < 9; i++)
		{
			tableWidth += recA[0][i].getSize().x;
		}
	}

}

void ViewScoreboardScene::drawViewScoreboardScene(sf::RenderWindow& window, Static* a)
{
	window.draw(viewScoreStudentBackground);
	window.draw(preButton);
	window.draw(preText);
	if (numCourse == 0)
		window.draw(needParticipationText);
	else
	{
		for (int i = 0; i < numCourse + 1; i++) {
			for (int j = 0; j < 9; j++) {
				window.draw(recA[i][j]);
				window.draw(textA[i][j]);
			}
		}
		for (int i = 0; i < 2; i++)
		{
			window.draw(recAverage[i]);
			window.draw(textAverage[i]);
		}
		for (int i = 1; i < numCourse + 1; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(tableWidth, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recA[0][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top));
			window.draw(line);
		}
		for (int i = 0; i < 1; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(recAverage[0].getSize().x, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recAverage[0].getPosition().x, recAverage[i + 1].getGlobalBounds().top));
			window.draw(line);
		}
		sf::RectangleShape line;
		createABox(line, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recAverage[0].getGlobalBounds().left, recA[0][1].getGlobalBounds().top + tableHeight / 2.0f));
		window.draw(line);
		for (int i = 1; i < 9; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recA[0][i].getGlobalBounds().left, recA[0][1].getGlobalBounds().top + tableHeight / 2.0f));
			window.draw(line);
		}
		
	}
	window.draw(title);
	window.draw(viewScoreStudentText);

}

void ViewScoreboardScene::renderViewScoreboardScene(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::ViewScoreboardStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else
	{
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->viewscoreboardstudent;
				scene->viewscoreboardstudent = nullptr;
				scene->a->currentState = programState::MenuSemesterStudent;
				if (scene->menusemesterstudent == nullptr)
					scene->menusemesterstudent = new MenuSemesterStudentScene(scene->a);
			}
		}
	}

}

ViewScoreboardScene::~ViewScoreboardScene()
{
	if (numCourse != 0)
	{
		for (int i = 0; i < numCourse; i++)
		{
			delete[] table[i];
		}
		delete[] table;
		for (int i = 0; i < numCourse + 1; i++)
		{
			delete[] recA[i];
			delete[] textA[i];
		}
		delete[] recA;
		delete[] textA;
		delete[] recAverage;
		delete[] textAverage;
	}
	delete stu;

}