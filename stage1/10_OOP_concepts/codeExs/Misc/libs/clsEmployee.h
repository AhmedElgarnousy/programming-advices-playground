#pragma once

#include <iostream>
#include "clsPerson.h"

using std::string;

class clsEmployee : public clsPerson
{

private:
    string _Title;
    string _Department;
    string _Salary;

public:
    clsEmployee(int id, string first_name, string last_name,
                string email, string phone,
                string title, string department, string salary)
        : clsPerson(id, first_name, last_name, email, phone)
    {
        _Title = title;
        _Department = department;
        _Salary = salary;
    }

    void SetTitle(const std::string title)
    {
        _Title = title;
    }
    std::string Title() const
    {
        return _Title;
    }
    void SetDepartment(const std::string department)
    {
        _Department = department;
    }
    std::string Department() const
    {
        return _Department;
    }
    void SetSalary(const std::string salary)
    {
        _Salary = salary;
    }
    std::string Salary() const
    {
        return _Salary;
    }
    string ToString()
    {
        std::stringstream oss;
        oss << "\nInfo:\n--------------------\n"
            << "ID        : " << ID() << "\n" // Handles int automatically
            << "FirstName : " << FirstName() << "\n"
            << "LastName  : " << LastName() << "\n"
            << "FullName  : " << FullName() << "\n"
            << "Email     : " << Email() << "\n"
            << "Phone     : " << Phone() << "\n"
            << "Phone     : " << Title() << "\n"
            << "Phone     : " << Department() << "\n"
            << "Phone     : " << Salary() << "\n"
            << "--------------\n\n";
        return oss.str();
    }

    void Print_To_Console()
    {
        // clsPerson::Print_To_Console();
        // std::cout << "hello from employee object\n";
        std::cout << ToString();
    }
};
