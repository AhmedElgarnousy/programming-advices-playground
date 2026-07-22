#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"
void ReadClientInfo(clsBankClient &client)
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
void UpdateClient()
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
    client.Print();

    cout << "\nUpdate Client Info: ";
    cout << "\n__________________________\n";

    ReadClientInfo(client);

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
        client.Print();
        break;
    }
    case clsBankClient::enSaveResult::svFailedEmptyObject:
    {
        cout << "\nError Account was not saved because it's empty";
        break;
    }
    }
};
void AddNewClient()
{
    string account_number = "";
    cout << "\nPlease Enter Account Number:";
    account_number = clsInputValidate::ReadString();

    while (clsBankClient::IsClientExist(account_number))
    {
        cout << "\nAccount Number is Already Used, choose another one: ";
        account_number = clsInputValidate::ReadString();
    }

    clsBankClient new_client = clsBankClient::GetAddNewClientObject(account_number);
    ReadClientInfo(new_client);

    clsBankClient::enSaveResult save_result;
    save_result = new_client.save();

    switch (save_result)
    {
    case clsBankClient::enSaveResult::svSuccessed:
    {
        cout << "\nAccount Added Successfully:-)\n";
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

int main()
{
    AddNewClient();
    return 0;
}