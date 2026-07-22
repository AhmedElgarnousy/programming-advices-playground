#pragma once

#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient Client)
    {
        ostringstream oss;
        oss << "\n\e[33;1mClient Card:\e[0m" << "\n________________"
            << "\nFull Name:" << Client.FullName()
            << "\nPhone:" << Client.Phone()
            << "\nAcc. Number:" << Client.AccountNumber()
            << "\nAcc. Balance:" << Client.AccountBalanace()
            << "\n__________________________\n";
        std::cout << oss.str();
    }
    static string _GetClientAccNumber()
    {
        string acc_num = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(acc_num))
        {
            cout << "\e[31;1mPlease Enter A Valid Account Number: \e[0m";
            acc_num = clsInputValidate::ReadString();
        }
        return acc_num;
    }
    static float _GetValidAmount(string AccountNumber)
    {
        clsBankClient curClientTransferFrom = clsBankClient::Find(AccountNumber);

        cout << "Please the Amount to transfer: ";
        float amount = clsInputValidate::ReadFloatNumber();
        while (curClientTransferFrom.AccountBalanace() < amount)
        {
            cout << "\e[31;1mAmount Exceeds the available Balance, Enter another Amount : \e[0m";
            amount = clsInputValidate::ReadFloatNumber();
        }
        return amount;
    }

public:
    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\e[44;1mTransfer Screen\e[0m");

        cout << "Please Enter Account Number to transfer from: ";
        string src_acc_num = _GetClientAccNumber();

        clsBankClient Src_Client = clsBankClient::Find(src_acc_num);
        _PrintClient(Src_Client);

        cout << "Please Enter Account Number to transfer to: ";
        string dest_acc_num = _GetClientAccNumber();

        // handle user error of entering the same account number
        while (dest_acc_num == src_acc_num)
        {
            cout << "\e[31;1mEnter A Different Account Number: \e[0m";
            dest_acc_num = _GetClientAccNumber();
        }

        clsBankClient Dest_client = clsBankClient::Find(dest_acc_num);
        _PrintClient(Dest_client);

        float valid_amount = _GetValidAmount(src_acc_num);

        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Src_Client.Transfer(valid_amount, Dest_client))
            {
                cout << "\e[42;1mTranfer Successfully Thank You\e[0m\n";
            }
            else
            {
                cout << "\e[43;1mTransfer Faild\e[0m\n";
            }
        }

        _PrintClient(Src_Client);
        _PrintClient(Dest_client);
    }
};
