#pragma once
#include <iostream>

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
