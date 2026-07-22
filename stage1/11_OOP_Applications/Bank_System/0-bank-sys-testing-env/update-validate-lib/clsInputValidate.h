#pragma once
#include <iostream>
#include <string>
#include <regex>

#include "clsString.h"
#include "clsDate.h"

#include <limits> // Add this line

class clsInputValidate
{
public:
    static bool IsNumberBetween(short Number, short From, short To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(int Number, int From, int To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(float Number, float From, float To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsNumberBetween(double Number, double From, double To)
    {
        if (Number >= From && Number <= To)
            return true;
        else
            return false;
    }

    static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
    {
        // Date>=From && Date<=To
        if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)) &&
            (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
        {
            return true;
        }

        // Date>=To && Date<=From
        if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)) &&
            (clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
        {
            return true;
        }

        return false;
    }

    static int ReadIntNumber(std::string ErrorMessage = "Invalid Number, Enter again\n")
    {
        int Number;
        while (!(std::cin >> Number))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            std::cout << ErrorMessage;
        }
        return Number;
    }

    static int ReadIntNumberBetween(int From, int To, std::string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        int Number = ReadIntNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            std::cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }
    static float ReadFloatNumber(std::string ErrorMessage = "Invalid Number, Enter again\n")
    {
        float Number;
        while (!(std::cin >> Number))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            std::cout << ErrorMessage;
        }
        return Number;
    }

    static float ReadFloatNumberBetween(float From, float To, std::string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        float Number = ReadFloatNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            std::cout << ErrorMessage;
            Number = ReadIntNumber();
        }
        return Number;
    }

    static double ReadDblNumber(std::string ErrorMessage = "Invalid Number, Enter again\n")
    {
        double Number;
        while (!(cin >> Number))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            std::cout << ErrorMessage;
        }
        return Number;
    }

    static double ReadDblNumberBetween(double From, double To, std::string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        double Number = ReadDblNumber();

        while (!IsNumberBetween(Number, From, To))
        {
            std::cout << ErrorMessage;
            Number = ReadDblNumber();
        }
        return Number;
    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }
    static string ReadString()
    {
        string str = "";
        getline(cin >> ws, str);
        return str;
    }

    static string IsValidEmail(std::string email)
    {
        // Simple RFC 5322 compliant regex for basic email structure
        const std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
        while (!std::regex_match(email, email_pattern))
        {
            cout << "Please Enter a Valid Email: ";
            email = clsInputValidate::ReadString(); // Get fresh input
        }

        return email; // Always safely returns a real string
    }
    static string ReadValidEmail()
    {
        string email = "";
        getline(cin >> ws, email);

        // Simple RFC 5322 compliant regex for basic email structure
        const std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        while (!std::regex_match(email, email_pattern))
        {
            cout << "Please Enter a Valid Email: ";
            return clsInputValidate::ReadString(); // Get fresh input
        }

        return email; // Always safely returns a real string
    }

    static bool IsValidPhone(const std::string &phone)
    {
        // Matches patterns like: 123-456-7890, (123) 456-7890, 1234567890
        const std::regex phone_pattern(R"(\(?\d{3}\)?[- ]?\d{3}[- ]?\d{4})");
        return std::regex_match(phone, phone_pattern);
    }
};
