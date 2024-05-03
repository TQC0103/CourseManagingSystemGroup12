#include "Course.h"
#include "Student.h"
#include "semester.h"
#include "schoolyear.h"
#include "date.h"
#include <iomanip>


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
            getline(s, lastName, ',');
            getline(s, firstName, ',');
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
        return 0;
    }

    fIn.close();
    return n;
}



int Course::loadStudentScoreInTheCourse(Static* a)
{
    int n = 0;
    std::ifstream fIn;
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "StudentScoreBoard.csv";
    fIn.open(path);

    if (fIn.is_open())
    {
        std::string line;
        getline(fIn, line); // Skip the headline

        while (getline(fIn, line))
        {
            std::string No, studentID, firstName, lastName, finalMark, midtermMark, otherMark, totalMark;
            std::stringstream s(line);
            getline(s, No, ',');
            getline(s, studentID, ',');
            getline(s, lastName, ',');
            getline(s, firstName, ',');
            getline(s, finalMark, ',');
            getline(s, midtermMark, ',');
            getline(s, otherMark, ',');
            getline(s, totalMark);

            int StudentNo = std::stoi(No);
            if (!pHeadScore)
            {
                pHeadScore = new studentScore(StudentNo, studentID, firstName, lastName, std::stod(totalMark), std::stod(finalMark), std::stod(midtermMark), std::stod(otherMark));
                pHeadScore->pNext = nullptr;
                pTailScore = pHeadScore;
                n++;
            }
            else
            {
                studentScore* tmpScore = new studentScore(StudentNo, studentID, firstName, lastName, std::stod(totalMark), std::stod(finalMark), std::stod(midtermMark), std::stod(otherMark));
                tmpScore->pNext = nullptr;
                pTailScore->pNext = tmpScore;
                pTailScore = tmpScore;
                n++;
            }
        }
        if (pTailScore)
        {
			pTailScore->pNext = nullptr;
		}

    }
    else
    {
        std::cerr << "Can't open file" << std::endl;
        return 0;
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

// Export student list to a file
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
        fOut << "No,Student ID,Last Name,First Name,Gender,Date Of Birth,Social ID" << std::endl;
        student* cur = pHeadStudent;
        while (cur)
        {
            std::string dob = formatDate(cur->dateOfBirth);
            std::string tmp = std::to_string(cur->No) + ',' + cur->studentID + ',' + cur->lastName + ',' + cur->firstName + ',' + cur->gender + ',' + dob + ',' + cur->socialID;
            fOut << tmp << std::endl;
            cur = cur->pNext;
        }
        delete cur;
    }

    fOut.close();
    return true;
}

// Add student manually
bool Course::addStudentManually(Static* a, std::string ID, std::string FirstName, std::string LastName, std::string Gender, std::string birthDay, std::string SocialID)
{
    if (!pHeadStudent)
        loadStudentInTheCourse(a);

    date DOB = parseDate(birthDay);

    student* tmp = new student(0, ID, FirstName, LastName, Gender, SocialID, DOB);
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
    
int Course::deleteStudent(Static* a, std::string ID)
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
                return 0;
            }
            prev = tmp;
            tmp = tmp->pNext;
        }
        // If the student ID was not found in the list
        return 2;
    }
    else
    {
        std::cerr << "There is no student to delete" << std::endl;
        return 1;
    }
}

//there is a bug when i try to display the date
int Course::addStudentbyFile(Static* a, std::string path)
{
    std::fstream fIn;
    fIn.open(path);

    if (!fIn.is_open())
    {
        fIn.close();
        return 1;
    }

    // Chech if the file is legal or not
    std::string check;
    getline(fIn, check);

    if (check != "No,Student ID,Last Name,First Name,Gender,Date Of Birth,Social ID")
    {
        fIn.close();
        return 2;
    }

    // Check and add each student to the list
    while (getline(fIn, check))
    {
        std::string No, studentID, firstName, lastName, gender, socialID, birthDay;
        std::stringstream s(check);
        getline(s, No, ',');
        getline(s, studentID, ',');
        getline(s, lastName, ',');
        getline(s, firstName, ',');
        getline(s, gender, ',');
        getline(s, birthDay, ',');
        getline(s, socialID);

        int StudentNo = std::stoi(No);

        if (addStudentManually(a, studentID, firstName, lastName, gender, birthDay, socialID))
            std::cout << lastName << " " << firstName << " " << " has been add to the list" << std::endl;

    }
    return 0;
    fIn.close();
}

// Export a student list to a "StudentScoreBoard.csv" that don't have mark
bool Course::ExportClass(Static* a, std::string filename)
{
  
    int n = loadStudentInTheCourse(a);

    normingNumberInStudentList();
    std::ofstream fOut;

    fOut.open(filename);
    if (!fOut.is_open())
    {
        std::cerr << "Can't open file" << std::endl;
        return false;
    }
    else
    {
        fOut << "No,Student ID,Last Name,First Name,Final,Midterm,Others,Overall" << std::endl;
        student* cur = pHeadStudent;
        while (cur)
        {
            std::string tmp = std::to_string(cur->No) + ',' + cur->studentID + ',' + cur->lastName + ',' + cur->firstName + ",,,,";
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


    if (check != "No,Student ID,Last Name,First Name,Final,Midterm,Others,Overall")
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
        getline(s, cur->lastName, ',');
        getline(s, cur->firstName, ',');
        getline(s, FinalMark, ',');
        getline(s, MidtermMark, ',');
        getline(s, OtherMark, ',');
        getline(s, TotalMark);

        cur->No = std::stoi(no);

        //If the point in the import file is empty, it will display at -1 in the scoreboard.csv
        cur->midtermMark = MidtermMark.empty() ? -1 : std::stod(MidtermMark);
        cur->finalMark = FinalMark.empty() ? -1 : std::stod(FinalMark);
        cur->otherMark = OtherMark.empty() ? -1 : std::stod(OtherMark);
        cur->totalMark = TotalMark.empty() ? -1 : std::stod(TotalMark);


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
        fOut << "No,Student ID,Last Name,First Name,Final,Midterm,Others,Overall" << std::endl;
        studentScore* cur = pHeadScore;
        while (cur)
        {
            fOut << cur->No << ',' << cur->studentID << ',' << cur->lastName << ',' << cur->firstName << ','
                << std::fixed << std::setprecision(2) << cur->finalMark << ',' << cur->midtermMark << ','
                << cur->otherMark << ',' << cur->totalMark << std::endl;
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


    // Create Folder and file
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + classname;
    int makeFile = _mkdir(path.c_str());

    fOut.open(path + "/classList.csv");
    fOut.close();

    fOut.open(path + "/StudentScoreBoard.csv");
    fOut << "No,StudentID,Last Name,First Name,Final,Midterm,Others,Overall\n";
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


std::string** Course::viewAllStudentsInACourse(Static* a, int &n)
{
    Course* tmp = new Course;
    n = tmp->loadStudentInTheCourse(a);
    if (n == 0)
    {
        delete tmp;
        return nullptr;
    }
    student* cur = tmp->pHeadStudent;
    std::string** allStudents = new std::string * [n];

    for (int i = 0; i < n; i++)
    {
        allStudents[i] = new std::string[7];
    }

    for (int i = 0; i < n; i++)
    {
        allStudents[i][0] = std::to_string(cur->No);
        allStudents[i][1] = cur->studentID;
        allStudents[i][2] = cur->lastName;
        allStudents[i][3] = cur->firstName;
        allStudents[i][4] = cur->gender;
        allStudents[i][5] = formatDate(cur->dateOfBirth);
        allStudents[i][6] = cur->socialID;
        cur = cur->pNext;
    }

    delete tmp;
    return allStudents;
}


std::string** Course::viewAllStudentsScoreInACourse(Static* a, int &n)
{
    Course* tmp = new Course;
    n = tmp->loadStudentScoreInTheCourse(a);
    if (n == 0)
    {
        delete tmp;
        return nullptr;
    }
    studentScore* cur = tmp->pHeadScore;
    std::string** allStudentsScore = new std::string* [n];

    for (int i = 0; i < n; i++)
    {
        allStudentsScore[i] = new std::string[8];
    }


    for (int i = 0; i < n; i++)
    {
        allStudentsScore[i][0] = std::to_string(cur->No);
        allStudentsScore[i][1] = cur->studentID;
        allStudentsScore[i][2] = cur->lastName;
        allStudentsScore[i][3] = cur->firstName;
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2) << cur->finalMark;
        allStudentsScore[i][4] = ss.str();

        ss.str(std::string()); // Clear the stringstream
        ss << std::fixed << std::setprecision(2) << cur->midtermMark;
        allStudentsScore[i][5] = ss.str();

        ss.str(std::string()); // Clear the stringstream
        ss << std::fixed << std::setprecision(2) << cur->otherMark;
        allStudentsScore[i][6] = ss.str();
        std::ostringstream streamObj;
        streamObj << std::fixed << std::setprecision(2) << cur->totalMark;
        allStudentsScore[i][7] = streamObj.str();
        cur = cur->pNext;
    }

    delete tmp;
    return allStudentsScore;
}

// Update the score
int Course::updateStudentResult(Static* a, std::string ID, std::string midterm, std::string final, std::string total, std::string others)
{
    // Load the score list
    if (!pHeadScore)
        loadStudentScoreInTheCourse(a);

    // Check the ID
    studentScore* tmp = pHeadScore;
    bool flag = false;
    while (tmp)
    {
        if (tmp->studentID == ID)
        {
            flag = true;
            break;
        }
        tmp = tmp->pNext;
    }

    if (flag == false)
    {
        std::cerr << "Student ID is not exist\n";
        return 1;
    }

    double Midterm, Final, Others, Total;

    // If the input was empty, the result would not be changed 
    try {
        Midterm = midterm.empty() ? tmp->midtermMark : std::stod(midterm);
        Final = final.empty() ? tmp->finalMark : std::stod(final);
        Others = others.empty() ? tmp->otherMark : std::stod(others);
        Total = total.empty() ? tmp->finalMark : std::stod(total);
    }
    catch (std::invalid_argument&) {
        std::cerr << "Invalid score input. Scores must be numeric." << std::endl;
        return 2; // Return an error code
    }
    catch (std::out_of_range&) {
        std::cerr << "Score input is out of range." << std::endl;
        return 2; // Return an error code
    }

    // Check the score
    if (Final > 10.0 || Final < 0.0)
    {
        return 2;
    }

    if (Midterm > 10.0 || Midterm < 0.0)
    {
        return 2;
    }

    if (Others > 10.00 || Others < 0.0)
    {
        return 2;
    }

    if (Total > 10.00 || Total < 0.0)
    {
        return 2;
    }

    tmp->midtermMark = Midterm;
    tmp->finalMark = Final;
    tmp->otherMark = Others;
    tmp->totalMark = Total;

    //Update the database
    std::ofstream fOut;
    fOut.open("../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + a->curCourse->className + "/" + "StudentScoreBoard.csv");

    if (!fOut.is_open())
    {
        std::cerr << "Can't open the file" << std::endl;
        return -1;
    }
    else
    {
        fOut << "No,Student ID,Last Name,First Name,Final,Midterm,Others,Overall" << std::endl;
        studentScore* cur = pHeadScore;
        while (cur)
        {
            fOut << cur->No << ',' << cur->studentID << ',' << cur->lastName << ',' << cur->firstName << ','
                << std::fixed << std::setprecision(2) << cur->finalMark << ',' << cur->midtermMark << ','
                << cur->otherMark << ',' << cur->totalMark << std::endl;
            cur = cur->pNext;
        }
    }

    fOut.close();
    return 0;
}


bool Course::deleteClass(Static* a, std::string classname)
{
    std::ifstream fIn;
    std::string path = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/Classes.txt";
    fIn.open(path);

    if (!fIn.is_open())
    {
        std::cerr << "Can't open input file" << std::endl;
        return false;
    }

    //Open a temporary file to copy the content from the original file
    std::ofstream fOut;
    std::string tmpPath = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/Classes_tmp.txt";
    fOut.open(tmpPath);
    if (!fOut.is_open())
    {
        std::cerr << "Can't open output file" << std::endl;
        return false;
    }
    
    bool found = false;
    std::string ClassName;
   
    // Check the classname and copy the content to another file
    while (getline(fIn, ClassName))
    {
        if (ClassName == classname)
        {
            found = true;
            continue;
        }
        fOut << ClassName << std::endl;
    }
    fIn.close();
    fOut.close();

    //Remove the orginal file and rename the temporary file to the original
    if (std::remove(path.c_str()) != 0)
    {
        std::cerr << "Error deleting original file" << std::endl;
        return false;
    }

    if (std::rename(tmpPath.c_str(), path.c_str()) != 0)
    {
        std::cerr << "Error renaming temporary file" << std::endl;
        return false;
    }

    // Return if the classname was not exist
    if (found == false)
    {
        std::cout << "Error: The class \"" << classname << "\" does not exist." << std::endl;
        return false;
    }


    // Move the Class Folder to the Deleted Folder
    std::string source = "../Database/SchoolYear/" + a->curSchoolYear->year + "/" + a->curSemester->semesterData + "/" + a->curCourse->ID + "/" + classname;
    std::string destination = "../Rubbish/" + classname;

    std::string originalDestination = destination;
    int count = 1;
    while (std::rename(source.c_str(), originalDestination.c_str()) != 0)
    {

        // Append a number to make it unique
        std::ostringstream oss;
        oss << destination << " (" << count << ")";
        originalDestination = oss.str();
        count++;
    }
    return true;
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



