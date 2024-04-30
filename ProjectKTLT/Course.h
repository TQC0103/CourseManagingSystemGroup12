#pragma once

#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include "config.h"
#include <direct.h>

struct Course
{	
	//Student score in the course
#include <string>

	struct studentScore {
		int No;
		std::string studentID;
		std::string firstName;
		std::string lastName;
		double totalMark, finalMark, midtermMark, otherMark;
		studentScore* pNext = nullptr;

		// Constructor with parameters
		studentScore(int number, const std::string& id, const std::string& first, const std::string& last, double total, double final, double midterm, double other)
			: No(number), studentID(id), firstName(first), lastName(last),
			 finalMark(final), midtermMark(midterm), otherMark(other), totalMark(total)
		{
		}

		// Default constructor
		studentScore() : No(0), totalMark(0), finalMark(0), midtermMark(0), otherMark(0), pNext(nullptr)
		{
		}
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
	//destructors
	~Course();

	//ponter to student score 
	studentScore* pHeadScore = nullptr;
	studentScore* pTailScore = nullptr;

	//pointer to student in course
	Course* pNext = nullptr;
	Course* pHeadClasses = nullptr;

	student* pHeadStudent = nullptr;
	student* pTailStudent = nullptr;



	// Function

	//Update the information of the course (done)
	int updateCourse(Static* a, std::string lecturer, std::string weekday, std::string session); 
	int addStudentOptions(); //done

	//Add a student to a list in a course manually (done)
	bool addStudentManually(Static* a, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string DOB, std::string SocialID);
	
	//Add the student list to the course by a file (done)
	int addStudentbyFile(Static* a, std::string path);

	// Check the ID of the student in the class to delete (done)
	bool deleteStudent(Static* a, std::string ID); 
	
	// Export a student list to a "scoreboard.csv" that don't have mark (done)
	bool ExportClass(Static* a); 

	//Import a scoreboard file and save it in the database (done)
	int ImportScoreboard(Static* a, std::string path);

	//Add a class to a course (done)
	int addClasstoCourse(Static* a, std::string classname, std::string lecturer, std::string weekday, std::string session);

	void updateStudentResult();

	void saveIndividualScore(Course* curCourse);

	// Supportive function
	void loadDataOfTheCourse(Static *a); //done
	int loadClassesInCourse(Static* a); //done
	int loadStudentInTheCourse(Static* a); //done
	int loadStudentScoreInTheCourse(Static* a); //done
	void sortStudentList(student* a);// done
	//void deleteStudentAfterSort(student* a); //done
	void normingNumberInStudentList(); //done
	bool exportStudentListToFile(Static* a);//done

	std::string** viewAllStudentsInACourse(Static* a, int &n); // done
	std::string** viewAllStudentsScoreInACourse(Static* a, int &n);
	int getAllStudent();

};



