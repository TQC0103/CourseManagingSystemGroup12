#pragma once
#include "../UserInterface.h"
#include "../config.h"
#include "SFML/Graphics.hpp"

struct ChangePassStaffScene
{
	sf::Text changePassText;

	ChangePassStaffScene();
	void drawChangePass(sf::RenderWindow& win);
	void renderChangePass(sf::Event event, programState& currentState, sf::RenderWindow& win);
};