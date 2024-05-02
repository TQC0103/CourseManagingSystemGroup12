#include "ViewClassScoreboard.h"
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Semester.h"
#include "../Student.h"

ViewClassScoreboardScene::ViewClassScoreboardScene(Static* a)
{
	scrollOffset = 0.0f;
	createABox(hideBack, sf::Vector2f((float)a->width, 350.0f), a->backGroundWhite, sf::Vector2f(a->width / 2.0f, 175.0f));


	recA = nullptr;
	textA = nullptr;
	recSem = nullptr;
	textSem = nullptr;
	recYear = nullptr;
	textYear = nullptr;
	recNo = nullptr;
	textNo = nullptr;

	createABox(viewClassScoreBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, a->curClass->name + " Scoreboard In", 60, (float)a->width / 2.0f, 75.0f);
	createText(viewClassScoreText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 60, (float)a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(200.0f, 100.0f), 30.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(100.0f, a->height - 1100.0f), 2.0f, sf::Color::Black);
	cl = new Class;
	year = new schoolYear;
	year->getGPASchoolYear(a);
	sem = new semester;
	sem->getGPASemester(a);
	table = cl->view_scoreboard_Student_Class(a, numStudents);
	if (numStudents == 0)
	{
		createText(needParticipationText, a->fontB, a->blurGrey, "No students in this class", 100, (float)a->width / 2.0f, (float)a->height / 2.0f);
	}
	else {
		recA = new sf::RectangleShape * [numStudents + 1];
		textA = new sf::Text * [numStudents + 1];
		numS = numStudents / 4;
		recSem = new sf::RectangleShape[numS + 1];
		textSem = new sf::Text[numS + 1];
		recYear = new sf::RectangleShape[numS + 1];
		textYear = new sf::Text[numS + 1];
		recNo = new sf::RectangleShape[numS + 1];
		textNo = new sf::Text[numS + 1];

		for (int i = 0; i < numStudents + 1; i++)
		{
			recA[i] = new sf::RectangleShape[9];
			textA[i] = new sf::Text[9];
		}
		float cellHeight = 100.0f;
		float cellWidth = 100.0f;
		sf::Vector2f pos = sf::Vector2f(250.0f, 300.0f);
		for (int i = 0; i < numStudents + 1; i++) {
			for (int j = 0; j < 9; j++) {
				// Draw cell
				if (i == 0)
				{
					switch (j)
					{
					case 0:
					{
						cellWidth = 150.0f;
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
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Last Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 4:
						cellWidth = 150.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "First Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 5:
						cellWidth = 125.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Final", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 6:
						cellWidth = 125.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Midterm", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 7:
						cellWidth = 125.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Others", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 8:
						cellWidth = 125.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Overall", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
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
					if (j == 3 && table[i - 1][j].size() > 15)
					{
						createText(textA[i][j], a->fontN, a->titleGreyColor, table[i - 1][j], 20, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					}
				}
			}
		}

		cellWidth = 120.0f;
		createABox(recSem[0], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[0][8].getPosition().x + cellWidth / 2.0f + recA[0][8].getSize().x / 2.0f, pos.y));
		createText(textSem[0], a->fontB, a->backGroundWhite, "    GPA\nSemester", 20, recSem[0].getPosition().x, recSem[0].getPosition().y);
		createABox(recYear[0], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recSem[0].getPosition().x + cellWidth / 2.0f + recSem[0].getSize().x / 2.0f, pos.y));
		createText(textYear[0], a->fontB, a->backGroundWhite, "GPA\nYear", 25, recYear[0].getPosition().x, recYear[0].getPosition().y);
		cellWidth = 120.0f;
		createABox(recNo[0], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[0][0].getGlobalBounds().left - cellWidth / 2.0f, pos.y));
		createText(textNo[0], a->fontB, a->backGroundWhite, "No", 25, recNo[0].getPosition().x, recNo[0].getPosition().y);

		semester* tmpSem = sem->GPASemester;
		schoolYear* tmpYear = year->GPAYear;
		for (int i = 1; i < numS + 1; i++)
		{
			cellWidth = 120.0f;
			createABox(recSem[i], sf::Vector2f(cellWidth, cellHeight * 4), a->pastelTitleCyan, sf::Vector2f(recSem[i - 1].getPosition().x, recA[i][0].getPosition().y + 150.0f));
			createText(textSem[i], a->fontN, a->titleGreyColor, std::to_string(tmpSem->GPA), 25, recSem[i].getPosition().x, recSem[i].getPosition().y);
			createABox(recYear[i], sf::Vector2f(recSem[i].getSize().x, recSem[i].getSize().y), a->pastelTitleCyan, sf::Vector2f(recYear[i - 1].getPosition().x, recSem[i].getPosition().y + recSem[i].getSize().y));
			createText(textYear[i], a->fontN, a->titleGreyColor, std::to_string(tmpYear->GPA), 25, recYear[i].getPosition().x, recYear[i].getPosition().y);
			createABox(recNo[i], sf::Vector2f(recSem[i].getSize().x, recSem[i].getSize().y), a->pastelTitleCyan, sf::Vector2f(recNo[i - 1].getPosition().x, recSem[i].getPosition().y + recSem[i].getSize().y));
			createText(textNo[i], a->fontN, a->titleGreyColor, std::to_string(i), 25, recNo[i].getPosition().x, recNo[i].getPosition().y);
			tmpSem = tmpSem->pNext;
			tmpYear = tmpYear->pNext;
		}

		for (int i = 0; i < numStudents + 1; i++)
		{
			tableHeight += recA[i][0].getSize().y;
		}
		for (int i = 0; i < 9; i++)
		{
			tableWidth += recA[0][i].getSize().x;
		}
	}

	times = numStudents;
	sizedisplay = a->height - 250.0f;
	fullsize = tableHeight - 500.0f;
	if (numStudents > 8)
		createAScrollbar(scrollbar, scrollbarArea, sf::Vector2f(20.0f, 50.0f), a->backGroundWhiteDarkerStill, a->backGroundWhiteDarker, sf::Vector2f(1950.0f, 625.0f), 15);


}

void ViewClassScoreboardScene::drawViewClassScoreboardScene(sf::RenderWindow& window, Static* a)
{
	window.draw(viewClassScoreBackgr);

	if (numStudents == 0)
		window.draw(needParticipationText);
	else
	{
		for (int i = numStudents; i >= 1; i--) {
			for (int j = 0; j < 9; j++) {
				recA[i][j].setPosition(recA[i][j].getPosition().x, 300.0f + (float)i * recA[i][j].getSize().y - scrollOffset);
				textA[i][j].setPosition(textA[i][j].getPosition().x, 300.0f + (float)i * recA[i][j].getSize().y - scrollOffset);
				window.draw(recA[i][j]);
				window.draw(textA[i][j]);
			}
		}
		for (int i = 1; i < numS + 1; i++)
		{
			recSem[i].setPosition(recSem[i].getPosition().x, 150.0f + (float)i * recSem[i].getSize().y - scrollOffset);
			textSem[i].setPosition(textSem[i].getPosition().x, recSem[i].getPosition().y);

			recYear[i].setPosition(recYear[i].getPosition().x, 150.0f + (float)i * recYear[i].getSize().y - scrollOffset);
			textYear[i].setPosition(textYear[i].getPosition().x, recYear[i].getPosition().y);

			recNo[i].setPosition(recNo[i].getPosition().x, 150.0f + (float)i * recNo[i].getSize().y - scrollOffset);
			textNo[i].setPosition(textNo[i].getPosition().x, recNo[i].getPosition().y);

			window.draw(recSem[i]);
			window.draw(textSem[i]);
			window.draw(recYear[i]);
			window.draw(textYear[i]);
			window.draw(recNo[i]);
			window.draw(textNo[i]);
		}
		for (int i = 1; i < numStudents + 1; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(tableWidth, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recA[1][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top));
			window.draw(line);
		}
		for (int i = 0; i < numS; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(recSem[0].getSize().x, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recSem[0].getPosition().x, recSem[i + 1].getGlobalBounds().top));
			window.draw(line);
		}
		for (int i = 0; i < numS; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(recYear[0].getSize().x, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recYear[0].getPosition().x, recYear[i + 1].getGlobalBounds().top));
			window.draw(line);
		}
		for (int i = 0; i < numS; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(recNo[0].getSize().x, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recNo[0].getPosition().x, recNo[i + 1].getGlobalBounds().top));
			window.draw(line);
		}
		sf::RectangleShape line1;
		createABox(line1, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recSem[0].getGlobalBounds().left, recA[1][1].getGlobalBounds().top - 100.0f + tableHeight / 2.0f));
		window.draw(line1);
		sf::RectangleShape line2;
		createABox(line2, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recYear[0].getGlobalBounds().left, recA[1][1].getGlobalBounds().top - 100.0f + tableHeight / 2.0f));
		window.draw(line2);
		sf::RectangleShape line5;
		createABox(line5, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recNo[0].getGlobalBounds().left, recA[1][1].getGlobalBounds().top - 100.0f + tableHeight / 2.0f));
		window.draw(line5);

		for (int i = 0; i < 9; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recA[1][i].getGlobalBounds().left, recA[1][1].getGlobalBounds().top - 100.0f + tableHeight / 2.0f));
			window.draw(line);
		}
		window.draw(hideBack);
		for (int i = 0; i < 9; i++)
		{
			window.draw(recA[0][i]);
			window.draw(textA[0][i]);
			if (i != 0)
			{
				sf::RectangleShape line;
				createABox(line, sf::Vector2f(2.0f, recA[0][i].getSize().y), a->backGroundWhiteDarker, sf::Vector2f(recA[0][i].getGlobalBounds().left, recA[0][1].getGlobalBounds().top + recA[0][1].getSize().y / 2.0f));
				window.draw(line);
			}
		}
		window.draw(recSem[0]);
		window.draw(textSem[0]);	
		window.draw(recYear[0]);
		window.draw(textYear[0]);
		window.draw(recNo[0]);
		window.draw(textNo[0]);
		sf::RectangleShape line3;
		createABox(line3, sf::Vector2f(2.0f, recSem[0].getSize().y), a->backGroundWhiteDarker, sf::Vector2f(recYear[0].getGlobalBounds().left, recYear[0].getPosition().y));
		window.draw(line3);
		sf::RectangleShape line4;
		createABox(line4, sf::Vector2f(2.0f, recSem[0].getSize().y), a->backGroundWhiteDarker, sf::Vector2f(recSem[0].getGlobalBounds().left, recSem[0].getPosition().y));
		window.draw(line4);
		sf::RectangleShape line6;
		createABox(line6, sf::Vector2f(2.0f, recSem[0].getSize().y), a->backGroundWhiteDarker, sf::Vector2f(recA[0][0].getGlobalBounds().left, recNo[0].getPosition().y));
		window.draw(line6);

	}
	window.draw(preButton);
	window.draw(preText);
	window.draw(title);
	window.draw(viewClassScoreText);
	if (numStudents > 8)
		drawScrollBar(scrollbar, scrollbarArea, window, scrollOffset, sizedisplay, fullsize, sf::Vector2f(1950.0f, 275.0f));

}

void ViewClassScoreboardScene::renderViewClassScoreboardScene(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::ViewClassScoreboard && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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
				delete scene->a->curSemester;
				scene->a->curSemester = nullptr;
				delete scene->viewclassscoreboard;
				scene->viewclassscoreboard = nullptr;
				scene->a->currentState = programState::ChooseSemesterClass;
				if (scene->choosesemesterclass == nullptr)
					scene->choosesemesterclass = new ChooseSemesterClassScene(scene->a);
			}
			else if (scrollbar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				isDragging = true;
				scrollbar.setFillColor(scene->a->backGroundWhiteMuchDarker);
			}
		}
	}

	if (numStudents > 8)
		renderScrollbar(scrollbar, scrollbarArea, window, scrollOffset, event, isDragging, scene->a, sf::Vector2f(1700.0f, 275.0f), sizedisplay, fullsize);
}

ViewClassScoreboardScene::~ViewClassScoreboardScene()
{
	if (numStudents != 0)
	{
		for (int i = 0; i < numStudents; i++)
		{
			delete[] table[i];
		}
		delete[] table;
		for (int i = 0; i < numStudents + 1; i++)
		{
			delete[] recA[i];
			delete[] textA[i];
		}
		delete[] recA;
		delete[] textA;
		delete[] recSem;
		delete[] textSem;
		delete[] recYear;
		delete[] textYear;
		delete[] recNo;
		delete[] textNo;

	}
	delete cl;
	delete year;
	delete sem;

}