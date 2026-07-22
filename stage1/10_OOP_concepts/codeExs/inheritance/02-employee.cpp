#include <iostream>
#include <sstream>

class clsPerson
{
private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _email;
    std::string _phone;

public:
    clsPerson() {}
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
        std::cout << "\nInfo:\n--------------------\n";
        std::cout << "ID        :" << ID() << "\n";
        std::cout << "FirstName :" << FirstName() << "\n";
        std::cout << "LastName  :" << LastName() << "\n";
        std::cout << "FullName  :" << FullName() << "\n";
        std::cout << "Email     :" << Email() << "\n";
        std::cout << "Phone     :" << Phone() << "\n--------------\n\n";
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
    std::string _Title;
    std::string _Department;
    std::string _Salary;

public:
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
};

int main()
{
    // later we will discuss paramterized constructor
    // clsEmployee Employee1(10, "ahmed", "kamal", "ahmed97@gmail.com", "01551442559");
    clsEmployee Employee1;
    Employee1.SetFirstName("mohand");
    Employee1.SetLastName("kamal");
    Employee1.SetEmail("mohand46@gmail.com");
    Employee1.SetPhone("123424343");

    Employee1.Salary();
    // note salary not found
    Employee1.Print_To_Console();

    getchar();
    system("clear");

    return 0;
}