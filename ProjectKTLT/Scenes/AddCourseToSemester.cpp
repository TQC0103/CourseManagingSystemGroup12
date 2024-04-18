#include "AddCourseToSemester.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>


AddCourseToSemesterScene::AddCourseToSemesterScene(Static* a)
{
	isCursorVisible = false;
	createABox(addCourseSemBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addCourseSemText, a->fontB, a->textColorBlue, "Enter course's information", 100, a->width / 2.0f, 125.0f);
	createText(semText, a->fontB, a->textColorBlue, a->curSemester->semesterData, 80, a->width / 2.0f, 225.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(id, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 400.0f, 450.0f));
	createText(idText, a->fontN, sf::Color::White, "", 55, id.getPosition().x, id.getPosition().y);
	createText(enterIdHere, a->fontI, sf::Color::White, "ENTER ID HERE", 40, id.getPosition().x, id.getPosition().y);

	createABox(name, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 400.0f, 450.0f));
	createText(nameText, a->fontN, sf::Color::White, "", 55, name.getPosition().x, name.getPosition().y);
	createText(enterNameHere, a->fontI, sf::Color::White, "ENTER NAME HERE", 40, name.getPosition().x, name.getPosition().y);

	createABox(credit, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 400.0f, 700.0f));
	createText(creditText, a->fontN, sf::Color::White, "", 55, credit.getPosition().x, credit.getPosition().y);
	createText(enterCreditHere, a->fontI, sf::Color::White, "ENTER CREDIT HERE", 40, credit.getPosition().x, credit.getPosition().y);

	createABox(maxStudent, sf::Vector2f(600.0f, 175.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 400.0f, 700.0f));
	createText(maxStudentText, a->fontN, sf::Color::White, "", 55, maxStudent.getPosition().x, maxStudent.getPosition().y);
	createText(enterMaxStudentHere, a->fontI, sf::Color::White, "ENTER MAX STUDENT HERE", 35, maxStudent.getPosition().x, maxStudent.getPosition().y);

	

}

void AddCourseToSemesterScene::drawAddCourseToSemesterScene(sf::RenderWindow& win, Static* a)
{
	win.draw(addCourseSemBackgr);
	win.draw(addCourseSemText);

	win.draw(id);
	win.draw(name);
	win.draw(credit);
	win.draw(maxStudent);


	win.draw(preButt);
	win.draw(preText);
	win.draw(create);
	win.draw(creatingText);


	idText.setString(idInput);
	if(idInput.size() >= 15)
		idText.setCharacterSize(45);
	else
		idText.setCharacterSize(55);
	setOriginTextToMiddle(idText);
	win.draw(idText);

	if (nameInput.size() >= 15)
		nameText.setCharacterSize(45);
	else
		nameText.setCharacterSize(55);
	nameText.setString(nameInput);
	setOriginTextToMiddle(nameText);
	win.draw(nameText);

	if(creditInput.size() >= 15)
		creditText.setCharacterSize(45);
	else
		creditText.setCharacterSize(55);
	creditText.setString(creditInput);
	setOriginTextToMiddle(creditText);
	win.draw(creditText);

	if(maxStudentInput.size() >= 15)
		maxStudentText.setCharacterSize(45);
	else
		maxStudentText.setCharacterSize(55);
	maxStudentText.setString(maxStudentInput);
	setOriginTextToMiddle(maxStudentText);
	win.draw(maxStudentText);


	if (inputEnable == 2)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(idText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 3)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(nameText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 4)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(creditText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 5)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(maxStudentText, cursor, win, cursorClock, isCursorVisible);
	}

	if (inputEnable != 2 && idInput == "")
	{
		win.draw(enterIdHere);
	}
	if (inputEnable != 3 && nameInput == "")
	{
		win.draw(enterNameHere);
	}
	if (inputEnable != 4 && creditInput == "")
	{
		win.draw(enterCreditHere);
	}
	if (inputEnable != 5 && maxStudentInput == "")
	{
		win.draw(enterMaxStudentHere);
	}


	if (isWrong == 1)
	{
		createText(fail, a->fontB, sf::Color::Red, "Course ID is already existing", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	if (isWrong == 2)
	{
		createText(successful, a->fontB, a->textColorGreen, "Create course " + idInput + " - " + nameInput + " successfully", 50, a->width / 2.0f, 1000.0f);
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

void AddCourseToSemesterScene::renderAddCourseToSemesterScene(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::AddCourseToSemester && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddCourseToSemester && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddCourseToSemester) {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		create.setFillColor(scene->a->highlightCyan);
		creatingText.setFillColor(sf::Color::White);
	}

	if (isWrong == 2)
	{
		sf::sleep(sf::seconds(1.0f));
		if (scene->menusemester == nullptr)
			scene->menusemester = new MenuSemesterScene(scene->a);
		delete scene->addcoursetosemester;
		scene->addcoursetosemester = nullptr;
		scene->a->currentState = programState::MenuSemester;
	}
	 
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->menusemester == nullptr)
					scene->menusemester = new MenuSemesterScene(scene->a);
				delete scene->addcoursetosemester;
				scene->addcoursetosemester = nullptr;
				scene->a->currentState = programState::MenuSemester;
			}
			else if (id.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 2;
			}
			else if (name.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 3;
			}
			else if (credit.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 4;
			}
			else if (maxStudent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 5;
			}
			else if (create.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				sem = new semester();
				bool check = sem->addCourse(scene->a, idInput, nameInput, stoi(creditInput), stoi(maxStudentInput));
				delete sem;
				if (check == false)
				{
					isWrong = 1;
				}
				else
				{
					isWrong = 2;
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
			sem = new semester();
			bool check = sem->addCourse(scene->a, idInput, nameInput, stoi(creditInput), stoi(maxStudentInput));
			delete sem;
			if (check == false)
			{
				isWrong = 1;
			}
			else
			{
				isWrong = 2;
			}
		}

		if (inputEnable >= 2 && inputEnable <= 5)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (inputEnable == 2 && idInput.length() < maxInputLength)
				{
					idInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 3 && nameInput.length() < maxInputLength)
				{
					nameInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 4 && creditInput.length() < maxInputLength)
				{
					creditInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 5 && maxStudentInput.length() < maxInputLength)
				{
					maxStudentInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (inputEnable == 2 && !idInput.empty())
				{
					idInput.pop_back();
				}
				else if (inputEnable == 3 && !nameInput.empty())
				{
					nameInput.pop_back();
				}
				else if (inputEnable == 4 && !creditInput.empty())
				{
					creditInput.pop_back();
				}
				else if (inputEnable == 5 && !maxStudentInput.empty())
				{
					maxStudentInput.pop_back();
				}
			}
		}
	}


}




