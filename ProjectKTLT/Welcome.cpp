#pragma once
#include "Welcome.h"
#include "config.h"
#include <iostream>

void WelcomeScene::renderWelcome(sf::Event event, programState& currentState, sf::RenderWindow& win) {
    if (event.type == sf::Event::Closed) {
        win.close();
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (signInRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                currentState = programState::SignIn;
            }
            else if (exitRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                win.close();
            }
        }
    }
}

void WelcomeScene::drawWelcome(sf::RenderWindow& win) {
    /*createText(welcomeText, a.fontB, a.textColorBlue, "WELCOME TO", 80, a.width / 2, 100.0f);
    createText(course, a.fontB, a.highlightCyan, "COURSE MANAGING SYSTEM", 120, a.width / 2, 250.0f);
    welcomeRect.setSize(sf::Vector2f(a.width, a.height));
    welcomeRect.setFillColor(a.backGroundWhite);

    createAButton(signInRect, signInText, sf::Vector2f(500.0f, 200.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "SIGN IN", sf::Vector2f(575.0f, 675.0f));

    createAButton(exitRect, exitText, sf::Vector2f(600.0f, 200.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "EXIT", sf::Vector2f(610.0f, 975.0f));*/
    
    win.draw(welcomeRect);
    win.draw(course);
    win.draw(welcomeText);
    win.draw(signInRect);
    win.draw(signInText);   
    win.draw(exitRect);   
    win.draw(exitText);
}
WelcomeScene::WelcomeScene(){
    createText(welcomeText, a.fontB, a.textColorBlue, "WELCOME TO", 80, a.width / 2, 100.0f);
    createText(course, a.fontB, a.highlightCyan, "COURSE MANAGING SYSTEM" , 120, a.width / 2, 250.0f);
    welcomeRect.setSize(sf::Vector2f(a.width, a.height));
    welcomeRect.setFillColor(a.backGroundWhite);

    createAButton(signInRect, signInText, sf::Vector2f(600.0f, 200.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "SIGN IN", sf::Vector2f(575.0f, 675.0f));

    createAButton(exitRect, exitText, sf::Vector2f(600.0f, 200.0f), 80, a.highlightCyan, a.fontB, sf::Color::White, "EXIT", sf::Vector2f(575.0f, 975.0f));
}



