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

    friend class clsB;
};

class clsB
{
private:
public:
    void display(const clsA &A1)
    {
        std::cout << "value of var1 = " << A1._var1 << "\n";
        std::cout << "value of var2 = " << A1._var2 << "\n";
    }
};

int main()
{

    clsA A1;
    clsB B1;
    B1.display(A1);

    return 0;
}