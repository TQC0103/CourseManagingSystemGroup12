#include "../UserInterface.h"
#include "SignInAsStaff.h"
#include <fstream>
#include <string>
#include "Scene.h"

SignInAsStaffScene::SignInAsStaffScene(Static *a)
{
	isCursorVisible = false;
	signInStudentPage.setFillColor(a->backGroundWhite);
	signInStudentPage.setSize(sf::Vector2f((float)a->width, (float)a->height));
	createText(studentSignInPageText, a->fontB, a->textColorBlue, "STAFF", 120, a->width / 2.0f, 150.0f);
	createAButton(signInStudentPreviousButton, signInStudentPreviousText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
	createAButton(submit, submitText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "SIGN IN", sf::Vector2f(a->width - 200.0f, 1000.0f));
	createABox(usernameStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 475.0f));
	createText(usernameStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, usernameStudentBox.getPosition().y);
	createABox(passwordStudentBox, sf::Vector2f(800.0f, 200.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 800.0f));
	createText(enterPasswordHere, a->fontI, sf::Color::White, "ENTER PASSWORD HERE", 40, a->width / 2.0f, 800.0f);
	createText(enterUsernameHere, a->fontI, sf::Color::White, "ENTER USERNAME HERE", 40, a->width / 2.0f, 475.0f);
	createText(passwordStudentText, a->fontN, sf::Color::White, "", 60, a->width / 2.0f, passwordStudentBox.getPosition().y);
	createText(successful, a->fontB, sf::Color::Green, "Sign in successfully", 50, a->width / 2.0f, 1000.0f);
}

void SignInAsStaffScene::drawSignInAsStaff(sf::RenderWindow& win, Static *a)
{
	win.draw(signInStudentPage);
	win.draw(studentSignInPageText);
	win.draw(signInStudentPreviousButton);
	win.draw(signInStudentPreviousText);
	win.draw(submit);
	win.draw(submitText);
	win.draw(usernameStudentBox);
	usernameStudentText.setString(usernameStaffInput);
	setOriginTextToMiddle(usernameStudentText);
	win.draw(usernameStudentText);

	win.draw(passwordStudentBox);
	passwordStudentText.setString(passwordStaffInput);
	setOriginTextToMiddle(passwordStudentText);
	win.draw(passwordStudentText);
	if (usernameInputEnable)
	{
		sf::RectangleShape cursorUsername;
		setBlinkingCursorInTypingBox(usernameStudentText, cursorUsername, win, cursorClock,	isCursorVisible);
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
	if (usernameInputEnable == false && usernameStaffInput == "")
	{
		win.draw(enterUsernameHere);
	}
	if (passwordInputEnable == false && passwordStaffInput == "")
	{
		win.draw(enterPasswordHere);
	}
	if (isWrong == 2)
	{
		win.draw(successful);
	}
}

void SignInAsStaffScene::renderSignInAsStaff(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::SignInAsStaff && signInStudentPreviousButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		signInStudentPreviousButton.setFillColor(scene->a->pastelTitleCyan);
		signInStudentPreviousText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::SignInAsStaff && submit.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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
		sf::sleep(sf::seconds(1.0f));
		delete scene->signinasstaff;
		scene->signinasstaff = nullptr;
		if (scene->menustaff == nullptr)
			scene->menustaff = new MenuStaffScene(scene->a);
		scene->a->currentState = programState::MenuStaff;
		isWrong = 0;
	}
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (signInStudentPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
<<<<<<< Updated upstream
				usernameStaffInput = "";
				passwordStaffInput = "";
				usernameInputEnable = false;
				passwordInputEnable = false;
				a->currentState = programState::SignIn;
=======
				isWrong = 0;
				delete scene->signinasstaff;
				scene->signinasstaff = nullptr;
				if(scene->signin == nullptr)
					scene->signin = new SignInScene(scene->a);
				scene->a->currentState = programState::SignIn;
>>>>>>> Stashed changes
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
					isWrong = 2;
					scene->a->username = usernameStaffInput;
					scene->a->password = passwordStaffInput;
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
				isWrong = 2;
				scene->a->username = usernameStaffInput;
				scene->a->password = passwordStaffInput;
			}
		}
		if (usernameInputEnable || passwordInputEnable)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (usernameInputEnable && usernameStaffInput.length() < maxUsernameLength)
				{
					usernameStaffInput += static_cast<char>(event.text.unicode);
				}
				else if (passwordInputEnable && passwordStaffInput.length() < maxPassWordLength)
				{
					passwordStaffInput += static_cast<char>(event.text.unicode);
				}
			}
			else if (event.text.unicode == 8) // Handle backspace
			{
				// Erase the last character from the appropriate input string
				if (usernameInputEnable && !usernameStaffInput.empty())
				{
					usernameStaffInput.pop_back();
				}
				else if (passwordInputEnable && !passwordStaffInput.empty())
				{
					passwordStaffInput.pop_back();
				}
			}
		}
	}

	

}
bool SignInAsStaffScene::checkAccount()
{
	std::ifstream fIn;
	std::string filename = "../AcademicAcc/" + usernameStaffInput + ".txt";
	fIn.open(filename);
	if (fIn.is_open() == false)
	{
		return false;
	}
	std::string password = "";
	std::getline(fIn, password);
	if (password == passwordStaffInput)
		return true;
	return false;
}