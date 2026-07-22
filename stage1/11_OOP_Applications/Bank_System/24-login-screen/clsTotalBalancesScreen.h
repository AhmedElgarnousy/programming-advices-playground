#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{

private:
    // Front End
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalanace();
    }

public:
    static void ShowTotalBalancesScreen()
    {
        // Backend
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        string Title = "\t Total Balances List Screen";
        string Subtitle = "\t\t\t (" + to_string(vClients.size()) + ") client(s)";

        _DrawScreenHeader(Title, Subtitle);

        cout << "\n"
             << setw(25) << left << "" << std::string(80, '_') << std::endl; // Separator line

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";

        cout << "\n"
             << setw(25) << left << "" << std::string(80, '_') << std::endl; // Separator line

        double total_balances = clsBankClient::GetTotalBalances();
        // Clients
        if (vClients.size() == 0)
        {
            cout << "\t\t\tNo Clients Available ib the system!";
        }
        else
        {
            for (clsBankClient &C : vClients)
            {
                _PrintClientRecordLine(C);
                cout << "\n";
            }
        }
        cout << "\n"
             << setw(25) << left << "" << std::string(80, '_') << std::endl; // Separator line
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << total_balances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t  ( " << clsUtil::NumberToText(total_balances) << ")";
    }
};
