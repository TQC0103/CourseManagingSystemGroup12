#include "Course.h"
#include "student.h"
#include "semester.h"
#include "schoolyear.h"
#include "date.h"
#include <string>
#include <fstream>

// global variables
schoolYear* pheadschoolyear;
schoolYear* curSchoolyear;
semester* curSemester;
Course* curCourse;


// check if it is valid day (not sunday)
bool isvalidweekday(const std::string& weekday)
{
        std::string validweekdays[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY" };
        for (int i = 0; i < 6; i++) 
        {
        if (weekday == validweekdays[i]) 
            return true;
   
        }
    return false;
}

// constructor
Course::Course(std::string id, std::string name, std::string classname, std::string lecturer, int credit, int maxstudent, std::string weekday, std::string session)
{
    ID = id;
    Name = name;
    className = classname;
    Lecturer = lecturer;
    Credit = credit;
    maxStudent = maxstudent;

    if (isvalidweekday(weekday))
        weekDay = weekday;
    else
    {
        weekday = "";
        std::cerr << "Error: Invalid weekday provided for course " << id << std::endl;
    }

    Session = session;
}

void Course::updateCourse()
{
    {
        std::ofstream fout;
        while (true)
        {
            std::cout << "Here is the information: " << std::endl;
            std::cout << "1. ID:" << ID << std::endl;
            std::cout << "2. Name:" << Name << std::endl;
            std::cout << "3. Class Name:" << className << std::endl;
            std::cout << "4. Lecturer:" << Lecturer << std::endl;
            std::cout << "5. Credit:" << Credit << std::endl;
            std::cout << "6. Max Student:" << maxStudent << std::endl;
            std::cout << "7. Day performed per week:" << weekDay << std::endl;
            std::cout << "8. Session: " << Session << std::endl;
          

            std::cout << "Choose the information (input a number) you want to edit (press enter to stop): ";
            std::string choice;
            getline(std::cin, choice);
            if (choice == "") break;

            while (choice <= "0" || choice >= "9" || choice.length() >= 2)
            {
                if (choice == "") break;
                std::cout << "Please input correctly!";
                std::cout << "                       ";
                std::cout << "                ";
                getline(std::cin, choice);
            }

            int ch = stoi(choice);
            std::string newData;
            int newNumber;
            std::cout << "Input the new one: ";

            switch (ch)
            {
            case 1:
                getline(std::cin, newData);
                ID = newData;
                break;
            case 2:
                getline(std::cin, newData);
                Name = newData;
                break;
            case 3:
                getline(std::cin, newData);
                className = newData;
                break;
            case 4:
                getline(std::cin, newData);
                Lecturer = newData;
                break;
            case 5:
                std::cin >> newNumber;
                Credit = newNumber;
                break;
            case 6:
                std::cin >> newNumber;
                maxStudent = newNumber;
                break;
            case 7:
                getline(std::cin, newData);
                weekDay = newData;
                break;
            case 8:
                std::cin >> newData;
                Session = newData;
                break;
            }
        }
        // save course id to textfile
        // not done yet
    }
}

void Course::loadDataOfTheCourse(Static* a)
{
    std::ifstream fIn;
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name + "/" + "information.txt");

    if (!fIn.is_open())
    {
        std::cerr << "Error: Data is not exist" << std::endl;
        return;
    }

    std::string tmpCourse;
    Course* tmp = nullptr;
    {
        while (getline(fIn, tmpCourse))
        {
        }
    }
