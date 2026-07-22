#pragma once

// #include <iostream>
// #include <string>

#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

class clsTransactionsMainMenu : protected clsScreen
{
private:
    enum enTransactionsOptions
    {
        eDeposit = 1,
        eWithDraw = 2,
        eShowTotalBalance = 3,
        eShowMainMenue = 4,
    };
    static int _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 4, "Enter Number between 1 to 4? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        // cout << "Deposit Screen will be here\n";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithDrawScreen()
    {
        // cout << "WithDraw Screen will be here\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        cout << "Total Balance Screen will be here\n";
    }
    static void _GoBackToTransactionMenu()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menu...\n";

        // Clear any leftover newline characters in the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Safely wait for user input natively
        std::cin.get();

        clsTransactionsMainMenu::showTransactionMainMenu();
    }

    static void _PerformTranactionMenuChoice(enTransactionsOptions enChoice)
    {
        switch (enChoice)
        {
        case enTransactionsOptions::eDeposit:
        {
            system("clear");
            _ShowDepositScreen();
            _GoBackToTransactionMenu();
            break;
        }
        case enTransactionsOptions::eWithDraw:
        {
            system("clear");
            _ShowWithDrawScreen();
            _GoBackToTransactionMenu();
            break;
        }
        case enTransactionsOptions::eShowTotalBalance:
        {
            system("clear");
            _ShowTotalBalanceScreen();
            _GoBackToTransactionMenu();
            break;
        }
        case enTransactionsOptions::eShowMainMenue:
        {
            // mein screen handle this option
        }
        }
    }

public:
    static void showTransactionMainMenu()
    {
        clsScreen::_DrawScreenHeader("\tTransactions Screen");

        cout << "\t\t\t\t\t\t Transaction Menu\n";

        cout << "\t\t\t\t" << string(60, '=') << endl;

        cout << setw(37) << left << "" << "\t[1] Deposit." << "\n";
        cout << setw(37) << left << "" << "\t[2] WithDraw." << "\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances." << "\n";
        cout << setw(37) << left << "" << "\t[4] Main Menu." << "\n";

        cout << "\t\t\t\t" << string(60, '=') << endl;

        _PerformTranactionMenuChoice((enTransactionsOptions)_ReadTransactionsMenueOption());
    }
};