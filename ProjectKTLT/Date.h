#pragma once
#include <string>
#include <sstream>
#include <iomanip>

struct date {
	//Constructors
	int d;
	int m;
	int y;

	//date();

	//Functions
	bool isValid();
	bool isLeapYear();
};

//Supportive Function
date parseDate(std::string dateString);
std::string formatDate (date Date);



