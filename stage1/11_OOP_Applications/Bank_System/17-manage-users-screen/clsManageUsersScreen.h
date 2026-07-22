
#pragma once

#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsManageUsersScreen : protected clsScreen
{
private:
    enum enManageUsersMenuOptions
    {
        eListUser = 1,
        eAddUser = 2,
        eUpdateUser = 3,
        eDeleteUser = 4,
        eFindUser = 5,
        eMainMenu = 6,
    };

    static int _ReadManageUsersMenuOption()
    {
        cout << "\t\t\t\t" << setw(37) << left << "Choose what do you want to do? [1 to 6]?";
        return clsInputValidate::ReadIntNumberBetween(1, 6, "Enter Number between 1 to 6? ");
    }
    static void _GoBackToManageUsersMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menu...\n";
        // Clear any leftover newline characters in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Safely wait for user input natively
        std::cin.get();
        clsManageUsersScreen::ShowManageUsersScreen();
    }

    static void _ShowListUsersScreen()
    {
        cout << "\nList Users Screen Will Be Here.\n";
    }

    static void _ShowAddNewUserScreen()
    {
        cout << "\nAdd New User Screen Will Be Here.\n";
    }

    static void _ShowDeleteUserScreen()
    {
        cout << "\nDelete User Screen Will Be Here.\n";
    }

    static void _ShowUpdateUserScreen()
    {
        cout << "\nUpdate User Screen Will Be Here.\n";
    }

    static void _ShowFindUserScreen()
    {
        cout << "\nFind User Screen Will Be Here.\n";
    }
    static void _PerformManageUsersMenuChoice(enManageUsersMenuOptions enChoice)
    {
        switch (enChoice)
        {
        case enManageUsersMenuOptions::eListUser:
        {
            system("clear"); // linux dependent
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eAddUser:
        {
            system("clear"); // linux dependent
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eUpdateUser:
        {
            system("clear"); // linux dependent
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eFindUser:
        {
            system("clear"); // linux dependent
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;
        }
        case enManageUsersMenuOptions::eMainMenu:
        {
            break;
        }
        }
    }

public:
    static void
    ShowManageUsersScreen()
    {
        _DrawScreenHeader("\t Manage Users Screen ");

        // print manage users menu header

        cout << setw(32) << left << "" << string(60, '=') << endl;
        cout << setw(32) << left << "" << "\t\tManage Users Menu\n";
        cout << setw(32) << left << "" << string(60, '=') << endl;

        cout << setw(32) << left << "" << "[1] List Users.\n";
        cout << setw(32) << left << "" << "[2] Add New User.\n";
        cout << setw(32) << left << "" << "[3] Delete User.\n";
        cout << setw(32) << left << "" << "[4] Update User.\n";
        cout << setw(32) << left << "" << "[5] Find User.\n";
        cout << setw(32) << left << "" << "[6] Main Menue.\n";

        cout << setw(32) << left << "" << string(60, '=') << endl; // line seperator

        _PerformManageUsersMenuChoice((enManageUsersMenuOptions)_ReadManageUsersMenuOption());
    }
};