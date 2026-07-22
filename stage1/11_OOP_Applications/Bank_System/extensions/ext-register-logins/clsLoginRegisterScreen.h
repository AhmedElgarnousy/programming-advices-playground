#pragma once

#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"

class clsLoginRegister : protected clsScreen
{

private:
    // string _SysTimeDate;
    // string _UserName;
    // string _Password;
    // string _Permissions; // int

    static vector<string> _LoadLoginRegisterFromFile()
    {
        std::ifstream file;
        file.open("RegisterLogins.txt", ios::in);

        string line;
        vector<string> loginsRecords;
        while (std::getline(file, line))
        {
            loginsRecords.push_back(line);
        }
        file.close();
        return loginsRecords;
    }
    static void _PrintLoginRegisterData(vector<string> rec_data)
    {
        cout
            << setw(20) << left << ""
            << "|" << setw(25) << left << rec_data[0]
            << "|" << setw(10) << left << rec_data[1]
            << "|" << setw(10) << left << rec_data[2]
            << "|" << setw(10) << left << rec_data[3]
            << "\n";
    }

public:
    static void ShowLoginRegisterScreen()
    {
        _DrawScreenHeader("\e[32mLogin Register Screen\e[0m");
        cout
            << setw(20) << left << ""
            << "|" << setw(25) << left << "Date"
            << "|" << setw(10) << left << "UserName"
            << "|" << setw(10) << left << "Password"
            << "|" << setw(10) << left << "Permissions"
            << "\n";

        cout << setw(20) << left << "" << string('=', 60) << "\n";

        // Load each login Register screen from the file
        vector<string> loginRegistered_records = _LoadLoginRegisterFromFile();

        for (string record : loginRegistered_records)
        {
            // spilit each string line with delimiter
            vector<string> record_data = clsString::Split(record, "#//#");
            // print it
            _PrintLoginRegisterData(record_data);
        }
    }
};