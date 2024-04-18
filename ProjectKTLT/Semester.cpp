#pragma once
#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include<direct.h>
#include "SchoolYear.h"
#include <cstdio>



semester::semester(std::string semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;
	endDate = EndDate;
}
semester::semester() {
	
}

int semester::loadCourse(Static* a)
{
	int n = 0;
	std::ifstream fin;
	fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	if (!fin.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return -1;
	}
	std::string tmpCourseID;
	std::string tmpCourseName;
	Course* cur = pHeadCourse;
	while (getline(fin, tmpCourseID, ';') && fin.eof() == false)
	{ 
		getline(fin, tmpCourseName);
		if (!pHeadCourse)
		{
			pHeadCourse = new Course; // fix this after having constructor Course
			cur = pHeadCourse;
			cur->ID = tmpCourseID;
			cur->Name = tmpCourseName;
			n++;
		}
		else {
			cur->pNext = new Course; // fix this after havving constructor Course
			cur = cur->pNext;
			cur->ID = tmpCourseID;
			cur->Name = tmpCourseName;
			n++;
		}
	}
	fin.close();
	if(cur != nullptr)
		cur->pNext = nullptr;
	return n;
}


int semester::specifyCourseForStudent(Static* a)
{
	int nStudent = 0;
	semester* listAllCourse = new semester;
	int n = listAllCourse->loadCourse(a);
	if (n == 0)
	{
		delete listAllCourse;
		return 0;
	}
	Course *cur = listAllCourse->pHeadCourse;
	Course* curStudent = pHeadCourseForStudent;
	for (int i = 0; i < n; i++)
	{
		std::ifstream fin;
		fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + "Classes.txt");
		if (fin.is_open() == false)
		{
			std::cerr << "Can't open file " << cur->ID << " Classes" << std::endl;
			return -1;
		}
		std::string className;
	
		while (getline(fin, className))
		{
			
			if (className == a->curClass->name)
			{
				if (!pHeadCourseForStudent)
				{
					pHeadCourseForStudent = new Course;
					curStudent = pHeadCourseForStudent;
				}
				else {
					curStudent->pNext = new Course;
					curStudent = curStudent->pNext;
				}
				std::ifstream fin2;
				fin2.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + a->curClass->name + "/information.txt");
				if (fin2.is_open() == false)
				{
					std::cerr << "Can't open file " << cur->ID << " information" << std::endl;
					return -1;
				}
				getline(fin2, curStudent->ID);
				getline(fin2, curStudent->Name);
				getline(fin2, curStudent->className);
				getline(fin2, curStudent->Lecturer);
				fin2 >> curStudent->Credit;
				fin2.ignore();
				fin2 >> curStudent->maxStudent;
				fin2.ignore();
				getline(fin2, curStudent->weekDay);
				getline(fin2, curStudent->Session);

				fin2.close();
				nStudent++;
			}
		}
		if (curStudent)
		{
			curStudent->pNext = nullptr;
		}
		fin.close();
		cur = cur->pNext;

	}

	delete listAllCourse;
	return nStudent;
}




int semester::specifyCourseForStudentUser(Static* a)
{
	int nStudent = 0;
	semester* listAllCourse = new semester;
	int n = listAllCourse->loadCourse(a);
	Course* cur = listAllCourse->pHeadCourse;
	if (n == 0)
	{
		std::cerr << "There is no course in this semester" << std::endl;
		return 0;
	}
	Course* curStudent = pHeadCourseForStudent;
	student* curStudentUser = new student;
	curStudentUser->loadStudentProfile(a->username);
	std::string curClass = curStudentUser->curClass;
	for (int i = 0; i < n; i++)
	{
		std::ifstream fin;
		fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + "Classes.txt");
		if (fin.is_open() == false)
		{
			std::cerr << "Can't open file " << cur->ID << " Classes" << std::endl;
			return -1;
		}
		std::string className;

		while (getline(fin, className))
		{

			if (className == curClass)
			{
				if (!pHeadCourseForStudent)
				{
					pHeadCourseForStudent = new Course;
					curStudent = pHeadCourseForStudent;
				}
				else {
					curStudent->pNext = new Course;
					curStudent = curStudent->pNext;
				}
				std::ifstream fin2;
				fin2.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + curClass + "/information.txt");
				if (fin2.is_open() == false)
				{
					std::cerr << "Can't open file " << cur->ID << " information" << std::endl;
					return -1;
				}
				getline(fin2, curStudent->ID);
				getline(fin2, curStudent->Name);
				getline(fin2, curStudent->className);
				getline(fin2, curStudent->Lecturer);
				fin2 >> curStudent->Credit;
				fin2.ignore();
				fin2 >> curStudent->maxStudent;
				fin2.ignore();
				getline(fin2, curStudent->weekDay);
				getline(fin2, curStudent->Session);

				fin2.close();
				nStudent++;
			}
		}
		if (curStudent)
		{
			curStudent->pNext = nullptr;
		}
		fin.close();
		cur = cur->pNext;

	}


	return nStudent;
}







void semester::normingNonSpace(std::string& data)
{
	int len = (int)data.length();
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		if (data[i] != ' ')
		{
			data[pos++] = data[i];
		}
	}
	len = pos;
	for (int i = 0; i < len; i++)
	{
		if (isalpha(data[i]))
		{
			data[i] = toupper(data[i]);
		}
	}
}
void semester::normingOneSpace(std::string& data)
{
	int len = (int)data.length();
	int pos = 0;
	for (int i = 0; i < len; i++)
	{
		if (data[i] != ' ' || (pos != 0 && i + 1 < len && data[i] == ' ' && data[i + 1] != ' '))
		{
			data[pos++] = data[i];
		}
	}
	len = pos;
	for (int i = 0; i < len; i++)
	{
		if (i == 0 || (i > 0 && data[i - 1] == ' '))
		{
			data[i] = toupper(data[i]);
		}
		else {
			data[i] = tolower(data[i]);
		}
	}
}
bool semester::addCourse(Static* a, std::string& id, std::string& name, int credit, int maxStudent, std::string& weekDay, std::string& session)
{
	normingNonSpace(id);
	normingOneSpace(name);
	normingNonSpace(weekDay);
	normingNonSpace(session);

	std::ifstream fin;
	fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	if (!fin.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	std::string checkID;
	std::string redundant;
	while (getline(fin, checkID, ';'))
	{
		getline(fin, redundant);
		if (checkID == id)
		{
			std::cerr << "This ID is already exist" << std::endl;
			return false;
		}
	}
	std::ofstream fout;
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt", std::ios::app);
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	fout << id << ";" << name << std::endl;
	fout.close();


	// Make Folder and file .txt
	int makeFile = _mkdir(("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id).c_str());
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + "Classes.txt");
	fout.close();
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/CommonInfo.txt");
	fout << id << std::endl;
	fout << name << std::endl;
	fout << credit << std::endl;
	fout << maxStudent << std::endl;
	fout << weekDay << std::endl;
	fout << session << std::endl;
	fout.close();
	return true;
}



bool semester::deleteCourse(std::string& courseName, Static* a)
{
	normingOneSpace(courseName);
	std::ifstream fin("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	// ID is not exist
	if (!fin.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	
	}
	Course* cur = pHeadCourse;
	std::string courseID;
	std::string tmpCourseID;
	std::string tmpCourseName;
	bool Flag = false;
	while (getline(fin, tmpCourseID, ';'))
	{
		getline(fin, tmpCourseName);
		if (tmpCourseName == courseName)
		{
			courseID = tmpCourseID;
			Flag = true;
			continue;
		}
		if (!pHeadCourse)
		{
			pHeadCourse = new Course;
			cur = pHeadCourse;
		}
		else {
			cur->pNext = new Course;
			cur = cur->pNext;
		}
		cur->ID = tmpCourseID;
		cur->Name = tmpCourseName;
	}
	if (cur)
	{
		cur->pNext = nullptr;
	}
	fin.close();
	// Course is not exist !
	if (Flag == false)
	{
		std::cerr << "This ID is not exist" << std::endl;
		return false;
	}
	std::ofstream fout;
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		fout.close();
		return false;
	}
	cur = pHeadCourse;
	while (cur)
	{
		fout << cur->ID << ";" << cur->Name << std::endl;
		cur = cur->pNext;
	}
	fout.close();
	// Move the Course File to the Deleted Folder
	int makeFile = _mkdir("../Rubbish");
	std::string source = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + courseID;
	std::string destination = "../Rubbish/" + courseID;
	int moveFile = rename(source.c_str(), destination.c_str());
	if (moveFile != 0)
	{
		std::cerr << "Can't move file" << std::endl;
		return false;
	}



	
	return true;

}












bool semester::getGPASemester(Static* a)
{
	

	semester* GPAstudent = GPASemester;
	std::ifstream fin;
	fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	if (!fin.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	std::string count;
	int numCourse = 0;
	while (getline(fin, count))
	{
		numCourse++;
	}
	fin.close();

	Course ** listScore = new Course *[numCourse];

	Course* listStudent = new Course;
	int nStudents = listStudent->loadStudentInTheCourse(a);

	fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");

	std::string courseID;
	std::string courseName;
	
	int i = 0;
	while (getline(fin, courseID, ';'))
	{
		getline(fin, courseName);
		
		a->curCourse->ID = courseID;

		//listScore[i] = new Course;
		
		// ScoreBoards of Courses are not full
		/*if (listScore[i]->getGPAStudents(a) == false)
		{
			break;
		}*/
		i++;
	}
	fin.close();
	if (i < numCourse)
	{
		std::cerr << "ScoreBoards of Courses are not full" << std::endl;
		for (int j = 0; j < i; j++)
		{
			delete listScore[j];
		}
		delete[] listScore;
		return false;
	}

	i = 0;

	for (i = 0; i < nStudents; i++)
	{
		double GPA = 0;
		for (int j = 0; j < numCourse; j++)
		{
			GPA += listScore[j]->pHeadScore->totalMark;
			listScore[j]->pHeadScore = listScore[j]->pHeadScore->pNext;
		}
		if (GPASemester == nullptr)
		{
			GPASemester = new semester;
			GPAstudent = GPASemester;
		}
		else {
			GPAstudent->pNext = new semester;
			GPAstudent = GPAstudent->pNext;
		}
		GPAstudent->GPA = GPA / numCourse;

	}
	if (GPAstudent)
	{
		GPAstudent->pNext = nullptr;
	}
	for (int j = 0; j < numCourse; j++)
	{
		delete listScore[j];
	}
	delete[] listScore;


	return true;
	
}

semester::~semester()
{
	Course* cur = pHeadCourse;
	while (cur)
	{
		Course* tmp = cur;
		cur = cur->pNext;
		delete tmp;
	}
	cur = pHeadCourseForStudent;
	while (cur)
	{
		Course* tmp = cur;
		cur = cur->pNext;
		delete tmp;
	}
	while (GPASemester)
	{
		semester* tmp = GPASemester;
		GPASemester++;
		delete tmp;
	}
	//delete this;
}