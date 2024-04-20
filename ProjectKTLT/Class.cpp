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
bool Class::input_Student_from_file(student*& pHeads, std::string path) {
	//pHeads->firstName = new_name_Class;
	pHeads = NULL;
	std::ifstream fIn;
	
	fIn.open(path);
	if (!fIn.is_open()) {
		std::cout << "Error! Enter file again!";
		return false;
	}
	std::string x;
	student* cur = pHeads;
	std::string tmp = "";
	//delete title
	std::getline(fIn, tmp, '\n');
	while (std::getline(fIn, x, ',')) {
		// Allocate memory for a new node
		student*  newNode = new student;
		newNode->No = std::stoi(x);

		// Read student information
		std::getline(fIn, newNode->studentID, ',');
		std::getline(fIn, newNode->firstName, ',');
		std::getline(fIn, newNode->lastName, ',');
		std::getline(fIn, newNode->gender, ',');
		std::string tmpDay = "";
		std::string tmpMonth = "";
		std::string tmpYear = "";
		std::getline(fIn, tmpDay, '/');
		newNode->dateOfBirth.d = std::stoi(tmpDay);
		std::getline(fIn, tmpMonth, '/');
		newNode->dateOfBirth.m = std::stoi(tmpMonth);
		std::getline(fIn,tmpYear , ',');
		newNode->dateOfBirth.y = std::stoi(tmpYear);
		std::getline(fIn, newNode->socialID,'\n');
		newNode->pNext = NULL;

		// Update the linked list
		if (!pHeads) {
			pHeads = newNode;
		}
		else {
			cur->pNext = newNode;
		}
		cur = newNode;
	}
	fIn.close();
	//std::cout << "SUCCESS!\n";
	return true;
}
//Load data
int Class::load_classes() // load data from files
{
	std::ifstream fIn;
	int num = 0;
	fIn.open("../Database/Class/AllClasses.txt"); //can insert link folder
	if (!fIn.is_open()) {
		//std::cout << "Error: File not found!";
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
Class*Class::isExist(Static* a) {
	Class* tmp = pHeadListClasses;
	while (tmp) {
		if (tmp->name == a->curClass->name) return tmp;
		tmp = tmp->pNext;
	}
	return NULL;
}
int Class::loadStudents(Static* a) {
	load_classes();
	Class* curStudent = isExist(a);
	if (curStudent == NULL) return 0;
	std::string path = "../Database/Class/" + curStudent->name + "/Students/" + curStudent->name + ".csv";
	if (!input_Student_from_file(curStudent->pHeadListStudents, path)) return 0;
	return 1;
}

//Not data to update pHeadListCLass
bool Class::isInvalid(std::string nameClass) {
	if(nameClass.size() < 5)	
		return true;
	if(nameClass.size() >= 10)	
		return true;
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
	new_Class->pNext = NULL;
	Sort_Class(new_Class);
	std::ofstream fOut;
	fOut.open(("../Database/Class/" + nameClass +"/" + name + "/" + nameClass + ".csv"));
	if (!fOut.is_open()) {
		//std::cout << "Error: Unable to create directory" << std::endl;
		return false;
	}
	fOut << "No,Student - ID,First Name,Last Name,Gender,Date of Birthday,Social ID\n";
	fOut.close();
	print_txt();
	delete new_Class;
	return true;
}

void Class::print_txt() {
	std::ofstream fOut;
	fOut.open("../Database/Class/AllClasses.txt"); //can insert link folder
	if (!fOut.is_open()) {
		//std::cout << "Error! Open file isn't successfull!";
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
	return (gender == "nam" || gender == "Nam" || gender == "Nu" || gender == "nu" || gender == "Male" || gender == "male" || gender == "female" || gender == "Female");
}
int Class::insert_new_Class_keyboard(Static *a, std::string no, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string BirthDay, std::string SocialID){
	Class* new_Class = new Class;

	new_Class->pNext = NULL;
	std::string path = "../Database/Class/" + a->curClass->name + "/Students/" + a->curClass->name + ".csv";
	input_Student_from_file(new_Class->pHeadListStudents, path);
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
	int Day ;
	int Month ;
	int Year;

	if (!checkInputDate(BirthDay, Day, Month, Year)) return 6;


	tmp->dateOfBirth.d = Day;
	tmp->dateOfBirth.m = Month;
	tmp->dateOfBirth.y = Year;
	tmp->socialID = SocialID;
	tmp->firstName = FirstName;
	while (cur && cur->pNext) {
		cur = cur->pNext;
	}
	if (!cur) {
		new_Class->pHeadListStudents = tmp;
	}
	else {
		cur->pNext = new student;
		cur->pNext = tmp;
	}
	
	if (!print_csv(new_Class->pHeadListStudents, a->curClass->name)) return 0;
	delete new_Class;
	delete tmp;
	return 8;
}
int Class::print_csv(student* a, std::string name_Class) {
	std::ofstream fOut;
	fOut.open("../Database/Class/" + name_Class + "/Students/" + name_Class + ".csv");
	//....,std::ios::app
	if (!fOut.is_open()) {
		//std::cout << "Error!\n";
		return 0;
	}
	fOut << "No" << "," << "Student-ID" << "," << "First Name" << "," << "Last Name" << "," << "Gender" << "," << "Date Of Birth" << "," << "" << "Social ID" << "\n";
	while (a) {
		std::string tmpBirthday = "";
		tmpBirthday = tmpBirthday + std::to_string(a->dateOfBirth.d) + "/" + std::to_string(a->dateOfBirth.m) + "/" + std::to_string(a->dateOfBirth.y);
		fOut << std::to_string(a->No) << "," << a->studentID << "," << a->firstName << "," << a->lastName << "," << a->gender << "," << tmpBirthday <<"," << a->socialID << "\n";
		a = a->pNext;
	}
	return 1;
}
//Year !???
bool Class::checkInputDate(std::string& data,int & day,int& month,int& year)
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
	pos++;
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
	day = std::stoi(stringDate);
	month = std::stoi(stringMonth);
	year = std::stoi(stringYear);

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
bool Class::input_for_path(student*& pHeads, std::string path, student *pHeadListStudent) {
	//pHeads->firstName = new_name_Class;
	pHeads = NULL;
	std::ifstream fIn;

	fIn.open(path);
	if (!fIn.is_open()) {
		std::cout << "Error! Enter file again!";
		return false;
	}
	std::string x;
	student* cur = pHeads;
	std::string tmp = "";
	//delete title
	std::getline(fIn, tmp, '\n');

	while (std::getline(fIn, x, ',')) {
		// Allocate memory for a new node
		student* newNode = new student;
		newNode->No = std::stoi(x);

		// Read student information
		std::getline(fIn, newNode->studentID, ',');
		std::getline(fIn, newNode->firstName, ',');
		std::getline(fIn, newNode->lastName, ',');
		std::getline(fIn, newNode->gender, ',');
		std::string tmpDay = "";
		std::string tmpMonth = "";
		std::string tmpYear = "";
		std::getline(fIn, tmpDay, '/');
		newNode->dateOfBirth.d = std::stoi(tmpDay);
		std::getline(fIn, tmpMonth, '/');
		newNode->dateOfBirth.m = std::stoi(tmpMonth);
		std::getline(fIn, tmpYear, ',');
		newNode->dateOfBirth.y = std::stoi(tmpYear);
		std::getline(fIn, newNode->socialID, '\n');
		newNode->pNext = NULL;

		// Update the linked list
		if(check_No(pHeadListStudent, x) == 0) continue;
		if (!pHeads) {
			pHeads = newNode;
		}
		else {
			cur->pNext = new student;
			cur->pNext = newNode;
		}
		cur = newNode;
		
	}
	fIn.close();
	//std::cout << "SUCCESS!\n";
	return true;
}
int Class :: insert_data_Class_from_path(Static* a, std::string path_keyboard) {
	Class* new_Class = new Class;

	new_Class->pNext = NULL;
	std::string path = "../Database/Class/" + a->curClass->name + "/Students/" + a->curClass->name + ".csv";
	input_Student_from_file(new_Class->pHeadListStudents, path);

	student* newStudent ;
	input_for_path(newStudent, path_keyboard, new_Class->pHeadListStudents);


	student * tmpStudent = new_Class->pHeadListStudents;
	if (tmpStudent == NULL) {
		new_Class->pHeadListStudents = newStudent;
		return 1;
	}
	while (tmpStudent->pNext) {
		tmpStudent = tmpStudent->pNext;
	}
	tmpStudent->pNext = newStudent;
	print_csv(new_Class->pHeadListStudents, a->curClass->name);
	delete new_Class;
	return 1;
}
int Class::count_Element(student* a) {
	student* tmp = a;
	int cnt = 0;
	while (tmp) {
		tmp = tmp->pNext;
		cnt ++;
	}
	return cnt;
}
std::string **Class::view_information_Class(Static *a) {
	if(loadStudents(a) == 0) return NULL;
	Class* pHeads = isExist(a);
	student* cur = pHeads->pHeadListStudents;

	int n = count_Element(cur);

	std::string** res = new std::string * [n+1];
	for (int i = 0; i < n+1; i++)
	{
		res[i] = new std::string[7];
	}
	res[0][0] = "No";
	res[0][1] = "Student-ID";
	res[0][2] = "First Name";
	res[0][3] = "Last Name";
	res[0][4] = "Gender";
	res[0][5] = "Date of Birthday";
	res[0][6] = "Social ID";

	for (int i = 1; i < n+1; i++) {
		res[i][0] = std::to_string(cur->No);
		res[i][1] = cur->studentID;
		res[i][2] = cur->firstName;
		res[i][3] = cur->lastName;
		res[i][4] = cur->gender;
		res[i][5] = std::to_string(cur->dateOfBirth.d) + "/" + std::to_string(cur->dateOfBirth.m) + "/" + std::to_string(cur->dateOfBirth.y);
		res[i][6] = cur->socialID;
		cur = cur->pNext;
	}
	return res;
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
			return;
		}
		pre = cur;
		cur = cur->pNext;
	}
	pre->pNext = new_Class;
	//print_txt();
}
Class::~Class() {
	Class* cur = pHeadListClasses;
	while (cur)
	{
		Class* tmp = cur;
		cur = cur->pNext;
		delete tmp;
	}
	student* cur2 = pHeadListStudents;
	while (cur2) {
		student* tmp2 = cur2;
		cur2 = cur2->pNext;
		delete tmp2;
	}
}


/*
* //void Class::print_class_txt() {
//	std::ofstream fOut;
//	fOut.open("class.txt");
//	if (!fOut.is_open()) {
//		std::cout << "Error! Open file isn't successfull!";
//		return;
//	}
//	Class* cur = pHeadListClasses;
//	if (!cur) return;
//	while (cur) {
//		fOut << cur->name << "\n";
//		cur = cur->pNext;
//	}
//	fOut.close();
//}
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