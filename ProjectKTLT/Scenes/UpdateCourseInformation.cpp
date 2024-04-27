#include "UpdateCourseInformation.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>


UpdateCourseInformationScene::UpdateCourseInformationScene(Static* a)
{
	c = new Course;
	c->loadDataOfTheCourse(a);
	isCursorVisible = false;
	createABox(updateCourseBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(updateCourseText, a->fontB, a->textColorBlue, "Update course's information", 60, a->width / 2.0f, 75.0f);
	createText(courseText, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 60, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(update, updatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Update", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createText(curData, a->fontB, a->highlightCyan, "Current data", 60, a->width / 2.0f, 275.0f);
	createText(newData, a->fontB, a->highlightCyan, "New data", 60, a->width / 2.0f, 625.0f);
	createABox(lecturer, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 425.0f));
	createText(lecturerText, a->fontN, sf::Color::White, a->curCourse->Lecturer, 40, lecturer.getPosition().x, lecturer.getPosition().y);

	createABox(weekday, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 425.0f));
	createText(weekdayText, a->fontN, sf::Color::White, a->curCourse->weekDay, 40, weekday.getPosition().x, weekday.getPosition().y);

	createABox(session, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 425.0f));
	createText(sessionText, a->fontN, sf::Color::White, a->curCourse->Session, 40, session.getPosition().x, session.getPosition().y);

	createABox(newLecturer, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 775.0f));
	createText(newLecturerText, a->fontN, sf::Color::White, "", 40, newLecturer.getPosition().x, newLecturer.getPosition().y);
	createText(enterNewLecturer, a->fontI, sf::Color::White, "ENTER NEW LECTURER HERE", 25, newLecturer.getPosition().x, newLecturer.getPosition().y);

	createABox(newWeekday, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 775.0f));
	createText(newWeekdayText, a->fontN, sf::Color::White, "", 40, newWeekday.getPosition().x, newWeekday.getPosition().y);
	createText(enterNewWeekday, a->fontI, sf::Color::White, "ENTER NEW WEEKDAY HERE", 25, newWeekday.getPosition().x, newWeekday.getPosition().y);

	createABox(newSession, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 775.0f));
	createText(newSessionText, a->fontN, sf::Color::White, "", 40, newSession.getPosition().x, newSession.getPosition().y);
	createText(enterNewSession, a->fontI, sf::Color::White, "ENTER NEW SESSION HERE", 25, newSession.getPosition().x, newSession.getPosition().y);

}

void UpdateCourseInformationScene::drawUpdateInfo(sf::RenderWindow& win, Static* a)
{
	win.draw(updateCourseBackgr);
	win.draw(updateCourseText);
	win.draw(curData);
	win.draw(newData);
	win.draw(courseText);
	win.draw(preButt);
	win.draw(preText);
	win.draw(update);
	win.draw(updatingText);
	win.draw(lecturer);
	win.draw(lecturerText);
	win.draw(weekday);
	win.draw(weekdayText);
	win.draw(session);
	win.draw(sessionText);
	win.draw(newLecturer);
	win.draw(newWeekday);
	win.draw(newSession);

	newLecturerText.setString(newLecturerInput);
	setOriginTextToMiddle(newLecturerText);
	win.draw(newLecturerText);

	newWeekdayText.setString(newWeekdayInput);
	setOriginTextToMiddle(newWeekdayText);
	win.draw(newWeekdayText);

	newSessionText.setString(newSessionInput);
	setOriginTextToMiddle(newSessionText);
	win.draw(newSessionText);

if (inputEnable == 4)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(newLecturerText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 5)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(newWeekdayText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 6)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(newSessionText, cursor, win, cursorClock, isCursorVisible);
	}

	if (inputEnable != 4 && newLecturerInput == "")
	{
		win.draw(enterNewLecturer);
	}
	if (inputEnable != 5 && newWeekdayInput == "")
	{
		win.draw(enterNewWeekday);
	}
	if (inputEnable != 6 && newSessionInput == "")
	{
		win.draw(enterNewSession);
	}



	if (isWrong == 5)
	{
		createText(fail, a->fontB, sf::Color::Red, "Invalid weekday. Example weekday input: FRIDAY", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 6)
	{
		createText(fail, a->fontB, sf::Color::Red, "Invalid session. There are 4 session for this course: 7:30, 9:30, 13:30 and 15:30", 35, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 1)
	{
		createText(successful, a->fontB, a->textColorGreen, "Successfully update information for " + a->curCourse->Name + " " + a->curCourse->className, 40, a->width / 2.0f, 1000.0f);
		win.draw(successful);
	}
	else if (isWrong == -1)
	{
		createText(fail, a->fontB, sf::Color::Red, "Can not open file", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}

}

void UpdateCourseInformationScene::renderUpdateInfo(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::UpdateCourseInformation && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::UpdateCourseInformation && update.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		update.setFillColor(scene->a->pastelTitleCyan);
		updatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::UpdateCourseInformation) {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		update.setFillColor(scene->a->highlightCyan);
		updatingText.setFillColor(sf::Color::White);
	}

	if (isWrong == 1)
	{
		win.draw(successful);
		sf::sleep(sf::seconds(1.25f));
		if (scene->menuclasscourse == nullptr)
			scene->menuclasscourse = new MenuClassCourseScene(scene->a);
		delete scene->updatecourseinformation;
		scene->updatecourseinformation = nullptr;
		scene->a->currentState = programState::MenuClassCourse;
	}

	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->menuclasscourse == nullptr)
					scene->menuclasscourse = new MenuClassCourseScene(scene->a);
				delete scene->updatecourseinformation;
				scene->updatecourseinformation = nullptr;
				scene->a->currentState = programState::MenuClassCourse;
			}
			else if (newLecturer.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 4;
			}
			else if (newWeekday.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 5;
			}
			else if (newSession.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 6;
			}
			else if (update.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (newLecturerInput == "")
				{
					newLecturerInput = scene->a->curCourse->Lecturer;
				}
				if (newWeekdayInput == "")
				{
					newWeekdayInput = scene->a->curCourse->weekDay;
				}
				if (newSessionInput == "")
				{
					newSessionInput = scene->a->curCourse->Session;
				}
				int check = c->updateCourse(scene->a, newLecturerInput, newWeekdayInput, newSessionInput);
				if (check == 7)
				{
					isWrong = 5;
				}
				else if (check == 8)
				{
					isWrong = 6;
				}
				else if (check == -1)
				{
					isWrong = -1;
				}
				else if (check == 0)
				{
					isWrong = 1;
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
		if ((inputEnable >= 4 && inputEnable <= 5) && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			inputEnable++;
		}
		else if ((inputEnable == 6 || inputEnable == -1) && (event.text.unicode == 13))
		{
			// Submit and check
			if (newLecturerInput == "")
			{
				newLecturerInput = scene->a->curCourse->Lecturer;
			}
			if (newWeekdayInput == "")
			{
				newWeekdayInput = scene->a->curCourse->weekDay;
			}
			if (newSessionInput == "")
			{
				newSessionInput = scene->a->curCourse->Session;
			}
			int check = c->updateCourse(scene->a, newLecturerInput, newWeekdayInput, newSessionInput);
			if (check == 7)
			{
				isWrong = 5;
			}
			else if (check == 8)
			{
				isWrong = 6;
			}
			else if (check == -1)
			{
				isWrong = -1;
			}
			else if (check == 0)
			{
				isWrong = 1;
			}
		}

		if (inputEnable >= 4 && inputEnable <= 6)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (inputEnable == 4 && newLecturerInput.length() < maxInputLength)
				{
					newLecturerInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 5 && newWeekdayInput.length() < maxInputLength)
				{
					newWeekdayInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 6 && newSessionInput.length() < maxInputLength)
				{
					newSessionInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if(inputEnable == 4 && !newLecturerInput.empty())
				{
					newLecturerInput.pop_back();
				}
				else if (inputEnable == 5 && !newWeekdayInput.empty())
				{
					newWeekdayInput.pop_back();
				}
				else if (inputEnable == 6 && !newSessionInput.empty())
				{
					newSessionInput.pop_back();
				}
			}
		}
	}


}


UpdateCourseInformationScene::~UpdateCourseInformationScene()
{
	if(c != nullptr)
		delete c;
}

