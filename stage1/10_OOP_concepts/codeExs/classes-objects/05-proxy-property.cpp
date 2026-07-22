#include <iostream>
#include <string>

template <typename Owner, typename T,
          T (Owner::*Getter)() const,
          void (Owner::*Setter)(T)>
class Property
{
    Owner *_owner;

public:
    explicit Property(Owner *owner) : _owner(owner) {}

    Property &operator=(const T &value)
    {
        (_owner->*Setter)(value);
        return *this;
    }

    operator T() const
    {
        return (_owner->*Getter)();
    }

    // ← this is the real fix
    friend std::ostream &operator<<(std::ostream &os, const Property &p)
    {
        return os << (p._owner->*Getter)();
    }
};

class clsPerson
{
private:
    std::string _FirstName;
    std::string _LastName;
    std::string _last_val_firstname;

public:
    std::string getFirstName() const { return _FirstName; }
    std::string getLastName() const { return _LastName; }

    void setFirstName(std::string first_name)
    {
        if (_last_val_firstname == first_name)
        {
            char ans{};
            std::cout << "Value already set. Overwrite? (y/n): ";
            std::cin >> ans;
            if (ans == 'n')
            {
                std::cout << "Enter new value: ";
                std::cin >> first_name;
            }
        }
        _FirstName = first_name;
        _last_val_firstname = first_name;
    }

    void setLastName(std::string last_name) { _LastName = last_name; }

    std::string FullName() const { return _FirstName + " " + _LastName; }

    Property<clsPerson, std::string,
             &clsPerson::getFirstName,
             &clsPerson::setFirstName>
        FirstName{this};

    Property<clsPerson, std::string,
             &clsPerson::getLastName,
             &clsPerson::setLastName>
        LastName{this};
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Ahmed";
    Person1.LastName = "Kamal";

    std::cout << "First Name : " << Person1.FirstName << "\n";
    std::cout << "Last Name  : " << Person1.LastName << "\n";
    std::cout << "Full Name  : " << Person1.FullName() << "\n";

    Person1.FirstName = "Ahmed"; // triggers audit trail
}