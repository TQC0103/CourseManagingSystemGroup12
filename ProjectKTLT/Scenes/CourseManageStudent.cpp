#include "CourseManageStudent.h"
#include "Scene.h"

CourseManageStudentScene::CourseManageStudentScene(Static* a)
{
	createABox(courseManageStudentBackground, sf::Vector2f(a->width, a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
	createText(courseManageStudentText, a->fontB, a->textColorBlue, "Manage Students", 80, a->width / 2.0f, 75.0f);
	createText(title, a->fontB, a->textColorBlue, a->curCourse->Name + " - " + a->curCourse->className, 80, a->width / 2.0f, 200.0f);
	createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Re-select", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(viewListStudent, viewListStudentText, sf::Vector2f(800.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "View list of students", sf::Vector2f(a->width / 2.0f, 500.0f), 2.0f, sf::Color::Black);
	createCornerRoundedButton(addStudent, addStudentText, sf::Vector2f(800.0f, 200.0f), 50.0f, a->highlightCyan, a->fontB, sf::Color::White, "Add student to this course", sf::Vector2f(a->width / 2.0f, 800.0f), 2.0f, sf::Color::Black);
}

void CourseManageStudentScene::drawCourseManageStudent(sf::RenderWindow& window, Static* a)
{
	window.draw(courseManageStudentBackground);
	window.draw(courseManageStudentText);
	window.draw(preButton);
	window.draw(preText);
	window.draw(viewListStudent);
	window.draw(viewListStudentText);
	window.draw(addStudent);
	window.draw(addStudentText);
	window.draw(title);
}

void CourseManageStudentScene::renderCourseManageStudent(sf::Event event, Scene* scene, sf::RenderWindow& window)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	if (scene->a->currentState == programState::CourseManageStudent && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		preButton.setFillColor(scene->a->pastelTitleCyan);
		preText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CourseManageStudent && viewListStudent.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		viewListStudent.setFillColor(scene->a->pastelTitleCyan);
		viewListStudentText.setFillColor(scene->a->titleGreyColor);
	}
	else if (scene->a->currentState == programState::CourseManageStudent && addStudent.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
	{
		addStudent.setFillColor(scene->a->pastelTitleCyan);
		addStudentText.setFillColor(scene->a->titleGreyColor);
	}
	else
	{
		viewListStudent.setFillColor(scene->a->highlightCyan);
		addStudent.setFillColor(scene->a->highlightCyan);
		viewListStudentText.setFillColor(sf::Color::White);
		addStudentText.setFillColor(sf::Color::White);
		preButton.setFillColor(scene->a->highlightCyan);
		preText.setFillColor(sf::Color::White);
	}
	
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->coursemanagestudent;
				scene->coursemanagestudent = nullptr;
				if (scene->menuclasscourse == nullptr)
					scene->menuclasscourse = new MenuClassCourseScene(scene->a);
				scene->a->currentState = programState::MenuClassCourse;
			}
			else if (viewListStudent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				//delete scene->coursemanagestudent;
				//scene->coursemanagestudent = nullptr;
				//if (scene->viewliststudent == nullptr)
				//	scene->viewliststudent = new ViewListStudentScene(scene->a);
				//scene->a->currentState = programState::ViewListStudent;
			}
			else if (addStudent.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->coursemanagestudent;
				scene->coursemanagestudent = nullptr;
				if (scene->addstudenttocourse == nullptr)
					scene->addstudenttocourse = new AddStudentToCourseScene(scene->a);
				scene->a->currentState = programState::AddStudentCourse;
			}
			

		}
	}
}