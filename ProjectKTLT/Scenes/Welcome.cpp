#pragma once
#include "Welcome.h"
#include "../config.h"
#include <iostream>

void WelcomeScene::renderWelcome(sf::Event event, Static *a, sf::RenderWindow& win) {

    if (event.type == sf::Event::Closed) {
        win.close();
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (signInRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                a -> currentState = programState::SignIn;
            }
            else if (exitRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                win.close();
            }
        }
    }
    sf::Vector2i mousePos = sf::Mouse::getPosition(win);
    if (a->currentState == programState::Welcome &&  signInRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        signInRect.setFillColor(a->backGroundWhite);
        signInText.setFillColor(a->titleGreyColor);
    }
    else if (a->currentState == programState::Welcome && exitRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        exitRect.setFillColor(a->backGroundWhite);
        exitText.setFillColor(a->titleGreyColor);
    }
    else {
        signInRect.setFillColor(a->fcc689);
        signInText.setFillColor(sf::Color::White);
        exitRect.setFillColor(a->fcc689);
        exitText.setFillColor(sf::Color::White);
    }
}

void WelcomeScene::drawWelcome(sf::RenderWindow& win, Static *a) {

    win.draw(welcomeRect);
    win.draw(a->sprite);
    win.draw(course);
    win.draw(welcomeTextBlur);
    win.draw(welcomeText);
    win.draw(signInRect);
    win.draw(signInText);   
    win.draw(exitRect);   
    win.draw(exitText);
}
WelcomeScene::WelcomeScene(Static *a){

    createText(welcomeText, a->fontB, sf::Color::Black, "WELCOME TO", 80, a->width / 2, 100.0f);
    createText(course, a->fontB, a->fcc689, "COURSE MANAGING SYSTEM" , 120, a->width / 2, 250.0f);
    createText(welcomeTextBlur, a->fontB, a->blurGrey, "COURSE MANAGING SYSTEM", 120, a->width / 2 + 5.0f, 257.0f);
    welcomeRect.setSize(sf::Vector2f(a->width, a->height));
    welcomeRect.setFillColor(a->backGroundWhite);

    createAButton(signInRect, signInText, sf::Vector2f(600.0f, 200.0f), 80, a->fcc689, a->fontB, sf::Color::White, "SIGN IN", sf::Vector2f(575.0f, 675.0f));

    createAButton(exitRect, exitText, sf::Vector2f(600.0f, 200.0f), 80, a->fcc689, a->fontB, sf::Color::White, "EXIT", sf::Vector2f(575.0f, 975.0f));
}



