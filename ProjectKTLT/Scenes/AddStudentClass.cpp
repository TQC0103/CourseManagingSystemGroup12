#include "AddStudentClass.h"
#include <fstream>
#include "Scene.h"

AddStudentClassScene::AddStudentClassScene(Static* a)
{
    createABox(addStudentBackgr, sf::Vector2f((float)a->width, (float)a->height), a->backGroundWhite, sf::Vector2f((float)a->width / 2.0f, a->height / 2.0f));
    createText(addStudentText, a->fontB, a->textColorBlue, "Add Student To " + a->curClass->name, 100, (float)a->width / 2.0f, 150.0f);
    createCornerRoundedButton(addManually, addManuallyText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "Manually", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f - 150.0f)), 2.0f, sf::Color::Black);
    createCornerRoundedButton(addFile, addFileText, sf::Vector2f(600.0f, 200.0f), 60.0f, a->highlightCyan, a->fontB, sf::Color::White, "From file", sf::Vector2f((float)(a->width / 2.0f), (float)(a->height / 2.0f + 150.0f)), 2.0f, sf::Color::Black);
    createCornerRoundedButton(preButton, preText, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);

}

void AddStudentClassScene::drawAddStudentClass(sf::RenderWindow& window, Static* a)
{
    window.draw(addStudentBackgr);
    window.draw(addStudentText);
    window.draw(addManually);
    window.draw(addManuallyText);
    window.draw(addFile);
    window.draw(addFileText);
    window.draw(preButton);
    window.draw(preText);
}

void AddStudentClassScene::renderAddStudentClass(sf::Event event, Scene* scene, sf::RenderWindow& window)
{

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (scene->a->currentState == programState::AddStudentCLass && preButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        preButton.setFillColor(scene->a->pastelTitleCyan);
        preText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::AddStudentCLass && addFile.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        addFile.setFillColor(scene->a->pastelTitleCyan);
        addFileText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::AddStudentCLass && addManually.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        addManually.setFillColor(scene->a->pastelTitleCyan);
        addManuallyText.setFillColor(scene->a->titleGreyColor);
    }
    else
    {
        preButton.setFillColor(scene->a->highlightCyan);
        preText.setFillColor(sf::Color::White);
        addFile.setFillColor(scene->a->highlightCyan);
        addFileText.setFillColor(sf::Color::White);
        addManually.setFillColor(scene->a->highlightCyan);
        addManuallyText.setFillColor(sf::Color::White);
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if (preButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->addstudentclass;
                scene->addstudentclass = nullptr;
                if (scene->menuclass == nullptr)
                    scene->menuclass = new MenuClassScene(scene->a);
                scene->a->currentState = programState::MenuClass;
            }
            else if(addManually.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                delete scene->addstudentclass;
                scene->addstudentclass = nullptr;
                if (scene->addstudentclassmanually == nullptr)
                    scene->addstudentclassmanually = new AddStudentClassManuallyScene(scene->a);
                scene->a->currentState = programState::AddStudentClassManually;
            }
            else if (addFile.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
			{
				delete scene->addstudentclass;
				scene->addstudentclass = nullptr;
				if (scene->addstudentclassfile == nullptr)
					scene->addstudentclassfile = new AddStudentClassFileScene(scene->a);
				scene->a->currentState = programState::AddStudentClassFile;
			}



        }
    }
}

