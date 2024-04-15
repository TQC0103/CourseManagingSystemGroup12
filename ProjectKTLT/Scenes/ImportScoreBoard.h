#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "windows.h"

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

	bool fileChosen = false;

	ImportScoreboardScene(Static* a);

	void drawImportScoreboard(sf::RenderWindow& win, Static* a);
	void renderImportScoreboard(sf::Event event, Scene* scene, sf::RenderWindow& win);
};

