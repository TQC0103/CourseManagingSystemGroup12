#include "ChangePassStudent.h"
#include "../UserInterface.h"
#include <string>
#include <fstream>
#include "Scene.h"
ChangePassStudentScene::ChangePassStudentScene(Static* a)
{
	createABox(changePassPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(changePassText, a->fontB, a->textColorBlue, "Change password", 120, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createABox(oldPassBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(oldPassText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, oldPassBox.getPosition().y);
	createABox(newPassBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(newPassText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, newPassBox.getPosition().y);
	createText(enterOldPass, a->fontI, sf::Color::White, "ENTER CURRENT PASSWORD", 40, a->width / 2.0f, 475.0f);
	createText(enterNewPass, a->fontI, sf::Color::White, "ENTER NEW PASSWORD", 40, a->width / 2.0f, 800.0f);
	createCornerRoundedButton(submit, submitText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Confirm", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createText(successful, a->fontB, sf::Color::Green, "Password changed successfully", 50, a->width / 2.0f, 1000.0f);
}

void ChangePassStudentScene::drawChangePass(sf::RenderWindow& win, Static* a)
{
	win.draw(changePassPage);
	win.draw(changePassText);
	win.draw(preButton);
	win.draw(preText);

	win.draw(oldPassBox);
	oldPassText.setString(oldPassInput);
	setOriginTextToMiddle(oldPassText);
	win.draw(oldPassText);

	win.draw(newPassBox);
	newPassText.setString(newPassInput);
	setOriginTextToMiddle(newPassText);
	win.draw(newPassText);
	win.draw(submit);
	win.draw(submitText);
	if (oldPassInputEnable)
	{
		sf::RectangleShape cursorOld;
		setBlinkingCursorInTypingBox(oldPassText, cursorOld, win, cursorClock, isCursorVisible);
	}
	if (newPassInputEnable)
	{
		sf::RectangleShape cursorNew;
		setBlinkingCursorInTypingBox(newPassText, cursorNew, win, cursorClock, isCursorVisible);
	}
	if (incorrect == 1)
	{
		sf::Text incorrectText;
		createText(incorrectText, a->fontB, sf::Color::Red, "         Password is incorrect\n please enter the correct password", 50, a->width / 2.0f, 1000.0f);
		win.draw(incorrectText);
	}
	if (oldPassInputEnable == false && oldPassInput == "")
	{
		win.draw(enterOldPass);
	}
	if (newPassInputEnable == false && newPassInput == "")
	{
		win.draw(enterNewPass);
	}
	if (incorrect == 2)
	{
		win.draw(successful);
	}
}

void ChangePassStudentScene::renderChangePass(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::ChangePassStu && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::ChangePassStu && submit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		submit.setFillColor(scene->a->pastelTitleCyan);
		submitText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		submit.setFillColor(scene->a->highlightCyan);
		submitText.setFillColor(sf::Color::White);
	}

	if (incorrect == 2)
	{
		sf::sleep(sf::seconds(1));
		delete scene->changepassstu;
		scene->changepassstu = nullptr;
		if(scene->menustudent == nullptr)
			scene->menustudent = new MenuStudentScene(scene->a);
		scene->a->currentState = programState::MenuStudent;
		incorrect = 0;
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->changepassstu;
				scene->changepassstu = nullptr;
				if(scene->menustudent == nullptr)
					scene->menustudent = new MenuStudentScene(scene->a);
				scene->a->currentState = programState::MenuStudent;

			}
			else if (oldPassBox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				oldPassInputEnable = true;
				newPassInputEnable = false;
			}
			else if (newPassBox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				oldPassInputEnable = false;
				newPassInputEnable = true;
			}
			else if (submitText.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (checkOldPass(scene->a->password) == true)
				{
					incorrect = 2;
					std::ofstream fOut;
					std::string filename = "../StudentAcc/" + scene->a->username + ".txt";
					fOut.open(filename);
					if (fOut.is_open() == true)
					{
						scene->a->password = newPassInput;
						fOut << scene->a->password;
						fOut.close();
					}
				}
				else {
					incorrect = 1;
				}
			}
			else {
				oldPassInputEnable = false;
				newPassInputEnable = false;
			}
		}
	}
	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if (oldPassInputEnable == true && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			oldPassInputEnable = false;
			newPassInputEnable = true;
		}
		else if ((newPassInputEnable == true && event.text.unicode == 13) || (newPassInputEnable == false && oldPassInputEnable == false))
		{
			if (checkOldPass(scene->a->password) == true)
			{
				incorrect = 2;
				std::ofstream fOut;
				std::string filename = "../StudentAcc/" + scene->a->username + ".txt";
				fOut.open(filename);
				if (fOut.is_open() == true)
				{
					scene->a->password = newPassInput;
					fOut << scene->a->password;
					fOut.close();
				}
			}
			else {
				incorrect = 1;
			}
		}
		if (oldPassInputEnable || newPassInputEnable)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (oldPassInputEnable && oldPassInput.length() < maxPassLength)
				{
					oldPassInput += static_cast<char>(event.text.unicode);
				}
				else if (newPassInputEnable && newPassInput.length() < maxPassLength)
				{
					newPassInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (oldPassInputEnable && !oldPassInput.empty())
				{
					oldPassInput.pop_back();
				}
				else if (newPassInputEnable && !newPassInput.empty())
				{
					newPassInput.pop_back();
				}
			}
		}
	}

	
}

bool ChangePassStudentScene::checkOldPass(std::string oldPass)
{
	if (oldPass == oldPassInput)
		return true;
	return false;
}

