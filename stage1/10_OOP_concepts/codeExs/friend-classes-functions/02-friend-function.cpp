#include <iostream>

class clsA
{
private:
    int _var1;

protected:
    int _var2;

public:
    int var3;

    clsA()
    {
        _var1 = 10;
        _var2 = 20;
        var3 = 20;
    }

    friend void display(const clsA &A1);
};

void display(const clsA &A1)
{

    std::cout << A1._var1 << "\n";
    std::cout << A1._var2 << "\n";
    std::cout << A1.var3 << "\n";
}

int main()
{

    clsA A1;
    display(A1);

    return 0;
}