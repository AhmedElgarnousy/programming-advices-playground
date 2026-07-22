#pragma
#include <iostream>
#include <sstream> // string stream
#include <fstream> // file stream
#include <vector>
#include <string>
#include "clsString.h"
#include "clsPerson.h"

using namespace std;

class clsBankClient : public clsPerson
{
private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1
    };
    enMode _Mode;

    std::string _AccountNumber;
    string _PinCode; // password
    float _AccountBalance;

    // guarantees that no object data modification as the method static (no this pointer)
    static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
    {
        vector<string> vClientDate;
        vClientDate = clsString::Split(line, seperator);

        return clsBankClient(enMode::UpdateMode, vClientDate[0],
                             vClientDate[1], vClientDate[2], vClientDate[3], vClientDate[4], vClientDate[5], stof(vClientDate[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

public:
    clsBankClient(enMode mode, string first_name, string last_name, string email, string phone,
                  string account_num, string pin_num, float account_balance)
        : clsPerson(first_name, last_name, email, phone),
          _Mode(mode), _AccountNumber(account_num), _PinCode(pin_num), _AccountBalance(account_balance)
    {
    }

    bool IsEmpty()
    {
        return this->_Mode == enMode::EmptyMode;
    }

    // read-only property
    string AccountNumber() const
    {
        return _AccountNumber;
    }

    void SetPinCode(const string pin_code)
    {
        _PinCode = pin_code;
    }
    string PinCode() const
    {
        return _PinCode;
    }
    void SetAccountBalance(const float account_balance)
    {
        _AccountBalance = account_balance;
    }
    float AccountBalanace() const
    {
        return _AccountBalance;
    }

    void Print()
    {
        ostringstream oss;
        oss << "\nInfo:" << "\n________________"
            << "\nFirstName: " << FirstName()
            << "\nLastName: " << LastName()
            << "\nFull Name:" << FullName()
            << "\nEmail:" << Email()
            << "\nPhone:" << Phone()
            << "\nAcc. Number:" << _AccountNumber
            << "\nPassword:" << _PinCode
            << "\nAcc. Balance:" << _AccountBalance
            << "\n__________________________\n";

        std::cout << oss.str();
    }

    static clsBankClient Find(string account_number)
    {
        fstream clientsFile;
        clientsFile.open("Clients.txt", ios::in); // read mode

        if (clientsFile.is_open())
        {
            string line;
            while (std::getline(clientsFile, line))
            {
                clsBankClient Client = _ConvertLineToClientObject(line);
                if (Client.AccountNumber() == account_number)
                {
                    clientsFile.close();
                    return Client;
                }
            }
            clientsFile.close();
        }
        else
        {
            std::cerr << "\n open file failed.!\n";
        }
        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string account_number, string pin_code)
    {

        fstream clientsFile;
        clientsFile.open("Clients,txt", ios::in);

        if (clientsFile.is_open())
        {
            string line;
            while (getline(clientsFile, line))
            {
                clsBankClient client = _ConvertLineToClientObject(line);
                if (client.AccountNumber() == account_number && client.PinCode() == pin_code)
                {
                    return client;
                }
            }
            return _GetEmptyClientObject();
        }
        else
        {
            std::cerr << "\n open file failed.!\n";
        }
    }
};