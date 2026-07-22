#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>

using std::string;

class clsDate
{
private:
    int _day;
    int _month;
    int _year;

public:
    clsDate() // print current date
    {
        std::time_t t = std::time(0);
        tm *pstLocal_tm = std::localtime(&t);
        _day = pstLocal_tm->tm_mday;
        _month = pstLocal_tm->tm_mon + 1;
        _year = pstLocal_tm->tm_year + 1900;
    }
    clsDate(string date)
    {
        // print given date string paramter
    }

    clsDate(int day, int month, int year) // print data from the 3 parameter
    {
        int error = 0;
        if (day <= 0 || day > 31)
        {
            error = -1;
        }
        _day = day;

        month >= 1 &&month <= 12 ? _month : errno = -1;
        year > 0 ? _year : errno = -1;

        if (error == -1)
            std::cout << "Invalid value Value\n";
    }
    clsDate(int numDayInYear, int year)
    {
        // 250, 2022 -> 7/9/2022
        // print data from the given 2 parameter
    }
    //////////////
    void Print()
    {
        std::cout << _day << "/" << _month << "/" << +_year << "\n";
    }
};