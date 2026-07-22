#include <iostream>
using namespace std;

class clsA
{
private:
    // only accessible inside this class, neither derived classes nor outside class.
    int _Var1;
    void _Fun_clsA_Prv()
    {
        cout << "Function 1";
    }

protected:
    // only accessible inside this class and all derived classes but not outside class
    int Var2;
    void Fun_clsA_protected()
    {
        cout << "Function 2";
    }

public:
    // Accessible inside this class, all derived classes, and outside class
    int Var3;
    void Fun_clsA_public()
    {
        cout << "Function 3";
    }

    static void _Fun_clsA_static_public()
    {
        cout << "Function 1";
    }
};

class clsB : public clsA
{
public:
    void Func_clsB_public()
    {
        // correct, access protected of base class inside derived class
        Fun_clsA_protected(); // another ways
        clsA::Fun_clsA_protected();
        this->Fun_clsA_protected();
    }
};

int main()
{
    clsA AA; // base class
    clsB BB; // derived class

    // can't access protected from outside main, even if it's an object of the derived class
    // AA.Fun_clsA_protected(); // error
    // BB.Fun_clsA_protected(); // error

    clsA::_Fun_clsA_static_public();
    clsB::_Fun_clsA_static_public();

    return 0;
}