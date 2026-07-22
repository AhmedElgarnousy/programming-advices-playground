#include <iostream>

class clsPerson
{
private:
    // only accessible inside this class
    int variable1 = 5;

    int function1() { return 40; }

protected:
    // only accessible inside this class and all classes inherits this class
    int variable2 = 100;
    int function2() { return 50; }

public:
    std::string FirstName;
    std::string LastName;

    std::string FullName()
    {
        return FirstName + " " + LastName;
    }

    float function3()
    {
        function1() + variable1 *variable2;
    }
};

class clsEmployee : clsPerson
{
public:
    int salary{};
};

int main()
{
    clsPerson Person1; //
    Person1.FirstName = "ahmed";
    Person1.LastName = "kamal";

    // Person1.

    clsEmployee emp1;
    emp1.variable1 = 2;
    emp1.function2();
}