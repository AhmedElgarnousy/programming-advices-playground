#pragma once

#include <iostream>
#include <string>
#include <sstream> // string stream

using namespace std;

class clsPerson
{
private:
    string _FirstName;
    string _LastName;
    string _Email;
    string _Phone;

public:
    clsPerson(string first_name, string last_name, string email, string phone)
        : _FirstName(first_name), _LastName(last_name), _Email(email), _Phone(phone)
    {
    }

    // set FirstName property
    void SetFirstName(const string first_name)
    {
        _FirstName = first_name;
    }
    // Get FirstName Property
    string FirstName() const
    {
        return _FirstName;
    }
    void SetLastName(const string last_name)
    {
        _LastName = last_name;
    }
    string LastName() const
    {
        return _LastName;
    }

    void SetEmail(const string email)
    {
        _Email = email;
    }
    string Email() const
    {
        return _Email;
    }
    void SetPhone(const string phone)
    {
        _Phone = phone;
    }
    string Phone() const
    {
        return _Phone;
    }

    string FullName()
    {
        return _FirstName + ' ' + _LastName;
    }
};