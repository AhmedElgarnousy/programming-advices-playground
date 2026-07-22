#include <iostream>

class clsA
{

public:
    int var;

    int function1()
    {
        return 5;
    }
    static int function2()
    {
        return 10;
    }
};

int main()
{
    // static function - a class-level
    std::cout << clsA::function2() << "\n";

    /**
     * ERROR:
     a nonstatic member reference must
     be relative to a specific objectC/C++(245)
     */
    // std::cout << clsA::function1() << "\n";

    clsA A1, A2, A3;
    std::cout << A1.function2() << "\n";

    return 0;
}