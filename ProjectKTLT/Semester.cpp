#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include "Date.h"
#include<direct.h>


extern schoolYear* curSchoolYear;
extern semester* curSemester;
semester::semester(int semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;	
	endDate = EndDate;
}
void semester::loadSemester() {
	std::string year = "2023-2024";
	std::ifstream fin("../Database/SchoolYear/" + year + "/AllSemester.txt");
	if (!fin.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		return;
	}
	pHead = new semester;
	semester* cur = pHead;

	while (!fin.eof()) {
		if (cur != pHead) {
			cur = cur->pNext;
		}
		fin >> cur->semesterData;
		getline(fin, cur->startDate, ',');
		getline(fin, cur->endDate, ',');
		cur->pNext = new semester;
		
	}
	delete cur->pNext;
	cur->pNext = nullptr;
}
void semester::addSemester(int num, std::string start, std::string end)
{
	std::string year = "2023-2024";
	semester* cur = pHead;
	std::ofstream fout("../Database/SchoolYear/" + year + "/AllSemester.txt", std::ios::app);
	fout << num << "\n";
	fout << start << "," << end << "\n";
	fout.close();
	std::string newDir = "../Database/SchoolYear/" + year + "/Semester" + std::to_string(num);
	_mkdir(newDir.c_str());
	
}

