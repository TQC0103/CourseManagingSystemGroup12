#pragma once
#include <string>
#include "Student.h"
#include<fstream>

struct student;
struct Class {
	//Name Class;
	std::string name;

	//Pointer
	Class* pNext = nullptr;
	Class* pHeadListClasses = nullptr;

	//List students
	student* pHeadListStudents = nullptr;

	//Constructor
	Class();

	//Fuction
	// data start
	//Read data from files
	void input_Student_from_file(student*& pHeads, std::string new_name_Class);
	int load_classes() ; // load data from files
	void delete_Class(Class*& pHead);
	void print_Student_profile_in_class(student* pHeads);
	//view profile student in class.(16)
	void view_List_Student_profile(Class* pHead, std::string name_class);
	void print_Student_scoreboard_in_class(student* pHeads);
	void show_List_Student_scoreboard(Class* pHead, std::string name_class);
	/* here or struct student
	void Class::insert_a_Student_Class1st(Class*& pHead);
	void Class::delete_a_Student_Class(Class*& pHead);
	*/
	bool find_Class_of_Student(Class* pHead, std::string ID, std::string& Name_class);

	void show_Student_each_profile(Class* pHead, std::string ID_student);

	Class* creat_new_Class(std::string path);
	void print_txt(Class* pHead);
	//Insert file new class by csv (4) 
	void insert_new_Class(Class*& pHead, std::string name_Class);
	void print_Student_profile_in_class_files(student* pHeads, std::ofstream& fOut);
	void export_File(Class* pHead, std::string name_Class, std::string path);
	void print_txt();
	void show_Student_each_scoreboard(Class* pHead, std::string ID_student) {}
	void export_File_score(Class* pHead, std::string name_Class, std::string path) {}
	// Show list last(15)
	void show_List_Class(Class* pHead);
	// sort file name follow name in data, all.txt;
	void Sort_Class(Class*& pHead, Class* new_Class);
	void print_class_txt(Class* pHead);
	~Class();
};
//Q: why error when i use Class* pHeadListClasses = nullptr; in Class.h
//A: Because you have already declared pHeadListClasses in Class struct, so you can't declare it again in Class.cpp