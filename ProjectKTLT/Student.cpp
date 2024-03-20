#include "Student.h"
extern std::string usernameStudentInput;
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
        std::cout << "Your profile is not exist";
        return "";
    }
    std::string studentProfile;
    studentProfile += "No: " + std::to_string(No) + "\n";
    studentProfile += "ID: " + studentID +"\n";
    studentProfile += "Name :" + lastName + " " + firstName + "\n";
    studentProfile += "Gender: " + gender + "\n";
    studentProfile += "Social ID : " + socialID + "\n";
    studentProfile += "Date of birth : " + std::to_string(dateOfBirth.d) + "/" + std::to_string(dateOfBirth.m) + "/" + std::to_string(dateOfBirth.y) + "\n";

    return studentProfile;
}

