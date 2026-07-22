#include <iostream>

class clsA
{
private:
    int _var1;
    int _func1()
    {
        return 1;
    }

protected:
    int var2;
    int func2()
    {
        // _func1();
        return 2;
    }

public:
    int var3;
    int func3()
    {
        return 3;
    }
};

class clsB : public clsA
{
private:
protected:
public:
    int func4()
    {
        func2(); // protected in clsA
        func3();
        return 4;
    }
};

class clsC : clsB
{
private:
public:
    void func5()
    {
        func2();
    }
};

int main()
{
    clsA A1;
    clsB B1;

    B1.func4();
    // B1.func3();

    return 0;
}