#pragma once
#include <SFML/Graphics.hpp>

enum progameState{Welcome, SignIn, SignInAsStudent, SignInAsStaff};

struct Static
{
    progameState currentState;
    float width = 2000;
    float height = 1200;
    sf::Font fontB;
    sf::Font fontN;
    sf::Font fontI;
    sf::Color backGroundWhite = sf::Color(255, 249, 240);
    sf::Color textColorBlue = sf::Color(8, 31, 92);
    sf::Color highlightCyan = sf::Color(93, 117, 153);
    sf::Color pastelGrey = sf::Color(192, 192, 192);
    sf::Color pastelCyan = sf::Color(156, 217, 207);
    sf::Color pastelPink1 = sf::Color(255, 230, 230);
    sf::Color pastelYellow1 = sf::Color(255, 247, 212);
    sf::Color pastelTitleCyan = sf::Color(185, 204, 218);
    sf::Color pastelSoftBlue = sf::Color(155, 184, 205);
    sf::Color titleGreyColor = sf::Color(64, 64, 64);
    sf::Color lightGrey = sf::Color(200, 200, 200);
    Static()
    {
        if (!fontB.loadFromFile("Palatino Linotype Bold.ttf")){}
        if (!fontN.loadFromFile("Palatino LinoType.ttf")){}
        if (!fontI.loadFromFile("Palatino Linotype Italic.ttf")){}
        currentState = progameState::Welcome;
    }
};