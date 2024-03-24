#include "ChooseClass.h"

ChooseClassScene::ChooseClassScene(Static* a)
{
	createABox(chooseClassBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(chooseClassText, a->fontB, a->textColorBlue, "CHOOSE CLASS", 100, a->width / 2.0f, 100.0f);
	createAButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(150.0f, 1000.0f));
}

void ChooseClassScene::drawChooseClass(sf::RenderWindow& window, Static* a)
{
	window.draw(chooseClassBackground);
	window.draw(chooseClassText);
	window.draw(preButton);
	window.draw(preText);
}

void ChooseClassScene::renderChooseClass(sf::Event event, Static* a, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				a->currentState = programState::MenuStaff;
			}
		}
	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (a->currentState == programState::ChooseClass && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(a->pastelTitleCyan);
		preText.setFillColor(a->titleGreyColor);
	}
	else
	{
		preButton.setFillColor(a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}
}