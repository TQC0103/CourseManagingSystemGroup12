#pragma once
#include <string>
#include<fstream>
#include"config.h"

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

	int load_classes(); // load data from files

	bool find_Class_of_Student(Static* a);

	Class* creat_new_Class(std::string path);

	void print_txt();

	//Insert file new class by csv (4) 

	void insert_new_Class(std::string name_Class);

	void print_Student_profile_in_class_files(student* pHeads, std::ofstream& fOut);
	void insert_data_Class(Static* a);
	void export_File(std::string name_Class, std::string path);

	void Sort_Class(Class* new_Class);

	void print_class_txt();

	~Class();
};