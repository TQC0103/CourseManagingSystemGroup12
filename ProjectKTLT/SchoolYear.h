#pragma once
#include<string>
#include "Semester.h"




struct schoolYear {
	schoolYear();
	schoolYear(std::string yearData);
	std::string year;
	schoolYear* pHead = nullptr;
	schoolYear* pNext = nullptr;

	// User Experience	
	void loadSchoolYear();// done
	
	bool addSchoolYear(std::string yearData);// done
	
	bool checkInputYear(std::string &data); // done

	void findCurrentSchoolYear(std::string data); // done
	
	// User Interface

	void viewSchoolYear(); // UI (later)
		
	// SEMESTER IN A SCHOOL YEAR
	// // // // // 
	// // // // //

	semester* pHeadSemester = nullptr;
	
	void loadSemester(); // done
	
	// Data must be like (Semester1) not (1)
	
	bool addSemester(std::string data, std::string start, std::string end);// done
	
	bool checkInputDate(std::string &data); // done

	// Deallocate
	
	void deallocateSchoolYear(); // done
	
	void deallocateSemester(); // done
};



