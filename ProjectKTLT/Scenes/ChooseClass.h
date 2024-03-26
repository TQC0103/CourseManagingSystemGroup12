#pragma once
#include <SFML/Graphics.hpp>
#include "../config.h"
#include "../UserInterface.h"

struct ChooseClassScene
{
	sf::RectangleShape chooseClassBackground;
	sf::Text chooseClassText;

	sf::RectangleShape preButton;
	sf::Text preText;

	

	ChooseClassScene(Static* a);

	void drawChooseClass(sf::RenderWindow& window, Static* a);
	void renderChooseClass(sf::Event event, Static* a, sf::RenderWindow& window);
};