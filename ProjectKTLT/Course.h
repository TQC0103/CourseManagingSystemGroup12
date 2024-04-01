#pragma once

#include "Student.h"
#include "Class.h"
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
	std::string ID, Name, className, Lecturer;

	// Credit, session
	int Credit, maxStudent;
	std::string weekDay;
	// Session should be string because it likes : 7:30 - 9:30
	int	Session;


	//construstor
	Course(std::string id, std::string name, std::string classname, std::string lecturer, int credit, int maxstudent, std::string weekday, int session);
	Course();
	//ponter to student score 
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

	// Scoreboard functions
	void ExportClass();
	void ImportScoreboard();
	void updateStudentResult();
	void ViewScoreboard();
	void saveIndividualScore(Course* curCourse);
	void LoadScoreList();


	// Supportive function
	void showingStudentList();
	void showStudent(student*& pHead, int range, int& Pcur);
	int getAllStudent();
	void showPStudent(student*& pHead, int range, int& Pcur);

};



