#include "Scene.h"
#include "SignIn.h"
#include "../UserInterface.h"
#include "../config.h"
#include <SFML/Graphics.hpp>


SignInScene::SignInScene(Static *a)
{
    // Set up signInPage
    signInPage.setSize(sf::Vector2f((float)a->width, (float)a->height));
    signInPage.setFillColor(a->backGroundWhite);

    // Set up goBackToWelcome button
    createCornerRoundedButton(goBackToWelcome,prePageToWelcome, sf::Vector2f(300.0f, 125.0f), 40.0f, a->highlightCyan, a->fontB, sf::Color::White, "Previous", sf::Vector2f(150.0f, 1000.0f), 2.0f, sf::Color::Black);

    // Set up ChooseAcc text
    createText(ChooseAcc, a->fontB, a->textColorBlue, "Sign In As", 120, a->width / 2.0f, 150.0f);

    // Set up signInAsStudentButton
    createCornerRoundedButton(signInAsStudentButton, signInAsStudentText, sf::Vector2f(600.0f, 200.0f), 80.0f, a->highlightCyan, a->fontB, sf::Color::White, "Student", sf::Vector2f(a->width / 2.0f, 500.0f), 2.0f, sf::Color::Black);

    // Set up signInAsStaffButton
    createCornerRoundedButton(signInAsStaffButton, signInAsStaffText, sf::Vector2f(600.0f, 200.0f), 80.0f, a->highlightCyan, a->fontB, sf::Color::White, "Staff", sf::Vector2f(a->width / 2.0f, 800.0f), 2.0f, sf::Color::Black);
}

void SignInScene::drawSignIn(sf::RenderWindow &win)
{
    win.draw(signInPage);
    win.draw(goBackToWelcome);
    win.draw(prePageToWelcome);
    win.draw(ChooseAcc);
    win.draw(signInAsStudentButton);
    win.draw(signInAsStudentText);
    win.draw(signInAsStaffButton);
    win.draw(signInAsStaffText);
}

void SignInScene::renderSignIn(sf::Event event, Scene *scene, sf::RenderWindow& win)
{

    sf::Vector2i mousePos = sf::Mouse::getPosition(win);
    if (scene->a->currentState == programState::SignIn  && goBackToWelcome.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        goBackToWelcome.setFillColor(scene->a->pastelTitleCyan);
        prePageToWelcome.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::SignIn && signInAsStaffButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        signInAsStaffButton.setFillColor(scene->a->pastelTitleCyan);
        signInAsStaffText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::SignIn && signInAsStudentButton.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        signInAsStudentButton.setFillColor(scene->a->pastelTitleCyan);
        signInAsStudentText.setFillColor(scene->a->titleGreyColor);
    }
    else {
        goBackToWelcome.setFillColor(scene->a->highlightCyan);
        prePageToWelcome.setFillColor(sf::Color::White);
        signInAsStaffButton.setFillColor(scene->a->highlightCyan);
        signInAsStaffText.setFillColor(sf::Color::White);
        signInAsStudentButton.setFillColor(scene->a->highlightCyan);
        signInAsStudentText.setFillColor(sf::Color::White);
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (goBackToWelcome.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                scene->welcome = new WelcomeScene(scene->a);
                scene->a->currentState = programState::Welcome;
                delete scene->signin;
                scene->signin = nullptr;
            }
            else if (signInAsStudentButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                scene->signinasstudent = new SignInAsStudentScene(scene->a);
                delete scene->signin;
                scene->signin = nullptr;
                scene->a->currentState = programState::SignInAsStudent;
            }
            else if (signInAsStaffButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                scene->signinasstaff = new SignInAsStaffScene(scene->a);
                delete scene->signin;
                scene->signin = nullptr;
                scene->a->currentState = programState::SignInAsStaff;
            }
        }
    }
}