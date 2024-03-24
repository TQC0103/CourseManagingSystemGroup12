#pragma once
#include <string>
#include "Date.h"
#include <fstream>
#include <iostream>
#include <sstream>

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

  
    //constructor
    student() {
    }
    student(int no, std::string id, std::string firstname, std::string lastname, std::string gender, std::string socialId,  date dob) :
        No(no), studentID(id), firstName(firstname), lastName(lastname), gender(gender), socialID(socialId), dateOfBirth(dob){}
    
    //functions 
    void loadStudentProfile(std::string username);
    std::string viewStudentProfile();
    //void readStudentScore();
};