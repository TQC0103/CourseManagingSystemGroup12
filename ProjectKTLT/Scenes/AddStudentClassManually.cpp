#include "AddStudentClassManually.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>


AddStudentClassManuallyScene::AddStudentClassManuallyScene(Static* a)
{
	isWrong = -1;
	isCursorVisible = false;
	createABox(addManuallyBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addManuallyText, a->fontB, a->textColorBlue, "Enter student's information", 100, a->width / 2.0f, 125.0f);
	createText(classText, a->fontB, a->textColorBlue, a->curClass->name, 80, a->width / 2.0f, 225.0f);
	createCornerRoundedButton(preButt, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(create, creatingText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);

	createABox(no, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 350.0f));
	createText(noText, a->fontN, sf::Color::White, "", 40, no.getPosition().x, no.getPosition().y);
	createText(enterNoHere, a->fontI, sf::Color::White, "ENTER NO HERE", 30, no.getPosition().x, no.getPosition().y);

	createABox(id, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 350.0f));
	createText(idText, a->fontN, sf::Color::White, "", 40, id.getPosition().x, id.getPosition().y);
	createText(enterIdHere, a->fontI, sf::Color::White, "ENTER ID HERE", 30, id.getPosition().x, id.getPosition().y);

	createABox(firstname, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 350.0f));
	createText(firstnameText, a->fontN, sf::Color::White, "", 40, firstname.getPosition().x, firstname.getPosition().y);
	createText(enterFirstnameHere, a->fontI, sf::Color::White, "ENTER FIRST NAME HERE", 25, firstname.getPosition().x, firstname.getPosition().y);

	createABox(lastname, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f - 600.0f, 600.0f));
	createText(lastnameText, a->fontN, sf::Color::White, "", 40, lastname.getPosition().x, lastname.getPosition().y);
	createText(enterLastnameHere, a->fontI, sf::Color::White, "ENTER LAST NAME HERE", 25, lastname.getPosition().x, lastname.getPosition().y);

	createABox(gender, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 600.0f));
	createText(genderText, a->fontN, sf::Color::White, "", 40, gender.getPosition().x, gender.getPosition().y);
	createText(enterGenderHere, a->fontI, sf::Color::White, "ENTER GENDER HERE", 25, gender.getPosition().x, gender.getPosition().y);
	
	createABox(birthday, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f + 600.0f, 600.0f));
	createText(birthdayText, a->fontN, sf::Color::White, "", 40, birthday.getPosition().x, birthday.getPosition().y);
	createText(enterbirthdayHere, a->fontI, sf::Color::White, "ENTER DAY OF BIRTH HERE", 25, birthday.getPosition().x, birthday.getPosition().y);

	createABox(sID, sf::Vector2f(400.0f, 150.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, 850.0f));
	createText(sIDText, a->fontN, sf::Color::White, "", 40, sID.getPosition().x, sID.getPosition().y);
	createText(entersIDHere, a->fontI, sf::Color::White, "ENTER SOCIAL ID HERE", 25, sID.getPosition().x, sID.getPosition().y);
}

void AddStudentClassManuallyScene::drawAddMunually(sf::RenderWindow& win, Static* a)
{
	win.draw(addManuallyBackgr);
	win.draw(addManuallyText);

	win.draw(no);
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

	noText.setString(noInput);
	setOriginTextToMiddle(noText);
	win.draw(noText);

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

	if (inputEnable == 1)
	{
		sf::RectangleShape cursor;
		setBlinkingCursorInTypingBox(noText, cursor, win, cursorClock, isCursorVisible);
	}
	else if (inputEnable == 2)
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

	if (inputEnable != 1 && noInput == "")
	{
		win.draw(enterNoHere);
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
	

	if (isWrong == 6)
	{
		createText(fail, a->fontB, sf::Color::Red, "Input dates invalid. Example date: 01/01/2020", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 1)
	{
		createText(fail, a->fontB, sf::Color::Red, "No. is already existing", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 8)
	{
		createText(successful, a->fontB, a->textColorGreen, "Successfully add " + lastnameInput + " " + firstnameInput + " to class " + a->curClass->name, 50, a->width / 2.0f, 1000.0f);
		win.draw(successful);
	}
	else if (isWrong == 2)
	{
		createText(fail, a->fontB, sf::Color::Red, "ID is already existing", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 5)
	{
		createText(fail, a->fontB, sf::Color::Red, "Invalid Gender. Example gender: Nam / Male", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}
	else if (isWrong == 0)
	{
		createText(fail, a->fontB, sf::Color::Red, "Not enough information was input or file error", 50, a->width / 2.0f, 1000.0f);
		win.draw(fail);
	}

}

void AddStudentClassManuallyScene::renderAddManually(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::AddStudentClassManually && preButt.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButt.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentClassManually && create.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		create.setFillColor(scene->a->pastelTitleCyan);
		creatingText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentClassManually) {
		preButt.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
		create.setFillColor(scene->a->highlightCyan);
		creatingText.setFillColor(sf::Color::White);
	}

	if (isWrong == 8)
	{
		createText(successful, scene->a->fontB, scene->a->textColorGreen, "Successfully add " + lastnameInput + " " + firstnameInput + " to class " + scene->a->curClass->name, 50, scene->a->width / 2.0f, 1000.0f);
		win.draw(successful);
		sf::sleep(sf::seconds(1.25f));
		if (scene->menuclass == nullptr)
			scene->menuclass = new MenuClassScene(scene->a);
		delete scene->addstudentclassmanually;
		scene->addstudentclassmanually = nullptr;
		scene->a->currentState = programState::MenuClass;
	}
	 
	// Handle mouse events
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButt.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				scene->addstudentclass = new AddStudentClassScene(scene->a);
				delete scene->addstudentclassmanually;
				scene->addstudentclassmanually = nullptr;
				scene->a->currentState = programState::AddStudentCLass;
			}
			else if(no.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				inputEnable = 1;
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
				Class* cl = new Class;
				int check = cl->insert_new_Class_keyboard(scene->a, noInput, idInput, firstnameInput, lastnameInput, genderInput, birthdayInput, sIDInput);
				if (check == 1)
				{
					isWrong = 1;
				}
				else if (check == 2)
				{
					isWrong = 2;
				}
				else if (check == 5)
				{
					isWrong = 5;
				}
				else if (check == 6)
				{
					isWrong = 6;
				}
				else if (check == 8)
				{
					isWrong = 8;
				}
				else
				{
					isWrong = 0;
				}
				delete cl;
			}	
			else {
				inputEnable = -1;
			}
		}
	}

	// Handle keyboard events
	if (event.type == sf::Event::TextEntered)
	{
		if ((inputEnable >= 1 && inputEnable <= 6) && (event.text.unicode == 13 || event.text.unicode == 9))
		{
			inputEnable++;
		}
		else if ((inputEnable == 7 || inputEnable == -1) && (event.text.unicode == 13))
		{
			// Submit and check
			Class* cl = new Class;
			int check = cl->insert_new_Class_keyboard(scene->a, noInput, idInput, firstnameInput, lastnameInput, genderInput, birthdayInput, sIDInput);
			if (check == 1)
			{
				isWrong = 1;
			}
			else if (check == 2)
			{
				isWrong = 2;
			}
			else if (check == 5)
			{
				isWrong = 5;
			}
			else if (check == 6)
			{
				isWrong = 6;
			}
			else if (check == 8)
			{
				isWrong = 8;
			}
			else
			{
				isWrong = 0;
			}
			delete cl;
		}

		if (inputEnable >= 1 && inputEnable <= 7)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126) // Only handle printable ASCII characters
			{
				// Append the character to the appropriate input string
				if (inputEnable == 1 && noInput.length() < maxInputLength)
				{
					noInput += static_cast<char>(event.text.unicode);
				}
				else if (inputEnable == 2 && idInput.length() < maxInputLength)
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
				if (inputEnable == 1 && !noInput.empty())
				{
					noInput.pop_back();
				}
				else if (inputEnable == 2 && !idInput.empty())
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




