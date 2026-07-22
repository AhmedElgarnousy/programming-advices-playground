#pragma once
#include "Global.h"

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
public:
    enum enLoginRetStatus
    {
        eLocked = -1,
        exitSuccess = 0,
    };

private:
    static enLoginRetStatus _Login()
    {
        bool LoginFailed = false;
        int failedMechanismCnt = 0;
        do
        {
            if (LoginFailed)
            {
                failedMechanismCnt++;
                cout << "\nInValid UserName/Pasword!\n";
                cout << "\e[41mYou have " << 3 - failedMechanismCnt << " Trial(s) to login\e[0m\n\n";
            }
            if (failedMechanismCnt == 3)
            {
                cout << "\e[41mYou are Locked After 3 Trials\e[0m" << endl;
                // cin.get();
                return enLoginRetStatus::eLocked;
            }

            cout << "Enter User Name: ";
            string user_name = clsInputValidate::ReadString();
            cout << "Enter Password: ";
            string password = clsInputValidate::ReadString();

            CurLoggedUsr = clsUser::Find(user_name, password);
            LoginFailed = CurLoggedUsr.IsEmpty();

        } while (LoginFailed);

        CurLoggedUsr.RegisterLogin();
        clsMainScreen::ShowMainMenu();
        return enLoginRetStatus::exitSuccess;
    }

public:
    static enLoginRetStatus ShowLoginScreen()
    {
        system("clear");
        _DrawScreenHeader("\e[42;37;1mLogin Screen\e[0m");
        enLoginRetStatus res = _Login();
        return res;
    }
};
