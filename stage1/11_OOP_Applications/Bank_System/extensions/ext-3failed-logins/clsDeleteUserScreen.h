#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{
private:
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

public:
    static void ShowDeleteUser()
    {
        _DrawScreenHeader("Delete User Screen");

        // Read user name
        // check if is exists or not and read until get a valid user name
        // get object by find
        // call delete method

        string user_name = "";
        cout << "\nEnter Enter user name :";
        user_name = clsInputValidate::ReadString();

        if (!clsUser::IsUserExist(user_name))
        {
            cout << "\nuser is not found, choose another one:";
            user_name = clsInputValidate::ReadString();
        }
        clsUser user = clsUser::Find(user_name);
        cout << "\nAre you sure you want to delete this user y/n?";
        char answer = 'n';
        cin >> answer;
        if (answer == 'y' | answer == 'Y')
        {
            if (user.Delete(user_name))
            {
                cout << "\n User Deleted Sucessfully\n";
                _PrintUserInfo(user);
            }
            else
            {
                cout << "\n Error User while user deletion\n";
            }
        }
        // user.Save();
    }
};