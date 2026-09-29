#include <iostream>
#include <cstdio> // Required for BUFSIZ
using namespace std;

void lesson14()
{
    std::ios::sync_with_stdio(false);
    std::cout << "Default Max Buffer Size: " << BUFSIZ << " bytes\n"; // 8192 means 8 kB
    for (int i = 0; i < 1000; i++)
    {
        // cout << "hello world" << endl; // 1000 buffer , 1000 system call
        cout << "hello world" << "\n";
    }
}

void lesson16_HW()
{
    // 3 programs
    // program1: Ring a bell
    cout << "\a";
}

void lesson16()
{
    /*
    int octalNum = 0700;
    cout << "Octal Value of 055 is: " << octalNum << " in decimal (base 10)" << "\n";
    */
    /*
     cout << "M1\M2 \n";
     cout << "M1\\M2 \n";
    */
    cout << "\n";
}

void SomeDataTypesErrors()
{
    double distance = 56E12;
    double d2 = 5.6e+13;

    cout << distance << " " << d2 << endl;

    // short d = 3434233; // Error: out of range for short, overflow occurs
    // cout << d << endl;

    unsigned int a = -10; // Bug: negative value for unsigned int
    cout << a << endl;

    unsigned short b = -1; // Error: negative value for unsigned short
    cout << b << endl;
}

int main()
{
    // lesson14();
    // lesson16();
    // lesson16_HW();
    SomeDataTypesErrors();
    return 0;
}