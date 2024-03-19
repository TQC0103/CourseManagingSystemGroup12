#pragma once

#include "Student.h"
#include <string>
#include <fstream>

struct Course
{

	//Student score in the course
	struct studentScore
	{
		std::string studentID;
		std::string firstName;
		std::string lastName;
		double totalMark, finalMark, midtermMark, otherMark;
		studentScore* pNext;
	};

	// Student basic infomation
	std::string studentID, name, className, lecturer, weekDay;

	// Credit, session
	int credit, maxStudent, session;

	//construstor
	Course(std::string studentID, std::string name, std::string className, std::string lecturer, int credit, int maxStudent, std::string weekDay, int session);
	
	//ponter to score total
	studentScore* pHeadScore = nullptr; 

	//pointer to student in course
	Course* pNext = nullptr;
	student* pHeadStudent = nullptr;
	student* pTailStudent = nullptr;



	// Function
	void updateCourse();
	void addStudentMenu();
	void addStudent(int choice);
	void deleteStudent();
	void showStudent();
	void showInfo();
	void deleteStudentCourseList();
	void deleteCourseList();

};

#pragma once

#include "Student.h"
#include <string>
#include <fstream>

struct Course
{

	//Student score in the course
	struct studentScore
	{
		std::string studentID;
		std::string firstName;
		std::string lastName;
		double totalMark, finalMark, midtermMark, otherMark;
		studentScore* pNext;
	};

	// Student basic infomation
	std::string studentID, name, className, lecturer, weekDay;

	// Credit, session
	int credit, maxStudent, session;

	//construstor
	Course(std::string studentID, std::string name, std::string className, std::string lecturer, int credit, int maxStudent, std::string weekDay, int session);
	
	//ponter to score total
	studentScore* pHeadScore = nullptr; 

	//pointer to student in course
	Course* pNext = nullptr;
	student* pHeadStudent = nullptr;
	student* pTailStudent = nullptr;



	// Function
	void updateCourse();
	void addStudentMenu();
	void addStudent(int choice);
	void deleteStudent();
	void showStudent();
	void showInfo();
	void deleteStudentCourseList();
	void deleteCourseList();

};

