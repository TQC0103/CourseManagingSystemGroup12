#include "AddStudentCourseManually.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>


CourseAddStudentManuallyScene::CourseAddStudentManuallyScene(Static* a)
{
	isCursorVisible = false;
	createABox(addManuallyBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addManuallyText, a->fontB, a->textColorBlue, "Enter student's information", 100, a->width / 2.0f, 125.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(id, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 450.0f));
	createText(idText, a->fontN, sf::Color::White, "", 40, id.getPosition().x, id.getPosition().y);
	createText(enterIdHere, a->fontI, sf::Color::White, "ENTER ID HERE", 30, id.getPosition().x, id.getPosition().y);

	createABox(firstname, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 450.0f));
	createText(firstnameText, a->fontN, sf::Color::White, "", 40, firstname.getPosition().x, firstname.getPosition().y);
	createText(enterFirstnameHere, a->fontI, sf::Color::White, "ENTER FIRSTNAME HERE", 30, firstname.getPosition().x, firstname.getPosition().y);

	createABox(lastname, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 450.0f));
	createText(lastnameText, a->fontN, sf::Color::White, "", 40, lastname.getPosition().x, lastname.getPosition().y);
	createText(enterLastnameHere, a->fontI, sf::Color::White, "ENTER LASTNAME HERE", 30, lastname.getPosition().x, lastname.getPosition().y);

	createABox(gender, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 700.0f));
	createText(genderText, a->fontN, sf::Color::White, "", 40, gender.getPosition().x, gender.getPosition().y);
	createText(enterGenderHere, a->fontI, sf::Color::White, "ENTER GENDER HERE", 30, gender.getPosition().x, gender.getPosition().y);

	createABox(birthday, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 700.0f));
	createText(birthdayText, a->fontN, sf::Color::White, "", 40, birthday.getPosition().x, birthday.getPosition().y);
	createText(enterbirthdayHere, a->fontI, sf::Color::White, "ENTER BIRTHDAY HERE", 30, birthday.getPosition().x, birthday.getPosition().y);

	createABox(sID, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 700.0f));
	createText(sIDText, a->fontN, sf::Color::White, "", 40, sID.getPosition().x, sID.getPosition().y);
	createText(entersIDHere, a->fontI, sf::Color::White, "ENTER SOCIAL ID HERE", 30, sID.getPosition().x, sID.getPosition().y);

}

void CourseAddStudentManuallyScene::drawAddMunually(sf::RenderWindow& win, Static* a)
{
	win.draw(addManuallyBackgr);
	win.draw(addManuallyText);

	win.draw(id);
	win.draw(firstname);
	win.draw(lastname);
	win.draw(birthday);
	win.draw(gender);
	win.draw(sID);

	win.draw(preButt);
	win.draw(preText);
	win.draw(create);
	win.draw(creatingText);

	idText.setString(idInput);
	setOriginTextToMiddle(idText);
	win.draw(idText);

	firstnameText.setString(firstnameInput);
	setOriginTextToMiddle(firstnameText);
	win.draw(firstnameText);

	lastnameText.setString(lastnameInput);
	setOriginTextToMiddle(lastnameText);
	win.draw(lastnameText);

	genderText.setString(genderInput);
	setOriginTextToMiddle(genderText);
	win.draw(genderText);

	birthdayText.setString(birthdayInput);
	setOriginTextToMiddle(birthdayText);
	win.draw(birthdayText);

	sIDText.setString(sIDInput);
	setOriginTextToMiddle(sIDText);
	win.draw(sIDText);

	if (inputEnable == 2)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(idText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 3)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(firstnameText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 4)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(lastnameText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 5)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(genderText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 6)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(birthdayText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 7)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(sIDText, cursor, win, cursorClock, isCursorVisible);
	}


	if (inputEnable != 2 && idInput == "")
	{
		win.draw(enterIdHere);
	}
	if (inputEnable != 3 && firstnameInput == "")
	{
		win.draw(enterFirstnameHere);
	}
	if (inputEnable != 4 && lastnameInput == "")
	{
		win.draw(enterLastnameHere);
	}
	if (inputEnable != 5 && genderInput == "")
	{
		win.draw(enterGenderHere);
	}
	if (inputEnable != 6 && birthdayInput == "")
	{
		win.draw(enterbirthdayHere);
	}
	if (inputEnable != 7 && sIDInput == "")
	{
		win.draw(entersIDHere);
	}


	//if (isWrong == 1)
	//{
	//	createText(fail, a->fontB, sf::Color::Red, "Input dates invalid. Example date: 01/01", 50, a->width / 2.0f, 1000.0f);
	//	win.draw(fail);
	//}
	//if (isWrong == 2)
	//{
	//	std::string data = semesterData + semesterData[semesterData.size() - 1];
	//	data[data.size() - 2] = ' ';
	//	createText(successful, a->fontB, sf::Color::Green, "Create " + data + " successfully", 50, a->width / 2.0f, 1000.0f);
	//	win.draw(successful);
	//}
	//if (isWrong == 3)
	//{
	//	createText(fail, a->fontB, sf::Color::Red, a->curSchoolYear->year + " already have 3 semesters", 50, a->width / 2.0f, 1000.0f);
	//	win.draw(fail);
	//}

}

void CourseAddStudentManuallyScene::renderAddManually(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::CourseAddStudentManually && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CourseAddStudentManually && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CourseAddStudentManually) {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		create.setFillColor(scene->a->highlightCyan);
		creatingText.setFillColor(sf::Color::White);
	}

	//if (isWrong == 2)
	//{
	//	sf::sleep(sf::seconds(1.0f));
	//	if (scene->menuschoolyear == nullptr)
	//		scene->menuschoolyear = new MenuSchoolYearScene(scene->a);
	//	delete scene->createsemester;
	//	scene->createsemester = nullptr;
	//	scene->a->currentState = programState::MenuSchoolYear;
	//}
	// 
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->addstudenttocoursemanually;
				scene->addstudenttocoursemanually = nullptr;
				if (scene->addstudenttocourse == nullptr)
					scene->addstudenttocourse = new AddStudentToCourseScene(scene->a);
				scene->a->currentState = programState::AddStudentCourse;
			}
			else if (id.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 2;
			}
			else if (firstname.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 3;
			}
			else if (lastname.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 4;
			}
			else if (gender.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 5;
			}
			else if (birthday.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 6;
			}
			else if (sID.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 7;
			}
			else if (create.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				/*int check = year->addSemester(semesterData, startDayInput, endDayInput, scene->a);*/

			}
			else {
				inputEnable = -1;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if ((inputEnable >= 2 && inputEnable <= 6) && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			inputEnable++;
		}
		else if ((inputEnable == 7 || inputEnable == -1) && (event.text.unicode == 13))
		{
			// Submit and check
		}

		if (inputEnable >= 2 && inputEnable <= 7)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (inputEnable == 2 && idInput.length() < maxInputLength)
				{
					idInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 3 && firstnameInput.length() < maxInputLength)
				{
					firstnameInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 4 && lastnameInput.length() < maxInputLength)
				{
					lastnameInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 5 && genderInput.length() < maxInputLength)
				{
					genderInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 6 && birthdayInput.length() < maxInputLength)
				{
					birthdayInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 7 && sIDInput.length() < maxInputLength)
				{
					sIDInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (inputEnable == 2 && !idInput.empty())
				{
					idInput.pop_back();
				}
				else if (inputEnable == 3 && !firstnameInput.empty())
				{
					firstnameInput.pop_back();
				}
				else if (inputEnable == 4 && !lastnameInput.empty())
				{
					lastnameInput.pop_back();
				}
				else if (inputEnable == 5 && !genderInput.empty())
				{
					genderInput.pop_back();
				}
				else if (inputEnable == 6 && !birthdayInput.empty())
				{
					birthdayInput.pop_back();
				}
				else if (inputEnable == 7 && !sIDInput.empty())
				{
					sIDInput.pop_back();
				}
			}
		}
	}


}




