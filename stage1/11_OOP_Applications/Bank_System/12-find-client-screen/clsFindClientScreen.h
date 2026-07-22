#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:
    static void _PrintClient(clsBankClient &client)
    {
        ostringstream oss;
        oss << "\nInfo:" << "\n________________"
            << "\nFirstName: " << client.FirstName()
            << "\nLastName: " << client.LastName()
            << "\nFull Name:" << client.FullName()
            << "\nEmail:" << client.Email()
            << "\nPhone:" << client.Phone()
            << "\nAcc. Number:" << client.AccountNumber()
            << "\nPassword:" << client.PinCode()
            << "\nAcc. Balance:" << client.AccountBalanace()
            << "\n__________________________\n";

        std::cout << oss.str();
        // std::cout << left << setw(70) << oss.str();
    }

public:
    static void showFindClientScreen()
    {
        clsScreen::_DrawScreenHeader("\tFind Client Screen");

        string account_number = "";
        cout << "\nPlease Enter Account Number: ";
        account_number = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(account_number))
        {
            cout << "\nAccount number is not found, choose another one: ";
            account_number = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(account_number);

        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);
    }
};