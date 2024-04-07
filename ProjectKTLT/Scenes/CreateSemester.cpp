#include "CreateSemester.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>
#include "Scene.h"

CreateSemesterScene::CreateSemesterScene(Static* a)
{
	
	isCursorVisible = false;
	createABox(createSemesterBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(createSemesterText, a->fontB, a->textColorBlue, "Create Semester", 80, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createABox(startDay, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(startDayText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, startDay.getPosition().y);
	createABox(endDay, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(enterEndDayHere, a->fontI, sf::Color::White, "ENTER PASSWORD HERE", 40, a->width / 2.0f, 800.0f);
	createText(enterStartDayHere, a->fontI, sf::Color::White, "ENTER USERNAME HERE", 40, a->width / 2.0f, 475.0f);
	createText(endDayText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, endDay.getPosition().y);
	createText(successful, a->fontB, sf::Color::Green, "Sign in successfully", 50, a->width / 2.0f, 1000.0f);
}

void CreateSemesterScene::drawCreateSemester(sf::RenderWindow& win, Static* a)
{
	win.draw(createSemesterBackgr);
	win.draw(createSemesterText);
	win.draw(preButt);
	win.draw(preText);
	win.draw(create);
	win.draw(creatingText);
	win.draw(startDay);
	startDayText.setString(startDayInput);
	setOriginTextToMiddle(startDayText);
	win.draw(startDayText);

	win.draw(endDay);
	endDayText.setString(endDayInput);
	setOriginTextToMiddle(endDayText);
	win.draw(endDayText);
	if (startDayInputEnable)
	{
		sf::RectangleShape cursorUsername;
		setBlinkingCursorInTypingBox(startDayText, cursorUsername, win, cursorClock, isCursorVisible);
	}
	if (endDayInputEnable)
	{
		sf::RectangleShape cursorPassword;
		setBlinkingCursorInTypingBox(endDayText, cursorPassword, win, cursorClock, isCursorVisible);
	}
	if (isWrong == 1)
	{
		createText(fail, a->fontB, sf::Color::Red, "Username or password is incorrect", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	if (startDayInputEnable == false && startDayInput == "")
	{
		win.draw(enterStartDayHere);
	}
	if (endDayInputEnable == false && endDayInput == "")
	{
		win.draw(enterEndDayHere);
	}
	if (isWrong == 2)
	{
		win.draw(successful);
	}

}

void CreateSemesterScene::renderCreateSemester(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::SignInAsStudent && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::SignInAsStudent && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		create.setFillColor(scene->a->highlightCyan);
		creatingText.setFillColor(sf::Color::White);
	}
	if (isWrong == 2)
	{
		sf::sleep(sf::seconds(1.0f)); \
			if (scene->menustudent == nullptr)
				scene->menustudent = new MenuStudentScene(scene->a);
		delete scene->signinasstudent;
		scene->signinasstudent = nullptr;
		scene->a->currentState = programState::MenuStudent;
		isWrong = 0;
	}
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				startDayInput = "";
				endDayInput = "";
				startDayInputEnable = false;
				endDayInputEnable = false;
				scene->signin = new SignInScene(scene->a);
				delete scene->signinasstudent;
				scene->signinasstudent = nullptr;
				scene->a->currentState = programState::SignIn;
			}
			else if (startDay.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				startDayInputEnable = true;
				endDayInputEnable = false;
			}
			else if (endDay.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				startDayInputEnable = false;
				endDayInputEnable = true;
			}
			else if (create.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (add() == false)
				{
					isWrong = 1;
				}
				else {
					isWrong = 2;
					scene->a->username = startDayInput;
					scene->a->password = endDayInput;
				}
			}
			else {
				startDayInputEnable = false;
				endDayInputEnable = false;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if (startDayInputEnable == true && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			startDayInputEnable = false;
			endDayInputEnable = true;
		}
		else if ((endDayInputEnable == true && event.text.unicode == 13) || (endDayInputEnable == false && startDayInputEnable == false))
		{
			if (checkAccount() == false)
			{
				isWrong = true;
			}
			else {
				scene->a->username = startDayInput;
				scene->a->password = endDayInput;
				isWrong = 2;
			}
		}
		if (startDayInputEnable || endDayInputEnable)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (startDayInputEnable && startDayInput.length() < maxInputLength)
				{
					startDayInput += static_cast<char>(event.text.unicode);
				}
				else if (endDayInputEnable && endDayInput.length() < maxInputLength)
				{
					endDayInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (startDayInputEnable && !startDayInput.empty())
				{
					startDayInput.pop_back();
				}
				else if (endDayInputEnable && !endDayInput.empty())
				{
					endDayInput.pop_back();
				}
			}
		}
	}


}


