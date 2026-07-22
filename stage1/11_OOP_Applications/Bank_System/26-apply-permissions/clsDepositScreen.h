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
        cout << setw(32) << left << "" << "PLease Enter Account Number: ";

        account_number = clsInputValidate::ReadString(); // cin >> account_number;

        while (!clsBankClient::IsClientExist(account_number))
        {
            cout << setw(32) << left << "" << "\nClient with [" << account_number << "] does not exist.\n";
            cout << setw(32) << left << "" << "Please Enter an Account Number Again: ";
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

        cout << setw(32) << left << "" << "\nPlease enter deposit amount? ";
        double new_amount = clsInputValidate::ReadDblNumber();

        char ans;
        cout << setw(32) << left << "" << "\nAre you sure you want to perform this transaction? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            client.Deposit(new_amount);
            cout << setw(32) << left << "" << "\nAmount Deposited Successfully.\n";
            cout << setw(32) << left << "" << "\nNew Balance Is: " << client.AccountBalanace();
        }
        else
        {
            cout << setw(32) << left << "" << "\nOperation was cancelled.\n";
        }
    }
};