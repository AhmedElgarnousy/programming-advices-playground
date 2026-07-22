#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::string;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string title, string SubTitle = "")
    {
        cout << setw(20) << left << " " << string(60, '_') << "\n"; // line seperator of __
        cout << "\n"
             << setw(40) << left << "" << title;

        if (SubTitle != "")
        {
            cout << endl
                 << setw(40) << left << " " << SubTitle;
        }

        cout << "\n"
             << setw(20) << left << "" << string(60, '_') << "\n\n";
    }
};