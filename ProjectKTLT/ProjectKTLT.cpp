#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
#include "Scenes/Scene.h"
#include "SchoolYear.h"


// Functions
int main() {
    Scene *scene = new Scene;
    sf::RenderWindow window(sf::VideoMode((unsigned int)scene->a->width, (unsigned int)scene->a->height), "CourseManagingSystem");

    window.setFramerateLimit(60); // Set frame rate limit to 60 FPS
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            switch (scene->a->currentState)
            {
            case programState::Welcome:
            {
                scene->welcome->renderWelcome(event, scene, window);
                break;
            }
            case programState::SignIn:
            {
                scene->signin->renderSignIn(event, scene, window);
                break;
            }
            case programState::SignInAsStudent:
            {
                scene->signinasstudent->renderSignInAsStudent(event, scene, window);
                break;
            }
            case programState::SignInAsStaff:
            {
                scene->signinasstaff->renderSignInAsStaff(event, scene, window);
                break;
            }
            case programState::MenuStudent:
            {
                scene->menustudent->renderMenuStudent(event, scene, window);
                break;
            }
            case programState::MenuStaff:
            {
                scene->menustaff->renderMenuStaff(event, scene, window);
                break;
            }
            case programState::ChangePassSta:
            {
                scene->changepasssta->renderChangePass(event, scene, window);
                break;
            }
            case programState::ChangePassStu:
            {
                scene->changepassstu->renderChangePass(event, scene, window);
                break;
            }
            case programState::ViewStudentProfile:
            {
                scene->viewstudentprofile->renderProfile(event, scene, window);
                break;
            }
            case programState::ChooseSchoolYear:
			{
				scene->chooseschoolyear->renderChooseSchoolYear(event, scene, window);
				break;
			}
            case programState::MenuSchoolYear:
            {
				scene->menuschoolyear->renderMenuSchoolYear(event, scene, window);
				break;
			}
            case programState::ChooseClass:
            {
                scene->chooseclass->renderChooseClass(event, scene, window);
				break;
			}
            case programState::MenuClass:
            {
				scene->menuclass->renderMenuClass(event, scene, window);
                break;
            }
            case programState::ChooseSemester:
            {
                scene->choosesemester->renderChooseSemester(event, scene, window);
                break;
            }
            case programState::MenuSemester:
            {
                scene->menusemester->renderMenuSemester(event, scene, window);
                break;
            }
            case programState::ChooseSchoolYearStudent:
            {
                scene->chooseschoolyearstudent->renderChooseSchoolYear(event, scene, window);
                break;
            }
            case programState::ChooseSemesterStudent:
            {
                scene->choosesemesterstudent->renderChooseSemester(event, scene, window);
                break;
            }
            case programState::MenuSemesterStudent:
            {
                scene->menusemesterstudent->renderMenuSemester(event, scene, window);
                break;
            }
            case programState::AddStudentCLass:
            {
                scene->addstudentclass->renderAddStudentClass(event, scene, window);
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
                scene->welcome->drawWelcome(window, scene->a);
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
            case programState::ViewStudentProfile:
            {
                scene->viewstudentprofile->drawProfile(window, scene->a);
                break;
            }
            case programState::ChooseSchoolYear:
            {
                scene->chooseschoolyear->drawChooseSchoolYear(window, scene->a);
				break;
            }
            case programState::MenuSchoolYear:
            {
				scene->menuschoolyear->drawMenuSchoolYear(window, scene->a);
                break;
            }
            case programState::ChooseClass:
            {
				scene->chooseclass->drawChooseClass(window, scene->a);
                break;
            }
            case programState::MenuClass:
            {
                scene->menuclass->drawMenuClass(window, scene->a);
                break;
            }
            case programState::ChooseSemester:
            {
                scene->choosesemester->drawChooseSemester(window, scene->a);
                break;
            }
            case programState::MenuSemester:
            {
                scene->menusemester->drawMenuSemester(window, scene->a);
                break;
            }
            case programState::ChooseSchoolYearStudent:
            {
                scene->chooseschoolyearstudent->drawChooseSchoolYear(window, scene->a);
                break;
            }
            case programState::ChooseSemesterStudent:
            {
                scene->choosesemesterstudent->drawChooseSemester(window, scene->a);
                break;
            }
            case programState::MenuSemesterStudent:
            {
                scene->menusemesterstudent->drawMenuSemester(window, scene->a);
                break;
            }
            case programState::AddStudentCLass:
            {
                scene->addstudentclass->drawAddStudentClass(window, scene->a);
                break;
            }
            default:
                break;
            }

            // Display the content
            window.display();
        }
        
    }
    delete scene;
    return 0;
}


