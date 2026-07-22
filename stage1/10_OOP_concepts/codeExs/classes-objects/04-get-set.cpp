#include <iostream>

class clsPerson
{
private:
    std::string _FirstName;
    std::string _LastName;
    std::string last_val_firstname;

protected:
    // only accessible inside this class and all classes inherits this class

public:
    std::string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    std::string getFirstName()
    {
        return _FirstName;
    }
    std::string getLastName()
    {
        return _LastName;
    }

    void setFirstName(std::string first_name)
    {
        /* Audit Trail:
            can achieved by saving old values or last old value before change
        */
        char ans{};
        if (last_val_firstname == first_name)
        {
            std::cout << "value already named do you want to overwrite? y or n ? " << " ";
            std::cin >> ans;
            if (ans == 'n')
            {
                std::cout << "enter new value: ";
                std::cin >> last_val_firstname;
                _FirstName = last_val_firstname;
                return;
            }
        }
        _FirstName = first_name;
        last_val_firstname = first_name; // update last value
    }

    void setLastName(std::string last_name)
    {
        _LastName = last_name;
    }
};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("ahmed");
    Person1.setLastName("kamal");

    std::cout << "First Name:" << Person1.getFirstName() << "\n";
    std::cout << "Last Name:" << Person1.getLastName() << "\n ";

    Person1.setFirstName("ahmed");
    // Person1._firstname = "failed";

    std::cout << "First Name:" << Person1.getFirstName() << "\n";
    std::cout << "Last Name:" << Person1.getLastName() << "\n ";
}
