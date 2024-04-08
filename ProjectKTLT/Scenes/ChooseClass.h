#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"
#include "../Class.h"
struct Scene;
struct ChooseClassScene
{
	sf::RectangleShape chooseClassBackground;
	sf::Text chooseClassText;

	sf::ConvexShape preButton;
	sf::Text preText;

	int numClass = 0;
	bool isDragging = false;
	float scrollOffset;
	sf::RectangleShape hideBack;
	sf::RectangleShape scrollbar;
	sf::RectangleShape scrollbarArea;

	sf::ConvexShape* buttons = nullptr;
	sf::Text* labels = nullptr;
	Class *listClasses = nullptr;

	int times = 0;
	float sizedisplay = 0;
	float fullsize = 0;

	ChooseClassScene(Static* a);
	~ChooseClassScene();
	void drawChooseClass(sf::RenderWindow& window, Static* a);
	void renderChooseClass(sf::Event event, Scene *scene, sf::RenderWindow& window);
};