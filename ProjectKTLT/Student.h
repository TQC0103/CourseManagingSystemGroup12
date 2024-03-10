#include <string>
#include "Date.h"

struct student
{
    int No;
    std::string studentID, firstName, lastName, gender, socialID;
    date dateOfBirth;
    struct scoreBoard
    {
        double totalMark;
        double finalMark;
        double midtermMark;
        double otherMark;
        scoreBoard* pNext;
    };
    student* pStudent;
    student* pNext = nullptr;
    //constructor
    student(int no, std::string id, std::string firstname, std::string lastname, std::string gender, date dob, std::string socialId) :
		No(no), studentID(id), firstName(firstname), lastName(lastname), gender(gender),
		dateOfBirth(dob), socialID(socialId){}
};