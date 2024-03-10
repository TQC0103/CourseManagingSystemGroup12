#include<iostream>
#include"Student.h"
#include"Class.h"
#include<string>
#include<fstream>
struct Class {
	//Name Class;
	std::string name;
	
	//Pointer
	Class *pNext;
	student *pHeads;

	//Constructor
	Class::Class();

	//Fuction
	// data start
	void Class::load_Files(Class*& pHead);
	void Class::delete_Class(Class* pHead); // delete Poiter;

	// interate with class of staff
	void Class::insert_new_Class(Class*& pHead);
	void Class::delete_Class(Class*& pHead, std::string name_class);
	void Class::export_File(Clas* pHead, std::string name_Class, std::string path);
	void Class::show_List_Class(Class* pHead); // show for staff
	void Class::show_List_Student_profile(Class *pHead);
	void Class::show_List_Student_scoreboard(Class *pHead);

	/* here or struct student
	void Class::insert_a_Student_Class1st(Class*& pHead);
	void Class::delete_a_Student_Class(Class*& pHead);
	*/

	std::string find_Class_of_Student(Class* pHead, std::string ID); //ponter place which data stored
	
	//Show for students
	void Class::show_Student_profile(Class *pHead, std::string ID_student);
	void Class::show_Student_scoreboard(Class *pHead, std::string ID_student);
};
//Constructor
Class::Class(){
	Class* pHead = NULL;
}

//Read data from files
static void input_Student_from_file(student *&pHeads, std::string new_name_Class) {
	pHeads -> firstName = new_name_Class;
	std::ifstream fIn;
	fIn.open(new_name_Class);
	if (!fIn.is_open()) {
		std::cout << "Please, Enter file again!";
		return;
	}
	int x;
	student* cur = pHeads;
	while (fIn >> x) {
		pHeads -> No = x;
		if (!pHeads) {
			pHeads = new student;
			cur = pHeads;
		}
		else{
			cur->pNext = new student;
			cur = cur-> pNext;
		}
		pHead->pNext = NULL;
		std::cin.ignore(1);
		std::getline(fIn, cur->socialID, ';');
		std::getline(fIn, cur->firstName, ';');
		std::getline(fIn, cur->gender, ';');
		std::getline(fIn, cur->dateOfBirth, ';');
		std::getline(fIn, cur->socialID, ';');
	}
}
void Class::load_Files(Class*& pHead) {
	//load File when open program;
}
void Class::delete_Class(Class* pHead) {
	//Delete poiter;
}
void Class::show_List_Student_profile(Class* pHead) {

}
void Class::show_List_Student_scoreboard(Class* pHead) {

}
/* here or struct student
void Class::insert_a_Student_Class1st(Class*& pHead);
void Class::delete_a_Student_Class(Class*& pHead);
*/
std::string Class::find_Class_of_Student(Class* pHead, std::string ID)
{
	return std::string();
}

void Class::show_Student_profile(Class* pHead, std::string ID_student){}
void Class::show_Student_scoreboard(Class* pHead, std::string ID_student){}


static Class* creat_new_Class() {
	Class* new_Class = new Class;
	student pnewHead = new_Class->pHead;
	input_Student_from_file(pnewHead);
	new_Class->pNext = NULL;
	return new_Class;
}
void Class::insert_new_Class(Class*& pHead) {
	//insert class into linked list;
	//update file into data
	//update all.txt
}

void Class::delete_Class(Class *&pHead, std::string name_class)
{
	// delete class from linked list
	//delete class from data
	//delete class from all.txt
}

void Class::export_File(Clas* pHead, std::string name_Class, std::string path)
{
	//Data printed file 
}
void Class::show_List_Class(Class* pHead)
{
}
// sort file name follow name in data, all.txt;

void Class::show_List_Class(Class* pHead) {
}