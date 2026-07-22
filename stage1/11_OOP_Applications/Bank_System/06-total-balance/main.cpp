#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsUtil.h"

#include <iomanip> // I/O Stream Manipulator

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
void DeleteClient()
{
    string account_number = "";
    cout << "\nEnter Enter Account Number:";
    account_number = clsInputValidate::ReadString();

    if (!clsBankClient::IsClientExist(account_number))
    {
        cout << "\nAccount number is not found, choose another one:";
        account_number = clsInputValidate::ReadString();
    }
    clsBankClient client = clsBankClient::Find(account_number);

    client.Print();

    cout << "\nAre you sure you want to delete this client y/n?";

    char answer = 'n';
    cin >> answer;

    if (answer == 'y' | answer == 'Y')
    {
        // delete the object
        if (client.Delete())
        {
            cout << "\n Account Deleted Sucessfully\n";
            client.Print();
        }
        else
        {
            cout << "\n Error Client was not deleted\n";
        }
    }
}

// Front End
void PrintClientRecordLine(clsBankClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone();
    cout << "| " << setw(20) << left << Client.Email();
    cout << "| " << setw(10) << left << Client.PinCode();
    cout << "| " << setw(12) << left << Client.AccountBalanace();
}
// Front End
void ShowClientsList()
{
    // Backend
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    // print clients list header
    cout << "\n\t\t\t\t\tClients List(" << vClients.size() << ")Client(s).\n";
    cout << "\n"
         << std::string(95, '_') << std::endl; // Separator line
    // cout << "\n_____________________________________________________\n";

    cout
        << "|" << left << setw(16) << "Account Number";
    cout << "|" << left << setw(21) << "Client Name";
    cout << "|" << left << setw(13) << "Phone";
    cout << "|" << left << setw(21) << "Email";
    cout << "|" << left << setw(11) << "Pin Code";
    cout << "|" << left << setw(12) << "Balance";

    cout << "\n"
         << std::string(95, '_') << std::endl; // Separator line

    // Clients
    if (vClients.size() == 0)
    {
        cout << "\t\t\tNo Clients Available ib the system!";
    }
    else
    {
        for (clsBankClient &C : vClients)
        {
            PrintClientRecordLine(C);
            cout << "\n";
        }
    }
    cout << std::string(95, '_') << std::endl; // Separator line
}

void PrintClientRecordBalance(clsBankClient Client)
{
    cout << "| " << left << setw(20) << Client.AccountNumber();
    cout << "| " << left << setw(40) << Client.FullName();
    cout << "| " << left << setw(12) << Client.AccountBalanace();
}

void ShowClientsTotalBalances()
{
    vector<clsBankClient> vClients = clsBankClient::GetClientsList();

    // print balance menu header
    cout << "\n\t\t\tBalances List (" << vClients.size() << ") Client(s).\n";
    cout << std::string(70, '_') << endl; // line seperator

    cout << "|" << left << setw(21) << "Account Number";
    cout << "|" << left << setw(41) << "Full Name";
    cout << "|" << left << setw(15) << "Balance" << "\n";

    cout << std::string(70, '_') << endl; // line seperator

    float total_balance = clsBankClient::GetTotalBalances();
    if (vClients.size() == 0)
    {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else
    {
        for (clsBankClient &C : vClients)
        {
            PrintClientRecordBalance(C);
            cout << endl;
        }
        cout << clsUtil::Tabs(2) << "Total Balances = " << total_balance << endl; // util numberToText
        // cout << "\t\t\t\t\t   Total Balances = " << total_balance << endl; // util numberToText
        cout << clsUtil::Tabs(2) << "   ( " << clsUtil::NumberToText((int)total_balance) << ")\n";
    }
    cout << std::string(70, '_') << endl; // line seperator
    cout << std::string(70, '_') << endl; // line seperator
    //
}
int main()
{
    ShowClientsTotalBalances();

    return 0;
}