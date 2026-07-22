
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