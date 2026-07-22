#include <iostream>

class clsAddress
{
private:
public:
    clsAddress()
    {
        std::cout << "Iam default construcor\n";
    }
    clsAddress(std::string name)
    {
        std::cout << "Iam ahmed construcor\n";
    }
};

int main()
{
    clsAddress Address1("ahmed");
    clsAddress Address2;
    clsAddress Address3;
    clsAddress Address4;

    return 0;
}