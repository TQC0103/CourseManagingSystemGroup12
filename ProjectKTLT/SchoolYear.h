#pragma once
#include<string>
#include "Semester.h"
#include "config.h"


struct schoolYear {
	schoolYear();
	schoolYear(std::string yearData);
	std::string year;

	schoolYear* pHead = nullptr;
	schoolYear* pNext = nullptr;

	// User Experience	
	void loadSchoolYear();// done
	
	bool addSchoolYear();// done
	// After add, staff can choose to move to the next school year now or later
	//void movetoNextSchoolYear(); // done
	
	bool checkInputYear(std::string &data); // done

	//bool findCurrentSchoolYear(std::string data); // done
	
	// User Interface

	//void viewSchoolYear(); // UI (later)
		
	// SEMESTER IN A SCHOOL YEAR
	// // // // // 
	// // // // //

	semester* pHeadSemester = nullptr;
	
	void loadSemester(std::string& year); // done
	
	// Data must be like (Semester1) not (1)
	//bool findCurrentSemester(std::string data); // done

	// Instruction: Input of data must be like Semester1, Semester2, Semester3. If the input is 1, 2, 3, you must convert it to Semester1, Semester2, Semester3
	bool addSemester(std::string data, std::string start, std::string end, Static *a);// done
	
	bool checkInputDate(std::string &data, Static *a); // done


	// Deallocate
	
	
	~schoolYear();

};



