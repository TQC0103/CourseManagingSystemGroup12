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

	//DONE 100%

	int load_classes(); // load data from files

	int loadStudents(Static* a);//load student from file

	bool creat_new_Class(std::string nameClass); 

	int insert_new_Class_keyboard(Static* a, std::string no, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string BirthDay, std::string SocialID);
	
	int insert_data_Class_from_path(Static* a, std::string path_keyboard);

	std::string** view_information_Class(Static* a, int &n);

	std::string** view_scoreboard_Student_CLass(Static* a);
	int count_Counrse(Static *a);

	std::string** getaStudentScoreBoard(Static* a, std::string ID_Student, int& n, std::string** res);
	int count_Element(student* a);
	//Read data from files
	bool input_Student_from_file(student*& pHeads, std::string path);
	bool input_for_path(student*& pHeads, std::string path, student* pHeadListStudent);
	
	//creat new file
	Class* isExist(Static* a);

	void print_txt();

	int print_csv(student* a, std::string name_Class);

	//Insert file new class by csv 
	bool checkInputDate(std::string& data, int& day, int& month, int& year);
	
	int check_ID(student* listStudent, std::string ID);

	int check_No(student* listStudent, std::string No);

	bool check_Gender(std::string gender);

	bool isInvalid(std::string nameClass);

	void Sort_Class(Class* new_Class);

	~Class();

	//bool find_Class_of_Student(Static* a);
	//void print_class_txt();

	// l0ad list students len 1 cai class
	// Class *class;
	// class->l0ad(...) => students trg class d0 se dc l0ad len

	//void insert_new_Class(std::string name_Class);

	//void print_Student_profile_in_class_files(student* pHeads, std::ofstream& fOut);
	//void insert_data_Class(Static* a);
	//void export_File(std::string name_Class, std::string path);

};