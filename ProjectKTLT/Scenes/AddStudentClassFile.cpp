#include "AddStudentClassFile.h"
#include "Scene.h"
#include "../UserInterface.h"
#include <fstream>
#include <string>

AddStudentClassFileScene::AddStudentClassFileScene(Static *a)
{
	
	createABox(addFromFileBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addFromFileText, a->fontB, a->textColorBlue, "Select Your Input File", 120, a->width / 2.0f, 150.0f);
	createCornerRoundedButton(preButton, preButtonText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(submitButton, submitButtonText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Enter", sf::Vector2f(a->width - 150.0f, 1000.0f), 2.0f, sf::Color::Black);
	
	createABox(chooseFileButton, sf::Vector2f(1200.0f, 250.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, a->height / 2.0f));
	createText(chooseFileButtonText, a->fontI, sf::Color::White, "CLICK HERE TO SELECT FILE", 50, chooseFileButton.getPosition().x, chooseFileButton.getPosition().y);
}

void AddStudentClassFileScene::drawAddFromFile(sf::RenderWindow& win, Static* a)
{
	win.draw(addFromFileBackgr);
	win.draw(addFromFileText);
	win.draw(preButton);
	win.draw(preButtonText);
	win.draw(submitButton);
	win.draw(submitButtonText);
	win.draw(chooseFileButton);
	if (fileChosen == true) {
		win.draw(filePathText);
	}
	else {
		win.draw(chooseFileButtonText);
	}

}

void AddStudentClassFileScene::renderAddFromFile(sf::Event event, Scene* scene, sf::RenderWindow& win)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::AddStudentClassFile && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preButtonText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentClassFile && submitButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		submitButton.setFillColor(scene->a->pastelTitleCyan);
		submitButtonText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentClassFile) {
		preButton.setFillColor(scene->a->highlightCyan);
		preButtonText.setFillColor(sf::Color::White);
		submitButton.setFillColor(scene->a->highlightCyan);
		submitButtonText.setFillColor(sf::Color::White);
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				if(scene->addstudentclass == nullptr)
					scene->addstudentclass = new AddStudentClassScene(scene->a);
				delete scene->addstudentclassfile;
				scene->addstudentclassfile = nullptr;
				scene->a->currentState = programState::AddStudentCLass;
			}
			else if (chooseFileButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				std::wstring path = openFileDialog(win.getSystemHandle());
				if (!path.empty()) {
					// Convert the std::wstring to std::string
					std::string filePathStr(path.begin(), path.end());
					filePath = filePathStr;
					filePathDisplay = filePath;
					if (filePath.length() > 40) {
						filePathDisplay = "..." + filePath.substr(filePath.length() - 39);
					}
					createText(filePathText, scene->a->fontB, sf::Color::White, filePathDisplay, 50, chooseFileButton.getPosition().x, chooseFileButton.getPosition().y);
					fileChosen = true;
				}
			}
			else if (submitButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{

			}
			
		}
	}
}