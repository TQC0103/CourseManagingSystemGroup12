#include "SignInAsStudent.h"
#include "UserInterface.h"


SignInAsStudentScene::SignInAsStudentScene()
{
	signInStudentPage.setFillColor(a.backGroundWhite);
	signInStudentPage.setSize(sf::Vector2f((float)a.width, (float)a.height));
	createText(studentSignInPageText, a.fontB, a.textColorBlue, "STUDENT", 120, a.width / 2.0f, 150.0f);
	createAButton(signInStudentPreviousButton, signInStudentPreviousText, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	
	createABox(usernameStudentBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 475.0f));
	createText(usernameStudentText, a.fontN, sf::Color::White, "", 60, a.width / 2.0f, usernameStudentBox.getPosition().y);
	createABox(passwordStudentBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 800.0f));
	createText(passwordStudentText, a.fontN, sf::Color::White, "", 60, a.width / 2.0f, passwordStudentBox.getPosition().y);
}

void SignInAsStudentScene::drawSignInAsStudent(sf::RenderWindow& win)
{
	win.draw(signInStudentPage);
	win.draw(studentSignInPageText);
	win.draw(signInStudentPreviousButton);
	win.draw(signInStudentPreviousText);

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
}

void SignInAsStudentScene::renderSignInAsStudent(sf::Event event, programState& currentState, sf::RenderWindow& win)
{
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (signInStudentPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				currentState = programState::SignIn;
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
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if (usernameInputEnable || passwordInputEnable)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (usernameInputEnable && usernameStudentInput.length() < maxUsernameLength)
				{
					usernameStudentInput += static_cast<char>(event.text.unicode);
					std::cout << usernameStudentInput;
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