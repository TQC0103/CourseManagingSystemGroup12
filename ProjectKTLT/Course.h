#pragma once

#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include "config.h"

struct Course
{
	// Course *course = new Course();
	// int n = course->loadstudent..(...);
	// 
	
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
	std::string ID, Name, className, Lecturer;

	// Credit, session
	int Credit, maxStudent;
	std::string weekDay;

	// Session should be string because it likes : 7:30 - 9:30


	std::string	Session;



	//construstor
	Course(std::string id, std::string name, std::string classname, std::string lecturer, int credit, int maxstudent, std::string weekday, std::string session);
	Course();

	//ponter to student score 
	studentScore* pHeadScore = nullptr;

	//pointer to student in course
	Course* pNext = nullptr;
	Course* pHeadClasses = nullptr;
	student* pHeadStudent = nullptr;
	student* pTailStudent = nullptr;



	// Function
	void updateCourse(); //done
	int addStudentOptions();
	//done 1/2 
	bool addStudent(Static* a, int choice, int No, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string SocialID);
	bool deleteStudent(std::string ID); 
	void showStudent();
	void showInfo();
	void deleteStudentCourseList();
	void deleteCourseList();

	// Scoreboard functions
	void ExportClass();
	void ImportScoreboard();
	void updateStudentResult();
	void ViewScoreboard();
	void saveIndividualScore(Course* curCourse);
	void LoadScoreList();


	// Supportive function
	void showingStudentList();
	void loadDataOfTheCourse(Static *a); //done
	int loadClassesInCourse(Static* a);
	int loadStudentInTheCourse();
	int getAllStudent();

};



