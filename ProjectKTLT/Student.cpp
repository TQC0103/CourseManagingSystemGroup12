#include "Student.h"
#include "Class.h"
#include "config.h" 
#include "SchoolYear.h"
#include "Semester.h"
#include "Course.h"
#include <iomanip>

void student::loadStudentProfile(std::string username)
{
    std::ifstream file("../Database/Profile/StudentProfile/" + username +".csv");
    if(!file.is_open())
    {
        std::cout <<"Unable to open file! \n";
        return;
    }

    std::string profile;
    if(std::getline(file, profile))
    {
        std::istringstream iss(profile);
        std::string dob;
        std::getline(iss, studentID, ',');
        std::getline(iss, firstName, ',');
        std::getline(iss, lastName, ',');
        std::getline(iss, gender, ',');
        std::getline(iss, dob, ',');
        std::string day, month, year;
        std::istringstream issdob(dob);
        std::getline(issdob, day, '/');
        dateOfBirth.d = stoi(day);
        std::getline(issdob, month, '/');
        dateOfBirth.m = stoi(month);
        std::getline(issdob, year, '/');
        dateOfBirth.y = stoi(year);
        std::getline(iss, socialID, ',');
        std::getline(iss, curClass, ',');

    }
    else
    {
        std::cout << "File is empty!" << std::endl;
    }
    file.close();
}
std::string student::viewStudentProfile()
{
    if (studentID.empty())
    {
        return "Your profile is not exsit";
    }
    std::string studentProfile;
    studentProfile += "ID: " + studentID +"\n";
    studentProfile += "Name: " + lastName + " " + firstName + "\n";
    studentProfile += "Gender: " + gender + "\n";
    studentProfile += "Social ID : " + socialID + "\n";
    studentProfile += "Date of birth : " + std::to_string(dateOfBirth.d) + "/" + std::to_string(dateOfBirth.m) + "/" + std::to_string(dateOfBirth.y) + "\n";
    studentProfile += "Class : " + curClass + "\n";
    return studentProfile;
}






std::string** student::viewAllCoursesInformations(Static* a, int& n)
{
    semester* tmp = new semester;
    n = tmp->specifyCourseForStudentUser(a);
    if (n == 0)
    {
        delete tmp;
        return nullptr;
    }
    Course* cur = tmp->pHeadCourseForStudent;
    std::string** allCourseInformations = new std::string * [n];
    for (int i = 0; i < n; i++)
    {
        allCourseInformations[i] = new std::string[8];
    }

    for (int i = 0; i < n; i++)
    {
        allCourseInformations[i][0] = cur->ID;
        allCourseInformations[i][1] = cur->Name;
        allCourseInformations[i][2] = cur->className;
        allCourseInformations[i][3] = cur->Lecturer;
        allCourseInformations[i][4] = std::to_string(cur->Credit);
        allCourseInformations[i][5] = std::to_string(cur->maxStudent);
        allCourseInformations[i][6] = cur->weekDay;
        allCourseInformations[i][7] = cur->Session;
        cur = cur->pNext;
    }

    delete tmp;
    return allCourseInformations;
}


std::string** student::getStudentScoreBoard(Static* a, int& n)
{
    semester* tmp = new semester;
    n = tmp->specifyCourseForStudentUser(a);
    if (n == 0)
    {
        delete tmp;
        return nullptr;
    }
    Course* cur = tmp->pHeadCourseForStudent;
    std::string** res = new std::string * [n];
    for (int i = 0; i < n; i++)
    {
        res[i] = new std::string[9];
    }

    student* curStudentUser = new student;
    curStudentUser->loadStudentProfile(a->username);
    std::string curClass = curStudentUser->curClass;
    delete curStudentUser;
    
    for (int i = 0; i < n; i++)
    {

        std::ifstream fIn("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + curClass + "/StudentScoreBoard.csv");
        if (!fIn.is_open())
        {
            std::cout << "Can not open file scoreboard.csv of course: " << cur->ID << std::endl;
            for (int j = 0; j < i; ++j)
            {
                delete[] res[j];
            }
            delete[] res;
            delete tmp;
            return nullptr;
        }
        std::string line;
        std::getline(fIn, line);
        while (std::getline(fIn, line))
        {
            std::istringstream iss(line);
            std::string ignore, studentID;
            std::getline(iss, ignore, ',');
            std::getline(iss, studentID, ',');
            if (studentID != a->username) continue;
            res[i][0] = cur->ID;
            res[i][1] = cur->Name;
            res[i][2] = a->username;
            for (int j = 3; j < 8; j++)
            {
                std::getline(iss, res[i][j], ',');
            }
            std::getline(iss, res[i][8], '\n');
            break;
        }
        fIn.close();
        cur = cur->pNext;
    }
    delete tmp;
    return res;
}




void student::dellocate2DArray(std::string** arr, int n)
{
    // Deallocate inner arrays
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }

    // Deallocate outer array
    delete[] arr;
}


