#include "ViewStudentProfile.h"
#include "../UserInterface.h"
#include "../Student.h"
#include "Scene.h"

ViewStudentProfileScene::ViewStudentProfileScene(Static* a)
{
	createAButton(preButton, preText, sf::Vector2f(400.0f, 150.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(200.0f, 1000.0f));
	createABox(ViewStudentProfilePage, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(title, a->fontB, a->textColorBlue, "Student Profile", 120, a->width / 2.0f, 150.0f);
	
	createABox(backgr, sf::Vector2f(1000.0f, 600.0f), a->highlightCyan, sf::Vector2f(a->width / 2.0f, a->height / 2.0f - 25.0f));
}

void ViewStudentProfileScene::drawProfile(sf::RenderWindow& win, Static *a)
{
	if (i < 1)
	{
		stu->loadStudentProfile(a->username);
		createText(studentProfile, a->fontN, sf::Color::White, stu->viewStudentProfile(), 50, a->width / 2.0f, a->height / 2.0f );
		i++;
	}
	win.draw(ViewStudentProfilePage);
	win.draw(title);
	win.draw(preButton);
	win.draw(preText);
	win.draw(backgr);
	win.draw(studentProfile);
}

void ViewStudentProfileScene::renderProfile(sf::Event event, Scene *scene, sf::RenderWindow& win)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->viewstudentprofile;
				scene->viewstudentprofile = nullptr;
				if(scene->menustudent == nullptr)
					scene->menustudent = new MenuStudentScene(scene->a);
				scene->a->currentState = programState::MenuStudent;
			}
		}
	}
	sf::Vector2i mousePos = sf::Mouse::getPosition(win);
	if (scene->a->currentState == programState::ViewStudentProfile && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else {
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}

}