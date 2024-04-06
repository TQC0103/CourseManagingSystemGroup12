#include "Date.h"

bool date::isLeapYear()
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

bool date::isValid()
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
    if (m == 4 || m == 6 || m == 9 || m == 11) {
        maxDays = 30;
    }
    else if (m == 2) {
        if (date::isLeapYear() == true) {
            maxDays = 29;
        }
        else {
            maxDays = 28;
        }
    }

    if (d < 1 || d > maxDays) {
        return false;
    }
    return true;
}
