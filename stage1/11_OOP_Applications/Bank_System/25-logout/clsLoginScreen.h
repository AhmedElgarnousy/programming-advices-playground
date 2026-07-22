#pragma once
#include "Global.h"

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
    static void _Login()
    {
        bool LoginFailed = false;
        do
        {
            if (LoginFailed)
            {
                cout << "InValid UserName/Pasword!\n";
            }
            cout << "Enter User Name: ";
            string user_name = clsInputValidate::ReadString();
            cout << "Enter Password: ";
            string password = clsInputValidate::ReadString();

            CurLoggedUsr = clsUser::Find(user_name, password);
            // if (!clsUser::IsUserExist(user_name))
            // {
            //     LoginFailed = true;
            // }
            LoginFailed = CurLoggedUsr.IsEmpty();

        } while (LoginFailed);

        clsMainScreen::ShowMainMenu();
    }

public:
    static void ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\e[42;37mLogin Screen\e[0m");
        _Login();
    }
};
