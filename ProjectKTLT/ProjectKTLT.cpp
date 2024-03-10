#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"

// Functions
int main() {
    // Create the window
    int width = 2000;
    int height = 1200;
    sf::RenderWindow window(sf::VideoMode(width, height), "CourseManagingSystem");

    // Declare global variables
    sf::Font fontB;
    sf::Font fontN;
    sf::Font fontI;
    sf::Color backGroundWhite(255, 249, 240);
    sf::Color textColorBlue(8, 31, 92);
    sf::Color highlightCyan(93, 117, 153);
    sf::Color pastelGrey(192, 192, 192);
    sf::Color pastelCyan(156, 217, 207);
    sf::Color pastelPink1(255, 230, 230);
    sf::Color pastelYellow1(255, 247, 212);
    sf::Color pastelTitleCyan(185, 204, 218);
    sf::Color pastelSoftBlue(155, 184, 205);
    sf::Color titleGreyColor(64, 64, 64);
    sf::Color lightGrey(200, 200, 200);

    // Set font
    if (!fontB.loadFromFile("Palatino Linotype Bold.ttf"))
        return -1;
    if (!fontN.loadFromFile("Palatino LinoType.ttf"))
        return -1;
    if (!fontI.loadFromFile("Palatino Linotype Italic.ttf"))
        return -1;
  
    // Create welcome text
    sf::Text welcomeText;
    createText(welcomeText, fontB, textColorBlue, "WELCOME TO", 80, (float)window.getSize().x / 2.0f, 150.0f);
    // Create program name
    sf::Text course;
    createText(course, fontB, highlightCyan, "COURSE MANAGING SYSTEM", 120, (float)window.getSize().x / 2.0f, 300.0f);

    // Define two rectangles to represent different pages
    sf::RectangleShape welcomePage(sf::Vector2f((float)width, (float)height));
    welcomePage.setFillColor(backGroundWhite);

    // Create buttons to sign in page
    sf::RectangleShape SignInRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text SignInText;
    createAButton(SignInRec, SignInText, sf::Vector2f(600.0f, 200.0f), highlightCyan, fontB, sf::Color::White, "SIGN IN", sf::Vector2f(250.0f, 500.0f));
    sf::RectangleShape ExitRec(sf::Vector2f(600.0f, 200.0f));
    sf::Text ExitText;
    createAButton(ExitRec, ExitText, sf::Vector2f(600.0f, 200.0f), highlightCyan, fontB,sf::Color::White, "EXIT", sf::Vector2f(250.0f, 800.0f));

    // Create Sign In page
    sf::RectangleShape signInPage(sf::Vector2f((float)width, (float)height));
    
    signInPage.setFillColor(highlightCyan);
    // Flag
    std::string programState = "Welcome";
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Check if the left mouse button is clicked
                    if (SignInRec.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                    {
                        programState = "SignIn";
                    }
                    if (ExitRec.getGlobalBounds().contains((float)event.mouseButton.x, (float)event.mouseButton.y))
                    {
                        window.close();
                    }
                }
            }
        }
        // Clear the window
        window.clear();

        // Draw the appropriate page based on the flag
        if (programState == "Welcome") {
            window.draw(welcomePage);
            window.draw(welcomeText);
            window.draw(course);
            window.draw(SignInRec);
            window.draw(SignInText);
            window.draw(ExitRec);
            window.draw(ExitText);
        }
        else if (programState == "SignIn") {
            window.draw(signInPage);
        }

        // Display the content
        window.display();
    }

    return 0;
}



