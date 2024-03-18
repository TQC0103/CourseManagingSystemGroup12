<<<<<<< HEAD
#include "SchoolYear.h"
#include "Semester.h"
#include <fstream>
#include<iostream>
#include<direct.h>
#include "Date.h"

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
		std::cout << "Error: File not found" << std::endl;
		return;
	}
	std::string data;
	schoolYear* cur = pHead;
	while (fin >> data) {
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

bool schoolYear::addSchoolYear(std::string yearData) {
	std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
	std::string check;
	while (fin >> check) {
		if (check == yearData) {
			return false;
		}
	}
	fin.close();
	std::ofstream fout("../Database/SchoolYear/AllSchoolYear.txt", std::ios::app);
	fout << yearData << std::endl;
	fout.close();
	_mkdir(("../Database/SchoolYear/" + yearData).c_str());
	return true;

}
void schoolYear::loadSemester() {
	std::ifstream fin("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt");
	if (!fin.is_open()) {
		std::cout << "Error: File not found" << std::endl;
		return;
	}
	pHeadSemester = new semester;
	semester* cur = pHeadSemester;
	std::string data;
	while (getline(fin, data)) {
		if (cur->pNext) {
			cur = cur->pNext;
		}
		cur->semesterData = data;
		fin.ignore();
		getline(fin, cur->startDate, ';');
		getline(fin, cur->endDate);
		cur->pNext = new semester;

	}
	semester* temp = cur->pNext;
	delete temp;
	cur->pNext = nullptr;
}

bool schoolYear::addSemester(std::string data, std::string start, std::string end)
{
	std::string checknumber;
	int n = data.length();
	checknumber = data.substr(n - 1);
	if (std::stoi(checknumber) > 3) {
		return false;
	}
	std::ifstream fin("..Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt");
	std::string check;
	std::string ignore_one;
	while (fin >> check) {
		if (check == data) {
			return false;
		}
		fin >> ignore_one;
	}
	fin.close();
	std::ofstream fout("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt", std::ios::app);
	fout << data << std::endl;
	fout << start << ";" << end << std::endl;
	fout.close();
	_mkdir(("../Database/SchoolYear/" + (std::string)curSchoolYear->year).c_str());
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
=======
//#include "SchoolYear.h"
//#include "Semester.h"
//#include <fstream>
//#include<iostream>
//#include<direct.h>
//#include "Date.h"
//
//
//schoolYear::schoolYear() {
//	year = "";
//	pHead = nullptr;
//	pNext = nullptr;
//}
//schoolYear::schoolYear(std::string yearData) {
//	year = yearData;
//	pHead = nullptr;
//	pNext = nullptr;
//}
//
//void schoolYear::loadSchoolYear()
//{
//	std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
//	if (!fin.is_open()) {
//		std::cout << "Error: File not found" << std::endl;
//		return;
//	}
//	std::string data;
//	schoolYear* cur = pHead;
//	while (fin >> data) {
//		if (!pHead) {
//			pHead = new schoolYear(data);
//			cur = pHead;
//		}
//		else {
//			cur->pNext = new schoolYear(data);
//			cur = cur->pNext;
//		}
//	}
//	cur->pNext = nullptr;
//	fin.close();
//}
//
//bool schoolYear::addSchoolYear(std::string yearData) {
//	std::ifstream fin("../Database/SchoolYear/AllSchoolYear.txt");
//	std::string check;
//	while (fin >> check) {
//		if (check == yearData) {
//			return false;
//		}
//	}
//	fin.close();
//	std::ofstream fout("../Database/SchoolYear/AllSchoolYear.txt", std::ios::app);
//	fout << yearData << std::endl;
//	fout.close();
//	_mkdir(("../Database/SchoolYear/" + yearData).c_str());
//	return true;
//
//}
//void schoolYear::loadSemester() {
//	std::ifstream fin("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt");
//	if (!fin.is_open()) {
//		std::cout << "Error: File not found" << std::endl;
//		return;
//	}
//	pHeadSemester = new semester;
//	semester* cur = pHeadSemester;
//	std::string data;
//	while (getline(fin, data)) {
//		if (cur->pNext) {
//			cur = cur->pNext;
//		}
//		cur->semesterData = data;
//		fin.ignore();
//		getline(fin, cur->startDate, ';');
//		getline(fin, cur->endDate);
//		cur->pNext = new semester;
//
//	}
//	semester* temp = cur->pNext;
//	delete temp;
//	cur->pNext = nullptr;
//}
//
//bool schoolYear::addSemester(std::string data, std::string start, std::string end)
//{
//	std::string checknumber;
//	int n = data.length();
//	checknumber = data.substr(n - 1);
//	if (std::stoi(checknumber) > 3) {
//		return false;
//	}
//	std::ifstream fin("..Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt");
//	std::string check;
//	std::string ignore_one;
//	while (fin >> check) {
//		if (check == data) {
//			return false;
//		}
//		fin >> ignore_one;
//	}
//	fin.close();
//	std::ofstream fout("../Database/SchoolYear/" + (std::string)curSchoolYear->year + "/AllSemester.txt", std::ios::app);
//	fout << data << std::endl;
//	fout << start << ";" << end << std::endl;
//	fout.close();
//	_mkdir(("../Database/SchoolYear/" + (std::string)curSchoolYear->year).c_str());
//	return true;
//	
//}
//
//
//
//void schoolYear::deallocateSchoolYear() {
//	while (pHead) {
//		schoolYear* tmp = pHead;
//		pHead = pHead->pNext;
//		delete tmp;
//	}
//}
//void schoolYear::deallocateSemester() {
//	while (pHeadSemester) {
//		semester* tmp = pHeadSemester;
//		pHeadSemester = pHeadSemester->pNext;
//		delete tmp;
//	}
//}
>>>>>>> 0904f518ba93f13dcfc54318cf801995c68799a2
