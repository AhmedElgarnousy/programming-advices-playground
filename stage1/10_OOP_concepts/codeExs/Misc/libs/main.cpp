#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "clsPerson.h"
#include "clsEmployee.h"

using std::string;

int main()
{
    clsEmployee Employee1(30, "ahmed", "kamal", "ahmed@gmail.com", "012230303", "developer", ".e-commerce", "3000$");
    /*
        By default, std::ofstream opens a file with std::ios::out,
        which truncates (deletes) any existing file contents.
    */
    // std::ofstream OutcsvDBFile("csvDBFile", std::ios::app);
    // OutcsvDBFile << Employee1.ToString();

    Employee1.Print_To_Console();

    getchar();
    system("clear");

    return 0;
}