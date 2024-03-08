#include "Date.h"

date::isLeapYear()
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

date::isValid()
{
    // Check if year is valid
    if (y < 0) {
        return false;
    }

    // Check if month is valid
    if (m < 1 || m > 12) {
        return false;
    }

    // Check if day is valid
    int maxDays = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    else if (month == 2) {
        if (isLeapYear(year) == true) {
            maxDays = 29;
        }
        else {
            maxDays = 28;
        }
    }

    if (day < 1 || day > maxDays) {
        return false;
    }
    return true;
}
