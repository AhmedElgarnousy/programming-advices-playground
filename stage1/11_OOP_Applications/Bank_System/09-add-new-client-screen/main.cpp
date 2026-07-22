
#include "clsMainScreen.h"

#include "clsUtil.h"
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
    clsMainScreen::ShowMainMenu();

    return 0;
}