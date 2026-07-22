#include <iostream>

class clsPerson
{
private:
    int x;

public:
    std::string FirstName;
    std::string LastName;

    std::string FullName()
    {
        return FirstName + " " + LastName;
    }
};

int main()
{
    clsPerson Person1; //
    Person1.FirstName = "ahmed";
    Person1.LastName = "kamal";

    // clsPerson *pClsPerson2 = nullptr;
    // pClsPerson2->FirstName = "mohand";
    // pClsPerson2->LastName = "kamal";

    // std::cout << Person1.FullName() << "\n";
    // std::cout << pClsPerson2->FullName() << "\n";

    // Person1.x // private
}