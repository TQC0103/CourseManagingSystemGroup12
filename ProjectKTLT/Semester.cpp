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

void semester::loadCourse(Static* a)
{
	if (pHeadCourse)
	{
		return;
	}
	std::ifstream fin;
	fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt");
	if (!fin.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}
	std::string tmpCourseID;
	std::string tmpCourseName;
	Course* cur = a->curSemester->pHeadCourse;
	while (getline(fin, tmpCourseID, ';'))
	{
		getline(fin, tmpCourseName);
		if (!pHeadCourse)
		{
			//pHeadCourse = new Course; // fix this after having constructor Course
			cur = pHeadCourse;
			cur->ID = tmpCourseID;
			cur->Name = tmpCourseName;
		}
		else {
			//cur->pNext = new Course; // fix this after havving constructor Course
			cur = cur->pNext;
			cur->ID = tmpCourseID;
			cur->Name = tmpCourseName;
		}

	}
	fin.close();
	cur->pNext = nullptr;


}











void semester::addCourse(Static* a, const std::string& id, const std::string& name, const std::string& className, const std::string& lecturer, int credit, int maxStudent, const std::string& weekDay, std::string& session)
{
	std::ofstream fout;
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + "courses.txt", std::ios::app);
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}
	fout << id << ";" << name << std::endl;
	fout.close();
	
	// Add course to linked list
	Course* cur = a->curSemester->pHeadCourse;
	if (!pHeadCourse)
	{
		//pHeadCourse = new Course(id, name, className, lecturer, credit, maxStudent, weekDay, session);
		pHeadCourse->pNext = nullptr;
	}
	else {
		while (cur->pNext)
		{
			cur = cur->pNext;
		}
		//cur->pNext = new Course(id, name, className, lecturer, credit, maxStudent, weekDay, session);
		cur = cur->pNext;
		cur->pNext = nullptr;
	}
	// Make Folder and file .txt
	int makeFile = _mkdir(("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id).c_str());
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + "ClassAndTeacher.txt",std::ios::app);
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}
	fout << className << ";" << lecturer << std::endl;
	fout.close();
	int makeFile2 = _mkdir(("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + className).c_str());
	fout.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + id + "/" + className + "/" + "information.txt");
	if (!fout.is_open())
	{
		std::cerr << "Can't open file" << std::endl;
		return;
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
}





void semester::deallocateRedundantSemester(Static* a)
{
	semester* cur = a->curSchoolYear->pHeadSemester;
	while (cur)
	{
		if (cur != a->curSemester)
		{
			semester* tmp = cur;
			cur = cur->pNext;
			delete tmp;
		}
		else {
			cur = cur->pNext;
		}
	}
	a->curSemester->pNext = nullptr;
}