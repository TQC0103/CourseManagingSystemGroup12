#pragma once
#include "Scene.h"
#include "Welcome.h"
#include "../config.h"
#include <iostream>
#include <SFML/Graphics.hpp>

void WelcomeScene::renderWelcome(sf::Event event, Scene *scene, sf::RenderWindow& win) {

    sf::Vector2i mousePos = sf::Mouse::getPosition(win);
    if (scene->a->currentState == programState::Welcome && signInRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        signInRect.setFillColor(scene->a->backGroundWhite);
        signInText.setFillColor(scene->a->titleGreyColor);
    }
    else if (scene->a->currentState == programState::Welcome && exitRect.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y)))
    {
        exitRect.setFillColor(scene->a->backGroundWhite);
        exitText.setFillColor(scene->a->titleGreyColor);
    }
    else {
        signInRect.setFillColor(scene->a->fcc689);
        signInText.setFillColor(sf::Color::White);
        exitRect.setFillColor(scene->a->fcc689);
        exitText.setFillColor(sf::Color::White);
    }
    if (event.type == sf::Event::Closed) {
        win.close();
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (signInRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                if(scene -> signin == nullptr)
                    scene -> signin = new SignInScene(scene -> a);
                scene -> a -> currentState = programState::SignIn;
                delete scene->welcome;
                scene->welcome = nullptr;
            }
            else if (exitRect.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y)) {
                win.close();
            }
        }
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

    createText(welcomeText, a->fontB, a->fcc689, "WELCOME TO", 80, a->width / 2, 100.0f);
    createText(course, a->fontB, a->fcc689, "COURSE MANAGING SYSTEM" , 120, a->width / 2, 250.0f);
    createText(welcomeTextBlur, a->fontB, a->blurGrey, "COURSE MANAGING SYSTEM", 120, a->width / 2 + 5.0f, 257.0f);
    welcomeRect.setSize(sf::Vector2f(a->width, a->height));
    welcomeRect.setFillColor(a->backGroundWhite);

    createAButton(signInRect, signInText, sf::Vector2f(600.0f, 200.0f), 80, a->fcc689, a->fontB, sf::Color::White, "Sign in", sf::Vector2f(575.0f, 675.0f));

    createAButton(exitRect, exitText, sf::Vector2f(600.0f, 200.0f), 80, a->fcc689, a->fontB, sf::Color::White, "Exit", sf::Vector2f(575.0f, 975.0f));
}



