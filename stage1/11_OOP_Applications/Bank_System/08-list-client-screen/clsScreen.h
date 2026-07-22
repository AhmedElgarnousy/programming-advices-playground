#pragma

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::string;

class clsScreen
{
protected:
    // vector<string> menu_options;

    // public:
    static void _DrawScreenHeader(string title, string SubTitle = "")
    {
        cout << "\t\t\t\t" << string(60, '_') << "\n";
        cout << "\n\t\t\t\t\t " << title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t " << SubTitle;
        }

        cout << "\n\t\t\t\t" << string(60, '_') << "\n\n";
    }
};