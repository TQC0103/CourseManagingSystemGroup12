#pragma once
#include<string>
#include "Semester.h"




struct schoolYear {
	schoolYear();
	schoolYear(std::string yearData);
	std::string year;
	schoolYear* pHead = nullptr;
	schoolYear* pNext = nullptr;

	// User Experience	
	void loadSchoolYear();// done
	bool addSchoolYear(std::string yearData);// done
	bool checkInputYear(std::string data);
	bool checkInputDate(std::string data);
	
	// User Interface
	void viewSchoolYear(); // UI (later)
	
	
	
	// About Semesters in a school Year
	semester* pHeadSemester = nullptr;
	void loadSemester(); // done
	bool addSemester(std::string data, std::string start, std::string end);// done

	// Deallocate
	void deallocateSchoolYear();
	void deallocateSemester();
};
//extern schoolYear *curSchoolYear;


