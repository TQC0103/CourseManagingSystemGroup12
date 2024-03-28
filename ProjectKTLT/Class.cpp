
#include<iostream>
#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include "Semester.h"
#include <cstring>
#include"config.h"


Class::Class() {
	pHeadListClasses = nullptr;
	pNext = nullptr;
	pHeadListStudents = nullptr;
}

//Read data from files
void Class::input_Student_from_file(student *&pHeads, std::string new_name_Class) {
	pHeads->firstName = new_name_Class;
	std::ifstream fIn;
	fIn.open("../Database/Profile/Class/" + new_name_Class + ".csv");
	if (!fIn.is_open()) {
		std::cout << "Error! Enter file again!";
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
	Class *cur = pHeadListClasses;
	std::string name_class;
	while (getline(fIn, name_class)) {
		if (pHeadListClasses == nullptr) {
			pHeadListClasses = new Class;
			cur = pHeadListClasses;
		}else{
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

bool Class::find_Class_of_Student(Class* pHead, std::string ID, std::string& Name_class) // find class of student
{
	while (pHead) {
		student* pHeads = pHead->pHeadListStudents;
		if (pHead->pHeadListStudents->studentID == ID) {
			Name_class = pHead->name;
			return 1;
		}
		pHead = pHead->pNext;
	}
	return 0;
}


 Class* Class::creat_new_Class(std::string path) {
	Class* new_Class = new Class;
	student *pnewHead = new_Class->pHeadListStudents;
	input_Student_from_file(pnewHead, path);
	new_Class->pNext = NULL;
	return new_Class;
}
void Class::print_txt() {
	std::ofstream fOut;
	fOut.open("../Database/Profile/Class/AllClasses.txt"); //can insert link folder
	if (!fOut.is_open()) {
		std::cout << "Error! Open file isn't successfull!";
		return;
	}
	Class* cur = pHeadListClasses;
	while (cur) {
		fOut << cur->name << "\n";
		cur = cur->pNext;
	}
	fOut.close();
}
//Insert file new class by csv (4) 
void Class::insert_new_Class(Class*& pHead, std::string name_Class) {
	Class* new_Class = new Class;
	new_Class->pNext = NULL;
	input_Student_from_file(new_Class->pHeadListStudents, name_Class);
	//insert class into linked list;
	//update file into data
	if (!pHead) {
		pHead = new_Class;
		print_txt();
		return;
	}
	Class* cur = pHead;
	while ( cur->pNext && cur->pNext->name < name_Class) {
		cur = cur->pNext;
	}
	Class* tmp = cur->pNext;
	cur->pNext = new_Class;
	new_Class->pNext = tmp;
	print_txt();	//update all.txt
}


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
	fOut.open("../Database/Profile/Class/" + path + ".csv"); //can insert link folder
	if (!fOut.is_open()) {
		std::cout << "Error! Open file isn't successfull!";
		return;
	}
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->name == name_Class) {
			print_Student_profile_in_class_files(cur->pHeadListStudents, fOut);
			break;
		}
		cur = cur->pNext;
	}
	fOut.close();
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
		std::cout << "Error! Open file isn't successfull!";
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
Class::~Class() {
	Class* cur = pHeadListClasses;
	while (cur)
	{
		Class* tmp = cur;
		cur = cur->pNext;
		delete tmp;
	}
}


/*
void class::print_student_profile_in_class(student* pheads) { // can replace by frame
	//to print student outside screen
	while (pheads) {
		std::cout << pheads->no << ";" << pheads->studentid << ";" << pheads->firstname << ";" << pheads->lastname << ";";

		std::cout<< pheads->gender << ";"<< pheads->dateofbirth.d <<"/" << pheads->dateofbirth.m << "/"<< pheads->dateofbirth.y << pheads->socialid << "\n";
		pheads = pheads->pnext;
	}
}*/
//view profile student in class.(16)

/*
void Class::view_List_Student_profile(Class* pHead, std::string name_class) {
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->name == name_class) {
			print_Student_profile_in_class(pHead->pHeadListStudents);
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

/*
void Class::show_Student_each_profile(Class* pHead, std::string ID_student) {
	Class* cur = pHead;
	if (!cur) return;
	while (cur) {
		if (cur->pHeadListStudents->studentID == ID_student) {
			std::cout << pHeadListStudents->No << ";" << pHeadListStudents->studentID << ";" << pHeadListStudents->firstName << ";" << pHeadListStudents->lastName << ";";
			std::cout << pHeadListStudents->gender << ";" << pHeadListStudents->dateOfBirth.d << "/" << pHeadListStudents->dateOfBirth.m << "/" << pHeadListStudents->dateOfBirth.y << pHeadListStudents->socialID << "\n";
			pHeadListStudents = pHeadListStudents->pNext;
			break;
		}
		cur = cur->pNext;
	}
}

*/
// delete class from linked list
/*void Delete_aCLass(Class*& aclass) {
	student* tmp = aclass->pheads;
	while (aclass->pheads) {
		tmp = aclass->pheads
		aclass->pheads = aclass->pheads->pNext;
		delete tmp;
	}
	delete aclass->pheads;
	delete aclass;
}
void Class::remove_Class(Class*& pHead, std::string name_class)
{
	if (!pHead) return;
	if (pHead->name == name_class) {
		Class* tmp = pHead;
		pHead = pHead->pNext;
		Delete_aClass(tmp);
		print_txt(pHead);
		//delete file
		if (const std::exception & ex) {
			std::cerr << "Error! " << ex.what() << '\n';
		}
		eypelse {
			// Link file which you need delete
			fs::path file_to_delete = ".. / Database / Profile / Class / " + name_class + ".csv";

			// delete file
			fs::remove(file_to_delete);

			std::cout << "File removed successfull!\n";
		}
		return;
	}
	Class* cur = pHead;
	while (cur->pNext && cur->pNext->name != name_class) {
		cur = cur->pNext;
	}
	if (!cur->pNext) return;
	Class* tmp = cur->pNext;
	Class* next = tmp->pNext;
	cur->pNext = next;
	Delete_aClass(tmp);
	//delete file
	 if (const std::exception& ex) {
		std::cerr << "Error! " << ex.what() << '\n';
	}else{
		// Link file which you need delete
		fs::path file_to_delete = ".. / Database / Profile / Class / " + name_class + ".csv";

		// delete file
		fs::remove(file_to_delete);

		std::cout << "File removed successfull!\n";
	}
	print_txt(pHead);
}*/
//export file.(can 19)


//void Class::show_Student_each_scoreboard(Class* pHead, std::string ID_student){}
//void Class::export_File_score(Class* pHead, std::string name_Class, std::string path) {}
// Show list last(15)
/*
void Class::show_List_Class(Class* pHead)
{
	while (pHead) {
		std::cout << pHead->name << "\n";
		pHead = pHead -> pNext;
	}
}*/
