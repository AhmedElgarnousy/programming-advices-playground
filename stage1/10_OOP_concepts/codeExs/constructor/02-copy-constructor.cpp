#include <iostream>

class clsAddress
{
private:
    std::string _AddressLine1;
    std::string _AddressLine2;
    std::string _POBox;
    std::string _ZipCode;

public:
    clsAddress(std::string AddressLine1, std::string AddressLine2, std::string POBox, std::string ZipCode)
    {
        _AddressLine1 = AddressLine1;
        _AddressLine2 = AddressLine2;
        _POBox = POBox;
        _ZipCode = ZipCode;
    }

    // copy constructor
    clsAddress(clsAddress &old_obj)
    {
        _AddressLine1 = old_obj.AddressLine1();
        // _AddressLine1 = old_obj.AddressLine2();
    }

    void SetAddressLine1(std::string AddressLine)
    {
        _AddressLine1 = AddressLine;
    }

    std::string AddressLine1()
    {
        return _AddressLine1;
    }

    void Print()
    {
        // std::cout << A
    }
};

int main()
{
    clsAddress Address1("kornish elNile", "giza", "", "");

    clsAddress Address2 = Address1;

    std::cout << Address2.AddressLine1() << "\n";

    // after changing address1 address 2 will not change it's copy means another memory
    Address1.SetAddressLine1("masr");

    std::cout << Address2.AddressLine1() << "\n";

    return 0;
}