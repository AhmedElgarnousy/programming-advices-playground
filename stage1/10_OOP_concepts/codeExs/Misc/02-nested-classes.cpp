#include <iostream>
#include <sstream>

using std::string;

class clsPerson
{
private:
    class clsAddress
    {
    private:
        string _AddressLine1;
        string _AddressLine2;
        string _City;
        string _Country;

    public:
        clsAddress(string line1, string line2, string city, string country) : _ddressLine1(line1),
                                                                              _AddressLine2(line2),
                                                                              _City(city),
                                                                              _Country(country)
        {
        }
        void Print()
        {
            std::cout << "\nAddress:\n"
                      << _AddressLine1 << "\n"
                      << _AddressLine2 << "\n"
                      << _City << "\n"
                      << _Country << "\n";
        }
    };

public:
    string FullName;
    clsAddress Address;

    clsPerson(string full_name, string line1, string line2, string city, string country)
        : Address(line1, line2, city, country)
    {
        FullName = full_name;
    }
};

int main()
{

    clsPerson person1("ahmed-kamal", "Building 10", "kornish elnile", "Giza", "Egypt");
    person1.Address.Print();

    return 0;
}