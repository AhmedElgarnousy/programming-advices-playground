#include <iostream>
#include <sstream>

class clsEmployee
{
private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _email;
    std::string _phone;

public:
    clsEmployee(int id, std::string first_name, std::string last_name, std::string email, std::string phone)
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

int main()
{

    /* now this code is portable as business logic for web app or mobile or desktop */

    clsEmployee Employee1(10, "ahmed", "kamal", "ahmed97@gmail.com", "01551442559");

    // Person1.Print();
    std::cout << Employee1.ToString();

    Employee1.SendEmail("Hi", "how are you ?");
    Employee1.SendSMS("how are you ?");

    getchar();
    system("clear");

    return 0;
}