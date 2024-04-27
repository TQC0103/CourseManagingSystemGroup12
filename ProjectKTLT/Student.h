#pragma once
#include <string>
#include "Date.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include "config.h"

struct schoolYear;
struct student
{
    int No;
    std::string studentID = "", firstName = "", lastName = "", gender = "", socialID = "";
    date dateOfBirth;
    student* pNext = nullptr;
    std::string curClass;
  
    //constructor
    student() {
        No = 0;
		studentID = "";
		firstName = "";
		lastName = "";
        //dateOfBirth = {1,1,0};
    }
    student(int no, std::string id, std::string firstname, std::string lastname, std::string gender, std::string socialId,  date dob) :
        No(no), studentID(id), firstName(firstname), lastName(lastname), gender(gender), socialID(socialId), dateOfBirth(dob){}
    
    //functions 
    void loadStudentProfile(std::string username); // done
    std::string viewStudentProfile(); // done
    std::string** viewAllCoursesInformations(Static* a, int &n); // done
    double calculateOverall(double final, double midterm, double other);//support function
    std::string** getStudentScoreBoard(Static* a, int& n); // done
    void dellocate2DArray(std::string** arr, int n);

};