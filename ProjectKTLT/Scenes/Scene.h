#pragma once

#include "Welcome.h"
#include "SignIn.h"
#include "SignInAsStudent.h"
#include "MenuStaff.h"
#include "SignInAsStaff.h"
#include "MenuStudent.h"
#include "ChangePassStaff.h"
#include "ChangePassStudent.h"
#include "ViewStudentProfile.h"
#include "ChooseSchoolYear.h"
#include "MenuSchoolYear.h"
#include "ChooseClass.h"
#include "MenuClass.h"
#include "ChooseSemester.h"
#include "MenuSemester.h"
#include "ChooseSchoolYearStudent.h"
#include "ChooseSemesterStudent.h"
#include "MenuSemesterStudent.h"
#include "AddStudentClass.h"
#include "CreateSemester.h"
#include "AddStudentClassManually.h"
#include "ChooseCourses.h"
#include "MenuCourse.h"
#include "ChooseClassCourse.h"
#include "AddStudentClassFile.h"
#include "CreateClass.h"
#include "MenuClassCourse.h"
#include "CourseManageScoreBoard.h"
#include "CourseManageStudent.h"
#include "AddStudentToCourse.h"
#include "ImportScoreBoard.h"
#include "AddStudentCourseManually.h"
#include "AddStudentCourseFile.h"
#include "ViewCoursesStudent.h"
#include "AddCourseToSemester.h"
#include "ViewScoreboardStudent.h"
#include "ViewStudentInClass.h"
#include "UpdateCourseInformation.h"
#include "AddClassCourse.h"

struct Scene
{
	Static* a = new Static();
	WelcomeScene* welcome = nullptr;
	SignInScene *signin = nullptr;
	SignInAsStudentScene *signinasstudent = nullptr;
	SignInAsStaffScene *signinasstaff = nullptr;
	MenuStudentScene *menustudent = nullptr;
	MenuStaffScene *menustaff = nullptr;
	ChangePassStaffScene *changepasssta = nullptr;
	ChangePassStudentScene *changepassstu = nullptr;
	ChooseSchoolYearScene* chooseschoolyear = nullptr;
	ViewStudentProfileScene* viewstudentprofile = nullptr;
	MenuSchoolYearScene* menuschoolyear = nullptr;
	ChooseClassScene* chooseclass = nullptr;
	MenuClassScene* menuclass = nullptr;
	ChooseSemesterScene* choosesemester = nullptr;
	MenuSemesterScene* menusemester = nullptr;
	ChooseSchoolYearStudentScene* chooseschoolyearstudent = nullptr;
	ChooseSemesterStudentScene* choosesemesterstudent = nullptr;
	MenuSemesterStudentScene* menusemesterstudent = nullptr;
	AddStudentClassScene* addstudentclass = nullptr;
	CreateSemesterScene* createsemester = nullptr;
	AddStudentClassManuallyScene* addstudentclassmanually = nullptr;
	ChooseCoursesScene* choosecoursescene = nullptr;
	MenuCourseScene* menucourse = nullptr;
	ChooseClassCourseScene* chooseclasscourse = nullptr;	
	AddStudentClassFileScene* addstudentclassfile = nullptr;
	CreateClassScene* createclass = nullptr;
	MenuClassCourseScene* menuclasscourse = nullptr;
	CourseManageScoreBoardScene* coursemanagescoreboard = nullptr;
	CourseManageStudentScene* coursemanagestudent = nullptr;
	AddStudentToCourseScene* addstudenttocourse = nullptr;
	ImportScoreboardScene* importscoreboard = nullptr;
	CourseAddStudentManuallyScene* addstudenttocoursemanually = nullptr;
	AddStudentCourseFileScene* addstudenttocoursefile = nullptr;
	ViewCoursesStudentScene* viewcoursesstudent = nullptr;
	AddCourseToSemesterScene* addcoursetosemester = nullptr;
	ViewScoreboardScene* viewscoreboardstudent = nullptr;
	ViewStudentInClassScene* viewstudentinclass = nullptr;
	UpdateCourseInformationScene* updatecourseinformation = nullptr;
	AddClassCourseScene* addclasscourse = nullptr;

	Scene() {
		a->currentState = programState::Welcome;
		welcome = new WelcomeScene(a);
	}
	~Scene() {
		if(welcome != nullptr)
			delete welcome;
		if(signin != nullptr) 
			delete signin;
		if(signinasstudent != nullptr)
			delete signinasstudent;
		if(signinasstaff != nullptr)
			delete signinasstaff;
		if(menustudent != nullptr)
			delete menustudent;
		if(menustaff != nullptr)
			delete menustaff;
		if(changepasssta != nullptr)
			delete changepasssta;
		if(changepassstu != nullptr)
			delete changepassstu;
		if(chooseschoolyear != nullptr)
			delete chooseschoolyear;
		if(viewstudentprofile != nullptr)
			delete viewstudentprofile;
		if(menuschoolyear != nullptr)
			delete menuschoolyear;
		if(chooseclass != nullptr)
			delete chooseclass;
		if(menuclass != nullptr)
			delete menuclass;
		if (choosesemester != nullptr)
			delete choosesemester;
		if (menusemester != nullptr)
			delete menusemester;
		if (chooseschoolyearstudent != nullptr)
			delete chooseschoolyearstudent;
		if (choosesemesterstudent != nullptr)
			delete choosesemesterstudent;
		if (menusemesterstudent != nullptr)
			delete menusemesterstudent;
		if (addstudentclass != nullptr)
			delete addstudentclass;
		if (createsemester != nullptr)
			delete createsemester;
		if (addstudentclassmanually != nullptr)
			delete addstudentclassmanually;
		if (choosecoursescene != nullptr)
			delete choosecoursescene;
		if (menucourse != nullptr)
			delete menucourse;
		if (chooseclasscourse != nullptr)
			delete chooseclasscourse;
		if (addstudentclassfile != nullptr)
			delete addstudentclassfile;
		if (createclass != nullptr)
			delete createclass;
		if (menuclasscourse != nullptr)
			delete menuclasscourse;
		if (coursemanagescoreboard != nullptr)
			delete coursemanagescoreboard;
		if (coursemanagestudent != nullptr)
			delete coursemanagestudent;
		if (addstudenttocourse != nullptr)
			delete addstudenttocourse;
		if (importscoreboard != nullptr)
			delete importscoreboard;
		if (addstudenttocoursemanually != nullptr)
			delete addstudenttocoursemanually;
		if (addstudenttocoursefile != nullptr)
			delete addstudenttocoursefile;
		if (viewcoursesstudent != nullptr)
			delete viewcoursesstudent;
		if (addcoursetosemester != nullptr)
			delete addcoursetosemester;
		if (viewscoreboardstudent != nullptr)
			delete viewscoreboardstudent;
		if (viewstudentinclass != nullptr)
			delete viewstudentinclass;
		if (updatecourseinformation != nullptr)
			delete updatecourseinformation;
		if (addclasscourse != nullptr)
			delete addclasscourse;
		delete a;

	}
};
