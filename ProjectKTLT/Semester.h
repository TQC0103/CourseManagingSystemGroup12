#pragma once
#include<string>
#include "SchoolYear.h"

struct semester {
	semester();
	semester(int semesterNum, std::string StartDate, std::string EndDate);
	int semesterData;
	std::string startDate;
	std::string endDate;
	semester* pHead = nullptr;
	semester* pNext = nullptr;
	
	// SEMESTER
	// UI
	void viewSemester();
	// UX
	void loadSemester(); // demo oke
	void addSemester(int num, std::string start, std::string end);
	// name, id, className, lecturer, credit, maxStudent, weekday, session, year, semester


	// COURSE
	void saveCoursetoFolder(const std::string& name, const std::string& id, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, int session, const std::string& year, const std::string& semester);
	




};

