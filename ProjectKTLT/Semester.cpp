#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>
#include<fstream>
#include<iostream>
#include "Date.h"
#include<direct.h>




semester::semester(std::string semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;	
	endDate = EndDate;
}
semester::semester() {
}





