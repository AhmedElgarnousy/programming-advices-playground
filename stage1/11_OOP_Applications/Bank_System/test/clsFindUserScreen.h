#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsFindUserScreen : protected clsScreen
{

private:
    static void _PrintUserInfo(clsUser &user)
    {
        cout << setw(5) << left << "" << "User Info:\n";
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
    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("Find User Screen");

        cout << "Enter User Name: ";

        string user_name = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(user_name))
        {
            cout << "User Not Exists, Enter another user name: ";
            user_name = clsInputValidate::ReadString();
        }

        clsUser usr = clsUser::Find(user_name);
        _PrintUserInfo(usr);
    }
};