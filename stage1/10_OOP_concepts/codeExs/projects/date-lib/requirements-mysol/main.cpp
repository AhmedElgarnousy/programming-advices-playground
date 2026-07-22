#include <iostream>
#include "clsDate.h"
#include <ctime>

int main()
{
    clsDate date1;
    date1.Print();

    clsDate date2(13, 32, 2026);
    date1.Print();

    return 0;
}