#include "Course.h"
#include "student.h"
#include "semester.h"
#include "schoolyear.h"
#include "date.h"



// check if it is valid day (not sunday)
bool isvalidweekday(const std::string& weekday)
{
    std::string validweekdays[] = { "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
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

// Load data of the Course (Like Course ID, Course Name....)
void Course::loadDataOfTheCourse(Static* a)
{
    std::ifstream fIn;
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "information.txt");

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

// Update the information of the Course
int Course::updateCourse(Static* a, std::string lecturer, std::string weekday, std::string session)
{

    // Can't check these information below
   

    //Capitalise and check the weekDay
    int size = (int)weekday.size();
    for (int i = 0; i < size; i++)
    {
        weekday[i] = std::toupper(weekday[i]);
    }

    if (!isvalidweekday(weekday))
    {
        std::cerr << "Your input is not legal" << std::endl;
        return 7;
    }
    

    // Check Session
    if (session != "7:30" && session != "9:30" && session != "15:30" && session != "13:30")
    {
        std::cerr << "Your input is not legal" << std::endl;
        return 8;
    }
    a->curCourse->weekDay = weekday;
    a->curCourse->Lecturer = lecturer;
    a->curCourse->Session = session;

    //Update the database
    std::fstream fOut;
    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "information.txt");

    if (fOut.is_open())
    {
        fOut << a->curCourse->ID << std::endl;
        fOut << a->curCourse->Name << std::endl;
        fOut << a->curCourse->className << std::endl;
        fOut << a->curCourse->Lecturer << std::endl;
        fOut << a->curCourse->Credit << std::endl;
        fOut << a->curCourse->maxStudent << std::endl;
        fOut << a->curCourse->weekDay << std::endl;
        fOut << a->curCourse->Session << std::endl;
    }
    else
    {
        std::cerr << "Can't open the information.txt file" << std::endl;
        return -1;
    }
    fOut.close();
    return 0;
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
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "classList.csv";
    fIn.open(path);

    if (fIn.is_open())
    {
        std::string line;
        getline(fIn, line); // Skip the headline

        while (getline(fIn, line))
        {
            std::string No, studentID, firstName, lastName, gender, birthday, socialID;
            std::stringstream s(line);
            getline(s, No, ',');
            getline(s, studentID, ',');
            getline(s, firstName, ',');
            getline(s, lastName, ',');
            getline(s, gender, ',');
            getline(s, birthday, ',');
            getline(s, socialID);

            int StudentNo = std::stoi(No);
            date dob = parseDate(birthday);
      

            if (!pHeadStudent)
            {
                pHeadStudent = new student(StudentNo, studentID, firstName, lastName, gender, socialID, dob);
                pTailStudent = pHeadStudent;
                n++;
            }
            else
            {
                pTailStudent->pNext = new student(StudentNo, studentID, firstName, lastName, gender, socialID, dob);
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
    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "classList.csv");
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return false;
    }
    else
    {
        fOut << "No,Student ID,First Name,Last Name,Gender,Date of Birthday,Social ID" << std::endl;
        student* cur = pHeadStudent;
        while (cur)
        {
            std::string dob = formatDate(cur->dateOfBirth);
            std::string tmp = std::to_string(cur->No) + ',' + cur->studentID + ',' + cur->firstName + ',' + cur->lastName + ',' + cur->gender + ',' + dob + ',' + cur->socialID;
            fOut << tmp << std::endl;
            cur = cur->pNext;
        }
        delete cur;
    }

    fOut.close();
    return true;
}

// Add student manually
bool Course::addStudentManually(Static* a, int No, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string birthDay, std::string SocialID)
{
    if (!pHeadStudent)
        loadStudentInTheCourse(a);

    date DOB = parseDate(birthDay);

    student* tmp = new student(No, ID, FirstName, LastName, Gender, SocialID, DOB);
    std::ifstream fIn;
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "classList.csv");
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
            std::cout << FirstName << " " << LastName << " is already exist" << std::endl;
            fIn.close();
            return false;
        }
    }
    fIn.close();

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

        while (tmp)
        {
            // If the current node matches the ID to be deleted
            if (tmp->studentID == ID)
            {
                if (prev)
                    prev->pNext = tmp->pNext;
                else
                    pHeadStudent = tmp->pNext;

                // If the node to be deleted is the tail node
                if (!tmp->pNext)
                    pTailStudent = prev;

                delete tmp;
                // Update the list and file
                normingNumberInStudentList();
                exportStudentListToFile(a);
                return true;
            }
            prev = tmp;
            tmp = tmp->pNext;
        }
        // If the student ID was not found in the list
        return false;
    }
    else
    {
        std::cerr << "There is no student to delete" << std::endl;
        return false;
    }
}

//there is a bug when i try to display the date
bool Course::addStudentbyFile(Static* a, std::string path)
{
    std::fstream fIn;
    fIn.open(path);

    if (!fIn.is_open())
    {
        std::cerr << "Can not open the file" << std::endl;
        return false;
    }

    // Chech if the file is legal or not
    std::string check;
    getline(fIn, check);

    if (check != "No,Student ID,First Name,Last Name,Gender,Date of Birthday,Social ID")
    {
        std::cout << "The header of the file is not correct. Please check the file again" << std::endl;
        fIn.close();
        return false;
    }

    // Check and add each student to the list
    while (getline(fIn, check))
    {
        std::string No, studentID, firstName, lastName, gender, socialID, birthDay;
        std::stringstream s(check);
        getline(s, No, ',');
        getline(s, studentID, ',');
        getline(s, firstName, ',');
        getline(s, lastName, ',');
        getline(s, gender, ',');
        getline(s, birthDay, ',');
        getline(s, socialID);

        int StudentNo = std::stoi(No);

        if (addStudentManually(a, StudentNo, studentID, firstName, lastName, gender, birthDay, socialID))
            std::cout << firstName << " " << lastName << " has been add to the list" << std::endl;

    }
    return true;
    fIn.close();
}

// Export a student list to a "scoreBoard.csv" that don't have mark
bool Course::ExportClass(Static* a)
{
    if (!pHeadStudent)
        loadStudentInTheCourse(a);

    normingNumberInStudentList();
    std::ofstream fOut;

    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "scoreboard.csv");
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return false;
    }
    else
    {
        fOut << "No,Student ID,First Name,Last Name,Midterm Mark,Final Mark,Total Mark,Other Mark" << std::endl;
        student* cur = pHeadStudent;
        while (cur)
        {
            std::string tmp = std::to_string(cur->No) + ',' + cur->studentID + ',' + cur->firstName + ',' + cur->lastName;
            fOut << tmp << std::endl;
            cur = cur->pNext;
        }
    }

    fOut.close();
    return true;
}

//Import a scoreboard file and save it in the database
int Course::ImportScoreboard(Static* a, std::string path)
{
    std::ifstream fIn;
    fIn.open(path);

    if (!fIn.is_open())
    {
        std::cerr << "Can't open the file" << std::endl;
        return 1;
    }

    //Check these information in the file
    std::string check;
    getline(fIn, check);


    if (check != "No,Student ID,Last Name,First Name,Midterm Mark,Final Mark,Total Mark,Other Mark")
    {
        std::cout << "The header of the file is not correct. Please check the file again" << std::endl;
        fIn.close();
        return 2;
    }

    while (getline(fIn, check))
    {
        std::string no, MidtermMark, FinalMark, OtherMark, TotalMark;
        std::stringstream s(check);
        studentScore* cur = new studentScore;
        getline(s, no, ',');
        getline(s, cur->studentID, ',');
        getline(s, cur->firstName, ',');
        getline(s, cur->lastName, ',');
        getline(s, MidtermMark, ',');
        getline(s, FinalMark, ',');
        getline(s, TotalMark, ',');
        getline(s, OtherMark);

        cur->No = std::stoi(no);

        //If the point in the import file is empty, it will display at -1 in the scoreboard.csv
        cur->midtermMark = MidtermMark.empty() ? -1 : std::stod(MidtermMark);
        cur->finalMark = FinalMark.empty() ? -1 : std::stod(FinalMark);
        cur->totalMark = TotalMark.empty() ? -1 : std::stod(TotalMark);
        cur->otherMark = OtherMark.empty() ? -1 : std::stod(OtherMark);

        if (!pHeadScore)
        {
            pHeadScore = cur;
            pTailScore = pHeadScore;
        }
        else
        {
            pTailScore->pNext = cur;
            pTailScore = pTailScore->pNext;
        }
    }
    if (pTailScore)
    {
        pTailScore->pNext = NULL; // Set the pNext pointer of the last studentScore object to NULL
    }
    fIn.close();

    //Update database
    std::ofstream fOut;
    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "StudentScoreBoard.csv");
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }
    else
    {
        fOut << "No,Student ID,First Name,Last Name,Midterm Mark,Final Mark,Total Mark,Other Mark" << std::endl;
        studentScore* cur = pHeadScore;
        while (cur)
        {
            std::string tmp = std::to_string(cur->No) + ',' + cur->studentID + ',' + cur->firstName + ',' + cur->lastName + ',' + std::to_string(cur->midtermMark) + ',' + std::to_string(cur->finalMark) + ',' + std::to_string(cur->totalMark) + ',' + std::to_string(cur->otherMark);
            fOut << tmp << std::endl;
            cur = cur->pNext;
        }
    }

    fOut.close();
    return 0;
}


int Course::addClasstoCourse(Static* a, std::string classname, std::string lecturer, std::string weekday, std::string session)
{
    //Check the className
    std::ifstream fIn;
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/Classes.txt");

    if (!fIn.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return -1;
    }
    std::string checkName;
    while (getline(fIn, checkName))
    {
        if (checkName == classname)
        {
            std::cerr << "This class is already exist" << std::endl;
            fIn.close();
            return 1;
        }
    }
    fIn.close();

    //Check weekday;
    int size = (int)weekday.size();
    for (int i = 0; i < size; i++)
    {
        weekday[i] = std::toupper(weekday[i]);
    }

    if (!isvalidweekday(weekday))
    {
        std::cerr << "Your input is illegal" << std::endl;
        return 3;
    }

    // Check Session
    if (session != "7:30" && session != "9:30" && session != "15:30" && session != "13:30")
    {
        std::cerr << "Your input is illegal" << std::endl;
        return 4;
    }

    //Update the database
    fIn.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a -> curCourse -> ID + "/CommonInfo.txt");
 
    std::string ID, Name;
    int Credit, maxStudent;

    if (fIn.is_open())
    {
        getline(fIn, ID);
        getline(fIn, Name);
        fIn >> Credit;
        fIn >> maxStudent;
    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
        return -1;
    }
    fIn.close();

    std::ofstream fOut;
    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/Classes.txt", std::ios::app);
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return -1;
    }
    fOut << classname << std::endl;
    fOut.close();


    // Make Folder and file
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + classname;
    int makeFile = _mkdir(path.c_str());

    fOut.open(path + "/classList.csv");
    fOut.close();

    fOut.open(path + "/StudentScoreBoard.csv");
    fOut << "No,StudentID,Last Name,First Name,Final,Midterm,Others\n";
    fOut.close();   

    fOut.open(path + "/information.txt");
    {
        fOut << ID << std::endl;
        fOut << Name << std::endl;
        fOut << classname << std::endl;
        fOut << lecturer << std::endl;
        fOut << Credit << std::endl;
        fOut << maxStudent << std::endl;
        fOut << weekday << std::endl;
        fOut << session << std::endl;
    }
    fOut.close();

    return 0;
}

Course::~Course()
{
    student* curS = pHeadStudent;
    while (curS)
    {
		student* next = curS->pNext;
		delete curS;
		curS = next;
	}

    studentScore* cur = pHeadScore;
    while (cur)
    {
        studentScore* next = cur->pNext;
        delete cur;
        cur = next;
    }

    Course* curC = pHeadClasses;
    while (curC)
    {
		Course* next = curC->pNext;
		delete curC;
		curC = next;
	}
}

