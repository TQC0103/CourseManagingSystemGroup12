#pragma once
#include <string>
#include <sstream>
#include <iomanip>

struct date {
	//Constructors
	int d;
	int m;
	int y;

	date()
	{
		d = 1;
		m = 1;
		y = 0;
	}

	//Functions
	bool isValid();
	bool isLeapYear();
};

//Supportive Function
date parseDate(std::string dateString);
std::string formatDate (date Date);



