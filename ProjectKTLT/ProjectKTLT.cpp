#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
// Functions
int main() {
    Static a;
    sf::RenderWindow window(sf::VideoMode((unsigned int)a.width, (unsigned int)a.height), "CourseManagingSystem");
    // Create welcome text
    sf::Text welcomeText;
    createText(welcomeText, a.fontB, a.textColorBlue, "WELCOME TO", 80, (float)window.getSize().x / 2.0f, 150.0f);
    // Create program name
    sf::Text course;
    createText(course, a.fontB, a.highlightCyan, "COURSE MANAGING SYSTEM", 120, (float)window.getSize().x / 2.0f, 300.0f);

    // Define two rectangles to represent welcome page
    sf::RectangleShape welcomePage(sf::Vector2f((float)a.width, (float)a.height));
    welcomePage.setFillColor(a.backGroundWhite);

    // Create buttons from Welcome to sign in page
    sf::RectangleShape SignInRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text SignInText;
    createAButton(SignInRec, SignInText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "SIGN IN", sf::Vector2f(500.0f, 625.0f));
    sf::RectangleShape ExitRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text ExitText;
    createAButton(ExitRec, ExitText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "EXIT", sf::Vector2f(500.0f, 925.0f));

    // Create Sign In page
    sf::RectangleShape signInPage(sf::Vector2f((float)a.width, (float)a.height));
    signInPage.setFillColor(a.backGroundWhite);
    sf::RectangleShape goBackToWelcome(sf::Vector2f(600.0f, 200.0f));
    sf::Text prePageToWelcome;
    createAButton(goBackToWelcome, prePageToWelcome, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));
    sf::Text ChooseAcc;
    createText(ChooseAcc, a.fontB, a.textColorBlue, "SIGN IN AS", 120, a.width / 2.0f, 150.0f);
    sf::RectangleShape signInAsStudentButton(sf::Vector2f(600.0f, 200.0f));
    sf::RectangleShape signInAsStaffButton(sf::Vector2f(600.0f, 200.0f));
    sf::Text signInAsStudentText;
    sf::Text signInAsStaffText;
    createAButton(signInAsStudentButton, signInAsStudentText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "STUDENT", sf::Vector2f(a.width / 2.0f, 500.0f));
    createAButton(signInAsStaffButton, signInAsStaffText, sf::Vector2f(600.0f, 200.0f), 80.0f, a.highlightCyan, a.fontB, sf::Color::White, "STAFF", sf::Vector2f(a.width / 2.0f, 800.0f));

    // Create SignInStudent page
    sf::RectangleShape signInStudentPage(sf::Vector2f((float)a.width, (float)a.height));
    signInStudentPage.setFillColor(a.backGroundWhite);
    // Create previous button in SignInStudent page
    sf::Text studentSignInPageText;
    createText(studentSignInPageText, a.fontB, a.textColorBlue, "STUDENT", 120, a.width / 2.0f, 150.0f);
    sf::RectangleShape signInStudentPreviousButton(sf::Vector2f(600.0f, 200.0f));
    sf::Text signInStudentPreviousText;
    createAButton(signInStudentPreviousButton, signInStudentPreviousText, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));

    // Create SignInStaff page
    sf::RectangleShape signInStaffPage(sf::Vector2f((float)a.width, (float)a.height));
    signInStaffPage.setFillColor(a.backGroundWhite);
    // Create previous button in SignInStaff page
    sf::Text staffSignInPageText;
    createText(staffSignInPageText, a.fontB, a.textColorBlue, "ACADEMIC STAFF", 120, a.width / 2.0f, 150.0f);
    sf::RectangleShape signInStaffPreviousButton(sf::Vector2f(600.0f, 200.0f));
    sf::Text signInStaffPreviousText;
    createAButton(signInStaffPreviousButton, signInStaffPreviousText, sf::Vector2f(400.0f, 150.0f), 60.0f, a.highlightCyan, a.fontB, sf::Color::White, "PREVIOUS", sf::Vector2f(200.0f, 1000.0f));

    // Create username student box
    sf::RectangleShape usernameStudentBox(sf::Vector2f(800.0f, 200.0f));
    createABox(usernameStudentBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 475.0f));

    // Create string to store student username
    std::string usernameStudentInput = "";

    // Create password student box
    sf::RectangleShape passwordStudentBox(sf::Vector2f(200.0f, 800.0f));
    createABox(passwordStudentBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 800.0f));

    sf::Text passwordStudentText;

    // Create string to store student password
    std::string passwordStudentInput = "";

    // Create username staff box
    sf::RectangleShape usernameStaffBox(sf::Vector2f(200.0f, 800.0f));
    createABox(usernameStaffBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 475.0f));
    sf::Text usernameStaffText;

    // Create string to store staff username
    std::string usernameStaffInput = "";

    // Create password staff box
    sf::RectangleShape passwordStaffBox(sf::Vector2f(200.0f, 800.0f));
    createABox(passwordStaffBox, sf::Vector2f(800.0f, 200.0f), a.highlightCyan, sf::Vector2f(a.width / 2.0f, 800.0f));

    // Create string to store student password
    std::string passwordStaffInput = "";


    //further des

    // A.currentState
    /*std::string a.currentState = "Welcome";*/
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the left mouse button is clicked
                    if (a.currentState == progameState::Welcome)
                    {
                        if (SignInRec.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::SignIn;
                        }
                        if (ExitRec.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            window.close();
                        }
                    }
                    if (a.currentState == progameState::SignIn)
                    {
                        if (goBackToWelcome.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::Welcome;
                        }
                        if (signInAsStudentButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::SignInAsStudent;
                        }
                        if (signInAsStaffButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::SignInAsStaff;
                        }
                    }
                    if (a.currentState == progameState::SignInAsStudent)
                    {
                        if (signInStudentPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::SignIn;
                        }
                        /*if (usernameStudentBox.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            while (true)
                            {
                                sf::Event textEvent;
                                while (window.pollEvent(textEvent))
                                {
                                    if (textEvent.type == sf::Event::TextEntered)
                                    {
                                        if (textEvent.text.unicode < 128 && textEvent.text.unicode != 13)
                                        {
                                            usernameStudentInput += textEvent.text.unicode;
                                        }
                                        else if (textEvent.text.unicode == 8 && usernameStudentInput.size() > 0)
                                        {
                                            usernameStudentInput.pop_back();
                                        }
                                    }
                                    else if (textEvent.type == sf::Event::KeyPressed)
                                    {
                                        if (textEvent.key.code == sf::Keyboard::Enter)
                                        {
                                            break;
                                        }
                                    }
                                }
                                window.draw(usernameStudentBox);
                                window.draw(usernameStudentText);
                                window.display();
                            }
                        }*/
                    }
                    if (a.currentState == progameState::SignInAsStaff)
                    {
                        if (signInStaffPreviousButton.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                        {
                            a.currentState = progameState::SignIn;
                        }
                    }
                }
            }
            else if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128)
                {
                    if (a.currentState == progameState::SignInAsStudent)
                    {
                        if (event.text.unicode == '\b')
                        {
                            if (usernameStudentInput.empty() == false)
                            {
                                usernameStudentInput.pop_back();
                            }
                        }
                    }

                }
            }
        }
        // Clear the window
        window.clear();

        // Draw the appropriate page based on the status
        if (a.currentState == progameState::Welcome) {
            window.draw(welcomePage);
            window.draw(welcomeText);
            window.draw(course);
            window.draw(SignInRec);
            window.draw(SignInText);
            window.draw(ExitRec);
            window.draw(ExitText);
        }
        else if (a.currentState == progameState::SignIn) {
            window.draw(signInPage);
            window.draw(goBackToWelcome);
            window.draw(prePageToWelcome);
            window.draw(ChooseAcc);
            window.draw(signInAsStudentButton);
            window.draw(signInAsStudentText);
            window.draw(signInAsStaffButton);
            window.draw(signInAsStaffText);
        }
        else if (a.currentState == progameState::SignInAsStudent)
        {
            window.draw(signInStudentPage);
            window.draw(studentSignInPageText);
            window.draw(signInStudentPreviousButton);
            window.draw(signInStudentPreviousText);
            window.draw(usernameStudentBox);
            window.draw(passwordStudentBox);
        }
        else if (a.currentState == progameState::SignInAsStaff)
        {
            window.draw(signInStaffPage);
            window.draw(staffSignInPageText);
            window.draw(signInStaffPreviousButton);
            window.draw(signInStaffPreviousText);
            window.draw(usernameStaffBox);
            window.draw(passwordStaffBox);
        }

        // Display the content
        window.display();
    }
    return 0;
}



