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
		delete a;

	}
};
//Q: error appears, why?
//A: because of the circular dependency between Scene.h and Scene.cpp