#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include "Date.h"
#include<direct.h>


extern semester* curSemester;

semester::semester(std::string semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;	
	endDate = EndDate;
}
semester::semester() {
}

void semester::loadCourse()
{
	if (pHeadCourse)
	{
		return;
	}
	std::ifstream fin;
	fin.open("../Database/SchoolYear" + curSchoolYear->year + "/" + curSemester->semesterData + "/courses.txt");
	if (!fin.is_open())	
	{
		std::cerr << "Can't open file" << std::endl;
		return;
	}
	std::string tmpCourseName;
	pHeadCourse = new Course;
	Course* cur = pHeadCourse;
	while (getline(fin, tmpCourseName))
	{
		Course* newCourse = new Course;
		
	}


}





