#pragma once
#include<string>

struct semester {
	semester();
	semester(int semesterNum, std::string StartDate, std::string EndDate);
	std::string semesterData;
	std::string startDate;
	std::string endDate;
	semester* pNext = nullptr;
	
	// SEMESTER
	// UI
	void viewSemester();
	// UX
	// 
	


	// COURSE
	// // name, id, className, lecturer, credit, maxStudent, weekday, session, year, semester
	//void saveCoursetoFolder(const std::string& name, const std::string& id, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, int session, const std::string& year, const std::string& semester);
	




};

