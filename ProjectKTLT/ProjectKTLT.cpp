#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
#include "Scenes/Scene.h"



#define para event, scene->a, window

// Functions
int main() {
    Scene *scene = new Scene;
    sf::RenderWindow window(sf::VideoMode((unsigned int)scene->a->width, (unsigned int)scene->a->height), "CourseManagingSystem");

    // A.currentState
    window.setFramerateLimit(60);
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (scene->a->currentState)
            {
            case programState::Welcome:
            {
                scene->welcome->renderWelcome(para);
                break;
            }
            case programState::SignIn:
            {
                scene->signin->renderSignIn(para);
                break;
            }
            case programState::SignInAsStudent:
            {
                scene->signinasstudent->renderSignInAsStudent(para);
                break;
            }
            case programState::SignInAsStaff:
            {
                scene->signinasstaff->renderSignInAsStaff(para);
                break;
            }
            case programState::MenuStudent:
            {
                scene->menustudent->renderMenuStudent(para);
                break;
            }
            case programState::MenuStaff:
            {
                scene->menustaff->renderMenuStaff(para);
                break;
            }
            case programState::ChangePassSta:
            {
                scene->changepasssta->renderChangePass(para);
                break;
            }
            case programState::ChangePassStu:
            {
                scene->changepassstu->renderChangePass(para);
                break;
            }
            default:
                break;
            }

            // Clear the window
            window.clear();

            // Draw the appropriate page based on the status
            switch (scene->a->currentState)
            {
            case programState::Welcome:
            {
                scene->welcome->drawWelcome(window);
                break;
            }
            case programState::SignIn:
            {
                scene->signin->drawSignIn(window);
                break;
            }
            case programState::SignInAsStudent:
            {
                scene->signinasstudent->drawSignInAsStudent(window, scene->a);
                break;
            }
            case programState::SignInAsStaff:
            {
                scene->signinasstaff->drawSignInAsStaff(window, scene->a);
                break;
            }
            case programState::MenuStudent:
            {
                scene->menustudent->drawMenuStudent(window);
                break;
            }
            case programState::MenuStaff:
            {
                scene->menustaff->drawMenuStaff(window);
                break;
            }
            case programState::ChangePassSta:
            {
                scene->changepasssta->drawChangePass(window, scene->a);
                break;
            }
            case programState::ChangePassStu:
            {
                scene->changepassstu->drawChangePass(window, scene->a);
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



