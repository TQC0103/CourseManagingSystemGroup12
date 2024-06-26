#include "ViewStudentInCourse.h"
#include "Scene.h"
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"

ViewStudentCourseScene::ViewStudentCourseScene(Static* a)
{
	scrollOffset = 0.0f;
	createABox(hideBack, sf::Vector2f((float)a->width, 350.0f), a->backGroundWhite, sf::Vector2f(a->width / 2.0f, 175.0f));

	remove = a->removeSprite;
	remove.setOrigin(remove.getLocalBounds().width / 2.0f, remove.getLocalBounds().height / 2.0f);
	remove.setScale(40.0f / remove.getLocalBounds().width, 40.0f / remove.getLocalBounds().height);
	
	recA = nullptr;
	textA = nullptr;
	createABox(viewStuCourseBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Course's Students", 60, (float)a->width / 2.0f, 75.0f);
	createText(viewStuCourseText, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 60, (float)a->width / 2.0f, 175.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(200.0f, 100.0f), 30.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(100.0f, a->height - 1100.0f), 2.0f, sf::Color::Black);
	c = new Course;
	table = c->viewAllStudentsInACourse(a, numStudent);
	if (numStudent == 0)
	{
		createText(needParticipationText, a->fontB, a->blurGrey, "No students in this course", 100, (float)a->width / 2.0f, (float)a->height / 2.0f);
	}
	else {
		recA = new sf::RectangleShape * [numStudent + 1];
		textA = new sf::Text * [numStudent + 1];
		isClicked = new bool[numStudent + 1];
		for (int i = 0; i < numStudent + 1; i++)
		{
			isClicked[i] = false;
		}
		for (int i = 0; i < numStudent + 1; i++)
		{
			recA[i] = new sf::RectangleShape[7];
			textA[i] = new sf::Text[7];
		}
		float cellHeight = 100.0f;
		float cellWidth = 100.0f;
		sf::Vector2f pos = sf::Vector2f(200.0f, 300.0f);
		for (int i = 0; i < numStudent + 1; i++) {
			for (int j = 0; j < 7; j++) {
				// Draw cell
				if (i == 0)
				{
					switch (j)
					{
					case 0:
					{
						cellWidth = 125.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(pos.x, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "No", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					}
					case 1:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Student ID", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 2:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Last Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 3:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "First Name", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 4:
						cellWidth = 200.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Gender", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 5:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Date Of Birth", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
						break;
					case 6:
						cellWidth = 300.0f;
						createABox(recA[i][j], sf::Vector2f(cellWidth, cellHeight), a->highlightCyan, sf::Vector2f(recA[i][j - 1].getPosition().x + cellWidth / 2.0f + recA[i][j - 1].getSize().x / 2.0f, pos.y));
						createText(textA[i][j], a->fontB, a->backGroundWhite, "Social ID", 25, recA[i][j].getPosition().x, recA[i][j].getPosition().y);
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
				}
			}
		}
		for (int i = 0; i < numStudent + 1; i++)
		{
			tableHeight += recA[i][0].getSize().y;
		}
		for (int i = 0; i < 7; i++)
		{
			tableWidth += recA[0][i].getSize().x;
		}
	}
	times = numStudent;
	sizedisplay = a->height - 250.0f;
	fullsize = tableHeight - 500.0f;
	if (numStudent > 8)
		createAScrollbar(scrollbar, scrollbarArea, sf::Vector2f(20.0f, 50.0f), a->backGroundWhiteDarkerStill, a->backGroundWhiteDarker, sf::Vector2f(1950.0f, 625.0f), 15);


}

void ViewStudentCourseScene::drawViewStudentCourseScene(sf::RenderWindow& window, Static* a)
{
	window.draw(viewStuCourseBackground);

	if (numStudent == 0)
		window.draw(needParticipationText);
	else
	{
		// Draw table
		for (int i = numStudent; i >= 1; i--) {
			for (int j = 0; j < 7; j++) {
				if (isClicked[i] == true)
				{
					recA[i][j].setFillColor(a->lightCyan);
					textA[i][j].setFillColor(sf::Color::Black);

				}
				else
				{
					recA[i][j].setFillColor(a->pastelTitleCyan);
					textA[i][j].setFillColor(a->titleGreyColor);
				}
					
				recA[i][j].setPosition(recA[i][j].getPosition().x, 300.0f + (float)i * recA[i][j].getSize().y - scrollOffset);
				textA[i][j].setPosition(textA[i][j].getPosition().x, 300.0f + (float)i * recA[i][j].getSize().y - scrollOffset);
				window.draw(recA[i][j]);
				window.draw(textA[i][j]);
			}
		}
		

		// Draw horizontal line
		for (int i = 1; i < numStudent + 1; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(tableWidth, 2.0f), a->backGroundWhiteDarker, sf::Vector2f(recA[1][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top));
			window.draw(line);
		}
		// Draw vertical line
		for (int i = 1; i < 7; i++)
		{
			sf::RectangleShape line;
			createABox(line, sf::Vector2f(2.0f, tableHeight), a->backGroundWhiteDarker, sf::Vector2f(recA[1][i].getGlobalBounds().left, recA[1][1].getGlobalBounds().top - 100.0f + tableHeight / 2.0f));
			window.draw(line);
		}
		
		// Draw remove button
		sf::Color lineChosenColor = sf::Color::Black;
		for (int i = 1; i < numStudent + 1; i++)
		{
			if (isClicked[i] == true)
			{
				remove.setPosition(recA[i][6].getPosition().x + 185.0f, recA[i][0].getPosition().y);
				window.draw(remove);
				//Draw line between
				for (int j = 0; j < 7; j++)
				{
					sf::RectangleShape line;
					createABox(line, sf::Vector2f(2.0f, recA[i][j].getSize().y), lineChosenColor, sf::Vector2f(recA[i][j].getGlobalBounds().left, recA[i][j].getPosition().y));
					window.draw(line);
				}
				//Draw line last
				sf::RectangleShape line;
				createABox(line, sf::Vector2f(2.0f, recA[i][6].getSize().y), lineChosenColor, sf::Vector2f(recA[i][6].getGlobalBounds().left + recA[i][6].getSize().x, recA[i][6].getPosition().y));
				window.draw(line);
				//Draw line top and bottom
				sf::RectangleShape line1;
				createABox(line1, sf::Vector2f(tableWidth, 2.0f), lineChosenColor, sf::Vector2f(recA[1][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top));
				window.draw(line1);
				sf::RectangleShape line2;
				createABox(line2, sf::Vector2f(tableWidth, 2.0f), lineChosenColor, sf::Vector2f(recA[1][0].getGlobalBounds().left + tableWidth / 2.0f, recA[i][0].getGlobalBounds().top + recA[i][0].getSize().y));
				window.draw(line2);

			}
		}
		window.draw(hideBack);
		// Draw line between headers
		for (int i = 0; i < 7; i++)
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
		
	}
	
	window.draw(title);
	window.draw(viewStuCourseText);
	window.draw(preButton);
	window.draw(preText);
	if (numStudent > 8)
		drawScrollBar(scrollbar, scrollbarArea, window, scrollOffset, sizedisplay, fullsize, sf::Vector2f(1950.0f, 275.0f));

}

void ViewStudentCourseScene::renderViewStudentCourseScene(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::ViewCourseStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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
				delete scene->viewstudentincourse;
				scene->viewstudentincourse = nullptr;
				scene->a->currentState = programState::CourseManageStudent;
				if (scene->coursemanagestudent == nullptr)
					scene->coursemanagestudent = new CourseManageStudentScene(scene->a);
			}
			else if (scrollbar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				isDragging = true;
				scrollbar.setFillColor(scene->a->backGroundWhiteMuchDarker);
			}
			else for (int i = 1; i < numStudent + 1; i++)
			{
				if (isClicked[i] == true)
				{
					if (remove.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						int check = c->deleteStudent(scene->a, table[i - 1][1]);
						if (check == 0)
						{
							delete scene->viewstudentincourse;
							scene->viewstudentincourse = nullptr;
							if (scene->viewstudentincourse == nullptr)
								scene->viewstudentincourse = new ViewStudentCourseScene(scene->a);
						}
					}
				}
			}
		}
		else if (event.mouseButton.button == sf::Mouse::Right)
		{
			for (int i = 1; i < numStudent + 1; i++)
			{
				for (int j = 0; j < 7; j++)
				{
					if (recA[i][j].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
					{
						if (isClicked[i] == false)
						{
							for (int k = 0; k < numStudent + 1; k++)
							{
								isClicked[k] = false;
							}
							isClicked[i] = true;
						}
						else
						{
							isClicked[i] = false;
						}
						break;
					}
				}
			}
		}
	}
	if (numStudent > 8)
		renderScrollbar(scrollbar, scrollbarArea, window, scrollOffset, event, isDragging, scene->a, sf::Vector2f(1700.0f, 275.0f), sizedisplay, fullsize);
}

ViewStudentCourseScene::~ViewStudentCourseScene()
{
	if (numStudent != 0)
	{
		for (int i = 0; i < numStudent; i++)
		{
			delete[] table[i];
		}
		delete[] table;
		for (int i = 0; i < numStudent + 1; i++)
		{
			delete[] recA[i];
			delete[] textA[i];
		}
		delete[] recA;
		delete[] textA;
		delete[] isClicked;
	}
	delete c;

}