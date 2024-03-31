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

	Static *a = new Static;

	WelcomeScene *welcome = new WelcomeScene(a);
	SignInScene *signin = new SignInScene(a);
	SignInAsStudentScene *signinasstudent = new SignInAsStudentScene(a);
	SignInAsStaffScene *signinasstaff = new SignInAsStaffScene(a);
	MenuStudentScene *menustudent = new MenuStudentScene(a);
	MenuStaffScene *menustaff = new MenuStaffScene(a);
	ChangePassStaffScene *changepasssta = new ChangePassStaffScene(a);
	ChangePassStudentScene *changepassstu = new ChangePassStudentScene(a);
	ChooseSchoolYearScene* chooseschoolyear = new ChooseSchoolYearScene(a);
	ViewStudentProfileScene* viewstudentprofile = new ViewStudentProfileScene(a);
	MenuSchoolYearScene* menuschoolyear = new MenuSchoolYearScene(a);
	ChooseClassScene* chooseclass = new ChooseClassScene(a);
	MenuClassScene* menuclass = new MenuClassScene(a);
	~Scene() {
		delete welcome;
		delete signin;
		delete signinasstudent;
		delete signinasstaff;
		delete menustudent;
		delete menustaff;
		delete changepasssta;
		delete changepassstu;
		delete viewstudentprofile;
		delete chooseschoolyear;
		delete menuschoolyear;
		delete chooseclass;
		delete menuclass;
		delete a;

	}
};
//Q: error appears, why?
//A: because of the circular dependency between Scene.h and Scene.cpp