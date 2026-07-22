#pragma once
#include <iostream>
#include <iomanip> // I/O Stream Manipulator

#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsClientListScreen : protected clsScreen
{
private:
    // Front End
    static void _PrintClientRecordLine(clsBankClient Client)
    {
        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone();
        cout << "| " << setw(20) << left << Client.Email();
        cout << "| " << setw(10) << left << Client.PinCode();
        cout << "| " << setw(12) << left << Client.AccountBalanace();
    }

public:
    // Front End
    static void ShowClientsList()
    {
        // Backend
        vector<clsBankClient> vClients = clsBankClient::GetClientsList();

        // print clients list header
        cout << "\n\t\t\t\t\tClients List(" << vClients.size() << ")Client(s).\n";
        cout << "\n"
             << std::string(95, '_') << std::endl; // Separator line

        cout << "|" << left << setw(16) << "Account Number";
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
                _PrintClientRecordLine(C);
                cout << "\n";
            }
        }
        cout << std::string(95, '_') << std::endl; // Separator line
    }
};