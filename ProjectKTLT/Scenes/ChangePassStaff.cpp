#include "ChangePassStaff.h"
#include "../UserInterface.h"
#include <string>
#include <fstream>

ChangePassStaffScene::ChangePassStaffScene(Static* a)
{
	createABox(changePassPage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(changePassText, a->fontB, a->textColorBlue, "CHANGE PASSWORD", 120, a->width / 2.0f, 150.0f);
	createAButton(preButton, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createABox(oldPassBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(oldPassText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, oldPassBox.getPosition().y);
	createABox(newPassBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(newPassText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, newPassBox.getPosition().y);
	createAButton(submit, submitText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "CONFIRM", sf::Vector2f(a->width - 200.0f, 1000.0f));
}

void ChangePassStaffScene::drawChangePass(sf::RenderWindow& win, Static *a)
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
	sf::Clock cursorClock;
	if (oldPassInputEnable)
	{
		sf::RectangleShape cursorOld;
		setBlinkingCursorInTypingBox(oldPassText, cursorOld, win, cursorClock);
	}
	if (newPassInputEnable)
	{
		sf::RectangleShape cursorNew;
		setBlinkingCursorInTypingBox(newPassText, cursorNew, win, cursorClock);
	}
	if (incorrect == true)
	{
		sf::Text incorrectText;
		createText(incorrectText, a->fontB, sf::Color::Red, "Password is incorrect, please enter the correct password", 50, a->width / 2.0f, 1000.0f);
		win.draw(incorrectText);
	}
}

void ChangePassStaffScene::renderChangePass(sf::Event event, Static *a, sf::RenderWindow& win)
{
	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				oldPassInputEnable = false;
				newPassInputEnable = false;
				oldPassInput = "";
				newPassInput = "";
				a->currentState = programState::MenuStaff;

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
				if (checkOldPass(a->password) == true)
				{
					std::ofstream fOut;
					std::string filename = "../AcademicAcc/" + a->username + ".txt";
					fOut.open(filename);
					if (fOut.is_open() == true)
					{
						a->password = newPassInput;
						fOut << a->password;
						fOut.close();
						a->currentState = programState::MenuStaff;
					}
				}
				else {
					incorrect = true;
				}
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
		else if (newPassInputEnable == true && event.text.unicode == 13)
		{
			
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

bool ChangePassStaffScene::checkOldPass(std::string oldPass)
{
	if (oldPass == oldPassInput)
		return true;
	return false;
}

