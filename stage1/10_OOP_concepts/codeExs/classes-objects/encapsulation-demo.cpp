#include <iostream>

class clsA
{
private:
    int _x_private;

public:
    int x_public;

    void Setx_private(const int val)
    {
        _x_private = val;
    }
    int x_private() const
    {
        return _x_private;
    }
};

int main()
{
    clsA Obj1, Obj2;

    // clsPerson::Setx_private(2);

    Obj1.Setx_private(2);
    Obj1.Setx_private(2);

    Obj1.x_public = 2;
    Obj2.x_public = 3;

    std::cout << "x_prv val at obj1: " << Obj1.x_private() << "\n";
    std::cout << "x_prv val at obj2: " << Obj2.x_private() << "\n";
}