//
//#include "Course.h"
//#include "Student.h"
//#include "Semester.h"
//#include "SchoolYear.h"
//#include "Date.h"
//#include <string>
//#include <fstream>
//#include <stdio.h>
//
// global variables
//schoolYear* pHeadSchoolYear;
//schoolYear* curSchoolYear;
//semester* curSemester;
//Course* curCourse;
//int mid;
//
// Check if it is valid day (not sunday)
//bool isValidWeekday(const std::string& weekday)
//{
//        std::string validWeekdays[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" };
//        for (int i = 0; i < 6; i++) 
//        {
//        if (weekday == validWeekdays[i]) 
//            return true;
//   
//        }
//    return false;
//}
//
// Constructor
//Course::Course(std::string id, std::string name, std::string classname, std::string lecturer, int credit, int maxstudent, std::string weekday, int session)
//{
//    ID = id;
//    Name = name;
//    className = classname;
//    Lecturer = lecturer;
//    Credit = credit;
//    maxStudent = maxstudent;
//
//    if (isValidWeekday(weekday))
//        weekDay = weekday;
//    else
//    {
//        weekDay = "";
//        std::cerr << "Error: Invalid weekday provided for course " << id << std::endl;
//    }
//
//    Session = session;
//}
//
//void Course::updateCourse()
//{
//    {
//        std::ofstream fout;
//        while (true)
//        {
//            std::cout << "Here is the information: " << std::endl;
//            std::cout << "1.Id:" << studentID << std::endl;
//            std::cout << "2.Name:" << Name << std::endl;
//            std::cout << "3.Class name:" << className << std::endl;
//            std::cout << "4.Lecturer:" << Lecturer << std::endl;
//            std::cout << "5.Credit:" << Credit << std::endl;
//            std::cout << "6.Max student:" << maxStudent << std::endl;
//            std::cout << "7.Day performed per week:" << weekDay << std::endl;
//            std::cout << "8. Session: ";
//            switch (Session)
//            {
//            case 1:
//                std::cout << "07:30\n";
//                break;
//            case 2:
//                std::cout << "09:30\n";
//                break;
//            case 3:
//                std::cout << "13:30\n";
//                break;
//            case 4:
//                std::cout << "15:30\n";
//                break;
//            }
//
//            std::cout << "Choose the number you want to edit (Press enter to stop): ";
//            std::string choice;
//            getline(std::cin, choice);
//            if (choice == "") break;
//
//            while (choice <= "0" || choice >= "9" || choice.length() >= 2)
//            {
//                if (choice == "") break;
//                std::cout << "Please input correctly!";
//
//                // To pause the system for 1 second
//
//
//                //Reset
//                std::cout << "                       ";
//                std::cout << "                ";
//                getline(std::cin, choice);
//            }
//
//            int ch = stoi(choice);
//            std::string New;
//            int newNumber;
//            std::cout << "Input the New one:";
//
//            switch (ch)
//            {
//            case 1:
//                getline(std::cin, New);
//                studentID = New;
//                break;
//            case 2:
//                getline(std::cin, New);
//                Name = New;
//                break;
//            case 3:
//                getline(std::cin, New);
//                className = New;
//                break;
//            case 4:
//                getline(std::cin, New);
//                Lecturer = New;
//                break;
//            case 5:
//                std::cin >> newNumber;
//                Credit = newNumber;
//                break;
//            case 6:
//                std::cin >> newNumber;
//                maxStudent = newNumber;
//                break;
//            case 7:
//                getline(std::cin, New);
//                weekDay = New;
//                break;
//            case 8:
//                std::cin >> newNumber;
//                Session = newNumber;
//                break;
//            }
//        }
//        // save course ID to textfile
//        // not done yet
//    }
//}
//
//
