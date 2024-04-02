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
	// This function is to load list of Course for Staff to see, it load include ID and Name, we should display Name only
	void loadCourse(Static *a); // done 90%
	// This function is to load list of Course for Student to see 
	void specifyCourseForStudent(Static *a);
	
	//These functions are for input data ---> add a course to list of courses of a semester
	
	void normingNonSpace(std::string& data); // for ID, Class, Day and Time
	
	void normingOneSpace(std::string& data); // for Name and Teacher

	void addCourse(Static *a,const std::string& id, const std::string& name, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, std::string& session); // done 90%

	// Delete Operation
	void deleteCourse(const std::string courseID); // this is remove a course in DATABASE

	void deallocateRedundantSemester(Static *a);
	
	void deallocateCurrentSemester();

	~semester();
	




};


