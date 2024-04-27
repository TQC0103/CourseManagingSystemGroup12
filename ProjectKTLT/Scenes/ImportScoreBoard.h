#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "windows.h"
#include "../Course.h"

struct Scene;
struct ImportScoreboardScene
{
	sf::RectangleShape importScoreboardBackground;
	sf::Text importScoreboardText;

	sf::RectangleShape chooseFileButton;
	sf::Text chooseFileButtonText;

	sf::ConvexShape preButton;
	sf::Text preButtonText;

	sf::ConvexShape submitButton;
	sf::Text filePathText;
	sf::Text submitButtonText;

	std::string filePath;
	std::string filePathDisplay;

	sf::Text successful;
	sf::Text fail;

	bool fileChosen = false;
	int isWrong = 0;

	ImportScoreboardScene(Static* a);

	void drawImportScoreboard(sf::RenderWindow& win, Static* a);
	void renderImportScoreboard(sf::Event event, Scene* scene, sf::RenderWindow& win);
};

