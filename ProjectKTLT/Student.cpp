﻿#include "Student.h"
#include "Class.h"
#include "config.h" 
#include "SchoolYear.h"
#include "Semester.h"
#include "Course.h"

std::string curClass;
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
        std::string sNum, dob;
        std::getline(iss, sNum, ',');
        No = stoi(sNum);
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
    studentProfile += "No: " + std::to_string(No) + "\n";
    studentProfile += "ID: " + studentID +"\n";
    studentProfile += "Name: " + lastName + " " + firstName + "\n";
    studentProfile += "Gender: " + gender + "\n";
    studentProfile += "Social ID : " + socialID + "\n";
    studentProfile += "Date of birth : " + std::to_string(dateOfBirth.d) + "/" + std::to_string(dateOfBirth.m) + "/" + std::to_string(dateOfBirth.y) + "\n";
    studentProfile += "Class : " + curClass + "\n";
    return studentProfile;
}

// Hàm này trả về 1 cái string chứ không phải mảng các string tui comment nó để backup thôi 
/*std::string student::getCoursesInformations(Static* a)
{   
    std::string listCourse;
    listCourse += "Your Courses In This Semester : \n";
    std::ifstream file("../Database/SchoolYear/"+a->curSchoolYear->year+"/"+a->curSemester->semesterData+"/courses.txt");
    if(!file.is_open())
    {  
        return "Unable to open file! \n";
    }
    std::string courseName;
    while(std::getline(file, courseName))
    {
        std::ifstream fIn("../Database/SchoolYear/"+ a->curSchoolYear->year +"/"+ a->curSchoolYear->pHeadSemester->semesterData +"/" + courseName + "/Informations.txt");
        std::string courseInformations;
        if(std::getline(fIn, courseInformations))
        {
                std::istringstream iss(courseInformations);
                listCourse += courseInformations + "\n";
        }
        else
        {
            return "File is empty! \n";

        }
        fIn.close();
    }
    file.close();
   
    return listCourse;
}*/
float calculateOverall(float final, float midterm, float other)
{
    int res = final * 0.5 + midterm * 0.2 + other * 0.3;
    return res;
}

std::string student::getAllCoursesInformations(Static* a)
{
    std::ifstream fIn("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + curClass + "/information.txt");
    Course* tmp = new Course;
  
    while(std::getline(fIn, tmp->ID, '\n'))
    {
        std::getline(fIn, tmp->Name,'\n');
        std::getline(fIn, tmp->className, '\n');
        std::getline(fIn, tmp->Lecturer, '\n');
        std::string credit = "";
        std::getline(fIn, credit, '\n');
        tmp->Credit = stoi(credit);
        std::string maxStudent = "";
        tmp->maxStudent = stoi(maxStudent);
        std::getline(fIn, tmp->weekDay, '\n');
        std::getline(fIn, tmp->Session, '\n');

    }
    fIn.close();
    std::string courseInformations = "";
    if (tmp->ID.empty())
    {
        return "Failed to read informations";
    }
    courseInformations += "Course ID: " + tmp->ID + "\n";
    courseInformations += "Course Name: " + tmp->Name + "\n";
    courseInformations += "Class name: " + tmp->className + "\n";
    courseInformations += "Lecturer: " + tmp->Lecturer + "\n";
    courseInformations += "Credit: " + std::to_string(tmp->Credit) + "\n";
    courseInformations += "Max Student: " + std::to_string(tmp->maxStudent) + "\n";
    courseInformations += "Weekly Class Schedule: " + tmp->weekDay + "\n";
    courseInformations += "Start time: " + tmp->Session + "\n";
    return courseInformations;
}


std::string** student::getStudentScoreBoard(Static* a)
{
    semester* tmp = new semester;
    int n = tmp->specifyCourseForStudent(a);
    Course* cur = tmp->pHeadCourseForStudent;
    std::string** res = new std::string * [n];
    for (int i = 0; i < n; i++)
    {
        res[i] = new std::string[9];
    }
    for(int i = 0; i < n; i++)
    {
        std::ifstream fIn("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + cur->ID + "/" + a->curClass->name + "/scoreboard.csv");
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
        for (int j = 0; j < 9; j++)
            while (std::getline(fIn, line))
            {
                std::istringstream iss(line);
                std::string ignore, studentID;
                std::getline(iss, ignore, ',');
                std::getline(iss, studentID, ',');
                if (studentID != a->username) continue;
                res[i][0] = cur->ID;
                for (int j = 1; j < 8; j++)
                {
                    std::getline(iss, res[i][j], ',');
                }
                float overall = calculateOverall(stof(res[i][5]), stof(res[i][6]), stof(res[i][7]));
                res[i][8] = std::to_string(overall);
        fIn.close();
        cur = cur->pNext;
    }
    delete tmp;
    delete cur;
    return res;
    }
}


void student::deallocateListOfCourses(std::string* listOfCourses) 
{
    delete[] listOfCourses;
}


void student::deallocateCourseInformation(std::string** coursesInfo, int n) {
    // Giải phóng từng hàng của mảng hai chiều
    for (int i = 0; i < n; ++i) {
        delete[] coursesInfo[i];
    }
    // Giải phóng mảng chứa con trỏ đến hàng
    delete[] coursesInfo;
}


