#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsAddNewUserScreen : protected clsScreen
{
private:
    static void _ReadUserInfo(clsUser &user)
    {
        cout << "\nEnter First Name: ";
        user.SetFirstName(clsInputValidate::ReadString());

        cout << "\nEnter Last Name: ";
        user.SetLastName(clsInputValidate::ReadString());

        cout << "\nEnter Email: ";
        user.SetEmail(clsInputValidate::ReadString());

        cout << "\nEnter Phone: ";
        user.SetPhone(clsInputValidate::ReadString());

        cout << "\nEnter Password: ";
        user.SetPassword(clsInputValidate::ReadString());

        cout << "\nEnter Permissions: ";
        user.SetPermissions(_ReadPermissionsToSet());
        // user.SetPermissions(clsInputValidate::ReadIntNumber());
    }
    static void _PrintUserInfo(clsUser &user)
    {
        // cout << setw(8) << left << "" << user.FullName() << "\n";
        ostringstream oss;
        oss << "\nNew User Info:" << "\n________________"
            << "\nUserName: " << user.UserName()
            << "\nFirstName: " << user.FirstName()
            << "\nLastName: " << user.LastName()
            << "\nFull Name:" << user.FullName()
            << "\nEmail:" << user.Email()
            << "\nPhone:" << user.Phone()
            << "\nPermissions:" << user.Permissions()
            << "\n__________________________\n";

        std::cout << oss.str();
    }
    static int _ReadPermissionsToSet()
    {
        int permissions = 0;
        char answer = 'n';

        cout << "\nDo you wan to give the user full access? y/n?:";
        cin >> answer;

        if (answer == 'Y' || answer == 'y')
        {
            return clsUser::enPermissions::pFullAccess; // all int bytes is 1s
        }

        cout << "\nDo you want to give access to: \n";

        cout << "\nShow Client List ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdding New User ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete User ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate User ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pUpdateClient;
        }

        cout << "\nFind User ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pManageUsers;
        }
        cout << "\nLogin Register ?y/n ? ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            permissions += clsUser::enPermissions::pLoginRegister;
        }
        return permissions;
    }

public:
    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("Add New User Screen");
        string user_name;
        cout << "\nEnter User Name: ";
        user_name = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(user_name))
        {
            cout << "\nUser Already Exist, Enter New User Name: ";
            user_name = clsInputValidate::ReadString();
        }
        // clsUser::Find(user_name);
        clsUser user = clsUser::GetAddNewUserObject(user_name);
        _ReadUserInfo(user);
        clsUser::enSaveResult newUsrSaveRes = user.Save();
        switch (newUsrSaveRes)
        {
        case clsUser::enSaveResult::svSucceeded:
        {
            cout << "\nUser Added To CSV File Database Sucessfully:-)\n";
            _PrintUserInfo(user);
            break;
        }
        case clsUser::enSaveResult::svFailedEmpty:
        {
            cout << "\nError While Saving Empty User\n";
            _PrintUserInfo(user);
            break;
        }
        case clsUser::enSaveResult::svFailedUserExists:
        {
            cout << "\nError While Saving User Name is used!\n";
            break;
        }
        }
    }
};