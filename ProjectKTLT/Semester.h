#pragma once
#include<string>
#include "Course.h"
#include "config.h"






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

	void loadCourse(Static *a);

	void specifyCourseForStudent(Static *a);

	void normingCourseData(std::string& data);

	void addCourse(const std::string& name, const std::string& id, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, int session);

	// Delete Operation
	void deleteCourse(const std::string courseID); // this is remove a course in DATABASE

	void deallocateRedundantSemester(Static *a);
	
	void deallocateCurrentSemester();

	~semester();
	




};


