#include <iostream>
#include <ctime>

/*
int tm_sec; // seconds of minutes from 0 to 61
int tm_min; // minutes of hour from 0 to 59
int tm_hour; // hours of day from 0 to 24
int tm_mday; // day of month from 1 to 31
int tm_mon; // month of year from 0 to 11
int tm_year; // year since 1900
int tm_wday; // days since sunday
int tm_yday; // days since January 1st
int tm_isdst; // hours of daylight savings time
*/

int main()
{
    // get time now
    time_t time_now = time(0);
    // // e.g. 1749814930  (about 55 years worth of seconds)

    tm *stDataTimeNow = localtime(&time_now);

    std::cout << "\n------------------\nYear: " << stDataTimeNow->tm_year + 1900 << "\n";
    std::cout << "Month: " << stDataTimeNow->tm_mon + 1 << "\n";
    std::cout << "Day: " << stDataTimeNow->tm_mday << "\n";
    std::cout << "Hour: " << stDataTimeNow->tm_hour << "\n";
    std::cout << "Min: " << stDataTimeNow->tm_min << "\n";

    std::cout << "Weak Day (Days since sunday): " << stDataTimeNow->tm_mday << "\n";
    std::cout << "Year Day (Days since Jan 1st): " << stDataTimeNow->tm_yday << "\n";
    std::cout << "hours of daylight saving time: " << stDataTimeNow->tm_isdst << "\n";

    char *dtString = asctime(stDataTimeNow);
    std::cout << "\n----------------\nLocal time: " << dtString << "\n";

    return 0;
}