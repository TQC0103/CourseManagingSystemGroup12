#pragma once
#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include<direct.h>
#include "SchoolYear.h"



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
	while (getline(fin, tmpCourseID, ';'))
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
	cur->pNext = nullptr;
	return n;
}


int semester::specifyCourseForStudent(Static* a)
{
	int nStudent = 0;
	semester* listAllCourse = new semester;
	int n = listAllCourse->loadCourse(a);
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
bool semester::addCourse(Static* a, std::string& id, std::string& name, std::string& className, std::string& lecturer, int credit, int maxStudent, std::string& weekDay, std::string& session)
{
	normingNonSpace(id);
	normingOneSpace(name);
	normingNonSpace(className);
	normingOneSpace(lecturer);
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
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + "Classes.txt", std::ios::app);
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	fout << className << std::endl;
	fout.close();
	int makeFile2 = _mkdir(("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + className).c_str());
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + className + "/" + "information.txt");
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return false;
	}
	fout << id << std::endl;
	fout << name << std::endl;
	fout << className << std::endl;
	fout << lecturer << std::endl;
	fout << credit << std::endl;
	fout << maxStudent << std::endl;
	fout << weekDay << std::endl;
	fout << session << std::endl;
	fout.close();
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
	//delete this;
}