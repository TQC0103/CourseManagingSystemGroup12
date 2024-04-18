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
	double GPA = 0;
	semester* pNext = nullptr;

	// SEMESTER



	// COURSE
	// // name, id, className, lecturer, credit, maxStudent, weekday, session, year, semester


	Course* pHeadCourse = nullptr;

	Course* pHeadCourseForStudent = nullptr;

	semester * GPASemester = nullptr;
	// This function is to load list of Course for Staff to see, it load include ID and Name, we should display Name only
	int loadCourse(Static* a); // done 90%
	// This function is to load list of Course for Student to see 
	int specifyCourseForStudent(Static* a); // done 100%

	int specifyCourseForStudentUser(Static* a);
	//These functions are for input data ---> add a course to list of courses of a semester

	void normingNonSpace(std::string& data); // for ID, Class, Day and Time // done 100%

	void normingOneSpace(std::string& data); // for Name and Teacher // done 100%

	bool addCourse(Static* a, std::string& id, std::string& name, std::string& className, std::string& lecturer, int credit, int maxStudent, std::string& weekDay, std::string& session); // done 100%

	// Delete Operation
	// Name is easier to remember than ID
	
	bool deleteCourse(std::string& courseName, Static* a); // , this is remove a course in DATABASE // done 100%
	bool getGPASemester(Static* a);

	~semester();// Done 100%
	


};


