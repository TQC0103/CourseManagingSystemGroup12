#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "../Class.h"
#include "windows.h"
 
struct Scene;
struct AddStudentClassFileScene
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

	bool fileChosen = false;
	int isWrong = -1;

	AddStudentClassFileScene(Static *a);

	void drawAddFromFile(sf::RenderWindow& win, Static* a);
	void renderAddFromFile(sf::Event event, Scene* scene, sf::RenderWindow& win);
};
