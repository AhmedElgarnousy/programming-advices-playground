#include <iostream>

class clsA
{

public:
    int var;
    static int counter;

    clsA()
    {
        counter++;
    }

    void Print()
    {
        std::cout << "\nVar    = " << var << "\n";
        std::cout << "counter  = " << counter << "\n";
    }
};

// defintion and intializatio outside class
int clsA::counter = 0;

int main()
{

    clsA A1, A2, A3;

    A1.var = 10;
    A2.var = 20;
    A3.var = 30;

    A1.Print();
    A2.Print();
    A3.Print();

    std::cout << "\nAfter changing static member in one object\n"; // No object Required
    A1.counter = 50;
    A1.var = 100;

    A1.Print();
    A2.Print();
    A3.Print();

    // A1.Print();
    // std::cout << clsA::counter << "\n"; // No object Required

    return 0;
}