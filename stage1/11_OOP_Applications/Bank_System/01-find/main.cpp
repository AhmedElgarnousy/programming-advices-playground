#include <iostream>
#include "clsBankClient.h"

int main()
{
    clsBankClient Client1 = clsBankClient::Find("A100");
    if (!Client1.IsEmpty())
    {
        std::cout << "\nClient Found:)\n";
    }
    else
    {
        std::cout << "\nClient Not Found:)\n";
    }
    Client1.Print();

    return 0;
}