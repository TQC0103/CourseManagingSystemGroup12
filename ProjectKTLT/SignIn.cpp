#include "SignIn.h"
#include "UserInterface.h"
#include "config.h"
#include <SFML/Graphics.hpp>

SignInScene::SignInScene()
{
    // Set up signInPage
    signInPage.setSize(sf::Vector2f((float)a.width, (float)a.height));
    signInPage.setFillColor(a.backGroundWhite);

    // Set up goBackToWelcome button
    goBackToWelcome.setSize(sf::Vector2f(600.0f, 200.0f));
    createAButton(goBackToWelcome, prePageToWelcome, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));

    // Set up ChooseAcc text
    createText(ChooseAcc, a.fontB, a.textColorBlue, "SIGN IN AS", 120, a.width / 2.0f, 150.0f);

    // Set up signInAsStudentButton
    signInAsStudentButton.setSize(sf::Vector2f(600.0f, 200.0f));
    createAButton(signInAsStudentButton, signInAsStudentText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "STUDENT", sf::Vector2f(a.width / 2.0f, 500.0f));

    // Set up signInAsStaffButton
    signInAsStaffButton.setSize(sf::Vector2f(600.0f, 200.0f));
    createAButton(signInAsStaffButton, signInAsStaffText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "STAFF", sf::Vector2f(a.width / 2.0f, 800.0f));
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

void SignInScene::renderSignIn(sf::Event event, programState& currentState, sf::RenderWindow& win)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (goBackToWelcome.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                currentState = programState::Welcome;
            }
            if (signInAsStudentButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                currentState = programState::SignInAsStudent;
            }
            if (signInAsStaffButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
            {
                currentState = programState::SignInAsStaff;
            }
        }
    }
}