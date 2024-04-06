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
		delete a;

	}
};