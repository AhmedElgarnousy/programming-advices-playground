#include <iostream>
#include <sstream>

using std::string;

class clsPerson
{
public:
    struct stAddress
    {
        string AddressLine1;
        string AddressLine2;
        string City;
        string Country;
    };

private:
    stAddress Address;
    string FullName;

public:
    clsPerson(string full_name, stAddress address)
        : FullName(full_name), Address(address)
    {
    }

    string ToString()
    {
        std::stringstream oss;
        oss << "\nAddress:\n"
            << Address.AddressLine1 << "\n"
            << Address.AddressLine2 << "\n"
            << Address.City << "\n"
            << Address.Country << "\n";
        return oss.str();
    }
    void PrintAddress()
    {
        std::cout << ToString();
    }
};

int main()
{
    clsPerson::stAddress peraAddress;
    peraAddress.AddressLine1 = "Building 10";
    peraAddress.AddressLine2 = "kornish elnile";
    peraAddress.City = "Giza";
    peraAddress.Country = "Egypt";

    clsPerson person1("ahmed kamal", peraAddress);
    person1.PrintAddress();
    return 0;
}