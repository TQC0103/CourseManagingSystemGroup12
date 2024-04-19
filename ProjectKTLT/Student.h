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
    struct scoreBoard
    {
        double totalMark;
        double finalMark;
        double midtermMark;
        double otherMark;
        scoreBoard* pNext;
    };
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
    float calculateOverall(float final, float midterm, float other);//support function
<<<<<<< HEAD
    std::string** getStudentScoreBoard(Static* a, int& n); // done
=======
    std::string** getStudentScoreBoard(Static* a, int &n); // done
>>>>>>> d0c9241918d984beacc6a6a46d7817f25cc0b984
    void dellocate2DArray(std::string** arr, int n);

};