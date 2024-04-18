#include "ViewCoursesStudent.h"
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Semester.h"
#include "../Student.h"

ViewCoursesStudentScene::ViewCoursesStudentScene(Static* a)
{
	recA = nullptr;
	textA = nullptr;
	createABox(viewCourseStudentBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Courses Learning In", 60, (float)a->width / 2.0f, 75.0f);
	createText(viewCourseStudentText, a->fontB, a->textColorBlue, a->curSchoolYear->year + " - " + a->curSemester->semesterData, 60, (float)a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(200.0f, 100.0f), 30.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(100.0f, a->height - 1100.0f), 2.0f, sf::Color::Black);
	stu = new student;
	table = stu->viewAllCoursesInformations(a, numCourse);
	if (numCourse == 0)
	{
		createText(needParticipationText, a->fontB, a->blurGrey, "You have not participated\n           in any courses", 100, (float)a->width / 2.0f, (float)a->height / 2.0f);
	}
	else {
		recA = new sf::RectangleShape * [numCourse + 1];
		textA = new sf::Text * [numCourse + 1];
		for (int i = 0; i < numCourse + 1; i++)
		{
			recA[i] = new sf::RectangleShape[8];
			textA[i] = new sf::Text[8];
		}
		float cellHeight = 100.0f;
		float cellWidth = 100.0f;
		sf::Vector2f pos = sf::Vector2f(200.0f, 300.0f);
		for (int i = 0; i < numCourse + 1; i++) {
			for (int j = 0; j < 8; j++) {
				// Draw cell
				if (i == 0)
				{
					switch (j)
					{
					case 0:
					{
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(pos.x, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Course ID", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					}
					case 1:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Course Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 2:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Class", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 3:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Lecturer", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 4:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Credit", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 5:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Max Student", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 6:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Week Day", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 7:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontN, a->backGroundWhite, "Session", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					default:
						break;
					}
				}
				else
				{
					float h = (float)recA[i - 1][j].getSize().y;
					createABox(recA[i][j], sf::Vector2f(recA[i - 1][j].getSize().x, h), a->highlightCyan, sf::Vector2f(recA[i - 1][j].getPosition().x, recA[i - 1][j].getPosition().y + h));
					// Draw text
					if (table[i - 1][j].size() > 25)
					{
						createText(textA[i][j], a->fontN, a->backGroundWhite, table[i - 1][j], 18, recA[i][j].getPosition().x, recA[i][j].getPosition().y);

					}
					else if (table[i - 1][j].size() > 18)
						createText(textA[i][j], a->fontN, a->backGroundWhite, table[i - 1][j], 20, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					else {
						createText(textA[i][j], a->fontN, a->backGroundWhite, table[i - 1][j], 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
					}
				}
			}
		}
		for (int i = 0; i < numCourse + 1; i++)
		{
			tableHeight += recA[i][0].getSize().y;
		}
		for (int i = 0; i < 8; i++)
		{
			tableWidth += recA[0][i].getSize().x;
		}
	}
	
}

void ViewCoursesStudentScene::drawViewCourseStudent(sf::RenderWindow& window, Static *a)
{
	window.draw(viewCourseStudentBackground);
	window.draw(preButton);
	window.draw(preText);
	if(numCourse == 0)
		window.draw(needParticipationText);
	else
	{
		for (int i = 0; i < numCourse + 1; i++) {
			for (int j = 0; j < 8; j++) {
				window.draw(recA[i][j]);
				window.draw(textA[i][j]);				
			}
		}
		for (int i = 1; i < numCourse + 1; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(tableWidth, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recA[0][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top));
			window.draw(line);
		}
		for (int i = 1; i < 8; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recA[0][i].getGlobalBounds().left, recA[0][1].getGlobalBounds().top + tableHeight / 2.0f));
			window.draw(line);
		}
	}
	window.draw(title);
	window.draw(viewCourseStudentText);
	
}

void ViewCoursesStudentScene::renderViewCourseStudent(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::ViewCoursesStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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
				delete scene->viewcoursesstudent;
				scene->viewcoursesstudent = nullptr;
				scene->a->currentState = programState::MenuSemesterStudent;
				if (scene->menusemesterstudent == nullptr)
					scene->menusemesterstudent = new MenuSemesterStudentScene(scene->a);
			}
		}
	}
	
}

ViewCoursesStudentScene::~ViewCoursesStudentScene()
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
	}
	delete stu;
	
}