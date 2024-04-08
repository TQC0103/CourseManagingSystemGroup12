﻿#include "Student.h"
#include "Class.h"
#include "config.h" 
#include "SchoolYear.h"
#include "Semester.h"

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


std::string student::getCoursesInformations(Static *a)
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
}



std::string* student::loadNumberOfCourses(Static* a)
{
    semester* tmp = new semester;
    int n = tmp->specifyCourseForStudent(a);
    std::string* listOfCourses = new std::string[n];
    std::ifstream file("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/courses.txt");
    if (!file.is_open())
    {
        std::cout << "Unable to open file! \n";
        return nullptr;
    }
    int index = 0;
    std::string courseName;
    while (std::getline(file, courseName))
    {
        std::ifstream fIn("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSchoolYear->pHeadSemester->semesterData + "/" + courseName + "Classes.txt");
        std::string className;
        while (std::getline(fIn, className))
        {
            if (curClass == className)
            {
                if (index < n) // Kiểm tra chỉ số index
                {
                    listOfCourses[index] = courseName;
                    index++;
                }
                else
                {
                    std::cout << "Error: Array index out of bounds!";
                    break;
                }
            }
        }
        fIn.close();
    }
    file.close(); // Đóng tệp
    if (index == 0) {
        delete[] listOfCourses; // Xóa mảng nếu không có phần tử nào được gán giá trị
        return nullptr;
    }
    return listOfCourses;
}




std::string** getAllCoursesInformations(Static* a)
{
    semester* tmp = new semester;
    int n = tmp->specifyCourseForStudent(a);

    // Cấp phát bộ nhớ cho mảng hai chiều
    std::string** res = new std::string * [n];
    for (int i = 0; i < n; i++)
    {
        res[i] = new std::string[8];
    }

    // Nhận danh sách các khóa học mà sinh viên đã đăng ký
    student* myStudent = new student;
    std::string* listOfCourses = myStudent->loadNumberOfCourses(a);
    if (listOfCourses == nullptr) {
        // Nếu danh sách khóa học rỗng, giải phóng bộ nhớ và trả về nullptr
        for (int i = 0; i < n; ++i) {
            delete[] res[i];
        }
        delete[] res;
        return nullptr;
    }

    // Đọc thông tin từ tệp cho mỗi khóa học
    for (int i = 0; i < n; i++)
    {
        std::ifstream fIn("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSchoolYear->pHeadSemester->semesterData + "/" + listOfCourses[i] + "/" + curClass + "/information.txt");
        for (int j = 0; j < 8; j++)
        {
            std::getline(fIn, res[i][j], '\n');
        }
        fIn.close();
    }

    // Giải phóng bộ nhớ của danh sách khóa học
    delete[] listOfCourses;

    return res;
}
