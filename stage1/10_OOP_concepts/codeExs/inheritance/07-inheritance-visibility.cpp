#include <iostream>
#include <sstream>
#include <fstream>

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
        oss << "\nInfo:\n--------------------"
            << "\nID        : " << ID() // Handles int automatically
            << "\nFirstName : " << FirstName()
            << "\nLastName  : " << LastName()
            << "\nFullName  : " << FullName()
            << "\nEmail     : " << Email()
            << "\nPhone     : " << Phone()
            << "\nTitle     : " << Title()
            << "\nDeprtment : " << Department()
            << "\nSalary    : " << Salary()
            << "\n--------------\n\n";
        return oss.str();
    }

    void Print_To_Console()
    {
        std::cout << ToString();
    }
};

class clsDoctor : private clsEmployee
{
private:
    int _NumOfPatients;

public:
    clsDoctor(int id, string first_name, string last_name,
              string email, string phone,
              string title, string department, string salary, int num_of_patients)
        : clsEmployee(id, first_name, last_name, email, phone, title, department, salary)
    {
        _NumOfPatients = num_of_patients;
    }
    void answer_patient()
    {
        Print_To_Console();
        Salary();
    }
};

int main()
{
    clsDoctor docker1(70, "ahm0", "moja", "test", "455", "sugorn", "kjj", "1400", 15);
    // docker1.Print_To_Console();
    docker1.Salary();

    return 0;
}