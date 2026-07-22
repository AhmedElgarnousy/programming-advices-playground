#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using std::string;

class clsPerson
{
private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _email;
    std::string _phone;

public:
    clsPerson(int id, std::string first_name, std::string last_name, std::string email, std::string phone)
    {
        _ID = id;
        SetFirstName(first_name);
        SetLastName(last_name);
        SetEmail(email);
        SetPhone(phone);
    }

    // properties
    int ID() // read-only
    {
        return _ID;
    }
    void SetFirstName(std::string first_name)
    {
        _FirstName = first_name;
    }
    std::string FirstName()
    {
        return _FirstName;
    }
    void SetLastName(std::string last_name)
    {
        _LastName = last_name;
    }
    std::string LastName()
    {
        return _LastName;
    }
    std::string FullName()
    {
        return _FirstName + " " + _LastName;
    }
    void SetEmail(std::string email)
    {
        _email = email;
    }
    std::string Email()
    {
        return _email;
    }
    void SetPhone(std::string phone)
    {
        _phone = phone;
    }
    std::string Phone()
    {
        return _phone;
    }

    // print object on console
    void Print_To_Console()
    {
        std::cout << this->ToString();
    }

    std::string ToString()
    {
        std::ostringstream oss;
        oss << "\nInfo:\n--------------------\n"
            << "ID        : " << ID() << "\n" // Handles int automatically
            << "FirstName : " << FirstName() << "\n"
            << "LastName  : " << LastName() << "\n"
            << "FullName  : " << FullName() << "\n"
            << "Email     : " << Email() << "\n"
            << "Phone     : " << Phone() << "\n"
            << "--------------\n\n";
        return oss.str();
    }

    void SendEmail(std::string subject, std::string body)
    {
        // simulate to send email
        std::cout << "The following message sent successfully to email:  " << Email() << "\n";

        std::cout << "subject: " << subject << "\n";
        std::cout << "body: " << body << "\n\n";
    }
    void SendSMS(std::string message)
    {
        std::cout << "The following SMS sent successfully to phone:  " << Phone() << "\n";
        std::cout << "subject: " << message << "\n\n";
    }
};

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

int main()
{
    clsEmployee Employee1(30, "ahmed", "kamal", "ahmed@gmail.com", "012230303", "developer", ".e-commerce", "3000$");

    // clsPerson::Print_To_Console(); error

    // Employee1.Salary();
    // Employee1.Print_To_Console();
    // std::cout << Employee1.ToString() << "\n";

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