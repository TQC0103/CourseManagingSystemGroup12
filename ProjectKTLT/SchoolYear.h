#pragma once
#include<string>
#include "Semester.h"


struct schoolYear {
	schoolYear(std::string year);
	std::string yearData;
	schoolYear* pNext = nullptr;

	// UI
	void viewSchoolYear();
	void addSchoolYear();
	void saveSchoolYear();
	void loadSchoolYear();
};
