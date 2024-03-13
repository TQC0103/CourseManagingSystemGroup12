#include "Semester.h"
#include<SFML/Graphics.hpp>
#include<string>


semester::semester(int semesterNum, std::string StartDate, std::string EndDate) {
	semesterData = semesterNum;
	startDate = StartDate;	
	endDate = EndDate;
}
void semester::loadSemester() {

}