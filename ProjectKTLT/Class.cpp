#include<iostream>
#include "Student.h"
#include"Class.h"
#include<string>
#include<fstream>
#include "Semester.h"
#include<cstring>
//Read data from files
static void input_Student_from_file(student *&pHeads, std::string new_name_Class) {
	pHeads->firstName = new_name_Class;
	std::ifstream fIn;
	fIn.open(new_name_Class);
	if (!fIn.is_open()) {
		std::cout << "Please, Enter file again!";
		return;
	}
	pHeads = nullptr;
	int x;
	student* cur = pHeads;
	while (fIn >> x) {
		// Allocate memory for a new node
		student *newNode = new student;
		newNode->No = x;

		// Read student information
		std::getline(fIn, newNode->socialID, ';');
		std::getline(fIn, newNode->firstName, ';');
		std::getline(fIn, newNode->gender, ';');
		fIn >> newNode->dateOfBirth.d;
		fIn.ignore(1);
		fIn >> newNode->dateOfBirth.m;
		fIn.ignore(1);
		fIn >> newNode->dateOfBirth.y;
		fIn.ignore(1); // Consume the delimiter
		std::getline(fIn, newNode->socialID, ';');
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
void Class::load_Files(Class*& pHead, std::string path) {	//load File when open program;
	std::ifstream fIn;
	fIn.open(path); //can insert link folder
	if (!fIn.is_open()) {
		std::cout << "Open file isn't successfull!";
		return;
	}
	fIn.close();
}
void Class::delete_Class(Class*& pHead) {
	Class * tmp = pHead;
	while (pHead) {
		tmp = pHead;
		pHead = pHead->pNext;
		delete tmp;
	}
	delete pHead;
}
void Class::show_List_Student_profile(Class* pHead) {

}
void Class::show_List_Student_scoreboard(Class* pHead) {

}
/* here or struct student
void Class::insert_a_Student_Class1st(Class*& pHead);
void Class::delete_a_Student_Class(Class*& pHead);
*/
bool Class::find_Class_of_Student(Class* pHead, std::string ID, std::string& Name_class) // find class of student
{
	while (pHead) {
		student* pHeads = pHead->pHeads;
		if (pHead->pHeads->studentID == ID) {
			Name_class = pHead->name;
			return 1;
		}
		pHead = pHead->pNext;
	}
	return 0;
}

void Class::show_Student_profile(Class* pHead, std::string ID_student) {}
void Class::show_Student_scoreboard(Class* pHead, std::string ID_student) {}


static Class* creat_new_Class(std::string path) {
	Class* new_Class = new Class;
	student *pnewHead = new_Class->pHeads;
	input_Student_from_file(pnewHead, path);
	new_Class->pNext = NULL;
	return new_Class;
}
void Class::insert_new_Class(Class*& pHead) {
	//insert class into linked list;
	//update file into data
	//update all.txt
}

void Class::delete_Class(Class*& pHead, std::string name_class)
{
	// delete class from linked list
	//delete class from data
	//delete class from all.txt
}

void Class::export_File(Class* pHead, std::string name_Class, std::string path)
{
	//Data printed file 
}
void Class::show_List_Class(Class* pHead)
{
	while (pHead) {
		std::cout << pHead->name << "\n";
		pHead = pHead -> pNext;
	}
}
// sort file name follow name in data, all.txt;
