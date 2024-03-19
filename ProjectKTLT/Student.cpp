#include "Student.h"
extern std::string usernameStudentInput;
void student::loadStudentProfile()
{
    std::cout <<"Input your username : ";
    std::string username;
    std::getline(std::cin, username);
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

    }
    else
    {
        std::cout << "File is empty!" << std::endl;
    }
    file.close();
}
void student::viewStudentProfile()
{
    if(studentID.empty())
    {
        std::cout <<"Your profile is not exsit";
        return;
    }
    std::cout << "Student Profile: \n";
    std::cout << "No: " << No << std::endl;
    std::cout << "ID: " << studentID << std::endl;
    std::cout << "Name :" << lastName << " " << firstName << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Social ID : " << socialID << std::endl;
    std::cout << "Date of birth : " << dateOfBirth.d << "/" << dateOfBirth.m <<"/" << dateOfBirth.y << std::endl; 
}


