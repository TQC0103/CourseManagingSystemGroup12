#include "Scenes/ChooseSchoolYear.h"
#include <fstream>

ChooseSchoolYearScene::ChooseSchoolYearScene(Static* a)
{
    createABox(chooseSchoolYearBackground, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(chooseSchoolYearText, a->fontB, a->textColorBlue, "CHOOSE SCHOOL YEAR", 100, (float)a->width / 2.0f, 150.0f);
    createAButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(150.0f, 1000.0f));
    // Load school years from file
    std::ifstream file("../Database/SchoolYear/AllSchoolYear.txt");
    std::string line;
    while (std::getline(file, line)) {
        numSchoolYears++;
    }
    file.close();
    // Limit number of school years to 6 because in reality, there are only 6 school years in a university for undergraduate students
    if(numSchoolYears > 6)
		numSchoolYears = 6;
    // Allocate arrays
    buttons = new sf::RectangleShape[numSchoolYears + 5];
    labels = new sf::Text[numSchoolYears + 5];
    schoolYears = new std::string[numSchoolYears + 5];

    // Load school years from file
    file.open("../Database/SchoolYear/AllSchoolYear.txt");
    int i = 0;

    // Get the first 6 school years in the file which are the most recent ones
    while (std::getline(file, line)) {
        if (i == 6)
            break;
        schoolYears[i] = line;
        i++;
    }
    file.close();

    // Create buttons and labels
    for (int i = 0; i < numSchoolYears; i++) {
        sf::RectangleShape button;
        if(i % 2 == 0)
            createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f - 350.0f, 400.0f + (i / 2) * 300.0f));
        else
        {
            createABox(button, sf::Vector2f(500.0f, 200.0f), a->highlightCyan, sf::Vector2f((float)a->width / 2.0f + 350.0f, 400.0f + (i / 2) * 300.0f));
        }

        buttons[i] = button;

        sf::Text label;
        createText(label, a->fontB, sf::Color::White , schoolYears[i], 60, button.getPosition().x, button.getPosition().y);
        labels[i] = label;
    }
}

void ChooseSchoolYearScene::drawChooseSchoolYear(sf::RenderWindow &window, Static *a)
{
	window.draw(chooseSchoolYearBackground);
	window.draw(chooseSchoolYearText);
    window.draw(preButton);
    window.draw(preText);

    for (int i = 0; i < numSchoolYears; i++) {
        window.draw(buttons[i]);
        window.draw(labels[i]);
    }
}

void ChooseSchoolYearScene::renderChooseSchoolYear(sf::Event event, Static* a, sf::RenderWindow& window)
{
    if(event.type == sf::Event::MouseButtonPressed)
	{
		if(event.mouseButton.button == sf::Mouse::Left)
		{
			for (int i = 0; i < numSchoolYears; i++) {
				if (buttons[i].getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
					a->schoolYear = schoolYears[i];
                    a->currentState = programState::MenuSchoolYear;
				}
			}
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                a->currentState = programState::MenuStaff;
            }
		}
	}
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (int i = 0; i < numSchoolYears; i++) {
        if (buttons[i].getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
            buttons[i].setFillColor(a->pastelTitleCyan);
            labels[i].setFillColor(a->titleGreyColor);
        }
        else {
            buttons[i].setFillColor(a->highlightCyan);
            labels[i].setFillColor(sf::Color::White);
        }
    }
    if(preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
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

ChooseSchoolYearScene::~ChooseSchoolYearScene()
{
    delete[] buttons;
    delete[] labels;
    delete[] schoolYears;
}