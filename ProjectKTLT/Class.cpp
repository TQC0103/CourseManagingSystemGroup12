
#include<iostream>
#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include "Semester.h"
#include <cstring>



Class::Class() {
	pNext = nullptr;

	pHeadListStudents = nullptr;

}

//Read data from files
void Class::input_Student_from_file(student*& pHeads, std::string new_name_Class) {
	pHeads->firstName = new_name_Class;
	std::ifstream fIn;
	fIn.open("../Database/Profile/Class/" + new_name_Class + ".csv");
	if (!fIn.is_open()) {
		std::cout << "Please, Enter file again!";
		return;
	}
	pHeads = nullptr;
	int x;
	student* cur = pHeads;
	while (fIn >> x) {
		// Allocate memory for a new node
		student* newNode = new student;
		newNode->No = x;

		// Read student information
		std::getline(fIn, newNode->socialID, ',');
		std::getline(fIn, newNode->firstName, ',');
		std::getline(fIn, newNode->gender, ',');
		fIn >> newNode->dateOfBirth.d;
		fIn.ignore(1);
		fIn >> newNode->dateOfBirth.m;
		fIn.ignore(1);
		fIn >> newNode->dateOfBirth.y;
		fIn.ignore(1); // Consume the delimiter
		std::getline(fIn, newNode->socialID, ',');
		newNode->pNext = nullptr;

		// Update the linked list
		if (!pHeads) {
			pHeads = newNode;
			cur = newNode;
		}
		else {
			cur->pNext = newNode;
			cur = cur->pNext;
		}
	}
	fIn.close();
}
int Class::load_classes() // load data from files
{
	std::ifstream fIn;
	int num = 0;
	fIn.open("../Database/Class/AllClasses.txt"); //can insert link folder
	if (!fIn.is_open()) {
		std::cout << "Error: File not found!";
		return 0;
	}
	Class* cur = pHeadListClasses;
	std::string name_class;
	while (getline(fIn, name_class)) {
		if (pHeadListClasses == nullptr) {
			pHeadListClasses = new Class;
			cur = pHeadListClasses;
		}
		else {
			cur->pNext = new Class;
			cur = cur->pNext;
		}
		cur->name = name_class;
		num++;
		cur->pNext = NULL;
	}
	fIn.close();
	return num;
}
void Class::delete_Class(Class*& pHead) {   //clean program if program end.
	Class* tmp = pHead;
	while (pHead) {
		tmp = pHead;






		pHead = pHead->pNext;
		delete tmp;
	}
	delete pHead;
}
void Class::print_Student_profile_in_class(student* pHeads) { // can replace by frame
	//to print student outside screen
}