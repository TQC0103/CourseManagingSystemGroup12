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
	Course* pHeadListCourses = nullptr;

	//Constructor
	Class();

	//Fuction
	// data start
	//Read data from files
	void input_Student_from_file(student*& pHeads, std::string new_name_Class);

	int load_classes(); // load data from files

	bool find_Class_of_Student(Static* a);

	int insert_new_Class_keyboard(Static* a, std::string no, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string BirthDay, std::string SocialID);
	int insert_data_Class_from_path(Static* a, std::string path_keyboard);

	bool creat_new_Class(std::string nameClass);


	void print_txt();
	int loadStudents(Static* a);
	bool isExist(Static* a, Class*& cur);
	int print_csv(student* a, std::string name_Class);
	//Insert file new class by csv (4) 
	bool checkInputDate(std::string& data);
	int check_ID(student* listStudent, std::string ID);
	int check_No(student* listStudent, std::string No);
	bool check_Gender(std::string gender);

	// l0ad list students len 1 cai class
	// Class *class;
	// class->l0ad(...) => students trg class d0 se dc l0ad len

	//void insert_new_Class(std::string name_Class);

	//void print_Student_profile_in_class_files(student* pHeads, std::ofstream& fOut);
	//void insert_data_Class(Static* a);
	//void export_File(std::string name_Class, std::string path);
	bool isInvalid(std::string nameClass);
	void Sort_Class(Class* new_Class);

	void print_class_txt();

	~Class();
};