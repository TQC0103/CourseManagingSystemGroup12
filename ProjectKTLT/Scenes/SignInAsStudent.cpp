#include "SignInAsStudent.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>
#include "Scene.h"

SignInAsStudentScene::SignInAsStudentScene(Static *a)
{
	isCursorVisible = false;
	signInStudentPage.setFillColor(a->backGroundWhite);
	signInStudentPage.setSize(sf::Vector2f((float)a->width, (float)a->height));
	createText(studentSignInPageText, a->fontB, a->textColorBlue, "- STUDENT -", 120, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(signInStudentPreviousButton, signInStudentPreviousText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(submit, submitText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Sign In", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createABox(usernameStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(usernameStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, usernameStudentBox.getPosition().y);
	createABox(passwordStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(enterPasswordHere, a->fontI, sf::Color::White, "ENTER PASSWORD HERE", 40, a->width / 2.0f, 800.0f);
	createText(enterUsernameHere, a->fontI, sf::Color::White, "ENTER USERNAME HERE", 40, a->width / 2.0f, 475.0f);
	createText(passwordStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, passwordStudentBox.getPosition().y);
	createText(successful, a->fontB, a->textColorGreen, "Sign in successfully", 50, a->width / 2.0f, 1000.0f);

	hidePassword.setTexture(a->hidePassTexture);
	hidePassword.setScale(passwordStudentBox.getSize().y / hidePassword.getLocalBounds().height / 2.0f, passwordStudentBox.getSize().y / hidePassword.getLocalBounds().height / 2.0f);
	hidePassword.setOrigin(hidePassword.getLocalBounds().width / 2.0f, hidePassword.getLocalBounds().height / 2.0f);
	hidePassword.setPosition(passwordStudentBox.getPosition().x + passwordStudentBox.getSize().x / 2.0f - hidePassword.getGlobalBounds().width / 2.0f - 30.0f, passwordStudentBox.getPosition().y);
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
	if (passwordHiden == true)
	{
		passwordStudentText.setString(passwordStudentInputHidden);
	}
	else
	{
		passwordStudentText.setString(passwordStudentInput);
	}
	setOriginTextToMiddle(passwordStudentText);
	win.draw(passwordStudentText);
	if (usernameInputEnable)
	{
		sf::RectangleShape cursorUsername;
		setBlinkingCursorInTypingBox(usernameStudentText, cursorUsername, win, cursorClock, isCursorVisible);
	}
	if (passwordInputEnable)
	{
		sf::RectangleShape cursorPassword;
		setBlinkingCursorInTypingBox(passwordStudentText, cursorPassword, win, cursorClock, isCursorVisible);
	}
	if (isWrong == 1)
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
	else
	{
		win.draw(hidePassword);
	
	}
	if (isWrong == 2)
	{
		win.draw(successful);
	}

}

void SignInAsStudentScene::renderSignInAsStudent(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::SignInAsStudent && signInStudentPreviousButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		signInStudentPreviousButton.setFillColor(scene->a->pastelTitleCyan);
		signInStudentPreviousText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::SignInAsStudent && submit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		submit.setFillColor(scene->a->pastelTitleCyan);
		submitText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		signInStudentPreviousButton.setFillColor(scene->a->highlightCyan);
		signInStudentPreviousText.setFillColor(sf::Color::White);
		submit.setFillColor(scene->a->highlightCyan);
		submitText.setFillColor(sf::Color::White);
	}
	if (isWrong == 2)
	{
		sf::sleep(sf::seconds(1.0f));\
		if(scene->menustudent == nullptr)
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
			if (signInStudentPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->signin == nullptr)
					scene->signin = new SignInScene(scene->a);
				delete scene->signinasstudent;
				scene->signinasstudent = nullptr;
				scene->a->currentState = programState::SignIn;
			}
			else if (hidePassword.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				passwordHiden = !passwordHiden;
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
					isWrong = 1;
				}
				else {
					isWrong = 2;
					scene->a->username = usernameStudentInput;
					scene->a->password = passwordStudentInput;
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
				scene->a->username = usernameStudentInput;
				scene->a->password = passwordStudentInput;
				isWrong = 2;
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
					passwordStudentInputHidden += "*";
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
					passwordStudentInputHidden.pop_back();
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
	std::string username = "";
	std::string password = "";
	std::getline(fIn, username);
	std::getline(fIn, password);
	if (username == usernameStudentInput && password == passwordStudentInput)
		return true;
	return false;
}