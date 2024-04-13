#include<iostream>
#include "Student.h"
#include "Class.h"
#include <string>
#include <fstream>
#include "Semester.h"
#include <direct.h>
#include <cstring>
#include"config.h"


Class::Class() {
	pNext = nullptr;
	name = "";
	pHeadListStudents = nullptr;

}

//Read data from files
bool Class::input_Student_from_file(student*& pHeads, std::string new_name_Class) {
	//pHeads->firstName = new_name_Class;
	std::ifstream fIn;
	fIn.open("../Database/Class/" + new_name_Class + "/Students/" + new_name_Class + ".csv");
	if (!fIn.is_open()) {
		//std::cout << "Error! Enter file again!";
		return false;
	}
	pHeads = nullptr;
	std::string x;
	student* cur = pHeads;
	std::string tmp = "";
	//delete title
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	while (std::getline(fIn, x, '\n')) {
		// Allocate memory for a new node
		student* newNode = new student;
		newNode->No = stoi(x);

		// Read student information
		std::getline(fIn, newNode->socialID, ',');
		std::getline(fIn, newNode->firstName, ',');
		std::getline(fIn, newNode->lastName, ',');
		std::getline(fIn, newNode->gender, ',');
		std::string tmpDay = "";
		std::string tmpMonth = "";
		std::string tmpYear = "";
		std::getline(fIn, tmpDay, '/');
		newNode->dateOfBirth.d = stoi(tmpDay);
		std::getline(fIn, tmpMonth, '/');
		newNode->dateOfBirth.m = stoi(tmpMonth);
		std::getline(fIn,tmpYear , ',');
		newNode->dateOfBirth.y = std::stoi(tmpYear);
		std::getline(fIn, newNode->socialID,'\n');
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
	return true;
}
//Load data
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
	while (std::getline(fIn, name_class)) {
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
//update curClass if class of user exist
//bool Class::find_Class_of_Student(Static* a) // find class of student
//{
//	Class* cur = pHeadListClasses;
//	while (cur) {
//		if (cur->pHeadListStudents->studentID == a->username) {
//			a->curClass = new Class;
//			a->curClass = pHeadListClasses;
//			return true;
//		}
//		cur = cur->pNext;
//	}
//	return false;
//}
bool Class::isExist(Static* a, Class *&cur) {
	cur = pHeadListClasses;
	while (cur) {
		if (cur->name == a->curClass->name) return true;
		cur = cur->pNext;
	}
	return false;
}
int Class::loadStudents(Static* a) {
	load_classes();
	Class* cur = NULL;
	if (!isExist(a, cur)) return 0;
	if (!input_Student_from_file(cur->pHeadListStudents, cur->name)) return 0;
	return 1;
}

//Not data to update pHeadListCLass
bool Class::isInvalid(std::string nameClass) {
	Class* tmp = pHeadListClasses;
	while (tmp) {
		if (tmp->name == nameClass) {
			return true;
		}
		tmp = tmp->pNext;
	}
	delete tmp;
	return false;
}
//create new Class Not to update data.

bool Class::creat_new_Class(std::string nameClass) {
	load_classes();
	if (isInvalid(nameClass) == true)
	{
		std::cout << "Error! The name Class is exist!\n";
		return false;
	}
	int result = _mkdir(("../Database/Class/" + nameClass).c_str());
	std::string name = "Students";
	
	if (result != 0) {

		//std::cout << "Error: Unable to create directory" << std::endl;
		return false;
	}
	int result_student = _mkdir(("../Database/Class/" + nameClass + "/" + name).c_str());
	if (result_student != 0) {
		std::cout << "Error: Unable to create directory" << std::endl;
		return false;
	}

	Class* new_Class = new Class;
	new_Class->name = nameClass;
	Sort_Class(new_Class);
	std::ofstream fOut;
	fOut.open(("../Database/Class/" + nameClass +"/" + name + "/" + nameClass + ".csv"));
	if (!fOut.is_open()) {
		//std::cout << "Error: Unable to create directory" << std::endl;
		return false;
	}
	print_txt();
	return true;
}

void Class::print_txt() {
	std::ofstream fOut;
	fOut.open("../Database/Class/AllClasses.txt"); //can insert link folder
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

// Insert data from keyboard !
//bool isInputValid(std::string a, std::string b, std::string c, std::string d, std::string e, std::string f) {
//
//}
int Class::check_No(student * listStudent, std::string No) {
	int tmp = stoi(No);
	while(listStudent){
		if (listStudent->No == tmp) return 0;
		listStudent = listStudent->pNext;
	}
	return 1;
}
int Class::check_ID(student* listStudent, std::string ID) {
	while (listStudent) {
		if (listStudent->studentID == ID) return 0;
		listStudent = listStudent->pNext;
	}
	return 1;
}
bool Class::check_Gender(std::string gender) {
	return (gender == "nam" || gender == "Nam" || gender == "Nu" || gender == "nu");
}
int Class::insert_new_Class_keyboard(Static *a, std::string no, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string BirthDay, std::string SocialID){
	Class* new_Class = new Class;

	new_Class->pNext = NULL;

	input_Student_from_file(new_Class->pHeadListStudents, a->curClass->name);
	//check input;
	
	student* cur =  new_Class->pHeadListStudents;
	student* tmp = new student;
	if (!check_No(new_Class->pHeadListStudents, no)) {
		return 1;
	}
	if (!check_ID(new_Class->pHeadListStudents, ID)) return 2;
	tmp->No = stoi(no);
	tmp->studentID = ID;
	tmp->lastName = LastName;
	if (!check_Gender(Gender)) return 5;
	tmp->gender = Gender;

	int i = 0;
	std::string Day = "";
	std::string month = "";
	std::string year = "";
	if (!checkInputDate(BirthDay)) return 6;
	while (BirthDay[i] != '/') {
		Day += BirthDay[i];
		i++;
	}
	while (BirthDay[i] != '/') {
		month += BirthDay[i];
		i++;
	}
	while ( i < BirthDay.length()) {
		year += BirthDay[i];
		i++;
	}
	tmp->dateOfBirth.d = std::stoi(Day);
	tmp->dateOfBirth.m = std::stoi(month);
	tmp->dateOfBirth.y = std::stoi(year);
	tmp->socialID = SocialID;
	tmp->firstName = FirstName;
	while (cur && cur->pNext) {
		cur = cur->pNext;
	}
	if (cur) cur = tmp;
	else {
		cur->pNext = new student;
		cur->pNext = tmp;
	}
	print_csv(new_Class->pHeadListStudents, new_Class->name);
	return 8;
}
int Class::print_csv(student* a, std::string name_Class) {
	std::ofstream fOut;
	fOut.open("../Database/Class/" + name_Class + "/Students/" + name_Class + ".csv");
	if (!fOut.is_open()) {
		std::cout << "Error!\n";
		return 0;
	}
	fOut << "No" << "," << "Student-ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender"<<"," << "Date Of Birth" << "," << "" << "Social ID" << "\n";
	while (a) {
		std::string tmpBirthday = "";
		tmpBirthday = tmpBirthday + std::to_string(a->dateOfBirth.d) + "/" + std::to_string(a->dateOfBirth.m) + "/" + std::to_string(a->dateOfBirth.y);
		fOut << std::to_string(a->No) << "," << a->studentID << "," << a->firstName << "," << a->lastName << "," << a->gender << "," << tmpBirthday <<"," << a->socialID << "\n";
		a = a->pNext;
	}
	return 1;
}
//Year !???
bool Class::checkInputDate(std::string& data)
{
	// Norming the input data
	int pos = 0;
	int n = (int)data.length();
	std::string testDay = "";
	std::string monthDay = "";
	std::string yearDay = "";
	for (int i = 0; i < n; i++)
	{
		if (data[i] != ' ')
		{
			data[pos++] = data[i];
		}
	}//delete space
	n = pos;
	pos = 0;
	//read /
	while (pos < n && isdigit(data[pos]))
	{
		testDay += data[pos++];
	}
	pos++;
	while (pos < n && isdigit(data[pos]))
	{
		monthDay += data[pos++];
	}
	while (pos < n) {
		yearDay += data[pos++];
	}
	if (testDay.length() == 1)
	{
		testDay = "0" + testDay;
	}
	if (monthDay.length() == 1)
	{
		monthDay = "0" + monthDay;
	}
	data = testDay + "/" + monthDay + "/" + yearDay;
	int len  = (int)data.length();
	if (len != 10)
	{
		return false;
	}
	std::string stringDate = data.substr(0, 2);
	std::string stringMonth = data.substr(3, 2);
	std::string stringYear = data.substr(6, 4);
	int day = std::stoi(stringDate);
	int month = std::stoi(stringMonth);
	int year = std::stoi(stringYear);

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
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		{
			return day >= 1 && day <= 29;
		}
		else {
			return day >= 1 && day <= 28;
		}
	}
}

//Insert data from path!
int Class :: insert_data_Class_from_path(Static* a, std::string path_keyboard) {
	student* newStudent = NULL;
	std::ifstream fIn;
	fIn.open(path_keyboard);
	if (!fIn.is_open()) {
		std::cout << "Error! Enter file again!";
		return 0;
	}
	std::string x;
	student* cur = newStudent;
	std::string tmp = "";
	//delete title
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	std::getline(fIn, tmp, ',');
	while (std::getline(fIn, x, ',')) {
		// Allocate memory for a new node
		student* newNode = new student;
		newNode->No = std::stoi(x);

		// Read student information
		std::getline(fIn, newNode->socialID, ',');
		std::getline(fIn, newNode->firstName, ',');
		std::getline(fIn, newNode->lastName, ',');
		std::getline(fIn, newNode->gender, ',');
		std::string tmpDay = "";
		std::string tmpMonth = "";
		std::string tmpYear = "";
		std::getline(fIn, tmpDay, '/');
		newNode->dateOfBirth.d = stoi(tmpDay);
		std::getline(fIn, tmpMonth, '/');
		newNode->dateOfBirth.m = stoi(tmpMonth);
		std::getline(fIn, tmpYear, ',');
		newNode->dateOfBirth.y = std::stoi(tmpYear);
		std::getline(fIn, newNode->socialID, '\n');
		newNode->pNext = nullptr;

		// Update the linked list
		if (!cur) {
			newStudent = new student;
			cur = newStudent;
		}
		else {
			cur->pNext = new student;
			cur = cur->pNext;
		}
		cur = newNode;
	}
	fIn.close();

	loadStudents(a);
	student * tmpStudent = a->curClass->pHeadListStudents;
	if (tmpStudent == NULL) {
		a->curClass->pHeadListStudents = newStudent;
		return 1;
	}
	while (tmpStudent->pNext) {
		tmpStudent = tmpStudent->pNext;
	}
	tmpStudent->pNext = newStudent;
	print_csv(a->curClass->pHeadListStudents, a->curClass->name);
	return 1;
}


// sort file name follow name in data, all.txt;
void Class::Sort_Class(Class* new_Class) {
	if (!pHeadListClasses) {
		pHeadListClasses = new_Class;
		return;
	}
	if (pHeadListClasses->name > new_Class->name) {
		new_Class->pNext = pHeadListClasses;
		pHeadListClasses = new_Class;
		return;
	}
	Class* cur = pHeadListClasses->pNext;
	Class* pre = pHeadListClasses;
	while (cur) {
		if (cur->name > new_Class->name) {
			new_Class->pNext = cur;
			pre->pNext = new_Class;
		}
		pre = cur;
		cur = cur->pNext;
	}
	if (!cur) pre->pNext = new_Class;
	print_class_txt();
}
void Class::print_class_txt() {
	std::ofstream fOut;
	fOut.open("class.txt");
	if (!fOut.is_open()) {
		std::cout << "Error! Open file isn't successfull!";
		return;
	}
	Class* cur = pHeadListClasses;
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
//void Class::print_Student_profile_in_class_files(student* pHeads, std::ofstream& fOut) { // can replace by frame
//	//to print student outside files
//	while (pHeads) {
//		fOut << pHeads->No << ";" << pHeads->studentID << ";" << pHeads->firstName << ";" << pHeads->lastName << ";";
//
//		fOut << pHeads->gender << ";" << pHeads->dateOfBirth.d << "/" << pHeads->dateOfBirth.m << "/" << pHeads->dateOfBirth.y << pHeads->socialID << "\n";
//		pHeads = pHeads->pNext;
//	}
//}
//Not finished!
//void Class::export_File(std::string name_Class, std::string path)
//{
//	std::ofstream fOut;
//	fOut.open("../Database/Class/" + path + ".csv"); //can insert link folder
//	if (!fOut.is_open()) {
//		std::cout << "Error! Open file isn't successfull!";
//		return;
//	}
//	Class* cur = pHeadListClasses;
//	if (!cur) return;
//	while (cur) {
//		if (cur->name == name_Class) {
//			print_Student_profile_in_class_files(cur->pHeadListStudents, fOut);
//			break;
//		}
//		cur = cur->pNext;
//	}
//	fOut.close();
//}