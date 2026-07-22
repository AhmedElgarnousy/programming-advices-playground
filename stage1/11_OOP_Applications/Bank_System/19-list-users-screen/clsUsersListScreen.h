#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"

class clsUsersListScreen : public clsScreen
{
private:
    static void _PrintUserRecordLine(clsUser usr)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << usr.UserName();
        cout << "| " << setw(25) << left << usr.FullName();
        cout << "| " << setw(12) << left << usr.Phone();
        cout << "| " << setw(20) << left << usr.Email();
        cout << "| " << setw(10) << left << usr.Password();
        cout << "| " << setw(12) << left << usr.Permissions();
    }

public:
    static void ShowUsersListScreen()
    {
        vector<clsUser> vUsers = clsUser::GetUsersLists();

        string Title = "\t  User List Screen";
        string SubTitle = "\t\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        // header
        cout << setw(8) << left << "" << string(100, '=') << "\n";

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions" << '\n';

        cout << setw(8) << left << "" << string(100, '=') << "\n";

        if (vUsers.size() > 0)
        {
            for (clsUser &usr : vUsers)
            {
                _PrintUserRecordLine(usr);
                cout << endl;
            }
        }
        else
        {
            cout << "No Users Exists\n";
        }
        cout << setw(8) << left << "" << string(100, '=') << "\n";
    }
};