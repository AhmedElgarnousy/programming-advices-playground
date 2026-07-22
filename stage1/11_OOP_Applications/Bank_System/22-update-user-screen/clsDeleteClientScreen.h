#pragma once

#include "clsBankClient.h"

#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
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
    static void ShowDeleteClientScreen()
    {
        _DrawScreenHeader("\tDelete Client Screen");

        string account_number = "";
        cout << "\nEnter Enter Account Number:";
        account_number = clsInputValidate::ReadString();

        if (!clsBankClient::IsClientExist(account_number))
        {
            cout << "\nAccount number is not found, choose another one:";
            account_number = clsInputValidate::ReadString();
        }
        clsBankClient client = clsBankClient::Find(account_number);

        // client.Print();
        _PrintClient(client);

        cout << "\nAre you sure you want to delete this client y/n?";

        char answer = 'n';
        cin >> answer;

        if (answer == 'y' | answer == 'Y')
        {
            // delete the object
            if (client.Delete())
            {
                cout << "\n Account Deleted Sucessfully\n";
                _PrintClient(client);
            }
            else
            {
                cout << "\n Error Client was not deleted\n";
            }
        }
    }
};