#pragma once
#include "SchoolYear.h"
#include <fstream>
#include <iostream>
#include <direct.h>
#include "Date.h"
#include <cctype>
#include<iomanip>





schoolYear::schoolYear() {
	year = "";
	pHead = nullptr;
	pNext = nullptr;
}

schoolYear::schoolYear(std::string yearData) {
	year = yearData;
	pHead = nullptr;
	pNext = nullptr;
}


void schoolYear::loadSchoolYear()
{

	std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
	if (!fin.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		return;
	}
	std::string data;
	schoolYear* cur = pHead;
	while (getline(fin, data)) {
		if (!pHead) {
			pHead = new schoolYear(data);
			cur = pHead;
		}
		else {
			cur->pNext = new schoolYear(data);
			cur = cur->pNext;
		}
	}
	if (cur == nullptr)
		return;
	cur->pNext = nullptr;
	fin.close();
}

//bool schoolYear::findCurrentSchoolYear(std::string data)
//{
//	checkInputYear(data);
//	if (!checkInputYear(data))
//	{
//		return false;
//	}
//
//	schoolYear* cur = pHead;
//	while (cur)
//	{
//		if (cur->year == data)
//		{
//			a->curSchoolYear = cur;
//			return true;
//			
//		}
//		cur = cur->pNext;
//	}
//	return false;
//}

bool schoolYear::checkInputYear(std::string &data) {
	// Norming the input data
	int pos = 0;
	int n = (int)data.length();
	for (int i = 0; i < n; i++)
	{
		if (data[i] != ' ')
		{
			data[pos++] = data[i];
		}
	}
	n = pos;
	pos = 0;
    std::string testYear1 = "";
	std::string testYear2 = "";
    while (pos < n && isdigit(data[pos]))
	{
		testYear1 += data[pos++];
	}
    pos++;	
	while (pos < n)
	{
		testYear2 += data[pos++];
	}
    if (testYear1.length() != 4 || testYear2.length() != 4) {
		return false;
	}
    if (testYear1[0] != '2' || testYear1[1] != '0' || testYear2[0] != '2' || testYear2[1] != '0') {
		return false;
	}
	data = testYear1 + "-" + testYear2;

	if (std::stoi(data.substr(5, 4)) - std::stoi(data.substr(0, 4)) != 1) {
		return false;
	}
	return true;
}

bool schoolYear::checkInputDate(std::string &data, Static* a)
{
	// Norming the input data
	int pos = 0;
	int n = (int)data.length();
	std::string testDay = "";
	std::string monthDay = "";
	for (int i = 0; i < n; i++)
	{
		if (data[i] != ' ')
		{
			data[pos++] = data[i];
		}
	}
	n = pos;
	pos = 0;
	while (pos < n && isdigit(data[pos]))
	{
		testDay += data[pos++];
	}
	pos++;
	while (pos < n)
	{
		monthDay += data[pos++];
	
	}
	if (testDay.length() == 1)
	{
		testDay = "0" + testDay;
	}
	if (monthDay.length() == 1)
	{
		monthDay = "0" + monthDay;
	}
	data = testDay + "/" + monthDay;
	int len = (int)data.length();
	if (len != 5)
	{
		return false;
	}
	std::string stringDate = data.substr(0, 2);
	std::string stringMonth = data.substr(3, 2);
	int day = std::stoi(stringDate);
	int month = std::stoi(stringMonth);

	if (month != 2)
	{
		if (month >= 8)
		{
			if (month % 2 == 0)
			{
				return day >= 1 && day <= 31;
			}
			else {
				return day >= 1 && day <= 30;
			}
		}
		else {
			if (month % 2 == 0)
			{
				return day >= 1 && day <= 30;
			}
			else {
				return day >= 1 && day <= 31;
			}
		}
	}
	else {
		std::string tmpYear = a->curSchoolYear->year.substr(5, 4);
		int year = std::stoi(tmpYear);
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			return day >= 1 && day <= 29;
		}
		else {
			return day >= 1 && day <= 28;
		}
	}
}

bool schoolYear::addSchoolYear() {
	
	schoolYear* cur = pHead;

	std::string curYear = cur->year;
	std::string nextYear1 = std::to_string(std::stoi(curYear.substr(0, 4)) + 1);
	std::string nextYear2 = std::to_string(std::stoi(curYear.substr(5, 4)) + 1);
	std::string nextYear = nextYear1 + "-" + nextYear2;
	schoolYear* tmp = new schoolYear(nextYear);
	tmp->pNext = pHead;
	pHead = tmp;
	cur = pHead;


	std::ofstream fout("../Database/SchoolYear/AllSchoolYear.txt");
	while (cur)
	{
		fout << cur->year << std::endl;
		cur = cur->pNext;
	}
	fout.close();
	int result = _mkdir(("../Database/SchoolYear/" + nextYear).c_str());
	if (result != 0) {
		std::cout << "Error: Unable to create directory" << std::endl;
		return false;
	}
	fout.open("../Database/SchoolYear/" + nextYear + "/AllSemester.txt");
	fout.close();
	return true;

	//checkInputYear(yearData);
	//if (!checkInputYear(yearData)) {
	//	return false;
	//}
	//std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
	//std::string check;
	//while (getline(fin, check)) {
	//	if (check == yearData) {
	//		return false;
	//	}
	//}
	////fin.ignore();
	//fin.close();
	//std::ofstream fout("../Database/SchoolYear/AllSchoolYear.txt", std::ios::app);
	//
	//fout << yearData << std::endl;
	//fout.close();
	//_mkdir(("../Database/SchoolYear/" + (std::string)yearData).c_str());
	//schoolYear* cur = pHead;
	//while (cur->pNext) {
	//	cur = cur->pNext;
	//}
	//cur->pNext = new schoolYear(yearData);
	//cur = cur->pNext;
	//cur->pNext = nullptr;
	//curSchoolYear = cur;
	//return true;
}

//void schoolYear::movetoNextSchoolYear()
//{
//	curSchoolYear = curSchoolYear->pNext;
//}

void schoolYear::loadSemester(std::string& year) {

	std::ifstream fin("../Database/SchoolYear/" + year + "/AllSemester.txt");
	if (!fin.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		return;
	}
	std::string data;
	std::string startDate;
	std::string endDate;

	semester* cur = pHeadSemester;

	while (getline(fin, data)) {
		getline(fin, startDate, ';');
		getline(fin, endDate);
		if (!pHeadSemester) {
			pHeadSemester = new semester(data, startDate, endDate);
			cur = pHeadSemester;
		}
		else {
			cur->pNext = new semester(data, startDate, endDate);
			cur = cur->pNext;
		}
	}
	if (cur == nullptr)
		return;
	cur->pNext = nullptr;


	fin.close();
}

//bool schoolYear::findCurrentSemester(std::string data) {
//	semester* cur = curSchoolYear->pHeadSemester;
//	while (cur) {
//		if (cur->semesterData == data)
//		{
//			curSemester = cur;
//			return true;
//		}
//		cur = cur->pNext;
//	}
//	return false;
//}

int schoolYear::addSemester(std::string& data, std::string start, std::string end, Static* a)
{
	if (!checkInputDate(start, a) || !checkInputDate(end, a)) {
		return 0;
	}
	std::ifstream fin("../Database/SchoolYear/" + a->curSchoolYear->year + "/AllSemester.txt");

	// if the semester in a new school year, create a new file
	if (!fin.is_open()) {
		std::cerr << "Can't open file" << std::endl;
		return 0;
	}
	std::string checkSemester = "";
	std::string date = "";
	while (getline(fin, checkSemester)) {
		
		getline(fin, date);
		if (checkSemester.length() != 0)
		{
			std::string checkNumber = checkSemester.substr(8, 1);
			int number = std::stoi(checkNumber);
			number++;
			if (number > 3)
			{
				fin.close();
				return 2;

			}
			data = "Semester" + std::to_string(number);
		}
		
	}
	fin.close();
	std::ofstream fout;
	if (data.length() == 0)
	{
		data = "Semester1";
		fout.open("../Database/SchoolYear/" + (std::string)a->curSchoolYear->year + "/AllSemester.txt");
	}
	else {
		fout.open("../Database/SchoolYear/" + (std::string)a->curSchoolYear->year + "/AllSemester.txt", std::ios::app);
	}
	
	
	fout << data << std::endl;
	fout << start << ";" << end << std::endl;
	fout.close();
	int makeFile = _mkdir(("../Database/SchoolYear/" + (std::string)a->curSchoolYear->year + "/" + (std::string)data).c_str());
	if (makeFile != 0) {
		std::cout << "Error: Unable to create directory" << std::endl;
		return 0;
	}
	fout.open("../Database/SchoolYear/" + (std::string)a->curSchoolYear->year + "/" + (std::string)data + "/courses.txt");
	fout.close();
	return 1;

}










bool schoolYear::getGPASchoolYear(Static* a)
{
	

	schoolYear* GPAStudents = GPAYear;

	int nSemester = 0;
	nSemester = std::stoi(a->curSemester->semesterData.substr(8, 1));
	switch (nSemester)
	{
	case 1:
	{
		semester* Semester1 = new semester;
		a->curSemester->semesterData = "Semester1";
		int n1 = Semester1->getGPASemester(a);
		if (n1 == 0)
		{
			
			delete Semester1;
			return false;
			
		}
		semester* cur = Semester1->GPASemester;
		while(cur)
		{
			if (GPAYear == nullptr)
			{
				GPAYear = new schoolYear;
				GPAStudents = GPAYear;
			}
			else {
				GPAStudents->pNext = new schoolYear;
				GPAStudents = GPAStudents->pNext;
			}
			
			std::stringstream ss;
			ss << std::fixed << std::setprecision(2) << cur->GPA;
			ss >> GPAStudents->GPA;
			
			cur = cur->pNext;
		}
		delete Semester1;
		break;
		
	}
	case 2:
	{
		semester* Semester1 = new semester;
		a->curSemester->semesterData = "Semester1";
		int n1 = Semester1->getGPASemester(a);
		semester* Semester2 = new semester;
		a->curSemester->semesterData = "Semester2";
		int n2 = Semester2->getGPASemester(a);
		if (n1 == 0 || n2 == 0)
		{
			
			delete Semester1;
			delete Semester2;
			return false;
		}
		semester * cur1 = Semester1->GPASemester;
		semester* cur2 = Semester2->GPASemester;
		while (cur1)
		{
			if (GPAYear == nullptr)
			{
				GPAYear = new schoolYear;
				GPAStudents = GPAYear;
			}
			else {
				GPAStudents->pNext = new schoolYear;
				GPAStudents = GPAStudents->pNext;
			}
			// This means that student have not completed 2 semesters
			if (cur1->GPA == -1 || cur2->GPA == -1)
			{
				GPAStudents->GPA = -1;
			}
			else {
				std::stringstream ss;
				ss << std::fixed << std::setprecision(2) << (cur1->GPA + cur2->GPA) / 2;
				ss >> GPAStudents->GPA;
				
				
			}
			cur1 = cur1->pNext;
			cur2 = cur2->pNext;

		}
		delete Semester1;
		delete Semester2;
		break;

	}
	case 3:
	{
		semester* Semester1 = new semester;
		a->curSemester->semesterData = "Semester1";
		int n1 = Semester1->getGPASemester(a);
		semester* Semester2 = new semester;
		a->curSemester->semesterData = "Semester2";
		int n2 = Semester2->getGPASemester(a);
		semester * Semester3 = new semester;
		a->curSemester->semesterData = "Semester3";
		int n3 = Semester3->getGPASemester(a);

		if (n1 == 0 || n2 == 0 || n3 == 0)
		{
			
			delete Semester1;
			delete Semester2;
			delete Semester3;
			return false;
		}
		semester* cur1 = Semester1->GPASemester;
		semester* cur2 = Semester2->GPASemester;
		semester* cur3 = Semester3->GPASemester;
		while (cur1)
		{
			if (GPAYear == nullptr)
			{
				GPAYear = new schoolYear;
				GPAStudents = GPAYear;
			}
			else {
				GPAStudents->pNext = new schoolYear;
				GPAStudents = GPAStudents->pNext;
			}
			// This means that student have not completed 2 semesters
			if (cur1->GPA == -1 || cur2->GPA == -1 || cur3->GPA == -1)
			{
				GPAStudents->GPA = -1;
			}
			else {
				std::stringstream ss;
				ss << std::fixed << std::setprecision(2) << (cur1->GPA + cur2->GPA + cur3->GPA) / 3;
				ss >> GPAStudents->GPA;
				
			}
			cur1 = cur1->pNext;
			cur2 = cur2->pNext;
			cur3 = cur3->pNext;
		}
		delete Semester1;
		delete Semester2;
		delete Semester3;
		break;
	}
	}

	if (GPAStudents)
	{
		GPAStudents->pNext = nullptr;
	}

	return true;
}

schoolYear::~schoolYear()
{
	while (pHeadSemester)
	{
		semester* tmpSemester = pHeadSemester;
		pHeadSemester = pHeadSemester->pNext;
		delete tmpSemester;
	}
	schoolYear* cur = pHead;
	while (cur)
	{

		schoolYear* tmpYear = cur;
		cur = cur->pNext;
		delete tmpYear;
	}

}

