#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{
private:
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
        // std::cout << left << setw(70) << oss.str();
    }

    static string _ReadAccountNumber()
    {
        string account_number;
        cout << "PLease Enter Account Number: ";

        account_number = clsInputValidate::ReadString(); // cin >> account_number;

        while (!clsBankClient::IsClientExist(account_number))
        {
            cout << "\nClient with [" << account_number << "] does not exist.\n";
            cout << "Please Enter an Account Number Again: ";
            account_number = clsInputValidate::ReadString();
        }
        return account_number;
    }

public:
    static void ShowDepositScreen()
    {
        _DrawScreenHeader("\t Deposit Screen");

        string valid_acc_number = _ReadAccountNumber();

        clsBankClient client = clsBankClient::Find(valid_acc_number);

        _PrintClient(client);

        cout << "\nPlease enter deposit amount? ";
        double new_amount = clsInputValidate::ReadDblNumber();

        char ans;
        cout << "\nAre you sure you want to perform this transaction? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            client.Deposit(new_amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << client.AccountBalanace();
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }
    }
};