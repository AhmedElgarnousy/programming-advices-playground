#pragma once
#include <iostream>
#include <iomanip> // I/O Stream Manipulator

#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMainScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"

#include "Global.h"

class clsMainScreen : protected clsScreen
{
private:
    // inline static clsLoginScreen *pclsLoginScreen;
    enum enMainMenuOptions
    {
        eListClients = 1, // show client option in main screen
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eLoginsRegister = 8,
        eExit = 9
    };

    static bool _CheckUserAccessRights(clsUser &usr, int PerBit)
    {
        int perm = usr.Permissions();
        return (perm &= (1 << PerBit));
    }
    static int _ReadMainMenuOption()
    {
        cout << setw(20) << left << " " << "Choose what do you want to do? [1 to 9]?";
        return clsInputValidate::ReadIntNumberBetween(1, 9, "Enter Number between 1 to 9? ");
    }
    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        // Clear any leftover newline characters in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Safely wait for user input natively
        std::cin.get();

        ShowMainMenu();
    }

    static void _ShowAllClientsScreen()
    {
        // cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::AddNewClient();
    }

    static void _ShowDeleteClientScreen()
    {
        // cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        // cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::showUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::showFindClientScreen();
    }

    static void _ShowTransactionsMenu()
    {
        clsTransactionsMainMenu::showTransactionMainMenu();
        // cout << "\nTransactions Menue Will be here...\n";
    }

    static void _ShowManageUsersMenu()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersScreen();
    }
    static void _ShowLoginsRegister()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsLoginRegister::ShowLoginRegisterScreen();
    }

    static void _ShowEndScreen()
    {
        CurLoggedUsr = clsUser::Find("", "");
        /*Can't Call ShowLoginScreen again like
        circular calling, think in stack calling
        runtime error
        //   clsLoginScreen::ShowLoginScreen();
        */
    }

    static void _PerformMainMenuOption(enMainMenuOptions main_menu_option)
    {
        switch (main_menu_option)
        {
        case enMainMenuOptions::eListClients:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 1))
            {
                _ShowAllClientsScreen();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 2))
            {
                _ShowAddNewClientsScreen();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 2))
            {
                _ShowDeleteClientScreen();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eUpdateClient:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 3))
            {
                _ShowUpdateClientScreen();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 4))
            {
                _ShowFindClientScreen();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eShowTransactionsMenu:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 5))
            {
                _ShowTransactionsMenu();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eManageUsers:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 6))
            {
                _ShowManageUsersMenu();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eLoginsRegister:
        {
            system("clear");
            if (_CheckUserAccessRights(CurLoggedUsr, 7))
            {
                _ShowLoginsRegister();
            }
            else
            {
                _DrawScreenHeader("\e[41;37mAccess Denied, Contact Admin.\e[0m");
            }

            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eExit:
        {

            _ShowEndScreen();
            system("clear");
            // _GoBackToMainMenu();
            break;
        }
        }
    }

public:
    // wrapper function to _PerformMainMenuOption which act as router or maper
    static void ShowMainMenu()
    {
        system("clear");
        _DrawScreenHeader("Main Screen");
        cout << setw(20) << left << "" << string(60, '=') << "\n";
        cout << setw(40) << left << "" << "Main Menu\n";
        cout << setw(20) << left << "" << string(60, '=') << endl;
        cout << setw(20) << left << "" << "[1] Show Client List." << endl;
        cout << setw(20) << left << "" << "[2] Add New Client." << endl;
        cout << setw(20) << left << "" << "[3] Delete Client." << endl;
        cout << setw(20) << left << "" << "[4] Update Client Info." << endl;
        cout << setw(20) << left << "" << "[5] Find Client." << endl;
        cout << setw(20) << left << "" << "[6] Transactions." << endl;
        cout << setw(20) << left << "" << "[7] Manage Users." << endl;
        cout << setw(20) << left << "" << "[8] Logins Register." << endl;
        cout << setw(20) << left << "" << "[9] Logout or Exit." << endl;

        cout << setw(20) << left << "" << string(60, '=') << endl;

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }
};