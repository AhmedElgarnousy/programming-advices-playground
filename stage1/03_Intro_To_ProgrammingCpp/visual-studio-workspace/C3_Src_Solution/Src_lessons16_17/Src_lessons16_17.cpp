// MyFirstApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <math.h>

using namespace std;

void lesson16_hw_program1() {
    // ring a bell
    cout << "\a";
}

void lesson16_hw_program2() {
    // write a program that print these info
    cout << "Dear Sir\\Madom,\n";
    cout << "How are you?\n";
    cout << "My name is \"Ahmed\", Nice to meet you.   \n";
}

void lesson16_hw_program3()
{
    cout << "Ali\t Ahmed\t Line\n"
        << "Fadi\t Zain\t Mona\n";
}

enum enIsMarried
{
    Yes = 1,
    No = 0
};
enum enGender {
    Female,
    Male
};

struct stCardInfo
{
public:
    string Name;
    int Age;
    string City;
    string Country;
    float MonthlySalary;
    float YearlySalary;
    enIsMarried isMarried;
    enGender Gender;

    stCardInfo(string name, int age, string city, string country, float monthlySalary,
        enIsMarried is_married, enGender gender)
        : Name(name), Age(age), City(city), Country(country),
        MonthlySalary(monthlySalary), YearlySalary(monthlySalary * 12),
        isMarried(is_married), Gender(gender)
    {
    }
};

void lesson17_hw_program1(struct stCardInfo* cardInfo)
{
    // write a program that print these info to console using ostringstream

    ostringstream oss;
    oss << "Name: " << cardInfo->Name << "\n"
        << "Age: " << cardInfo->Age << "\n"
        << "City: " << cardInfo->City << "\n"
        << "Country: " << cardInfo->Country << "\n"
        << "Monthly Salary: " << cardInfo->MonthlySalary << "\n"
        << "Yearly Salary: " << cardInfo->YearlySalary << "\n"
        << "Married: " << (cardInfo->isMarried ? "Yes" : "No") << "\n"
        //<<"Married: " << cardInfo->isMarried  <<"\n"
        << "Gender: " << (cardInfo->Gender ? "Male" : "Female") << "\n";

    cout << "****************************\n";
    cout << oss.str();
    cout << "****************************\n";

}

void lesson17_hw_program2()
{
    float number1 = 20;
    float number2 = 30;
    float number3 = 10;

    cout << number1 << " +\n";
    cout << number2 << " +\n";
    cout << number3 << " \n";

    cout << "-----------------------\n";
    cout << "Total = " << number1 + number2 + number3 << "\n";
}

void lesson17_hw_program3()
{
    int cuurentAge = 25;
    cout << "After 5 years , your age will be: " << cuurentAge + 5 << endl;
}


int main()
{
    //lesson16_hw_program1();
    //lesson16_hw_program2();
    //lesson16_hw_program3();

    //stCardInfo cardInfo1("Ahmed", 30, "Cairo", "Egypt", 5000, enIsMarried::No, enGender::Male);
    //lesson17_hw_program1(&cardInfo1);
 //   cout << endl;

 //   lesson17_hw_program2();
 //   cout << endl;
 //   lesson17_hw_program3();
 //   cout << endl;
}

