#include "AddStudentToCourse.h"
#include "Scene.h"

AddStudentToCourseScene::AddStudentToCourseScene(Static* a)
{
	createABox(addStudentToCourseBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(addStudentToCourseText, a->fontB, a->textColorBlue, "Add Student To", 80, a->width / 2.0f, 75.0f);
	createText(title, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 80, a->width / 2.0f, 200.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Re-select", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(addManually, addManuallyText, sf::Vector2f(800.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add one by one manually", sf::Vector2f(a->width / 2.0f, 500.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(addFile, addFileText, sf::Vector2f(800.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add students from file", sf::Vector2f(a->width / 2.0f, 800.0f), 2.0f, sf::Color::Black);
}

void AddStudentToCourseScene::drawAddStudentToCourse(sf::RenderWindow& window, Static* a)
{
	window.draw(addStudentToCourseBackground);
	window.draw(addStudentToCourseText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(addManually);
	window.draw(addManuallyText);
	window.draw(addFile);
	window.draw(addFileText);
	window.draw(title);
}

void AddStudentToCourseScene::renderAddStudentToCourse(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::AddStudentCourse && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentCourse && addManually.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		addManually.setFillColor(scene->a->pastelTitleCyan);
		addManuallyText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::AddStudentCourse && addFile.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		addFile.setFillColor(scene->a->pastelTitleCyan);
		addFileText.setFillColor(scene->a->titleGreyColor);
	}
	else
	{
		addManually.setFillColor(scene->a->highlightCyan);
		addFile.setFillColor(scene->a->highlightCyan);
		addManuallyText.setFillColor(sf::Color::White);
		addFileText.setFillColor(sf::Color::White);
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}
	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->addstudenttocourse;
				scene->addstudenttocourse = nullptr;
				if (scene->coursemanagestudent == nullptr)
					scene->coursemanagestudent = new CourseManageStudentScene(scene->a);
				scene->a->currentState = programState::CourseManageStudent;
			}
			else if (addManually.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//delete scene->coursemanagestudent;
				//scene->coursemanagestudent = nullptr;
				//if (scene->addmanually == nullptr)
				//	scene->addmanually = new AddManuallyScene(scene->a);
				//scene->a->currentState = programState::AddManually;
			}
			else if (addFile.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//delete scene->coursemanagestudent;
				//scene->coursemanagestudent = nullptr;
				//if (scene->addfile == nullptr)
				//	scene->addfile = new AddFileScene(scene->a);
				//scene->a->currentState = programState::AddFile;
			}
			


		}
	}
}