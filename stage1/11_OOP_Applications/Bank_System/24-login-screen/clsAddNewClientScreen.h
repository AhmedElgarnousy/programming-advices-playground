#pragma once

#include <sstream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient &client)
    {
        cout << "\nEnter First Name: ";
        client.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name: ";
        client.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        client.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        client.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Pin Code: ";
        client.SetPinCode(clsInputValidate::ReadString());

        cout << "\nEnter Account Balance: ";
        client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
    }
    // Front End
    static void _PrintClient(clsBankClient Client)
    {
        ostringstream oss;
        oss << "\nInfo:" << "\n________________"
            << "\nFirstName: " << Client.FirstName()
            << "\nLastName: " << Client.LastName()
            << "\nFull Name:" << Client.FullName()
            << "\nEmail:" << Client.Email()
            << "\nPhone:" << Client.Phone()
            << "\nAcc. Number:" << Client.AccountNumber()
            << "\nPassword:" << Client.PinCode()
            << "\nAcc. Balance:" << Client.AccountBalanace()
            << "\n__________________________\n";

        std::cout << oss.str();
    }

public:
    static void AddNewClient()
    {
        clsScreen::_DrawScreenHeader("\tAdd New Client Screen");

        string account_number = "";
        cout << "\nPlease Enter Account Number:";
        account_number = clsInputValidate::ReadString();

        while (clsBankClient::IsClientExist(account_number))
        {
            cout << "\nAccount Number is Already Used, choose another one: ";
            account_number = clsInputValidate::ReadString();
        }

        clsBankClient new_client = clsBankClient::GetAddNewClientObject(account_number);
        _ReadClientInfo(new_client);

        clsBankClient::enSaveResult save_result;
        save_result = new_client.save();

        switch (save_result)
        {
        case clsBankClient::enSaveResult::svSuccessed:
        {
            cout << "\nAccount Added Successfully:-)\n";
            _PrintClient(new_client);
            break;
        }
        case clsBankClient::enSaveResult::svFailedEmptyObject:
        {
            cout << "\nError Account was not saved because it's empty\n";
            break;
        }
        case clsBankClient::enSaveResult::svFailedAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        default:
            break;
        }
    }
};
