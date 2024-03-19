#include "SignInAsStudent.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>

SignInAsStudentScene::SignInAsStudentScene(Static *a)
{
	signInStudentPage.setFillColor(a->backGroundWhite);
	signInStudentPage.setSize(sf::Vector2f((float)a->width, (float)a->height));
	createText(studentSignInPageText, a->fontB, a->textColorBlue, "STUDENT", 120, a->width / 2.0f, 150.0f);
	createAButton(signInStudentPreviousButton, signInStudentPreviousText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createAButton(submit, submitText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "SIGN IN", sf::Vector2f(a->width - 200.0f, 1000.0f));
	createABox(usernameStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(usernameStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, usernameStudentBox.getPosition().y);
	createABox(passwordStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(enterPasswordHere, a->fontI, sf::Color::White, "ENTER PASSWORD HERE", 40, a->width / 2.0f, 800.0f);
	createText(enterUsernameHere, a->fontI, sf::Color::White, "ENTER USERNAME HERE", 40, a->width / 2.0f, 475.0f);
	createText(passwordStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, passwordStudentBox.getPosition().y);
}

void SignInAsStudentScene::drawSignInAsStudent(sf::RenderWindow& win, Static *a)
{
	win.draw(signInStudentPage);
	win.draw(studentSignInPageText);
	win.draw(signInStudentPreviousButton);
	win.draw(signInStudentPreviousText);
	win.draw(submit);
	win.draw(submitText);
	win.draw(usernameStudentBox);
	usernameStudentText.setString(usernameStudentInput);
	setOriginTextToMiddle(usernameStudentText);
	win.draw(usernameStudentText);

	win.draw(passwordStudentBox);
	passwordStudentText.setString(passwordStudentInput);
	setOriginTextToMiddle(passwordStudentText);
	win.draw(passwordStudentText);
	sf::Clock cursorClock;
	if (usernameInputEnable)
	{
		sf::RectangleShape cursorUsername;
		setBlinkingCursorInTypingBox(usernameStudentText, cursorUsername, win, cursorClock);
	}
	if (passwordInputEnable)
	{
		sf::RectangleShape cursorPassword;
		setBlinkingCursorInTypingBox(passwordStudentText, cursorPassword, win, cursorClock);
	}
	if (isWrong == true)
	{
		createText(incorrect, a->fontB, sf::Color::Red, "Username or password is incorrect", 50, a->width / 2.0f, 1000.0f);
		win.draw(incorrect);
	}
	if (usernameInputEnable == false && usernameStudentInput == "")
	{
		win.draw(enterUsernameHere);
	}
	if (passwordInputEnable == false && passwordStudentInput == "")
	{
		win.draw(enterPasswordHere);
	}
}

void SignInAsStudentScene::renderSignInAsStudent(sf::Event event, Static *a, sf::RenderWindow& win)
{
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (signInStudentPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				usernameStudentInput = "";
				passwordStudentInput = "";
				usernameInputEnable = false;
				passwordInputEnable = false;
				a->currentState = programState::SignIn;
			}
			else if (usernameStudentBox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				usernameInputEnable = true;
				passwordInputEnable = false;
			}
			else if (passwordStudentBox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{	
				usernameInputEnable = false;
				passwordInputEnable = true;
			}
			else if (submit.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if (checkAccount() == false)
				{
					isWrong = true;
				}
				else {
					a->username = usernameStudentInput;
					a->password = passwordStudentInput;
					a->currentState = programState::MenuStudent;
				}
			}
			else {
				usernameInputEnable = false;
				passwordInputEnable = false;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if (usernameInputEnable == true && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			usernameInputEnable = false;
			passwordInputEnable = true;
		}
		else if ((passwordInputEnable == true && event.text.unicode == 13) || (passwordInputEnable == false && usernameInputEnable == false))
		{
			if (checkAccount() == false)
			{
				isWrong = true;
			}
			else {
				a->username = usernameStudentInput;
				a->password = passwordStudentInput;
				a->currentState = programState::MenuStudent;
			}
		}
		if (usernameInputEnable || passwordInputEnable)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (usernameInputEnable && usernameStudentInput.length() < maxUsernameLength)
				{
					usernameStudentInput += static_cast<char>(event.text.unicode);
				}
				else if (passwordInputEnable && passwordStudentInput.length() < maxPassWordLength)
				{
					passwordStudentInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (usernameInputEnable && !usernameStudentInput.empty())
				{
					usernameStudentInput.pop_back();
				}
				else if (passwordInputEnable && !passwordStudentInput.empty())
				{
					passwordStudentInput.pop_back();
				}
			}
		}
	}
}

bool SignInAsStudentScene::checkAccount()
{
	std::ifstream fIn;
	std::string filename = "../StudentAcc/" + usernameStudentInput + ".txt";
	fIn.open(filename);
	if (fIn.is_open() == false)
	{
		return false;
	}
	std::string password = "";
	std::getline(fIn, password);
	if (password == passwordStudentInput)
		return true;
	return false;
}