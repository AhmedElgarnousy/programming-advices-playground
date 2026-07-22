#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Global.h"
#include "clsDate.h"

using std::cout;
using std::string;

using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string title, string SubTitle = "")
    {
        cout << setw(20) << left << " " << string(60, '_') << "\n\n"; // line seperator of __
        cout << setw(40) << left << "" << title << "\n";
        // cout << setw(20) << left << "" << "User:" << CurLoggedUsr.UserName() << "\n";
        // cout << setw(20) << left << "" << "Date:" << clsDate::DateToString(clsDate());
        cout << setw(20) << left << "" << "User:" << CurLoggedUsr.UserName()
             << setw(40) << right << "Date:" << clsDate::DateToString(clsDate()) << "\n";

        if (SubTitle != "")
        {
            cout << endl
                 << setw(40) << left << " " << SubTitle;
        }

        cout << "\n"
             << setw(20) << left << "" << string(60, '_') << "\n\n";
    }
};