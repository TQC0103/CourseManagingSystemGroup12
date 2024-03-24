#pragma once
#include<string>
#include "Course.h"







struct semester {
	semester();
	semester(std::string semesterNum, std::string StartDate, std::string EndDate);
	std::string semesterData;
	std::string startDate;
	std::string endDate;
	semester* pNext = nullptr;
	
	// SEMESTER
	


	// COURSE
	// // name, id, className, lecturer, credit, maxStudent, weekday, session, year, semester
	
	
	Course* pHeadCourse = nullptr;

	Course* pHeadCourseForStudent = nullptr;

	void loadCourse();

	void specifyCourseForStudent(std::string studentID);

	void normingCourseData(std::string& data);

	bool findCurrentCourse(const std::string& data);

	void addCourse(const std::string& name, const std::string& id, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, int session);

	void deleteCourse(const std::string courseID);
	




};


