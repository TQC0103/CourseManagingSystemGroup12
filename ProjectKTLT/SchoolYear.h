#pragma once
#include<string>
#include "Semester.h"

extern schoolYear* curSchoolYear;
extern semester* curSemester;

struct schoolYear {
	schoolYear(std::string yearData);
	std::string year;
	schoolYear* pNext = nullptr;

	// UI
	void viewSchoolYear();
	void addSchoolYear();
	void saveSchoolYear();
	void loadSchoolYear();
	// Semester
	semester *pHead = nullptr;
	
};
