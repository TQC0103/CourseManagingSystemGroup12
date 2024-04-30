#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "windows.h"
#include "../Course.h"

struct Scene;
struct AddStudentCourseFileScene
{
	sf::RectangleShape addFromFileBackgr;
	sf::Text addFromFileText;

	sf::RectangleShape chooseFileButton;
	sf::Text chooseFileButtonText;

	sf::ConvexShape preButton;
	sf::Text preButtonText;

	sf::ConvexShape submitButton;
	sf::Text filePathText;
	sf::Text submitButtonText;

	std::string filePath;
	std::string filePathDisplay;

	sf::Text fail;
	sf::Text successful;

	bool fileChosen = false;
	int isWrong = 0;
	AddStudentCourseFileScene(Static* a);

	void drawAddFile(sf::RenderWindow& win, Static* a);
	void renderAddFile(sf::Event event, Scene* scene, sf::RenderWindow& win);
	
};

