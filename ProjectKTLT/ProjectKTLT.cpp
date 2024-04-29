#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "UserInterface.h"
#include "config.h"
#include "Scenes/Scene.h"
#include "SchoolYear.h"
#include "Student.h"
#include "Semester.h"
#include "Course.h"
// Functions
int main() {
	


    Scene* scene = new Scene;
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
            case programState::CreateSemester:
            {
                scene->createsemester->renderCreateSemester(event, scene, window);
                break;
            }
            case programState::AddStudentClassManually:
            {
                scene->addstudentclassmanually->renderAddManually(event, scene, window);
                break;
            }
            case programState::ChooseCourses:
            {
                scene->choosecoursescene->renderChooseCourses(event, scene, window);
                break;
            }
            case programState::MenuCourse:
            {
                scene->menucourse->renderMenuCourse(event, scene, window);
                break;
            }
            case programState::ChooseClassCourse:
            {
                scene->chooseclasscourse->renderChooseClassCourses(event, scene, window);
                break;
            }
            case programState::AddStudentClassFile:
            {
                scene->addstudentclassfile->renderAddFromFile(event, scene, window);
                break;
            }
            case programState::CreateClass:
            {
                scene->createclass->renderCreateClass(event, scene, window);
                break;
            }
            case programState::MenuClassCourse:
            {
                scene->menuclasscourse->renderMenuClassCourse(event, scene, window);
                break;
            }
            case programState::CourseManageScoreBoard:
            {
                scene->coursemanagescoreboard->renderCourseManageScoreBoard(event, scene, window);
                break;
            }
            case programState::CourseManageStudent:
            {
                scene->coursemanagestudent->renderCourseManageStudent(event, scene, window);
                break;
            }
            case programState::AddStudentCourse:
            {
                scene->addstudenttocourse->renderAddStudentToCourse(event, scene, window);
                break;
            }
            case programState::ImportScoreboard:
            {
                scene->importscoreboard->renderImportScoreboard(event, scene, window);
                break;
            }
            case programState::CourseAddStudentManually:
            {
                scene->addstudenttocoursemanually->renderAddManually(event, scene, window);
                break;
            }
            case programState::CourseAddStudentFIle:
            {
                scene->addstudenttocoursefile->renderAddFile(event, scene, window);
                break;
            }
            case programState::ViewCoursesStudent:
            {
				scene->viewcoursesstudent->renderViewCourseStudent(event, scene, window);
				break;
			}
            case programState::AddCourseToSemester:
            {
                scene->addcoursetosemester->renderAddCourseToSemesterScene(event, scene, window);
                break;
            }
            case programState::ViewScoreboardStudent:
            {
				scene->viewscoreboardstudent->renderViewScoreboardScene(event, scene, window);
				break;
			}
            case programState::ViewStudentInClass:
            {
                scene->viewstudentinclass->renderViewStudentInClassScene(event, scene, window);
                break;
            }
            case programState::UpdateCourseInformation:
            {
				scene->updatecourseinformation->renderUpdateInfo(event, scene, window);
				break;
			}
            case programState::AddClassCourse:
            {
                scene->addclasscourse->renderAddClassCourseScene(event, scene, window);
                break;
            }
            case programState::ViewCourseScoreboard:
            {
				scene->viewcoursescoreboard->renderViewScoreboardCourseScene(event, scene, window);
				break;
			}
            case programState::ViewCourseStudent:
			{
                scene->viewstudentincourse->renderViewStudentCourseScene(event, scene, window);
                break;
            }
            case programState::ChooseSchoolYearClass:
			{
				scene->chooseschoolyearclass->renderChooseSchoolYearClassScene(event, scene, window);
				break;
			}
            case programState::ChooseSemesterClass:
            {
                scene->choosesemesterclass->renderChooseSemesterClassScene(event, scene, window);
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
            case programState::CreateSemester:
            {
                scene->createsemester->drawCreateSemester(window, scene->a);
                break;
            }
            case programState::AddStudentClassManually:
            {
                scene->addstudentclassmanually->drawAddMunually(window, scene->a);
                break;
            }
            case programState::ChooseCourses:
            {
                scene->choosecoursescene->drawChooseCourses(window, scene->a);
                break;
            }
            case programState::MenuCourse:
            {
                scene->menucourse->drawMenuCourse(window, scene->a);
                break;
            }
            case programState::ChooseClassCourse:
            {
                scene->chooseclasscourse->drawChooseClassCourses(window, scene->a);
                break;
            }
            case programState::AddStudentClassFile:
            {
                scene->addstudentclassfile->drawAddFromFile(window, scene->a);
                break;
            }
            case programState::CreateClass:
            {
                scene->createclass->drawCreateClass(window, scene->a);
                break;
            }
            case programState::MenuClassCourse:
            {
                scene->menuclasscourse->drawMenuClassCourse(window, scene->a);
                break;
            }
            case programState::CourseManageScoreBoard:
            {
                scene->coursemanagescoreboard->drawCourseManageScoreBoard(window, scene->a);
                break;
            }
            case programState::CourseManageStudent:
            {
                scene->coursemanagestudent->drawCourseManageStudent(window, scene->a);
                break;
            }
            case programState::AddStudentCourse:
            {
                scene->addstudenttocourse->drawAddStudentToCourse(window, scene->a);
                break;
            }
            case programState::ImportScoreboard:
            {
                scene->importscoreboard->drawImportScoreboard(window, scene->a);
                break;
            }
            case programState::CourseAddStudentManually:
            {
                scene->addstudenttocoursemanually->drawAddMunually(window, scene->a);
                break;
            }
            case programState::CourseAddStudentFIle:
            {
                scene->addstudenttocoursefile->drawAddFile(window, scene->a);
                break;
            }
            case programState::ViewCoursesStudent:
            {
				scene->viewcoursesstudent->drawViewCourseStudent(window, scene->a);
				break;
			}
            case programState::AddCourseToSemester:
            {
				scene->addcoursetosemester->drawAddCourseToSemesterScene(window, scene->a);
				break;
			}
            case programState::ViewScoreboardStudent:
            {
                scene->viewscoreboardstudent->drawViewScoreboardScene(window, scene->a);
                break;
            }
            case programState::ViewStudentInClass:
            {
				scene->viewstudentinclass->drawViewStudentInClassScene(window, scene->a);
				break;
			}
            case programState::UpdateCourseInformation:
            {
                scene->updatecourseinformation->drawUpdateInfo(window, scene->a);
                break;
            }
            case programState::AddClassCourse:
            {
				scene->addclasscourse->drawAddClassCourseScene(window, scene->a);
				break;
			}
            case programState::ViewCourseScoreboard:
            {
				scene->viewcoursescoreboard->drawViewScoreboardCourseScene(window, scene->a);
				break;
			}
            case programState::ViewCourseStudent:
            {
				scene->viewstudentincourse->drawViewStudentCourseScene(window, scene->a);
				break;
			}
            case programState::ChooseSchoolYearClass:
			{
                scene->chooseschoolyearclass->drawChooseSchoolYearClassScene(window, scene->a);
                break;
            }
            case programState::ChooseSemesterClass:
			{
				scene->choosesemesterclass->drawChooseSemesterClassScene(window, scene->a);
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


//
//
//}
//int main()
//{
//	Static* a = new Static;
//	a->curSchoolYear = new schoolYear;
//	a->curSemester = new semester;
//	a->curCourse = new Course;
//	a->curSchoolYear->year = "2023-2024";
//	a->curSemester->semesterData = "Semester1";
//	a->curCourse->ID = "CSC00004";
//	a->curCourse->className = "23CLC03";
//	//int Course::addClasstoCourse(Static * a, std::string classname, std::string lecturer, std::string weekday, std::string session)
//	
//	Course * check = new Course;
//	
//	bool hahaha = check->ExportClass(a);
//	std::cout << hahaha;
//	delete check;
//	delete a->curCourse;
//	delete a->curSemester;
//	delete a->curSchoolYear;
//

////int main() {
////	static* a = new static;
////	a->curclass = new class;
////	a->curschoolyear = new schoolyear;
////
////
////	a->curcourse = new course;
////
////
////	a->cursemester = new semester;
////	a->curclass->name = "23clc03";
////	class* b = new class;
////	b->load_classes();
////	class* cur = b->pheadlistclasses;
////	while (cur) {
////		std::cout << cur->name << " ";
////		cur = cur->pnext;
////	}
////	delete a->curclass;
////	delete a->curschoolyear;
////	delete a->curcourse;
////	delete a->cursemester;
////	delete a;
////	delete b;
////	return 0;
////}

//////
//////
//
//
//
//
//
//
//
//
//
//
//
////Static* a = new Static;
////student* curStudent = new student;
////semester* tmpSem = new semester;
////a->curClass = new Class;
////a->curSemester = new semester;
////a->curSchoolYear = new schoolYear;
////
////a->curSchoolYear->year = "2023-2024";
////a->curSemester->semesterData = "Semester1";
////a->curClass->name = "23CLC03";
////
////std::string testCourse;
////std::cout << "Input Course: ";
////getline(std::cin, testCourse);
////bool check = tmpSem->deleteCourse(testCourse, a);
////if (check)
////{
////    std::cout << "Successfull ";
////}
////else {
////    std::cout << "Try again";
////}
////
////
////
////delete a;
////delete curStudent;
////delete tmpSem;
////
////
////return 0;

