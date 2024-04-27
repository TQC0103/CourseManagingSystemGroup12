#include "AddClassCourse.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>


AddClassCourseScene::AddClassCourseScene(Static* a)
{
	isCursorVisible = false;
	createABox(addClassCourseBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addClassCourseText, a->fontB, a->textColorBlue, "Enter Class Course Information", 80, a->width / 2.0f, 75.0f);
	createText(courseText, a->fontB, a->textColorBlue, "Added Into " + a->curCourse->Name, 70, a->width / 2.0f, 225.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(nameClass, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 400.0f, 450.0f));
	createText(nameClassText, a->fontN, sf::Color::White, "", 55, nameClass.getPosition().x, nameClass.getPosition().y);
	createText(enterNameClassHere, a->fontI, sf::Color::White, "ENTER CLASS NAME HERE", 35, nameClass.getPosition().x, nameClass.getPosition().y);

	createABox(lecturer, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 400.0f, 450.0f));
	createText(lecturerText, a->fontN, sf::Color::White, "", 55, lecturer.getPosition().x, lecturer.getPosition().y);
	createText(enterLecturerHere, a->fontI, sf::Color::White, "ENTER LECTURER HERE", 40, lecturer.getPosition().x, lecturer.getPosition().y);

	createABox(weekday, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 400.0f, 700.0f));
	createText(weekdayText, a->fontN, sf::Color::White, "", 55, weekday.getPosition().x, weekday.getPosition().y);
	createText(enterWeekdayHere, a->fontI, sf::Color::White, "ENTER WEEKDAY HERE", 40, weekday.getPosition().x, weekday.getPosition().y);

	createABox(session, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 400.0f, 700.0f));
	createText(sessionText, a->fontN, sf::Color::White, "", 55, session.getPosition().x, session.getPosition().y);
	createText(enterSessionHere, a->fontI, sf::Color::White, "ENTER SESSION HERE", 40, session.getPosition().x, session.getPosition().y);
}

void AddClassCourseScene::drawAddClassCourseScene(sf::RenderWindow& win, Static* a)
{
	win.draw(addClassCourseBackgr);
	win.draw(addClassCourseText);
	win.draw(courseText);

	win.draw(nameClass);
	win.draw(lecturer);
	win.draw(weekday);
	win.draw(session);

	win.draw(preButt);
	win.draw(preText);
	win.draw(create);
	win.draw(creatingText);


	nameClassText.setString(nameClassInput);
	if (nameClassInput.size() >= 15)
		nameClassText.setCharacterSize(45);
	else
		nameClassText.setCharacterSize(55);
	setOriginTextToMiddle(nameClassText);
	win.draw(nameClassText);

	lecturerText.setString(lecturerInput);
	if (lecturerInput.size() >= 15)
		lecturerText.setCharacterSize(45);
	else
		lecturerText.setCharacterSize(55);
	setOriginTextToMiddle(lecturerText);
	win.draw(lecturerText);

	weekdayText.setString(weekdayInput);
	if (weekdayInput.size() >= 15)
		weekdayText.setCharacterSize(45);
	else
		weekdayText.setCharacterSize(55);
	setOriginTextToMiddle(weekdayText);
	win.draw(weekdayText);

	sessionText.setString(sessionInput);
	if (sessionInput.size() >= 15)
		sessionText.setCharacterSize(45);
	else
		sessionText.setCharacterSize(55);
	setOriginTextToMiddle(sessionText);
	win.draw(sessionText);


	if (inputEnable == 2)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(nameClassText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 3)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(lecturerText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 4)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(weekdayText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 5)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(sessionText, cursor, win, cursorClock, isCursorVisible);
	}

	if (inputEnable != 2 && nameClassInput == "")
	{
		win.draw(enterNameClassHere);
	}
	if (inputEnable != 3 && lecturerInput == "")
	{
		win.draw(enterLecturerHere);
	}
	if (inputEnable != 4 && weekdayInput == "")
	{
		win.draw(enterWeekdayHere);
	}
	if (inputEnable != 5 && sessionInput == "")
	{
		win.draw(enterSessionHere);
	}


	if (isWrong == 1)
	{
		createText(fail, a->fontB, sf::Color::Red, "This class is already existing", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == -1)
	{
		createText(fail, a->fontB, sf::Color::Red, "Fail to open files", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 3)
	{
		createText(fail, a->fontB, sf::Color::Red, "Learning day input invalid. Example input: TUESDAY", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 4)
	{
		createText(fail, a->fontB, sf::Color::Red, "Session input invalid. There are sessions: 7:30, 9:30, 13:30, 15:30.", 35, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 5)
	{
		createText(successful, a->fontB, a->textColorGreen, "Create class " + nameClassInput + " successfully", 50, a->width / 2.0f, 1000.0f);
		if (successful.getString().getSize() >= 40)
		{
			successful.setCharacterSize(40);
			successful.setOrigin(successful.getLocalBounds().width / 2.0f, successful.getLocalBounds().height / 2.0f);
		}
		win.draw(successful);
	}

	//if (isWrong == 3)
	//{
	//	createText(fail, a->fontB, sf::Color::Red, a->curSchoolYear->year + " already have 3 semesters", 50, a->width / 2.0f, 1000.0f);
	//	win.draw(fail);
	//}

}

void AddClassCourseScene::renderAddClassCourseScene(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::AddClassCourse && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddClassCourse && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddClassCourse) {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		create.setFillColor(scene->a->highlightCyan);
		creatingText.setFillColor(sf::Color::White);
	}

	if (isWrong == 5)
	{
		sf::sleep(sf::seconds(1.0f));
		if (scene->menucourse == nullptr)
			scene->menucourse = new MenuCourseScene(scene->a);
		delete scene->addclasscourse;
		scene->addclasscourse = nullptr;
		scene->a->currentState = programState::MenuCourse;
	}

	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (scene->menucourse == nullptr)
					scene->menucourse = new MenuCourseScene(scene->a);
				delete scene->addclasscourse;
				scene->addclasscourse = nullptr;
				scene->a->currentState = programState::MenuCourse;
			}
			else if (nameClass.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 2;
			}
			else if (lecturer.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 3;
			}
			else if (weekday.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 4;
			}
			else if (session.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 5;
			}
			else if (create.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				c = new Course;
				int check = c->addClasstoCourse(scene->a, nameClassInput, lecturerInput, weekdayInput, sessionInput);
				delete c;
				if (check == 1)
				{
					isWrong = 1;
				}
				else if (check == 2)
				{
					isWrong = 2;
				}
				else if(check == 3)
				{
					isWrong = 3;
				}
				else if (check == 4)
				{
					isWrong = 4;
				}
				else if (check == -1)
				{
					isWrong = -1;
				}
				else if (check == 0)
				{
					isWrong = 5;
				}
			}
			else {
				inputEnable = -1;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if ((inputEnable >= 2 && inputEnable <= 4) && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			inputEnable++;
		}
		else if ((inputEnable == 5 || inputEnable == -1) && (event.text.unicode == 13))
		{
			c = new Course;
			int check = c->addClasstoCourse(scene->a, nameClassInput, lecturerInput, weekdayInput, sessionInput);
			delete c;
			if (check == 1)
			{
				isWrong = 1;
			}
			else if (check == 2)
			{
				isWrong = 2;
			}
			else if (check == 3)
			{
				isWrong = 3;
			}
			else if (check == 4)
			{
				isWrong = 4;
			}
			else if (check == -1)
			{
				isWrong = -1;
			}
			else if (check == 0)
			{
				isWrong = 5;
			}
		}

		if (inputEnable >= 2 && inputEnable <= 5)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (inputEnable == 2 && nameClassInput.length() < maxInputLength)
				{
					nameClassInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 3 && lecturerInput.length() < maxInputLength)
				{
					lecturerInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 4 && weekdayInput.length() < maxInputLength)
				{
					weekdayInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 5 && sessionInput.length() < maxInputLength)
				{
					sessionInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (inputEnable == 2 && !nameClassInput.empty())
				{
					nameClassInput.pop_back();
				}
				else if (inputEnable == 3 && !lecturerInput.empty())
				{
					lecturerInput.pop_back();
				}
				else if (inputEnable == 4 && !weekdayInput.empty())
				{
					weekdayInput.pop_back();
				}
				else if (inputEnable == 5 && !sessionInput.empty())
				{
					sessionInput.pop_back();
				}
			}
		}
	}
}




