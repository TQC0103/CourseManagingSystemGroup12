#pragma once

#include "Welcome.h"
#include "SignIn.h"
#include "SignInAsStudent.h"
#include "SignInAsStaff.h"

struct Scene
{
	WelcomeScene welcome;
	SignInScene signin;
	SignInAsStudentScene signinasstudent;
	SignInAsStaffScene signinasstaff;
};
