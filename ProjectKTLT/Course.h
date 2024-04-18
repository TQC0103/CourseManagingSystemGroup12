#pragma once

#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "config.h"

struct Course
{
	// Course *course = new Course();
	// int n = course->loadstudent..(...);
	// 
	
	//Student score in the course
	struct studentScore
	{
		int No;
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
	Course()
	{
		ID = "";
		Name = "";
		className = "";
		Lecturer = "";
		Credit = 0;
		maxStudent = 0;
		weekDay = "";
		Session = "";
	}

	//ponter to student score 
	studentScore* pHeadScore = nullptr;

	//pointer to student in course
	Course* pNext = nullptr;
	Course* pHeadClasses = nullptr;

	student* pHeadStudent = nullptr;
	student* pTailStudent = nullptr;



	// Function
	int updateCourse(Static* a, std::string id, std::string name, std::string classname, std::string lecturer, int credit, int maxstudent, std::string weekday, std::string session); //done
	int addStudentOptions();
	//done
	bool addStudentManually(Static* a, int No, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string DOB, std::string SocialID);
	bool addStudentbyFile(Static* a, std::string path); //done
	bool deleteStudent(Static* a, std::string ID); //done 
	

	// Scoreboard functions
	bool ExportClass(Static* a); //done
	bool ImportScoreboard(std::string path);
	void updateStudentResult();
	void ViewScoreboard();
	void saveIndividualScore(Course* curCourse);
	void LoadScoreList();


	// Supportive function
	void showingStudentList();
	void loadDataOfTheCourse(Static *a); //done
	int loadClassesInCourse(Static* a); //done
	int loadStudentInTheCourse(Static* a); //done
	void sortStudentList(student* a);// done
	//void deleteStudentAfterSort(student* a); //done
	void normingNumberInStudentList(); //done
	bool exportStudentListToFile(Static* a);//done
	int getAllStudent();

};



