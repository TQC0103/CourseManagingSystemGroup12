#pragma once

#include "Welcome.h"
#include "SignIn.h"
#include "SignInAsStudent.h"
#include "SignInAsStaff.h"
#include "MenuStudent.h"
#include "MenuStaff.h"
#include "ChangePassStaff.h"
#include "ChangePassStudent.h"

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
};
