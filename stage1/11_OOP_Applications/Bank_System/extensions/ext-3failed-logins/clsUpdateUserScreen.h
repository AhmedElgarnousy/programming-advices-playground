
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

class clsUpdateUserScreen : protected clsScreen
{
private:
    static void _PrintUser(clsUser usr)
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << usr.UserName();
        cout << "| " << setw(25) << left << usr.FullName();
        cout << "| " << setw(12) << left << usr.Phone();
        cout << "| " << setw(20) << left << usr.Email();
        cout << "| " << setw(10) << left << usr.Password();
        cout << "| " << setw(12) << left << usr.Permissions();
    }

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
        return permissions;
    }

public:
    static void
    ShowUpdateUserScreen()
    {
        _DrawScreenHeader("Update User Screen");

        cout << "Enter User Name: ";
        string user_name = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(user_name))
        {
            cout << "User Not Exists, Enter user name again:";
        }

        clsUser cur_user = clsUser::Find(user_name);

        _PrintUser(cur_user);
        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";

            _ReadUserInfo(cur_user);

            clsUser::enSaveResult enUpdateUsrRes = cur_user.Save();

            switch (enUpdateUsrRes)
            {
            case clsUser::enSaveResult::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(cur_user);
                break;
            }
            case clsUser::enSaveResult::svFailedEmpty:
            {
                cout << "\nError User was not saved because it's Empty";
                break;
            }
            }
        }
    }
};