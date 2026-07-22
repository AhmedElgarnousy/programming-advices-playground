#pragma once

// #include <iostream>
// #include <string>

#include "clsScreen.h"
#include "clsInputValidate.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"

class clsTransactionsMainMenu : protected clsScreen
{
private:
    enum enTransactionsOptions
    {
        eDeposit = 1,
        eWithDraw = 2,
        eShowTotalBalance = 3,
        eShowTransfer = 4,
        eShowMainMenue = 5,
    };
    static int _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithDrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _ShowTotalBalanceScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }
    static void _ShowTransferScreen()
    {
        // cout << "Transfer Screen will be here\n";
        clsTransferScreen::ShowTransferScreen();
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
        case enTransactionsOptions::eShowTransfer:
        {
            system("clear");
            _ShowTransferScreen();
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
        cout << setw(37) << left << "" << "\t[4] Transfer." << "\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu." << "\n";

        cout << "\t\t\t\t" << string(60, '=') << endl;

        _PerformTranactionMenuChoice((enTransactionsOptions)_ReadTransactionsMenueOption());
    }
};