#include <iostream>

using std::string;

class clsPerson
{
private:
public:
    string name;
};

class clsEmployee : public clsPerson
{
private:
public:
    string salary = "5";
};

int main()
{
    clsEmployee employee1;
    // up casting
    // this will convert employee to person
    clsPerson *pbaseCls = &employee1;

    std::cout << pbaseCls->name << "\n";
    // std::cout << pbaseCls->salary << "\n"; //

    // downcasting : but you cannot convert person to employee
    //  clsPerson person1;
    //  clsEmployee *pderivedCls = &person1;

    return 0;
}