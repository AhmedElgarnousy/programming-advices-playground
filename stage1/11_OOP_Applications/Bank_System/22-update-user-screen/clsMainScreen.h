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

class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenuOptions
    {
        eListClients = 1, // show client option in main screen
        eAddNewClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eShowTransactionsMenu = 6,
        eManageUsers = 7,
        eExit = 8
    };
    static int _ReadMainMenuOption()
    {
        cout << setw(20) << left << " " << "Choose what do you want to do? [1 to 8]?";
        return clsInputValidate::ReadIntNumberBetween(1, 8, "Enter Number between 1 to 8? ");
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

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";
    }

    static void _PerformMainMenuOption(enMainMenuOptions main_menu_option)
    {
        switch (main_menu_option)
        {
        case enMainMenuOptions::eListClients:
        {
            system("clear");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eAddNewClient:
        {
            system("clear");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eDeleteClient:
        {
            system("clear");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eUpdateClient:
        {
            system("clear");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eFindClient:
        {
            system("clear");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eShowTransactionsMenu:
        {
            system("clear");
            _ShowTransactionsMenu();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenuOptions::eManageUsers:
        {
            system("clear");
            _ShowManageUsersMenu();
            _GoBackToMainMenu();
            break;
        }
        // Enter =  '\r\n':
        case enMainMenuOptions::eExit:
        {
            system("clear");
            _ShowEndScreen();
            _GoBackToMainMenu();
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
        cout << setw(20) << left << "" << "[8] Logout or Exit." << endl;

        cout << setw(20) << left << "" << string(60, '=') << endl;
        // cout << string(60, '=') << "\n";

        _PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
    }
};