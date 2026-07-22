#pragma once

#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
    static void _PrintClient(clsBankClient &client)
    {
        ostringstream oss;
        oss << "\nInfo:" << "\n________________"
            << "\nFirstName: " << client.FirstName()
            << "\nLastName: " << client.LastName()
            << "\nFull Name:" << client.FullName()
            << "\nEmail:" << client.Email()
            << "\nPhone:" << client.Phone()
            << "\nAcc. Number:" << client.AccountNumber()
            << "\nPassword:" << client.PinCode()
            << "\nAcc. Balance:" << client.AccountBalanace()
            << "\n__________________________\n";

        std::cout << oss.str();
    }
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

    static void _UpdateClient()
    {
        // read account num from user
        string account_num = "";
        std::cout << "Please Enter an Acc. Number: ";
        account_num = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(account_num))
        {
            // system("clear");
            cout << "Account Number is not found choose another one: ";
            account_num = clsInputValidate::ReadString();
        }

        // get the client object from the entered acc. number
        clsBankClient client = clsBankClient::Find(account_num);
        _PrintClient(client);

        cout << "\nUpdate Client Info: ";
        cout << "\n__________________________\n";

        _ReadClientInfo(client);

        clsBankClient::enSaveResult SaveResult;

        // we need to know when we call find method we
        // returned by an empty object or returned with already exsiting object
        // but i know until now if we returned by empty it will not be in csv DB

        SaveResult = client.save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svSuccessed:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            // client.Print(); // bad design: print from outside the object to separate UI
            _PrintClient(client);
            break;
        }
        case clsBankClient::enSaveResult::svFailedEmptyObject:
        {
            cout << "\nError Account was not saved because it's empty";
            break;
        }
        }
    }

public:
    static void showUpdateClientScreen()
    {
        clsScreen::_DrawScreenHeader("\tUpdate Client Screen");
        _UpdateClient();
    }
};
