#include "CreateClass.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>
#include "Scene.h"

CreateClassScene::CreateClassScene(Static* a)
{
	//year = new schoolYear();
	isCursorVisible = false;
	createABox(createClassBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(createClassText, a->fontB, a->textColorBlue, "         Create Class\nFor First Year Students", 80, a->width / 2.0f, 200.0f);
	
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(className, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, a->height / 2.0f));
	createText(classNameText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, className.getPosition().y);
	createText(enterClassnameHere, a->fontI, sf::Color::White, "ENTER CLASS NAME HERE", 40, a->width / 2.0f, className.getPosition().y);
	

}

void CreateClassScene::drawCreateClass(sf::RenderWindow& win, Static* a)
{
	win.draw(createClassBackgr);
	win.draw(createClassText);
	win.draw(preButt);
	win.draw(preText);
	win.draw(create);
	win.draw(creatingText);
	win.draw(className);
	classNameText.setString(classNameInput);
	setOriginTextToMiddle(classNameText);
	win.draw(classNameText);

	if (inputEnable)
	{
		sf::RectangleShape cursorUsername;
		setBlinkingCursorInTypingBox(classNameText, cursorUsername, win, cursorClock, isCursorVisible);
	}
	
	
	if (inputEnable == false && classNameInput == "")
	{
		win.draw(enterClassnameHere);
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

void CreateClassScene::renderCreateClass(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::CreateClass && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CreateClass && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CreateClass) {
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
	
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->menustaff == nullptr)
					scene->menustaff = new MenuStaffScene(scene->a);
				delete scene->createclass;
				scene->createclass = nullptr;
				scene->a->currentState = programState::MenuStaff;
			}
			else if (className.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = true;
			}
			else if (create.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//int check = year->addSemester(semesterData, startDayInput, endDayInput, scene->a);
				//if (check == 0)
				//{
				//	isWrong = 1;
				//}
				//else if (check == 2)
				//{
				//	isWrong = 3;
				//}
				//else {
				//	isWrong = 2;
				//}
			}
			else {
				inputEnable = false;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if (event.text.unicode == 13)
		{
			//int check = year->addSemester(semesterData, startDayInput, endDayInput, scene->a);
			//if (check == 0)
			//{
			//	isWrong = 1;
			//}
			//else if (check == 2)
			//{
			//	isWrong = 3;
			//}
			//else {
			//	isWrong = 2;
			//}
		}
		if (inputEnable == true)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (classNameInput.length() < maxInputLength)
				{
					classNameInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (inputEnable == true && !classNameInput.empty())
				{
					classNameInput.pop_back();
				}
			}
		}
	}


}

CreateClassScene::~CreateClassScene()
{
	
}


