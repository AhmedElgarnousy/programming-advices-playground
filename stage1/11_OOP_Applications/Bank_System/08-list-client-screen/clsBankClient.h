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
        UpdateMode = 1,
        AddNewMode = 2
    };
    enMode _Mode;

    std::string _AccountNumber;
    string _PinCode; // password
    float _AccountBalance;
    bool _MarkedAsDelete = false;

    // guarantees that no object data modification as the method static (no this pointer)
    static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
    {
        vector<string> vClientDate;
        vClientDate = clsString::Split(line, seperator);

        return clsBankClient(enMode::UpdateMode, vClientDate[0],
                             vClientDate[1], vClientDate[2], vClientDate[3], vClientDate[4], vClientDate[5], stof(vClientDate[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient client, string separator = "#//#")
    {
        string clientObjRecord = "";
        clientObjRecord += client.FirstName() + separator;
        clientObjRecord += client.LastName() + separator;
        clientObjRecord += client.Email() + separator;
        clientObjRecord += client.Phone() + separator;
        clientObjRecord += client.AccountNumber() + separator;
        clientObjRecord += client.PinCode() + separator;
        clientObjRecord += to_string(client.AccountBalanace());

        return clientObjRecord;
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector<clsBankClient> vClients;
        fstream clientsFileDB;
        clientsFileDB.open("Clients.txt", ios::in); // read mode

        if (clientsFileDB.is_open())
        {
            string line;
            while (getline(clientsFileDB, line))
            {
                clsBankClient db_client = _ConvertLineToClientObject(line);
                vClients.push_back(db_client);
            }
            clientsFileDB.close();
        }
        else
        {
            std::cout << "Failed To Open Clients Database!\n";
        }
        return vClients;
    }

    // update database
    static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
    {
        fstream clientsFileDB;
        string csv_data_line;
        clientsFileDB.open("Clients.txt", ios::out); // overwrite
        if (clientsFileDB.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedAsDelete() == false)
                {
                    // we write only records that are not marked for delete
                    csv_data_line = _ConvertClientObjectToLine(C);
                    clientsFileDB << csv_data_line << endl;
                }
            }
            clientsFileDB.close();
        }
        else
        {
            std::cout << "Failed To Open Clients CSV DataBase\n";
        }
    }
    void _Update()
    {
        vector<clsBankClient> _vClients;

        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &db_client : _vClients)
        {
            if (db_client.AccountNumber() == this->AccountNumber())
            {
                db_client = *this; // update with new data by assignment operator
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
    }

    void _AddDataLineToFile(string line)
    {
        fstream clientsFileDB;
        clientsFileDB.open("Clients.txt", ios::out | ios::app);
        if (clientsFileDB.is_open())
        {
            clientsFileDB << line;
            clientsFileDB.close();
        }
        else
        {
            cout << "\nFailed to open clients cvs db file to add new client\n";
        }
    }
    void _AddNewClient()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

public:
    clsBankClient(enMode mode, string first_name, string last_name, string email, string phone,
                  string account_num, string pin_num, float account_balance)
        : clsPerson(first_name, last_name, email, phone),
          _Mode(mode),
          _AccountNumber(account_num),
          _PinCode(pin_num),
          _AccountBalance(account_balance)
    {
    }

    static clsBankClient GetAddNewClientObject(string account_number)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", account_number, "", 0);
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

    bool MarkedAsDelete() const
    {
        return _MarkedAsDelete;
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
        clientsFile.open("Clients.txt", ios::in);

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

    static bool IsClientExist(string account_number)
    {
        clsBankClient client = clsBankClient::Find(account_number);

        return (!client.IsEmpty());
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        bool delete_status = false;
        for (clsBankClient &C : _vClients)
        {
            if (C.AccountNumber() == this->_AccountNumber)
            {
                C._MarkedAsDelete = true;
                delete_status = true;
                break;
            }
        }
        _SaveClientsDataToFile(_vClients);
        *this = _GetEmptyClientObject(); // also delete from memory
        // return true;
        return delete_status;
    }

    enum enSaveResult
    {
        svFailedEmptyObject = 0,
        svSuccessed = 1,
        svFailedAccountNumberExists = 2,
    };

    enSaveResult save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResult::svFailedEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update(); // UpdateClientsDB
            return enSaveResult::svSuccessed;
        }
        case enMode::AddNewMode:
        {
            // this will add new record tro file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResult::svFailedAccountNumberExists;
            }
            else
            {
                _AddNewClient();
                // change mode to update
                _Mode = enMode::EmptyMode;
                return enSaveResult::svSuccessed;
            }
        }
        default:
            return enSaveResult::svFailedEmptyObject; // just to ignore waring appears
        }
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        float total_balance = 0;

        for (clsBankClient &C : vClients)
        {
            total_balance += C.AccountBalanace();
        }
        return total_balance;
    }
};