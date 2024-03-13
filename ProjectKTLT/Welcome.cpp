#pragma once
#include "Welcome.h"
#include "config.h"

void WelcomeScene::drawWelcome(sf::RenderWindow &win) {
    win.draw(welcomeRect);
    win.draw(course);
    win.draw(welcomeText);
    win.draw(signInRect);
    win.draw(signInText);
    win.draw(exitRect);
    win.draw(exitText);
    
}

void WelcomeScene::renderWelcome(sf::Event event, programState &currentState, sf::RenderWindow &win) {
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