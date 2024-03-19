#include "SchoolYear.h"
#include "Semester.h"
#include <fstream>
#include<iostream>
#include<direct.h>
#include "Date.h"
#include <cctype>

schoolYear* curSchoolYear;
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
		std::cerr << "Error: File not found" << std::endl;
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
	cur->pNext = nullptr;
	fin.close();
}

void schoolYear::findCurrentSchoolYear(std::string data)
{
	schoolYear* cur = pHead;
	while (cur)
	{
		if (cur->year == data)
		{
			curSchoolYear = cur;
			return;
		}
	}
}

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

bool schoolYear::checkInputDate(std::string &data)
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
		std::string tmpYear = curSchoolYear->year.substr(5, 4);
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

bool schoolYear::addSchoolYear(std::string yearData) {
	checkInputYear(yearData);
	if (!checkInputYear(yearData)) {
		return false;
	}
	std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
	std::string check;
	while (getline(fin, check)) {
		if (check == yearData) {
			return false;
		}
	}
	//fin.ignore();
	fin.close();
	std::ofstream fout("../Database/SchoolYear/AllSchoolYear.txt", std::ios::app);
	
	fout << yearData << std::endl;
	fout.close();
	_mkdir(("../Database/SchoolYear/" + (std::string)yearData).c_str());
	schoolYear* cur = pHead;
	while (cur->pNext) {
		cur = cur->pNext;
	}
	cur->pNext = new schoolYear(yearData);
	cur = cur->pNext;
	cur->pNext = nullptr;
	curSchoolYear = cur;
	return true;

}

void schoolYear::loadSemester() {
	std::ifstream fin("../Database/SchoolYear/" + curSchoolYear->year + "/AllSemester.txt");
	if (!fin.is_open()) {
		std::cerr << "Error: File not found" << std::endl;
		return;
	}
	curSchoolYear->pHeadSemester = new semester;
	semester* cur = curSchoolYear->pHeadSemester;
	std::string data;
	while (getline(fin, data)) {
		if (cur->pNext) {
			cur = cur->pNext;
		}
		cur->semesterData = data;
		getline(fin, cur->startDate, ';');
		getline(fin, cur->endDate);
		cur->pNext = new semester;

	}
	fin.close();
	semester* temp = cur->pNext;
	delete temp;
	cur->pNext = nullptr;

}

bool schoolYear::addSemester(std::string data, std::string start, std::string end)
{
	if (!checkInputDate(start) || !checkInputDate(end)) {
		return false;
	}
	std::string checknumber;
	int n = (int)data.length();
	checknumber = data.substr(n - 1);
	if (std::stoi(checknumber) > 3) {
		return false;
	}
	std::ifstream fin("../Database/SchoolYear/" + curSchoolYear->year + "/AllSemester.txt");

	// if the semester in a new school year, create a new file
	if (!fin.is_open()) {
		//std::cerr << "Error: File not found" << std::endl;
		//_mkdir(("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt").c_str());
        std::ofstream fout("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt");
		fout.close();
		if (std::stoi(checknumber) != 1) {
			return false;
		}
	}
	else {
		std::string check;
		std::string ignore_one;
		while (getline(fin, check)) {
			if (check == data) {
				return false;
			}
			getline(fin, ignore_one);
		}
		
	}
	fin.close();
	std::ofstream fout("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt", std::ios::app);
	fout << data << std::endl;
	fout << start << ";" << end << std::endl;
	fout.close();
	_mkdir(("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/" + (std::string)data).c_str());
	semester* cur = curSchoolYear->pHeadSemester;
	if (!cur) {
		cur = new semester(data, start, end);
		cur->pNext = nullptr;
	}
	else {
		while (cur->pNext) {
			cur = cur->pNext;
		}
		cur->pNext = new semester(data, start, end);
		cur = cur->pNext;
		cur->pNext = nullptr;
	}
	

	return true;

}



void schoolYear::deallocateSchoolYear() {
	while (pHead) {
		schoolYear* tmp = pHead;
		pHead = pHead->pNext;
		delete tmp;
	}
}

void schoolYear::deallocateSemester() {
	while (pHeadSemester) {
		semester* tmp = pHeadSemester;
		pHeadSemester = pHeadSemester->pNext;
		delete tmp;
	}
}