#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
#include "Scenes/Scene.h"
#include "Scenes/Welcome.h"
#include "Scenes/SignIn.h"
#include "Scenes/SignInAsStudent.h"

#define para event, a.currentState, window

// Functions
int main() {
    Static a;
    Scene scene;
    sf::RenderWindow window(sf::VideoMode((unsigned int)a.width, (unsigned int)a.height), "CourseManagingSystem");

    // A.currentState
    window.setFramerateLimit(60);
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (a.currentState)
            {
            case programState::Welcome:
            {
                scene.welcome.renderWelcome(para);
                break;
            }
            case programState::SignIn:
            {
                scene.signin.renderSignIn(para);
                break;
            }
            case programState::SignInAsStudent:
            {
                scene.signinasstudent.renderSignInAsStudent(para);
                break;
            }
            case programState::SignInAsStaff:
            {
                scene.signinasstaff.renderSignInAsStaff(para);
                break;
            }
            case programState::MenuStudent:
            {
                scene.menustudent.renderMenuStudent(para);
            }
            case programState::MenuStaff:
            {
                scene.menustaff.renderMenuStaff(para);
            }
            default:
                break;
            }

            // Clear the window
            window.clear();

            // Draw the appropriate page based on the status
            switch (a.currentState)
            {
            case programState::Welcome:
            {
                scene.welcome.drawWelcome(window);
                break;
            }
            case programState::SignIn:
            {
                scene.signin.drawSignIn(window);
                break;
            }
            case programState::SignInAsStudent:
            {
                scene.signinasstudent.drawSignInAsStudent(window);
                break;
            }
            case programState::SignInAsStaff:
            {
                scene.signinasstaff.drawSignInAsStaff(window);
                break;
            }
            case programState::MenuStudent:
            {
                scene.menustudent.drawMenuStudent(window);
                break;
            }
            case programState::MenuStaff:
            {
                scene.menustaff.drawMenuStaff(window);
                break;
            }
            default:
                break;
            }

            // Display the content
            window.display();
        }
        
    }
    return 0;
}



