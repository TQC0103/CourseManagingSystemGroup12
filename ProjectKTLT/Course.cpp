#include "Course.h"
#include "student.h"
#include "semester.h"
#include "schoolyear.h"
#include "date.h"
#include <string>
#include <fstream>


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

// Update the information of the Course
void Course::updateCourse()
{
    {
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

            while (choice <= "1" || choice > "8" || choice.length() > 1)
            {
                if (choice == "") break;
                std::cerr << "Please input correctly: ";
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
    }
}

// Load data of the Course (Like Course ID, Course Name....)
void Course::loadDataOfTheCourse(Static* a)
{
    std::ifstream fIn;
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name + "/" + "information.txt");

    if (fIn.is_open())
    {
        getline(fIn, a -> curCourse ->ID);
        getline(fIn, a->curCourse -> Name);
        getline(fIn, a->curCourse->className);
        getline(fIn, a->curCourse->Lecturer);
        fIn >> a->curCourse->Credit;
        fIn >> a->curCourse->maxStudent;
        fIn.ignore();
        getline(fIn, a->curCourse->weekDay);
        getline(fIn, a->curCourse->Session);
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
        return;
    }
    fIn.close();
}

// Load the student list in the course
int Course::loadStudentInTheCourse()
{
    int n = 0;
    std::ifstream fIn;
    std::string path = "../Database/Class/" + className + "/Students/" + className + ".csv";
    fIn.open(path);

    if (fIn.is_open())
    {
        std::string redundant;
        getline(fIn, redundant);

        while (!fIn.eof())
        {
            int No;
            std::string studentID, firstName, lastName, gender, socialID;
            fIn >> No;
            getline(fIn, studentID, ',');
            getline(fIn, firstName, ',');
            getline(fIn, lastName, ',');
            getline(fIn, gender, ',');
            getline(fIn, socialID);

            if (!pHeadStudent)
            {
                pHeadStudent = new student(No, studentID, firstName, lastName, gender, socialID);
                pTailStudent = pHeadStudent;
                n++;
            }
            else
            {
                pTailStudent->pNext = new student(No, studentID, firstName, lastName, gender, socialID);
                pTailStudent = pTailStudent->pNext;
                n++;
            }
        }
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
        return -1;
    }

    fIn.close();
    return n;
}

// Option to add student
int Course::addStudentOptions()
{
    std::string choice;
    while (true)
    {
        std::cout << "How do you want to add student?" << std::endl;
        std::cout << "1: Add manually" << std::endl;
        std::cout << "2: By a file" << std::endl;
        std::cout << "3: Go back" << std::endl;

        std::cout << "Choose the way (input a number) you want to add (press enter to stop): ";
        getline(std::cin, choice);

        if (choice == "") break;
        while (choice < "1" || choice > "3" || choice.length() > 1)
        {
            if (choice == "") break;
            std::cerr << "Please input correctly: ";
            getline(std::cin, choice);
        }
        break;
    }

    return stoi(choice);
}

// Add student manually
bool Course::addStudent(Static* a, int choice, int No, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string SocialID)
{
    if (choice == 1)
    {
        std::ifstream fIn;
        fIn.open("../Database/Class/" + a -> curClass -> name + "/Students/" + a->curClass->name + "csv");
        if (!fIn.is_open())
        {
            std::cerr << "Can't open file" << std::endl;
            return false;
        }
        std::string line;
        std::string redundant;

        getline(fIn, redundant);

        while (getline(fIn, line))
        {
            std::stringstream s(line);
            std::string checkID;
            getline(s, checkID, '\t');
            getline(s, checkID, '\t');

            if (checkID == ID)
            {
                std::cerr << "This ID is already exist" << std::endl;
                return false;
            }
        }
        fIn.close();

        // Update the csv file
        std::fstream fOut;
        fOut.open("../ Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name + "/" + "classList.csv", std::ios::app);
        if (!fOut.is_open())
        {
            std::cerr << "Can't open file" << std::endl;
            return false;
        }
        else
        {
            std::string tmp = std::to_string(No) + "," + ID + "," + FirstName + "," + LastName + "," + Gender + "," + SocialID;
            fOut << tmp << std::endl;
        }
      
        fOut.close();
        return true;
    }
}


bool Course::deleteStudent(std::string ID)
{
    for (int i = 0)
}
