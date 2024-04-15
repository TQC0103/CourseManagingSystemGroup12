#include "Course.h"
#include "student.h"
#include "semester.h"
#include "schoolyear.h"
#include "date.h"
#include <string>
#include <fstream>
#include <sstream>
#include "config.h"


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



int Course::loadClassesInCourse(Static* a)
{
    std::ifstream fin;
    fin.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + "Classes.txt");
   
    Course* cur = pHeadClasses;
    int nClass = 0;
    std::string ClassData = "";
    while (getline(fin, ClassData))
    {
        if (!pHeadClasses)
        {
            pHeadClasses = new Course;
            cur = pHeadClasses;
            cur->className = ClassData;
        }
        else {
            cur->pNext = new Course;
            cur = cur->pNext;
            cur->className = ClassData;
        }
        nClass++;
    }
    if (cur)
    {
        cur->pNext = nullptr;
    }
    return nClass;

}

// Load the student list in the course
int Course::loadStudentInTheCourse(Static* a)
{
    int n = 0;
    std::ifstream fIn;
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name +"/classlist.csv";
    fIn.open(path);

    if (fIn.is_open())
    {
        std::string line;
        getline(fIn, line); // Skip the headline

        while (getline(fIn, line))
        {
            std::string No, studentID, firstName, lastName, gender, socialID;
            std::stringstream s(line);
            getline(s, No, ',');
            getline(s, studentID, ',');
            getline(s, firstName, ',');
            getline(s, lastName, ',');
            getline(s, gender, ',');
            getline(s, socialID);

            int StudentNo = std::stoi(No);
            if (!pHeadStudent)
            {
                pHeadStudent = new student(StudentNo, studentID, firstName, lastName, gender, socialID);
                pTailStudent = pHeadStudent;
                n++;
            }
            else
            {
                pTailStudent->pNext = new student(StudentNo, studentID, firstName, lastName, gender, socialID);
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

void Course::normingNumberInStudentList()
{
    student* tmp = pHeadStudent;

    int i = 1;
    while(tmp)
    {
        tmp->No = i;
        tmp = tmp->pNext;
        i++;
    }

    delete tmp;

}
// Delete the last student in the linked list
//void Course::deleteStudentAfterSort(student* prev)
//{
//    student* cur = prev->pNext;
//   while (cur && cur->pNext)
//   {
//        prev = cur;
//        cur = cur->pNext;
//   }
//    prev->pNext = nullptr;
//    pTailStudent = prev;
//    student* tmp = pHeadStudent;
//
//    for (int i = 1; tmp; i++)
//   {
//        tmp->No = i;
//       tmp = tmp->pNext;
//    }
//
//    delete cur;
//   delete tmp;
//}

void Course::sortStudentList(student* tmp)
{
    // If the list is empty or the new student's ID is less than the head student's ID
    if (!pHeadStudent || tmp->studentID < pHeadStudent->studentID)
    {
        tmp->pNext = pHeadStudent;
        pHeadStudent = tmp;
    }
    else
    {
        // Locate the node before the point of insertion
        student* cur = pHeadStudent;
        while (cur->pNext != nullptr && cur->pNext->studentID < tmp->studentID)
        {
            cur = cur->pNext;
        }
        tmp->pNext = cur->pNext;
        cur->pNext = tmp;

        // If the new node is inserted at the end of the list, update the tail pointer
        if (tmp->pNext == nullptr)
        {
            pTailStudent = tmp;
        }
    }
}


bool Course::exportStudentListToFile(Static* a)
{
    std::ofstream fOut;
    fOut.open("../ Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name + "/" + "classList.csv");
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return false;
    }
    else
    { 
        fOut << "No,Student - ID,First Name,Last Name,Gender,Social ID" << std::endl;
        student* cur = pHeadStudent;
        while (cur)
        {
            std::string tmp = std::to_string(cur->No) + "," + cur->studentID + "," + cur->firstName + "," + cur->lastName + "," + cur->gender + "," + cur->socialID;
            fOut << tmp << std::endl;
            cur = cur->pNext;
        }
        delete cur;
    }

    fOut.close();
    return true;
}

// Add student manually
bool Course::addStudentManually(Static* a, int No, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string SocialID)
{
    if (!pHeadStudent)
        loadStudentInTheCourse(a);

    student* tmp = new student(No, ID, FirstName, LastName, Gender, SocialID);
    if (pHeadStudent)
    {
        std::ifstream fIn;
        fIn.open("../ Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curClass->name + "/" + "classList.csv");
        if (!fIn.is_open())
        {
            std::cerr << "Can't open file" << std::endl;
            return false;
        }
        std::string line;

        getline(fIn, line);

        while (getline(fIn, line))
        {
            std::stringstream s(line);
            std::string checkID;
            getline(s, checkID, ',');
            getline(s, checkID, ',');

            if (checkID == ID)
            {
                std::cerr << "This ID is already exist" << std::endl;
                fIn.close();
                return false;
            }
        }
        fIn.close();

        student* tmp = new student(No, ID, FirstName, LastName, Gender, SocialID);

        // Update the linked list

        sortStudentList(tmp);
        normingNumberInStudentList();

        // Update the csv file
        exportStudentListToFile(a);
        return true;
    }
    
bool Course::deleteStudent(Static* a, std::string ID)
{
    if (!pHeadStudent)
        loadStudentInTheCourse(a);
    if (pHeadStudent)
    {
        student* tmp = pHeadStudent;
        student* prev = nullptr;

        if (tmp->studentID == ID)
        {
            pHeadStudent = tmp->pNext;
            delete tmp;
            return true;
        }

        while (tmp)
        {
            if (tmp->studentID == ID)
            {
                prev->pNext = tmp->pNext;
                delete tmp;
                tmp = nullptr;

                //Update the database;
                normingNumberInStudentList();
                exportStudentListToFile(a);
                return true;
            }
            prev = tmp;
            tmp = tmp->pNext;
        }
        return false;
    }
    else
    {
        std::cerr << "There is no student to delete" << std::endl;
        return false;
    }
}