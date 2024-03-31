#include "ChooseClass.h"
#include "../Class.h"
#include "Scene.h"

ChooseClassScene::ChooseClassScene(Static* a)
{
	scrollOffset = 0.0f;
	createABox(scrollbar, sf::Vector2f(20.0f, 50.0f), a->backGroundWhiteDarkerStill, sf::Vector2f(1700.0f, 300.0f));
	createABox(chooseClassBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(chooseClassText, a->fontB, a->textColorBlue, "Choose Class", 100, a->width / 2.0f, 100.0f);
	createAButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f));
	createABox(hideBack, sf::Vector2f((float)a->width, 300.0f), a->backGroundWhite, sf::Vector2f(a->width / 2.0f, 100.0f));
	createABox(scrollbarArea, sf::Vector2f(20.0f, 750.0f), a->backGroundWhiteDarker, sf::Vector2f(1700.0f, 625.0f));
	listClasses = new Class();
	numClass = listClasses->load_classes();
	Class *tmp = listClasses->pHeadListClasses;
	buttons = new sf::RectangleShape[numClass];
	labels = new sf::Text[numClass];
	for (int i = 0; i < numClass; ++i) {
		sf::RectangleShape button;
		if (i % 2 == 0)
			createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f - 350.0f, 350.0f + (i / 2) * 300.0f));
		else
		{
			createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f + 350.0f, 350.0f + (i / 2) * 300.0f));
		}

		buttons[i] = button;

		sf::Text label;
		createText(label, a->fontB, sf::Color::White, tmp->name, 60, buttons[i].getPosition().x, buttons[i].getPosition().y);
		tmp = tmp->pNext;
		labels[i] = label;
	}
}

void ChooseClassScene::drawChooseClass(sf::RenderWindow& window, Static* a)
{
	window.draw(chooseClassBackground);
	
	window.draw(preButton);
	window.draw(preText);
	for (int i = 0; i < numClass; i++) {
		buttons[i].setPosition(buttons[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - scrollOffset);
		labels[i].setPosition(labels[i].getPosition().x, 350.0f + (float)(i / 2) * 300.0f - scrollOffset);
		window.draw(buttons[i]);
		window.draw(labels[i]);
	}
	window.draw(hideBack);
	window.draw(chooseClassText);
	scrollbar.setPosition(1700.0f, 300.0f + scrollOffset / (numClass * 150.0f - 500.0f) * 650.0f);
	window.draw(scrollbarArea);
	window.draw(scrollbar);
}

void ChooseClassScene::renderChooseClass(sf::Event event, Scene *scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (event.type == sf::Event::MouseWheelScrolled) {
		scrollOffset += event.mouseWheelScroll.delta * -30.0f;
		if (scrollOffset < 0.0f) {
			scrollOffset = 0.0f;
		}
		if (scrollOffset > (numClass * 150.0f - 500.0f)) {
			scrollOffset = numClass * 150.0f - 500.0f;
		}
	}
	Class* tmp = listClasses->pHeadListClasses;
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->chooseclass;
				scene->chooseclass = nullptr;
				if(scene->menustaff == nullptr)
					scene->menustaff = new MenuStaffScene(scene->a);
				scene->a->currentState = programState::MenuStaff;
			}
		}
		for (int i = 0; i < numClass; i++)
		{
			if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
				scene->a->curClass = tmp;
				scene->menuclass = new MenuClassScene(scene->a);
				scene->a->currentState = programState::MenuClass;
			}
			tmp = tmp->pNext;
		}
		if (scrollbar.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
		{
			isDragging = true;
			scrollbar.setFillColor(scene->a->backGroundWhiteMuchDarker);
		}
	}
	if (event.type == sf::Event::MouseButtonReleased)
	{
		isDragging = false;
		scrollbar.setFillColor(scene->a->backGroundWhiteDarkerStill);
	}
	if (event.type == sf::Event::MouseMoved && isDragging)
	{
		scrollOffset = (static_cast<float>(event.mouseMove.y - 350.0) / 650.0f) * (numClass * 150.0f - 500.0f);
		if (scrollOffset < 0.0f) {
			scrollOffset = 0.0f;
		}
		if (scrollOffset > (numClass * 150.0f - 500.0f)) {
			scrollOffset = numClass * 150.0f - 500.0f;
		}
	}

	for (int i = 0; i < numClass; i++) {
		if (scene->a->currentState == programState::ChooseClass && buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
			buttons[i].setFillColor(scene->a->pastelTitleCyan);
			labels[i].setFillColor(scene->a->titleGreyColor);
		}
		else {
			buttons[i].setFillColor(scene->a->highlightCyan);
			labels[i].setFillColor(sf::Color::White);
		}
	}
	if (scene->a->currentState == programState::ChooseClass && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else
	{
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}


}

ChooseClassScene::~ChooseClassScene()
{
	delete[] buttons;
	delete[] labels;
	listClasses->~Class();
}