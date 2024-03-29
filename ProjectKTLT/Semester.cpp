#pragma once
#include "Semester.h"
#include "SchoolYear.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include<direct.h>


semester::semester(std::string semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;	
	endDate = EndDate;
}
semester::semester() {
}

void semester::loadCourse(Static *a)
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
	std::string tmpCourseName;
	//pHeadCourse = new Course;
	//Course* cur = pHeadCourse;
	while (getline(fin, tmpCourseName))
	{
		//Course* newCourse = new Course;
		
	}


}





