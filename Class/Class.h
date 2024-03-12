#include<iostream>
#include"Student.h"
#include"Class.h"
#include<string>
#include<fstream>
struct Class {
	//Name Class;
	std::string name;

	//Pointer
	Class* pNext;
	student* pHeads;

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
	void Class::show_List_Student_profile(Class* pHead);
	void Class::show_List_Student_scoreboard(Class* pHead);

	/* here or struct student
	void Class::insert_a_Student_Class1st(Class*& pHead);
	void Class::delete_a_Student_Class(Class*& pHead);
	*/

	bool find_Class_of_Student(Class* pHead, std::string ID, std::string& Name_class);  //ponter place which data stored

	//Show for students
	void Class::show_Student_profile(Class* pHead, std::string ID_student);
	void Class::show_Student_scoreboard(Class* pHead, std::string ID_student);
};
static void input_Student_from_file(student*& pHeads, std::string new_name_Class);