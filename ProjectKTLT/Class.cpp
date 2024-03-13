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
void Class::load_Files(Class*& pHead, std::string path) {	//load File when open program; path is file .txt
	std::ifstream fIn;
	fIn.open(path); //can insert link folder
	if (!fIn.is_open()) {
		std::cout << "Open file isn't successfull!";
		return;
	}
	Class *cur = pHead;
	std::string name_class;
	while (fIn >> name_class) {
		if (!pHead) {
			pHead = new Class;
			cur = pHead;
		}else{
			cur->pNext = new Class;
			cur = cur->pNext;
		}
		input_Student_from_file(cur->pHeads, cur->name); //read data of each student
		cur->pNext = NULL;
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
void Class::print_Student_profile_in_class(student* pHeads) { // can replace by frame
	//to print student outside screen
	while (pHeads) {
		std::cout << pHeads->No << ";" << pHeads->studentID << ";" << pHeads->firstName << ";" << pHeads->lastName << ";";

		std::cout<< pHeads->gender << ";"<< pHeads->dateOfBirth.d <<"/" << pHeads->dateOfBirth.m << "/"<< pHeads->dateOfBirth.y << pHeads->socialID << "\n";
		pHeads = pHeads->pNext;
	}
}
void Class::show_List_Student_profile(Class* pHead, std::string name_class) {
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->name == name_class) {
			print_Student_profile_in_class(pHead->pHeads);
			break;
		}
		cur = cur->pNext;
	}
}
void Class::print_Student_scoreboard_in_class(student* pHeads) { // can replace by frame (not Done!)
	//to print student outside screen
	// depend on semester
	while (pHeads) {
		std::cout << pHeads->No << ";" << pHeads->studentID << ";" << pHeads->firstName << ";" << pHeads->lastName << ";";

		std::cout << pHeads->gender << ";" << pHeads->dateOfBirth.d << "/" << pHeads->dateOfBirth.m << "/" << pHeads->dateOfBirth.y << pHeads->socialID << "\n";
		pHeads = pHeads->pNext;
	}
}
void Class::show_List_Student_scoreboard(Class* pHead, std::string name_class) { // depend on semester
	//(not Done!)

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

void Class::show_Student_each_profile(Class* pHead, std::string ID_student) {
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->pHeads->studentID == ID_student) {
			std::cout << pHeads->No << ";" << pHeads->studentID << ";" << pHeads->firstName << ";" << pHeads->lastName << ";";
			std::cout << pHeads->gender << ";" << pHeads->dateOfBirth.d << "/" << pHeads->dateOfBirth.m << "/" << pHeads->dateOfBirth.y << pHeads->socialID << "\n";
			pHeads = pHeads->pNext;
			break;
		}
		cur = cur->pNext;
	}
}
void Class::show_Student_each_scoreboard(Class* pHead, std::string ID_student) {}


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
//export file:
void Class::print_Student_profile_in_class_files(student* pHeads, std::ofstream &fOut) { // can replace by frame
	//to print student outside files
	while (pHeads) {
		fOut << pHeads->No << ";" << pHeads->studentID << ";" << pHeads->firstName << ";" << pHeads->lastName << ";";

		fOut << pHeads->gender << ";" << pHeads->dateOfBirth.d << "/" << pHeads->dateOfBirth.m << "/" << pHeads->dateOfBirth.y << pHeads->socialID << "\n";
		pHeads = pHeads->pNext;
	}
}
void Class::export_File(Class* pHead, std::string name_Class, std::string path)
{
	std::ofstream fOut;
	fOut.open(path); //can insert link folder
	if (!fOut.is_open()) {
		std::cout << "Open file isn't successfull!";
		return;
	}
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->name == name_Class) {
			print_Student_profile_in_class_files(cur->pHeads, fOut);
			break;
		}
		cur = cur->pNext;
	}
	fOut.close();
}
void Class::show_Student_each_scoreboard(Class* pHead, std::string ID_student){}
void Class::export_File_score(Class* pHead, std::string name_Class, std::string path) {}

void Class::show_List_Class(Class* pHead)
{
	while (pHead) {
		std::cout << pHead->name << "\n";
		pHead = pHead -> pNext;
	}
}
// sort file name follow name in data, all.txt;
void Class::Sort_Class(Class*& pHead, Class* new_Class) {
	if (!pHead) {
		pHead = new_Class;
		return;
	}
	if (pHead->name > new_Class->name) {
		new_Class->pNext = pHead;
		pHead = new_Class;
		return;
	}
	Class* cur = pHead->pNext;
	Class* pre = pHead;
	while (cur) {
		if (cur->name > new_Class->name) {
			new_Class->pNext = cur;
			pre->pNext = new_Class;
		}
		pre = cur;
		cur = cur->pNext;
	}
	if (!cur) pre->pNext = new_Class;
	print_class_txt(pHead);
}
void Class::print_class_txt(Class* pHead) {
	std::ofstream fOut;
	fOut.open("class.txt");
	if (!fOut.is_open()) {
		std::cout << "Open file isn't successfull!";
		return;
	}
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		fOut << cur->name << "\n";
		cur = cur->pNext;
	}
	fOut.close();
}