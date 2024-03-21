#pragma once
#include <string>
#include "Student.h"
#include<fstream>
struct Class {
	//Name Class;
	std::string name;

	//Pointer
	Class* pNext = nullptr;
	//List students
	student* pHeads = nullptr;

	//Constructor
	Class(){}

	//Fuction
	// data start
	void load_Files(Class*& pHead, std::string path);
	void delete_Class(Class *&pHead); // delete Poiter;

	// interate with class of staff
	void insert_new_Class(Class*& pHead);
	void delete_Class(Class*& pHead, std::string name_class);
	void export_File(Class* pHead, std::string name_Class, std::string path);
	void show_List_Class(Class* pHead); // show for staff
	void print_Student_profile_in_class(student* pHeads);
	void show_List_Student_profile(Class* pHead, std::string name_class);
	void print_Student_scoreboard_in_class(student* pHeads);
	void show_List_Student_scoreboard(Class* pHead, std::string name_class);
	void export_File_score(Class* pHead, std::string name_Class, std::string path);


	void Class::insert_a_Student_Class1st(Class*& pHead);
	void Class::delete_a_Student_Class(Class*& pHead);
	void print_txt(Class* pHead, std::string AllClasses);


	bool find_Class_of_Student(Class* pHead, std::string ID, std::string& Name_class); //ponter place which data stored

	//Show for students
	void print_Student_profile_in_class_files(student* pHeads, std::ofstream&fOut);
	void show_Student_each_profile(Class* pHead, std::string ID_student);
	void show_Student_each_scoreboard(Class* pHead, std::string ID_student);
	void Sort_Class(Class*& pHead, Class* new_Class);
	void print_class_txt(Class* pHead);

};
static void input_Student_from_file(student*& pHeads, std::string new_name_Class);
static Class* creat_new_Class(std::string path);

void Delete_aCLass(Class*& aclass);